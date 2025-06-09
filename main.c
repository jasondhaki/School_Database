#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#define student_count 200
struct school
{
    int id_no;
    char first_name[20], last_name[20];
    char gender;
    char phone[15];
    int dob_day, dob_month, dob_year;

};

//Database
struct school students[student_count];
int student_index = 0;

void Welcome_Screen();
void Starting_System();
void Continue_Exit();
void Menu();

//Menu
void Student_Registrations();
void Search_By_Name();
void Edit_Info();
void Delete_Info();
void View_All_Students();
void Exit();

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    system("cls");

    Welcome_Screen();
    //Register_Students();
    return 0;
}

void Welcome_Screen()
{
    printf("╔══════════════════════════════════════════════════╗\n");
    printf("║                                                  ║\n");
    printf("║       🎓  BACHA ENGLISH MEDIUM SCHOOL  🎓        ║\n");
    printf("║                                                  ║\n");
    printf("║       ✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨       ║\n");
    printf("║           🌟 STUDENT DATABASE SYSTEM 🌟          ║\n");
    printf("║       ✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨       ║\n");
    printf("║                                                  ║\n");
    printf("║           ➤  Student Registration                ║\n");
    printf("║           ➤  Search & Edit Student Info          ║\n");
    printf("║           ➤  Delete Student Records              ║\n");
    printf("║           ➤  View All Enrolled Students          ║\n");
    printf("║                                                  ║\n");
    printf("╚══════════════════════════════════════════════════╝\n");
    printf("             Enter any key to continue\n\n        ");
    getch();

    Starting_System();
    system("cls");
    Menu();
}

void Starting_System()
{
    //Delay affect
    printf("      Starting the system");
    for (int i = 0; i < 3; i++) 
    {
        Sleep(500); // Half-second delay
        printf(".");
    }
}

void Continue_Exit()
{
    int continue_choice;
    printf("   Do you want to Continue?\n");
    printf("   Yes [1] No [2]: ");
    scanf("%d", &continue_choice);
    if(continue_choice == 1)
    {
        system("cls");
        Menu();
    }
    else if(continue_choice == 2)
    {
        system("cls");
        Exit();
    }
}

void Menu()
{
    int menu_choice;
    printf("╔══════════════════════════════════════════╗\n");
    printf("║               SCHOOL PANEL               ║\n");
    printf("║══════════════════════════════════════════║\n");
    printf("║                                          ║\n");
    printf("║      [1]  📝 Student Registration        ║\n");
    printf("║      [2]  🔍 Search By Name              ║\n");
    printf("║      [3]  ✏️  Edit Student Info           ║\n");
    printf("║      [4]  🗑️  Delete Student Records      ║\n");
    printf("║      [5]  👁️  View All Students           ║\n");
    printf("║      [6]  ❌ Exit                        ║\n");
    printf("║                                          ║\n");
    printf("╚══════════════════════════════════════════╝\n");
    printf("\n\tUser Choice: ");
    scanf("%d", &menu_choice);
    system("cls");

    if(menu_choice == 1)
        Student_Registrations();
    else if(menu_choice == 2)
        Search_By_Name();
    else if(menu_choice == 3)
        Edit_Info();
    else if(menu_choice == 4)
        Delete_Info();
    else if(menu_choice == 5)
        View_All_Students();
    else if(menu_choice == 6)
        Exit();
}

void Student_Registrations()
{
    printf("\n\n🔷 🔷 🔷  Student Registration 🔷 🔷 🔷\n");
    printf("\n       ➤  Enter Student ID: ");
    scanf("%d", &students[student_index].id_no);
    getchar();
    printf("       ➤  Enter First Name: ");
    gets(students[student_index].first_name);
    printf("       ➤  Enter Last Name: ");
    gets(students[student_index].last_name);
    printf("       ➤  Enter Sex [M] or [F]: ");
    scanf(" %c", &students[student_index].gender);
    printf("       ➤  Enter Birth Year: ");
    scanf("%d", &students[student_index].dob_year);
    printf("       ➤  Enter Birth Month: ");
    scanf("%d", &students[student_index].dob_month);
    printf("       ➤  Enter Birth Day: ");
    scanf("%d", &students[student_index].dob_day);
    getchar();
    printf("       ➤  Enter Phone No: ");
    gets(students[student_index].phone);

    printf("\n   ✅  Student Registration Complete\n\n");
    student_index++;
    Continue_Exit();
}

void Search_By_Name()
{
    printf("\n\n🔷 🔷 🔷  Search By Name 🔷 🔷 🔷\n");
    char search_name[20];
    int found = 0;
    printf("Enter Student Name: ");
    getchar();
    gets(search_name);
    
    for(int i = 0; i<student_index; i++)
    {
        if(strcmp(search_name, students[i].first_name) == 0)
        {
            found = 1;
            printf("\n   ✅  Student Info Found\n\n");
            printf("   Student ID: %d\n", students[i].id_no);
            printf("   First Name: %s\n", students[i].first_name);
            printf("   Last Name: %s\n", students[i].last_name);
            if(students[i].gender == 'M')
                printf("   Student Gender: Male\n");
            else
                printf("   Student Gender: Female\n");
            printf("   Date of Birth: %d ", students[i].dob_day);
            if(students[i].dob_month == 1)
                printf("Jan ");
            else if(students[i].dob_month == 2)
                printf("Feb ");
            else if(students[i].dob_month == 3)
                printf("Mar ");
            else if(students[i].dob_month == 4)
                printf("Apr ");
            else if(students[i].dob_month == 5)
                printf("May ");
            else if(students[i].dob_month == 6)
                printf("Jun ");
            else if(students[i].dob_month == 7)
                printf("Jul ");
            else if(students[i].dob_month == 8)
                printf("Aug ");
            else if(students[i].dob_month == 9)
                printf("Sep ");
            else if(students[i].dob_month == 10)
                printf("Oct ");
            else if(students[i].dob_month == 11)
                printf("Nov ");
            else if(students[i].dob_month == 12)
                printf("Dec ");
            printf("%d\n", students[i].dob_year);
            printf("   Phone No: %s\n\n", students[i].phone);
        }   
    }

    if(found == 0)
        printf("\n   🚫  Student Info Not Found\n\n");

    Continue_Exit();
}

void Edit_Info()
{
    int id, found = 0, user_input;
    printf("\n\n🔷 🔷 🔷  Edit Information 🔷 🔷 🔷\n\n");
    printf("   Enter ID: ");
    scanf("%d", &id);

    for(int i = 0; i<student_count; i++)
    {
        if(id == students[i].id_no)
        {
            found = 1;
            printf("\n   ✅  Student Info Found\n\n");
            printf("   Please Input Changes\n");
            printf("   [1] First Name\n");
            printf("   [2] Last Name\n");
            printf("   [3] Sex\n");
            printf("   [4] Birth Year\n");
            printf("   [5] Birth Month\n");
            printf("   [6] Birth Day\n");
            printf("   [7] Phone Number\n\n");
            
            do
            {
                printf("   Input: ");
                scanf("%d", &user_input);

                //Changes
                if(user_input == 1)
                {
                    printf("   Enter New First Name: ");
                    getchar();
                    gets(students[i].first_name);
                }

                else if(user_input == 2)
                {
                    printf("   Enter New Last Name: ");
                    getchar();
                    gets(students[i].last_name);
                }

                else if(user_input == 3)
                {
                    printf("   Enter New Sex [M] or [F]: ");
                    scanf(" %c", &students[i].gender);
                }

                else if(user_input == 4)
                {
                    printf("   Enter New Birth Year: ");
                    scanf("%d", &students[i].dob_year);
                }

                else if(user_input == 5)
                {
                    printf("   Enter New Birth Month: ");
                    scanf("%d", &students[i].dob_month);
                }

                else if(user_input == 6)
                {
                    printf("   Enter New Birth Day: ");
                    scanf("%d", &students[i].dob_day);
                }

                else if(user_input == 7)
                {
                    getchar();
                    printf("   Enter New Phone Number: ");
                    gets(students[i].phone);
                }

                if(user_input < 1 && user_input > 7)
                    printf("   Invalid Input!\n");
            } while (user_input < 1 || user_input > 7);
            
            
        }
    }

    if(found == 0)
        printf("\n   🚫  Student Info Not Found\n\n");

    Continue_Exit();
}

void Delete_Info()
{
    int id, found = 0;
    printf("\n\n🔷 🔷 🔷  Delete Information 🔷 🔷 🔷\n\n");
    printf("   Enter ID: ");
    scanf("%d", &id);

    for(int i = 0; i<student_index; i++)
    {
        if(students[i].id_no = id)
        {
            found = 1;
            printf("\n   ✅  Student Found: %s %s (ID: %d)\n\n", students[i].first_name, students[i].last_name, students[i].id_no);
            
            char confirmation;
            printf("   Are you sure you want to delete Information? Yes[Y] No[N]: ");
            scanf(" %c", &confirmation);

            if(confirmation == 'Y')
            {
                for(int j = i; j<student_index-1; j++)
                {
                    students[j] = students[j+1];
                }

                student_index--;
                printf("\n   🗑️  Student record deleted successfully!\n");
            }

            else
                printf("\n   ❌  Deletion canceled\n");
            break;
        }
    }

    if(found == 0)
         printf("\n   🚫  Student with ID %d not found!\n", id);

    Continue_Exit();
}

void View_All_Students()
{
    printf("\n\n🔷 🔷 🔷  All Student Information 🔷 🔷 🔷\n\n");

    printf("No.    ID        First Name       Last Name       Gender        Date of Birth     Phone No.\n");
    printf("-------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < student_index; i++)
    {
        printf("%-6d ", i + 1);                          // Serial number
        printf("%-9d ", students[i].id_no);            // ID
        printf("%-16s ", students[i].first_name);       // First Name
        printf("%-15s ", students[i].last_name);        // Last Name

        if (students[i].gender == 'M')
            printf("%-6s ", "Male");
        else
            printf("%s ", "Female");

        printf("%9d ", students[i].dob_day);           // Day

        if (students[i].dob_month == 1)
            printf("Jan ");
        else if (students[i].dob_month == 2)
            printf("Feb ");
        else if (students[i].dob_month == 3)
            printf("Mar ");
        else if (students[i].dob_month == 4)
            printf("Apr ");
        else if (students[i].dob_month == 5)
            printf("May ");
        else if (students[i].dob_month == 6)
            printf("Jun ");
        else if (students[i].dob_month == 7)
            printf("Jul ");
        else if (students[i].dob_month == 8)
            printf("Aug ");
        else if (students[i].dob_month == 9)
            printf("Sep ");
        else if (students[i].dob_month == 10)
            printf("Oct ");
        else if (students[i].dob_month == 11)
            printf("Nov ");
        else if (students[i].dob_month == 12)
            printf("Dec ");

        printf("%d ", students[i].dob_year);          // Year
        printf("%17s", students[i].phone);             // Phone

        printf("\n");
    }

    Continue_Exit();
}

void Exit()
{
    printf("╔═════════════════════════════════════════╗\n");
    printf("║  ✨ Thank You For Using Our System ✨   ║\n");
    printf("╚═════════════════════════════════════════╝\n");
}