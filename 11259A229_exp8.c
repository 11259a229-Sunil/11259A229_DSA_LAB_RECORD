
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *rear = NULL;

// Enqueue Operation
void enqueue(int val) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = val;

    if (rear == NULL) {
        newNode->next = newNode;
        rear = newNode;
    } 
    else {
        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d enqueued to circular queue.\n", val);
}

// Dequeue Operation
void dequeue() {
    struct Node *front;

    if (rear == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    front = rear->next;

    printf("%d dequeued from circular queue.\n", front->data);

    if (front == rear) {
        rear = NULL;
    } 
    else {
        rear->next = front->next;
    }

    free(front);
}

// Display Operation
void display() {
    struct Node *temp;

    if (rear == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    temp = rear->next;

    printf("Circular Queue elements: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != rear->next);

    printf("\n");
}

// Main Function
int main() {
    int choice, val;

    do {
        printf("\n--- Circular Queue (Linked List) Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    // Free remaining nodes
    while (rear != NULL) {
        dequeue();
    }

    return 0;
}
