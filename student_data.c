#include <stdio.h>
#include <string.h>

#define MAX_BRANCH 100
#define MAX_NAME_LEN 50

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int year;
    float CGPA;
} Student;

void displayMenu();
void addStudent(Student inventory[], int *studentCount);
void removeStudent(Student inventory[], int *studentCount);
void listStudents(Student inventory[], int studentCount);
void searchStudent(Student inventory[], int studentCount);
void saveToFile(Student inventory[], int studentCount);
void loadFromFile(Student inventory[], int *studentCount);

int main() {
    Student inventory[MAX_BRANCH];
    int studentCount = 0;
    int choice;

    loadFromFile(inventory, &studentCount);

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(inventory, &studentCount);
                break;
            case 2:
                removeStudent(inventory, &studentCount);
                break;
            case 3:
                listStudents(inventory, studentCount);
                break;
            case 4:
                searchStudent(inventory, studentCount);
                break;
            case 5:
                saveToFile(inventory, studentCount);
                printf("Data saved successfully.\n");
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\n---- College Management System ----\n");
    printf("1. Add Student\n");
    printf("2. Remove Student\n");
    printf("3. List All Students\n");
    printf("4. Search Student\n");
    printf("5. Save Data\n");
    printf("6. Exit\n");
}

void addStudent(Student inventory[], int *studentCount) {
    if (*studentCount >= MAX_BRANCH) {
        printf("Inventory is full! Cannot add more students.\n");
        return;
    }

    printf("Enter student ID: ");
    scanf("%d", &inventory[*studentCount].id);

    printf("Enter student name: ");
    getchar();
    fgets(inventory[*studentCount].name, MAX_NAME_LEN, stdin);
    inventory[*studentCount].name[strcspn(inventory[*studentCount].name, "\n")] = '\0';

    printf("Enter year: ");
    scanf("%d", &inventory[*studentCount].year);

    printf("Enter CGPA: ");
    scanf("%f", &inventory[*studentCount].CGPA);

    (*studentCount)++;
    printf("Student added successfully.\n");
}

void removeStudent(Student inventory[], int *studentCount) {
    int id, found = 0;
    printf("Enter student ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < *studentCount; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < *studentCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*studentCount)--;
            printf("Student removed successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

void listStudents(Student inventory[], int studentCount) {
    if (studentCount == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n---- List of Students ----\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d | Name: %s | Year: %d | CGPA: %.2f\n", inventory[i].id, inventory[i].name, inventory[i].year, inventory[i].CGPA);
    }
}

void searchStudent(Student inventory[], int studentCount) {
    int choice;
    printf("Search by: \n1. ID\n2. Name\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int id, found = 0;
        printf("Enter student ID: ");
        scanf("%d", &id);

        for (int i = 0; i < studentCount; i++) {
            if (inventory[i].id == id) {
                printf("Student found: ID: %d | Name: %s | Year: %d | CGPA: %.2f\n", inventory[i].id, inventory[i].name, inventory[i].year, inventory[i].CGPA);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Student with ID %d not found.\n", id);
        }
    } else if (choice == 2) {
        char name[MAX_NAME_LEN];
        int found = 0;
        printf("Enter student name: ");
        getchar();
        fgets(name, MAX_NAME_LEN, stdin);
        name[strcspn(name, "\n")] = '\0';

        for (int i = 0; i < studentCount; i++) {
            if (strstr(inventory[i].name, name) != NULL) {
                printf("Student found: ID: %d | Name: %s | Year: %d | CGPA: %.2f\n", inventory[i].id, inventory[i].name, inventory[i].year, inventory[i].CGPA);
                found = 1;
            }
        }

        if (!found) {
            printf("No student found with the name '%s'.\n", name);
        }
    } else {
        printf("Invalid choice.\n");
    }
}

void saveToFile(Student inventory[], int studentCount) {
    FILE *file = fopen("inventory.dat", "wb");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    fwrite(&studentCount, sizeof(int), 1, file);
    fwrite(inventory, sizeof(Student), studentCount, file);
    fclose(file);
}

void loadFromFile(Student inventory[], int *studentCount) {
    FILE *file = fopen("inventory.dat", "rb");
    if (!file) {
        printf("No saved data found.\n");
        return;
    }

    fread(studentCount, sizeof(int), 1, file);
    fread(inventory, sizeof(Student), *studentCount, file);
    fclose(file);
}

