#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    char name[50];
    int roll;
    float marks[3];
    float percentage;
    char grade;
};

// Global list
struct Student students[MAX];
int count = 0;

// Function to calculate grade
char calculateGrade(float p) {
    if (p >= 90) return 'A';
    else if (p >= 80) return 'B';
    else if (p >= 70) return 'C';
    else if (p >= 60) return 'D';
    else if (p >= 50) return 'E';
    else return 'F';
}

void addStudent() {
    if (count >= MAX) {
        printf("Max students reached!\n");
        return;
    }

    struct Student s;
    printf("Enter name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter roll number: ");
    scanf("%d", &s.roll);

    float total = 0;

    for (int i = 0; i < 3; i++) {
        do {
            printf("Enter marks %d (0-100): ", i + 1);
            scanf("%f", &s.marks[i]);
        } while (s.marks[i] < 0 || s.marks[i] > 100);
        total += s.marks[i];
    }

    s.percentage = total / 3.0;
    s.grade = calculateGrade(s.percentage);

    students[count++] = s;
    printf("\nStudent Added!\n\n");
}

void displayAll() {
    printf("\n----- Student Records -----\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s | Roll: %d | Percentage: %.2f | Grade: %c\n",
               i + 1, students[i].name, students[i].roll,
               students[i].percentage, students[i].grade);
    }
}

void searchByRoll() {
    int r;
    printf("Enter roll to search: ");
    scanf("%d", &r);

    for (int i = 0; i < count; i++) {
        if (students[i].roll == r) {
            printf("Found: %s | %.2f%% | Grade %c\n", students[i].name,
                   students[i].percentage, students[i].grade);
            return;
        }
    }
    printf("Roll not found!\n");
}

void searchByName() {
    char name[50];
    printf("Enter name to search: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Found: Roll %d | %.2f%% | Grade %c\n",
                   students[i].roll, students[i].percentage, students[i].grade);
            return;
        }
    }
    printf("Name not found!\n");
}

void findByGrade() {
    char g;
    printf("Enter grade to filter: ");
    scanf(" %c", &g);

    printf("\nStudents with Grade %c:\n", g);
    for (int i = 0; i < count; i++) {
        if (students[i].grade == g) {
            printf("%s | %.2f%%\n", students[i].name, students[i].percentage);
        }
    }
}

void classAverage() {
    float avg = 0;

    for (int i = 0; i < count; i++) {
        avg += students[i].percentage;
    }
    avg /= count;

    printf("\nClass Average = %.2f\n", avg);

    printf("\nAbove Average:\n");
    for (int i = 0; i < count; i++)
        if (students[i].percentage > avg)
            printf("%s | %.2f\n", students[i].name, students[i].percentage);

    printf("\nBelow Average:\n");
    for (int i = 0; i < count; i++)
        if (students[i].percentage < avg)
            printf("%s | %.2f\n", students[i].name, students[i].percentage);
}

void rankList() {
    struct Student temp;

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (students[j].percentage > students[i].percentage) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    printf("\n----- Rank List -----\n");
    for (int i = 0; i < count; i++) {
        printf("%d) %s | %.2f%%\n", i + 1, students[i].name, students[i].percentage);
    }
}

int main() {
    int choice;

    do {
        printf("\n===== STUDENT RECORD MENU =====\n");
        printf("1. Add Student\n2. Display All\n3. Search By Roll\n4. Search By Name\n5. Find By Grade\n6. Class Average\n7. Rank List\n8. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchByRoll(); break;
            case 4: searchByName(); break;
            case 5: findByGrade(); break;
            case 6: classAverage(); break;
            case 7: rankList(); break;
        }
    } while (choice != 8);

    return 0;
}
