#define _CRT_SECURE_NO_WARNINGS //scanf ���� �ذ��
#include<stdio.h>
#include<stdlib.h>

#define MAX_STACK_SIZE 100					//�迭�� ũ��
typedef int element;						//int -> element
typedef struct {							//����ü ����
	element data[MAX_STACK_SIZE];
	int top;							
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s)
{
	s->top = -1;
}
// ���� ���� ���� �Լ�
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

// �����Լ�
void push(StackType* s, element item)
{
	if (is_full(s)) {
		printf("���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// �����Լ�
element pop(StackType* s)
{
	if (is_empty(s)) {
		printf("���� ���� ����\n");
		return -1;
		//exit(1);
	}
	else return s->data[(s->top)--];
}

int main(void)
{
	StackType s;
	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));

	printf("%d\n", pop(&s));						//���� ���� �߻��� ���
	
	init_stack(&s);

	for (int i = 1; i < MAX_STACK_SIZE + 1; i++) {	//��ȭ ���·� �����	
		push(&s, i);
		if (i % 10 == 0) {
			printf("%d\n", i);
		}
	}

	printf("�߰��Ϸ�\n");							//��ȭ ���� �߻��� ���
	push(&s, 5);


}

/*
* ����ü �迭�� ����Ͽ� stack�� �����Ͽ���.
*/