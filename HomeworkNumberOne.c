#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node* next;
}node;

// Function to add a new node to the beginning of the list
node* addNodeToFront(struct node* head, int num) {
    node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->number = num;
    newNode->next = head;
    return newNode;
}

// Function to add a new node to the end of the list
node* addNodeToEnd(struct node* head, int num) {
    node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->number = num;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to print the linked list
void printList(struct node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->number);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    node* head = NULL;
    int num;

    printf("Enter numbers (-1 to stop):\n");

    while (1) {
        printf("Number: ");
        scanf("%d", &num);

        if (num == -1) {
            break;
        }

        if (num % 2 == 0) {
            head = addNodeToEnd(head, num); // Add even number to the end
        } else {
            head = addNodeToFront(head, num); // Add odd number to the front
        }
    }

    printf("\nLinked List after adding odd numbers to the front and even numbers to the end:\n");
    printList(head);

    // Free memory
    node* current = head;
    while (current != NULL) {
        node* p = current;
        current = current->next;
        free(p);
    }

    return 0;
}
