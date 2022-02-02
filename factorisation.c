#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

int* factlyndon1(char* mot) {
    int* fact = NULL;
    int n=strlen(mot);
    fact = malloc(n * sizeof(int));
    printf("Factorisation du mot w:%s\n", mot);

    int indexfact=0;
    int k=-1;
    int i=k+1;
    int j=k+2;
    while(k+1<n) {
        printf("Boucle: k:%d;i:%d;j:%d;\n",k,i,j);
            if(mot[i]<mot[j])
            {
                //printf("Test\n");
                i=k+1; j++;
            }
            else if(mot[i]==mot[j])
            {
                //printf("Test2\n");
                i++; j++;
            }
            if(j==n || mot[i]>mot[j])
            {
                while(k<i) {
                    k=k+(j-i);
                    fact[indexfact]=k;
                    indexfact++;
                }
                i=k+1;
                j=k+2;
            }
    }
    printf("Factorisation du mot w:%s finie\n", mot);
    return fact;
}

int* factlyndon2(char* mot) {
    int* fact = NULL;
    int* f = NULL;
    int n=strlen(mot);
    fact = malloc(n * sizeof(int));
    f = malloc(n * sizeof(int));
    printf("Factorisation du mot w:%s\n", mot);

    int indexfact=0;
    int k=-1;
    int j=1;
    f[2]=1;
    int i=k+f[j-k];
    while(k+1<n) {
        printf("Boucle: k:%d;i:%d;j:%d;\n",k,i,j);
            if(mot[i]<mot[j])
            {
                i=k+1; j++;
                if(j<=((n+1)/2)) {
                    f[j-k]=i-k;
                }
            }
            else if(mot[i]==mot[j])
            {
                i++; j++;
                if(j<=((n+1)/2)) {
                    f[j-k]=i-k;
                }
            }
            if(j==n || mot[i]>mot[j])
            {
                while(k<i) {
                    k=k+(j-i);
                    fact[indexfact]=k;
                    indexfact++;
                }
                if(k==j-1) { j++; }
                i=k+f[j-k];
            }
    }
    printf("Factorisation du mot w:%s finie\n", mot);
    return fact;
}

void printab(int* tab) {
    int taille = (int)(sizeof(tab)/sizeof(tab[0]));
    for (int i = 0; i < taille+2; ++i)
    {
        printf("Tab[%d]:%d\n", i,tab[i]);
    }
}

void printfact(int* tab, char* mot) {
    int taille = (int)(sizeof(tab)/sizeof(tab[0]));
    int indexmot=0;
    printf("Factorisation de w:%s\n", mot);
    for (int i = 0; i < taille+2; ++i)
    {
        printf("Tab[%d]:%d\n", i,tab[i]);
        char* facto = NULL;
        facto = malloc((tab[i]+1) * sizeof(char));
        int indexdeux=tab[i]+1-indexmot;
        for (int j = 0; j < indexdeux; ++j)
        {
            facto[j]=mot[indexmot];
            indexmot++;
        }
        printf("%s\n", facto);
        free(facto);
    }
}

int main(void)
{
    char* mot="abaababaa";

    int* fact = NULL;
    fact=factlyndon2(mot);
    printab(fact);
    printfact(fact, mot);

    free(fact);
}

