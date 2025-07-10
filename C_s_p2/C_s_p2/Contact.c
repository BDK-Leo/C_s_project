#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"
#include"SeqList.h"
#include<string.h>

//加载通讯录
void LoadContact(Contact* con)
{
	//打开文件
	FILE* pf = fopen("contact.txt", "rb");
	if (pf == NULL)
	{
		perror("fopen error!\n");
		return;
	}

	//循环读取文件数据
	peoInfo info;
	while (fread(&info, sizeof(peoInfo), 1, pf))
	{
		SLPushBack(con, info);
	}
	printf("历史数据导入通讯录成功！\n");
}

//通讯录的初始化
void ContactInit(Contact* con)
{
	SLInit(con);
}

//通讯录添加数据
void ContactAdd(Contact* con)
{
	//获取用户输入的内容
	peoInfo info;
	printf("请输入要添加的联系人姓名：\n");
	scanf("%s", info.name);

	printf("请输入要添加的联系人性别：\n");
	scanf("%s", info.gender);

	printf("请输入要添加的联系人年龄：\n");
	scanf("%d", &info.age);

	printf("请输入要添加的联系人电话：\n");
	scanf("%s", info.tel);

	printf("请输入要添加的联系人地址：\n");
	scanf("%s", info.addr);

	//添加联系人数据
	SLPushBack(con, info);
}

//根据姓名查找
int FindByName(Contact* con, char name[])
{
	for (int i = 0; i < con->size; i++)
	{
		if (0 == strcmp(con->arr[i].name, name))
		{
			return i;
		}
	}
	return -1;
}

//通讯录删除数据
void ContactDel(Contact* con)
{
	//保证要删除的数据存在，才能执行删除操作
	//查找
	char name[NAME_MAX];
	printf("请输入要删除的联系人姓名：\n");
	scanf("%s", name);
	int Find = FindByName(con, name);
	if (Find < 0)
	{
		printf("联系人不存在！\n");
		return;
	}
	SLErase(con, Find);
	printf("删除成功！\n");
}

//通讯录的修改
void ContactModify(Contact* con)
{
	//要修改的联系人存在
	char name[NAME_MAX];
	printf("请输入要修改的联系人姓名：");
	scanf("%s", name);
	int Find = FindByName(con, name);
	if (Find < 0)
	{
		printf("联系人不存在！\n");
		return;
	}
	printf("请输入新的姓名：");
	scanf("%s", con->arr[Find].name);

	printf("请输入新的性别：");
	scanf("%s", con->arr[Find].gender);

	printf("请输入新的年龄：");
	scanf("%d", &con->arr[Find].age);

	printf("请输入新的电话：");
	scanf("%s", con->arr[Find].tel);

	printf("请输入新的地址：");
	scanf("%s", con->arr[Find].addr);

	printf("修改成功！\n");
}

//通讯录的查找
void ContactFind(Contact* con)
{
	char name[NAME_MAX];
	printf("请输入要查找的联系人姓名：\n");
	scanf("%s", name);

	int Find = FindByName(con, name);
	if (Find < 0)
	{
		printf("联系人不存在！\n");
		return;
	}
	printf("姓名:%s\n", con->arr[Find].name);
	printf("性别:%s\n", con->arr[Find].gender);
	printf("年龄:%d\n", con->arr[Find].age);
	printf("电话:%s\n", con->arr[Find].tel);
	printf("地址:%s\n", con->arr[Find].addr);
	printf("\n");
}

//通讯录的展示
void ContactShow(Contact* con)
{
	if (con->size == 0)
	{
		printf("联系人为空！\n");
	}
	for (int i = 0; i < con->size; i++)
	{
		printf("姓名:%s\n", con->arr[i].name);
		printf("性别:%s\n", con->arr[i].gender);
		printf("年龄:%d\n", con->arr[i].age);
		printf("电话:%s\n", con->arr[i].tel);
		printf("地址:%s\n", con->arr[i].addr);
		printf("\n");
	}
}

//保存
void ContactSave(Contact* con)
{
	FILE* pf = fopen("contact.txt", "wb");
	if (pf == NULL)
	{
		perror("fopen error!\n");
		return;
	}

	//将通讯录写入文件
	for (int i = 0; i < con->size; i++)
	{
		fwrite(con->arr + i, sizeof(peoInfo), 1, pf);
	}
	printf("通讯录数据保存成功！\n");
}

//通讯录的销毁
void ContactDesTroy(Contact* con)
{
	//ContactSave(con);
	SLDestroy(con);
}