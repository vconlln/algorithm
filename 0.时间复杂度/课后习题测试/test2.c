#include<stdio.h>
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main(){
    int n = 10;
    int A[10] = {10,9,8,7,6,5,4,3,2,1};
    int i,j;
    for(i = n-1; i>1; i--){
        printf("执行第%d次\n",10-i);
        for(j = 0;j<i;j++){
            if(A[j]>A[j+1]){
                // 交换索引为index1和index2的元素
                swap(&A[j], &A[j+1]);
            }
            // 使用循环遍历数组并打印每个元素
            for (int i = 0; i < n; i++) {
                printf("%d ", A[i]);
            }
            
            printf("\n"); // 打印换行符，美化输出
        }
    }

    return 0;
}