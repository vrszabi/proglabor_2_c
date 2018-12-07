#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
fgv1();

int main()
{
    fgv1();
    //printf("Hello world!\n");
    return 0;
}
fgv1(){
    int fileaz = -2;
    int meret = 0;
    fileaz = open("adat1.bin",O_CREAT|O_RDWR|O_TRUNC|O_BINARY,S_IREAD|S_IWRITE);
    int i = 0;

    //printf("%d",fileaz);

    for(i=0;i<=150;i++){
        if (i%10==7){
            //printf("%d",i);
            write(fileaz,&i,sizeof(int));
        }
    }
    meret = lseek(fileaz,0,SEEK_END);
    printf("%d",meret);
    close(fileaz);

    int sorszam = 1;
    FILE *fileaz_magas = fopen("adat1.bin","r+b");
    int c = 0;
    int hetes_szam_sorszama = 0;
    while(fread(&c,1,sizeof(int),fileaz_magas)){
        //

        if(c%10==7 && c/10%10==7){
          printf("\n%d ",c);
          hetes_szam_sorszama = sorszam;

        }
        sorszam++;
    }
    fclose(fileaz_magas);
    printf("beirni: %d",(meret*1000000)+hetes_szam_sorszama);
}
