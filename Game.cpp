//
// Created by peter on 2021/11/9.
//

#include "Game.h"


Game::Game() {

}

void Game::InitGame() {
    //��ӡ���̺ͻ�ӭ��ʾ
    Checkerboard board;
    checkerboard = board;
    checkerboard.ShowCheckerboard();
    //��Ϸģʽѡ��
    SelectMode();
    //����ѡ��
    SelectFirstHand();
}

void Game::SelectMode() {
    int mode = 0;

    std::cout << "\n��ѡ����Ϸģʽ.\n ģʽ 1: ���˶�ս\n ģʽ 2: �˻���ս\n ����ѡ��(���� 1 ���� 2 ):";
    std::cin >> mode;

    while (mode != 1 && mode != 2) {
        std::cout << "������������.\n������ѡ����Ϸģʽ(���� 1 ���� 2 ):";
        std::cin.clear();
        std::cin.sync();
        std::cin >> mode;
    }

    game_mode = mode;
}

void Game::SelectFirstHand() {
    int selected_first_hand_player = -1;

    if (game_mode == 1)
        std::cout << "\n����ѡ����: ���˶�ս\n ����б�: ���_1 , ���_2\n ��ѡ��������� (�������ʹ�ú�ɫ����).\n ����ѡ����(���� 1 ���� 2 ):";
    else
        std::cout << "\n����ѡ����: �˻���ս\n ����б�: ���_1 , ����\n ��ѡ��������� (�������ʹ�ú�ɫ����).\n ����ѡ����(���� 1 ���� 2 ):";

    std::cin >> selected_first_hand_player;
    while (selected_first_hand_player != 1 && selected_first_hand_player != 2) {
        std::cout << "������������.\n������ѡ���������(���� 1 ���� 2 ):";
        std::cin.clear(); //��������
        std::cin.sync();  //�����
        std::cin >> selected_first_hand_player;
    }

    fist_hand_player = selected_first_hand_player;
    if (fist_hand_player == 1 && game_mode == 1) {
        //1����������֣�����Ϸģʽ�����˶�ս
        //�������ʹ�ú�ɫ
        player_1.color = 1;
        player_2.color = 0;
    } else if (fist_hand_player == 1 && game_mode == 2) {
        //1�����(���ࣩ�����֣�����Ϸģʽ���˻���ս
        player_1.color = 1;
        machine_2.SetColor(0);
    } else if (fist_hand_player == 2 && game_mode == 1) {
        //2�����Ϊ���֣�����Ϸģʽ�����˶�ս
        player_2.color = 1;
        player_1.color = 0;
    } else if (fist_hand_player == 2 && game_mode == 2) {
        //�������ʹ�ú�ɫ������Ϸģʽ���˻���ս
        machine_2.SetColor(1);
        player_1.color = 0;
    }
}

void Game::RunGame() {
    if (game_mode == 1) {
        //std::cout << "���˶�ս";
        ManManCombat();
    } else {
        //std::cout << "�˻���ս";
        ManMachineCombat();
    }

}

void Game::ManManCombat() {
    //system("cls");
    while (true) {
        //����
        if (fist_hand_player == 1) {

            player_1.PlayChess(checkerboard, game_round);
            //std::cout<<"���һ����,round"<<game_round<<std::endl;
            //������
            if (judge.IsDisallowed(checkerboard)) {
                //����ʤ
                std::cout << "������֣�" << std::endl;
                ShowWinner(0);
                break;

            }
            //����Ƿ��������
            if (judge.JudgeFiveLink(checkerboard)) {
                std::cout << "����������" << std::endl;
                ShowWinner(1);
                break;
            }
            if (judge.JusgeDraw(checkerboard)) {
                std::cout << "ƽ�֣�" << std::endl;
                break;
            }


            player_2.PlayChess(checkerboard, game_round);
            //std::cout<<"��Ҷ�����,round"<<game_round<<std::endl;
            //�������Ƿ��������
            if (judge.JudgeFiveLink(checkerboard)) {
                std::cout << "��������!" << std::endl;
                ShowWinner(0);
                break;
            }
            if (judge.JusgeDraw(checkerboard)) {
                std::cout << "ƽ�֣�" << std::endl;
                break;
            }

        } else {

            player_2.PlayChess(checkerboard, game_round);
            //������
            //������
            if (judge.IsDisallowed(checkerboard)) {
                //����ʤ
                std::cout << "������֣�" << std::endl;
                ShowWinner(0);
                break;

            }
            //����Ƿ��������
            if (judge.JudgeFiveLink(checkerboard)) {
                std::cout << "����������" << std::endl;
                ShowWinner(1);
                break;
            }
            if (judge.JusgeDraw(checkerboard)) {
                std::cout << "ƽ�֣�" << std::endl;
                break;
            }


            player_1.PlayChess(checkerboard, game_round);
            //�������Ƿ��������
            if (judge.JudgeFiveLink(checkerboard)) {
                std::cout << "��������!" << std::endl;
                ShowWinner(0);
                break;
            }
            if (judge.JusgeDraw(checkerboard)) {
                std::cout << "ƽ�֣�" << std::endl;
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
            //������

            player_1.PlayChess(checkerboard, game_round);
            //std::cout<<"���һ����,round"<<game_round<<std::endl;
            //������
            if (judge.IsDisallowed(checkerboard)) {
                //����ʤ
                std::cout << "������֣�" << std::endl;
                ShowWinner(0);
                break;
            }
            //����Ƿ��������
            if (judge.JudgeFiveLink(checkerboard)) {
                std::cout << "����������" << std::endl;
                ShowWinner(1);
                break;
            }
            if (judge.JusgeDraw(checkerboard)) {
                std::cout << "ƽ�֣�" << std::endl;
                break;
            }


            std::cout << "Round " << game_round << "��";
            machine_2.PlayChess(checkerboard, game_round);
            //std::cout<<"��Ҷ�����,round"<<game_round<<std::endl;
            //�������Ƿ��������
            if (judge.JudgeFiveLink(checkerboard)) {
                std::cout << "��������!" << std::endl;
                ShowWinner(0);
                break;
            }
            if (judge.JusgeDraw(checkerboard)) {
                std::cout << "ƽ�֣�" << std::endl;
                break;
            }

        } else {
            //��������
            std::cout << "Round " << game_round << "��";
            machine_2.PlayChess(checkerboard, game_round);
            //������
            //������
            if (judge.IsDisallowed(checkerboard)) {
                //����ʤ
                std::cout << "������֣�" << std::endl;
                ShowWinner(0);
                break;

            }
            //����Ƿ��������
            if (judge.JudgeFiveLink(checkerboard)) {
                std::cout << "��������" << std::endl;
                ShowWinner(1);
                break;
            }
            if (judge.JusgeDraw(checkerboard)) {
                std::cout << "ƽ�֣�" << std::endl;
                break;
            }


            player_1.PlayChess(checkerboard, game_round);
            //�������Ƿ��������
            if (judge.JudgeFiveLink(checkerboard)) {
                std::cout << "����������" << std::endl;
                ShowWinner(0);
                break;
            }

            if (judge.JusgeDraw(checkerboard)) {
                std::cout << "ƽ�֣�" << std::endl;
                break;
            }
        }
        game_round = game_round + 1;

    }
    PlayAgain();
}

void Game::PlayAgain() {
    //ѯ���û��Ƿ�����һ��
    int is_play_again;
    std::cout << "\n�Ƿ���սһ�֣���1����  ��2����.\n ����ѡ����(���� 1 ���� 2 ):";

    std::cin >> is_play_again;
    while (is_play_again != 1 && is_play_again != 2) {
        std::cout << "������������.\n�Ƿ���սһ�֣���1����  ��2����.\n ����ѡ����(���� 1 ���� 2 ):";
        std::cin.clear();
        std::cin.sync();
        std::cin >> is_play_again;
    }
    if (is_play_again == 1) {
        //���ûغ���
        game_round = 1;
        //���ֽ�����ɫ
        if (game_mode == 1) {
            //��������������ҵ���ɫ
            int temp = player_1.color;
            player_1.color = player_2.color;
            player_2.color = temp;

        } else {
            //�����˺͵��Ե���ɫ
            int temp = player_1.color;
            player_1.color = machine_2.color;
            machine_2.color = temp;

        }

        //�����������
        if (player_1.color == 1)
            fist_hand_player = 1;
        else
            fist_hand_player = 2;

        //��������
        Checkerboard board;
        checkerboard = board;
        checkerboard.ShowCheckerboard();

        system("cls");
        //��ʾ��Ϸ˫���ѽ���������ɫ
        std::cout << "��ע�⡿����ѽ���������ɫ��" << std::endl;
        ShowPlayer();

        //�ٴο�ʼ��ս
        if (game_mode == 1) {
            //std::cout << "���˶�ս";
            ManManCombat();
        } else {
            //std::cout << "�˻���ս";
            ManMachineCombat();
        }
    } else {
        std::cout << "��Ϸ������" << std::endl;
    }
}


void Game::ShowWinner(int winner_color) {
    std::string winner_color_string;
    if (winner_color == 0)
        winner_color_string = "��ɫ";
    else
        winner_color_string = "��ɫ";
    if (game_mode == 1) {
        //���˶�ս
        if (player_1.color == winner_color) {
            std::cout << "���1��" << winner_color_string << ")��ʤ��" << std::endl;
        } else {
            std::cout << "���2��" << winner_color_string << ")��ʤ��" << std::endl;
        }
    } else {
        //�˻���ս
        if (player_1.color == winner_color) {
            std::cout << "���1��" << winner_color_string << ")��ʤ��" << std::endl;
        } else {
            std::cout << "���ԣ�" << winner_color_string << ")��ʤ��" << std::endl;
        }
    }

}

void Game::ShowPlayer() {
    //��ӡ���������ɫ
    if (game_mode == 1) {
        //���˶�սģʽ
        if (player_1.color == 1) {
            std::cout << "���1Ϊ�ڷ���ʹ�ã� ��ɫ���� (��) " << std::endl;
            std::cout << "���2Ϊ�׷���ʹ�ã� ��ɫ���� (��) " << std::endl;
        } else {
            std::cout << "���1Ϊ�׷���ʹ�ã� ��ɫ���� (��) " << std::endl;
            std::cout << "���2Ϊ�ڷ���ʹ�ã� ��ɫ���� (��) " << std::endl;
        }

    } else {
        //�˻���սģʽ
        if (player_1.color == 1) {
            std::cout << "���1Ϊ�ڷ���ʹ�ã� ��ɫ���� (��) " << std::endl;
            std::cout << "����Ϊ�׷���ʹ�ã� ��ɫ���� (��) " << std::endl;
        } else {
            std::cout << "���1Ϊ�׷���ʹ�ã� ��ɫ���� (��) " << std::endl;
            std::cout << "����Ϊ�ڷ���ʹ�ã� ��ɫ���� (��) " << std::endl;
        }
    }

    std::cout << "�ڷ�Ϊ���֣�" << std::endl;


}


