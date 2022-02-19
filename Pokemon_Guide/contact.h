#pragma once
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#define Max 3

typedef enum Option
{
	EXIT,
	ADD,
	DELETE,
	MODIFY,
	SHOW,
	SORT,
	DELETE_ALL,
} Option;

//名字  属性  年龄  体重  身高  生活环境  是否友善  喜好
typedef struct Pokemon {
	char name[12];
	char property[10];
	int Level;
	char hobby[20];
	char living_environment[20];
	
} Pokemon;

typedef struct Pokemon_Guide {
	int sz;
	int capacity;
	Pokemon *player;
} Pokemon_Guide;



//增加 删除 修改 排序 显示（只显示一个还是全都显示） 退出
void Pokemon_Guide_menu();
//初始化图鉴
void initial_pokemon_guide(Pokemon_Guide* PC);
//增加宝可梦
void Add_pokemon(Pokemon_Guide* PC);
//显示宝可梦
void Show_Pokemon(Pokemon_Guide* PC);
//删除宝可梦
void Delete_Pokemon(Pokemon_Guide* PC);
//查找宝可梦
int Search_Pokemon(char name[12], Pokemon_Guide *PC);
//修改宝可梦的某一项
void Modify_Pokemon(Pokemon_Guide* PC);
//宝可梦排序系统
void Sort_Pokemon(Pokemon_Guide* PC);
//名字排序
void Sort_in_name(Pokemon_Guide* PC);
//等级排序
void Sort_in_level(Pokemon_Guide* PC);
//删除所以联系人
void Delete_all(Pokemon_Guide* PC);
//删除结构
void free_all(Pokemon_Guide* PC);
//扩张容量
void expansion_capacity(Pokemon_Guide* PC);
//保存数据
void save_data(Pokemon_Guide* PC);
//读取数据
void read_data(Pokemon_Guide* PC);
