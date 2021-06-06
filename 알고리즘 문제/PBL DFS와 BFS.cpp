#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 1000

typedef struct graph {//그래프 구조체 선언
	int n;
	int mat[MAX_VERTEX][MAX_VERTEX];
}graph;

typedef struct queue {//원형큐 구조체 선언
	int front,rear;
	int data[MAX_VERTEX];
}queue;

void init_queue(queue* q){//원형큐 초기화 함수
	q->front = q->rear = 0;
}

int is_empty(queue* q){//원형큐의 공백상태를 확인하는 함수
	return (q->front == q->rear);
}

int is_full(queue* q){//원형큐의 포화상태를 확인하는 함수
	return ((q->rear + 1) % MAX_VERTEX == q->front);
}

void enqueue(queue* q, int vertex){//원형큐에 값을 추가하는 함수
	if (is_full(q)) {//포화상태일 경우 값을 추가하지 않음
		printf("큐가 포화상태입니다");
		return;
	}
	q->rear = (q->rear + 1) % MAX_VERTEX;//rear값을 증가시키고 vertex값을 삽입
	q->data[q->rear] = vertex;
}

int dequeue(queue* q) {//원형큐의 값을 삭제하고 돌려주는 함수
	if (is_empty(q)){//공백상태일 경우 값을 삭제하지 않음
		printf("큐가 공백상태입니다");
		return 0;
	}
	q->front = (q->front + 1) % MAX_VERTEX;//front값을 증가시키고 값을 돌려줌
	return q->data[q->front];
}

void init_graph(graph* g) {//그래프 초기화 함수
	g->n = 0;//정점의 개수를 0으로 초기화
	for (int i = 0; i < MAX_VERTEX; i++) {//간선의 값을 0으로 초기화
		for (int j = 0; j < MAX_VERTEX; j++) {
			g->mat[i][j] = 0;
		}
	}
}

void insert_vertex(graph* g, int v){//정점추가 함수
	if (((g->n) + 1) > MAX_VERTEX) {//최대값보다 클경우 정점을 추가하지 않음
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;//정점의 개수에 1을 더함
}

void insert_edge(graph* g, int start, int end){//양방향 간선 추가 함수
	if (start > g->n || end > g->n) {//정점의 개수보다 큰 정점의 값은 존재하지 않으므로 간선을 추가하지 않음
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g->mat[start][end] = 1;//양방향 간선을 추가
	g->mat[end][start] = 1;
}

void dfs_mat(graph* g, int v, int* visited){//DFS탐색 함수
	int w;
	visited[v] = 1; //정점 v에 방문한 것을 표시
	printf("%d ", v); //방문한 정점 출력
	for (w = 1; w <= g->n; w++) //인접한 정점 탐색
		if (g->mat[v][w] && visited[w] != 1)//방문하지 않았고 간선이 존재하는 정점이면 DFS함수 호출
			dfs_mat(g, w, visited);
}

void bfs_mat(graph* g, int v, int* visited){//BFS탐색 함수
	int w;
	queue* q = (queue*)malloc(sizeof(queue));//방문한 정점을 저장할 큐 선언
	init_queue(q); //큐 초기화
	visited[v] = 1; //정점 v에 방문한 것을 표시
	printf("%d ", v);//방문한 정점 출력
	enqueue(q, v); // 시작 정점을 큐에 저장
	while (!is_empty(q)) {
		v = dequeue(q); // 큐에 저장된 정점을 v에 삽입하고 삭제
		for (w = 1; w <= g->n; w++) // 인접한 정점 탐색
			if (g->mat[v][w] && visited[w] != 1) {//방문하지 않았고 간선이 존재하는 정점이면 방문 표시하고 큐에 저장
				visited[w] = 1;
				printf("%d ", w);//방문한 정점 출력
				enqueue(q, w);
			}
	}
	free(q);
}

int main(){
	graph* g = (graph*)malloc(sizeof(graph));//그래프 선언
	init_graph(g);//그래프 초기화
	int n = 0, m = 0, v = 0, start = 0, end = 0;
	scanf_s("%d %d %d", &n, &m, &v);//정점의 개수, 간선의 개수, 시작할 정점을 입력받음
	int* visited = (int*)malloc(sizeof(int)*(n+1));//방문한 정점을 저장할 배열을 동적할당
	for (int i = 1; i <= n; i++) {//정점의 개수만큼 정점을 추가하고 visited배열 초기화
		insert_vertex(g,i);
		visited[i] = 0;
	}
	for (int i = 0; i < m; i++) {//간선의 개수만큼 간선을 입력받고 그래프에 간선 추가
		scanf_s("%d %d", &start, &end);
		insert_edge(g, start, end);
	}
	dfs_mat(g, v, visited);//DFS탐색
	printf("\n");
	for (int i = 0; i < n; i++) {//visited배열 초기화
		visited[i+1] = 0;
	}
	bfs_mat(g, v, visited);//BFS탐색
	free(visited);
	free(g);
}

