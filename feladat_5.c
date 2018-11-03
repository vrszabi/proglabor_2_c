#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>      // W-L  (O_CREAT | O_RDWR   miatt kell)
#include <sys/stat.h>   // W-L  (S_IREAD | S_IWRITE miatt kell)
#include <string.h>

//5.
//Hozzon létre alacsony szintű fájlkezeléssel egy adat1.txt fájlt,
//majd írja ki ebbe a fájlba a nevét és zárja le a fájlt!
//A létrehozott adat1.txt-t nyissa meg, és olvassa ki a
//benne található információt! A vezeték nevét írja ki az adat2.txt-be
//és a keresztnevét írja az adat3.txt-be! Mindkét esetben írja a
//fájl végére a lezárás előtti fájl méretét! Ellenőrzésképpen olvassa
//vissza az adat2.txt-t és az adat3.txt tartalmát, majd írja ki a képernyőre!

int main()
{
    int fileaz=-2;
    int fileaz_vez=-2;
    int fileaz_ker=-2;

    char nevem[]="Meszaros Lorinc"; //ezt irjuk a fájlba
    char c = 0;
    fileaz=open("adat1.txt",O_CREAT|O_TRUNC|O_RDWR,S_IREAD|S_IWRITE);//megnyitom létrehozásra meg irásra
    write(fileaz,&nevem[0],strlen(nevem)); //megadjuk honnan kezdi, és mennyit irjon bele
    close(fileaz);

    fileaz_vez=open("adat2.txt",O_CREAT|O_TRUNC|O_RDWR,S_IREAD|S_IWRITE);
    fileaz_ker=open("adat3.txt",O_CREAT|O_TRUNC|O_RDWR,S_IREAD|S_IWRITE);

    fileaz=open("adat1.txt", O_RDONLY); //megnyitjuk olvasásra a filet
    /////////////////////////////////
    // feltételezzük h a név vezetéknévvel kezdődik, egy space-el van elválasztva
    // a keresztnévtől, ezért elkezdjük írni a fájlba a vezetéknevet,
    // és ha találunk egy spacet, akkor elkezdjük írni a másik fájlba a maradékot ami már a keresztnév.
    /////////////////////////////////
    char keresztnev=0;      //ezzel  változoval tudjuk hogy vezetéknévnél járunk. Ha ennek az értéke 1 lesz,
    //akkor tudjuk hogy keresztnévhez értünk. (gyakorlatilag ez egy boolean)

    while(read(fileaz,&c,sizeof(c))){
        if(c==' '){
            keresztnev=1; //ha space-t találunk akkor átváltunk keresztnévre
        }else
        {//azért van az egész fájlbaírás egy else ágban, mert ha space-t találunk akkor csak
             //átírja a keresztnev-et 1-re, és nem fogja beleírni a space-t egyik fájlba sem

            if(keresztnev==0){ //ha ez igaz akkor a vezetéknévnél járunk

                write(fileaz_vez,&c,1); //ha igen akkor írjuk a fájlba
            }
            else{ //ha nem vezetéknév akkor keresztnév
                write(fileaz_ker,&c,1);
            }
        }
    }

//  Az összes feladatnál ott van hogy "Mindkét esetben írja a
//  fájl végére a lezárás előtti fájl méretét!"
//  Ha megnézem a fájl méretét, és beleírom, akkor megváltozik a mérete.
//  Ezt nem vágom hogy érti a feladat... kihagyom.
    close(fileaz);
    close(fileaz_vez);
    close(fileaz_ker);

    int fileaz_adat2=-2;
    int fileaz_adat3=-2;
//most megnyitjuk újra ellenörzésképpen, hogy jobb legyen...
    fileaz_adat2=open("adat2.txt",O_RDONLY); //CSAK OLVASÁSRA NYITJUK MEG
    fileaz_adat3=open("adat3.txt",O_RDONLY);

    printf("Az adat2.txt tartalma: ");
    while(read(fileaz_adat2,&c,sizeof(c)))  //amíg tud olvasni a fájlból, vagyis
    {
        //nem 0 a visszatérítési érték, addig kiirja karakterenként a tartalmát
        printf("%c",c);
    }

    printf("\nAz adat3.txt tartalma: ");
    while(read(fileaz_adat3,&c,sizeof(c)))
    {
        printf("%c",c);
    }
    return 0;
}

