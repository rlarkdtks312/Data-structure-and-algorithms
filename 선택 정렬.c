#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

void selection_sort(int list[], int n)
{
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) { // n-1 Ƚ�� �ݺ�
		least = i;
		for (j = i + 1; j < n; j++) // �ּڰ� Ž��, (n-1)-i Ƚ�� �ݺ�
			if (list[j] < list[least]) least = j;
		SWAP(list[i], list[least], temp); // 3(n-1) Ƚ�� �ݺ�
	}
}

//
int main(void)
{
	int i;
	srand(time(NULL));
	int list[10];
	int n = 10;
	for (i = 0; i < n; i++) // ���� ���� �� ���
		list[i] = rand() % 100; // ���� �߻� ���� 0~99
	selection_sort(list, n); // �������� ȣ��
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}