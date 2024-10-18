#include<stdio.h>
#include<stdlib.h>

typedef int Datatype;

typedef struct node{
    Datatype data;
    struct node *next;
} LinkList;

typedef struct {
    LinkList *front, *rear;  // 头指针和尾指针
} LinkQueue;

LinkQueue *SetNullQ() {
    LinkQueue *sq = (LinkQueue *)malloc(sizeof(LinkQueue)); // 申请指针
    sq->front = (LinkList *)malloc(sizeof(LinkList));   // 申请头节点
    sq->front->next = NULL;      //头结点指向NULL
    sq->rear = sq->front;   //尾指针也指向头结点
    return sq;
}

int EmptyQ(LinkQueue *sq) {
    return sq->front == sq->rear;
}

int En_Queue_Q(LinkQueue *sq, Datatype x) {
    sq->rear->next = (LinkList *)malloc(sizeof(LinkList));   // 生成新结点
    sq->rear = sq->rear->next;  // 尾结点指向新节点
    sq->rear->data = x; // 新结点赋值
    sq->rear->next = NULL;
    return 1;
}

int De_Queue_Q(LinkQueue *sq) {
    if (EmptyQ(sq)) {
        printf("队列为空，无法出队\n");
        return 0; // 出队失败
    }
    LinkList *temp = sq->front->next; // 要出队的节点
    Datatype e = temp->data; // 获取节点数据
    sq->front->next = temp->next; // 更新头节点的 next 指针
    if (sq->rear == temp) { // 如果出队后队列为空，更新 rear 指针
        sq->rear = sq->front;
    }
    printf("出队元素: %d\n", e);
    free(temp); // 释放出队的节点
    return 1; // 出队成功
}

void show_print(LinkQueue *sq) {
    if (EmptyQ(sq)) {
        printf("队列为空\n");
    } else {
        printf("队列中的元素: ");
        LinkList *temp = sq->front->next;  // 从第一个有效元素开始
        while (temp != NULL) {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    LinkQueue *sq = SetNullQ();

    En_Queue_Q(sq, 2);
    En_Queue_Q(sq, 3);
    En_Queue_Q(sq, 4);

    show_print(sq);

    De_Queue_Q(sq); 

    show_print(sq);

    De_Queue_Q(sq); 
    show_print(sq);

    De_Queue_Q(sq); 
    show_print(sq);

    // 尝试在队列为空时出队
    De_Queue_Q(sq); 

    // 释放队列内存
    free(sq->front);
    free(sq);

    return 0;
}
