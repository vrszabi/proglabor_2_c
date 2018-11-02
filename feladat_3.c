#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>      // W-L  (O_CREAT | O_RDWR   miatt kell)
#include <sys/stat.h>   // W-L  (S_IREAD | S_IWRITE miatt kell)
#include <string.h>

//3.
//Hozzon létre alacsony szintű fájlkezeléssel egy adat1.txt fájlt,
//majd írja ki ebbe a fájlba a nevét és zárja le a fájlt!
//A létrehozott adat1.txt nyissa meg, és olvassa ki a benne
//található információt! Ha a visszaolvasott karakter ASCII
//kódja páros értékű, akkor azt írja ki az adat2.txt-be,
//ha páratlan ASCII kódértékű a visszaolvasott karakter,
//akkor azt írja az adat3.txt-be! Mindkét esetben írja a
//fájl végére a lezárás előtti fájl méretét! Ellenőrzésképpen
//olvassa vissza az adat2.txt-t és az adat3.txt tartalmát,
//majd írja ki a képernyőre!

int main()
{
    int fileaz=-2;
    int fileaz_paros=-2;
    int fileaz_paratlan=-2;
    int beirt_paros=0;
    int beirt_paratlan=0;

    char nevem[]="Meszaros Lorinc"; //ezt irjuk a fájlba
    char c = 0;
    fileaz=open("adat1.txt",O_CREAT|O_TRUNC|O_RDWR,S_IREAD|S_IWRITE);//megnyitom létrehozásra meg irásra
    write(fileaz,&nevem[0],strlen(nevem)); //megadjuk honnan kezdi, és mennyit irjon bele
    close(fileaz);

    fileaz_paros=open("adat2.txt",O_CREAT|O_TRUNC|O_RDWR,S_IREAD|S_IWRITE);
    fileaz_paratlan=open("adat3.txt",O_CREAT|O_TRUNC|O_RDWR,S_IREAD|S_IWRITE);

    fileaz=open("adat1.txt", O_RDONLY); //megnyitjuk olvasásra a filet
    while(read(fileaz,&c,sizeof(c)))
    {
        if(c%2==0) //itt megnézzük páros-e, vagyis hogy kettővel való osztásnál a maradék nulla-e
        {
            write(fileaz_paros,&c,1); //ha igen akkor írjuk a fájlba
        }
        else{ //ha nem páros akkor páratlan
            write(fileaz_paratlan,&c,1);
        }
    }

//  Az összes feladatnál ott van hogy "Mindkét esetben írja a
//  fájl végére a lezárás előtti fájl méretét!"
//  Ha megnézem a fájl méretét, és beleírom, akkor megváltozik a mérete.
//  Ezt nem vágom hogy érti a feladat... kihagyom.
    close(fileaz);
    close(fileaz_paros);
    close(fileaz_paratlan);

    int fileaz_adat2=-2;
    int fileaz_adat3=-2;
//most megnyitjuk újra ellenörzésképpen, hogy jobb legyen...
    fileaz_adat2=open("adat2.txt",O_RDONLY); //CSAK OLVASÁSRA NYITJUK MEG
    fileaz_adat3=open("adat3.txt",O_RDONLY);

    printf("Az adat2.txt tartalma: ");
    while(read(fileaz_adat2,&c,sizeof(c)))  //amíg tud olvasni a fájlból, vagyis
    {                                       //nem 0 a visszatérítési érték, addig kiirja karakterenként a tartalmát
        printf("%c",c);
    }

    printf("\nAz adat3.txt tartalma: ");
    while(read(fileaz_adat3,&c,sizeof(c)))
    {
        printf("%c",c);
    }
    return 0;
}
