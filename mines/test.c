#include "minesweeper.h"

int main() {
	int input = 1;
	int choice;
	while (input) {
		menu();
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("Game Started !\n");
			printf("Choose Difficulty :\n");
			game();
			break;
		case 2:
			printf("Bye Bye !\n");
			input = 0;
			break;
		default:
			printf("Please Enter 1 or 2 !\n");
			break;
		}
	}

}
void game() {
	system("cls");
	srand((unsigned int)time(NULL));
	char board_debug[rows][cols], board_player[rows][cols];
	initial_board(board_debug, rows, cols, '0');
	initial_board(board_player, rows, cols, 'o');
	int choice;
	menu_dificulty_set();
	scanf("%d", &choice);
	switch (choice) {
	case 1:
		printf("------Easy-----\n");
		set_mine(board_debug, EASY);
		break;
	case 2:
		printf("------Normal-----\n");
		set_mine(board_debug, Normal);
		break;
	case 3:
		printf("------Dificulty-----\n");
		set_mine(board_debug, Dificult);
		break;
	case 4:
		printf("------Dificulty-----\n");
		set_mine(board_debug, Very_Difficult);
		break;
	case 5:
		printf("------Purgatory-----\n");
		set_mine(board_debug, Purgatory);
		break;
	default:
		printf("Please Enter A Number Between 1 - 5 To Choose Difficulty\n");
		break;
	}
	//print(board_debug, row, col);
	//print(board_player, row, col);
	playermove(board_player, board_debug);
}
