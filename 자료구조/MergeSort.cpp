#include <stdio.h>
#include <stdlib.h>

void Merge(int list[], int left, int mid, int right) {
	/* i : ���ĵ� ���� ����Ʈ�� ���� �ε���
	*  j : ���ĵ� ������ ����Ʈ�� ���� �ε���
	*  k : ���ĵ� ����Ʈ�� ���� �ε���	*/
	int i, j, k;
	int* sortArr = (int*)malloc(sizeof(int) * (right + 1));
	i = left;
	j = mid + 1;
	k = left;
	/* ���� ���ĵ� list�� �պ� */
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sortArr[k++] = list[i++];
		else
			sortArr[k++] = list[j++];
	}
	/* �����ִ� ������ �ϰ� ���� */
	if (i > mid)
		for (int x = j; x <= right; x++)
			sortArr[k++] = list[x];
	/* �����ִ� ������ �ϰ� ���� */
	else
		for (int x = i; x <= mid; x++)
			sortArr[k++] = list[x];
	/* ���ĵ� �迭�� ���� �迭�� �纹��*/
	for (int i = left; i <= right; i++)list[i] = sortArr[i];
	free(sortArr);
}

void MergeSort(int list[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2; // �߰� ��ġ�� ����Ͽ� �յ� ���� / ����(Divide)
		MergeSort(list, left, mid); // ���� �κ� ����Ʈ ���� / ����(Conquer)
		MergeSort(list, mid + 1, right); // ���� �κ� ����Ʈ ���� / ����(Conquer)
		Merge(list, left, mid, right); // ���ĵ� �հ��� ����Ʈ�� �պ� / ����(Combine)
	}

}


int main() {
	int N;
	scanf("%d", &N);
	int* list = (int*)malloc(sizeof(int) * (N + 1));
	for (int i = 0; i < N; i++) {
		scanf("%d", &list[i]);
	}
	MergeSort(list, 0, N - 1);
	for (int i = 0; i < N; i++)printf("%d\n", list[i]);
	free(list);
	return 0;
}