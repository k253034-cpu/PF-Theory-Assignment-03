#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    char designation[50];
    float salary;
};

// Function to display all employees
void displayEmployees(struct Employee emp[], int n) {
    printf("\n-------------------------------------------------------------\n");
    printf("ID\tName\t\tDesignation\t\tSalary\n");
    printf("-------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%-10s\t%-15s\t%.2f\n",
               emp[i].id, emp[i].name, emp[i].designation, emp[i].salary);
    }

    printf("-------------------------------------------------------------\n");
}

// Function to find employee with highest salary
void findHighestSalary(struct Employee emp[], int n) {
    int index = 0;

    for (int i = 1; i < n; i++) {
        if (emp[i].salary > emp[index].salary) {
            index = i;
        }
    }

    printf("\nEmployee with Highest Salary:\n");
    printf("ID: %d\n", emp[index].id);
    printf("Name: %s\n", emp[index].name);
    printf("Designation: %s\n", emp[index].designation);
    printf("Salary: %.2f\n", emp[index].salary);
}

// Function to search employee by ID or name
void searchEmployee(struct Employee emp[], int n) {
    int choice;
    printf("\nSearch Employee:\n1. Search by ID\n2. Search by Name\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int searchID;
        printf("Enter Employee ID to search: ");
        scanf("%d", &searchID);

        for (int i = 0; i < n; i++) {
            if (emp[i].id == searchID) {
                printf("\nEmployee Found:\n");
                printf("ID: %d\nName: %s\nDesignation: %s\nSalary: %.2f\n",
                       emp[i].id, emp[i].name, emp[i].designation, emp[i].salary);
                return;
            }
        }
        printf("Employee with ID %d not found.\n", searchID);
    }

    else if (choice == 2) {
        char searchName[50];
        printf("Enter Name to search: ");
        scanf("%s", searchName);

        for (int i = 0; i < n; i++) {
            if (strcmp(emp[i].name, searchName) == 0) {
                printf("\nEmployee Found:\n");
                printf("ID: %d\nName: %s\nDesignation: %s\nSalary: %.2f\n",
                       emp[i].id, emp[i].name, emp[i].designation, emp[i].salary);
                return;
            }
        }
        printf("Employee with name %s not found.\n", searchName);
    }

    else {
        printf("Invalid choice.\n");
    }
}

// Function to update salary if below threshold
void updateSalaryBelow(struct Employee emp[], int n, float threshold) {
    for (int i = 0; i < n; i++) {
        if (emp[i].salary < threshold) {
            emp[i].salary = emp[i].salary + (emp[i].salary * 0.10); // 10% bonus
        }
    }
}

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee emp[n];

    // Input employee records
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].id);

        printf("Name: ");
        scanf("%s", emp[i].name);

        printf("Designation: ");
        scanf("%s", emp[i].designation);

        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }

    // Display all employees
    displayEmployees(emp, n);

    // Find highest salary
    findHighestSalary(emp, n);

    // Search employee
    searchEmployee(emp, n);

    // Update employees with low salary
    printf("\nApplying 10%% bonus to employees earning below 50000...\n");
    updateSalaryBelow(emp, n, 50000);

    printf("\nUpdated Employee Records:\n");
    displayEmployees(emp, n);

    return 0;
}
