#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>      // W-L  (O_CREAT | O_RDWR   miatt kell)
#include <sys/stat.h>   // W-L  (S_IREAD | S_IWRITE miatt kell)
#include <string.h>
int main()
{
    //printf("Az e betuk szama a szovegben: %i", count_e(".\eszamlal.txt"));
    //masol("d:/games/dvdrum.rar", "d:/games/proba/dvdrum_masolt.rar");
    //printf("Ennyi kis a betu van a fileban: %d",olvas("./text2.txt"));
//    printf("sikeresen beirtam 8 valamit, talán %d",ir_lowlevel("./beir.txt"));

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
while(read(fileaz,&c,sizeof(c))){
    if(c=='a' || c=='e' || c=='u' || c=='i' || c=='o' || c=='A' || c=='E' || c=='O' || c=='I' || c=='U'){
        write(fileaz_magan,&c,1); //beírjuk az adat2.txt-be
        beirt_maganhanzo++;
    }else if(isalpha(c)){ //ha nem magánhangzó, DE betű, akkor lépünk ebbe az ágba
        write(fileaz_massal,&c,1); //beírjuk az adat3.txt-be
        beirt_massalhangzo++;
    }
}
printf("\n\nA beirt maganhangzok szama: %d",beirt_maganhanzo);
char mgh=beirt_maganhanzo+'0';
char msh=beirt_massalhangzo+'0';

write(fileaz_magan,&mgh,1);
write(fileaz_massal,&msh,1);
// 2 fontos dolog amit nem tanitottak:
//isalpha() fuggvény, megnézi hogy betű-e az átadott karakter
//integer+'0' -> igy megkapod az integert char-ként, pl 5+'0' egyenlő lesz 5-tel mint karakter
//több számjegyű számnál nemtudom hogy működik, nem próbáltam
close(fileaz);
close(fileaz_magan);
close(fileaz_massal);

int fileaz_adat2=-2;
int fileaz_adat3=-2;
//most megnyitjuk újra ellenörzésképpen, hogy jobb legyen...
fileaz_adat2=open("adat2.txt",O_RDONLY); //CSAK OLVASÁSRA NYITJUK MEG
fileaz_adat3=open("adat3.txt",O_RDONLY);

printf("\n\nAz adat2.txt tartalma: ");
while(read(fileaz_adat2,&c,sizeof(c))){
    printf("%c",c);
}
printf("\n\n");

printf("\nAz adat3.txt tartalma: ");
while(read(fileaz_adat3,&c,sizeof(c))){
    printf("%c",c);
}
printf("\n");

return 0;
}

