
#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    int n, i, choice;
    struct Employee *emp;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of employees.\n");
        return 1;
    }

    // Dynamic memory allocation
    emp = (struct Employee *)malloc(n * sizeof(struct Employee));

    if (emp == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input employee details
    for (i = 0; i < n; i++) {
        printf("\nEnter details for employee %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &(emp + i)->id);

        printf("Name: ");
        scanf("%49s", (emp + i)->name);

        printf("Salary: ");
        scanf("%f", &(emp + i)->salary);
    }

    // Menu-driven operations
    do {
        printf("\n--- Employee Record Menu ---\n");
        printf("1. Display all employees\n");
        printf("2. Search employee by ID\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\n%-6s %-20s %-10s\n",
                   "ID", "Name", "Salary");

            for (i = 0; i < n; i++) {
                printf("%-6d %-20s %-10.2f\n",
                       (emp + i)->id,
                       (emp + i)->name,
                       (emp + i)->salary);
            }
        }

        else if (choice == 2) {
            int searchId, found = 0;

            printf("Enter ID to search: ");
            scanf("%d", &searchId);

            for (i = 0; i < n; i++) {
                if ((emp + i)->id == searchId) {
                    printf("\nEmployee Found!\n");
                    printf("ID: %d\n", (emp + i)->id);
                    printf("Name: %s\n", (emp + i)->name);
                    printf("Salary: %.2f\n", (emp + i)->salary);

                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Employee with ID %d not found.\n",
                       searchId);
            }
        }

        else if (choice == 3) {
            printf("Exiting program.\n");
        }

        else {
            printf("Invalid choice.\n");
        }

    } while (choice != 3);

    // Free allocated memory
    free(emp);

    return 0;
}
