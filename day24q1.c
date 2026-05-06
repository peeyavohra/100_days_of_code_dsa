// Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer key

// Output:
// - Print the linked list elements after deletion, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 30

// Output:
// 10 20 40 50

// Explanation:
// Traverse list, find first node with key, remove it by adjusting previous node's next pointer.

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void deleteFirstOccurrence(struct Node** head, int key) {
    struct Node* current = *head;
    struct Node* previous = NULL;
    
    while (current != NULL) {
        if (current->data == key) {
            if (previous == NULL) {
                *head = current->next; // Deleting head node
            } else {
                previous->next = current->next; // Bypass current node
            }
            free(current); // Free memory of deleted node
            return; // Exit after deleting first occurrence
        }
        previous = current;
        current = current->next;
    }
}
void traverseList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main() {
    int n, key;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    
    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    printf("Enter the elements of the list: ");
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        struct Node* newNode = createNode(data);
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    printf("Enter the key to delete: ");
    scanf("%d", &key);
    
    deleteFirstOccurrence(&head, key);
    
    printf("Linked list after deletion: ");
    traverseList(head);
    
    return 0;
}
