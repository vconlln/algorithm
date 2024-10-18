
#include<stdio.h>
#include<stdlib.h>
typedef int DataType;

typedef struct Node{
  DataType data;
  struct Node * next;
}Node;

//带头结点
Node * Initlink(){
  Node * link = (Node *)malloc(sizeof(Node)); //创建头结点
  link->data = -1;
  link->next = NULL;  //头结点指向NULL
  return link;
}

void show_print(Node * link){
    Node * n = link;
    while(n!=NULL){
        printf("%d->",n->data);
        n = n->next;
    }printf("%s \n",NULL);

}

//查找第i个节点，并返回该结点的存储位置
Node * Get(Node * list, int i){
    int j = 0;
    Node * p = list;
    while(p->next != NULL && j<i ){
        p = p->next;    //扫描下一个节点
        j++;
    }
    if(i==j){
        return p;
    }
    else{
        return NULL;
    }
}

//p后插
void InsertAfter(Node *p, DataType x){
    Node *NewNode = (Node*)malloc(sizeof(Node));
    NewNode->data = x;

    NewNode->next = p->next;
    p->next = NewNode;
}

//在第i个结点前（也就是第i个结点）插入x值
void Insert(Node *list, DataType x, int i){
    Node *p = Get(list,i-1);
    if(p==NULL){
        printf("没有该位置\n");
    }else{
        InsertAfter(p,x);
    }
}

/*
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    if(l1->val < l2->val){
        l1->next = mergeTwoLists(l1->next,l2);
        return l1;
    }else{
        l2->next = mergeTwoLists(l1,l2->next);
        return l2;
    }
}
*/

Node * merge(Node *l1, Node *l2){
    if(l1 == NULL){return l2;}
    if(l2 == NULL){return l1;}

    // 如果当前 l1 和 l2 节点值相同，选择一个，并递归处理
    if (l1->data == l2->data) {
        l1->next = merge(l1->next, l2->next);  // 跳过重复的节点
        return l1;
    }
    // 如果 l1 小于 l2，递归处理 l1 的后续部分
    else if (l1->data < l2->data) {
        l1->next = merge(l1->next, l2);
        return l1;
    }
    // 如果 l2 小于 l1，递归处理 l2 的后续部分
    else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

Node *merge2(Node *l1, Node *l2){
    Node *p_l1 = l1->next;
    //printf("%d\n",p_l1->data);
    Node *q_l2 = l2->next;
    Node *before = l1;  //before为p_l1的前驱
    Node *u;    //用于临时存储q_l2的指针
    while(p_l1 != NULL && q_l2 != NULL){
        if(p_l1->data > q_l2->data){
            u = q_l2->next;
            before->next = q_l2;    //前驱指向第二个列表
            before = q_l2 ;  //前驱指针指向新添加的结点 q_12
            q_l2->next = p_l1;  //新加入的结点指向p_11下一个结点
            q_l2 = u;
        }else{
            before = p_l1;
            p_l1 = p_l1->next;
        }
    }
    if(q_l2!=NULL){
        before->next = q_l2;
    }
    return l1;
}

int main(){
    Node *list1 = Initlink();
    Node *list2 = Initlink();
    Insert(list1,1,1);
    Insert(list1,4,2);
    Insert(list1,5,3);
    show_print(list1);

    Insert(list2,2,1);
    Insert(list2,3,2);
    Insert(list2,6,3);
    show_print(list2);

    Node *mergeList = merge2(list1,list2);
    show_print(mergeList);
    return 0;
}