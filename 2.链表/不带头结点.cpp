#include<stdio.h>
#include<stdlib.h>

typedef int Datatype;

typedef struct node{
    Datatype data;
    struct node * next;
}LinkList;

void show_print(LinkList * link){
    LinkList * n = link;
    while(n!=NULL){
        printf("%c->",n->data);
        n = n->next;
    }printf("%s \n",NULL);

}

LinkList * CreatListF(){
    int ch;
    LinkList *head, *s;
    head = NULL;
    while((ch=getchar())!='#'){
        s = (LinkList*)malloc(sizeof(LinkList));
        s->data = ch;
        s->next = head;
        head = s;
    }
    return head;
}

int main(){
    LinkList * link = CreatListF();
    show_print(link);
}