#include <stdio.h>
#include <stdlib.h>

typedef struct node {//노드 구조체 선언
	int data;
	struct node* left, * right;
}node;

node* new_node(int data)//노드를 생성하는 함수
{
	node* temp = (node*)malloc(sizeof(node));//노드를 동적할당
	temp->data = data;//주어진 데이터값을 삽입
	temp->left = temp->right = NULL;//왼쪽,오른쪽 트리 초기화
	return temp;//생성한 노드를 돌려줌
}

node* insert_node(node* node, int key)//이진 탐색 트리에 값을 추가하는 함수
{
	if (node == NULL) return new_node(key);//주소 값이 NULL일 경우 새 노드를 생성함
	if (key < node->data)//입력받은 값이 부모 노드의 데이터보다 작을 경우 왼쪽트리에 값을 추가
		node->left = insert_node(node->left, key);
	else if (key > node->data)//입력받은 값이 부모 노드의 데이터보다 클 경우 오른쪽트리에 값을 추가
		node->right = insert_node(node->right, key);
	return node;//값을 삽입한 후 부모 노드를 돌려줌
}

void postorder(node* root){//트리를 후위순회 하는 함수
	if (root) {
		postorder(root->left);//왼쪽부터 후위순회
		postorder(root->right);//오른쪽을 후위순회
		printf("%d\n", root->data);//순회가 종료된 후 데이터를 출력
	}
}

int main(void)
{
	node* root = NULL;//트리의 루트를 NULL로 선언
	int num = 0;//트리의 노드 개수 선언
	int data = 0;//노드에 삽입할 데이터값 선언
	scanf_s("%d", &num);//노드 개수를 입력받음
	for (int i = 0; i < num; i++) {//노드 개수만큼 이진 탐색트리에 값을 추가
		scanf_s("%d", &data);
		root = insert_node(root, data);
	}
	printf("후위순회 결과\n");
	postorder(root);//이진탐색트리 후위순회
}