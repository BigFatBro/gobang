//
// Created by peter on 2021/11/9.
//

#ifndef GOBANG_GAME_H
#define GOBANG_GAME_H

#include <iostream>
#include "Player.h"
#include "Checkerboard.h"
#include "Judge.h"
#include "Machine.h"

//游戏类，控制一切
class Game {
public:

    Game();

    Player player_1;
    Player player_2;
    Machine machine_2;
    Checkerboard checkerboard;
    Judge judge;
    int game_mode;//游戏模式，1：人人对战  2：人机对战
    int fist_hand_player;//先手的玩家，1：player_1 2：player_2
    int game_round = 1;

    void InitGame();//初始化
    void SelectMode();//选择对战模式
    void SelectFirstHand();//选择先手
    void RunGame();//开始游戏
    void PlayAgain();

    void ShowWinner(int winner_color);

    void ShowPlayer();

    void ManManCombat();

    void ManMachineCombat();


};


#endif //GOBANG_GAME_H
