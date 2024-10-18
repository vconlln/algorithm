#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 40
#define max(a,b) ((a) >= (b) ? (a) : (b))
//条件运算符（也称为三元运算符） condition ? expr1 : expr2。如果 condition 为真（非零），则表达式的结果是 expr1；如果 condition 为假（零），则结果是 expr2。
typedef int ElementType;

typedef struct SqList{
    ElementType data[MAX_SIZE];
    int length;
}SqList;

SqList * InitList(){
    SqList * list = (SqList*)malloc(sizeof(SqList));
    list->length = 0;
}

void print_list(SqList * list){
    for(int i = 0;i < list->length; i++){
        printf("%d,",list->data[i]);
    }
    printf("\n");
}


void same_value(SqList * A, SqList * B, SqList * C){
    int i = 0, j = 0, k = 0;    //三个顺序表的计数器
    while(i < A->length && j < B->length && k < C->length){
        if (A->data[i] == B->data[j] && B->data[j] == C->data[k]){
            printf("相同元素为 %d \n",A->data[i]);
            i++;j++;k++;
        }else{
            int maxnum = max(A->data[i], max(B->data[j], C->data[k]) );
            if(A->data[i] < maxnum){
                i++;}
            else if(B->data[j] < maxnum){
                j++;}
            else if(C->data[k] < maxnum){
                k++;}
        }
    }
}

int main(){
    int arr1[] = {1,2,3,4,5,6,7,8};
    int arr2[] = {2,3,5,6,7,8,9};
    int arr3[] = {4,6,7,8,9,10,11};

    SqList * list1 = InitList();
    SqList * list2 = InitList();
    SqList * list3 = InitList();
    for(int i= 0;i<sizeof(arr1)/sizeof(arr1[0]); i++){
        list1->data[i] = arr1[i];
        list1->length++;
    }
    for(int i= 0; i < sizeof(arr2)/sizeof(arr2[0]); i++){
        list2->data[i] = arr2[i];
        list2->length++;
    }

    for(int i= 0; i < sizeof(arr3)/sizeof(arr3[0]); i++){
        list3->data[i] = arr3[i];
        list3->length++;
    }
    print_list(list1);
    print_list(list2);
    print_list(list3);
    same_value(list1,list2,list3);
}