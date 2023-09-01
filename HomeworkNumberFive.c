#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int age;
    struct Node* next;
};

// Function to create a new node with the given age
struct Node* createNode(int age) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->age = age;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int age) {
    struct Node* newNode = createNode(age);
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

// Function to delete the second node with the given age value
struct Node* deleteNode(struct Node* head, int ageToDelete) {
    if (head == NULL || head->next == NULL) {
        // Empty list or list with only one element, nothing to delete.
        return head;
    }

    struct Node* current = head;
    struct Node* previous = NULL;
    int count = 0;

    while (current != NULL) {
        if (current->age == ageToDelete) {
            count++;
            if (count == 2) {
                // Found the second node with the given age, delete it
                if (previous == NULL) {
                    // If it's the first node, update the head pointer
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                free(current);
                return head;
            }
        }
        previous = current;
        current = current->next;
    }

    // If we reach here, there was no second node with the given age
    printf("No second node with age %d found in the list.\n", ageToDelete);
    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->age);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int age, ageToDelete;

    printf("Enter ages (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &age);
        if (age == -1) {
            break;
        }
        head = insertAtEnd(head, age);
    }

    printf("Original Linked List:\n");
    printList(head);

    printf("Enter the age to delete the second occurrence: ");
    scanf("%d", &ageToDelete);

    head = deleteNode(head, ageToDelete);

    printf("Updated Linked List (after deleting the second occurrence of age %d):\n", ageToDelete);
    printList(head);

    // Free memory
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
