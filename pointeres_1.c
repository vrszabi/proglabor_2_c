#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

pointeres_1(int *p, int darab);

int main()
{
    int szamtomb[13]={410, 140, 200, 250, 340, 100, 950, 940, 840, 4, 5, 6, 7};
    printf("\n%i db tomb elemnek van a 10es helyi erteken 4es\n",pointeres_1(szamtomb,13)); //int tömbnél mindig át kell adni a darabszámot is.

    return 0;
}


pointeres_1(int *p, int darab){ //a lényeg h pointerrel adjuk át a tömböt

//    Egy numerikus számtömbben lévo értékek közül válassza ki, és számolja meg,
//hogy hány darab olyan számérték van a tömbben, melynek 10-es helyiértékén 4-es áll!
//Pl.: számtömb: [410, 140, 200, 250, 340, 100, 950, 940, 840, 4, 5, 6, 7]
//eredmény: 4 darab
//
//A numerikus számtömböt a függvénynek cím-szerint (pointerrel) adja át!
//A végeredmény-t a 'main()' fofüggvényben írassa ki a képernyore!

    int i = 0;
    int szamol = 0;
    for(i=0;i<darab;i++){
        if(((*p/10)%10)==4){
            printf("%i, ",*p);  //kiiratom csak hogy lássuk tényleg azok a számok leszneke
                                //megszámolva amelyeknek a tizes helyi értékén 4 van.
            szamol++;
           }
     p++;
    }
    return szamol;
}