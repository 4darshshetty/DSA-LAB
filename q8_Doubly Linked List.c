#include<stdio.h> 
#include<malloc.h> 
#include<stdlib.h> 
 
// C Structure for employee... 
struct Employee{ 
    struct node *llink;  // Left link of node 
    int ssn;             // Info.. of employee 
    char name[50]; 
    char dept[20]; 
    char designation[20]; 
    float sal; 
    char phno[10];   
    struct Employee *rlink;  // Right link of node 
}; 
typedef struct Employee *NODE;  
int count=0; // to count total number of employees 
NODE first=NULL; // Start with empty list.. 
NODE createNode();// Creating temp node with data 
void createDll(); // Creating emp DLL by inserting at end 
void insertFront(); // Inserting at front of the list 
void insertEnd(); // inserting at the end of the list 
void deleteFront(); // Deleting node at front of list 
void deleteEnd(); // delelting node at end of list 
void displayDll(); // displaying the list of employees 
int main() 
{ 
    int ch; 
    while (1) 
    { 
        printf("\n 1.Create Emp DLL\n2.insert Front\n 3.Insert End\n 
4.Delete Front\n 5.Delete End\n6.Display DLL\n7.Exit\n Enter Your 
Choice: "); 
        scanf("%d",&ch); 
        switch(ch) 
        { 
        case 1:createDll();// Create a DLL by inserting end  
              break; 
        case 2:insertFront(); // inserting front of list 
              break;         
        case 3:insertEnd();  // Inserting end of the list 
              break; 
        case 4:deleteFront(); // delete front of the list 
              break; 
        case 5:deleteEnd();  // delete end of the list 
              break; 
        case 6:displayDll();  
              break; 
        case 7:exit(0); 
        } 
    } 
    return 0; 
} 
NODE createNode() 
{ 
    NODE temp; 
    temp=malloc(sizeof(struct Employee)); // allocate memory for new node 
    printf("Enter emp SSN: \t");// read all the details of emp 
    scanf("%d",&temp->ssn); 
    printf("Enter emp Name: \t"); 
    scanf("%s",temp->name); 
    printf("Enter emp desigantion: \t"); 
    scanf("%s",temp->designation); 
    printf("Enter emp Department: \t"); 
    scanf("%s",temp->dept); 
    printf("Enter emp Salary: \t"); 
    scanf("%f",&temp->sal); 
    printf("Enter emp Phone Number: \t"); 
    scanf("%s",temp->phno); 
    temp->llink=NULL; // make new node left and right link NULL 
    temp->rlink=NULL; 
    count++; // increment the count when new node is created.. 
    return temp;       // return newly created node with data 
} 
void createDll() 
{ 
    NODE temp,cur;  // creating DLL by inserting end of the list 
    temp=createNode(); // Get new node with data 
    if(first==NULL)   // if no nodes in list temp node is first node 
    { 
        first=temp;   
    } 
    else 
    { 
        cur=first;  // take cur is reference node to insert at last 
        while(cur->rlink!=NULL) // repeat till end of list  
        { 
            cur=cur->rlink;   // traverse to next node 
        } 
        cur->rlink=temp;  // attach temp to last node with rLink 
        temp->llink=cur;  // store second last node address in last node 
    } 
    displayDll(); 
} 
 
void insertFront() 
{ 
    NODE temp; 
    temp=createNode(); // Get new node with data 
    first->llink=temp; // store address of temp node in first node left 
link 
    temp->rlink=first; // insert fornt of the list by linking right of 
temp with first 
    first=temp; // Make temp as first node 
    displayDll(); 
} 
void insertEnd() 
{ 
    createDll(); // Insert at end have same logic of Create Dll call the 
function 
} 
void deleteFront() 
{ 
    NODE cur; 
    cur=first->rlink;  // store second node in current node 
    free(first); // delete front i.e first node 
    first=cur;  // make second node as first node after deletion 
    //   (or) use the below statements  
    // first->llink=NULL; 
    // first=first->rlink; 
    first->llink=NULL;//  Make first node left link NULL 
    count--;  // when node is deleted 
    displayDll(); 
} 
void deleteEnd() 
{ 
    NODE cur,prev; // Prev stores the second last node 
    cur=first;   // take cur as reference to delete last node 
    while(cur->rlink!=NULL) // repeat till end of the list  
    { 
       prev=cur;   // Store second last node in cur node 
       cur=cur->rlink; // Move to next node 
    } 
    free(cur); // delete the last Node 
    prev->rlink=NULL; // Make last node rlink null to get end of the list. 
    count--;  // decrement the count when node is deleted 
    displayDll(); 
} 
void displayDll() 
{ 
    int count=0; 
    NODE cur; // take cur node as reference to populate data 
    cur=first;  // Make use of cur as first 
    if(first==NULL)  // if first is null list is empty... 
    { 
        printf("\n List is Empty!"); 
        return; 
    } 
    // Display the heading part of details.... 
    printf("\n SSN \t Name \t\t Department \t Designation \t Salary \t 
Phone Num \n"); 
    while(cur!=NULL)    
    {  
        printf("%d \t %s \t\t %s \t %s \t %f \t %s \n ",cur->ssn,cur
>name,cur->dept,cur->designation,cur->sal,cur->phno); 
        cur=cur->rlink; // move to the next node till end of list.. 
        count++; //increment the count to get total count of nodes  
    } 
    printf("\n Total Num of employees:%d\n ",count); // Dispaly total 
count of Employees... 
} 