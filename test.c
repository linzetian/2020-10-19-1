#define _CRT_SECURE_NO_WARNINGS 1 

//��������Ϸ

#include"game.h"
void menu()
{
	printf("**********************\n");
	printf("*** 1.play  0.exit ***\n");
	printf("**********************\n");
}
//��Ϸ�����㷨��ʵ��
void game()
{
	int ret = 0;
	//�������߳���������Ϣ
	char board[ROW][COL] = {0};//ROW��COLͨ���궨�壬���Կ��ٸ������̵����У������̵Ĵ�С��	(һ��ȫ��)
	//board��ʼ��Ϊ�ո�(board[ROW][COL] = {0}��һ����0û�д�ӡ����)
	InitBoard(board, ROW, COL);//�˲��軹�Ǳ�Ҫ��
	Display(board, ROW, COL);//��ӡ����
	while (1)
	{
		
		PlayerMove(board, ROW, COL);//�������
		Display(board, ROW, COL);//���������ӡ
		//�ж�����Ƿ�Ӯ
		ret=IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}

		ComputerMove(board, ROW, COL);//��������
		Display(board, ROW, COL);//����������ӡ
		//�жϵ����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret== '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
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