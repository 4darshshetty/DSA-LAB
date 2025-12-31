#include<stdio.h> 
#define MAX 6 
int stack[MAX],ele,num,top=-1; 
void push(int); 
int pop(); 
void checkpalindrome(int); 
void stakstatus(); 
void display(); 
int main() 
{ 
    int ch; 
    while(1) 
    { 
        printf("\n1.Push \n2.Pop \n3.Check Palindrome \n4.Stack Status 
\n5.Display\n 6.Exit \n Enter Your choice: "); 
        scanf("%d",&ch); 
        switch(ch) 
        { 
            case 1:printf("\n Enter element to Push: "); 
                   scanf("%d",&ele); 
                   push(ele); 
                   break; 
            case 2:ele=pop(); 
                   printf("\n Popped element from stack: %d",ele); 
                   break; 
          case 3:printf("\nEnter a number to check Palindrome or Not:"); 
                   scanf("%d",&num); 
                   checkpalindrome(num); 
                   break; 
            case 4:stakstatus(); 
                   break; 
            case 5:display(); 
                   break; 
            case 6:exit(0); 
        } 
    } 
} 
void push(int ele) 
{ 
    if(top==MAX-1)      //  if top==MAX-1 stack is full ... 
    { 
        printf("\n Stack is Overflow...\n"); 
    } 
    else 
    { 
        stack[++top]=ele;  // Increment top and push element to stack  
    } 
} 
int pop() 
{ 
   if(top==-1)     // if top=-1 stack is empty you cannot pop element 
    { 
       printf("\n Stack is underflow! \n");  
    } 
    else 
    { 
      return stack[top--];  // pop last element inserted from stack 
    }  
} 
 
void checkpalindrome(int num) 
{ 
    int temp,rem=0,poppedele; 
    int flag=0;     // flag set to 0 given number is a palindrome.. 
    top=-1;  // Reinitialize top=-1 make stack empty      
    temp=num; 
    while(temp!=0) 
    { 
        rem=temp%10;  // calculate reminder and push into stack 
        push(rem);     // push all remainders to stack  
        temp=temp/10;  
    }  
    while(num!=0) 
    { 
        rem=num%10;  
        poppedele =pop();    // pop top element and check               
        if(rem!= poppedele)  // Popped element compare with remainder  
        { 
            flag=1;   // if flag becomes 1 num is not palindrome 
        } 
        num=num/10; 
    }  
    if(flag==0)     // if flag=0 it is palindrome... 
        printf("Given Number is palindrome\n"); 
    else 
        printf("Given Number is not a palindrome!\n"); 
} 
void stakstatus() 
{ 
    if(top==MAX-1)  //  
    { 
       printf("Stack is Full!");        
    } 
    display(); 
} 
 
void display() 
{ 
    int i;  
    if(top==-1) 
    { 
      printf("Stack is empty!\n"); 
    }        
    else 
    { 
        printf("Stack eles are \n"); 
        for(i=top;i>=0;i--) 
        { 
            printf("%d \n",stack[i]); 
        } 
    } 
} 
 