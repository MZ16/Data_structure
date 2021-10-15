#include<stdio.h>
#include<stdlib.h>
#define MAX_LEN 20

int main() {
	int arr[MAX_LEN];
	for (int i = 0; i < MAX_LEN; i++) scanf("%d", &arr[i]);
	
	for (int i = 0; i < MAX_LEN-1; i++) { // 작은 수 부터 정렬
		for (int j = i + 1; j < MAX_LEN; j++) {
			if (arr[i] > arr[j]) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	/*
	for (int i = 0; i < MAX_LEN-1; i++) { // 큰 수 부터 정렬
		for (int j = 0; j < (MAX_LEN-i)-1; j++) {
			if (arr[j] > arr[j+1]) {
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}*/

	for (int i = 0; i < MAX_LEN; i++) printf("%d ", arr[i]);
	return 0;

}

/* 10 2 5 20 9 8 1 17 12 3 16 4 11 15 7 6 13 14 19 18
* 
*/