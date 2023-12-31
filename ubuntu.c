#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int id, nbrj;
} JourRest;
// creation de la structure de date;
typedef struct
{
    int year, month, day;

} date;
// creation de la structures de tesk
typedef struct
{
    int id;
    char title[50];
    char description[200];
    char statut[50];
    date deadline;
} task;

// Decalration des variables global
task t[100];
int choice, total = 0, statut_num, task_num, sorting_choice, id_searching, id_updating, nbr_incomplet = 0, complet = 0;
char title_searching[50];

// CLEAN
// add a new task
void addTask()
{
    t[total].id = total + 1;
    printf("\e[1;1H\e[2J");
    printf("\n-------------------------------| Task N %d |-------------------------------\n\n", total + 1);

    printf("Please enter the task title :\n\t>>>>>\t");
    scanf(" %[^\n]", t[total].title);

    printf("\nPlease put the task descrpion :\n\t>>>>>\t");
    scanf(" %[^\n]", t[total].description);

    printf("Please choose one of this status using numbers : \n");
    printf("\n\t[1]==> 'To Do' \n\t[2]==> 'Doing' \n\t[3]==> 'Done'\n");
    while (1)
    {
        printf("\nPlease choose a number : \n\t>>>>>\t");
        scanf("%d", &statut_num);

        if (statut_num == 1)
        {
            strcpy(t[total].statut, "To Do");
            break;
        }
        else if (statut_num == 2)
        {
            strcpy(t[total].statut, "Doing");
            break;
        }
        else if (statut_num == 3)
        {
            strcpy(t[total].statut, "Done");
            break;
        }
        else
        {
            printf("Oops, This choice not exist, Please try again !!! \n");
        }
    }
    printf("Please enter the task date (day/month/year):  \n\t>>>>>\t");
    scanf("%d/%d/%d", &t[total].deadline.day, &t[total].deadline.month, &t[total].deadline.year);

    printf("\t\t\tTask added succesflly 😀️ !!! \n");
    total++;
}

// CLEAN ALSO

void addMultipleTasks()
{
    printf("\tHow many tasks you want add : \t");
    scanf("%d", &task_num);
    for (int i = 1; i <= task_num; i++)
    {
        addTask();
    }
}

// I CLEAN THIS
void sortTasksByID()
{
    // Affichage de la te de tâches triée
    printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");
    printf("| ID |     Task Title          |          Description          |  Deadline Date   |        Statut        |\n");
    printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");

    for (int i = 0; i < total; i++)
    {
        printf("| %-2d | %-25s | %-31s | %04d-%02d-%02d | %-23s |\n", t[i].id, t[i].title, t[i].description, t[i].deadline.year, t[i].deadline.month, t[i].deadline.day, t[i].statut);
        printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");
    }
}

void sortTasksAlphabetically()
{
    task temp;
    for (int i = 0; i < total - 1; i++)
    {
        for (int j = 0; j < total - i - 1; j++)
        {
            if (strcmp(t[j].title, t[j + 1].title) > 0)
            {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
    printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");
    printf("| ID |     Task Title          |          Description          |  Deadline Date   |        Statut        |\n");
    printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");

    for (int j = 0; j < total; j++)
    {
        printf("| %-2d | %-25s | %-31s | %04d-%02d-%02d | %-23s |\n", t[j].id, t[j].title, t[j].description, t[j].deadline.year, t[j].deadline.month, t[j].deadline.day, t[j].statut);
        printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");
    }
}
// searching
void searching_id()
{
    int checker = 0;
    printf("Please enter Task ID to search : \t");
    scanf("%d", &id_searching);
    for (int i = 0; i <= total; i++)
    {
        if (id_searching == t[i].id)
        {
            checker = 1;
            printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");
            printf("| ID |     Task Title          |          Description          |  Deadline Date   |        Statut        |\n");
            printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");

            printf("| %-2d | %-25s | %-31s | %04d-%02d-%02d | %-23s |\n", t[i].id, t[i].title, t[i].description, t[i].deadline.year, t[i].deadline.month, t[i].deadline.day, t[i].statut);
            printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");
            break;
        }
        else
        {
            checker = 0;
        }
    }
    if (checker == 0)
    {
        printf("ID doesn't exist !!! \n");
    }
}
void searching_title()
{
    int checker = 0;
    printf("Please enter task title to search : \t");
    scanf(" %[^\n]", title_searching);

    printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");
    printf("| ID |     Task Title          |          Description          |  Deadline Date   |        Statut        |\n");
    printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");

    for (int i = 0; i < total; i++)
    {
        if (strcmp(title_searching, t[i].title) == 0)
        {
            checker = 1;
            printf("| %-2d | %-25s | %-31s | %04d-%02d-%02d | %-23s |\n", t[i].id, t[i].title, t[i].description, t[i].deadline.year, t[i].deadline.month, t[i].deadline.day, t[i].statut);
        }
    }
    if (checker == 0)
    {
        printf("No tasks with this title were found.\n");
    }
}
void updating_task()
{
    int check = 0;
    printf("\n\n Please enter ID to modify: ");
    scanf("%d", &id_updating);
    for (int i = 0; i <= total; i++)
    {
        if (id_updating == t[i].id)
        {
            check = 1;
            // Affichage de la liste de tâches triée
            printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");
            printf("| ID |     Title     |          Description          |  Deadline |        Status        |\n");
            printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");

            printf("| %-2d | %-25s | %-31s | %04d-%02d-%02d | %-23s |\n", t[i].id, t[i].title, t[i].description, t[i].deadline.year, t[i].deadline.month, t[i].deadline.day, t[i].statut);
            printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");

            printf("\tPlease to fill the informations to modify the task\n");

            printf("Enter new title :\t");
            scanf(" %[^\n]", t[i].title);

            printf("Enter new description  :\t");
            scanf(" %[^\n]", t[i].description);

            printf("\t[1]==> To Do \n\t [2]==> Doing \n\t [3]==> Done\n");
            printf("Enter your choice : \n");
            scanf("%d", &statut_num);

            //      cette condition remplit la variable statut ca depent le choix de l'utilisateur
            if (statut_num == 1)
            {
                strcpy(t[i].statut, "To Do");
            }
            else if (statut_num == 2)
            {
                strcpy(t[i].statut, "Doing");
            }
            else if (statut_num == 3)
            {
                strcpy(t[i].statut, "Done");
            }
            else
            {
                printf("Invalid choice !!! \n");
            }
            printf("Enter the new deadline :   ");
            scanf("%d/%d/%d", &t[i].deadline.day, &t[i].deadline.month, &t[i].deadline.year);
            break;
        }
    }
    if (check == 0)
    {
        printf("ID doesn't exist !!!  \n");
    }
}
void count_status()
{
    for (int i = 0; i <= total; i++)
    {
        if (t[i].statut == "To Do" || t[i].statut == "Doing")
        {
            nbr_incomplet++;
        }else if (t[i].statut == "Done"){
            complet++;
        }
    }
}

// static function
void static_func()
{
    printf("The number of incomplete tasks is  : \t%d \n", nbr_incomplet);
    printf("The number of complete tasks is : \t%d", complet);
}
// delete tasks
void delete_task()
{
    int p, q, id;
    int verifier;
    printf("Please enter task ID to delete : ");
    scanf("%d", &id);
// here where the compiler gonna get back to
here:

    printf("Comfirm with (1 / 0): \n");
    scanf("%d", &verifier);
    if (verifier == 1)
    {
        for (p = 0; p < total; p++)
        {
            if (t[p].id == id)
            {
                printf("FOUND\n\n");
                for (q = p; q < total - 1; q++)
                {
                    t[p] = t[q + 1];
                    p++;
                }
                total--;

                printf("\tTask deleted successfully 😀️ !!! \n\n");
            }
        }
    }
    else if (verifier == 0)
    {
        printf("\t\t\tOperation canceled 🙃️ !!!\n\n");
    }
    else
    {
        printf("\e[1;1H\e[2J");
        printf("\t\t\tInvalid value, Try again \n");
        goto here;
    }
}

void remaining_sort()
{
    time_t currentTime;
    struct tm *localTimeInfo;
    currentTime = time(NULL);

    localTimeInfo = localtime(&currentTime);

    int year = localTimeInfo->tm_year + 1900;
    int month = localTimeInfo->tm_mon + 1;
    int day = localTimeInfo->tm_mday;

    printf("\t\tTasks have deadline before 3 days :\n");
    printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");
    printf("| ID |     Nom de la tâche     |          Description          |  Date d'échéance |        Statut        |\n");
    printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");
    for (int i = 0; i < total; i++)
    {
        if (t[i].deadline.year == year && t[i].deadline.month == month && (t[i].deadline.day - day) <= 3 && (t[i].deadline.day - day) >= 0)
        {

            printf("| %-2d | %-25s | %-31s | %04d-%02d-%02d | %-23s |\n", t[i].id, t[i].title, t[i].description, t[i].deadline.year, t[i].deadline.month, t[i].deadline.day, t[i].statut);
            printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");
        }
    }
}

void deadline_sorting()
{
    task temp;
    for (int i = 0; i < total - 1; i++)
    {
        for (int j = 0; j < total - i - 1; j++)
        {
            if (t[j].deadline.year > t[j + 1].deadline.year)
            {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
            else if (t[j].deadline.year == t[j + 1].deadline.year && t[j].deadline.month > t[j + 1].deadline.month)
            {
            }
        }
    }
    printf("\t\t\t *** Table sorted by deadline **** \n");
    printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");
    printf("| ID |     Nom de la tâche     |          Description          |  Date d'échéance |        Statut        |\n");
    printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");

    int year = 0;
    int month = 0;
    int day = 0;

    for (int j = 0; j < total; j++)
    {
        // if (t[j].deadline.year == year && t[j].deadline.month == month && (t[j].deadline.day - day) <= 3 && (t[j].deadline.day - day) >= 0){
        printf("| %-2d | %-25s | %-31s | %04d-%02d-%02d | %-23s |\n", t[j].id, t[j].title, t[j].description, t[j].deadline.year, t[j].deadline.month, t[j].deadline.day, t[j].statut);
        printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");
        // }
    }
}

JourRest tt[100];
void remainingDeadline()
{
    int i;

    time_t now;
    struct tm *timeinfo;
    time(&now);
    timeinfo = localtime(&now);

    for (i = 0; i < total; i++)
    {
        tt[i].id = t[i].id;

        struct tm deadline;
        deadline.tm_year = t[i].deadline.year - 1900;
        deadline.tm_mon = t[i].deadline.month - 1;
        deadline.tm_mday = t[i].deadline.day;
        deadline.tm_hour = 0;
        deadline.tm_min = 0;
        deadline.tm_sec = 0;

        time_t deadlineTime = mktime(&deadline);
        double diff = difftime(deadlineTime, now);

        tt[i].nbrj = (int)(diff / (60 * 60 * 24));
    }
    int year, month, day;

    printf("\t\tTasks have deadline before 3 days :\n");
    printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");
    printf("| ID |     Nom de la tâche     |          Description          |  Date d'échéance |        Statut        |\n");
    printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");

    for (int j = 0; j < total; j++)
    {
        if (tt[j].nbrj <= 3 && tt[j].nbrj >= 0)
        {
            printf("| %-2d | %-25s | %-31s | %04d-%02d-%02d | %-23s |\n", tt[j].id, t[j].title, t[j].description, t[j].deadline.year, t[j].deadline.month, t[j].deadline.day, t[j].statut);
            printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");
        }
    }
}

int main()
{
    do
    {
        printf("\n**********************************\n");
        printf("*      Task Manager Menu         *\n");
        printf("**********************************\n");
        printf("1. Add a new task\n");
        printf("2. Add a lot of tasks\n");
        printf("3. Display all tasks\n");
        printf("4. Sort tasks by alphabetically'\n");
        printf("5. Sort tasks by deadline\n");
        printf("6. Search task by ID\n");
        printf("7 Search task by title\n");
        printf("8. Display statistics\n");
        printf("9. Delete task\n");
        printf("10. Modify task\n");
        printf("11. Display tasks with deadline less 3 days\n");
        printf("12. Remaining days to each task \n");
        printf("0. Exit\n\n");
        printf("\t\t*** Please enter your choice  : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\e[1;1H\e[2J");
            addTask();
            break;
        case 2:
            printf("\e[1;1H\e[2J");
            addMultipleTasks();
            break;
        case 3:
            printf("\e[1;1H\e[2J");
            sortTasksByID();
            break;
        case 4:
            printf("\e[1;1H\e[2J");
            sortTasksAlphabetically();
            break;
        case 5:
            printf("\e[1;1H\e[2J");
            deadline_sorting();
            break;
        case 6:
            printf("\e[1;1H\e[2J");
            searching_id();
            break;
        case 7:
            printf("\e[1;1H\e[2J");
            searching_title();
            break;
        case 8:
            printf("\e[1;1H\e[2J");
            static_func();
            break;
        case 9:
            printf("\e[1;1H\e[2J");
            delete_task();
            break;
        case 10:
            printf("\e[1;1H\e[2J");
            updating_task();
            break;
        case 11:
            printf("\e[1;1H\e[2J");

            remaining_sort();
            break;
        case 12:
            printf("\e[1;1H\e[2J");

            remainingDeadline();
            break;
        case 0:
            printf("\e[1;1H\e[2J");
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("\e[1;1H\e[2J");
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 0);

    return 0;
}
