#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int start;
    int reach;
    struct node* node;
}node;

typedef struct move {//링크드리스트를 구조체로 선언합니다.
    node* head = (node*)malloc(sizeof(node));
    node* tail = (node*)malloc(sizeof(node));
}move;

move* create() {//링크드리스트를 생성하는 함수입니다. 시작부분인 head와 리스트의 끝부분을 가리키는 tail을 선언했습니다.
    move* m = (move*)malloc(sizeof(move));
    m->head = NULL;
    m->tail = NULL;
    return m;
}

void insert(move* m, int start, int reach) {//링크드리스트에 순차적으로 값을 추가하는 함수입니다.
    node* new1 = (node*)malloc(sizeof(node));//값을 추가할 노드를 생성합니다.
    new1->start = start;
    new1->reach = reach;
    if (m->head == NULL) {//링크드리스트가 공백일 경우 head와 tail에 new1의 주소를 삽입합니다.
        m->head = m->tail = new1;
    }
    else {//공백이 아닐 경우 NULL과 tail사이에 노드를 추가합니다.
        m->tail->node = new1;
        new1->node = NULL;
        m->tail = new1;
    }
}
void print(move* m) {//링크드리스트를 출력하는 함수입니다.
    while (m->head != NULL) {//링크드리스트의 시작부터 끝을 알리는 NULL이 나올 떄까지 저장된 값을 출력합니다.
        printf("%d %d\n", m->head->start, m->head->reach);
        m->head = m->head->node;
    }
}

void movement(int start, int reach, int* k, move* m) {//하노이 탑의 판의 출발지와 도착지를 링크드리스트에 값을 추가합니다. 그리고 이동횟수인 k에 1을 더합니다.
    insert(m, start, reach);
    *k=*k+1;
}

int hanoi(int n, int start, int mid, int reach,int* k, move* m) {//하노이 탑의 이동순서와 이동횟수를 계산할 함수입니다.
    if (n == 1) {//판의 개수가 1개 일경우 경유지를 거치지 않고 도착지로 바로 이동시킵니다.
        movement(start, reach, k, m);
    }
    else {//판의 개수가 1개보다 많을 경우 마지막 판을 제외한 모든 판들을 경유지로 옮기고, 마지막 판을 도착지로, 경유지에 있는 판들을 도착지로 옮깁니다.
        hanoi(n - 1, start, reach, mid, k, m);//마지막판을 제외한 판들을 경유지로 옮기는 재귀함수
        movement(start, reach, k, m);//마지막판을 도착지로 옮깁니다.
        hanoi(n - 1, mid, start, reach, k, m);//경유지에 있던 판들을 도착지로 옮기는 재귀함수
    }
    return *k;//이동한 횟수를 돌려줍니다.
}

int main(){
    int n = 0;//판의 개수를 저장할 변수입니다.
    int k = 0;//판을 이동시킨 횟수를 기록할 변수입니다.
    move* m = create();
    printf("판의 개수를 입력하십시오");
    scanf_s("%d", &n);
    printf("%d\n", hanoi(n, 1, 2, 3, &k, m));//판을 이동한 횟수를 출력합니다.
    print(m);//판들의 출발지와 도착지를 순서대로 출력합니다.
 }

