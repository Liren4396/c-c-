#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

int main()
{
	int num;
	Pokemon_Guide player = { 0 };
	printf("    Welcome to Pokemon_Guide\n");
	initial_pokemon_guide(&player);
	do {
		Pokemon_Guide_menu();
		printf("***********************************\n");
		printf("Please Enter 0-6 to begin: [ ].\b\b\b");
		scanf("%d", &num);
		switch (num)
		{
		case EXIT:
			printf("EXIT SUCCESSFULLY");
			break;
		case ADD:
			Add_pokemon(&player);
			break;
		case DELETE:
			Delete_Pokemon(&player);
			break;
		case MODIFY:
			Modify_Pokemon(&player);
			break;
		case SHOW:
			Show_Pokemon(&player);
			break;
		case SORT:
			Sort_Pokemon(&player);
			break;
		case DELETE_ALL:
			Delete_all(&player);
			break;
		default:
			printf("Please Enter the right number!\n");
			break;
		}
	} while (num);
	save_data(&player);
	free_all(&player);
	
}
