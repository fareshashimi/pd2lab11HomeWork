#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node *next;
}node;

node *createNum(int num){
    node *newNode = malloc(sizeof(node));
    
    newNode->number = num;
    newNode->next = NULL;
    
    return newNode;
}

node *addNumsToEnd(node *head, int num){
    node *newNode = createNum(num);
    
    newNode->number = num;
    newNode->next = NULL;
    if(head==NULL){
        return newNode;
    }
    
    node *current = head;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = newNode;
    
    return head;
}

node *swapLastAndFirst(node *head){
    node* prevNode = NULL;
    node* current = head;

    while (current->next != NULL) {
        prevNode = current;
        current = current->next;
    }

    prevNode->next = head;
    current->next = head->next;
    head->next = NULL;
    head = current;

    return head;
}

void printNums(node *head){
    node *current = head;
    while(current!=NULL){
        printf(" %d ->", current->number);
        current = current->next;
    }
    printf(" NULL\n");
}

int main(){
    int num;
    node *head = NULL;
    
    printf("Insert the numbers (-1 to stop):\n");
    while(1){
        printf("Number: ");
        scanf("%d", &num);
        
        if(num==-1){
            break;
        }
        
        head = addNumsToEnd(head, num);
    }
    
    printf("\n\n Original Linkead List:\n");
    printNums(head);
    
    head = swapLastAndFirst(head);
    
    printf("\n Updated Linkead List (after swapping between last and first node):\n");
    printNums(head);
    
    node *current = head;
    while(current!=NULL){
        node *p = current;
        current = current->next;
        free(p);
    }
    
    return 0;
}
