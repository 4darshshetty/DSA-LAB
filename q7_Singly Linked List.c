#include<stdio.h> 
struct student 
{ 
    char usn[20]; 
    char name[50]; 
    char branch[20]; 
    int sem; 
    char phno[10]; 
    struct student  *link; 
}; 
typedef struct student *NODE; 
int count=0; // To count total no of nodes in a list.. 
NODE createNode(); 
void CreateSLL();   // Creating list by inserting fornt 
void DisplaySLL(); 
void InsertFront(); 
void InsertEnd(); 
void DeleteFront(); 
void DeleteEnd(); 
NODE  first=NULL; 
int main() 
{ 
    int ch; 
    while(1) 
    { 
        printf("1.CreateSLL \n2.DisplaySLL \n3.Insert front \n4.Insert 
End \n5.Delete Front\n6.Delete End \n7.Exit\nEnter Your Choice:"); 
        scanf("%d",&ch); 
        switch (ch) 
        { 
            case 1:CreateSLL(); 
                   break; 
            case 2:DisplaySLL(); 
                   break; 
            case 3:InsertFront(); 
                   break; 
            case 4:InsertEnd(); 
                   break; 
            case 5:DeleteFront(); 
                   break; 
            case 6:DeleteEnd(); 
                   break; 
            case 7:exit(0); 
        } 
    } 
    return 0; 
} 
NODE  createNode() 
{ 
    // Creating student node dtails 
    NODE temp; 
    // Allocate memeory for temp node  
    temp=malloc(sizeof(struct student)); 
    // read student details 
    printf("\n Enter Usn:"); 
    scanf("%s", temp->usn); 
    printf("\n Enter Student Name:"); 
    scanf("%s", temp->name); 
    printf("\n Enter branch:"); 
    scanf("%s", temp->branch); 
    printf("\n Enter semester:"); 
    scanf("%d", &temp->sem); 
    printf("\n Enter Phone Number:"); 
    scanf("%s", temp->phno); 
    temp->link=NULL;        // Make temp link null default  
    count++;  // Increment the count new node is created 
    return temp;      // return newly created node  
} 
void CreateSLL() 
{ 
    int count=0; 
    NODE temp; 
    temp=createNode();  // Copy student node to temp 
    if(first==NULL)  // If first is NULL no nodes in the list 
    { 
       first=temp; // Make first node as Temp 
    } 
    else 
    {    
        temp->link=first; // insert front of the list store first node 
address to temp 
        first=temp;       // Make temp as first node    
    }  
   printf("Student node inserted at Front of List \n"); 
   DisplaySLL(); 
} 
void DisplaySLL() 
{ 
    NODE cur=first; 
    if(first==NULL) 
    { 
       printf("\n Student List is empty!"); 
       return; 
    } 
        printf("\nStudents List:\n"); 
        printf("----------------------------------------------\n"); 
        while(cur!=NULL) 
        { 
          // print student information.... 
       printf("%s\t%s\t%s\t%d\t%s\n",cur->usn,cur->name,cur->branch, 
        cur->sem,cur->phno); 
          cur=cur->link; 
           
        }         
        printf("\n");  
        printf("Total Number of students: %d \n",count);  
} 
void InsertFront() 
{ 
  CreateSLL();// Call CreateSLL to insert front of the list 
} 
void InsertEnd() 
{ 
    NODE temp,cur; // To create node temp node taken as reference 
    cur=first;     // make current as first  
    while(cur->link!=NULL)  //Go to end of the list 
    { 
        cur=cur->link;     // Move current node to next node 
    } 
    temp=createNode(); // Create Node and copy to temp 
    cur->link=temp;    // Link new node to last node        
    printf("Studnet Node inserted at end of the list!\n"); 
    DisplaySLL();     // Display List 
} 
void DeleteFront() 
{ 
   NODE cur; 
   cur=first->link;   // Make second node as current  
   free(first);     // delete first node 
   first=cur;     // make currrent node as first.. 
   printf("Node deleted front of the list!\n"); 
   count--; // decrement the node when node is deleted 
   DisplaySLL(); 
    
} 
void DeleteEnd() 
{ 
    NODE cur, prev;// Copy second last node in prev  
    cur = first; // Make current as first for reference 
    if (first == NULL)  // If first is null list is empty 
    { 
        printf("Student list is empty!\n"); 
        return; 
    } 
    if (first->link == NULL) // if list contains one node delete it 
    { 
       free(first); // delete first node 
       return ; 
    }   
    while (cur->link != NULL)  // Move to end of the list 
    { 
        prev = cur;     // Store second last node in prev node 
        cur = cur->link; // Cur is last node.. 
    } 
    free(cur); // delete the last node.. 
    prev->link = NULL; // make prev link is null now prev is last node 
    printf("Node deleted end of the list!\n"); 
    count--; // decrement the count any node is deleted... 
    DisplaySLL(); 
} 