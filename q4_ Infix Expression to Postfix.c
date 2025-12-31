#include<stdio.h> 
#include<ctype.h> 
char stack[20]; 
int top=-1; 
void push(char ele); 
char pop(); 
int priority(char sym); 
int main() 
{ 
    int i=0; 
    char exp[20]; 
    char sym,ele; 
    printf("Enter valid Infix expression:"); 
    scanf("%s",exp); 
    printf("\n Postfix:"); 
    for(i=0;exp[i]!='\0';i++)   // read each char from infix  
    { 
        sym=exp[i];   
        if(isalnum(sym))    // check is alpha numeric   
            printf("%c ",sym);   // print output if it is operand alphabet 
        else if(sym=='(')     
            push(sym);      // push symbol if it lparenthsis 
        else if(sym==')')   // if rparenthesis encountered  
        { 
          while((ele=pop())!='(') // Pop all the elements from stack till    
                printf("%c ",ele);   // left parenthesis encountered & print on output 
        } 
        else  
        { 
// check priority of incoming symbol 
 
 
            while(priority(stack[top])>=priority(sym))  
                printf("%c ",pop()); // and stack[top] symbol print on output 
            push(sym);     // Push the symbol 
        } 
    } 
        while(top!=-1)   // Pop remaining all the ele from stack and print  
        {                 // on output.. 
            printf("%c ",pop());  
        } 
     
    return 0; 
} 
void push(char ele) 
{ 
    stack[++top]=ele; 
} 
char pop() 
{ 
    return stack[top--]; 
} 
int priority(char sym)  // initialize priorities 
{ 
    if(sym=='(') 
        return 0; 
    if(sym=='+'|| sym=='-') 
        return 1; 
    if(sym=='*'|| sym=='/'|| sym=='%') 
        return 2; 
    if(sym=='^') 
        return 3; 
    return 0; 
} 
 