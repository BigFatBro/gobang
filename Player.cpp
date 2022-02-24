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
        player_name = "白色玩家";
        piece_style = " (○) ";
    } else {
        player_name = "黑色玩家";
        piece_style = " (●) ";
    }


    //引导玩家输入坐标,并做好输入检查
    //system("cls");
    board.ShowCheckerboard();
    std::cout << "\nRound " << round << ": " << player_name << piece_style << " 请输入棋子坐标 (如:A1 或 a1):";
    std::cin >> col >> row;
    while (std::cin.fail()) {
        system("cls");
        board.ShowCheckerboard();
        std::cin.clear();
        std::cin.sync();
        std::cout << "\n输入非法.\n请重新输入棋子坐标：";
        std::cin >> col >> row;
    }

    //黑色棋子的第一颗必须落在天元
    if (round == 1 && color == 1) {
        while ((col != 'H' && row != 8) || (col != 'h' && row != 8)) {
            system("cls");
            board.ShowCheckerboard();
            std::cout << "\n第一颗棋子必须落在天元：H8.\n请重新输入棋子坐标：";
            scanf("%c%d", &col, &row);
        }
    }

    //判断棋子输入是否不在棋盘内
    while (((col > 79 && col < 97) || col < 65 || col > 111) || row > 15 || row < 1) {
        system("cls");
        board.ShowCheckerboard();
        std::cout << "\n输入非法.\n请重新输入棋子坐标：";
        std::cin >> col >> row;
        while (std::cin.fail()) {
            system("cls");
            board.ShowCheckerboard();
            std::cin.clear();
            std::cin.sync();
            std::cout << "\n输入非法.\n请重新输入棋子坐标：";
            std::cin >> col >> row;
        }
    }

    //将用户输入的棋子坐标转换成数组内的索引
    int x, y;
    while (true) {
        x = Row_to_int(row);
        y = Col_to_int(col);
        //std::cout<<"row:"<<row<<" col:"<<col<<std::endl;
        //std::cout <<"x:"<<x <<" y:"<< y << std::endl;
        int is_there_have_piece = board.IsHavePiece(x, y);
        //std::cout << is_there_have_piece << std::endl;
        if (is_there_have_piece != -1) {
            //输入的坐标处已经有棋子
            system("cls");
            board.ShowCheckerboard();
            std::cout << "\n输入的坐标处已有棋子。\n请重新输入棋子坐标：";
            std::cin >> col >> row;
            while (std::cin.fail()) {
                system("cls");
                board.ShowCheckerboard();
                std::cin.clear();
                std::cin.sync();
                std::cout << "\n输入非法.\n请重新输入棋子坐标:";
                std::cin >> col >> row;
            }
        } else
            //输入的坐标处无棋子
            break;
    }

    //把棋子写入棋盘
    ChessPiece piece = FetchAPiece();
    //std::cout<<"坐标：x:"<<x<<" y:"<<y<<std::endl;
    //std::cout<<"piece color:"<<piece.color<<std::endl;
    board.SendPiece(x, y, piece);


}
