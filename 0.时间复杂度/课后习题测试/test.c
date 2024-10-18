#include<stdio.h>
int main(){
    int m = 0,i,j;
    int n = 10;
    for(i=1;i<=n;i++){
        for(j=1;j<=2*i;j++){
            m++;
            printf("%d ",m);
        }
        printf("finished %d\n",i);
    }
return 0;
}