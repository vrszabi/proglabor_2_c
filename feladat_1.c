#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>      // W-L  (O_CREAT | O_RDWR   miatt kell)
#include <sys/stat.h>   // W-L  (S_IREAD | S_IWRITE miatt kell)
#include <string.h>

//1.
//    Hozzon létre alacsony szintű fájlkezeléssel egy adat1.txt fájlt, 
//    majd írja ki ebbe a fájlba a nevét és zárja le a fájlt! 
//    A létrehozott adat1.txt-t nyissa meg, és olvassa ki a benne található információt! 
//    Ha a visszaolvasott információ magánhangzó, akkor azt írja ki az adat2.txt-be, 
//    ha mássalhangzó a visszaolvasott karakter, akkor azt írja az adat3.txt-be! 
//    Mindkét esetben írja a fájl végére a lezárás előtti fájl méretét! 
//    Ellenőrzésképpen olvassa vissza az adat2.txt-t és az adat3.txt tartalmát, 
//    majd írja ki a képernyőre!

int main()
{

int fileaz=-2;
int fileaz_magan=-2;
int fileaz_massal=-2;
int beirt_maganhanzo=0;
int beirt_massalhangzo=0;
char nevem[]="Meszaros Lorinc"; //ezt irjuk a fájlba
char c = 0;
fileaz=open("adat1.txt",O_CREAT|O_TRUNC|O_RDWR,S_IREAD|S_IWRITE);//megnyitom létrehozásra meg irásra
write(fileaz,&nevem[0],strlen(nevem)); //megadjuk honnan kezdi, és mennyit irjon bele
close(fileaz);
fileaz_magan=open("adat2.txt",O_CREAT|O_TRUNC|O_RDWR,S_IREAD|S_IWRITE);
fileaz_massal=open("adat3.txt",O_CREAT|O_TRUNC|O_RDWR,S_IREAD|S_IWRITE);


fileaz=open("adat1.txt", O_RDONLY); //megnyitjuk olvasásra a filet
while(read(fileaz,&c,sizeof(c))){ //ez a blokk nagyon fontos, itt nézzük meg hogy magánhangzo vagy mássalhangzó a karakter
    if(c=='a' || c=='e' || c=='u' || c=='i' || c=='o' || c=='A' || c=='E' || c=='O' || c=='I' || c=='U'){ //itt megnézzük hogy magánhangzó-e
        write(fileaz_magan,&c,1); //ha igen beírjuk az adat2.txt-be
        beirt_maganhanzo++;
    }else if(isalpha(c)){ //ha nem magánhangzó, DE betű, akkor csak mássalhangzó lehet.
        write(fileaz_massal,&c,1); //beírjuk az adat3.txt-be
        beirt_massalhangzo++;
    }
}

char mgh=beirt_maganhanzo+'0'; //itt megkapjuk karakterként a beirt karakterek számát
char msh=beirt_massalhangzo+'0';

write(fileaz_magan,&mgh,1); //és beírjuk a fájl végére
write(fileaz_massal,&msh,1);
//////////////////////////////////////////
// 2 fontos dolog amit nem tanitottak:
//isalpha() fuggvény, megnézi hogy betű-e az átadott karakter.

//integer+'0' -> igy megkapod az integert char-ként, pl 5+'0' egyenlő lesz 5-tel mint karakter
//több számjegyű számnál nemtudom hogy működik, nem próbáltam
////////////////////////////////////////////
close(fileaz);
close(fileaz_magan);
close(fileaz_massal);


int fileaz_adat2=-2;
int fileaz_adat3=-2;
//most megnyitjuk újra ellenörzésképpen, hogy jobb legyen...
fileaz_adat2=open("adat2.txt",O_RDONLY); //CSAK OLVASÁSRA NYITJUK MEG
fileaz_adat3=open("adat3.txt",O_RDONLY);

printf("Az adat2.txt tartalma: ");
while(read(fileaz_adat2,&c,sizeof(c))){ //amíg tud olvasni a fájlból, vagyis
    printf("%c",c); //nem 0 a visszatérítési érték, addig kiirja karakterenként a tartalmát
}

printf("\nAz adat3.txt tartalma: ");
while(read(fileaz_adat3,&c,sizeof(c))){
    printf("%c",c);
}

printf("\n");

return 0;
}

