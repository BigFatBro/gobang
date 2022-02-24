//
// Created by peter on 2021/11/9.
//

#include "Judge.h"
#include <iostream>


int Judge::IsDisallowed(Checkerboard board) {
    //�����Ƿ񴥷����ֹ���
    int judge_result = 0;
    //Ϊ�˷�����㣬��Ҫ����ά����board.data_for_compute��һЩת��
    int converted_chess_data[15][15];
    for (int m = 0; m < 15; m++) {
        for (int n = 0; n < 15; n++) {
            if (board.data_for_compute[m][n] == -1)
                converted_chess_data[m][n] = 0;
            else if (board.data_for_compute[m][n] == 0)
                converted_chess_data[m][n] = 1;
            else
                converted_chess_data[m][n] = 2;
        }
    }


    if (CountLiveThree(board, converted_chess_data) > 1) {
        std::cout << "���崥����������" << std::endl;
        judge_result = 1;
    }
    if (CountFour(board, converted_chess_data) > 1) {
        std::cout << "���崥�����Ľ���" << std::endl;
        judge_result = 2;
    }
    if (JudgeLongLink(board, converted_chess_data)) {
        std::cout << "���崥����������" << std::endl;
        judge_result = 3;
    }
    return judge_result;
}

int Judge::CountLiveThree(Checkerboard board, int chess_data[15][15]) {

    //���ػ����ĸ���
    int color, opponent_color;
    if (board.last_piece_color == 0) {
        //������
        color = 1;
        opponent_color = 2;
    } else {
        //����
        color = 2;
        opponent_color = 1;
    }

    int live_three_count = 0;
    int pi = 22, pj = 22;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 10; j++) {
            if ((i != pi || j != pj + 1) && chess_data[i][j] == 0 && chess_data[i][j + 1] != opponent_color && chess_data[i][j + 2] != opponent_color && chess_data[i][j + 3] != opponent_color && chess_data[i][j + 4] != opponent_color && chess_data[i][j + 5] == 0 && (chess_data[i][j + 1] + chess_data[i][j + 2] + chess_data[i][j + 3] + chess_data[i][j + 4]) == 3 * color) {
                live_three_count++;
                //std::cout << "���� �� �����" << std::endl;
                pi = i;
                pj = j;
            }
        }
    }

    pi = 22;
    pj = 22;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 15; j++) {
            if ((i != pi + 1 || j != pj) && chess_data[i][j] == 0 && chess_data[i + 1][j] != opponent_color && chess_data[i + 2][j] != opponent_color && chess_data[i + 3][j] != opponent_color && chess_data[i + 4][j] != opponent_color && chess_data[i + 5][j] == 0 && (chess_data[i + 1][j] + chess_data[i + 2][j] + chess_data[i + 3][j] + chess_data[i + 4][j]) == 3 * color) {
                live_three_count++;
                //std::cout << "���� �� �����" << std::endl;
                pi = i;
                pj = j;
            }
        }
    }

    pi = 22;
    pj = 22;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if ((i != pi + 1 || j != pj + 1) && chess_data[i][j] == 0 && chess_data[i + 1][j + 1] != opponent_color && chess_data[i + 2][j + 2] != opponent_color && chess_data[i + 3][j + 3] != opponent_color && chess_data[i + 4][j + 4] != opponent_color && chess_data[i + 5][j + 5] == 0 && (chess_data[i + 1][j + 1] + chess_data[i + 2][j + 2] + chess_data[i + 3][j + 3] +chess_data[i + 4][j + 4]) == 3 * color) {
                live_three_count++;
                pi = i;
                pj = j;
            }
        }
    }

    pi = 22;
    pj = 22;
    for (int i = 0; i < 10; i++) {
        for (int j = 5; j < 15; j++) {
            if ((i != pi + 1 || j != pj - 1) && chess_data[i][j] == 0 && chess_data[i + 1][j - 1] != opponent_color && chess_data[i + 2][j - 2] != opponent_color && chess_data[i + 3][j - 3] != opponent_color && chess_data[i + 4][j - 4] != opponent_color && chess_data[i + 5][j - 5] == 0 &&(chess_data[i + 1][j - 1] + chess_data[i + 2][j - 2] + chess_data[i + 3][j - 3] + chess_data[i + 4][j - 4]) == 3 * color) {
                live_three_count++;
                pi = i;
                pj = j;
            }
        }
    }

    //std::cout << "��������:" << live_three_count << std::endl;
    return live_three_count;
}


int Judge::CountFour(Checkerboard board, int chess_data[15][15]) {
    //������ġ����ĵĸ���
    int color, opponent_color;
    if (board.last_piece_color == 0) {
        //����
        color = 1;
        opponent_color = 2;
    } else {
        //����
        color = 2;
        opponent_color = 1;
    }

    int four_count = 0;
    int pi = 22, pj = 22;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 11; j++) {
            if ((i != pi || j != pj + 1) && chess_data[i][j] != opponent_color && chess_data[i][j + 1] != opponent_color && chess_data[i][j + 2] != opponent_color && chess_data[i][j + 3] != opponent_color && chess_data[i][j + 4] != opponent_color && (chess_data[i][j] + chess_data[i][j + 1] + chess_data[i][j + 2] + chess_data[i][j + 3] + chess_data[i][j + 4]) == 4 * color) {
                four_count++;
                pi = i;
                pj = j;
            }
        }
    }

    pi = 22;
    pj = 22;
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 15; j++) {
            if ((i != pi + 1 || j != pj) && chess_data[i][j] != opponent_color && chess_data[i + 1][j] != opponent_color && chess_data[i + 2][j] != opponent_color &&chess_data[i + 3][j] != opponent_color && chess_data[i + 4][j] != opponent_color &&(chess_data[i][j] + chess_data[i + 1][j] + chess_data[i + 2][j] + chess_data[i + 3][j] + chess_data[i + 4][j]) == 4 * color) {
                four_count++;
                pi = i;
                pj = j;
            }
        }
    }

    pi = 22;
    pj = 22;
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            if ((i != pi + 1 || j != pj + 1) && chess_data[i][j] != opponent_color && chess_data[i + 1][j + 1] != opponent_color && chess_data[i + 2][j + 2] != opponent_color && chess_data[i + 3][j + 3] != opponent_color && chess_data[i + 4][j + 4] != opponent_color &&(chess_data[i][j] + chess_data[i + 1][j + 1] + chess_data[i + 2][j + 2] + chess_data[i + 3][j + 3] + chess_data[i + 4][j + 4]) == 4 * color) {
                four_count++;
                pi = i;
                pj = j;
            }
        }
    }

    pi = 22;
    pj = 22;
    for (int i = 0; i < 11; i++) {
        for (int j = 4; j < 15; j++) {
            if ((i != pi + 1 || j != pj - 1) && chess_data[i][j] != opponent_color && chess_data[i + 1][j - 1] != opponent_color && chess_data[i + 2][j - 2] != opponent_color && chess_data[i + 3][j - 3] != opponent_color && chess_data[i + 4][j - 4] != opponent_color &&(chess_data[i][j] + chess_data[i + 1][j - 1] + chess_data[i + 2][j - 2] + chess_data[i + 3][j - 3] + chess_data[i + 4][j - 4]) == 4 * color) {
                four_count++;
                pi = i;
                pj = j;
            }
        }
    }

    return four_count;
}

int Judge::JudgeLongLink(Checkerboard board, int chess_data[15][15]) {
    //�ж��Ƿ���ڳ���������ֵ����0����ڳ���
    //����
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 10; j++) {
            if (chess_data[i][j] == 2 && chess_data[i][j + 1] == 2 && chess_data[i][j + 2] == 2 && chess_data[i][j + 3] == 2 && chess_data[i][j + 4] == 2 && chess_data[i][j + 5] == 2) {
                return 1;
            }
        }
    }

    //����
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 15; j++) {
            if (chess_data[i][j] == 2 && chess_data[i + 1][j] == 2 && chess_data[i + 2][j] == 2 && chess_data[i + 3][j] == 2 && chess_data[i + 4][j] == 2 && chess_data[i + 5][j] == 2) {
                return 1;
            }
        }
    }

    //��\����
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (chess_data[i][j] == 2 && chess_data[i + 1][j + 1] == 2 && chess_data[i + 2][j + 2] == 2 && chess_data[i + 3][j + 3] == 2 && chess_data[i + 4][j + 4] == 2 && chess_data[i + 5][j + 5] == 2) {
                return 1;
            }
        }
    }

    //��/����
    for(int i = 0; i < 10; i++) {
        for(int j = 5; j < 15; j++) {
            if (chess_data[i][j] == 2 && chess_data[i + 1][j - 1] == 2 && chess_data[i + 2][j - 2] == 2 && chess_data[i + 3][j - 3] == 2 && chess_data[i + 4][j - 4] == 2 && chess_data[i + 5][j - 5] == 2) {
                return 1;
            }
        }
    }

    return 0;
}

int Judge::JudgeFiveLink(Checkerboard board) {
    //�ж��Ƿ��������������ֵ����0���������
    if (board.last_piece_color == 0) {
        for (auto & i : board.data_for_compute) {
            for (int j = 0; j < 11; j++) {
                if (i[j] == 0 && i[j + 1] == 0 &&i[j + 2] == 0 && i[j + 3] == 0 && i[j + 4] == 0) {
                    return 1;
                }
            }
        }
    } else {
        for (auto & i : board.data_for_compute) {
            for (int j = 0; j < 11; j++) {
                if (i[j] == 1 && i[j + 1] == 1 && i[j + 2] == 1 && i[j + 3] == 1 && i[j + 4] == 1) {
                    return 1;
                }
            }
        }
    }
    if (board.last_piece_color == 0) {
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 15; j++) {
                if (board.data_for_compute[i][j] == 0 && board.data_for_compute[i + 1][j] == 0 && board.data_for_compute[i + 2][j] == 0 && board.data_for_compute[i + 3][j] == 0 && board.data_for_compute[i + 4][j] == 0) {
                    return 1;
                }
            }
        }
    } else {
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 15; j++) {
                if (board.data_for_compute[i][j] == 1 && board.data_for_compute[i + 1][j] == 1 && board.data_for_compute[i + 2][j] == 1 && board.data_for_compute[i + 3][j] == 1 && board.data_for_compute[i + 4][j] == 1) {
                    return 1;
                }
            }
        }
    }
    if (board.last_piece_color == 0) {
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                if (board.data_for_compute[i][j] == 0 && board.data_for_compute[i + 1][j + 1] == 0 && board.data_for_compute[i + 2][j + 2] == 0 && board.data_for_compute[i + 3][j + 3] == 0 && board.data_for_compute[i + 4][j + 4] == 0) {
                    return 1;
                }
            }
        }
    } else {
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                if (board.data_for_compute[i][j] == 1 && board.data_for_compute[i + 1][j + 1] == 1 && board.data_for_compute[i + 2][j + 2] == 1 && board.data_for_compute[i + 3][j + 3] == 1 && board.data_for_compute[i + 4][j + 4] == 1) {
                    return 1;
                }
            }
        }
    }
    if (board.last_piece_color == 0) {
        for (int i = 0; i < 11; i++) {
            for (int j = 4; j < 15; j++) {
                if (board.data_for_compute[i][j] == 0 && board.data_for_compute[i + 1][j - 1] == 0 && board.data_for_compute[i + 2][j - 2] == 0 && board.data_for_compute[i + 3][j - 3] == 0 && board.data_for_compute[i + 4][j - 4] == 0) {
                    return 1;
                }
            }
        }
    } else {
        for (int i = 0; i < 11; i++) {
            for (int j = 4; j < 15; j++) {
                if (board.data_for_compute[i][j] == 1 && board.data_for_compute[i + 1][j - 1] == 1 && board.data_for_compute[i + 2][j - 2] == 1 && board.data_for_compute[i + 3][j - 3] == 1 && board.data_for_compute[i + 4][j - 4] == 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int Judge::JusgeDraw(Checkerboard board) {
    // �ж��Ƿ������ƽ�֣��������һ����⣩,����0����û�г���ƽ�֣�����1���������ƽ��
    for(auto & i : board.data_for_compute){
        for(int j : i){
            if(j == -1)
                return 0;
        }
    }
    return 1;
}
