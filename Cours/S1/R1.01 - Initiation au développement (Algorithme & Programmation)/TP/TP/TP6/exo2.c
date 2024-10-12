#include <stdlib.h>
#include <stdio.h>

int factorielle(int a);
void test();

int main()
{
    int nb = 0;

    printf("Entrez un nombre :\n");
    scanf("%d", &nb);

    printf("%d\n", factorielle(nb));

    test();

   return EXIT_SUCCESS;
}

int factorielle(int a)
{
    int result = 1;

    for (int i = 1; i <= a; i++)
    {
        result = result * i;

    }
    return result;
}

void test()
{
    printf("valeur attendue : %d valeur obtenue : %d\n", 1, factorielle(0));
    printf("valeur attendue : %d valeur obtenue : %d\n", 1, factorielle(1));
    printf("valeur attendue : %d valeur obtenue : %d\n", 2, factorielle(2));
    printf("valeur attendue : %d valeur obtenue : %d\n", 6, factorielle(3));
    printf("valeur attendue : %d valeur obtenue : %d\n", 5040, factorielle(7));
}