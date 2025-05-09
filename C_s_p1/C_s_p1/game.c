#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//���̳�ʼ��
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

//��ӡ����
void DisPlayBoard(char Board[ROWS][COLS], int r, int c)
{
	int i = 0;
	int j = 0;
	printf("-------ɨ ��-------\n");
	for (j = 0;j <= c;j++)
	{
		printf("%d ",j);//��ӡ�к�
	}
	printf("\n");
	for (i = 1;i <= r;i++)
	{
		printf("%d ",i);//��ӡ�к�
		for (j = 1;j <= c;j++)
		{
			printf("%c ", Board[i][j]);
		}
		printf("\n");
	}
}

//��mine�в�����
void SetMine(char mine[ROWS][COLS], int r, int c)
{
	int count = EAZY_COUNT;
	while (count)
	{
		//����������꣬x,y��Χ����1~9
		int x = rand() % r + 1;
		int y = rand() % c + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

//�����׵�����
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

//�Ų���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int r, int c)
{
	int x = 0;
	int y = 0;
	//��ȫ������ʾ������
	int win = 0;
	while (win < r * c - EAZY_COUNT)
	{
		printf("���������꣺");
		scanf("%d %d", &x, &y);
		//�ж�����Ϸ���
		if (x >= 1 && x <= r && y >= 1 && y <= c)
		{
			//�ж��Ƿ�Ϊ��
			if (mine[x][y] == '1')
			{
				printf("���ź����㴥���ˣ�\n");
				DisPlayBoard(mine, r, c);
				break;
			}
			else
			{
				if (show[x][y] == '*')
				{
					//����mine��������ͳ�Ƶ��׵�����
					int c = GetMineCount(mine, x, y);
					show[x][y] = c + '0';//�ó�����c��Ӧ���ַ�
					DisPlayBoard(show, ROW, COL);
					win++;
				}
				else
				{
					printf("��������ʾ�����������룡\n");
				}
			}
		}
		else
		{
			printf("����Ƿ������������룡\n");
		}
	}
	if (win == r * c - EAZY_COUNT)
	{
		printf("��ϲ�㣡��Ϸͨ�أ�\n");
		DisPlayBoard(mine, r, c);
	}
}