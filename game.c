#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
//��ʼ������
void Init_board(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//����չʾ
void Display_board(char board[ROW][COL], int row, int col)
{
	int i,j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if(j < col-1)
				printf(" %c |", board[i][j]);
			else if(j == col - 1)
				printf(" %c ", board[i][j]);
		}
		printf("\n");

		for (j = 0; j < col; j++)
		{
			if (i < row - 1 && j < col-1)
				printf("---|");
			else if (i < row - 1 && j == col - 1)
				printf("---");
			else
				break;
		}
		if (i < row - 1)
			printf("\n");
	}
}   
//void Display_board(char board[ROW][COL], int row, int col)
//{
//	int i;
//	for (i = 0; i < row; i++)
//	{
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		if(i < row - 1)
//			printf("---|---|---\n");
//	}
//}//                          !!!!!!version 1!!!!!!
void player_step(char board[ROW][COL], int row, int col)
{
	printf("�������:\n");
	int a, b;
	while (1)
	{
		printf("����������=>");
		scanf("%d %d", &a, &b);
		if (board[a-1][b-1] == ' ')
		{
			board[a-1][b-1] = '*';
			break;
		}
		else if (board[a - 1][b - 1] != ' ' && If_full(board, row, col) == 1)
		{
			break;
		}
		else
		{
			printf("�����²��ˣ��뻻һ��λ�ð�\n");
		}
	}
}
void machine_step(char board[ROW][COL], int row, int col)
{
	printf("��������:\n");
	int a, b;
	while (1)
	{
		a = rand() % 3;
		b = rand() % 3;
		if (board[a][b] == ' ')
		{
			board[a][b] = '#';
			break;
		}
		if (If_full(board, row, col))
		{
			break;
		}
	}
}
//�ж���û��Ӯ
char If_win(char board[ROW][COL], int row, int col)
{
	//����Ӯ:#  ���Ӯ:*  ƽ��:E  ����:C
	int i, j;
	//Ӯ-��
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			return board[i][0];
		}
	}
	//Ӯ-��
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
		{
			return board[0][i];
		}
	}
	//Ӯ-�Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		return board[1][1];
	}
	//����������ƽ��
	if (If_full(board, row, col))
	{
		return 'E';
	}
	//��Ϸ����
	return 'C';
}
//-----------------------------------------------------------------------
//�ж������Ƿ�����
int If_full(char board[ROW][COL], int row, int col)
{
	int i = 0,j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}