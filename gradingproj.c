#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double input();
int students;
double get_mean(double a, double b, double c, double d, double e, double f);
char* get_grade(double mean);
void show(double mean, double total, char* grade);

int main() {
    double math, english, kisw, sci, sst, re, mean, total;
    char* grade_result;

    printf("\nHello.\tWelcome to KCPE Grading System.\n Enter number of students to be graded: ");
    scanf("%i", &students);

    while (students <= 0) {
        printf("The number of students must be greater than 0. Please try again: \n");
        scanf("%d", &students);
    }

    for (int i = 0; i < students; i++) {
        printf("Input marks for Math: ");
        math = input();

        printf("Input marks for English: ");
        english = input();

        printf("Input marks for Kiswahili: ");
        kisw = input();

        printf("Input marks for Science: ");
        sci = input();

        printf("Input marks for Social Studies: ");
        sst = input();

        printf("Input marks for Religious Education: ");
        re = input();

        mean = get_mean(math, english, kisw, sci, sst, re);
        total = math + english + kisw + sci + sst + re;
        grade_result = get_grade(mean);

        show(mean, total, grade_result);
    }
    return 0;
}

double input() {
    double marks;
    scanf("%lf", &marks);
    while (marks < 0 || marks > 100) {
        printf("Invalid Mark! Try again (marks should be between 0-100): ");
        scanf("%lf", &marks);
    }
    return marks;
}

double get_mean(double a, double b, double c, double d, double e, double f) {
    return (a + b + c + d + e + f) / 6;
}

char* get_grade(double mean) {
    if (mean >= 79)
        return "A";
    else if (mean >= 75)
        return "A-";
    else if (mean >= 70)
        return "B+";
    else if (mean >= 65)
        return "B";
    else if (mean >= 60)
        return "B-";
    else if (mean >= 55)
        return "C+";
    else if (mean >= 45)
        return "C";
    else if (mean >= 40)
        return "C-";
    else if (mean >= 35)
        return "D+";
    else if (mean >= 30)
        return "D";
    else if (mean >= 25)
        return "D-";
    else
        return "E";
}

void show(double mean, double total, char* grade) {
    printf("\nMean: %.3f, Grade: %s, Total: %.3f\n", mean, grade, total);
}
