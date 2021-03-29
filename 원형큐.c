#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5


// ===== 원형큐 코드 시작 ======
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct { // 큐 타입
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;
// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);	//에러 메세지 출력
	exit(1);
}
// 큐 초기화 함수
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;	//front, rear 를 0으로 초기화한다.
}
// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return (q->front == q->rear);	//front와 rear이 같다면 queue는 공백상태이다.
}
// 포화 상태 검출 함수
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);	// 포화 상태인경우 front는 0값을 가지고 rear은 queue 사이즈의 -1값을 가진다 따라서 %연산자를 통해서 같다면 포화상태이다.
}

// 원형큐 출력 함수
void queue_print(QueueType* q)	//front값에 1씩 증가시키면서 인덱스로 활용하여 queue에서 값을 출력한다.
{
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);	
	}
	printf("\n");
}
// 삽입 함수
void enqueue(QueueType* q, element item)	//rear값을 늘리고 그값을 인덱스로 활용하여 queue에 값 추가
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
// 삭제 함수
element dequeue(QueueType* q) // front값을 1늘려서 인덱스로 활용하여 값을 출력한다.
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

int main(void) //full 상태까지 채우고 empty 상태까지 꺼내기
{
	QueueType queue;
	int element;
	init_queue(&queue);
	printf("--데이터 추가 단계--\n");
	while (!is_full(&queue))	//full 상태가 아니라면
	{
		printf("정수를 입력하시오: ");
		scanf("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
	}
	printf("큐는 포화상태입니다.\n\n");
	printf("--데이터 삭제 단계--\n");
	while (!is_empty(&queue))
	{
		element = dequeue(&queue);
		printf("꺼내진 정수: %d \n", element);
		queue_print(&queue);
	}
	printf("큐는 공백상태입니다.\n");
	return 0;
}