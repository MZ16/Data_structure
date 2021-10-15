#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 20

int main() {
	int arr[MAX_LEN];
	int maxIdx;
	for (int i = 0; i < MAX_LEN; i++) scanf("%d", &arr[i]);

	for (int i = 0; i < MAX_LEN-1; i++) {
		maxIdx = i;
		for (int j = i + 1; j < MAX_LEN; j++) {
			if (arr[j] < arr[maxIdx]) maxIdx = j;
		}
		int tmp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = tmp;
	}

	for (int i = 0; i < MAX_LEN; i++)printf("%d ", arr[i]);
	return 0;
}

/* 10 2 5 20 9 8 1 17 12 3 16 4 11 15 7 6 13 14 19 18
*
*/