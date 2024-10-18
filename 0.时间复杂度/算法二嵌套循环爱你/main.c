#include <stdio.h>
//算法2——嵌套循环爱你 
void loveYou(int n){ //n为问题规模
    int i = 0;  //爱你的程度
    while(i <= (n-1)){                        // n次
        i++;    //每次+1
        printf("I Love You %d\n", i);
        for (int j=1; j<=n; j++){
            printf("I am Iron Man\n");  // n次
        }
    }
    printf("I Love You More Than %d\n", n);     //执行n^2次后执行这个
}

int main(){
    loveYou(5);
	return 0; 
}