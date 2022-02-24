//
// Created by peter on 2021/11/9.
//

#ifndef GOBANG_PLAYER_H
#define GOBANG_PLAYER_H


#include "ChessPiece.h"
#include "Checkerboard.h"

class Player {
public:
    int color;//�����ִ��ɫ���ף�0, �ڣ�1
    Player(int player_color);

    Player();

    ChessPiece FetchAPiece() const;

    void PlayChess(Checkerboard &board, int round) const;//����
    static int Col_to_int(char col);//���û���������ӵ���������Ӣ���ַ�ת�������
    static int Row_to_int(int row);//���û���������ӵ��������ɴ�����ת��ɶ�λ���������
};


#endif //GOBANG_PLAYER_H
