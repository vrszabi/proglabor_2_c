#include <stdio.h>
#include <stdlib.h>
int megszamol(char *p); // 01. a. megszamolja n meg e karaktereket a tömbben, pointeres
int neg_negyjegy(int *tomb[], int db); // 01. b. tombbol az elso negativ 4jegyu szamot

int main()
{
    char szoveg[]="Mint szamuzott ki vandorol a sotet ejen at";

    printf("A tombben levo e meg n betuk szama: %i\n", megszamol(szoveg));
    return 0;
}

megszamol(char *p) //itt adod át a tömböt pointerrel a függvénynek
{
    int e_n_szama = 0;
    while(*p)
    {
        if(*p=='e'||*p=='n')    //és ez az amikor a tömb elemeire pointerrel hivatkozol
        {
            e_n_szama++;
        }
        p++;
    }
    int tomb1[]= {9350,1234,-157, -1999, 4444,-1564,-4897,4677,-1111}; //nem ugyanazokat a számokat irtam mint a feladatban, lényegtelen
    neg_negyjegy(tomb1, 9); //bizony át kell adni a darabszámot is, mert int tipusu a tömb

    return e_n_szama;
}

int neg_negyjegy(int *tomb[], int db)
{
    int negyjegyu_negativ = 0;
    while(db)
    {
        int szam = 0;
        szam=*tomb;
        if(szam<=1000)
        {
            printf ("Az elso negativ 4jegyu szam: %d \n", szam);
            break;
        }
        tomb++;
        db--;
    }
    return negyjegyu_negativ;
}
