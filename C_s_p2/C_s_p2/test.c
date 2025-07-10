#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

//void SLTest01()
//{
//	//初始化
//	SL sl;
//	SLInit(&sl);
//
//	//测试尾插
//	SLPushBack(&sl, 1);
//	SLPushBack(&sl, 2);
//	SLPushBack(&sl, 3);
//	SLPushBack(&sl, 4);
//
//	//测试头插
//	SLPushFront(&sl, 5);
//	SLPushFront(&sl, 6);
//
//
//	//测试尾删
//	SLPopBack(&sl);
//
//	//测试头删
//	SLPopFront(&sl);
//	SLPrint(sl);
//
//	//销毁
//	SLDestroy(&sl);
//}
//
//void SLTest02()
//{
//	SL sl;
//	SLInit(&sl);
//
//	//指定位置之前插入
//	SLPushBack(&sl, 1);
//	SLPushBack(&sl, 2);
//	SLPushBack(&sl, 3);
//	SLPushBack(&sl, 4);
//	SLPrint(sl);
//	SLInsert(&sl, sl.size, 5);
//	SLInsert(&sl, 0, 0);
//	SLPrint(sl);
//
//	//指定位置删除
//	SLErase(&sl, 0);
//	SLErase(&sl, sl.size - 1);
//	SLPrint(sl);
//
//	//查找
//	int Find = SLFind(&sl, sl.size);
//	if (Find < 0)
//	{
//		printf("没有找到！\n");
//	}
//	else
//	{
//		printf("位置为:%d", Find);
//	}
//
//	SLDestroy(&sl);
//}

////通讯录的测试
//void ContactTest01()
//{
//	//测试通讯录的初始化
//	Contact con;//创建的通讯录对象，实际上是顺序表对象，等价于SL sl;
//	ContactInit(&con);
//
//	//测试通讯录添加数据
//	ContactAdd(&con);
//	ContactAdd(&con);
//
//	//测试通讯录删除数据
//	//ContactShow(&con);
//	//ContactDel(&con);
//
//	//通讯录的修改
//	//ContactModify(&con);
//	//ContactShow(&con);
//
//	//通讯录的查找
//    ContactFind(&con);
//
//	//通讯录的展示
//	//ContactShow(&con);
//
//	//测试通讯录的销毁
//	ContactDesTroy(&con);
//}
//
//int main()
//{
//	//SLTest01();
//	//SLTest02();
//	ContactTest01();
//	return 0;
//}

void menu()
{
	printf("*******   通讯录   *******\n");
	printf("***1.添加用户 2.删除用户***\n");
	printf("***3.修改用户 4.查找用户***\n");
	printf("***5.显示用户 6.保存用户***\n");
	printf("***7.加载用户 0.退出程序***\n");
}

int main()
{
	int op = -1;
	Contact con;
	ContactInit(&con);
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			ContactAdd(&con);
			break;
		case 2:
			ContactDel(&con);
			break;
		case 3:
			ContactModify(&con);
			break;
		case 4:
			ContactFind(&con);
			break;
		case 5:
			ContactShow(&con);
			break;
		case 6:
			ContactSave(&con);
			break;
		case 7:
			LoadContact(&con);
			break;
		case 0:
			printf("已退出！\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	} while (op);
	ContactDesTroy(&con);
	return 0;
}