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
		printf("�������:\n");
		Display_board(board, ROW, COL);
		if (If_win(board, ROW, COL) != 'C')
		{
			if (If_win(board, ROW, COL) == '#')
			{
				system("cls");
				Display_board(board, ROW, COL);
				printf("����Ӯ��\n");
				system("pause");
				system("cls");
				break;
			}
			else if (If_win(board, ROW, COL) == '*')
			{
				system("cls");
				Display_board(board, ROW, COL);
				printf("���Ӯ��\n");
				system("pause");
				system("cls");
				break;
			}
			else if (If_win(board, ROW, COL) == 'E')
			{
				system("cls");
				Display_board(board, ROW, COL);
				printf("ƽ�֣�\n");
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
				printf("����Ӯ��\n");
				system("pause");
				system("cls");
				break;
			}
			else if (If_win(board, ROW, COL) == '*')
			{
				system("cls");
				Display_board(board, ROW, COL);
				printf("���Ӯ��\n");
				system("pause");
				system("cls");
				break;
			}
			else if (If_win(board, ROW, COL) == 'E')
			{
				system("cls");
				Display_board(board, ROW, COL);
				printf("ƽ�֣�\n");
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
		printf("������>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			system("cls");
			game();
			break;
		case 2:
			system("cls");
			printf("��Ϸ������\n");
			break;
		default:
			system("cls");
			printf("�����������������\n");
			Sleep(1300);
			system("cls");
			break;
		}
	} while (input != 2);

	system("pause");
	return 0;
}