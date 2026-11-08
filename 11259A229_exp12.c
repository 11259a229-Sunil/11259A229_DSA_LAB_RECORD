
#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];
int isOccupied[SIZE] = {0};

// Hash Function
int hashFunction(int key) {
    return ((key % SIZE) + SIZE) % SIZE;
}

// Insert Operation
void insert(int key) {
    int index = hashFunction(key);
    int start = index;
    int count = 0;

    while (isOccupied[index] == 1) {

        if (hashTable[index] == key) {
            printf("Key %d already exists.\n", key);
            return;
        }

        index = (index + 1) % SIZE;
        count++;

        if (count == SIZE) {
            printf("Hash Table is full. Cannot insert %d.\n", key);
            return;
        }
    }

    hashTable[index] = key;
    isOccupied[index] = 1;

    if (index != start) {
        printf("Collision occurred for key %d. ", key);
    }

    printf("Key %d inserted at index %d.\n", key, index);
}

// Search Operation
void search(int key) {
    int index = hashFunction(key);
    int count = 0;

    while (isOccupied[index] == 1 && count < SIZE) {

        if (hashTable[index] == key) {
            printf("Key %d found at index %d.\n", key, index);
            return;
        }

        index = (index + 1) % SIZE;
        count++;
    }

    printf("Key %d not found in hash table.\n", key);
}

// Display Operation
void display() {
    int i;

    printf("\nHash Table:\n");

    for (i = 0; i < SIZE; i++) {
        if (isOccupied[i]) {
            printf("Index %d: %d\n", i, hashTable[i]);
        } else {
            printf("Index %d: --\n", i);
        }
    }
}

// Main Function
int main() {
    int choice, key;

    do {
        printf("\n--- Hashing (Linear Probing) Menu ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
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

    return 0;
}
