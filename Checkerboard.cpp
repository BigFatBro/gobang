//
// Created by peter on 2021/11/9.
//

#include <cstdio>
#include <iostream>
#include "Checkerboard.h"

Checkerboard::Checkerboard() {
    last_black_piece_x = -1;
    last_black_piece_y = -1;
    last_white_piece_x = -1;
    last_white_piece_y = -1;
    last_piece_color = -1;

    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 16; j++)
            color_data[i][j] = -1;

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            data_for_compute[i][j] = -1;

}


void Checkerboard::ShowCheckerboard() {
    std::cout << "\n\t五子棋游戏(黑色方:● 白色方:○)\n\n";


    if (data_for_compute[0][0] == -1) {
        std::cout << "\t15┏ ";
    } else {
        if (data_for_compute[0][0] == 1) {
            if (last_black_piece_x == 0 && last_black_piece_y == 0)
                std::cout << "\t15▲";
            else
                std::cout << "\t15●";
        } else {
            if (last_white_piece_x == 0 && last_white_piece_y == 0)
                std::cout << "\t15△";
            else
                std::cout << "\t15○";
        }

    }
    for (int j = 1, i = 0; j < 14; j++) {
        if (data_for_compute[i][j] == -1) {
            std::cout << "┯ ";
        } else {
            if (data_for_compute[i][j] == 1) {
                if (last_black_piece_x == i && last_black_piece_y == j)
                    std::cout << "▲";
                else
                    std::cout << "●";

            } else {
                if (last_white_piece_x == i && last_white_piece_y == j)
                    std::cout << "△";
                else
                    std::cout << "○";
            }

        }
    }

    if (data_for_compute[0][14] == -1) {
        std::cout << "┓" << std::endl;
    } else {
        if (data_for_compute[0][14] == 1) {
            if (last_black_piece_x == 0 && last_black_piece_y == 14)
                std::cout << "▲" << std::endl;
            else
                std::cout << "●" << std::endl;
        } else {
            if (last_white_piece_x == 0 && last_white_piece_y == 14)
                std::cout << "△" << std::endl;
            else
                std::cout << "○" << std::endl;
        }

    }

    for (int i = 1; i < 14; i++) {
        if (data_for_compute[i][0] == -1) {
            printf("\t%2d┠ ", 15 - i);
        } else {
            if (data_for_compute[i][0] == 1) {
                if (last_black_piece_x == i && last_black_piece_y == 0)
                    printf("\t%2d▲", 15 - i);
                else
                    printf("\t%2d●", 15 - i);
            } else {
                if (last_white_piece_x == i && last_white_piece_y == 0)
                    printf("\t%2d△", 15 - i);
                else
                    printf("\t%2d○", 15 - i);
            }

        }
        for (int j = 1; j < 14; j++) {
            if (data_for_compute[i][j] == -1) {
                std::cout << "┼ ";
            } else {
                if (data_for_compute[i][j] == 1) {
                    if (last_black_piece_x == i && last_black_piece_y == j)
                        std::cout << "▲";
                    else
                        std::cout << "●";
                } else {
                    //白色棋子
                    if (last_white_piece_x == i && last_white_piece_y == j)
                        std::cout << "△";
                    else
                        std::cout << "○";

                }
            }
        }
        if (data_for_compute[i][14] == -1) {
            std::cout << "┨" << std::endl;
        } else {
            if (data_for_compute[i][14] == 1) {
                if (last_black_piece_x == i && last_black_piece_y == 14)
                    std::cout << "▲" << std::endl;
                else
                    std::cout << "●" << std::endl;
            } else {
                if (last_white_piece_x == i && last_white_piece_y == 14)
                    std::cout << "△" << std::endl;
                else
                    std::cout << "○" << std::endl;
            }

        }
    }

    if (data_for_compute[14][0] == -1) {
        std::cout << "\t 1┗ ";
    } else {
        if (data_for_compute[14][0] == 1) {
            if (last_black_piece_x == 14 && last_black_piece_y == 0)
                std::cout << "\t 1▲";
            else
                std::cout << "\t 1●";
        } else {
            if (last_white_piece_x == 14 && last_white_piece_y == 0)
                std::cout << "\t 1△";
            else
                std::cout << "\t 1○";
        }

    }

    for (int j = 1; j < 14; j++) {
        if (data_for_compute[14][j] == -1) {
            std::cout << "┷ ";
        } else {
            if (data_for_compute[14][j] == 1) {
                if (last_black_piece_x == 14 && last_black_piece_y == j)
                    std::cout << "▲";
                else
                    std::cout << "●";
            } else {
                if (last_white_piece_x == 14 && last_white_piece_y == j)
                    std::cout << "△";
                else
                    std::cout << "○";
            }

        }
    }

    if (data_for_compute[14][14] == -1) {
        std::cout << "┛" << std::endl;
    } else {
        if (data_for_compute[14][14] == 1) {
            if (last_black_piece_x == 14 && last_black_piece_y == 14)
                std::cout << "▲" << std::endl;
            else
                std::cout << "●" << std::endl;
        } else {
            if (last_white_piece_x == 14 && last_white_piece_y == 14)
                std::cout << "△" << std::endl;
            else
                std::cout << "○" << std::endl;
        }

    }

    std::cout << "\t ";
    char col_tags[15] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O'};
    for (char col_tag: col_tags) {
        printf(" %c", col_tag);
    }
    std::cout << std::endl;


}

void Checkerboard::SendPiece(int x, int y, ChessPiece piece) {
    //记录颜色
    color_data[x][y] = piece.color;
    //再记录一遍
    data_for_compute[x][y - 1] = piece.color;

    //记录一下最新落下棋子的颜色,并把新落下的字的位置记下
    if (piece.color == 0) {
        last_piece_color = 0;
        last_white_piece_x = x;
        last_white_piece_y = y - 1;
    } else {
        last_piece_color = 1;
        last_black_piece_x = x;
        last_black_piece_y = y - 1;
    }
}

int Checkerboard::IsHavePiece(int x, int y) {
    return color_data[x][y];
}
