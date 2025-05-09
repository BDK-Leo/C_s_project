#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//棋盘初始化
void InitBoard(char Board[ROWS][COLS], int r, int c, char set)
{
	int i = 0;
	for (i = 0;i < r;i++)
	{
		int j = 0;
		for (j = 0;j < c;j++)
		{
			Board[i][j] = set;
		}
	}
}

//打印棋盘
void DisPlayBoard(char Board[ROWS][COLS], int r, int c)
{
	int i = 0;
	int j = 0;
	printf("-------扫 雷-------\n");
	for (j = 0;j <= c;j++)
	{
		printf("%d ",j);//打印列号
	}
	printf("\n");
	for (i = 1;i <= r;i++)
	{
		printf("%d ",i);//打印行号
		for (j = 1;j <= c;j++)
		{
			printf("%c ", Board[i][j]);
		}
		printf("\n");
	}
}

//在mine中布置雷
void SetMine(char mine[ROWS][COLS], int r, int c)
{
	int count = EAZY_COUNT;
	while (count)
	{
		//生成随机坐标，x,y范围都是1~9
		int x = rand() % r + 1;
		int y = rand() % c + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

//计算雷的数量
int GetMineCount(char mine[ROWS][COLS],int x,int y)
{
	int i = 0;
	int j = 0;
	int num = 0;
	for (i = -1;i <= 1;i++)
	{
		for (j = -1;j <= 1;j++)
		{
			if (mine[x+i][y+j] == '1')
			{
				num++;
			}
		}
	}
	return num;
}

//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int r, int c)
{
	int x = 0;
	int y = 0;
	//安全且已显示的坐标
	int win = 0;
	while (win < r * c - EAZY_COUNT)
	{
		printf("请输入坐标：");
		scanf("%d %d", &x, &y);
		//判断坐标合法性
		if (x >= 1 && x <= r && y >= 1 && y <= c)
		{
			//判断是否为雷
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你触雷了！\n");
				DisPlayBoard(mine, r, c);
				break;
			}
			else
			{
				if (show[x][y] == '*')
				{
					//接收mine数组中已统计的雷的数量
					int c = GetMineCount(mine, x, y);
					show[x][y] = c + '0';//得出数字c对应的字符
					DisPlayBoard(show, ROW, COL);
					win++;
				}
				else
				{
					printf("坐标已显示，请重新输入！\n");
				}
			}
		}
		else
		{
			printf("坐标非法，请重新输入！\n");
		}
	}
	if (win == r * c - EAZY_COUNT)
	{
		printf("恭喜你！游戏通关！\n");
		DisPlayBoard(mine, r, c);
	}
}