#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9//��
#define COL 9//��

#define ROWS ROW+2
#define COLS COL+2

#define EAZY_COUNT 10//�׵�����

//��ʼ������
void InitBoard(char Board[ROWS][COLS],int r,int c,char set);

//��mine�в�����
void SetMine(char mine[ROWS][COLS],int r,int c);

//��ӡ����
void DisPlayBoard(char Board[ROWS][COLS], int r, int c);

//�Ų���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS],int r,int c);
