#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void add_student_record();
void student_records();
void search_student_records();
void delete_student_records();

struct students
{
    char full_name[100];
    int roll;
    int class;
    char section;
    struct subjects
    {
        float marks_of_bangla;
        float marks_of_english;
        float marks_of_math;
    } subj;
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
        exit(1);
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

    fptr = fopen("student_records.txt", "ab");

    if (fptr == NULL)
    {
        char ext;
        printf("An Error Occurred\n\n");
        printf("\n\n\t\t\t\t\tPress ENTER to exit....");
        scanf("%c", &ext);
    gotoInIfStatementIfFptrIsNULL:
        if (ext == '\n')
        {
            exit(1);
        }
        else
        {
            printf("\n\n\t\t\t\t\tPress ENTER to exit....");
            scanf("%c", &ext);
            goto gotoInIfStatementIfFptrIsNULL;
        }
    }

    printf("\n\n\t\t\t\t\t==========ADD STUDENT'S RECORD==========\n\n");

    printf("\n\t\t\t\t\tName             : ");
    getchar();
    fgets(stdnt.full_name, sizeof(stdnt.full_name), stdin);
    stdnt.full_name[strcspn(stdnt.full_name, "\n")] = '\0';
    printf("\n\t\t\t\t\tRoll No          : ");
    scanf("%d", &stdnt.roll);
    printf("\n\t\t\t\t\tClass            : ");
    scanf("%d", &stdnt.class);
    printf("\n\t\t\t\t\tSection          : ");
    getchar();
    scanf("%c", &stdnt.section);
    stdnt.section = toupper(stdnt.section);
    printf("\n\t\t\t\t\tMarks of Bangla  : ");
    scanf("%f", &stdnt.subj.marks_of_bangla);
    printf("\n\t\t\t\t\tMarks of English : ");
    scanf("%f", &stdnt.subj.marks_of_english);
    printf("\n\t\t\t\t\tMarks of Math    : ");
    scanf("%f", &stdnt.subj.marks_of_math);

    stdnt.total = stdnt.subj.marks_of_bangla + stdnt.subj.marks_of_english + stdnt.subj.marks_of_math;

    fwrite(&stdnt, sizeof(stdnt), 1, fptr);

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

    char enterInStudentsRecord;

    FILE *fptr;

    fptr = fopen("student_records.txt", "rb");

    if (fptr == NULL)
    {
        char ext;
        printf("An Error Occurred\n\n");
        printf("\n\n\t\t\t\t\tPress ENTER to exit....");
        scanf("%c", &ext);
    gotoInIfStatementIfFptrIsNULL:
        if (ext == '\n')
        {
            exit(1);
        }
        else
        {
            printf("\n\n\t\t\t\t\tPress ENTER to exit....");
            scanf("%c", &ext);
            goto gotoInIfStatementIfFptrIsNULL;
        }
    }

    printf("\n\n\t\t\t\t\t==========STUDENT RECORDS==========\n\n");

    while (fread(&stdnt, sizeof(stdnt), 1, fptr))
    {
        printf("\n\t\t\t\t\tName             : %s", stdnt.full_name);
        printf("\n\n\t\t\t\t\tRoll No          : %d", stdnt.roll);
        printf("\n\n\t\t\t\t\tClass            : %d", stdnt.class);
        printf("\n\n\t\t\t\t\tsection          : %c", stdnt.section);
        printf("\n\n\t\t\t\t\tMarks of Bangla  : %.2f", stdnt.subj.marks_of_bangla);
        printf("\n\n\t\t\t\t\tMarks of English : %.2f", stdnt.subj.marks_of_english);
        printf("\n\n\t\t\t\t\tMarks of Math    : %.2f", stdnt.subj.marks_of_math);
        printf("\n\n\t\t\t\t\tTotal            : %.2f", stdnt.total);
        printf("\n\n\t\t\t\t\t______________________________________________\n\n\n");
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

    fptr = fopen("student_records.txt", "rb");

    if (fptr == NULL)
    {
        char ext;
        printf("An Error Occurred\n\n");
        printf("\n\n\t\t\t\t\tPress ENTER to exit....");
        scanf("%c", &ext);
    gotoInIfStatementIfFptrIsNULL:
        if (ext == '\n')
        {
            exit(1);
        }
        else
        {
            printf("\n\n\t\t\t\t\tPress ENTER to exit....");
            scanf("%c", &ext);
            goto gotoInIfStatementIfFptrIsNULL;
        }
    }

    printf("\n\n\t\t\t\t\t==========SEARCH STUDENT'S RECORD==========\n\n");

    printf("\n\n\t\t\t\t\tEnter the Roll No: ");
    scanf("%d", &roll);

    while (fread(&stdnt, sizeof(stdnt), 1, fptr))
    {
        if (stdnt.roll == roll)
        {
            printf("\n\t\t\t\t\tName             : %s", stdnt.full_name);
            printf("\n\n\t\t\t\t\tRoll No          : %d", stdnt.roll);
            printf("\n\n\t\t\t\t\tClass            : %d", stdnt.class);
            printf("\n\n\t\t\t\t\tsection          : %c", stdnt.section);
            printf("\n\n\t\t\t\t\tMarks of Bangla  : %.2f", stdnt.subj.marks_of_bangla);
            printf("\n\n\t\t\t\t\tMarks of English : %.2f", stdnt.subj.marks_of_english);
            printf("\n\n\t\t\t\t\tMarks of Math    : %.2f", stdnt.subj.marks_of_math);
            printf("\n\n\t\t\t\t\tTotal            : %.2f", stdnt.total);
            printf("\n\n\t\t\t\t\t______________________________________________");
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
    system("cls");

    int rollUWantToDelete;
    char enterInDeleteStudentsRecord;

    FILE *fptr, *fptrTemp;

    fptr = fopen("student_records.txt", "rb");
    fptrTemp = fopen("temp.txt", "ab");

    if (fptr == NULL)
    {
        char ext;
        printf("An Error Occurred\n\n");
        printf("\n\n\t\t\t\t\tPress ENTER to exit....");
        scanf("%c", &ext);
    gotoInIfStatementIfFptrIsNULL:
        if (ext == '\n')
        {
            exit(1);
        }
        else
        {
            printf("\n\n\t\t\t\t\tPress ENTER to exit....");
            scanf("%c", &ext);
            goto gotoInIfStatementIfFptrIsNULL;
        }
    }

    printf("\n\n\t\t\t\t\t==========DELETE STUDENT'S RECORD==========\n\n");

    printf("\n\n\t\t\t\t\tEnter the Roll No that you want to delete: ");
    scanf("%d", &rollUWantToDelete);

    while (fread(&stdnt, sizeof(stdnt), 1, fptr))
    {
        if (stdnt.roll == rollUWantToDelete)
        {
            printf("\n\t\t\t\t\tName             : %s", stdnt.full_name);
            printf("\n\n\t\t\t\t\tRoll No          : %d", stdnt.roll);
            printf("\n\n\t\t\t\t\tClass            : %d", stdnt.class);
            printf("\n\n\t\t\t\t\tsection          : %c", stdnt.section);
            printf("\n\n\t\t\t\t\tMarks of Bangla  : %.2f", stdnt.subj.marks_of_bangla);
            printf("\n\n\t\t\t\t\tMarks of English : %.2f", stdnt.subj.marks_of_english);
            printf("\n\n\t\t\t\t\tMarks of Math    : %.2f", stdnt.subj.marks_of_math);
            printf("\n\n\t\t\t\t\tTotal            : %.2f", stdnt.total);
            printf("\n\n\t\t\t\t\t______________________________________________\n\n\n");
        }

        if (stdnt.roll != rollUWantToDelete)
        {
            fwrite(&stdnt, sizeof(stdnt), 1, fptrTemp);
        }
    }

    fclose(fptr);
    fclose(fptrTemp);

    remove("student_records.txt");
    rename("temp.txt", "student_records.txt");

    printf("\n\n\t\t\t\t\tRecord deleted succesfully....");

    printf("\n\n\t\t\t\t\tPress ENTER to go back....");
    getchar();
    scanf("%c", &enterInDeleteStudentsRecord);

gotoInDeleteStudentsRecord:

    if (enterInDeleteStudentsRecord == '\n')
    {
        system("cls");
    }
    else
    {
        printf("\n\t\t\t\t\tPress ENTER to go back....");
        getchar();
        scanf("%c", &enterInDeleteStudentsRecord);
        goto gotoInDeleteStudentsRecord;
    }
}