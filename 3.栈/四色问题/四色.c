#include<stdio.h>
#define num 7
int show_result(int stack[]){
    //char *colorarr[4] = { "1#","2#","3#","4#" };    //颜色数组
    char *colorarr[4] = { "红色","绿色","蓝色","黄色" };//颜色数组

    for (int k = 0; k < num; k++){
        printf("第%d块地的颜色是%s\n", k+1, colorarr[stack[k] - 1]);
    }
}

void MapColor(int arr[num][num], int stack[]){
    int color = 1, area = 1;    //第二个区域从颜色1#开始试探
 
    stack[0] = color;   //第一块区域染色,颜色1入栈
    while(area < num){  //直到遍历完所有区域
        while(color <= 4){  //试探四个颜色
            int dyeing = 0;     //已经染色的区域
            while(dyeing < area && stack[dyeing] * arr[area][dyeing] != color){     //第一遍循环过来，是stack [0] * arr[1][0] == 1 == color,跳出循环
                dyeing++;}      //进行到第二遍循环时 stack [0] * arr[1][1] == 0，执行dyeing++，紧接着执行底下的else
            if(dyeing < area){color++;}     //area与dyeing重色，用另一种颜色试探
            else{
                stack[area++] = color;    //保存area区域的颜色,并且开始试探下一个区域
                if(area>num){break;}
                color = 1;      //重置颜色
            }
        }   //while(color <= 4)
        //如果四种颜色都重色，则要回溯栈
        if(color > 4){
            //area -= 1;      
            color = stack[--area] + 1;  ////上一个区域用下一个颜色重新试探
        }
    }  //while(area < num)
    show_result(stack);
}

int main()
{
    int arr[7][7] = {
        {0,1,1,1,1,1,0},
        {1,0,0,0,0,1,0},
        {1,0,0,1,1,0,0},
        {1,0,1,0,1,1,0},
        {1,0,1,1,0,1,0},
        {1,1,0,1,1,0,0},
        {0,0,0,0,0,0,0}
    }; 
    int stack[num];//定义栈
    MapColor(arr, stack);
    return 0;
}