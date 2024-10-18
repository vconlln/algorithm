#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20 //定义数组的最大长度
typedef int ElementType; //定义结构类型

//  定义栈结构体
typedef struct Stack{
  ElementType data[MAXSIZE];  //定义ElementType类型的数组
  int top;  //定义栈顶索引
}Stack;

//初始化栈
Stack * InitStack(){
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->top = -1;
  return s;
}

//判断栈是否为满栈
int isFull(Stack *s){
  return s->top == MAXSIZE;
}

//判断栈是否为空栈
int isEmpty(Stack *s){
  return s->top == -1;
}

//入栈操作
int push(Stack *s, ElementType value){
  if(isFull(s)){ //判断栈是否为满栈
    printf("栈已满，不能再入栈");
    return -1;
  }
  s->top++; //栈顶指针+1
  s->data[s->top] = value;  //把值存入栈顶
  return 0;
}

//出栈操作
ElementType pop(Stack *s){
  if(isEmpty(s)){  //判断栈是否为空栈
    return -1;
  }
  ElementType value = s->data[s->top];  //栈顶元素赋值给value
  s->top--; //栈顶指针自减
  return value; //返回出栈元素
}

//定义运算符优先级
int evalSort(char string){
  if (string == '*' || string == '/'){    // '*'， '/'' 是最高运算符
    return 2;}
  else if(string == '+' || string == '-'){
    return 1;}
  else if(string == '('){
    return 0;}
  else{
    printf("\n输入运算符有误，程序异常退出\n");
    exit(1);
  }
}

ElementType top(Stack * s){
  return s->data[s->top]; // 取出栈顶元素
}

//中缀表达式转为逆波兰表达式
void toNBL(char * string){
  Stack * s = InitStack();  //存放运算符号的栈
  int i = 0;  //while循环的计数器
  while(string[i]!='\0'){   //直到字符串最后一个字符为'\0'
    if( string[i] >= '0' && string[i] <= '9' )
    {  //判断是否为数字
      printf("%c",string[i]); //打印数字
    }
    else
    {
      if(isEmpty(s) || string[i]== '('){  //空栈或者运算符最低的'{'直接入栈
        push(s,string[i]);}
      else if(string[i] == ')' ){ //如果遇到')'，处理右括号，要先把括号里的运算符全部输出，并出栈
        while( top(s) != '(' )  // 直到右括号遇到左括号，停止输出
        {
            char str = pop(s);  // 左括号里面的栈顶元素出栈
            printf("%c",str); // 输出
          }
            pop(s); }// 最后'('出栈，但是不输出
      else{
          while(evalSort(string[i]) <= evalSort(top(s))){ //如果此时的操作符比栈顶的操作符级别小或者相等
            char str = pop(s);    // 输出级别高的操作符
            printf("%c",str);
            if(isEmpty(s)){break;}  // 空栈则退出
          }
          push(s,string[i]);  // 放入级数低或者相等的操作符
        }
    }
    i++;  // 计数器加一
  }
    while(!isEmpty(s)){   // 将操作符栈里的元素全部输出
        printf("%c",pop(s));
    }
}

//逆波兰表达式的计算
void calculate(char * string){
  Stack * numstack = InitStack();
  //Stack * opestack = InitStack();
  int i = 0;  //while循环的计数器
  while(string[i]!='\0'){   //直到字符串最后一个字符为'\0'
      switch(string[i]){
        case '+':  push(numstack,pop(numstack) + pop(numstack)); break;
        case '-':  push(numstack,pop(numstack) - pop(numstack)); break;
        case '*':  push(numstack,pop(numstack) * pop(numstack)); break;
        case '/':  push(numstack,pop(numstack) / pop(numstack)); break;
        default:   push(numstack,string[i]- '0'); break;;
      }
    i++;
  }
  printf("\n逆波兰表达式的计算结果：%d\n", top(numstack)); 
}

int main(){
    char str[MAXSIZE] = "3*4*((5+2)*5+5*3)";
    printf("中缀为表达式：")
    //scanf("%s",str);
    printf("后缀为表达式：");
    toNBL(str);
    //char star1[] = ")";
    //printf("%d",evalSort(star1[0]));
    char strnbl[MAXSIZE] = "34*52+5*53*+*";
    calculate(strnbl);
}
