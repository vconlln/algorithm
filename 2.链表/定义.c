#include<stdio.h>
#include<stdlib.h>
typedef int DataType;

typedef struct Node{
  DataType value;
  struct Node * next;
}Node;

//带头结点
Node * Initlink(){
  Node * link = (Node *)malloc(sizeof(Node)); //创建头结点
  link->value = -1;
  link->next = NULL;  //头结点指向NULL
  return link;
}

//不带头结点
Node * initlink(){
  Node * list; //声明类型
  list = NULL;  //不带头结点
  return list;
}

//求表长
int get_length(Node * list){
  int len = 0;
  Node * p = list;
  while(p->next != NULL){
    p = p->next;
    len++;
  }
  printf("表长为 %d\n",len);
  return len;
}

void show_print(Node * link){
    Node * n = link;
    while(n!=NULL){
        printf("%d->",n->value);
        n = n->next;
    }printf("%s \n",NULL);

}

//带头节点，头插法，是在头结点之后插入
void Head_Insert( DataType num,Node * list){
    int x =0;
    while(x != num){
        Node * NewNode = (Node *)malloc(sizeof(Node));
        NewNode->value = x;

        //关键代码
        NewNode->next = list->next;
        list->next = NewNode;

        x++;
        //show_print(list);
  }
}


//不带头节点，头插法，没有头结点，在第一个节点之前插入，并且需要给第一个节点赋值，还需要return list
Node * NO_Head_Insert1(DataType num, Node * list){
    int x =0;
    list = (Node *)malloc(sizeof(Node));
    list->value = x++;
    while(x != num){
        Node * NewNode = (Node *)malloc(sizeof(Node));
        NewNode->value = x;

        //关键代码
        NewNode->next = list;
        list = NewNode;

        x++;
        //show_print(list);
  }
  //show_print(list);
  return list;
}

/*
这样覆盖了list指针的地址，出函数的时候，list会回归原始的值
NewNode->next = list;
list = NewNode;
所以必须retun list,再在main函数里面接受这个list
*/

/*
如果不想返回，则要用双指针，需要有一个指向nolink变量的地址的指针
void NO_Head_Insert(DataType num, Node ** list){
    int x =0;
    while(x != num){
        Node * NewNode = (Node *)malloc(sizeof(Node));
        NewNode->value = x;
        //关键代码
        NewNode->next = *list;
        *list = NewNode;
        x++;
  }
}
int main(){
    ...
    NO_Head_Insert(5,&nolink);
}
*/

void NO_Head_Insert(DataType num, Node ** list){
    int x =0;
    while(x != num){
        Node * NewNode = (Node *)malloc(sizeof(Node));
        NewNode->value = x;
        //关键代码
        NewNode->next = *list;
        *list = NewNode;
        x++;
  }
}

//尾插法，带头节点
void Tail_Insert(DataType num, Node * list){
    int x = 1;
    Node * last = list; //尾指针
    while(x != num){
        Node * NewNode = (Node *)malloc(sizeof(Node));
        NewNode->value = x++;
        last->next = NewNode;
        last = NewNode;
    }
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
        printf("找到节点 %d 的地址是 %d ,对应值为 %d\n",i,p,p->value);
        return p;
    }
    else{
        printf("没有找到节点 %d\n",i);
        return NULL;
    }
}

//在带有头结点的单链表中查找其结点值为key的结点
//若找到，返回节点的位置p;否则返回NULL
Node * Locate(Node * list, DataType key){
    Node *p = list->next;
    while(p != NULL && p->value != key){
        p = p->next;
    }
    if(p == NULL){
        printf("没有找到值 %d\n",key);
        
        return NULL;
    }
    else{
        printf("找到值 %d 的地址是 %d \n",key,p);
        return NULL;
    }
}

//p后插
void InsertAfter(Node *p, DataType x){
    Node *NewNode = (Node*)malloc(sizeof(Node));
    NewNode->value = x;

    NewNode->next = p->next;
    p->next = NewNode;
}

//在last前插
void InsertBefore(Node *list, Node *last, DataType x){
    Node *NewNode = (Node*)malloc(sizeof(Node));
    NewNode->value = x;
    Node *befor = list;     //前一个指针
    while(befor->next != last){     //找到为last的指针
        befor = befor->next;
    }
    NewNode->next = last;
    befor->next = NewNode;
}

//在第i个结点后插入x值
void Insert1(Node *list, DataType x, int i){
    Node *p = Get(list,i);
    if(p==NULL){
        printf("没有该位置\n");
    }else{
        InsertAfter(p,x);
    }
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

//找到被删除结点的前驱，再进行删除
void delete(Node *list, int i){
    Node *p = Get(list,i-1);  //被删除结点的前驱结点的地址
    if(p!=NULL&& p->next!=NULL){
        Node *q = p->next;  //q是被删除结点，p的next指向被删除结点
        DataType e = q->value;
        p->next = q->next;
        free(q);
    }
}

int main(){
    Node * head_link = Initlink();    //带头结点
    Head_Insert(10,head_link);
    show_print(head_link);
    
    Node * no_head_link = initlink(); //不带头节点  
    NO_Head_Insert(10,&no_head_link);
    show_print(no_head_link);

    Node * tail_link = Initlink();  //带头结点
    Tail_Insert(10,tail_link);
    show_print(tail_link);

    get_length(tail_link);
    Get(tail_link,5);
    Locate(tail_link,5);

    Node *p = tail_link;
    while(p->next!=NULL){p=p->next;}
    InsertAfter(p,10);      //尾部插入
    show_print(tail_link);

    Node *last = Get(tail_link,3);  //找到第3个节点的指针
    InsertBefore(tail_link,last,123);       //第三个节点前插入123
    show_print(tail_link);

    Insert(tail_link,100,2);    //第二个节点插入100
    show_print(tail_link);

    delete(tail_link,2);
    show_print(tail_link);
    
    return 0;
}
