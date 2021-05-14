#include <stdio.h>
#include <stdlib.h>

void SWAP(int* a, int* b, int temp) {//리스트의 인덱스의 값을 변경하는 함수
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int* list, int left, int right) {//퀵정렬 시에 기준점을 결정하고 기준점의 대소에 따라 리스트를 정렬합니다.
	int low = left;
	int high = right+1;
	int temp=0;
	int pivot = list[left];//리스트의 좌측을 기준으로 삼습니다.
	do {
		do {
			low++;//기준점보다 큰 값이 나올 때까지 low값을 증가시킵니다.
		} while (low <= right && list[low] < pivot);
		do {
			high--;//기준점보다 작은 값이 나올 때까지 high값을 증가시킵니다.
		} while (high >= left && list[high] > pivot);
		if(low<high)SWAP(&list[low], &list[high], temp);//low가 high보다 작을 경우 두 값의 인덱스를 바꿉니다.
	} while (low < high);//low가 high보다 작을 동안 반복합니다.
	SWAP(&list[left], &list[high], temp);//high인덱스와 기준점인 pivot의 인덱스를 바꿉니다.
	return high;//high값을 돌려줍니다.
}

void quick_sort(int* list, int left, int right) {//퀵정렬을 실행하는 함수
	if (left < right) {
		int q = partition(list, left, right);//받은 high값을 기준으로 리스트를 분할 합니다.
		quick_sort(list, left, q - 1);//기준의 좌측에 있는 리스트를 정렬합니다.
		quick_sort(list, q + 1, right);//high보다 우측에 있는 리스트를 정렬합니다.
	}
}

int H_index(int* list, int n) {//H-index를 알아내는 함수
	int i = 0;
	int h = 0;//h-index를 저장할 변수를 선언합니다.
	for (i = 0; i < n; i++) {//리스트의 처음부터 끝까지 반복합니다.
		if (n - i >= list[i]) {//현재 인덱스의 우측에 있는 인덱스들의 수가 인덱스의 값과 같거나 크면 h에 인덱스의 값을 삽입합니다.
			h = list[i];
		}
		else if (n < list[i] && h < n - i) {//인덱스의 값이 전체 리스트의 개수보다 크고 저장된 h값이 남은 리스트개수보다 작으면 h에 남은 리스트의 개수를 삽입합니다.
			h = n - i;
		}
	}
	return h;//h-index값을 돌려줍니다.
}

int main(){
	int* citations;
	int n = 0;
	scanf_s("%d", &n);//발표한 논문의 개수를 입력받습니다.
	citations = (int*)malloc(sizeof(int) * n);//논문의 개수만큼 동적할당 합니다.
	int left = 0;
	int right = n - 1;
	for (int i = 0; i < n; i++) {//각 논문의 활용횟수를 입력받습니다.
		scanf_s("%d", &citations[i]);
	}
	quick_sort(citations, left, right);//논문을 활용횟수의 크기에따라 정렬합니다.
	for (int i = 0; i < n; i++) {//정렬한 값을 출력합니다.
		printf("%d", citations[i]);
	}
	printf("H-index : %d",H_index(citations, n));//h-index값을 출력합니다.
	free(citations);//동적할당을 해제합니다.
}
