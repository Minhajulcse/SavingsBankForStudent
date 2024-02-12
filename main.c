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

struct node* userProfile(struct node* head){
    struct node * h = head;
    while(head != NULL){
        printf("Welcome %s\n",head -> name);
        printf("Your student id is %d \n",head -> id);
        printf("Your password is %d\n",head -> pass);
        printf("Your deposit money is %.2f\n",head -> deposit);
        printf("Your total withdraw money is %.2f\n", head -> withdraw);
        head = head -> next;
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
    head = userProfile(head);

    return 0;
}