#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node* next;
}node;

// Function to create a new node
node* createNode(int num) {
    node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->number = num;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
struct node* insertAtBeginning(struct node* head, struct node* newNode) {
    if (newNode == NULL) {
        return head;
    }

    newNode->next = head;
    return newNode;
}

// Function to cut the last node and add it to the beginning
struct node* cutlastaddhead(struct node* head) {
    if (head == NULL || head->next == NULL) {
        // List is empty or has only one node, nothing to cut and add.
        return head;
    }

    node* current = head;
    node* previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    // Cut the last node
    previous->next = NULL;

    // Insert the cut node at the beginning
    head = insertAtBeginning(head, current);

    return head;
}

// Function to print the linked list
void printList(struct node* head) {
    node* current = head;
    while (current != NULL) {
        printf(" %d -> ", current->number);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    node* head = NULL;
    int num;

    printf("Enter numbers (enter -1 to stop):\n");
    while (1) {
        printf("Number: ");
        scanf("%d", &num);
        if (num == -1) {
            break;
        }

        node* newNode = createNode(num);
        head = insertAtBeginning(head, newNode);
    }

    printf("\n\n Original Linked List:\n");
    printList(head);

    head = cutlastaddhead(head);

    printf("\n Updated Linked List (after cutting the last node and adding it to the beginning):\n");
    printList(head);

    // Free memory
    node* current = head;
    while (current != NULL) {
        node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

