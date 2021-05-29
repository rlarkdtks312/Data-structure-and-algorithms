#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000

typedef struct Heap {//힙 구조체 선언
    int heap_size;
    int heap[MAX_SIZE];
}Heap;

Heap* create()//힙 생성
{
    return (Heap*)malloc(sizeof(Heap));
}

void init(Heap* h)//힙 초기화 함수
{
    h->heap_size = 0;
}

void insert_heap(Heap* h, int data)//힙에 노드를 추가하는 함수
{
    int i;
    i = ++(h->heap_size);
    while ((i != 1) && (data > h->heap[i / 2])) {// 트리를 거슬러 올라가면서 부모 노드와 비교
        h->heap[i] = h->heap[i / 2];//부모 노드의 값보다 클 경우 부모 노드와 위치를 바꿈
        i /= 2;
    }
    h->heap[i] = data; // 새로운 노드를 추가
}

int delete_heap(Heap* h)//힙의 루트를 삭제하는 함수
{
    int parent, child;
    int data, temp;
    data = h->heap[1];//돌려줄 힙의 루트 값을 저장
    temp = h->heap[(h->heap_size)--];//힙의 크기를 줄이고 마지막으로 추가된 노드를 저장
    parent = 1;
    child = 2;
    while (child <= h->heap_size) {
        if ((child < h->heap_size) && (h->heap[child]) < h->heap[child + 1])// 현재 노드의 자식노드 중 더 큰 자식노드를 찾음
            child++;
        if (temp >= h->heap[child]) break;// temp가 자식노드들보다 클 경우 반복문을 빠져나감
        h->heap[parent] = h->heap[child];//부모와 자식 노드의 위치를 바꿈
        parent = child;//트리의 다음 높이로 내려감
        child *= 2;
    }
    h->heap[parent] = temp;//temp값을 parent 위치에 삽입
    return data;//힙의 루트값을 돌려줌
}

int middle(Heap* h) {//힙의 중간값을 찾는 함수
    int s = h->heap_size;//힙의 크기를 저장
    int* sort = (int*)malloc(sizeof(int) * s);//힙을 정렬할 sort를 동적할당
    Heap* heap1;//새로운 힙을 생성
    heap1 = create();
    init(heap1);
    for (int i = 0; i < s; i++) {//입력받은 힙을 그대로 새로운 힙에 복사
        insert_heap(heap1, h->heap[i+1]);
    }
    for (int i = s-1; i >= 0; i--) {//힙의 루트들을 제거하면서 작은수가 처음에 오도록 sort에 값을 저장
        sort[i] = delete_heap(heap1);
    }
    int mid = sort[(s-1) / 2];//저장된 값의 중간값을 mid에 저장
    free(sort);//동적할당 해제
    free(heap1);
    return mid;//mid값을 돌려줌
}

int main(void){
    int data;
    int num = 0;
    Heap* heap;//힙 생성
    heap = create();
    init(heap);
    scanf_s("%d", &num);//입력받을 수의 개수를 입력받음
    int* ans = (int*)malloc(sizeof(int) * num);//가운데 수를 저장할 ans를 동적할당
    for (int i = 0 ; i < num; i++) {//num만큼 수를 입력받고 입력받을 때마다 가운데 값을 ans에 저장
        scanf_s("%d", &data);
        insert_heap(heap, data);
        ans[i] = middle(heap);
    }
    printf("가운데 값\n");
    for (int i = 0; i < heap->heap_size; i++) {//저장된 가운데 값들을 출력
        printf("%d\n", ans[i]);
    }
    free(ans);//동적할당 해제
}
