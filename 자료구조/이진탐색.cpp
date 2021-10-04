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

int Linear_Search(int arr[], int len, int target);
int Binary_Search(int arr[], int len, int target);
/* 이진탐색의 최악의 시간복잡도
* n이 1이 되기까지 2로 나눈 횟수 k회 + 데이터가 1개 남았을 때 마지막 비교연산 1회 - [ n*(1/2)^k=1 ]
* 최악의 경우 시간복잡도 - T(n) = K+1
* n * (1/2)^k =1 -> n * 2^-k = 1 -> n = 2^k  // (로그의 지수를 생략하면 2이다) 
* n = 2^k -> log n = log 2^k -> log n = k log 2 -> log n = k
* T(n) = log n + 1 -> T(n) = log n // 뒤에 오는 +1의 연산횟수는 크게 중요하지 않기때문에 생략하는것이 보편적이다.
* 그래서 생겨난 것이 빅-오 표기법이며 최고차항만 취급함 Ex) T(n) = n^2 + 2n + 1 인 최악의 시간복잡도를 O(n^2)로 표현
* 빅오표기법의 크기와 뜻하는바는 자료구조책 37p에 자세히 나와있음
*/
/* 빅-오에 대한 수학적 판별법 
	두 개의 함수 f(n)과 g(n)이 주어졌을 때 모든 n>=K에 대하여 F(n) <= Cg(n)을 만족하는 두개의 상수 C와 K가 존재한다면 
	f(n)의 빅-오는 O(g(n))이다.
*/
void Bubble_sort(int arr[], int len);

int main() {
	init();
	int arr[10] = { 0, };
	for (int i = 0; i < 10; i++) {
		int num;
		scanf("%d", &num);
		arr[i] = num;
	}
	int len = sizeof(arr)/sizeof(int);
	
	if (Linear_Search(arr, len, 5) == -1)
		printf("target이 없습니다.\n");
	else
		printf("Linear_serch target 5의 seach횟수는 %d입니다.\n", Linear_Search(arr, len, 5));
	
	Bubble_sort(arr, len);

	if (Binary_Search(arr, len, 7) == -1)
		printf("target이 없습니다.\n");
	else
		printf("Binary_search target 7의 search횟수는 %d입니다.\n", Binary_Search(arr, len, 7));
	/*각 Seach의 연산 횟수 비교*/
	
	int arr1[500] = { 0, };
	int arr2[5000] = { 0, };
	int arr3[50000] = { 0, };
	Linear_Search(arr1, sizeof(arr1) / sizeof(int), 1);
	Linear_Search(arr2, sizeof(arr2) / sizeof(int), 1);
	Linear_Search(arr3, sizeof(arr3) / sizeof(int), 1);

	Binary_Search(arr1, sizeof(arr1) / sizeof(int), 1);
	Binary_Search(arr2, sizeof(arr2) / sizeof(int), 1);
	Binary_Search(arr3, sizeof(arr3) / sizeof(int), 1);
	

	return 0;
}

void Bubble_sort(int arr[], int len) {
	int tmp;
	for (int i = 0; i < len; i++) {
		for (int j = i+1; j < len; j++) {
			if (arr[i] > arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

int Linear_Search(int arr[], int len, int target) {
	int LinearOpCnt = 0;
	for (int i = 0; i < len; i++) {
		if (target == arr[i]) {
			return i+1;
		}
		LinearOpCnt++;
	}
	printf("Linear_Search 비교연산 횟수 : %d\n", LinearOpCnt);
	return -1;
}

int Binary_Search(int arr[], int len, int target) {
	int first = 0;
	int last = len - 1; // 배열은 0부터시작이니까
	int mid,cnt=0;
	int BinaryOpcnt=0;
	while (first <= last) {
		cnt++;
		mid = (first + last) / 2;
		if (arr[mid] == target) return cnt;
		else {
			if (target < arr[mid]) last=mid-1;
			else if (target > arr[mid]) first = mid + 1;
		}
		BinaryOpcnt++;
	}
	printf("Binary_search의 비교연산 횟수 : %d\n", BinaryOpcnt);
	return -1;
}