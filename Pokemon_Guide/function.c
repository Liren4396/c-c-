#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"



void Pokemon_Guide_menu() {
	printf("***********************************\n");
	printf("*****    1.Add     2.Delete    ****\n");
	printf("*****    3.Modify  4.Show      ****\n");
	printf("*****    5.Sort    6.Delete_All****\n");
	printf("*****    0.Save and Exit       ****\n");
	printf("***********************************\n");
}
//初始化
void initial_pokemon_guide(Pokemon_Guide* PC) {
	assert(PC);
	PC->sz = 0;
	Pokemon *tmp = (struct Pokemon *)malloc(Max * sizeof(Pokemon));
	if (tmp != NULL) {
		PC->player = tmp;
	}
	else {
		printf("initial error %s", errno);
		return ;
	}
	PC->capacity = Max;
	//读数据
	read_data(PC);
}

void read_data(Pokemon_Guide* PC) {
	FILE* pf;
	if (pf = fopen("C:\\Users\\Administrator\\Desktop\\Pokemon.txt", "rb")) {
		if (pf == NULL) {
			printf("read data error : %s\n", errno);
			return;
			}
		else {
			Pokemon tmp = { 0 };
		while (fread(&tmp, sizeof(Pokemon), 1, pf)) {
				expansion_capacity(PC);
				PC->player[PC->sz] = tmp;
				PC->sz++;
			}
		fclose(pf);
		pf = NULL;
		}
	}



}

/*	char name[20];
char property[10];
int Level;
char hobby[20];
char living_environment[20];
printf("%s\t\t\t\t%s\t\t%s\t%s\t\t%s", "Name", "Property", "Level", "Hobby", "Living_Environment");*/
//添加宝可梦
void Add_pokemon(Pokemon_Guide* PC) {
	assert(PC);
	expansion_capacity(PC);
	printf("Please Enter Following data:\n");
	printf("Name->");
	scanf("%s", PC->player[PC->sz].name);
	printf("Property->");
	scanf("%s", PC->player[PC->sz].property);
	printf("Level->");
	scanf("%d", &PC->player[PC->sz].Level);
	printf("Hobby->");
	scanf("%s", PC->player[PC->sz].hobby);
	printf("Living_environment->");
	scanf("%s", PC->player[PC->sz].living_environment);

	PC->sz++;
	printf("Add Successfully\n");
}

void expansion_capacity(Pokemon_Guide *PC) {
	if (PC->sz == PC->capacity) {
		Pokemon* tmp = (struct Pokemon*)realloc(PC->sz, (PC->capacity + 2) * sizeof(Pokemon));
		if (tmp != NULL) {
			PC->player = tmp;
			PC->capacity += 2;
		}
		else {
			printf("add error : %s", errno);
			return;
		}
	}
}
void Show_Pokemon(Pokemon_Guide* PC) {
	assert(PC->sz > 0);
	int i = 0;
	printf("****************     You have %d Pokemon!           *********************************\n", PC->sz);
	printf("%-12s\t\t\t%-8s\t\t%-4s\t%-8s\t\t%-10s\n", "Name", "Property", "Level", "Hobby", "Living_Environment");
	for (i = 0; i < PC->sz; i++) {
		printf("%-12s\t\t\t%-8s\t\t%-4d\t%-8s\t\t%-10s\n", PC->player[i].name, PC->player[i].property, PC->player[i].Level,
			PC->player[i].hobby, PC->player[i].living_environment);
	}
	printf("\n");

}

int Search_Pokemon(char name[12], Pokemon_Guide *PC) {
	int i = 0;
	for (i = 0; i < PC->sz; i++) {
		if (strcmp(name, PC->player[i].name) == 0) {
			return i;
		}
	}
	return -1;
}

void Delete_Pokemon(Pokemon_Guide* PC) {
	char name[12];
	if (PC->sz == 0) {
		printf("No Pokemon in your Pokemon Guide\n");
		printf("You can't delete\n");
	}
	printf("Enter Pokemon name to delete->");
	scanf("%s", name);
	int pos = Search_Pokemon(name, PC);
	if (pos == -1) {
		printf("Can not find the entered pokemon\n");
	}
	else {
		//从pos位置开始删
		for (int i = pos; i < PC->sz; i++) {
			PC->player[i] = PC->player[i + 1];
		}
		PC->sz--;
		printf("Delete Successfully\n");
	}
}

void Delete_all(Pokemon_Guide* PC) {
	PC->sz = 0;
}

void Modify_Pokemon(Pokemon_Guide* PC) {
	char name[12];
	printf("Which Pokemon do you want to modify->");
	scanf("%s", name);
	int pos = Search_Pokemon(name, PC);
	if (pos == -1) {
		printf("Can not find the entered pokemon\n");
	}
	else {
		int num;
		//找到当前宝可梦位置
		printf("1(Name) 2(Property) 3(Level) 4(Hobby) 5(Living Environment)\n");
		printf("Which item do you want to change->");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			printf("Name->");
			scanf("%s", PC->player[pos].name);
			break;
		case 2:
			printf("Property->");
			scanf("%s", PC->player[pos].property);
			break;
		case 3:
			printf("Level->");
			scanf("%d", &PC->player[pos].Level);
			break;
		case 4:
			printf("Hobby->");
			scanf("%s", PC->player[pos].hobby);
			break;
		case 5:
			printf("Living Environment->");
			scanf("%s", PC->player[pos].living_environment);
			break;
		default:
			printf("Can not modify!\n");
			break;
		}
	}
}



void Sort_Pokemon(Pokemon_Guide* PC) {
	int num;
	printf(" 1(Name Order)  2(Level Order)\n");
	printf("Please Enter number->");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		Sort_in_name(PC);
		break;
	case 2:
		Sort_in_level(PC);
		break;
	default:
		printf("number entered is wrong!\n");
		break;
	}
	Show_Pokemon(PC);
}

void Sort_in_name(Pokemon_Guide* PC) {
	for (int i = 0; i < PC->sz; i++) {
		for (int j = i + 1; j < PC->sz; j++) {
			for (int pos = 0; pos < 12; pos++) {
				if (PC->player[i].name[pos] < PC->player[j].name[pos]) {
					break;
				}
				else if (PC->player[i].name[pos] > PC->player[j].name[pos]) {
					char name[20];
					strcpy(name, PC->player[i].name);
					strcpy(PC->player[i].name, PC->player[j].name);
					strcpy(PC->player[j].name, name);
					break;
				}
			}
		}
	}
}


void Sort_in_level(Pokemon_Guide* PC) {
	for (int i = 0; i < PC->sz; i++) {
		for (int j = i + 1; j < PC->sz; j++) {
			if (PC->player[i].Level > PC->player[j].Level) {
				break;
			}
			else if (PC->player[i].Level < PC->player[j].Level) {
				int min = PC->player[i].Level;
				PC->player[i].Level = PC->player[j].Level;
				PC->player[j].Level = min;
				break;
			}
		}
	}
}

void free_all(Pokemon_Guide* PC) {
	
	free(PC->player);
	PC->player = NULL;
	PC->sz = 0;
	PC->capacity = Max;

}

void save_data(Pokemon_Guide* PC) {
	FILE* pf = fopen("C:\\Users\\Administrator\\Desktop\\Pokemon.txt", "wb");
	if (pf == NULL) {
		printf("save data error: %s", errno);
		return;
	}
	for (int i = 0; i < PC->sz; i++) {
		fwrite(PC->player + i, sizeof(Pokemon), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}
