#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct Student_info
{
    int studants_no;
    char name[200];
    char last_name[200];
    float vize;
    float final;
    struct Student_info *next;
    
}* head;
void insert(int studants_no, char* name, char* last_name, float final, float vize)
{
    
    struct Student_info * student_info = (struct Student_info *) malloc(sizeof(struct Student_info));
    student_info->studants_no = studants_no;
    strcpy(student_info->name, name);
    strcpy(student_info->last_name, last_name);
    student_info->final = final;
    student_info->vize = vize;
    student_info->next = NULL;
    
    if(head==NULL){
       
        head = student_info;
    }
    else{
       
        student_info->next = head;
        head = student_info;
    }
    
}
void search(int studants_no)
{
    struct Student_info * temp = head;
    while(temp!=NULL){
        if(temp->studants_no==studants_no){
            printf("studants_no: %d\n", temp->studants_no);
            printf("Name: %s\n", temp->name);
            printf("last name: %s\n", temp->last_name);
            printf("final : %0.4f\n", temp->final);
            printf("vize : %0.4f\n", temp->vize);
            return;
        }
        temp = temp->next;
    }
    printf("Student with studants no %d is not found !!!\n", studants_no);
}
void update(int studants_no)
{
   FILE *fptr;
   fptr = (fopen("C:\students informtion.txt", "w"));
   if(fptr == NULL)
   {
       printf("Error!");
       exit(1);
   }
 
    struct Student_info * temp = head;
    while(temp!=NULL){
    	
        
        if(temp->studants_no==studants_no){
            printf("Record with studants no %d Found !!!\n", studants_no);
            printf("Enter new name: ");
            scanf("%s", temp->name);
            printf("Enter new last name: ");
            scanf("%s", temp->last_name);
            printf("Enter new final : ");
            scanf("%f",&temp->final);
            printf("Enter vize:");
            scanf("f",&temp->vize);
            printf("Updation Successful!!!\n");
            fprintf(fptr,"\nName: %s \last name=%s \n \student no=%d\n \final=%f\n \vize=%f\n",temp->name,temp->last_name,temp->studants_no,temp->final,temp->vize );
            fclose(fptr);            
            return;
        }
        temp = temp->next;
        
    }
    printf("Student with studants no %d is not found !!!\n", studants_no);
    
}
void Delete(int studants_no)
{
    struct Student_info * temp1 = head;
    struct Student_info * temp2 = head; 
    while(temp1!=NULL){
        
        if(temp1->studants_no==studants_no){
            
            printf("Record with studants no %d Found !!!\n", studants_no);
            
            if(temp1==temp2){
                
                head = head->next;
                free(temp1);
            }
            else{
                
                temp2->next = temp1->next;
                free(temp1); 
            }
            
            printf("Record Successfully Deleted !!!\n");
            return;
            
        }
        temp2 = temp1;
        temp1 = temp1->next;
        
    }
    printf("Student with studants no %d is not found !!!\n", studants_no);
    
}
void display()
{
    struct Student_info * temp = head;
    while(temp!=NULL){
        
        printf("studants no: %d\n", temp->studants_no);
        printf("Name: %s\n", temp->name);
        printf("last name: %s\n", temp->last_name);
        printf("final : %0.4f\n\n", temp->final);
        printf("vize: %0.4f\n\n", temp->vize);
        temp = temp->next;
        
    }
}
int main()
{
    head = NULL;
    int choice;
    char name[200];
    char last_name[200];
    int studants_no;
    float vize;
    float final;
    printf("1 to insert student details\n2 to search for student details\n3 to delete student details\n4 to update student details\n5 to display all student details");
    do
    {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter studants no: ");
                scanf("%d", &studants_no);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter last name: ");
                scanf("%s", last_name);
                printf("Enter final : ");
                scanf("%f", &final);
                printf("Enter vize: ");
                scanf("%f", &vize);
                insert(studants_no, name, last_name, final,vize);
                break;
            case 2:
                printf("studants no number to search: ");
                scanf("%d", &studants_no);
                search(studants_no);
                break;
            case 3:
                printf("Enter studants no to delete: ");
                scanf("%d", &studants_no);
                Delete(studants_no);
                break;
            case 4:
                printf("Enter studants no to update: ");
                scanf("%d", &studants_no);
                update(studants_no);
                break;
            case 5:
                display();
                break;
        }
        
    } while (choice != 0);
    return 0;
}
