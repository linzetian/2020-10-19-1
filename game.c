#define _CRT_SECURE_NO_WARNINGS 1 
#include"game.h"

void InitBoard(char board[ROW][COL], int row, int col)//��������Ҫ���±꣬Ҫ��ROW��COLҪ����ͷ�ļ�
{
	//��ʼ���̣���ӿո��ַ���
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] =' ';//�ո��ַ����������̵ĳ�ʼ��
		}
	}
}
void Display(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//for (i = 0; i < row; i++)
	//{
	//	//��ӡ��һ������
	//	printf(" %c | %c | %c \n",board[i][0], board[i][1], board[i][2]);//�������д���оͱ�д���ˣ��Ժ����10x10�����̾ͻ��������
	//	//��ӡ�ָ���
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
			//��ӡһ������
			printf(" %c ", board[i][j]);
		    if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//��ӡ�ָ���
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

//�������
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����:>\n");
	while (1)
	{
		printf("������Ҫ�µ�����:>");
		scanf("%d%d",&x, &y);
		//�ж�����ĺϷ���
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
				printf("�����ѱ�ռ��\n");
			}
		}
		else
		{
			printf("����Ƿ������������룡\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("��������:>\n");
	while (1)
	{
		x = rand() % row+1;//x��ΧΪ1-row
		y = rand() % col+1;//y��ΧΪ1-col
		if (board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = '#';
			break;
		}
	}

}
//1��ʾ��������
//0��ʾ����û��
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
				return 0;//������break�����ʲô����
			}
		}
	}
	return 1;
}
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//������
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//������
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
			return board[1][i];
	}
	//����б(�����Խ�)
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	//�ж��Ƿ�ƽ��
	if (1 == IsFull(board, row, col))//����IsWinǰ�治��Ҫ����
	{
		return 'Q';
	}
	return 'C';
}