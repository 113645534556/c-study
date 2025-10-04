#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
//初始化布局
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
//布局展示
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
	printf("玩家下棋:\n");
	int a, b;
	while (1)
	{
		printf("请输入坐标=>");
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
			printf("这里下不了！请换一个位置吧\n");
		}
	}
}
void machine_step(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋:\n");
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
//判断有没有赢
char If_win(char board[ROW][COL], int row, int col)
{
	//电脑赢:#  玩家赢:*  平局:E  继续:C
	int i, j;
	//赢-行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			return board[i][0];
		}
	}
	//赢-列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
		{
			return board[0][i];
		}
	}
	//赢-对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		return board[1][1];
	}
	//棋盘已满，平局
	if (If_full(board, row, col))
	{
		return 'E';
	}
	//游戏继续
	return 'C';
}
//-----------------------------------------------------------------------
//判断棋盘是否已满
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