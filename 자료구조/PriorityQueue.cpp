#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HEAP_LEN 100
#define TRUE 1
#define FALSE 0
 // �迭 idx�� ������� �켱������ ����
typedef char HData;
typedef int Priority;

typedef struct _heapElem {
	Priority pr;
	HData data;
}HeapElem;

typedef struct _heap {
	int numOfData; // ������ ����� ������ȣ
	HeapElem heapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap* ph) {
	ph->numOfData = 0;
}

int HEmpty(Heap * ph) {
	if (ph->numOfData == 0) return TRUE;
	else return FALSE;
}

int GetLChildIDX(int idx) {
	return idx * 2;
}
int GetRChildIDX(int idx) {
	return idx * 2 + 1;
}
int GetParentIDX(int idx) {
	return idx / 2;
}

int GetHiPriChildIDX(Heap* ph, int idx) {
	//�ڽ��� ������
	if (GetLChildIDX(idx)>ph->numOfData) return 0;
	//�ڽ��� �ϳ���
	else if (ph->numOfData == GetLChildIDX(idx)) return GetLChildIDX(idx);
	//�ڽ��� ���̸�
	else {
		if (ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap * ph, Priority pr, HData data) {
	int idx = ph->numOfData + 1;
	HeapElem newElem = { pr,data };

	while (idx != 1) {
		if (pr < ph->heapArr[GetParentIDX(idx)].pr) { //������� �켱������ �������
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)]; // �θ��带 �ѷ��� ����
			idx = GetParentIDX(idx);
		}
		else {
			break;
		}
	}
	ph->heapArr[idx] = newElem;
	ph->numOfData++;
}

HData HDelete(Heap* ph) {
	HData retData = ph->heapArr[1].data;// ������ ������ ����
	HeapElem lastElem = ph->heapArr[ph->numOfData];// ���� ������ ��� ����

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIDX(ph, parentIdx)) {
		if (ph->heapArr[childIdx].pr >= lastElem.pr) break; // Ż������
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}
	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData--;
	return retData;

}

int main() {
	Heap ph;
	HeapInit(&ph);
	HInsert(&ph, 1, '1'); HInsert(&ph, 2, '2');
	HInsert(&ph, 4, '4'); HInsert(&ph, 3, '3');

	//printf("%c\n", HDelete(&ph));

	HInsert(&ph, 1, 'A'); HInsert(&ph, 2, 'B');
	HInsert(&ph, 4, 'D'); HInsert(&ph, 3, 'C');

	while (!HEmpty(&ph)) {
		printf("%c\n", HDelete(&ph));
	}
}