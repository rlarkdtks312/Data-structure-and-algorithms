#include <stdio.h>
#include <stdlib.h>

typedef struct position {//좌표를 저장할 구조체를 정의합니다.
	int x=0;
	int y=0;
}pos;

void merge(pos* p, int left, int mid, int right) {//분할한 배열을 합병하는 함수입니다.
	int l = left;//좌측분할배열의 시작점을 저장할 변수입니다.
	int r = mid + 1;//우측분할배열의 시작점을 저장할 변수입니다.
	int rest;
	int k = left;//정렬된 배열을 저장할 공간의 시작점을 저장할 변수입니다.
	pos* sort = (pos*)malloc(sizeof(pos) * (right+1));//합병한 배열을 저장할 공간을 동적할당합니다.
	while (l <= mid && r <= right){//좌측이나 우측분할배열이 끝날 떄까지 반복합니다.
		if (p[l].x < p[r].x) {//좌측배열의 x값이 우측보다 작을 경우 sort에 추가하고 l을 증가시킵니다.
			sort[k].x = p[l].x;
			sort[k++].y = p[l++].y;
		}
		else if (p[l].x == p[r].x) {//x값이 동일할 경우 y값의 크기가 작은 것을 sort에 추가하고 해당되는 변수의 값을 증가시킵니다.
			if (p[l].y < p[r].y) {
				sort[k].x = p[l].x;
				sort[k++].y = p[l++].y;
			}
			else {
				sort[k].x = p[r].x;
				sort[k++].y = p[r++].y;
			}
		}
		else {//우측배열의 x값이 좌측보다 작을 경우 sort에 추가하고 r을 증가시킵니다.
			sort[k].x = p[r].x;
			sort[k++].y = p[r++].y;
		}			
	}
	if (l > mid) {//정렬하고 남은 배열을 순서대로 sort배열에 추가합니다.
		for (rest = r; rest <= right; rest++) {
			sort[k].x = p[rest].x;
			sort[k++].y = p[rest].y;
		}
	}
	else{
		for (rest = l; rest <= mid; rest++) {
			sort[k].x = p[rest].x;
			sort[k++].y = p[rest].y;
		}
	}
	for (int i = left; i <= right; i++) {//sort에 정렬되어 있는 배열을 초기배열인 p에 저장합니다.
		p[i].x = sort[i].x;
		p[i].y = sort[i].y;
	}
	free(sort);//동적할당한 sort를 해제합니다.
}

void merge_sort(pos* p, int left, int right) {//합병정렬을 실행하는 함수입니다.
	int mid;
	if (left < right) {
		mid = (left + right) / 2;//배열의 중간 인덱스를 mid에 삽입합니다.
		merge_sort(p, left, mid);//좌측부분을 정렬합니다.
		merge_sort(p, mid + 1, right);//우측부분을 정렬합니다.
		merge(p, left, mid, right);//정렬된 두 부분을 합병합니다.
	}
}

int main() {
	int n = 0;
	printf("좌표의 개수를 입력하십시오");
	scanf_s("%d", &n);//입력받을 좌표의 개수를 입력받습니다.
	pos* p = (pos*)malloc(sizeof(pos) * n);//좌표를 저장할 구조체를 동적할당합니다.
	int l = 0;
	int r = n - 1;
	for (int i = 0; i < n; i++) {//좌표를 입력받습니다.
		printf("좌표를 입력하십시오");
		scanf_s("%d %d", &p[i].x, &p[i].y);
	}
	merge_sort(p, l, r);//좌표를 합병정렬합니다.
	for (int i = 0; i < n; i++) {//합병정렬한 배열을 출력합니다.
		printf("%d %d\n", p[i].x, p[i].y);
	}
	free(p);//동적할당을 해제합니다.
}