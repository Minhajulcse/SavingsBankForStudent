// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char name[20];
    int id;
    int pass;
    float deposit;
    float withdraw;
    struct node * next;
};

struct node* signUp(struct node* tail){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter Your name -> ");
    scanf("%s",&temp -> name);
    printf("Enter your student ID -> ");
    scanf("%d",&temp -> id);
    printf("Enter a strong password -> ");
    scanf("%d",&temp -> pass);
    temp -> deposit = 0.0;
    temp -> withdraw = 0.0;
    temp -> next = NULL;
    tail -> next = temp;
    return temp;
}

struct node* userProfile(struct node* head){
    struct node * h = head;
    while(head != NULL){
        printf("Welcome %s\n",head -> name);
        printf("Your student id is %d \n",head -> id);
        printf("Your password is %d\n",head -> pass);
        printf("Your deposit money is %.2f\n",head -> deposit);
        printf("Your total withdraw money is %.2f\n", head -> withdraw);
        head = head -> next;
        printf("\n");
    }printf("\n");
    return h;
}

int main() {
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    strcpy(temp -> name,"TOTO BANK");
    temp -> id = 12;
    temp -> pass = 123;
    temp -> deposit = 0.0;
    temp -> withdraw = 0.0;
    struct node *head, *tail;
    head = temp;
    tail = temp;
    
    homepage : 
    printf("\t\tTOTO BANK \n");
    printf("1.Want to create new accout .\n");
    printf("2.Login your excisting accout .\n");
    printf("3.Exist\n");
    int k;
    scanf("%d",&k);
    
    switch(k){
        case 1:
              printf("Welcome to our family .\n");
              tail = signUp(tail);
              printf("Congratulation , Your account was created succesfully.\n");
              printf("1.want to go homepage\n");
              printf("2.Exit\n");
              int n;
              scanf("%d",&n);
              if(n == 1){
                    goto homepage;
              }else {
                    return 0;
              }
              break;
        
        case 2:
        break;
        
        case 3:
        return 0;
    }
    head = userProfile(head);

    return 0;
}
