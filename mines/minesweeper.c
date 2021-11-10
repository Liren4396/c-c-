#include "minesweeper.h"
void initial_board(char board[rows][cols], int r, int c, char word) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			board[i][j] = word;
		}
	}
}

void print(char board[rows][cols], int r, int c) {
	for (int j = 0; j <= c; j++) {
		printf(" %d ", j);
	}
	printf("\n");
	for (int i = 1; i <= r; i++) {
		printf(" %d ", i);
		for (int j = 1; j <= c; j++) {
			printf(" %c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void set_mine(char board[rows][cols], int mines_count) {
	while (mines_count > 0) {
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
		if (board[y][x] != '1') {
			board[y][x] = '1';
			mines_count--;
		}
	}
}



void menu() {
	printf("******************************\n");
	printf("**  Welcome to minesweeper  **\n");
	printf("******************************\n");
	printf("*******   1. Play     ********\n");
	printf("*******   2. Exit     ********\n");
	printf("******************************\n");
	printf("Please Enter Your Choice[1,2]:[ ]\b\b");

}
void menu_dificulty_set() {
	printf("**********************************\n");
	printf("**  Choose      Difficulty  ******\n");
	printf("**********************************\n");
	printf("     Difficulty   Number of Mines \n");
	printf("**   1. Easy           10     ****\n");
	printf("**   2. Normal         25     ****\n");
	printf("**   3. Difficult      35     ****\n");
	printf("**   4. VeryDifficult  50     ****\n");
	printf("**   5. Purgatory      80     ****\n");
	printf("Please Enter Your Choice[1,2,3,4,5]:[ ]\b\b");
}
//判断是否遇雷：前提是输在row and col 之中
//1.遇雷gg 2.不遇雷显示该方块周围有几个雷（此处一个函数） 3.如果周围无雷应该像周围八个方块延伸（此处一个递归函数）
void playermove(char board_player[rows][cols], char board_debug[rows][cols]) {
	system("cls");
	print(board_player, row, col);
	int x, y;
	int count = 0;
	printf("Please Enter Y and X Between 0-9 To Get Coordinate:\n");
	while (row * col - EASY > count) {
		printf("Enter Coordinate(y,x) : [   ]\b\b\b\b");
		scanf("%d %d", &y, &x);
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9) {
			if (board_debug[y][x] == '1') {
				board_player[y][x] = '*';
				//print(board_debug, row, col);
				print(board_player, row, col);
				printf("Game Over !\n");
				break;
			}
			else if (board_debug[y][x] == '0' && board_player[y][x] == 'o') {
				int number = get_mine(board_debug, y, x);
				board_player[y][x] = number + '0';
				//board_debug[y][x] = number + '0';
				if_coordinate_is_0(board_debug, board_player, y, x);
				//print(board_debug, row, col);
				print(board_player, row, col);
				count++;
			}
			else {
				printf("Coordinate Has Been Entered!\n");
			}

		}
		else {
			printf("You Should Enter Y And X Between 1-9\n");
		}
	}
	if (row * col - EASY == count) {
		print(board_player, row, col);
		printf("You Win ....\n");
	}
}

int get_mine(char board[rows][cols], int y, int x) {
	return board[y + 1][x + 1] + board[y + 1][x] + board[y][x + 1] + board[y - 1][x - 1] + board[y][x - 1]
		+ board[y - 1][x] + board[y - 1][x + 1] + board[y + 1][x - 1] - 8 * '0';
}
// 周围8格格子没有雷 2.该点应该换为‘  ’
// 在 1 - 9 之间举行
void if_coordinate_is_0(char board_debug[rows][cols], char board_player[rows][cols], int y, int x) {
	if (get_mine(board_debug, y, x) == 0) {
		board_player[y][x] = ' ';
		for (int i = y - 1; i <= y + 1; i++) {
			for (int j = x - 1; j <= x + 1; j++) {
				if (i >= 1 && i <= row && j >= 1 && j <= col && board_debug[i][j] != '1' && board_player[i][j] == 'o') {
					if_coordinate_is_0(board_debug, board_player, i, j);
				}
			}
		}
	}
	else {
		board_player[y][x] = '0' + get_mine(board_debug, y, x);
	}
}
