#include <stdio.h>
#include <string.h>
#define max 9
int main() {
	int arr[] = { 0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11};
	int number = 13;


	int left = 0;
	int right = sizeof(arr) / sizeof(arr [0] );
	int mid = (left + right) / 2;
	while (left <= right) {
		mid = (left + right) / 2;
		if (arr[mid] > number) {
			right = mid - 1;
		}
		if (arr[mid] < number) {
			left = mid + 1;
		}
		if (arr[mid] == number) {
			printf("找到了\n");
			break;
		}
	}
	if (left > right) {
		printf("没找到\n");
	}
	return 0;
}
