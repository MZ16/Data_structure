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
/*기둥이 3개일때, 4개면 매개변수가 늘어남, 이동횟수 원판>=3 이면 (원판개수-3*7)+7=이동횟수 */
int Hanoi(int val, char first, char by, char to) { // 최초 인자 전달자체가 1트 (A -> C)
	if (val == 1) { printf("원판1이 기둥%c에서 기둥%c로 이동\n", first, to); return 0; }
	Hanoi(val-1,first,to,by);
	printf("원판%d가/이 기둥%c에서 기둥%c로 이동\n",val,first,to);
	Hanoi(val - 1, by, first, to);
} 

int main() {
	init();
	Hanoi(4, 'A', 'B', 'C');
	return 0;
}