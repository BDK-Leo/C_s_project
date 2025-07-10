#pragma once

#define NAME_MAX 20
#define GENDER_MAX 2 //male female
#define TEL_MAX 20
#define ADDR_MAX 100

//定义联系人数据
//姓名 性别 年龄 电话 地址
typedef struct PersonInfo
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}peoInfo;

//通讯录相关的方法(要用到顺序表相关的方法)
//给顺序表改个名字，叫通讯录
typedef struct SeqList Contact;//前置声明  typedef SL Contact;

//通讯录的初始化
void ContactInit(Contact* con);

//通讯录添加数据
void ContactAdd(Contact* con);

//通讯录删除数据
void ContactDel(Contact* con);

//通讯录的修改
void ContactModify(Contact* con);

//通讯录的查找
void ContactFind(Contact* con);

//通讯录的展示
void ContactShow(Contact* con);

//保存
void ContactSave(Contact* con);

//加载通讯录
void LoadContact(Contact* con);

//通讯录的销毁
void ContactDesTroy(Contact* con);
