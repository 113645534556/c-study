#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define ROW 3
#define COL 3
void Init_board(char board[ROW][COL], int row, int col);
void Display_board(char board[ROW][COL], int row, int col);
void player_step(char board[ROW][COL], int row, int col);
void machine_step(char board[ROW][COL], int row, int col);
char If_win(char board[ROW][COL], int row, int col);
int If_full(char board[ROW][COL], int row, int col);