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
/* ����Ž���� �־��� �ð����⵵
* n�� 1�� �Ǳ���� 2�� ���� Ƚ�� kȸ + �����Ͱ� 1�� ������ �� ������ �񱳿��� 1ȸ - [ n*(1/2)^k=1 ]
* �־��� ��� �ð����⵵ - T(n) = K+1
* n * (1/2)^k =1 -> n * 2^-k = 1 -> n = 2^k  // (�α��� ������ �����ϸ� 2�̴�) 
* n = 2^k -> log n = log 2^k -> log n = k log 2 -> log n = k
* T(n) = log n + 1 -> T(n) = log n // �ڿ� ���� +1�� ����Ƚ���� ũ�� �߿����� �ʱ⶧���� �����ϴ°��� �������̴�.
* �׷��� ���ܳ� ���� ��-�� ǥ����̸� �ְ����׸� ����� Ex) T(n) = n^2 + 2n + 1 �� �־��� �ð����⵵�� O(n^2)�� ǥ��
* ���ǥ����� ũ��� ���ϴ¹ٴ� �ڷᱸ��å 37p�� �ڼ��� ��������
*/
/* ��-���� ���� ������ �Ǻ��� 
	�� ���� �Լ� f(n)�� g(n)�� �־����� �� ��� n>=K�� ���Ͽ� F(n) <= Cg(n)�� �����ϴ� �ΰ��� ��� C�� K�� �����Ѵٸ� 
	f(n)�� ��-���� O(g(n))�̴�.
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
		printf("target�� �����ϴ�.\n");
	else
		printf("Linear_serch target 5�� seachȽ���� %d�Դϴ�.\n", Linear_Search(arr, len, 5));
	
	Bubble_sort(arr, len);

	if (Binary_Search(arr, len, 7) == -1)
		printf("target�� �����ϴ�.\n");
	else
		printf("Binary_search target 7�� searchȽ���� %d�Դϴ�.\n", Binary_Search(arr, len, 7));
	/*�� Seach�� ���� Ƚ�� ��*/
	
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
	printf("Linear_Search �񱳿��� Ƚ�� : %d\n", LinearOpCnt);
	return -1;
}

int Binary_Search(int arr[], int len, int target) {
	int first = 0;
	int last = len - 1; // �迭�� 0���ͽ����̴ϱ�
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
	printf("Binary_search�� �񱳿��� Ƚ�� : %d\n", BinaryOpcnt);
	return -1;
}