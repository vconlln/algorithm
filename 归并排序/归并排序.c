#include<stdio.h>
#include <stdlib.h> // 为了使用malloc和free

void print_array(int *array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int* merge(int a[], int b[], int len_a, int len_b){

    printf("a的长度: %d\nb的长度: %d\n",len_a,len_b);
    int* merged = (int*)malloc(( len_a + len_b )*sizeof(int));  //malloc申请内存地址，新建数组
    if (merged == NULL) {
        fprintf(stderr, "Memory allocation failed\n");  //错误处理
        exit(1);
    }
    int ptr_a = 0, ptr_b = 0, ptr_mre = 0;  //定义指针
    
    while(ptr_a < len_a || ptr_b < len_b) {
        if(ptr_a < len_a && (ptr_b >= len_b || a[ptr_a] < b[ptr_b])) {           //比较a和b中的元素大小，小的先放，大的后放
            merged[ptr_mre++] = a[ptr_a++]; 
            print_array(merged,ptr_mre);
            //printf("ptr_a: %d\n",ptr_a);
        }  else if (ptr_b < len_b) {
            merged[ptr_mre++] = b[ptr_b++]; 
            print_array(merged,ptr_mre);
            //printf("ptr_b: %d\n",ptr_b);
        }

    }
    /*
    while (ptr_mre < len_a + len_b) 
    {
    if (ptr_a == len_a) merged[ptr_mre++] = b[ptr_b++];
    if (ptr_b == len_b) merged[ptr_mre++] = a[ptr_a++];
    }*/
    
    return merged;
}

int main(){
    int a[] = {1, 5, 9, 10, 11, 99};
    int b[] = {2, 3, 7, 20};
    int len_a = sizeof(a)/sizeof(a[0]);
    int len_b = sizeof(b)/sizeof(b[0]);

    int* merged = merge(a, b, len_a, len_b);
    
    printf("Merged array: ");
    for(int i = 0; i < sizeof(a)/sizeof(a[0]) + sizeof(b)/sizeof(b[0]); i++) {
        printf("%d ", merged[i]);
    }
    
    free(merged);
    return 0;
}