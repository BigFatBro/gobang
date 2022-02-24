//
// Created by Peter on 2021/11/13.
//

#ifndef GOBANG_MACHINE_H
#define GOBANG_MACHINE_H


#include "ChessPiece.h"
#include "Checkerboard.h"

class Machine {
public:
    int color;//玩家所执颜色，白：0, 黑：1
    Machine();

    Machine(int machine_color);

    void SetColor(int machine_color);

    ChessPiece FetchAPiece() const;

    char Col_int_to_char(int col);

    void PlayChess(Checkerboard &board, int round);//落子
    int ComputePointScore(Checkerboard checkerboard, int x, int y) const;

};


#endif //GOBANG_MACHINE_H
