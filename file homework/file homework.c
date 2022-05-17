#include <stdio.h>

 	int ogrencino;
    char name[40];
    int midterm;

    int biggerfifty(FILE* myptr);
    int onpuan_ekle (FILE*myptr);
    int average(FILE*myptr);


    int main(){
       int i;
    
    FILE *myptr;
    myptr=fopen("students.txt","w");
    if(myptr==NULL){
        printf("dosya acilamadi ");
    }
    else{
        printf("ogrenci no,isim,midterm \n");
        for(i=0;i<10;i++){
		
        printf("?");
        scanf("%d%s%d",&ogrencino,name,&midterm);

        
        fprintf(myptr,"%d %s %d\n",ogrencino,name,midterm);
        }
        fclose(myptr);
    }


   int secim;
    printf(" 1-Notu elliden buyuk kisiler\n"
    "2-Notu 50 den az olanlara 10 puan ekle \n"
    "3-Ortalamayi bul\n"
    "4-EXIT");
    printf("\n");

    printf("secim giriniz :");
    scanf("%d",&secim);

    while (secim!=4){
        switch(secim){
            case 1:biggerfifty(myptr);break;
            case 2:onpuan_ekle(myptr); break;
            case 3: average(myptr);break;
            case 4:break;
        }
        printf("\n");
        printf("secim giriniz: ");
        scanf("%d",&secim);
		 }
     return 0;
}

   int biggerfifty(FILE* myptr){
   myptr=fopen("students.txt","r");
   int sayac =0;
   
  fscanf(myptr,"%d%s%d",&ogrencino,name,&midterm); 

   while(!feof(myptr)){
       
        if(midterm>50){
            sayac+=1;
            
            printf("%4d %s %4d\n",ogrencino,name,midterm);
         }
        fscanf(myptr,"%d%s%d",&ogrencino,name,&midterm); 
    }
    printf("Notu 50 den buyuk olan kisi sayisi : %d",sayac);
   }

int onpuan_ekle(FILE*myptr){
    myptr=fopen("students.txt","r+");
   
   fscanf(myptr,"%d%s%d",&ogrencino,name,&midterm); 

   while(!feof(myptr)){
       
        if(midterm<50){
            midterm+=10;

            printf("yeni mid : %d",midterm);
            printf("\n");
        }
        fscanf(myptr,"%d%s%d",&ogrencino,name,&midterm); 
    }

}

int average(FILE*myptr){
    myptr=fopen("students.txt","r");
    int sayac=0;
    int toplam=0;
    
    fscanf(myptr,"%d%s%d",&ogrencino,name,&midterm); 

   while(!feof(myptr)){
       sayac++;
       toplam+=midterm;
       fscanf(myptr,"%d%s%d",&ogrencino,name,&midterm); 
    }
    int ortalama = toplam/sayac;
    printf("ortalama: %d",ortalama);

}
