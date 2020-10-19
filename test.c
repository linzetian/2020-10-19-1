#define _CRT_SECURE_NO_WARNINGS 1 

//三子棋游戏

#include"game.h"
void menu()
{
	printf("**********************\n");
	printf("*** 1.play  0.exit ***\n");
	printf("**********************\n");
}
//游戏整个算法的实现
void game()
{
	int ret = 0;
	//数组存放走出的棋盘信息
	char board[ROW][COL] = {0};//ROW和COL通过宏定义，可以快速更改棋盘的行列（即棋盘的大小）	(一改全改)
	//board初始化为空格(board[ROW][COL] = {0}不一样，0没有打印出来)
	InitBoard(board, ROW, COL);//此步骤还是必要的
	Display(board, ROW, COL);//打印棋盘
	while (1)
	{
		
		PlayerMove(board, ROW, COL);//玩家下棋
		Display(board, ROW, COL);//玩家下棋后打印
		//判断玩家是否赢
		ret=IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}

		ComputerMove(board, ROW, COL);//电脑下棋
		Display(board, ROW, COL);//电脑下棋后打印
		//判断电脑是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret== '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	}
	while (input);
}
int main()
{
	test();
	return 0;
}