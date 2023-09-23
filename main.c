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
int searching_type;
char title_searching[50];
int id_updating;
int nbr_incomplet = 0;

// cette fonction ajouter une nouveau tache a le tableau
// CLEAN
void add_task()
{

    t[total].id = total + 1;
    printf("\n\tTask N %d :\n\n", total);

    printf("Saisir le titre de tache :\n\t>>>>>\t");
    getchar();
    gets(t[total].title);

    printf("\nSaisir description de votre tache :\n\t>>>>>\t");
    gets(t[total].description);
    getchar();

    printf("\n\t[1]==> a realiser \n\t[2]==> en cours\n\t[3]==> finalise\n");
    while (1)
    { // Infinite loop until a valid choice is made
        printf("\nChoisissez votre choix avec numero : \n\t>>>>>\t");
        scanf("%d", &statut_num);

        if (statut_num == 1)
        {
            strcpy(t[total].statut, "a realiser");
            break; // Exit the loop when a valid choice is made
        }
        else if (statut_num == 2)
        {
            strcpy(t[total].statut, "en cours");
            break;
        }
        else if (statut_num == 3)
        {
            strcpy(t[total].statut, "finalise");
            break;
        }
        else
        {
            printf("Ce choix n'existe pas !!! \n");
        }
    }
    printf("Saisir le temps de fin de cette tache sous cette forme (jour/mois/annee):  \n\t>>>>>\t");
    scanf("%d/%d/%d", &t[total].deadline.day, &t[total].deadline.month, &t[total].deadline.year);

    total++;
}

// CLEAN ALSO
void adding()
{
    printf("\n\t\t\tVoullez vous ajouter combien de tache : \t");
    scanf("%d", &task_num);
    for (int i = 1; i <= task_num; i++)
    {
        add_task();
    }
}
// la fonction de triage par alphabet
void alpha_sorting()
{

    task temp;
    for (int i = 0; i < total - 1; i++)
    {
        for (int j = i + 1; j < total - i - 1; j++)
        {
            if (strcmp(t[j].title, t[j + 1].title) == 0)
            {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
    printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");
    printf("| ID |     Nom de la tache     |          Description          |  Date d'echeance |        Statut        |\n");
    printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");

    for (int i = 0; i < total; i++)
    {
        printf("| %-2d | %-25s | %-31s | %04d-%02d-%02d | %-23s |\n", t[i].id, t[i].title, t[i].description, t[i].deadline.year, t[i].deadline.month, t[i].deadline.day, t[i].statut);
        printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");
    }
}

// function to choose how it will display (sorting)
void sorting()
{
    if (total != 0)
    {
        printf("\n\t[1] Trier par ordre alphabitique \n");
        printf("\t[2] Trier par Deadline \n");
        printf("\t[0] Retourner  \n");

        printf("Entrez votre choix : ");
        scanf("%d", &sorting_choice);

        switch (sorting_choice)
        {
        case 1:
            alpha_sorting();
            break;
        case 2:
            // deadline_sorting();
            break;
        default:
            printf("Valeur Invalide\n");
            break;
        }
    }
    else
    {
        printf("\n\t\t\tle tableau de tache est vide !!  \n\n");
    }
}

// searching
void searching_id()
{
    printf("Entrez le ID pour rechercher : \t");
    scanf("%d", &id_searching);

    for (int i = 0; i <= total; i++)
    {
        if (id_searching == t[i].id)
        {
            printf("la tache vous chercher sur est existe : \n");
            printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");
            printf("| ID |     Nom de la tâche     |          Description          |  Date d'échéance |        Statut        |\n");
            printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");

            printf("| %-2d | %-25s | %-31s | %04d-%02d-%02d | %-23s |\n", t[i].id, t[i].title, t[i].description, t[i].deadline.year, t[i].deadline.month, t[i].deadline.day, t[i].statut);
            printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");
            break;
        }
        else
        {
            printf("Ce ID n'existe pas \n");
        }
    }
}
void searching_title()
{
    printf("Entrez le titre de ce tache pour rechercher : \t");
    getchar();
    gets(title_searching);

    for (int i = 0; i <= total; i++)
    {
        if (strcmp(title_searching, t[i].title) == 0)
        {
            printf("%s", title_searching);
        }
        else if (strcmp(title_searching, t[i].title) != 0)
        {
            printf("Ce ID n'existe pas \n");
        }
    }
}
void updating_task()
{
    printf("\n\n Entrez l'ID de la tache a modifier: ");
    scanf("%d", &id_updating);
    for (int i = 0; i <= total; i++)
    {
        if (id_searching == t[i].id)
        {
            // Affichage de la liste de tâches triée
            printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");
            printf("| ID |     Nom de la tâche     |          Description          |  Date d'échéance |        Statut        |\n");
            printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");

            printf("| %-2d | %-25s | %-31s | %04d-%02d-%02d | %-23s |\n", t[i].id, t[i].title, t[i].description, t[i].deadline.year, t[i].deadline.month, t[i].deadline.day, t[i].statut);
            printf("+----+-------------------------+-------------------------------+------------------+----------------------+\n");

            printf("\tPour modifier une tache merci de remplir ces informations :\n");

            printf("Saisir le nouveau titre de tache :\n");
            getchar();
            gets(t[i].title);

            printf("Saisir le nouveau description  :\n");
            getchar();
            gets(t[i].description);

            printf("\t[1]==> a realiser \n\t [2]==> en cours de realisation \n\t [3]==> finalise\n");
            printf("Choisissez votre choix avec numero : \n");
            scanf("%d", &statut_num);

            //      cette condition remplit la variable statut ca depent le choix de l'utilisateur
            if (statut_num == 1)
            {
                strcpy(t[i].statut, "a realiser");
            }
            else if (statut_num == 2)
            {
                strcpy(t[i].statut, "en cours de realisation");
            }
            else if (statut_num == 3)
            {
                strcpy(t[i].statut, "finalise");
            }
            else
            {
                printf("ce choix n'existe pas !!! \n");
            }
            printf("Saisir le temps de fin de cette tache sous cette forme (jour/mois/annee):  ");
            scanf("%d/%d/%d", &t[i].deadline.day, &t[i].deadline.month, &t[i].deadline.year);
            break;
        }
        else
        {
            printf("Ce ID n'existe pas \n");
        }
    }
}

void count_status()
{
    for (int i = 0; i <= total; i++)
    {
        if (t[i].statut == "a realiser" && t[i].statut == "en cours de realisation")
        {
            nbr_incomplet++;
        }
    }
}

// static function
void static_func()
{
    printf("\e[1;1H\e[2J");

    printf("\n\t[1] Afficher le nombre total des tâches.\n");
    printf("\n\t[1] Afficher le nombre de les taches complet et incomplet.\n");
    printf("\nEntrez votre choix :: \n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("\t le nombre total des taches est : %d", total);
        break;
    case 2:
        printf("\tle nombre des taches incomples est : \t%d \n", nbr_incomplet);
        printf("\tle nombre des taches complets est : \t%d", (total - nbr_incomplet));
        break;
    default:
        printf("valeur invalide !!! \n");
        break;
    }
}

// searching menu
void searching_menu()
{
    printf("\e[1;1H\e[2J");
    printf("\t[1] Rechercher  par ID : \n");
    printf("\t[2] Rechercher  par Deadline :\n");
    printf("Entrez votre choix :: ");
    scanf("%d", &searching_type);

    switch (searching_type)
    {
    case 1:
        searching_id();
        break;
    case 2:
        searching_title();
        break;
    default:
        printf("Ce choix n'existe pas\n");
        break;
    }
}

// delete tasks
void delete_task()
{
    int p, q, id;
    int verifier;

    printf("Saisir le ID de tache a supprimer : ");
    scanf("%d", &id);

    printf("Confirmez avec (1 / 0): \n");
    scanf("%d", &verifier);
    if (verifier == 1)
    {
        for (p = 0; p < total; p++)
        {
            if (t[p].id == id)
            {
                printf("FOUND\n\n");
                //  TEST SUPRIMMER
                for (q = p; q < total; q++)
                {
                    t[p] = t[q + 1];
                    p++;
                }
                total--;

                printf("\tTache supprime !!! \n\n");
            }
        }
    }
    else if (verifier == 0)
    {
        printf("\t\t\toperation annulee !!!\n\n");
    }
    else
    {
        printf("\t\t\tvaleur invalide \n");
    }
}

int main()
{
    printf("\e[1;1H\e[2J");

    // this is the main menu
    printf("\t\t\t=======================================================\n\n");
    printf("\t\t\t\t\t Bienvenue a To do List \t\t\t\n");
    do
    {
        printf("\t\t\t__________________________________________________________\n");
        printf("\t\t\t|\t[1] Ajouter une tache ou plusieurs :                  |\n");
        printf("\t\t\t|\t[2] Voir toute les taches :                           |\n");
        printf("\t\t\t|\t[3] Rechercher une tache                              |\n");
        printf("\t\t\t|\t[4] Modifier une tache :                              |\n");
        printf("\t\t\t|\t[5] Statistique de mes taches :                       |\n");
        printf("\t\t\t|\t[6] Supprimer une tache                               |\n");
        printf("\t\t\t|\t[0] Quit                                              |\n");
        printf("\t\t\t___________________________________________________________\n\n");

        printf("Entrez votre choix : ");
        scanf("%d", &choice);
        // this is the switch case that

        switch (choice)
        {
        case 1:
            printf("\e[1;1H\e[2J");
            adding();

            break;
        case 2:
            printf("\e[1;1H\e[2J");
            sorting();

            break;
        case 3:
            printf("\e[1;1H\e[2J");
            searching_menu();

            break;
        case 4:
            printf("\e[1;1H\e[2J");
            updating_task();

            break;
        case 5:
            printf("\e[1;1H\e[2J");
            static_func();

            break;
        case 6:
            printf("\e[1;1H\e[2J");
            delete_task();

            break;
        default:
            printf("\e[1;1H\e[2J");
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 0);

    return 0;
}
