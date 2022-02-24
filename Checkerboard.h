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
    int color_data[ROW][COL];//��¼���̸������괦��������ɫ��-1�������ӣ�0����ɫ���ӣ�1����ɫ����
    int data_for_compute[15][15];
    int last_black_piece_x;
    int last_black_piece_y;
    int last_white_piece_x;
    int last_white_piece_y;
    int last_piece_color;//last_piece_color�������µ����ӵ���ɫ��0����ɫ��1����ɫ

    Checkerboard();
    void ShowCheckerboard();//���������״
    void SendPiece(int x, int y, ChessPiece piece);//�����µ�����
    int IsHavePiece(int x, int y);//ͨ������������ж��������ӣ�-1�������ӣ�0����ɫ���ӣ�1����ɫ����
};


#endif //GOBANG_CHECKERBOARD_H
