#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5


// ===== ����ť �ڵ� ���� ======
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct { // ť Ÿ��
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;
// ���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);	//���� �޼��� ���
	exit(1);
}
// ť �ʱ�ȭ �Լ�
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;	//front, rear �� 0���� �ʱ�ȭ�Ѵ�.
}
// ���� ���� ���� �Լ�
int is_empty(QueueType* q)
{
	return (q->front == q->rear);	//front�� rear�� ���ٸ� queue�� ��������̴�.
}
// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);	// ��ȭ �����ΰ�� front�� 0���� ������ rear�� queue �������� -1���� ������ ���� %�����ڸ� ���ؼ� ���ٸ� ��ȭ�����̴�.
}

// ����ť ��� �Լ�
void queue_print(QueueType* q)	//front���� 1�� ������Ű�鼭 �ε����� Ȱ���Ͽ� queue���� ���� ����Ѵ�.
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
// ���� �Լ�
void enqueue(QueueType* q, element item)	//rear���� �ø��� �װ��� �ε����� Ȱ���Ͽ� queue�� �� �߰�
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
// ���� �Լ�
element dequeue(QueueType* q) // front���� 1�÷��� �ε����� Ȱ���Ͽ� ���� ����Ѵ�.
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

int main(void) //full ���±��� ä��� empty ���±��� ������
{
	QueueType queue;
	int element;
	init_queue(&queue);
	printf("--������ �߰� �ܰ�--\n");
	while (!is_full(&queue))	//full ���°� �ƴ϶��
	{
		printf("������ �Է��Ͻÿ�: ");
		scanf("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
	}
	printf("ť�� ��ȭ�����Դϴ�.\n\n");
	printf("--������ ���� �ܰ�--\n");
	while (!is_empty(&queue))
	{
		element = dequeue(&queue);
		printf("������ ����: %d \n", element);
		queue_print(&queue);
	}
	printf("ť�� ��������Դϴ�.\n");
	return 0;
}