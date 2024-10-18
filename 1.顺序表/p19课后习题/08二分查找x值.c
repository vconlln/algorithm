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
        printf("%d,",list->data[i]);
    }
    printf("\n");
}

//删除表中相同的元素，只留下一个
int del_same(SqList* list){
    if (list->length == 0){
    return 0;}
    int i,j;  //i是记录不同元素的个数，j是计数器用于遍历顺序表
    for(i = 0, j = 1; j < list->length; j++){  //遍历顺序表
        if(list->data[i] != list->data[j]){   //找到下一个与上一个值不同的元素，把i+1后，将那个不同的元素覆盖前面的元素
        list->data[++i] = list->data[j];  //把元素前移
        }
    }
    list->length = i+1;
    print_list(list);
    return 1;
}
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
    print_list(All_list);
    return 1;
}

/*
x = 9
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
|           |                    |
low        mid                  high
              |          |        |
             low        mid       high
             |   |    | 
             low mid high        
*/
// 二分查找
void Search(SqList *list, ElementType x){
    //二分查找
    int low = 0 ,high = list->length - 1, mid;  // low
    while(low <= high){
        mid = (low + high) / 2;
        if(list->data[mid] == x) {break;}
        else if(list->data[mid] < x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    //找到后交换后继
    if(list->data[mid] == x && mid != list->length - 1){    //若最后一个元素是x,则不能交换后继
        ElementType temp = list->data[mid]; 
        list->data[mid] = list->data[mid + 1];
        list->data[mid + 1] = temp;
        printf("找到元素 %d ,它在第 %d 个位置\n",x,mid);
    }
    //未找到，直接插入
    if(low > high){ //没找到，并且此时的位置正好是data[i-1] < x && x < data[i] 只需将后面的元素后移一位，插入x即可
    printf("未找到元素 %d\n",x);
    for(int i = list->length - 1; i >= high; i--){
        list->data[i + 1] = list->data[i];
    }
    list->data[high + 1] = x;
    printf("元素 %d 已插入第 %d 个位置\n",x,high + 1);
    list->length ++;
    }
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
    del_same(all_list);

    Search(all_list,10);
    print_list(all_list);
}