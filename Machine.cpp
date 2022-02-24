//
// Created by Peter on 2021/11/13.
//

#include "Machine.h"
#include "Judge.h"
#include <iostream>
#include <map>
#include <string>


Machine::Machine() {}

Machine::Machine(int machine_color) {
    color = machine_color;
}

void Machine::SetColor(int machine_color) {
    color = machine_color;
}

char Machine::Col_int_to_char(int col) {
    char result = 'A';
    result = result + col;
    return result;
}

ChessPiece Machine::FetchAPiece() const {
    int piece_coloe = color;
    ChessPiece piece(piece_coloe);
    return piece;
}

void Machine::PlayChess(Checkerboard &board, int round) {
    int x, y;//x,y为电脑落子的坐标
    int best_x = -1, best_y = -1, max_score = 0, current_point_score;
    //黑色棋子的第一颗必须落在天元
    if (round == 1 && color == 1) {
        best_x = 7;
        best_y = 7;
//        ChessPiece piece=FetchAPiece();
//        board.SendPiece(x,y+1, piece);
    } else {
        for (x = 0; x < 14; x++) {
            for (y = 0; y < 14; y++) {
                if (board.data_for_compute[x][y] == -1) {
                    current_point_score = ComputePointScore(board, x, y);
                    if (current_point_score > max_score) {
                        max_score = current_point_score;
                        best_x = x;
                        best_y = y;
                    }
                }
            }
        }
//        std::cout<<"max score:"<<max_score<<std::endl;
//        std::cout<<"best x:"<<best_x<<std::endl;
//        std::cout<<"best y:"<<best_y<<std::endl;

        //std::cout<<"score:"<<max_score<<" 电脑落子："<<Col_int_to_char(best_y)<<" "<<15-best_x<<std::endl;
    }
    std::cout << "电脑落子坐标 (如:A1 或 a1):" << Col_int_to_char(best_y) << "" << 15 - best_x << std::endl;

    ChessPiece piece = FetchAPiece();
    board.SendPiece(best_x, best_y + 1, piece);
}


int Machine::ComputePointScore(Checkerboard checkerboard, int x, int y) const {
    int machine_score = 0;
    //电脑使用白子时使用, 白：0, 黑：1
    std::map<std::string, int> score_map_for_white = {
            {"1",     10},
            {"11",    100},
            {"111",   5000},
            {"1111",  8000},

            {"10",    5},
            {"110",   80},
            {"1110",  3000},
            {"11110", 10000},

            {"01",    11},
            {"011",   110},
            {"0111",  1100},
            {"01111", 11000},

            {"0",     20},
            {"00",    200},
            {"000",   4500},
            {"0000",  10000},

            {"001",   100},
            {"0001",  3000},
            {"00001", 12000},
            {"100",   5},
            {"1000",  500},
            {"10000", 10000}
    };

    std::map<std::string, int> score_map_for_black = {
            {"0",     10},
            {"00",    100},
            {"000",   5000},
            {"0000",  8000},

            {"01",    5},
            {"001",   80},
            {"0001",  3000},
            {"00001", 10000},

            {"10",    11},
            {"100",   110},
            {"1000",  1100},
            {"10000", 11000},

            {"1",     20},
            {"11",    200},
            {"111",   4500},
            {"1111",  10000},

            {"110",   100},
            {"1110",  3000},
            {"11110", 12000},
            {"011",   5},
            {"0111",  500},
            {"01111", 10000}
    };

    std::map<std::string, int> score_map;
    if (color == 0)
        score_map = score_map_for_white;
    else
        score_map = score_map_for_black;
    //从x,y处开始搜索，看看周围的情况能构成的棋型，累加其得分

    std::string pattern;
    int position_color = -1;
    for (int k = x + 1; k < 15; k++) {
        if (checkerboard.data_for_compute[k][y] == -1) {
            break;
        } else {
            if (position_color == -1) {
                position_color = checkerboard.data_for_compute[k][y];
                pattern += std::to_string(checkerboard.data_for_compute[k][y]);
            } else if (position_color == checkerboard.data_for_compute[k][y]) {
                pattern += std::to_string(checkerboard.data_for_compute[k][y]);
            } else {
                pattern += std::to_string(checkerboard.data_for_compute[k][y]);
                break;
            }

        }
    }
    if (score_map.find(pattern) != score_map.end()) {
        machine_score += score_map[pattern];
    }


    pattern = "";
    position_color = -1;
    for (int k = x - 1; k > 0; k--) {
        if (checkerboard.data_for_compute[k][y] == -1) {
            break;
        } else {
            if (position_color == -1) {
                position_color = checkerboard.data_for_compute[k][y];
                pattern += std::to_string(checkerboard.data_for_compute[k][y]);
            } else if (position_color == checkerboard.data_for_compute[k][y]) {
                pattern += std::to_string(checkerboard.data_for_compute[k][y]);
            } else {
                pattern += std::to_string(checkerboard.data_for_compute[k][y]);
                break;
            }

        }
    }

    if (score_map.find(pattern) != score_map.end()) {
        machine_score += score_map[pattern];
    }

    //向上搜索棋型
    pattern = "";
    position_color = -1;
    for (int k = y - 1; k > 0; k--) {
        if (checkerboard.data_for_compute[x][k] == -1) {
            break;
        } else {
            if (position_color == -1) {
                position_color = checkerboard.data_for_compute[x][k];
                pattern += std::to_string(checkerboard.data_for_compute[x][k]);
            } else if (position_color == checkerboard.data_for_compute[x][k]) {
                pattern += std::to_string(checkerboard.data_for_compute[x][k]);
            } else {
                pattern += std::to_string(checkerboard.data_for_compute[x][k]);
                break;
            }

        }
    }

    if (score_map.find(pattern) != score_map.end()) {
        machine_score += score_map[pattern];
    }

    //向下搜索棋型
    pattern = "";
    position_color = -1;
    for (int k = y + 1; k < 15; k++) {
        if (checkerboard.data_for_compute[x][k] == -1) {
            break;
        } else {
            if (position_color == -1) {
                position_color = checkerboard.data_for_compute[x][k];
                pattern += std::to_string(checkerboard.data_for_compute[x][k]);
            } else if (position_color == checkerboard.data_for_compute[x][k]) {
                pattern += std::to_string(checkerboard.data_for_compute[x][k]);
            } else {
                pattern += std::to_string(checkerboard.data_for_compute[x][k]);
                break;
            }

        }
    }
    if (score_map.find(pattern) != score_map.end()) {
        machine_score += score_map[pattern];
    }

    //向左上搜索棋型
    pattern = "";
    position_color = -1;

    for (int m = x - 1, k = y - 1; m > 0 && k > 0; m--, k--) {
        if (checkerboard.data_for_compute[m][k] == -1) {
            break;
        } else {
            if (position_color == -1) {
                position_color = checkerboard.data_for_compute[m][k];
                pattern += std::to_string(checkerboard.data_for_compute[m][k]);
            } else if (position_color == checkerboard.data_for_compute[m][k]) {
                pattern += std::to_string(checkerboard.data_for_compute[m][k]);
            } else {
                pattern += std::to_string(checkerboard.data_for_compute[m][k]);
                break;
            }

        }
    }
    if (score_map.find(pattern) != score_map.end()) {
        machine_score += score_map[pattern];
    }

    //向右上搜索棋型
    pattern = "";
    position_color = -1;

    for (int m = x + 1, k = y - 1; m < 15 && k > 0; m++, k--) {
        if (checkerboard.data_for_compute[m][k] == -1) {
            break;
        } else {
            if (position_color == -1) {
                position_color = checkerboard.data_for_compute[m][k];
                pattern += std::to_string(checkerboard.data_for_compute[m][k]);
            } else if (position_color == checkerboard.data_for_compute[m][k]) {
                pattern += std::to_string(checkerboard.data_for_compute[m][k]);
            } else {
                pattern += std::to_string(checkerboard.data_for_compute[m][k]);
                break;
            }

        }
    }
    if (score_map.find(pattern) != score_map.end()) {
        machine_score += score_map[pattern];
    }

    //向右下搜索棋型
    pattern = "";
    position_color = -1;
    for (int m = x + 1, k = y + 1; m < 15 && k < 15; m++, k++) {
        if (checkerboard.data_for_compute[m][k] == -1) {
            break;
        } else {
            if (position_color == -1) {
                position_color = checkerboard.data_for_compute[m][k];
                pattern += std::to_string(checkerboard.data_for_compute[m][k]);
            } else if (position_color == checkerboard.data_for_compute[m][k]) {
                pattern += std::to_string(checkerboard.data_for_compute[m][k]);
            } else {
                pattern += std::to_string(checkerboard.data_for_compute[m][k]);
                break;
            }

        }
    }
    if (score_map.find(pattern) != score_map.end()) {
        machine_score += score_map[pattern];
    }

    //向左下搜索棋型
    pattern = "";
    position_color = -1;
    for (int m = x - 1, k = y + 1; m > 0 && k < 15; m--, k++) {
        if (checkerboard.data_for_compute[m][k] == -1) {
            break;
        } else {
            if (position_color == -1) {
                position_color = checkerboard.data_for_compute[m][k];
                pattern += std::to_string(checkerboard.data_for_compute[m][k]);
            } else if (position_color == checkerboard.data_for_compute[m][k]) {
                pattern += std::to_string(checkerboard.data_for_compute[m][k]);
            } else {
                pattern += std::to_string(checkerboard.data_for_compute[m][k]);
                break;
            }

        }
    }
    if (score_map.find(pattern) != score_map.end()) {
        machine_score += score_map[pattern];
    }

    //检测是否出现禁手，如果出现禁手则score清零
    if (color == 1) {
        //如果电脑使用黑色棋子，则判断这个点会不会造成禁手
        Checkerboard temp_board_for_test_fobiddenhand;
        int converted_chess_data[15][15];

        for (int i = 0; i < 15; ++i) {
            for (int j = 0; j < 15; ++j) {
                temp_board_for_test_fobiddenhand.data_for_compute[i][j] = checkerboard.data_for_compute[i][j];
                if (checkerboard.data_for_compute[i][j] == -1)
                    converted_chess_data[i][j] = 0;
                else if (checkerboard.data_for_compute[i][j] == 0)
                    converted_chess_data[i][j] = 1;
                else
                    converted_chess_data[i][j] = 2;
            }
        }
        //暂时把这个黑色棋子落下
        temp_board_for_test_fobiddenhand.data_for_compute[x][y] = 1;
        temp_board_for_test_fobiddenhand.last_piece_color = 1;

        //测试落下后是否出现了禁手
        if (Judge::CountLiveThree(temp_board_for_test_fobiddenhand, converted_chess_data) > 1 ||
            Judge::CountFour(temp_board_for_test_fobiddenhand, converted_chess_data) || Judge::JudgeLongLink(
                temp_board_for_test_fobiddenhand, converted_chess_data)) {
            machine_score = 0;
        }
    }

    return machine_score;
}
