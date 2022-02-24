//
// Created by peter on 2021/11/9.
//

#ifndef GOBANG_PLAYER_H
#define GOBANG_PLAYER_H


#include "ChessPiece.h"
#include "Checkerboard.h"

class Player {
public:
    int color;//玩家所执颜色，白：0, 黑：1
    Player(int player_color);

    Player();

    ChessPiece FetchAPiece() const;

    void PlayChess(Checkerboard &board, int round) const;//落子
    static int Col_to_int(char col);//将用户输入的棋子的列坐标由英文字符转变成整数
    static int Row_to_int(int row);//将用户输入的棋子的行坐标由从数字转变成二位数组的索引
};


#endif //GOBANG_PLAYER_H
