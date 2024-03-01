/*#include <stdio.h>
int stack[10];
static int top=-1;
void push(){
    int el;
    printf("Enter element to be inserted:");
    scanf("%d",&el);
    if(top==9){
        printf("Overflow...!!!");
    }else{
    top++;
    stack[top] = el;
    }
}
void pop(){
    if(top==-1){
        printf("Underflow...!!!");
    }else{
        top--;
    }
}
void display(){
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
}
int main(){
    int choice;
    while(1){
    printf("1.Push\n2.Pop\n3.Display\n4.Exit\nEnter a choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:push();
        break;
        case 2:pop();
        break;
        case 3:display();
        break;
        case 4:exit(0);
    }
    }
    return 0;
}*/
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char stack[100];
static int top;
static int postcount = 0;
int isoptr(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}
int prec(char a) {
    switch (a) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}
void infixtopostfix(char a[], char b[]) {
    top = -1;
    top++;
    stack[top] = '#';

    for (int i = 0; i < strlen(a); i++) {
        if (isalnum(a[i])) {
            b[postcount] = a[i];
            postcount++;
        } else if (a[i] == '(') {
            top++;
            stack[top] = a[i];
        } else if (a[i] == ')') {
            while (stack[top] != '(') {
                b[postcount] = stack[top];
                postcount++;
                top--;
            }
            top--; // Discard '(' from the stack
        } else if (isoptr(a[i])) {
            while (top >= 0 && stack[top] != '(' && prec(a[i]) <= prec(stack[top])) {
                b[postcount] = stack[top];
                postcount++;
                top--;
            }
            top++;
            stack[top] = a[i];
        }
    }

    while (top > 0 && stack[top] != '#') {
        b[postcount] = stack[top];
        postcount++;
        top--;
    }

}
int main(){
    char infix[100];
    char postfix[100];
    printf("Enter the infix expression:");
    scanf("%s",infix);
    
    infixtopostfix(infix,postfix);
    postfix[postcount]='\0';
    printf("Postfix expression is: %s",postfix);
    return 0;
}*/
/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int queue[5];
static int front=-1;
static int rear=-1;
void insert(){
    int el;
    if(rear-front==4){
        printf("Overflow..!!\n");
    }else{
    printf("Enter the element: ");
    scanf("%d",&el);
    if(front==-1){
        front=0;
        rear=0;
        queue[rear]=el;
    }
    else{

        queue[++rear]=el;
    }
    }
}
void del(){
    front++;
}
void display(){
    for (int i=front; i<=rear; i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}
int main(){
    int choice;
    while(1){
    printf("1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        insert();
        break;
        case 2:
        del();
        break;
        case 3:
        display();
        break;
        case 4:
        exit(0);
        case 5:
        printf("Invalid input");
        break;
    }
    }
    return 0;
}*/
/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int queue[5];
static int front=-1;
static int rear=-1;
void insert(){
    int el;
    if(rear-front==4||rear=front+1||r){
        printf("Overflow..!!\n");
    }else{
    printf("Enter the element: ");
    scanf("%d",&el);
    if(front==-1){
        front=0;
        rear=0;
        queue[rear]=el;
    }
    else if(rear==4){
        rear=0;
        queue[rear]=el;
    }
    else{
        queue[++rear]=el;
    }
    }
}
void del(){
    if()
    front++;
}
void display(){
    for (int i=front; i<=rear; i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}
int main(){
    int choice;
    while(1){
    printf("1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        insert();
        break;
        case 2:
        del();
        break;
        case 3:
        display();
        break;
        case 4:
        exit(0);
        case 5:
        printf("Invalid input");
        break;
    }
    }
    return 0;
}*/
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct node{
    int info;
    struct node *next;
};
struct node *start=NULL;
void insert(){
    int el,pos;
    struct node *temp,*ptr=start;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the element to be inserted: ");
    scanf("%d",&el);
    printf("Enter the position you want to insert the element:");
    scanf("%d",&pos);
    temp->info=el;
    if(pos==0){
        if(start==NULL){
        temp->next=NULL;
        start=temp;
        }else{
            temp->next=start;
            start=temp;
        }
    }
    else{
        for(int i=0;i<pos-1;i++){
            ptr=ptr->next;
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }
}
void del(){
    int el;
    struct node *temp, *ptr=start;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the element to be deleted:");
    scanf("%d",&el);
    if(start->info==el){
        temp=start;
        start=start->next;
        free(temp);
    }
    else{
        while(ptr->next!=NULL){
            if(ptr->next->info==el &&ptr->next->next!=NULL){
                temp=ptr->next;
                ptr->next=ptr->next->next;
                free(temp);
            }
            else if(ptr->next->info==el &&ptr->next->next==NULL){
                temp=ptr->next;
                ptr->next=NULL;
                free(temp);
            }
            else{
                ptr=ptr->next;
            }
        }
    }
}
void display(){
    struct node *ptr=start;
    while(ptr!=NULL){
        printf("%d ",ptr->info);
        ptr=ptr->next;
    }
    printf("\n");
}
int main() {
    int choice;
    while(1){
        printf("\n1.Add\n2.Delete an element\n3.Display\n4.Exit\nEnter your choice:");
        scanf("%d",&choice);
        if(choice == 1){
            insert();
        }
        else if(choice == 2){
            del();
        }
        else if(choice == 3){
            display();
        }
        else if(choice==4){
            exit(0);
        }
    }
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct node{
    int info;
    struct node *next;
};
struct node *start=NULL;
void insert(){
    int el;
    struct node *temp,*ptr=start;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the element to be inserted: ");
    scanf("%d",&el);
    temp->info=el;
        if(start==NULL){
        temp->next=start;
        start=temp;
        }else{
            while(ptr->next!=start){
                temp->next=start;
                ptr->next=temp;
            }
        }
}
void del(int el){
    struct node *temp, *ptr=start;
    temp=(struct node *)malloc(sizeof(struct node));
    if(start->info==el){
        temp=start;
        start=start->next;
        free(temp);
    }
    else{
        while(ptr->next!=start){
            if(ptr->next->info==el &&ptr->next->next!=start){
                temp=ptr->next;
                ptr->next=ptr->next->next;
                free(temp);
            }
            else if(ptr->next->info==el &&ptr->next->next==start){
                temp=ptr->next;
                ptr->next=start;
                free(temp);
            }
            else{
                ptr=ptr->next;
            }
        }
    }
}
void display(){
    struct node *ptr=start;
    while(ptr!=start){
        printf("%d ",ptr->info);
        ptr=ptr->next;
    }
    printf("\n");
}
int main() {
    int n;int m;int choice;
    struct node *ptr=start;
    printf("Enter the number of participants:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        insert();
    }
    printf("Enter number of passes:");
    scanf("%d",&m);
    if(m>n-1){
        printf("Invalid number of passes:");
        return 0;
    }
    while(m>=0){
    printf("1.Pass\n2.Exit");
    scanf("%d",&choice);
    if(choice==1){
    for(int i=0;i<m;i++){
        ptr=ptr->next;
    }
    printf("%d lost and been removed.\n",ptr->info);
    del(ptr->info);
    m--;
    }
    else{
        exit(0);
    }
    return 0;
    }
}