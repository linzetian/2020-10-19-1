#pragma once
#define ROW 3//��ͷ�ļ����壬���������ļ��а���ͷ�ļ�
#define COL 3
#include<stdio.h>//��Ϊgame.h�а���stdio.h������ֻ��Ҫ�������ļ��а���game.h����
//��������Ҫ����ͷ�ļ���

#include<stdlib.h>//����srand
#include<time.h>//����ʱ���time



void InitBoard(char board[ROW][COL], int row, int col);//��ʼ�����̺�������
void Display(char board[ROW][COL], int row, int col);//��ʾ���̵Ĳ���
void PlayerMove(char board[ROW][COL], int row, int col);//�������
void ComputerMove(char board[ROW][COL], int row, int col);//��������

//����������Ϸ����״̬
//���Ӯ '*'
//����Ӯ'#'
//ƽ��'Q'
//����'C'

char IsWin(char board[ROW][COL], int row, int col);//�ж���Ӯ