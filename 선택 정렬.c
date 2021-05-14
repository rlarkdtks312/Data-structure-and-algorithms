#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

void selection_sort(int list[], int n)
{
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) { // n-1 횟수 반복
		least = i;
		for (j = i + 1; j < n; j++) // 최솟값 탐색, (n-1)-i 횟수 반복
			if (list[j] < list[least]) least = j;
		SWAP(list[i], list[least], temp); // 3(n-1) 횟수 반복
	}
}

//
int main(void)
{
	int i;
	srand(time(NULL));
	int list[10];
	int n = 10;
	for (i = 0; i < n; i++) // 난수 생성 및 출력
		list[i] = rand() % 100; // 난수 발생 범위 0~99
	selection_sort(list, n); // 선택정렬 호출
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}