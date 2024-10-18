#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	int value;
	struct Node * next;
}Link;

Link * create_link(){
	Link * link = (Link *)malloc(sizeof(Link));
	link->value = -1;
	link->next = NULL;
	return link;
}

void show_print(Link * link){
	Node * n = link;
	while(n!=NULL){
		printf("%d->",n->value);
		n = n->next;
	}printf("%s",NULL);

}

void insert(int v,Link * link){
	if(link->value == -1){
		link->value = v;
		return;
	}
	Node * n = (Node *)malloc(sizeof(Node));
	n->value = v;
	n->next = NULL;

	Node * last = link;
	while(last->next!=NULL){
		last = last->next;
	}
	last->next = n;
}




int main(){
	Link *link = create_link();
	insert(11,link);
	insert(22,link);
	insert(33,link);
	show_print(link);
	return 0;
}
