#include <�dev 1.h>

#fuses HS, NOWDT, NOPROTECT // Denetleyici konfig�rasyon ayarlar�
#use delay(clock=4000000) // Gecikme fonksiyonu i�in kullan�lan
 // osilat�r frekans� belirtiliyor
#use fast_io(b) // Port y�nlendirme komutlar� B portu i�in ge�erli
int i=0; // integer "i" de�i�keni tan�mlamas�

/*** ANA PROGRAM ***/

void main()
{
setup_adc_ports(NO_ANALOGS);
setup_adc(ADC_OFF);
setup_psp(PSP_DISABLED);
setup_spi(SPI_SS_DISABLED);
setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
setup_timer_1(T1_DISABLED);
setup_timer_2(T2_DISABLED,0,1);
set_tris_b(0x00); // B portunun t�m pinlerini ��k�� olarak ayarla
output_b(0x00); // B portunun ��k��lar�n� temizle

//while d���nda oldu�u durumlarda yaln�zca 1 kez �al���r ard�ndan durur.

for(i=0; i<15; i++)
   {
      output_b(0x0F);
      delay_ms(500);
      output_b(0x00);
      delay_ms(500);
      //
      output_b(0xF0);
      delay_ms(500);
      output_b(0x00);
      delay_ms(500);
   }
   for(i=0; i<5; i++)
   {
      output_b(0x55);
      delay_ms(1000);
      output_b(0x00);
      delay_ms(1000);
      //
      output_b(0xAA);
      delay_ms(1000);
      output_b(0x00);
      delay_ms(1000);
   }
   
   
 while(1)
{

//while i�erisinde ise sonsuz d�nd�dedir.

   for(i=0; i<15; i++)
   {
      output_b(0x0F);
      delay_ms(500);
      output_b(0x00);
      delay_ms(500);
      //
      output_b(0xF0);
      delay_ms(500);
      output_b(0x00);
      delay_ms(500);
   }
   for(i=0; i<5; i++)
   {
      output_b(0x55);
      delay_ms(1000);
      output_b(0x00);
      delay_ms(1000);
      //
      output_b(0xAA);
      delay_ms(1000);
      output_b(0x00);
      delay_ms(1000);
   }
}
}
