#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9//行
#define COL 9//列

#define ROWS ROW+2
#define COLS COL+2

#define EAZY_COUNT 10//雷的数量

//初始化棋盘
void InitBoard(char Board[ROWS][COLS],int r,int c,char set);

//在mine中布置雷
void SetMine(char mine[ROWS][COLS],int r,int c);

//打印棋盘
void DisPlayBoard(char Board[ROWS][COLS], int r, int c);

//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS],int r,int c);
