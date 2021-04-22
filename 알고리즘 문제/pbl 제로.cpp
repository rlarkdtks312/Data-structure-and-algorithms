#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100000

typedef int element;
typedef struct {//스택 정의
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

void error(const char* message) {//에러 메시지
    fprintf(stderr, "%s", message);
}

void init_stack(StackType* s){//스택 초기화
    s->top = -1;
}

int is_empty(StackType* s) {//스택 공백 확인
    return s->top == -1;
}

int is_full(StackType* s) {//스택 포화 확인
    return s->top == MAX_STACK_SIZE-1;
}

void push(StackType* s, element value) {//스택 추가 함수
    if (is_full(s)) {
        error("스택이 포화 상태입니다.");
    }
    s->data[++(s->top)] = value;
}

element pop(StackType* s) {//스택 제거 함수
    if(is_empty(s)) {
        error("스택이 공백 상태입니다.");
    }
    return s->data[(s->top)--];
}

int main(){
    StackType money;
    init_stack(&money);
    int K=0;
    printf("장부의 출납금의 개수를 입력하시오.");
    scanf_s("%d", &K);//장부의 출납금의 개수를 입력받음
    int num = 0;
    int sum = 0;
    element m=0;
    while (num < K) {   
        printf("장부의 금액을 입력해 주세요");
        scanf_s("%d", &m);//장부의 출납금액을 입력받음.
        if (is_empty(&money)) {//스택이 공백 일 때 금액이 0이 되지 않도록 함
            while (m == 0) {
                printf("잘못된 입력입니다. 다시 입력해주세요");
                scanf_s("%d", &m);
            }
            push(&money, m);
        }
        else if (m == 0) {//0일 경우 스택의 값 제거
            pop(&money);
        }
        else {//0이 아닐 경우 스택에 값 추가
            push(&money, m);
        }
        num++;
    }
    while (is_empty(&money) != 1) {//스택에 저장된 값들의 합
        sum = sum + pop(&money);
    }
    printf("장부 금액의 총합은 %d 입니다.", sum);
}

