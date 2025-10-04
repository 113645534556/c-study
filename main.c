#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void game()
{
	char board[ROW][COL] = { 0 };
	Init_board(board, ROW, COL);
	Display_board(board, ROW, COL);
	while (1)
	{
		player_step(board, ROW, COL);
		system("cls");
		printf("玩家下棋:\n");
		Display_board(board, ROW, COL);
		if (If_win(board, ROW, COL) != 'C')
		{
			if (If_win(board, ROW, COL) == '#')
			{
				system("cls");
				Display_board(board, ROW, COL);
				printf("电脑赢！\n");
				system("pause");
				system("cls");
				break;
			}
			else if (If_win(board, ROW, COL) == '*')
			{
				system("cls");
				Display_board(board, ROW, COL);
				printf("玩家赢！\n");
				system("pause");
				system("cls");
				break;
			}
			else if (If_win(board, ROW, COL) == 'E')
			{
				system("cls");
				Display_board(board, ROW, COL);
				printf("平局！\n");
				system("pause");
				system("cls");
				break;
			}
		}
		machine_step(board, ROW, COL);
		Display_board(board, ROW, COL);
		if (If_win(board, ROW, COL) != 'C')
		{
			if (If_win(board, ROW, COL) == '#')
			{
				system("cls");
				Display_board(board, ROW, COL);
				printf("电脑赢！\n");
				system("pause");
				system("cls");
				break;
			}
			else if (If_win(board, ROW, COL) == '*')
			{
				system("cls");
				Display_board(board, ROW, COL);
				printf("玩家赢！\n");
				system("pause");
				system("cls");
				break;
			}
			else if (If_win(board, ROW, COL) == 'E')
			{
				system("cls");
				Display_board(board, ROW, COL);
				printf("平局！\n");
				system("pause");
				system("cls");
				break;
			}
		}
	}
}
void menu()
{
	printf("############################################\n");
	printf("################   1.play   ################\n");
	printf("################   2.exit   ################\n");
	printf("############################################\n"); 
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请输入>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			system("cls");
			game();
			break;
		case 2:
			system("cls");
			printf("游戏结束！\n");
			break;
		default:
			system("cls");
			printf("输入错误，请重新输入\n");
			Sleep(1300);
			system("cls");
			break;
		}
	} while (input != 2);

	system("pause");
	return 0;
}