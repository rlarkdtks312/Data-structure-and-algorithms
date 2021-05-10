#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_QEUEU_SIZE 101

typedef int element;
typedef struct {//큐 정의
    int front;
    int rear;
    element data[MAX_QEUEU_SIZE];
}QeueuType;

void error(const char* message) {//에러 메세지
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_qeueu(QeueuType* q) {//큐 초기화
    q->front = q->rear = 0;
}

int is_full(QeueuType* q) {//큐 포화 상태 확인
    return q->front == ((q->rear + 1) % MAX_QEUEU_SIZE);
}

int is_empty(QeueuType* q) {//큐 공백 상태 확인
    return q->front == q->rear;
}

void enqeueu(QeueuType* q, element e) {//큐 추가 함수
    if (is_full(q)) {
        error("큐가 포화상태입니다.");
    }
    q->rear = (q->rear + 1) % MAX_QEUEU_SIZE;
    q->data[q->rear] = e;
}

void deqeueu(QeueuType* q) {//큐 제거 함수
    if (is_empty(q)) {
        error("큐가 공백상태입니다.");
    }
    q->front = (q->front + 1) % MAX_QEUEU_SIZE;
}

element complete(QeueuType* p, QeueuType* s) {//개발이 완료되었는지 확인하고 완료 되었다면 큐에서 제거
    if (p->data[p->front + 1] >= 100) {
        deqeueu(p);
        deqeueu(s);
        return 1;
    }
    return 0;
}

int main(void)
{
    QeueuType progress, speed;
    init_qeueu(&progress);
    init_qeueu(&speed);
    srand(time(NULL));
    int nump = rand() % 100;//개발과정과 개발 속도의 개수를 랜덤 정의
    int* solution;
    solution = (int*)malloc(100 * sizeof(int));//일자별 개발 완료 상황을 저장할 동적 할당 생성
    int j = 0;
    for (int k = 0; k < nump; k++) {
        element P = rand() % 99 + 1;//개발 과정 랜덤 정의
        element S = rand() % 100 + 1;//개발 속도 랜덤 정의
        enqeueu(&progress, P);
        enqeueu(&speed, S);
        printf("개발 진행도와 개발 속도 : %d,%d\n", progress.data[k+1], speed.data[k+1]);
    }
    int i = progress.front;
     do {//progress가 공백이 될 때까지 반복
        solution[j] = 0;//일자별 개발 완료 상황 초기화
        while (i != progress.rear) {//큐에 추가된 progress와 speed값을 더해서 progress에 저장
            i = (i + 1) % MAX_QEUEU_SIZE;
            progress.data[i] = progress.data[i] + speed.data[i];            
         }
        while (complete(&progress, &speed)) {//개발이 완료된 경우 큐에서 progress와 speed를 제거하고 solution에 1을 더함
             solution[j] = solution[j] + 1;            
             if (is_empty(&progress)) {//progress가 공백이 되면 반복문 탈출
                 break;
             }
        }
        i = progress.front;//반복문을 위해 i를 다시 fornt값으로 초기화
        j = j + 1;//일자를 다음날로 넘김
    }while (is_empty(&progress) != 1);

    printf("발행되는 일자별 프로그램의 수는 ");
    for (int i = 0; i < j; i++) {//모든 개발이 끝난 일자까지 각 날짜별 완료 수를 프린트
        printf("%d일 : %d개 ", (i+1), solution[i]);
    }
    free(solution);

}