#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

pointeres_1(int *p, int darab);

int main()
{
    int szamtomb[13]={410, 140, 200, 250, 340, 100, 950, 940, 840, 4, 5, 6, 7};
    printf("\n%i db tomb elemnek van a 10es helyi erteken 4es\n",pointeres_1(szamtomb,13)); //int t�mbn�l mindig �t kell adni a darabsz�mot is.

    return 0;
}


pointeres_1(int *p, int darab){ //a l�nyeg h pointerrel adjuk �t a t�mb�t

//    Egy numerikus sz�mt�mbben l�vo �rt�kek k�z�l v�lassza ki, �s sz�molja meg,
//hogy h�ny darab olyan sz�m�rt�k van a t�mbben, melynek 10-es helyi�rt�k�n 4-es �ll!
//Pl.: sz�mt�mb: [410, 140, 200, 250, 340, 100, 950, 940, 840, 4, 5, 6, 7]
//eredm�ny: 4 darab
//
//A numerikus sz�mt�mb�t a f�ggv�nynek c�m-szerint (pointerrel) adja �t!
//A v�geredm�ny-t a 'main()' fof�ggv�nyben �rassa ki a k�pernyore!

    int i = 0;
    int szamol = 0;
    for(i=0;i<darab;i++){
        if(((*p/10)%10)==4){
            printf("%i, ",*p);  //kiiratom csak hogy l�ssuk t�nyleg azok a sz�mok leszneke
                                //megsz�molva amelyeknek a tizes helyi �rt�k�n 4 van.
            szamol++;
           }
     p++;
    }
    return szamol;
}