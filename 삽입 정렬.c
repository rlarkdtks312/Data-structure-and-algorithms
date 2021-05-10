#include <stdio.h>
#pragma warning(disable: 4996)
#include <stdlib.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

// ��������
void insertion_sort(int list[], int n)
{
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j]; // ���ڵ��� ������ �̵�
		list[j + 1] = key;
	}
}

//
int main(void)
{
	int i;
	srand(time(NULL));
	int list[5];
	int n = 5;
	for (i = 0; i < n; i++) // ���� ���� �� ���
		list[i] = rand() % 100; // ���� �߻� ���� 0~99
	insertion_sort(list, n); // �������� ȣ��
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}