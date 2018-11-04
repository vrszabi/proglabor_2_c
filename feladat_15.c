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
char mgh[256]={0}; //ha nem nullázzuk ki a stringet, akkor nem helyes értéket ad vissza  astrlen()
char msh[256]={0};
FILE *ir = fopen("./adat1.txt", "w+b"); //write+ binary(binary a windows miatt kell)
fwrite(nevem, strlen(nevem),1,ir);
fclose(ir);

FILE *olvas = fopen("./adat1.txt","rb"); //megnyitjuk az adat1.txt-t (rb = read binary)

int i=0;
int j=0;

while(fread(&c,1,1,olvas)){ //kiolvassuk az adat1.txt tartalmát azmit az elobb beirtunk
     if(c=='a' || c=='e' || c=='u' || c=='i' || c=='o' || c=='A' || c=='E' || c=='O' || c=='I' || c=='U'){ //itt megnézzük
        mgh[i]=c; //kiolvassuk a magánhangzókat és belerakjuk egy tömbbe
        i++;
    }else if(isalpha(c)){ //ha nem magánhangzó, DE betu, akkor csak mássalhangzó lehet.
        msh[j]=c; //a mássalhangzókat belerakjuk egy tömbbe
        j++;
    }

}
fclose(olvas); //jól lezárjuk

FILE *adat2 = fopen("./adat2.txt","w+b");//az adat2-t megnyitjuk
int beirtkarakterekszama = fwrite(mgh,1,strlen(mgh),adat2);//beirunk a mgh tartalmából, egyszer, annyit amennyi az mgh string hossza, az adat2-be
//és mivel az fwrite() függvény visszatérítési értéke a beít karakterek száma, ezért azt beíom a
//beirtkarakterekszama változóba
//////////////////////////////////////////


//////////////////////////////////////////
//itt beírom a beírás előtti fájl méretét,
//mivel lezárás előtti fájl méretet nem tudok beleírni,
//mert akkor változik a fájl mérete lezárás előtt...
//továbbra sem értem ezt a lezárás előtti fájl méretet,
//ha valaki tudja írja meg: vr.szabi@gmail.com
fprintf(adat2,"%d",beirtkarakterekszama); //fprintf-fel beírom a beirtkarakterekszama decimális értékét a fájlba

fclose(adat2);//az adat2-t lezárjuk


//amit fentebb elkövettünk az adat2-vel, ugyanazt elkövetjük az adat3-mal is:
FILE *adat3 = fopen("./adat3.txt","w+b"); //megnyitjuk
beirtkarakterekszama = fwrite(msh,1,strlen(msh),adat3); //megszámoljuk a beírást
fprintf(adat3,"%d",beirtkarakterekszama);//beirjuk a megszámolt beírást a végére
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
