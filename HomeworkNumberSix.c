#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node *next;
}node;

node *addNumsToFront(node *head, int num){
    node *newNode = malloc(sizeof(node));
    if(newNode==NULL){
        printf(" No numbers in the heap.\n");
        exit(1);
    }

    newNode->number = num;
    newNode->next = head;

    return newNode;
}

node *addNumsToEnd(node *head, int num){
    node *newNode = malloc(sizeof(node));
    if(newNode==NULL){
        printf(" No current numbers in the heap.\n");
        exit(1);
    }

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

        if(num%2==0){
            head = addNumsToFront(head, num);
        }
        else{
            head = addNumsToEnd(head, num);
        }
    }

    printf("\n\n Linked List after adding even number to the front and odd numbers to the end:\n");
    printNums(head);

    node *current = head;
    while(current!=NULL){
        node *p = current;
        current = current->next;
        free(p);

    }

    return 0;
}
