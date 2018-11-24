#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
/*
Itt deklaráljuk a függvényeket.
Nagyjából azt jelenti hogy szólunk a C-nek hogy lesznek ilyen függvények,
amik ilyen argumentumokat fogadnak, és ilyen visszatérítési értékük lesz
*/
int pointeres_1(int *p, int darab);
alacsony_beir_olvas();
magas_fgv1();
generate_ascii();

/*majd jön maga a fő függvény, ami ugye a main*/
int main()
{
    int szamtomb[]={410, 140, 200, 250, 340, 100, 950, 940, 840, 4, 5, 6, 7};
    printf("A tombben ennyi szamnak van 4 a tizes helyi erteken: %i\n",pointeres_1(szamtomb,13)); //itt meghívom a pointeres függvényt

    printf("\nAlacsony szinten ezt irtuk a fajlba: \n");
    alacsony_beir_olvas();//itt meghívom a fájlbaírós függvényt

    magas_fgv1(); //itt meghívom a következő fájlos függvényt

    return 0;
}


int pointeres_1(int *p, int darab){ //itt definiálom a függvényt, amit feljebb deklaráltam, gyakorlatilag itt irom meg az egésznek a működését

//    Egy numerikus számtömbben lévő értékek közül válassza ki, és számolja meg,
//hogy hány darab olyan számérték van a tömbben, melynek 10-es helyiértékén 4-es áll!
//Pl.: számtömb: [410, 140, 200, 250, 340, 100, 950, 940, 840, 4, 5, 6, 7]
//eredmény: 4 darab
//
//A numerikus számtömböt a függvénynek cím-szerint (pointerrel) adja át!
//A végeredmény-t a 'main()' főfüggvényben írassa ki a képernyőre!
    int i = 0;
    int szamol = 0;
    for(i=0;i<darab;i++){
        if(((*p/10)%10)==4){
            //printf("%i, ",*p);  //kiiratom csak hogy lássuk tényleg azok a számok leszneke
                                //megszámolva amelyeknek a tizes helyi értékén 4 van.
            szamol++;
           }
     p++;
    }
    return szamol;
}

alacsony_beir_olvas(){ //itt definiálom, vagyis megírom a másik függvényt, amit feljebb deklaráltam
    int fileaz = -2;
    int i = 0;
    fileaz = open("alacsony.dat",O_CREAT|O_TRUNC|O_RDWR|O_BINARY,S_IWRITE|S_IREAD);
    for(i=0;i<=10;i++){
        write(fileaz,&i, sizeof(int));
    }
    close(fileaz);

    fileaz = open("alacsony.dat",O_RDONLY|O_BINARY,S_IREAD|S_IWRITE);
    while(read(fileaz,&i,sizeof(i))){

        printf("%i ",i);

    }
    close(fileaz);
}

magas_fgv1(){ //itt definiálom, vagyis megírom a harmadik függvényt, amit feljebb deklaráltam
    FILE *file_ir = fopen("form.txt","w+b");
    int i=0;
    for(i=0;i<=20;i++){
        if(i%2==0){
            fprintf(file_ir,"%i\n",i);
        }
    }
    fclose(file_ir);
}

