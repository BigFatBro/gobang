//
// Created by peter on 2021/11/9.
//

#include <iostream>
#include <string>
#include "Player.h"

Player::Player() {}

Player::Player(int player_color) {
    color = player_color;
}

ChessPiece Player::FetchAPiece() const {
    int piece_coloe = color;
    ChessPiece piece(piece_coloe);
    return piece;
}

int Player::Col_to_int(char col) {
    int result;
    if (col > 96)
        result = col - 96;
    else if (col > 64 && col < 97)
        result = col - 64;
    return result;
}

int Player::Row_to_int(int row) {
    return 15 - row;
}

void Player::PlayChess(Checkerboard &board, int round) const {
    std::string player_name;
    std::string piece_style;
    int row;
    char col;

    if (color == 0) {
        player_name = "��ɫ���";
        piece_style = " (��) ";
    } else {
        player_name = "��ɫ���";
        piece_style = " (��) ";
    }


    //���������������,������������
    //system("cls");
    board.ShowCheckerboard();
    std::cout << "\nRound " << round << ": " << player_name << piece_style << " �������������� (��:A1 �� a1):";
    std::cin >> col >> row;
    while (std::cin.fail()) {
        system("cls");
        board.ShowCheckerboard();
        std::cin.clear();
        std::cin.sync();
        std::cout << "\n����Ƿ�.\n�����������������꣺";
        std::cin >> col >> row;
    }

    //��ɫ���ӵĵ�һ�ű���������Ԫ
    if (round == 1 && color == 1) {
        while ((col != 'H' && row != 8) || (col != 'h' && row != 8)) {
            system("cls");
            board.ShowCheckerboard();
            std::cout << "\n��һ�����ӱ���������Ԫ��H8.\n�����������������꣺";
            scanf("%c%d", &col, &row);
        }
    }

    //�ж����������Ƿ���������
    while (((col > 79 && col < 97) || col < 65 || col > 111) || row > 15 || row < 1) {
        system("cls");
        board.ShowCheckerboard();
        std::cout << "\n����Ƿ�.\n�����������������꣺";
        std::cin >> col >> row;
        while (std::cin.fail()) {
            system("cls");
            board.ShowCheckerboard();
            std::cin.clear();
            std::cin.sync();
            std::cout << "\n����Ƿ�.\n�����������������꣺";
            std::cin >> col >> row;
        }
    }

    //���û��������������ת���������ڵ�����
    int x, y;
    while (true) {
        x = Row_to_int(row);
        y = Col_to_int(col);
        //std::cout<<"row:"<<row<<" col:"<<col<<std::endl;
        //std::cout <<"x:"<<x <<" y:"<< y << std::endl;
        int is_there_have_piece = board.IsHavePiece(x, y);
        //std::cout << is_there_have_piece << std::endl;
        if (is_there_have_piece != -1) {
            //��������괦�Ѿ�������
            system("cls");
            board.ShowCheckerboard();
            std::cout << "\n��������괦�������ӡ�\n�����������������꣺";
            std::cin >> col >> row;
            while (std::cin.fail()) {
                system("cls");
                board.ShowCheckerboard();
                std::cin.clear();
                std::cin.sync();
                std::cout << "\n����Ƿ�.\n������������������:";
                std::cin >> col >> row;
            }
        } else
            //��������괦������
            break;
    }

    //������д������
    ChessPiece piece = FetchAPiece();
    //std::cout<<"���꣺x:"<<x<<" y:"<<y<<std::endl;
    //std::cout<<"piece color:"<<piece.color<<std::endl;
    board.SendPiece(x, y, piece);


}
