#include <stdlib.h>
#include <stdio.h>

void menu();


int main()
{
    int choix = 0;

    menu();
    scanf("%d", &choix);

    while(choix != 0)
    {
        if(choix == 1)
        {
            printf("Action n°1\n");
        }

        else if(choix == 2)
        {
            printf("Action n°2\n");
        }

        else
        {
            printf("Choix erroné");
        }

        menu();
        scanf("%d", &choix);
    }
    printf("Au revoir !\n");

    return EXIT_SUCCESS;
}   

void menu()
{
    printf("0 pour arrêter\n");
    printf("1 pour l'action n°1\n");
    printf("2 pour l'action n°2\n");
}