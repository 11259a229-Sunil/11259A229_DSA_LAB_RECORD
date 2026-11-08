
#include <stdio.h>
#include <stdlib.h>

#define QMAX 100

struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node *createNode(int val) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a node into BST
struct Node *insert(struct Node *root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    else {
        printf("Duplicate value not allowed.\n");
    }

    return root;
}

// In-order Traversal
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Pre-order Traversal
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order Traversal
void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Level-order Traversal
void levelorder(struct Node *root) {
    struct Node *queue[QMAX];
    int front = 0, rear = 0;

    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    queue[rear++] = root;

    while (front < rear) {
        struct Node *curr = queue[front++];

        printf("%d ", curr->data);

        if (curr->left != NULL) {
            if (rear < QMAX) {
                queue[rear++] = curr->left;
            }
        }

        if (curr->right != NULL) {
            if (rear < QMAX) {
                queue[rear++] = curr->right;
            }
        }
    }
}

// Free allocated memory
void freeTree(struct Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main Function
int main() {
    struct Node *root = NULL;
    int n, i, val, choice;

    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    printf("Enter %d values: ", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    do {
        printf("\n--- BST Traversal Menu ---\n");
        printf("1. In-order\n");
        printf("2. Pre-order\n");
        printf("3. Post-order\n");
        printf("4. Level-order\n");
        printf("5. Insert new node\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("In-order Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 2:
                printf("Pre-order Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 3:
                printf("Post-order Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 4:
                printf("Level-order Traversal: ");
                levelorder(root);
                printf("\n");
                break;

            case 5:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;

            case 6:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 6);

    freeTree(root);

    return 0;
}
