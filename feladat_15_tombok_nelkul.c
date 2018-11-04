#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//    15.
//    Hozzon létre magas szintu fájlkezeléssel egy adat1.txt fájlt,
//    majd írja ki ebbe a fájlba a nevét és zárja le a fájlt! A létrehozott adat1.txt-t nyissa meg,
//    és olvassa ki a benne található információt!
//    Ha a visszaolvasott információ magánhangzó, akkor azt írja ki az adat2.txt-be, ha
//    mássalhangzó a visszaolvasott karakter, akkor azt írja az adat3.txt-be! Mindkét esetben írja a
//    fájl végére a lezárás elotti fájl méretét! Ellenorzésképpen olvassa vissza az adat2.txt-t és az
//    adat3.txt tartalmát, majd írja ki a képernyore!

int main()
{
char c;
char nevem[]="Magasszintu Fajlkezeles"; //ezt irjuk a fájlba
int beirt_mgh=0;
int beirt_msh=0;

FILE *ir = fopen("./adat1.txt", "w+b"); //write+ binary(binary a windows miatt kell)
fwrite(nevem, strlen(nevem),1,ir);
fclose(ir);

FILE *olvas = fopen("./adat1.txt","rb"); //megnyitjuk az adat1.txt-t (rb = read binary)

int i=0;
int j=0;

FILE *adat2 = fopen("./adat2.txt","w+b");//az adat2-t megnyitjuk
FILE *adat3 = fopen("./adat3.txt","w+b");//az adat3-at is megnyitjuk

while(fread(&c,1,1,olvas)){ //kiolvassuk az adat1.txt tartalmát azmit az elobb beirtunk
     if(c=='a' || c=='e' || c=='u' || c=='i' || c=='o' || c=='A' || c=='E' || c=='O' || c=='I' || c=='U'){ //itt megnézzük
        fwrite(&c,1,1,adat2); //beirjuk az adat2-be
        beirt_mgh++; //közben számoljuk hány karaktert irunk be
    }else if(isalpha(c)){ //ha nem magánhangzó, DE betu, akkor csak mássalhangzó lehet.
        fwrite(&c,1,1,adat3);
        beirt_msh++;
    }

}
fclose(olvas); //jól lezárjuk az olvast

//////////////////////////////////////////
//itt beírom a beírás előtti fájl méretét,
//mivel lezárás előtti fájl méretet nem tudok beleírni,
//mert akkor változik a fájl mérete lezárás előtt...
//továbbra sem értem ezt a lezárás előtti fájl méretet,
//ha valaki tudja írja meg: vr.szabi@gmail.com
fprintf(adat2,"%d",beirt_mgh); //fprintf-fel beírom a beirtkarakterekszama decimális értékét a fájlba
fclose(adat2);//az adat2-t lezárjuk


//amit fentebb elkövettünk az adat2-vel, ugyanazt elkövetjük az adat3-mal is:
fprintf(adat3,"%d",beirt_msh);//beirjuk a megszámolt beírást a végére
fclose(adat3); //lezárjuk

//most kiiratjuk mindkét fájl tartalmát
printf("Az adat2.txt tartalma: "); //csak hogy szebb legyen a végeredmény

FILE *adat2olvas = fopen("./adat2.txt","rb"); //újra megnyitjuk hogy ki tudjuk írni a tartalmát
while(fread(&c,1,1,adat2olvas)){
    printf("%c",c);
}
fclose(adat2olvas);


printf("\nAz adat3.txt tartalma: ");

FILE *adat3olvas=fopen("./adat3.txt","rb");
while(fread(&c,1,1,adat3olvas)){
    printf("%c",c);
}
printf("\n");
return 0;
}
