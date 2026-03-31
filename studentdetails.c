#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    int age;
};


void display(struct Student s[], int n) {
    printf("\nStudents with age >= 20:\n");
    for (int i = 0; i < n; i++) {
        if (s[i].age >= 20) {
            printf("%d %s %d\n", s[i].roll, s[i].name, s[i].age); 
        }
    }
}

int main() {
    struct Student s[5];

    printf("Enter details of 5 students:\n");

    for (int i = 0; i < 5; i++) {
        printf("\nStudent %d:\n", i + 1);

        printf("Enter roll number: ");
        scanf("%d", &s[i].roll);

        getchar();  

        printf("Enter name: ");
        fgets(s[i].name, 50, stdin);

        s[i].name[strcspn(s[i].name, "\n")] = '\0';

        printf("Enter age: ");
        scanf("%d", &s[i].age);
    }

    display(s, 5);

    return 0;
}