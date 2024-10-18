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

//整体逆置顺序表
void reverse(SqList * list){
    ElementType temp;   // 临时变量，用于存储顺序表里面的值
    for(int i = 0; i < (list->length/2) ;i++){  //只需遍历一半元素即可
        temp = list->data[i];
        list->data[i] = list->data[list->length - 1 - i];
        list->data[list->length - 1 - i] = temp;
        }
    printf("逆置后的顺序表为:\n");
    print_list(list);
}

int Reverse(int start, int end, SqList *list)
{
    if(end >= list->length || start >= end)   //不能超过顺序表长度
        return 0;
    ElementType temp=0;     //交换对称位置的数
    int mid=(start+end)/2;  //只需翻转一半的数
    for(int i=0; i <= mid - start; i++)//需要小于等于 ？ 如果<，中间两个换不过来 
    {
        temp=list->data[start+i];
        list->data[start+i]=list->data[end-i];
        list->data[end-i]=temp;         
    } 
    print_list(list);
    return 1;
}



int main(){
    int arr1[] = {1,2,2,3,4,5,5,6,6,7};
    int arr2[] = {2,3,3,5,6,7,8,8,9,10,11,12,13};
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
    printf("要翻转的顺序表为：");
    del_same(all_list);

    int n = 5;
    printf("先整体翻转：");
    Reverse(0,all_list->length-1, all_list);    //先整体翻转 
    printf("翻转前%d部分：",n);  //翻转前m部分  注意：m<=n
    Reverse(0,n-1,all_list);    //再翻转前m部分 
    printf("翻转后%d部分：",n);  //翻转后n部分  注意：m<=n  
    Reverse(n,all_list->length-1,all_list);     //再翻转后n部分 
}