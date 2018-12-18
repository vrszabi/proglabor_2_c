#include <stdio.h>
#include <stdlib.h>

int max_fgv(int *int_tomb, int num_elem);

int main()
{
    int tomb1[]={1500,2000,109,-154,-1575,-2000,-9000}; //itt adunk értékeket a tömbnek
    printf("%d\n",max_fgv(tomb1, 7));  //fontos hogy a tömb elemeinek számát is megadjuk
    return 0;
}
int max_fgv(int *int_tomb, int num_elem){ //a függvénynek pointerrel adjuk át a tömböt
    int elso_neg=0;
    int max1=*int_tomb; //belerakjuk az első elemet a maxba

    while(num_elem){
        if(*int_tomb<= -1000){ //minden elemre pointerrel hivatkozunk
            elso_neg=*int_tomb; //ha a tömb valamelyik eleme kisebb vagy egyenlő -1000
            //akkor break-kel kilépünk a while-ból
            break;
        }
        *int_tomb++; //veszzük a tömbben a következő elemet
        num_elem--;
    }

    return elso_neg; //a függvény ezt adja vissza
}
