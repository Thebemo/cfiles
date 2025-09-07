#include <stdio.h>

float calcGPA(float m1, float m2, float m3, float m4, float m5);

int main() {
    FILE *infile, *outfile;
    char id[10], fName[50];
    float m1, m2, m3, m4, m5;
    char file[50];

    printf("Enter file name: ");
    scanf("%s", file);

    infile = fopen(file, "r");
    if (infile == NULL) {
        printf("Error reading from file\n");
        return 1;
    }

    outfile = fopen("youse_cooked.txt", "w");
    if (outfile == NULL) {
        printf("Error writing to file\n");
        return 1;
    }

    // Read: ID, First Name, 5 marks
    while (fscanf(infile, "%s %s %f %f %f %f %f", id, fName, &m1, &m2, &m3, &m4, &m5) != EOF) {
        float gpa = calcGPA(m1, m2, m3, m4, m5);
        if (gpa >= 4.0)
            fprintf(outfile, "%s %.1f Goated\n", fName, gpa);
        else
            fprintf(outfile, "%s %.1f\n", fName, gpa);
    }

    fclose(infile);
    fclose(outfile);
    return 0;
}

float calcGPA(float m1, float m2, float m3, float m4, float m5) {
    float marks[] = {m1, m2, m3, m4, m5};
    float total = 0.0, gradePoint = 0.0;

    for (int i = 0; i < 5; i++) {
        float mark = marks[i];

        if (mark >= 80.0) gradePoint = 5.0;
        else if (mark >= 75.0) gradePoint = 4.5;
        else if (mark >= 70.0) gradePoint = 4.0;
        else if (mark >= 65.0) gradePoint = 3.5;
        else if (mark >= 60.0) gradePoint = 3.0;
        else if (mark >= 55.0) gradePoint = 2.5;
        else if (mark >= 50.0) gradePoint = 2.0;
        else gradePoint = 0.0;

        total += gradePoint * 3;  
    }

    return total / 15.0;  
}
