#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int cnt;

int Binary_Search(int arr[], int first, int last, int target) { // 연산횟수 구하기
	int mid = (first + last) / 2;
	printf("mid=%d, first=%d, last=%d\n", mid,first,last);
	if (first > last) return -1;
	cnt++; // 연산횟수
	if (arr[mid] == target) return cnt;
	else {
		if (arr[mid] < target) Binary_Search(arr, mid + 1, last, target);
		else if (arr[mid] > target) Binary_Search(arr, first, mid - 1, target);
	}
}

int main() {
	init();
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	if (Binary_Search(arr, 0, sizeof(arr) / sizeof(int) - 1, 4) > 0) printf("%d\n", cnt);
	else printf("없는 숫자\n");
	return 0;
}