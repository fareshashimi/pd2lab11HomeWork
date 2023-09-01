#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
}node;

// Function to create a new node with the given data
node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to swap the first and last nodes of the linked list
node* changeFirstAndLast(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        // Empty list or list with only one element, nothing to swap.
        return head;
    }

    node* lastNode = head;
    node* secondLastNode = NULL;

    // Traverse the list to find the last and second-last nodes
    while (lastNode->next != NULL) {
        secondLastNode = lastNode;
        lastNode = lastNode->next;
    }

    // Update the last node's next pointer to point to the second node in the list
    lastNode->next = head->next;

    // Update the head pointer to point to the last node
    head = lastNode;

    // Set the next pointer of the second-last node to NULL to finalize the swap
    secondLastNode->next = NULL;

    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    node* current = head;
    while (current != NULL) {
        printf(" %d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    node* head = NULL;
    int num;

    printf("Enter numbers (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &num);
        if (num == -1) {
            break;
        }
        head = insertAtEnd(head, num);
    }

    printf("\n\n Original Linked List:\n");
    printList(head);

    head = changeFirstAndLast(head);

    printf("\n Updated Linked List (after swapping first and last nodes):\n");
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

