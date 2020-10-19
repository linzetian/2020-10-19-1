#define _CRT_SECURE_NO_WARNINGS 1 
#include"game.h"

void InitBoard(char board[ROW][COL], int row, int col)//定义数组要带下标，要用ROW和COL要引用头文件
{
	//初始棋盘（添加空格字符）
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] =' ';//空格字符，进行棋盘的初始化
		}
	}
}
void Display(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//for (i = 0; i < row; i++)
	//{
	//	//打印第一行数据
	//	printf(" %c | %c | %c \n",board[i][0], board[i][1], board[i][2]);//如果这样写，列就被写死了，以后想改10x10的棋盘就会出现问题
	//	//打印分割行
	//	if (i < row - 1)
	//	{
	//		printf("---|---|---\n");
	//	}
	//}
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			//打印一行数据
			printf(" %c ", board[i][j]);
		    if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//打印分割行
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

//玩家下子
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走:>\n");
	while (1)
	{
		printf("请输入要下的坐标:>");
		scanf("%d%d",&x, &y);
		//判断坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				//printf("%c", board[x - 1][y - 1]);
				break;
			}
			else
			{
				printf("坐标已被占有\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入！\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑下棋:>\n");
	while (1)
	{
		x = rand() % row+1;//x范围为1-row
		y = rand() % col+1;//y范围为1-col
		if (board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = '#';
			break;
		}
	}

}
//1表示棋盘满了
//0表示棋盘没满
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//这里用break会出现什么问题
			}
		}
	}
	return 1;
}
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//横三行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//竖三行
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
			return board[1][i];
	}
	//左右斜(两个对角)
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	//判断是否平局
	if (1 == IsFull(board, row, col))//放在IsWin前面不需要声明
	{
		return 'Q';
	}
	return 'C';
}