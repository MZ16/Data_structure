#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 20

int main() {
	int arr[MAX_LEN];
	int insData;
	int j;
	for (int i = 0; i < MAX_LEN; i++) scanf("%d", &arr[i]);

	for (int i = 1; i < MAX_LEN; i++) {
		insData = arr[i]; // ���� ���
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > insData) arr[j + 1] = arr[j]; // �񱳴�� �ڷ� ��ĭ �̵�
			else break;
		}		
		arr[j+1] = insData; // ã�� ��ġ�� insData ����
	}
	for (int i = 0; i < MAX_LEN; i++)printf("%d ", arr[i]);

	return 0;
}

/* 10 2 5 20 9 8 1 17 12 3 16 4 11 15 7 6 13 14 19 18
*
*/