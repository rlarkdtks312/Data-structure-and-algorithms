#include <stdio.h>
#pragma warning(disable: 4996)
#include <stdlib.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

void bubble_sort(int list[], int n)
{
	int i, j, temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) { // �յ��� ���ڵ带 ���� �� ��ü
			if (list[j] > list[j + 1])
				SWAP(list[j], list[j + 1], temp);
		}
	}
}

int main(void)
{
	int i;
	srand(time(NULL));
	int list[5];
	int n = 5;
	for (i = 0; i < n; i++) // ���� ���� �� ���
		list[i] = rand() % 100; // ���� �߻� ���� 0~99
	bubble_sort(list, n); // �������� ȣ��
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}