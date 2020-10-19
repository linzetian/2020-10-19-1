#pragma once
#define ROW 3//在头文件定义，必须在主文件中包含头文件
#define COL 3
#include<stdio.h>//因为game.h中包含stdio.h，所以只需要在其它文件中包含game.h就行
//函数声明要放在头文件中

#include<stdlib.h>//用了srand
#include<time.h>//用了时间戳time



void InitBoard(char board[ROW][COL], int row, int col);//初始化棋盘函数声明
void Display(char board[ROW][COL], int row, int col);//演示棋盘的布局
void PlayerMove(char board[ROW][COL], int row, int col);//玩家下棋
void ComputerMove(char board[ROW][COL], int row, int col);//电脑下棋

//告诉我们游戏四种状态
//玩家赢 '*'
//电脑赢'#'
//平局'Q'
//继续'C'

char IsWin(char board[ROW][COL], int row, int col);//判断输赢