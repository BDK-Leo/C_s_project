#define _CRT_SECURE_NO_WARNINGS 1
//扫雷一版(初级)

#include"game.h"

void menu()
{
	printf("------------------------\n");
	printf("-------  1.PALY  -------\n");
	printf("-------  0.EXIT  -------\n");
	printf("------------------------\n");
}

void game()
{
	char mine[ROWS][COLS] = {0};//存放布置好的雷的信息
	char show[ROWS][COLS] = {0};//存放排查出的雷的信息

	//棋盘初始化
    //mine数组初始化为全'0' - 表示还没有布置雷
    //show数组初始化为全'*' - 表示所有位置都没有被排查
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show,ROWS,COLS,'*');

	//布置雷
	SetMine(mine,ROW,COL);

	//打印棋盘
	//DisPlayBoard(mine,ROW,COL);
	DisPlayBoard(show,ROW,COL);

	//排查雷
	FindMine(mine,show,ROW,COL);
}

int main()
{
	//设置时间戳
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("已退出游戏！\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input);
	return 0;
}