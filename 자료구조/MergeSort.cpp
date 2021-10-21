#include <stdio.h>
#include <stdlib.h>

void Merge(int list[], int left, int mid, int right) {
	/* i : 정렬된 왼쪽 리스트에 대한 인덱스
	*  j : 정렬된 오른쪽 리스트에 대한 인덱스
	*  k : 정렬될 리스트에 대한 인덱스	*/
	int i, j, k;
	int* sortArr = (int*)malloc(sizeof(int) * (right + 1));
	i = left;
	j = mid + 1;
	k = left;
	/* 분할 정렬된 list의 합병 */
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sortArr[k++] = list[i++];
		else
			sortArr[k++] = list[j++];
	}
	/* 남아있는 값들을 일괄 복사 */
	if (i > mid)
		for (int x = j; x <= right; x++)
			sortArr[k++] = list[x];
	/* 남아있는 값들을 일괄 복사 */
	else
		for (int x = i; x <= mid; x++)
			sortArr[k++] = list[x];
	/* 정렬된 배열을 기존 배열에 재복사*/
	for (int i = left; i <= right; i++)list[i] = sortArr[i];
	free(sortArr);
}

void MergeSort(int list[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2; // 중간 위치를 계산하여 균등 분할 / 분할(Divide)
		MergeSort(list, left, mid); // 앞쪽 부분 리스트 정렬 / 정복(Conquer)
		MergeSort(list, mid + 1, right); // 뒤쪽 부분 리스트 정렬 / 정복(Conquer)
		Merge(list, left, mid, right); // 정렬된 앞과뒷 리스트를 합병 / 결합(Combine)
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