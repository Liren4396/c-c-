#define _CRT_SECURE_NO_WARNINGS
#include "minesweeper.h"

void SeqListInit(SeqList* ps) {
	ps->a =  NULL;
	ps->capacity = 0;
	ps->size = 0;
}

void SeqListDestory(SeqList* ps) {
	assert(ps);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;

	//free(ps);
}
void SeqListPrint(SeqList* ps) {
	assert(ps);
	for (int i = 0; i < ps->size; i++) {
		printf("%d->", ps->a[i]);
	}
}

void SeqListPushBack(SeqList* ps, SLDateType x) {
	assert(ps);
	if (ps->size == ps->capacity) {
		size_t newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDateType* tmp = realloc(ps->a, sizeof(SLDateType) * newcapacity);
		if (tmp == NULL) {
			printf("realloc fail");
		}
		else {
			ps->a = tmp;
			ps->capacity *= 2;
		}
	}
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPushFront(SeqList* ps, SLDateType x) {
	assert(ps);
	if (ps->size == ps->capacity) {
		size_t newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDateType* tmp = realloc(ps->a, sizeof(SLDateType) * newcapacity);
		if (tmp == NULL) {
			printf("realloc fail");
		}
		else {
			ps->a = tmp;
			ps->capacity *= 2;
		}
	}
	for (int i = ps->size - 1; i >= 0; i--) {
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SeqList* ps) {
	assert(ps);
	for (int i = 0; i < ps->size - 1; i++) {
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

void SeqListPopBack(SeqList* ps) {
	assert(ps);
	ps->size--;
}

int SeqListFind(SeqList* ps, SLDateType x) {
	for (int i = 0; i < ps->size; i++) {
		if (ps->a[i] == x) {
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SeqList* ps, size_t pos, SLDateType x) {
	assert(ps);
	if (ps->size == ps->capacity) {
		size_t newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDateType* tmp = realloc(ps->a, sizeof(SLDateType) * newcapacity);
		if (tmp == NULL) {
			printf("realloc fail");
		}
		else {
			ps->a = tmp;
			ps->capacity *= 2;
		}
	}
	for (int i = pos; i < ps->size - 1; i++) {
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[pos] = x;
}


void SeqListErase(SeqList* ps, size_t pos) {
	for (int i = pos; i < ps->size - 1; i++) {
		ps->a[i] = ps->a[i + 1];

	}
	ps->size--;
}
