#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 40

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
        printf("%d ",list->data[i]);
    }
    printf("\n");
}

//合并顺序表
int merge(SqList * list1, SqList * list2 , SqList * All_list){
    if(list1->length + list2->length > MAX_SIZE){
        printf("list1和list2相加长度超过顺序表长度\n");
        return 0;
    }
    int index1=0,index2=0,index_all=0;  // 各个顺序表的计数器
    while(index1 < list1->length && index2 < list2->length){
        if(list1->data[index1] <= list2->data[index2]){     //小的先放进来
            All_list->data[index_all++] = list1->data[index1++];    //放入后，计数器自+1
        }else{
            All_list->data[index_all++] = list2->data[index2++];
        }
    }
    while(index1 < list1->length){  //遍历完第一个顺序表
        All_list->data[index_all++] = list1->data[index1++];
    }
    while(index2 < list2->length){
        All_list->data[index_all++] = list2->data[index2++];
    }
    All_list->length = index_all;
    return 1;
}


int main(){
    int arr1[] = {1,2,2,3,4,5,5,6,6,7};
    int arr2[] = {2,3,3,5,6,7,8,8,9};
    SqList * list1 = InitList();
    SqList * list2 = InitList();
    SqList * all_list = InitList();
    for(int i= 0;i<sizeof(arr1)/sizeof(arr1[0]); i++){
        list1->data[i] = arr1[i];
        list1->length++;
    }
    for(int i= 0; i < sizeof(arr2)/sizeof(arr2[0]); i++){
        list2->data[i] = arr2[i];
        list2->length++;
    }

    print_list(list1);
    print_list(list2);
    merge(list1,list2,all_list);
    print_list(all_list);
}