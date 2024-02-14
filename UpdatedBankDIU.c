#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct student{
    char name[20];
    int id;
    struct student * next;

};
struct node{
    char name[20];
    int id;
    int pass;
    float deposit;
    float withdraw;
    struct node * next;
};

struct student * User(){
    struct student *s1, *s2, *s3;
    s1 = (struct student*)malloc(sizeof(struct student));
    s2 = (struct student*)malloc(sizeof(struct student));
    s3 = (struct student*)malloc(sizeof(struct student));
    s4 = (struct student*)malloc(sizeof(struct student));
    strcpy(s1 -> name,"Minhajul");
    s1 -> id = 23215931;
    s1 -> next = s2;

    strcpy(s2 -> name,"Ziad");
    s2 -> id = 23215935;
    s2 -> next = s3;

    strcpy(s3 -> name,"Zarif");
    s3 -> id = 23215914;
    s3 -> next = s4;

    strcpy(s4 -> name,"Bayzid");
    s4 -> id = 23215927;
    s4 -> next = NULL;

    return s1;
}
struct node* signUp(struct student *s1,struct node* tail){
    int id, pass;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    up :
    printf("Enter your student ID -> ");
    scanf("%d",&id);
    
    struct student * h = s1;
    while(h -> next != NULL){
        if(h -> id == id){
            strcpy(temp -> name, h -> name);
            temp -> id = id;
            temp -> deposit = 0.0;
            temp -> withdraw = 0.0;
            temp -> next = NULL;
            tail -> next = temp;
            break;
        }
        h = h -> next;
    }
    if(h -> id != id){
        printf("Incorrect ID, Please insert a valid ID.\n");
        goto up;
    }        
    printf("Enter a strong password -> ");
    scanf("%d",&pass);
    temp -> pass = pass;

    return temp;
    
}
struct node* login(struct node* head){
    struct node* temp = head;
    int id, pass,k;
    float amount;
    Login :
    
    printf("Enter your student ID -> ");
    scanf("%d",&id);
    printf("Enter your password -> ");
    scanf("%d",&pass);
    while(temp != NULL){
        if((temp -> id == id) && (temp -> pass == pass)){
            print :
            printf("\n");
            printf("Welcome back %s\n", temp -> name);
            printf("Your student id is %d \n",temp -> id);
            printf("Your password is %d\n",temp -> pass);
            printf("Your current available bank balance is %.2f\n",temp -> deposit);
             printf("Your total withdraw money is %.2f\n", temp -> withdraw);
             printf("\n");
            
            break;
        }
        else if(temp -> next == NULL){
            printf("\n");
            printf("Your entered ID or password is wrong.\nPlease insert right id and password.\n");
            goto Login;
        }
        temp = temp -> next;
    }
    calc:
    printf("\n");
    printf("->>Do you wanna deposit or withdraw you money??? \n");
    printf("Press 1 for deposit.\n");
    printf("Press 2 for withdraw .\n");
    printf("Press 3 for logout . \n");
    scanf("%d",&k);
    switch(k){
        case 1:
              printf("Enter deposit amount -> ");
              scanf("%f", &amount);
              temp -> deposit =(temp -> deposit) + amount;
              printf("Congratulations , deposit succesfull.\n");
              printf("Your current available bank balance is %.2f\n",temp -> deposit);
              goto print;
              break;
        case 2:
              printf("Enter amount for withdraw -> ");
              scanf("%f",&amount);
              if(amount > temp -> deposit){
                  printf("Sorry, You dont have enough money in your account\n");
                  goto calc;
              }else if(amount <= temp -> deposit){
                  temp -> deposit -= amount;
                  printf("Withdraw Succesful\n");
                  temp -> withdraw += amount;
                  printf("available bank balance is %.2f\n",temp -> deposit);
                  goto print;
              }
              break;
        case 3:
              return head;
    }
    
    return head;
}
struct node* userProfile(struct node* head, int id, int pass){
    struct node * h = head;
    head = head -> next;
    int AdminId = 2328, AdminPass = 2222;
    int i = 0;
    if(AdminId == id && AdminPass == pass){
        while(head != NULL){
            printf("Student name -> %s\n",head -> name);
            printf("student id is %d \n",head -> id);
           // printf("Student password is %d\n",head -> pass);
            printf("Students current available bank balance is %.2f\n",head -> deposit);
            printf("Student's total withdraw money is %.2f\n", head -> withdraw);
            head = head -> next;
            i++;
            printf("\n");
        }
        printf("Total Registared Student -> %d\n",i);
    }
    return h;
}
void print(struct student *head){
    struct student *p = head;
    while(p != NULL){
        printf("Student name -> %s\n",p -> name);
        printf("Student ID -> %d\n", p -> id);
        p = p -> next;
    }
}
int main(){
    int k, n;
    int AdminId = 0, AdminPass = 0;
    struct student *student1 = NULL;
    student1 = User();
    //create a null node for starting nodes for userinput
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
    printf("\t\tTOTO BANK\n");
    printf("1.Want to create new accout .\n");
    printf("2.Login your excisting accout .\n");
    printf("3.Payment \n");
    printf("4.Admin.\n");
    printf("5.Exist\n");
    scanf("%d",&k);

    switch(k){
        case 1:
              printf("Welcome to our family .\n");
              tail = signUp(student1,tail);
              printf("Congratulation , Your account was created succesfully.\n");
              printf("1.want to go homepage\n");
              printf("2.Exit\n");
              scanf("%d",&n);
              if(n == 1){
                    goto homepage;
              }else {
                    return 0;
              }
              break;
        
        case 2:
              head = login(head);
              goto homepage;
              break;
        
        case 4:
              printf("Enter your Admin Id please ->");
              scanf("%d",&AdminId);
              printf("Enter your Admin password please ->");
              scanf("%d",&AdminPass);
              head = userProfile(head,AdminId,AdminPass);
              goto homepage;
              break;
        case 5:
              printf("Thankes for explore TOTO BANK. Hope You enjoyed our service.\n");
              break;
    }





    return 0;
}
