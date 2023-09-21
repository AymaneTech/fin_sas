#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
int choice;
int total = 0;
int statut_num;
int task_num;
int sorting_choice;
int id_searching;
char title_searching;

// cette fonction ajouter une nouveau tache a le tableau
void add_task()
{
    total++;
    t[total].id = total;
    printf("\tPour ajouter une nouveau tache merci de remplir ces informations :\n");

    printf("Saisir le titre de tache :\n");
    getchar();
    gets(t[total].title);

    printf("Saisir description de votre tache :\n");
    getchar();
    gets(t[total].description);

    printf("[1]==> a realiser \t [2]==> en cours de realisation \t [3]==> finalise\n");
    printf("Choisissez votre choix avec numero : \n");
    scanf("%d", &statut_num);

    //      cette condition remplit la variable statut ca depent le choix de l'utilisateur
    if (statut_num == 1)
    {
        strcpy(t[total].statut, "a realiser");
    }
    else if (statut_num == 2)
    {
        strcpy(t[total].statut, "en cours de realisation");
    }
    else if (statut_num == 3)
    {
        strcpy(t[total].statut, "finalise");
    }
    else
    {
        printf("ce choix n'existe pas !!! \n");
    }
    printf("Saisir le temps de fin de cette tache sous cette forme (jour/mois/annee):  ");
    scanf("%d/%d/%d", &t[total].deadline.day, &t[total].deadline.month, &t[total].deadline.year);
}

// precision de combien de tache va ajouter
void adding()
{

    printf("Combien de tache voullez vous ajouter : ");
    scanf("%d", &task_num);
    for (int i = 0; i < task_num; i++)
    {
        add_task();
    }
}

// la fonction d'affichage de tous les taches
void id_sorting()
{

    // Affichage de la liste de tâches triée
    printf("+----+-----------------+----------------------+--------------+-------------+\n");
    printf("| ID |    Nom de la tâche   |    Description    |  Date d'échéance |    Statut   |\n");
    printf("+----+-----------------+----------------------+--------------+-------------+\n");

    for (int i = 1; i <= total; i++)
    {
        printf("| %-2d | %-19s | %-20s | %04d-%02d-%02d | %-15s |\n", t[i].id, t[i].title, t[i].description, t[i].deadline.year, t[i].deadline.month, t[i].deadline.day, t[i].statut);
    }

    printf("+----+-----------------+----------------------+--------------+-------------+\n");
}

// la fonction de triage par alphabet
void alpha_sorting()
{
    task temp;

    for (int i = 1; i <= total - 1; i++)
    {
        for (int j = 1; j <= total - i; j++)
        {
            if (strcmp(t[j].title, t[j + 1].title) > 0)
            {
                // Swap tasks
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
    // Affichage de la liste de tâches triée
    printf("+----+-----------------+----------------------+--------------+-------------+\n");
    printf("| ID |    Nom de la tâche   |    Description    |  Date d'échéance |    Statut   |\n");
    printf("+----+-----------------+----------------------+--------------+-------------+\n");

    for (int j = 1; j <= total; j++)
    {
        printf("| %-2d | %-19s | %-20s | %04d-%02d-%02d | %-15s |\n", t[j].id, t[j].title, t[j].description, t[j].deadline.year, t[j].deadline.month, t[j].deadline.day, t[j].statut);
    }

    printf("+----+-----------------+----------------------+--------------+-------------+\n");
}

// function to choose how it will display (sorting)
void sorting()
{
    printf("\n\t[1] Trier par ordre alphabitique :: \n");
    printf("\t[2] Trier par ID : \n");
    printf("\t[3] Trier par Deadline :\n");
    printf("Entrez votre choix :: ");
    scanf("%d", &sorting_choice);

    switch (sorting_choice)
    {
    case 1:
        alpha_sorting();
        break;
    case 2:
        id_sorting();
        break;
    case 3:
        // deadline_sorting();
        break;
    default:
        printf("Valeur Invalide\n");
        printf("\e[1;1H\e[2J");
        break;
    }
}

// modification
void searching_id()
{
    printf("Entrez le ID pour rechercher : \t");
    scanf("%d", &id_searching);

    for (int i = 0; i <= total; i++)
    {
        if (id_searching == t[i].id)
        {
            printf("la tache vous chercher sur est existe : \n");
            printf("+----+-----------------+----------------------+--------------+-------------+\n");
            printf("| ID |    Nom de la tâche   |    Description    |  Date d'échéance |    Statut   |\n");
            printf("+----+-----------------+----------------------+--------------+-------------+\n");

            printf("| %-2d | %-19s | %-20s | %04d-%02d-%02d | %-15s |\n", t[i].id, t[i].title, t[i].description, t[i].deadline.year, t[i].deadline.month, t[i].deadline.day, t[i].statut);
            printf("+----+-----------------+----------------------+--------------+-------------+\n");
            break;
        }else {
            printf("Ce ID n'existe pas \n");
        }
    }
}
void searching_title(){
    printf("Entrez le titre de ce tache pour rechercher : \t");
    getchar();
    gets(title_searching);

    for (int i = 0; i <= total; i++)
    {
        if (strcmp(title_searching, t[i].title) == 0)
        {
            printf("la tache vous chercher sur est existe : \n");
            printf("+----+-----------------+----------------------+--------------+-------------+\n");
            printf("| ID |    Nom de la tâche   |    Description    |  Date d'échéance |    Statut   |\n");
            printf("+----+-----------------+----------------------+--------------+-------------+\n");

            printf("| %-2d | %-19s | %-20s | %04d-%02d-%02d | %-15s |\n", t[i].id, t[i].title, t[i].description, t[i].deadline.year, t[i].deadline.month, t[i].deadline.day, t[i].statut);
            printf("+----+-----------------+----------------------+--------------+-------------+\n");
            break;
        }
        else if (strcmp(title_searching, t[i].title) != 0){
            printf("Ce ID n'existe pas \n");
        }

    }
}

int main()
{
    // this is the main menu
    do
    {

        printf("\t\t\t\t Bienvenue a To do List \t\t\t\n");
        printf("\t=======================================================\n");
        printf("\t|[1] Ajouter une tache :\n");
        printf("\t|[2] Afficher tous les taches : \n");
        printf("\t|[3] Rechercher sur une tache \n");
        printf("\t|[4] Modifier une tache :\n");
        printf("\t|[5] Supprimer une tache : \n");
        printf("\t|[0 ] Quit\n");
        printf("\t=======================================================\n");

        printf("Entrez votre choix : ");
        scanf("%d", &choice);
        // this is the switch case that

        switch (choice)
        {
        case 1:
            adding();
            break;
        case 2:
            sorting();
            break;
        case 3:
            searching_id();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            printf("\e[1;1H\e[2J");
            break;
        }
    } while (choice != 0);

    return 0;
}