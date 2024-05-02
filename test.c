// tester lappartenance dun mot au grammar
// S -> 0A
// A -> 1A | 2B
// B -> 0B | 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 20
char M[N] = "";
int i, n, accepte;

void B()
{
    char c = M[i];
    if (c == '0')
    {
        i++;
        B();
    }
    else if (c == '1')
    {
        if (i == n-1)
            accepte = 1;
        else
            accepte = 0;
    }
    else
        accepte = 0;
}

void A()
{
    char c = M[i];
    if (c == '1')
    {
        i++;
        A();
    }
    else if (c == '2')
    {
        i++;
        B();
    }
    else
    {
        accepte = 0;
    }
}

void S()
{
    char c = M[i];
    if (c == '0')
    {
        i++;
        A();
    }
    else
    {
        accepte = 0;
    }
}

int main()
{
    printf("Ce programme teste l'appartenance d'un mot au grammar difinit comme suit: \n\tS -> 0A \n\tA -> 1A | 2B \n\tB -> 0B | 1\n\n");
    printf("Entrez un mot à tester: \n");
    scanf("%s", M);
    n = strlen(M);
    
    i = 0;
    S();
    if (accepte == 1)
        printf("Ce mot appartient au language.\n");
    else
        printf("Ce mot n'appartient pas au language.\n");
}
