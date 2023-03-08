#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void add_student_record();
void student_records();
void search_student_records();
void delete_student_records();
void exit_student_record();

struct students
{
    char full_name[200];
    int roll;
    int class;
    char section;
    float marks_of_bangla;
    float marks_of_english;
    float marks_of_math;
    float total;
    float gpa;
    char grade[3];
} stdnt;

void main()
{
    int choice;

top:
    printf("\n\n\t\t\t\t\t==========STUDENTS INFORMATION==========\n\n\n");
    printf("\t\t\t\t\t 1. Add Student Record\n");
    printf("\t\t\t\t\t 2. Student Records\n");
    printf("\t\t\t\t\t 3. Search Student Records\n");
    printf("\t\t\t\t\t 4. Delete Student Records\n");
    printf("\t\t\t\t\t 5. Exit");
    printf("\n\n\t\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\tEnter your choice number: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        add_student_record();
        break;
    case 2:
        student_records();
        break;
    case 3:
        search_student_records();
        break;
    case 4:
        delete_student_records();
        break;
    case 5:
        exit_student_record();
        break;
    default:
        system("cls");
        printf("\n\n\t\t\t\t\t\tEnter a valid number\n\n");
        system("\t\t\t\t\t\t\tpause");
        system("cls");
        break;
    }

    goto top;
}

void add_student_record()
{
    system("cls");

    char answer;

    FILE *fptr;

    fptr = fopen("student_records.txt", "a");

    printf("\n\n\t\t\t\t\t==========ADD STUDENT'S INFORMATION==========\n\n");

    printf("\n\t\t\t\t\tName             : ");
    fflush(stdin);
    fgets(stdnt.full_name, 200, stdin);
    fputs(stdnt.full_name, fptr);

    printf("\n\t\t\t\t\tRoll No          : ");
    scanf("%d", &stdnt.roll);
    fprintf(fptr, "%d", stdnt.roll);

    printf("\n\t\t\t\t\tClass            : ");
    scanf("%d", &stdnt.class);
    fprintf(fptr, "%d", stdnt.class);

    printf("\n\t\t\t\t\tSection          : ");
    getchar();
    scanf("%c", &stdnt.section);
    stdnt.section = toupper(stdnt.section);
    fprintf(fptr, "%c", stdnt.section);

    printf("\n\t\t\t\t\tMarks of Bangla  : ");
    scanf("%f", &stdnt.marks_of_bangla);
    fprintf(fptr, "%.2f", stdnt.marks_of_bangla);

    printf("\n\t\t\t\t\tMarks of English : ");
    scanf("%f", &stdnt.marks_of_english);
    fprintf(fptr, "%.2f", stdnt.marks_of_english);

    printf("\n\t\t\t\t\tMarks of Math    : ");
    scanf("%f", &stdnt.marks_of_math);
    fprintf(fptr, "%.2f", stdnt.marks_of_math);

    stdnt.total = stdnt.marks_of_bangla + stdnt.marks_of_english + stdnt.marks_of_math;
    fprintf(fptr, "%.2f", stdnt.total);

    fclose(fptr);

    printf("\n\n\t\t\t\t\t______________________________________________");
    printf("\n\t\t\t\t\tStudent's Information Stored Successfully.");

    printf("\n\t\t\t\t\tDo you want to store another Student's Information?(y/n) ");
    getchar();

gotoInAddStudentsInfo:

    answer = getchar();

    if (answer == 'Y' || answer == 'y')
    {
        system("cls");
        add_student_record();
    }
    else if (answer == 'N' || answer == 'n')
    {
        system("cls");
    }
    else
    {
        printf("\n\n\t\t\t\t\tEnter a valid answer...");
        getchar();
        goto gotoInAddStudentsInfo;
    }
}

void student_records()
{
    system("cls");

    char ch, enterInStudentsRecord;

    FILE *fptr;

    fptr = fopen("student_records.txt", "r");

    printf("\n\n\t\t\t\t\t==========STUDENT RECORDS==========\n\n");

    while (fread(&stdnt, sizeof(stdnt), 1, fptr))
    {
        printf("\n\t\t\t\t\tName             : %s", stdnt.full_name);
        printf("\n\t\t\t\t\tRoll No          : %d", stdnt.roll);
        printf("\n\t\t\t\t\tClass            : %d", stdnt.class);
        printf("\n\t\t\t\t\tsection          : %c", stdnt.section);
        printf("\n\t\t\t\t\tMarks of Bangla  : %.2f", stdnt.marks_of_bangla);
        printf("\n\t\t\t\t\tMarks of English : %.2f", stdnt.marks_of_english);
        printf("\n\t\t\t\t\tMarks of Math    : %.2f", stdnt.marks_of_math);
        printf("\n\t\t\t\t\tTotal            : %.2f", stdnt.total);
    }

    fclose(fptr);

    printf("\n\n\t\t\t\t\tPress ENTER to go back....");
    getchar();
    scanf("%c", &enterInStudentsRecord);

gotoInStudentsRecord:

    if (enterInStudentsRecord == '\n')
    {
        system("cls");
    }
    else
    {
        printf("\n\t\t\t\t\tPress ENTER to go back....");
        getchar();
        scanf("%c", &enterInStudentsRecord);
        goto gotoInStudentsRecord;
    }
}

void search_student_records()
{
    system("cls");

    int roll;
    char enterInSearchStudentsRecord;

    FILE *fptr;

    fptr = fopen("student_records.txt", "r");

    printf("\n\n\t\t\t\t\t==========SEARCH STUDENT'S RECORDS==========\n\n");

    printf("\n\n\t\t\t\t\tEnter the Roll No: ");
    scanf("%d", &roll);

    while (fread(&stdnt, sizeof(struct students), 1, fptr))
    {

        if (stdnt.roll == roll)
        {
            printf("\n\t\t\t\t\tName             : %s", stdnt.full_name);
            printf("\n\t\t\t\t\tRoll No          : %d", stdnt.roll);
            printf("\n\t\t\t\t\tClass            : %d", stdnt.class);
            printf("\n\t\t\t\t\tsection          : %c", stdnt.section);
            printf("\n\t\t\t\t\tMarks of Bangla  : %.2f", stdnt.marks_of_bangla);
            printf("\n\t\t\t\t\tMarks of English : %.2f", stdnt.marks_of_english);
            printf("\n\t\t\t\t\tMarks of Math    : %.2f", stdnt.marks_of_math);
            printf("\n\t\t\t\t\tTotal            : %.2f", stdnt.total);
        }
    }

    fclose(fptr);

    printf("\n\n\t\t\t\t\tPress ENTER to go back....");
    getchar();
    scanf("%c", &enterInSearchStudentsRecord);

gotoInSearchStudentsRecord:

    if (enterInSearchStudentsRecord == '\n')
    {
        system("cls");
    }
    else
    {
        printf("\n\t\t\t\t\tPress ENTER to go back....");
        getchar();
        scanf("%c", &enterInSearchStudentsRecord);
        goto gotoInSearchStudentsRecord;
    }
}

void delete_student_records()
{
}

void exit_student_record()
{
}