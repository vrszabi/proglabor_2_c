#include <stdio.h>
#include <stdlib.h>
int fugv1(char *tomb);
int main()
{
    char tomb1[70] = "Mint szamuzott ki vandorol a sotet ejen at.";
    printf("%d",fugv1(tomb1));
    //printf("Hello world!\n");
    return 0;
}

int fugv1(char *tomb)
{
    int paratlan = 0;
    while(*tomb){

        if(*tomb%2==1){
            //printf("%c, %d \n", *tomb,*tomb); //ha innen kiveszed a kommentet, akkor láthatod a karaktert, annak az ascii kódját, és hogy páratlan

            paratlan++; //növeljük a számlálót
        }

        tomb++; //lépünk a tömb következő elemére
    }
    return paratlan;
}
