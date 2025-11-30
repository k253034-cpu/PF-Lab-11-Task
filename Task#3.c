#include <stdio.h>
#include <string.h>

#define MAX 100

struct Employee {
    int id;
    char name[50];
    char department[20];
    char designation[20];
    float salary;
    int joiningYear;
};

struct Employee emp[MAX];
int count = 0;

int experience(int year) {
    return 2025 - year;
}

void addEmployee() {
    struct Employee e;

    printf("Enter Employee ID: ");
    scanf("%d", &e.id);

    printf("Enter Name: ");
    scanf(" %[^\n]", e.name);

    printf("Enter Department (IT/HR/Finance/Marketing/Operations): ");
    scanf("%s", e.department);

    printf("Enter Designation (Intern/Junior/Senior/Manager/Director): ");
    scanf("%s", e.designation);

    printf("Enter Salary: ");
    scanf("%f", &e.salary);

    printf("Enter Joining Year: ");
    scanf("%d", &e.joiningYear);

    emp[count++] = e;
    printf("Employee Added!\n");
}

void displayAll() {
    printf("\n----- ALL EMPLOYEES -----\n");
    for (int i = 0; i < count; i++) {
        printf("%d) %s | %s | %s | %.2f | Joined: %d | Exp: %d yrs\n",
               emp[i].id, emp[i].name, emp[i].department,
               emp[i].designation, emp[i].salary,
               emp[i].joiningYear, experience(emp[i].joiningYear));
    }
}

void searchDept() {
    char dept[20];
    printf("Enter Department: ");
    scanf("%s", dept);

    printf("\nEmployees in %s:\n", dept);
    for (int i = 0; i < count; i++)
        if (strcmp(emp[i].department, dept) == 0)
            printf("%s | %s | %.2f\n",
                   emp[i].name, emp[i].designation, emp[i].salary);
}

void searchDesignation() {
    char des[20];
    printf("Enter Designation: ");
    scanf("%s", des);

    printf("\nEmployees with %s:\n", des);
    for (int i = 0; i < count; i++)
        if (strcmp(emp[i].designation, des) == 0)
            printf("%s | %s | %.2f\n",
                   emp[i].name, emp[i].department, emp[i].salary);
}

void searchExperience() {
    int exp;
    printf("Minimum experience (years): ");
    scanf("%d", &exp);

    printf("\nEmployees with >= %d years:\n", exp);
    for (int i = 0; i < count; i++)
        if (experience(emp[i].joiningYear) >= exp)
            printf("%s | %s | %.2f | %d years\n",
                   emp[i].name, emp[i].designation, emp[i].salary,
                   experience(emp[i].joiningYear));
}

void departmentStats() {
    char dept[20];
    printf("Enter Department: ");
    scanf("%s", dept);

    float total = 0;
    int c = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(emp[i].department, dept) == 0) {
            total += emp[i].salary;
            c++;
        }
    }

    if (c == 0) {
        printf("No employees found!\n");
        return;
    }

    printf("Average Salary in %s = %.2f\n", dept, total / c);
}

void promotionList() {
    printf("\nEmployees Eligible for Promotion (>3 years):\n");
    for (int i = 0; i < count; i++)
        if (experience(emp[i].joiningYear) > 3)
            printf("%s | %s | Exp: %d yrs\n",
                   emp[i].name, emp[i].designation,
                   experience(emp[i].joiningYear));
}

void appraisal() {
    int id;
    float inc;
    printf("Enter Employee ID: ");
    scanf("%d", &id);

    printf("Increment percentage (5–15): ");
    scanf("%f", &inc);

    for (int i = 0; i < count; i++) {
        if (emp[i].id == id) {
            emp[i].salary += emp[i].salary * (inc / 100.0);
            printf("New Salary = %.2f\n", emp[i].salary);
            return;
        }
    }
    printf("Employee not found!\n");
}

int main() {
    int ch;

    do {
        printf("\n===== EMPLOYEE MENU =====\n");
        printf("1. Add Employee\n2. Display All\n3. Search Dept\n4. Search Designation\n5. Search Experience\n6. Dept Salary Stats\n7. Promotion List\n8. Appraisal\n9. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: addEmployee(); break;
            case 2: displayAll(); break;
            case 3: searchDept(); break;
            case 4: searchDesignation(); break;
            case 5: searchExperience(); break;
            case 6: departmentStats(); break;
            case 7: promotionList(); break;
            case 8: appraisal(); break;
        }

    } while (ch != 9);

    return 0;
}
