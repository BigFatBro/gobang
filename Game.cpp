//
// Created by peter on 2021/11/9.
//

#include "Game.h"


Game::Game() {

}

void Game::InitGame() {
    //打印棋盘和欢迎提示
    Checkerboard board;
    checkerboard = board;
    checkerboard.ShowCheckerboard();
    //游戏模式选择
    SelectMode();
    //先手选择
    SelectFirstHand();
}

void Game::SelectMode() {
    int mode = 0;

    std::cout << "\n请选择游戏模式.\n 模式 1: 人人对战\n 模式 2: 人机对战\n 您的选择(输入 1 或者 2 ):";
    std::cin >> mode;

    while (mode != 1 && mode != 2) {
        std::cout << "您的输入有误.\n请重新选择游戏模式(输入 1 或者 2 ):";
        std::cin.clear();
        std::cin.sync();
        std::cin >> mode;
    }

    game_mode = mode;
}

void Game::SelectFirstHand() {
    int selected_first_hand_player = -1;

    if (game_mode == 1)
        std::cout << "\n您的选择是: 人人对战\n 玩家列表: 玩家_1 , 玩家_2\n 请选择先手玩家 (先手玩家使用黑色棋子).\n 您的选择是(输入 1 或者 2 ):";
    else
        std::cout << "\n您的选择是: 人机对战\n 玩家列表: 玩家_1 , 电脑\n 请选择先手玩家 (先手玩家使用黑色棋子).\n 您的选择是(输入 1 或者 2 ):";

    std::cin >> selected_first_hand_player;
    while (selected_first_hand_player != 1 && selected_first_hand_player != 2) {
        std::cout << "您的输入有误.\n请重新选择先手玩家(输入 1 或者 2 ):";
        std::cin.clear(); //清除流标记
        std::cin.sync();  //清空流
        std::cin >> selected_first_hand_player;
    }

    fist_hand_player = selected_first_hand_player;
    if (fist_hand_player == 1 && game_mode == 1) {
        //1号玩家是先手，且游戏模式是人人对战
        //先手玩家使用黑色
        player_1.color = 1;
        player_2.color = 0;
    } else if (fist_hand_player == 1 && game_mode == 2) {
        //1号玩家(人类）是先手，且游戏模式是人机对战
        player_1.color = 1;
        machine_2.SetColor(0);
    } else if (fist_hand_player == 2 && game_mode == 1) {
        //2号玩家为先手，且游戏模式是人人对战
        player_2.color = 1;
        player_1.color = 0;
    } else if (fist_hand_player == 2 && game_mode == 2) {
        //先手玩家使用黑色，且游戏模式是人机对战
        machine_2.SetColor(1);
        player_1.color = 0;
    }
}

void Game::RunGame() {
    if (game_mode == 1) {
        //std::cout << "人人对战";
        ManManCombat();
    } else {
        //std::cout << "人机对战";
        ManMachineCombat();
    }

}

void Game::ManManCombat() {
    //system("cls");
    while (true) {
        //下棋
        if (fist_hand_player == 1) {

            player_1.PlayChess(checkerboard, game_round);
            //std::cout<<"玩家一下完,round"<<game_round<<std::endl;
            //检查禁手
            if (judge.IsDisallowed(checkerboard)) {
                //白棋胜
                std::cout << "黑棋禁手！" << std::endl;
                ShowWinner(0);
                break;

            }
            //检查是否出现五连
            if (judge.JudgeFiveLink(checkerboard)) {
                std::cout << "黑棋五连！" << std::endl;
                ShowWinner(1);
                break;
            }
            if (judge.JusgeDraw(checkerboard)) {
                std::cout << "平局！" << std::endl;
                break;
            }


            player_2.PlayChess(checkerboard, game_round);
            //std::cout<<"玩家二下完,round"<<game_round<<std::endl;
            //检查白棋是否出现五连
            if (judge.JudgeFiveLink(checkerboard)) {
                std::cout << "白棋五连!" << std::endl;
                ShowWinner(0);
                break;
            }
            if (judge.JusgeDraw(checkerboard)) {
                std::cout << "平局！" << std::endl;
                break;
            }

        } else {

            player_2.PlayChess(checkerboard, game_round);
            //检查禁手
            //检查禁手
            if (judge.IsDisallowed(checkerboard)) {
                //白棋胜
                std::cout << "黑棋禁手！" << std::endl;
                ShowWinner(0);
                break;

            }
            //检查是否出现五连
            if (judge.JudgeFiveLink(checkerboard)) {
                std::cout << "黑棋五连！" << std::endl;
                ShowWinner(1);
                break;
            }
            if (judge.JusgeDraw(checkerboard)) {
                std::cout << "平局！" << std::endl;
                break;
            }


            player_1.PlayChess(checkerboard, game_round);
            //检查白棋是否出现五连
            if (judge.JudgeFiveLink(checkerboard)) {
                std::cout << "白棋五连!" << std::endl;
                ShowWinner(0);
                break;
            }
            if (judge.JusgeDraw(checkerboard)) {
                std::cout << "平局！" << std::endl;
                break;
            }
        }
        game_round = game_round + 1;
    }
    PlayAgain();
}

void Game::ManMachineCombat() {
    system("cls");
    while (true) {

        if (fist_hand_player == 1) {
            //人先手

            player_1.PlayChess(checkerboard, game_round);
            //std::cout<<"玩家一下完,round"<<game_round<<std::endl;
            //检查禁手
            if (judge.IsDisallowed(checkerboard)) {
                //白棋胜
                std::cout << "黑棋禁手！" << std::endl;
                ShowWinner(0);
                break;
            }
            //检查是否出现五连
            if (judge.JudgeFiveLink(checkerboard)) {
                std::cout << "黑棋五连！" << std::endl;
                ShowWinner(1);
                break;
            }
            if (judge.JusgeDraw(checkerboard)) {
                std::cout << "平局！" << std::endl;
                break;
            }


            std::cout << "Round " << game_round << "：";
            machine_2.PlayChess(checkerboard, game_round);
            //std::cout<<"玩家二下完,round"<<game_round<<std::endl;
            //检查白棋是否出现五连
            if (judge.JudgeFiveLink(checkerboard)) {
                std::cout << "白棋五连!" << std::endl;
                ShowWinner(0);
                break;
            }
            if (judge.JusgeDraw(checkerboard)) {
                std::cout << "平局！" << std::endl;
                break;
            }

        } else {
            //机器先手
            std::cout << "Round " << game_round << "：";
            machine_2.PlayChess(checkerboard, game_round);
            //检查禁手
            //检查禁手
            if (judge.IsDisallowed(checkerboard)) {
                //白棋胜
                std::cout << "黑棋禁手！" << std::endl;
                ShowWinner(0);
                break;

            }
            //检查是否出现五连
            if (judge.JudgeFiveLink(checkerboard)) {
                std::cout << "黑棋五连" << std::endl;
                ShowWinner(1);
                break;
            }
            if (judge.JusgeDraw(checkerboard)) {
                std::cout << "平局！" << std::endl;
                break;
            }


            player_1.PlayChess(checkerboard, game_round);
            //检查白棋是否出现五连
            if (judge.JudgeFiveLink(checkerboard)) {
                std::cout << "白棋五连！" << std::endl;
                ShowWinner(0);
                break;
            }

            if (judge.JusgeDraw(checkerboard)) {
                std::cout << "平局！" << std::endl;
                break;
            }
        }
        game_round = game_round + 1;

    }
    PlayAgain();
}

void Game::PlayAgain() {
    //询问用户是否再来一局
    int is_play_again;
    std::cout << "\n是否再战一局？【1】是  【2】否.\n 您的选择是(输入 1 或者 2 ):";

    std::cin >> is_play_again;
    while (is_play_again != 1 && is_play_again != 2) {
        std::cout << "您的输入有误.\n是否再战一局？【1】是  【2】否.\n 您的选择是(输入 1 或者 2 ):";
        std::cin.clear();
        std::cin.sync();
        std::cin >> is_play_again;
    }
    if (is_play_again == 1) {
        //重置回合数
        game_round = 1;
        //棋手交换颜色
        if (game_mode == 1) {
            //交换两个真人玩家的颜色
            int temp = player_1.color;
            player_1.color = player_2.color;
            player_2.color = temp;

        } else {
            //交换人和电脑的颜色
            int temp = player_1.color;
            player_1.color = machine_2.color;
            machine_2.color = temp;

        }

        //更新先手玩家
        if (player_1.color == 1)
            fist_hand_player = 1;
        else
            fist_hand_player = 2;

        //重置棋盘
        Checkerboard board;
        checkerboard = board;
        checkerboard.ShowCheckerboard();

        system("cls");
        //提示游戏双方已交换棋子颜色
        std::cout << "【注意】玩家已交换棋子颜色：" << std::endl;
        ShowPlayer();

        //再次开始对战
        if (game_mode == 1) {
            //std::cout << "人人对战";
            ManManCombat();
        } else {
            //std::cout << "人机对战";
            ManMachineCombat();
        }
    } else {
        std::cout << "游戏结束！" << std::endl;
    }
}


void Game::ShowWinner(int winner_color) {
    std::string winner_color_string;
    if (winner_color == 0)
        winner_color_string = "白色";
    else
        winner_color_string = "黑色";
    if (game_mode == 1) {
        //人人对战
        if (player_1.color == winner_color) {
            std::cout << "玩家1（" << winner_color_string << ")获胜！" << std::endl;
        } else {
            std::cout << "玩家2（" << winner_color_string << ")获胜！" << std::endl;
        }
    } else {
        //人机对战
        if (player_1.color == winner_color) {
            std::cout << "玩家1（" << winner_color_string << ")获胜！" << std::endl;
        } else {
            std::cout << "电脑（" << winner_color_string << ")获胜！" << std::endl;
        }
    }

}

void Game::ShowPlayer() {
    //打印玩家所持颜色
    if (game_mode == 1) {
        //人人对战模式
        if (player_1.color == 1) {
            std::cout << "玩家1为黑方，使用： 黑色棋子 (●) " << std::endl;
            std::cout << "玩家2为白方，使用： 白色棋子 (○) " << std::endl;
        } else {
            std::cout << "玩家1为白方，使用： 白色棋子 (○) " << std::endl;
            std::cout << "玩家2为黑方，使用： 黑色棋子 (●) " << std::endl;
        }

    } else {
        //人机对战模式
        if (player_1.color == 1) {
            std::cout << "玩家1为黑方，使用： 黑色棋子 (●) " << std::endl;
            std::cout << "电脑为白方，使用： 白色棋子 (○) " << std::endl;
        } else {
            std::cout << "玩家1为白方，使用： 白色棋子 (○) " << std::endl;
            std::cout << "电脑为黑方，使用： 黑色棋子 (●) " << std::endl;
        }
    }

    std::cout << "黑方为先手！" << std::endl;


}


