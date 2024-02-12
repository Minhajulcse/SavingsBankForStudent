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

struct node* login(struct node* head){
    login :
    
    int id, pass;
    printf("Enter your student ID -> ");
    scanf("%d",&id);
    printf("Enter your password -> ");
    scanf("%d",&pass);
    struct node* temp = head;
    while(temp != NULL){
        if((temp -> id == id) && (temp -> pass == pass)){
            printf("\nWelcome back %s\n", temp -> name);
            printf("Your student id is %d \n",temp -> id);
            printf("Your password is %d\n",temp -> pass);
            printf("Your current available bank balance is %.2f\n",temp -> deposit);
             printf("Your total withdraw money is %.2f\n", temp -> withdraw);
            
            break;
        }
        else if(temp -> next == NULL){
            printf("Your entered ID or password is wrong.\nPlease insert right id and password.\n");
            goto login;
        }
        temp = temp -> next;
    }
    return head;
}

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
        printf("Your current available bank balance is %.2f\n",head -> deposit);
        printf("Your total withdraw money is %.2f\n", head -> withdraw);
        head = head -> next;
        printf("\n");
    }printf("\n");
    return h;
}

int main() {
    struct node * node1 = (struct node*)malloc(sizeof(struct node));
    strcpy(node1 -> name,"TOTO BANK");
    node1 -> id = 12;
    node1 -> pass = 123;
    node1 -> deposit = 0.0;
    node1 -> withdraw = 0.0;
    struct node *head, *tail;
    head = node1;
    tail = node1;
    
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
              head = login(head);
              break;
        
        case 3:
              return 0;
    }

    return 0;
}
