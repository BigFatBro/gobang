//
// Created by peter on 2021/11/9.
//

#ifndef GOBANG_CHECKERBOARD_H
#define GOBANG_CHECKERBOARD_H
#define ROW 16
#define COL 16

#include "ChessPiece.h"


class Checkerboard {
public:
    int color_data[ROW][COL];//记录棋盘各个坐标处的棋子颜色，-1：无棋子，0：白色棋子，1：黑色棋子
    int data_for_compute[15][15];
    int last_black_piece_x;
    int last_black_piece_y;
    int last_white_piece_x;
    int last_white_piece_y;
    int last_piece_color;//last_piece_color最新落下的棋子的颜色，0：白色，1：黑色

    Checkerboard();
    void ShowCheckerboard();//输出棋盘现状
    void SendPiece(int x, int y, ChessPiece piece);//落下新的棋子
    int IsHavePiece(int x, int y);//通过输入的坐标判断有无棋子，-1：无棋子，0：白色棋子，1：黑色棋子
};


#endif //GOBANG_CHECKERBOARD_H
