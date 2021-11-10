#pragma once
//我设置的长度为0-8
#include <stdio.h>
#include <time.h>
#include <Windows.h>


#define EASY 10
#define Normal 25
#define Dificult 35
#define Very_Difficult 50
#define Purgatory 80
#define row 9
#define col 9
#define rows row+2
#define cols col+2
//界面
void menu();
void menu_dificulty_set();
//开始游戏
void game();
//初始化棋盘
void initial_board(char board[rows][cols], int r, int c, char word);
//打印棋盘
void print(char board[rows][cols], int r, int c);
//设置雷数
void set_mine(char board[rows][cols], int mines_count);
//判断是否遇雷：前提是输在row and col 之中
//1.遇雷gg 2.不遇雷显示该方块周围有几个雷（此处一个统计函数） 3.如果周围无雷应该像周围八个方块延伸（此处一个递归函数）
int get_mine(char board[rows][cols], int y, int x);
void playermove(char board_player[rows][cols], char board_debug[rows][cols]);
void if_coordinate_is_0(char board_debug[rows][cols], char board_player[rows][cols], int y, int x);
