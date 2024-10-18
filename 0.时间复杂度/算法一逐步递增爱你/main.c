#include <stdio.h>
// 算法一 ———— 逐步递增型爱你
void loveYou(int n){    // n 为问题规模
    int i = 1;  //爱你的程度
    while (i<=n){
        i++;	// i每次+1
        printf("I Love You %d\n", i);
    }
    printf("I Love You More Than %d\n", n);
    
}

int main(){
    loveYou(3000);
	return 0; 
}

