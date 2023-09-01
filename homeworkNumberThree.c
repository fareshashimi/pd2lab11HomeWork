#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;

// Function to create a new node
node* createNode(int data) {
    node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
node* insertAtEnd(struct node* head, int data) {
    node* newNode = createNode(data);

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

// Function to delete the element in the middle of the list
node* deleteMiddleElement(struct node* head) {
    if (head == NULL || head->next == NULL) {
        // List is empty or has only one element, nothing to delete.
        return head;
    }

    node* slowPtr = head;
    node* fastPtr = head;
    node* prev = NULL;

    // Move the fast pointer twice as fast as the slow pointer
    while (fastPtr != NULL && fastPtr->next != NULL) {
        fastPtr = fastPtr->next->next;
        prev = slowPtr;
        slowPtr = slowPtr->next;
    }

    // Delete the middle element (slowPtr)
    if (prev != NULL) {
        prev->next = slowPtr->next;
    } else {
        // If there is no previous node, update the head
        head = head->next;
    }

    // Free the memory of the deleted node
    free(slowPtr);

    return head;
}

// Function to print the linked list
void printList(struct node* head) {
    node* current = head;
    while (current != NULL) {
        printf(" %d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    node* head = NULL;
    int data, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("\nEnter the elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element: ");
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }

    printf("\n\n Original Linked List:\n");
    printList(head);

    head = deleteMiddleElement(head);

    printf("\n Updated Linked List (after deleting the middle element):\n");
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
