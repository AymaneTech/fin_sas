#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// creation de la structure de date;

typedef struct
{
    int year, month, day;

}date;
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

// cette fonction ajouter une nouveau tache a le tableau
void add_task()
{
    total++;
    t[total].id =total;
    printf("\tPour ajouter une nouveau tache merci de remplir ces informations :\n");

    printf("Saisir le titre de tache :\n");
    getchar();
    gets(t[total].title, stdin);

    printf("Saisir description de votre tache :\n");
    getchar();
    gets(t[total].description, stdin);

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
void adding(){

        printf("Combien de tache voullez vous ajouter : ");
        scanf("%d", &task_num);
        for (int i = 0; i< task_num; i++){
            add_task();
        }
    

}

// la fonction d'affichage de tous les taches 
void show_tasks (){

    // Affichage de la liste de tâches triée
    printf("+----+-----------------+----------------------+--------------+-------------+\n");
    printf("| ID |    Nom de la tâche   |    Description    |  Date d'échéance |    Statut   |\n");
    printf("+----+-----------------+----------------------+--------------+-------------+\n");

    for (int i = 1; i <= total; i++) {
        printf("| %-2d | %-20s | %-20s | %04d-%02d-%02d | %-10s |\n", t[i].id, t[i].title, t[i].description, t[i].deadline.year, t[i].deadline.month, t[i].deadline.day, t[i].statut);
    }

    printf("+----+-----------------+----------------------+--------------+-------------+\n");
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
        printf("\t|[3] Modifier une tache :\n");
        printf("\t|[4] Supprimer une tache : \n");
        printf("\t|[5] Rechercher sur une tache \n");
        printf("\t|[0 ] Quit\n");
        printf("\t=======================================================\n");

        printf("Entrez votre choix : ");
        scanf("%d", &choice);
        // this is the switch case that

        switch (choice)
        {
        case 1:
            add_task();
            break;
        case 2:
            show_tasks();
            break;
        default:

            break;
        }
    }while(choice !=0);

    return 0;
}