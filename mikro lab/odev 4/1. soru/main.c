#include <soru1.h>                           
#fuses HS, NOWDT                           // konfig�rasyon ayarlar�

#use delay(clock=4000000)           // osilat�r frekans� belirtiliyor
#define buton pin_C0                    // pin_C0'a buton tan�m� yap�l�yor
int i,z,y;                   // i,z ve y ad�nda 8 bitlik de�i�kenler tan�mlan�yor
const int digit[16]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};  //0'dan F'e kadar sayan 16'l�k sabit dizi tan�mlamas� yap�lmakta
const int digit1[4]={0x5C, 0x73, 0x79, 0x54};    // 4'l�k sabit dizi

void main()
{
 set_tris_a(0x00);         //a portu t�m pinleri ��k�� yap�lmata
 set_tris_c(0x01);         //c portu C0 pini giri� geriye kalanlar ��k�� yap�lmakta
 set_tris_d(0x00);         //d portu t�m pinleri ��k�� yap�lmata
 output_d(0x00);           //d portu t�m ��k��lar� temizlenir
 
   while(TRUE)
      {
         output_a(0x0f);   //a portunun ilk 4 bitine 1 bilgisi g�nderilir
         output_d(0x80);   //d portunun son bitine(RD7) 1 bilgisi g�nderilir
         delay_ms(400);    // gecikme yap�lmakta
         output_d(0x00);   //d portu t�m ��k��lar� temizlenir
         delay_ms(400);    //400 ms gecikme yap�lmakta
 
      if (input(buton))    //e�er butona bas�lirsa
        {
               for(z=0;z<=50;z++)           //z=0'dan 51'e kadar birer birer artt�r
                  {
                     output_a(0x08);        //a portunun RA3.bitine 1 bilgisi g�nderilir
                     output_d(digit1[0]);   //digit1'in 0.eleman� d portuna g�nderilir
                     delay_ms(10);             //gecikme yap�lmakta
 
                     output_a(0x04);           //a portunun RA2.bitine 1 bilgisi g�nderilir
                     output_d(digit1[1]);   //digit1'in 1.eleman� d portuna g�nderilir 
                     delay_ms(10);             //gecikme yap�lmakta
 
                     output_a(0x02);           //a portunun RA1.bitine 1 bilgisi g�nderilir
                     output_d(digit1[2]);   //digit1'in 2.eleman� d portuna g�nderilir 
                     delay_ms(10);             //gecikme yap�lmakta 
 
                     output_a(0x01);          //a portunun RA0.bitine 1 bilgisi g�nderilir
                     output_d(digit1[3]);   //digit1'in 3.eleman� d portuna g�nderilir 
                     delay_ms(10);             //gecikme yap�lmakta 
                  } 
         output_a(0x01);                    //a portunun RA0.bitine 1 bilgisi g�nderilir
         for (y=0;y<=3;y++)                 //y=0'dan 4'e kadar birer birer artt�r
            {
               for (i=0;i<=15;i++)          //i=0'dan 16'ya kadar birer birer artt�r
                   {
                     output_d(digit[i]);    //digit'in i.eleman� d portuna g�nderilir
                     delay_ms(500);         //gecikme yap�lmakta 
                   }
            }
         }
      }
}

