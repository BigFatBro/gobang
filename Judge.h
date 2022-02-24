//
// Created by peter on 2021/11/9.
//

#ifndef GOBANG_JUDGE_H
#define GOBANG_JUDGE_H


#include "Checkerboard.h"

class Judge {
public:

    static int IsDisallowed(Checkerboard board);

    static int CountLiveThree(Checkerboard board, int chess_data[15][15]);

    static int CountFour(Checkerboard board, int chess_data[15][15]);

    static int JudgeLongLink(Checkerboard board, int chess_data[15][15]);

    static int JudgeFiveLink(Checkerboard board);

    static int JusgeDraw(Checkerboard board);

};


#endif //GOBANG_JUDGE_H
