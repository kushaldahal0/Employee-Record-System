#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

struct emp {
    char name[40]; 
    int age; 
    float bs; 
    struct emp *next;
}*head = NULL;
struct emp *newnode(){
	struct emp *temp = (struct emp*) malloc(sizeof(struct emp));
	temp->next = NULL;
	temp->age = 0;
	temp->bs = 0;
	return temp;
}
void insert(){
	struct emp *temp, *newemp = newnode();
	char another;
	printf("\n\tEnter name: ");
    	scanf("%s",&newemp->name);
    	printf("\n\tEnter age: ");
    	scanf("%d", &newemp->age);
   	 printf("\n\tEnter basic salary: ");
    	scanf("%f", &newemp->bs);
	if(head == NULL)
	head = newemp;
	else{
		temp = head;
		while(temp->next !=NULL){
			temp = temp->next;
		}
       	 temp->next = newemp;
 }
 	getch();	
}
void traverse() {
    struct emp* temp = head;
    while (temp != NULL) {
        printf("\n\nName :\t\t%s ", temp->name);
        printf("\nAge :\t\t%d", temp->age);
        printf("\nBasic Salary:\t%.2f\n",temp->bs);
        temp = temp->next;
    }
    printf("\n");
    getch();
}

void modify() {
    struct emp* temp = head;
    char empname[40];
    printf("Enter the employee name to modify: ");
    scanf("%s", empname);
    while (temp != NULL) {
    	if(strcmp(empname,temp->name)==0){
   		printf("Enter Updated Record\n");
        		printf("\n\tEnter name: ");
    		scanf("%s",&temp->name);
    		printf("\n\tEnter age: ");
    		scanf("%d", &temp->age);
    		printf("\n\tEnter basic salary: ");
    		scanf("%f",&temp->bs);
    	}
	temp = temp->next;
     }
    printf("\n");
    getch();
}
int deleter() {
    char empname[40];
    if(head == NULL){
    	printf("Record Empty");
    	getch();
	return ;
    }
        printf("Enter the employee name to modify: ");
        scanf("%s", empname);
        struct emp *temp = head, *prev;
        if (temp != NULL && (strcmp(empname, temp->name)==0)) {
  	printf("Record to be deleted: \n");
    	printf("\n\nName :\t\t%s ", temp->name);
        	printf("\nAge :\t\t%d", temp->age);
        	printf("\nBasic Salary:\t%.2f\n",temp->bs);
    	head = temp->next;
    	free(temp);
    	getch();
    	return;
      }
      while (temp != NULL && (strcmp(empname, temp->name)!=0)) {
    	prev = temp;
    	temp = temp->next;
     }  
    printf("Record to be deleted: \n");
    printf("\n\nName :\t\t%s ", temp->name);
    printf("\nAge :\t\t%d", temp->age);
    printf("\nBasic Salary:\t%.2f\n",temp->bs);
    prev->next = temp->next;
  	free(temp);
  	getch();
}
void search(){
	struct emp* temp = head;
char empname[40];
    	int flag = 0;
	printf("Enter the employee name: ");
    	scanf("%s", empname);
    	while (temp != NULL) {
    		if(strcmp(empname,temp->name)==0){
    			printf("Record Found");
    			printf("\n\nName :\t\t%s ", temp->name);
        			printf("\nAge :\t\t%d", temp->age);
        			printf("\nBasic Salary:\t%.2f\n",temp->bs);
			flag = 1;
		}
	temp = temp->next;
    	}
 	if(flag == 0) printf("Searched item not found!");
 	printf("\n");
    	getch();
}
int main()
{
    char choice;
    struct emp e;
    while(1)
    {
        system("cls");
        printf("\t\t\tEmployee Record\n");
        printf("\n1. Add Record"); 
        printf("\n2. List Records"); 
        printf("\n3. Modify Records"); 
        printf("\n4. Delete Records"); 
        printf("\n5. Search Record");
        printf("\n6. Exit"); 
        printf("\nYour Choice: "); 
        fflush(stdin); 
        choice  = getche(); 
        switch(choice)
        {
        	case '1': 
            		system("cls");
            		printf("ADD RECORD:\n\n");
            		insert();
            		break;
        	case '2':
        		system("cls");
        		printf("LIST RECORD:\n\n");
        		traverse();
        		break;
   	case '3':  
            		system("cls");
           		printf("MODIFY EXISTING RECORD:\n\n");
           		 modify();
           		 break;
          

     	case '4':
           		 system("cls");
            		printf("DELETE RECORD:\n\n");
            		deleter();
            		break;
         
     	 case '5':
        		system("cls");
        		printf("SEARCH RECORD:\n\n");
        		search();
        		break;
   
   	  case '6':
            		exit(0);
       	}
              }
        return 0;
}
