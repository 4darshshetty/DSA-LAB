#include<stdio.h> 
char str[100],pat[100],rep[100],res[100]; 
int i,j,c,m,k,flag=0; 
void read(void); 
void replace(void); 
int main() 
{ 
    int ch; 
    while (1) 
    { 
      printf("\n 1.Read Strings \n 2. Replace \n 3.Exit\n Enter Your Choice:"); 
        scanf("%d",&ch); 
        switch (ch) 
        { 
        case 1:read(); 
            break; 
        case 2:replace(); 
               break;      
        case 3:exit(0); 
             
        } 
    } 
     
    return 0; 
} 
void read() 
{ 
    char temp; 
    scanf("%c",&temp);  
    // read all the input strings (Main string, pattern, replacement string) 
    printf("\n Enter main string:\n"); 
    gets(str);     
    printf("\n Enter pattern string:\n"); 
    gets(pat); 
    printf("\n Enter replacement string\n"); 
    gets(rep); 
} 
void replace() 
{ 
    i=m=c=j=0; 
    while(str[c]!='\0')  // Check each character to find pattern.. 
    { 
        if(str[m]==pat[i]) 
        { 
            i++;    // Increment i and m till complete match found 
            m++; 
            if(pat[i]=='\0')    // If match found replace with given string 
            { 
                for(k=0;rep[k]!='\0';k++,j++) // replacing pattern with given string 
                    res[j]=rep[k]; 
                i=0;     //  i value make 0 to find same pattern again                    
                c=m;     //  initialize c with m to start from m location  
                flag=1;  // flag set 1 to confirm atleast one pattern found  
            } 
        } 
        else     // if no match found all the chars should be copied to res string 
        { 
            res[j]=str[c];// copy each character which is not matching into resultant  
            j++;   //increment c and j to copy all the remaining chars  
            c++; 
            m=c;   // copy c to m to check pattern matching  
            i=0;   // i value make 0 to find same pattern again  
        } 
    } 
    if(flag==0) 
        printf("pattern doesen't found!!!\n"); 
    else 
    { 
        res[j]='\0'; 
        printf("\n the RESULTANT string is: %s \n",res); 
    } 
} 