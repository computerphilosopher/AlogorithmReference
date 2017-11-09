#define MAX_QUEUE_SIZE 100
#define MAX_VERTICES 50

typedef int element;
typedef struct QueueType{
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

typedef struct GraphNode{
	int vertex;
	struct GraphNode *link;
}GraphNode;

typedef struct {
	int n;
	GraphNode **adj_list;
}GraphType;



void error(char *message);
void init(QueueType *q);
int is_empty(QueueType *q);
int is_full(QueueType *q);
void enqueue(QueueType *q, element item);
element dequeue(QueueType *q);
