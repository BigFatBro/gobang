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

//��Ϸ�࣬����һ��
class Game {
public:

    Game();

    Player player_1;
    Player player_2;
    Machine machine_2;
    Checkerboard checkerboard;
    Judge judge;
    int game_mode;//��Ϸģʽ��1�����˶�ս  2���˻���ս
    int fist_hand_player;//���ֵ���ң�1��player_1 2��player_2
    int game_round = 1;

    void InitGame();//��ʼ��
    void SelectMode();//ѡ���սģʽ
    void SelectFirstHand();//ѡ������
    void RunGame();//��ʼ��Ϸ
    void PlayAgain();

    void ShowWinner(int winner_color);

    void ShowPlayer();

    void ManManCombat();

    void ManMachineCombat();


};


#endif //GOBANG_GAME_H
