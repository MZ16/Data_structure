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
/*����� 3���϶�, 4���� �Ű������� �þ, �̵�Ƚ�� ����>=3 �̸� (���ǰ���-3*7)+7=�̵�Ƚ�� */
int Hanoi(int val, char first, char by, char to) { // ���� ���� ������ü�� 1Ʈ (A -> C)
	if (val == 1) { printf("����1�� ���%c���� ���%c�� �̵�\n", first, to); return 0; }
	Hanoi(val-1,first,to,by);
	printf("����%d��/�� ���%c���� ���%c�� �̵�\n",val,first,to);
	Hanoi(val - 1, by, first, to);
} 

int main() {
	init();
	Hanoi(4, 'A', 'B', 'C');
	return 0;
}