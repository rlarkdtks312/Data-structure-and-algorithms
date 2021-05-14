#define MAXSIZE 10 
#include <stdio.h> 
#include <stdlib.h>

int sorted[MAXSIZE]; // �߰� ������ �ʿ�
// i�� ���ĵ� ���ʸ���Ʈ�� ���� �ε���
// j�� ���ĵ� �����ʸ���Ʈ�� ���� �ε���
// k�� ���ĵ� ����Ʈ�� ���� �ε���
void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	// ���� ���ĵ� list�� �պ�
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
	}
	if (i > mid) // ���� �ִ� ���ڵ��� �ϰ� ����
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else // ���� �ִ� ���ڵ��� �ϰ� ����
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	// �迭 sorted[]�� ����Ʈ�� �迭 list[]�� ����
	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left < right) {
		mid = (left + right) / 2; // ����Ʈ�� �յ����
		merge_sort(list, left, mid); // �κи���Ʈ ����
		merge_sort(list, mid + 1, right); //�κи���Ʈ ����
		merge(list, left, mid, right); // �պ�
	}
}

int main(void)
{
	int i;
	int n = MAXSIZE;
	int list[MAXSIZE];
	srand(time(NULL));
	for (i = 0; i < n; i++) // ���� ���� �� ���
		list[i] = rand() % 100;
		merge_sort(list, 0, n - 1); // ������ ȣ��
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}