#include <stdio.h>
#include <stdlib.h>
int fugv1(char *tomb);
int main()
{
    char tomb1[80] = "Oseinket felhozad Karpat szent bercere";
    printf("Az elso 6 karakter p�ros ascii k�dj�nak �sszege: %d",fugv1(tomb1));
    //printf("Hello world!\n");
    return 0;
}

int fugv1(char *tomb)
{
    int n = 0;
    int i = 1;
    int osszeg = 0;
    while(*tomb)
    {
        n = *tomb;
        if(n%2==0 && i<=6)
        {
            //printf("%d, ", n); //itt ellenorz�m hogy az elso 6 db p�ros sz�mr�l vane sz�

            osszeg+=n;
            i++;
        }

        tomb++;
    }
    return osszeg;
}
