/******************************************************
      PIC16F877 ile Timer1 Uygulamas�-1
      PIC PROG/DEKA     : Port B jumper'� LED konumunda olmal�
*******************************************************/
#include <16f877.h>     // Kullan�lacak denetleyicinin ba�l�k dosyas� tan�t�l�yor.

// Denetleyici konfig�rasyon ayarlar�
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG,NOCPD

#use delay (clock=4000000) // Gecikme fonksiyonu i�in kullan�lacak osilat�r frekans� belirtiliyor.

#use fast_io(b) //Port y�nlendirme komutlar� B portu i�in ge�erli

int i, led; // Tamsay� tipinde de�i�ken tan�mlan�yor

//****************** Timer0 Kesmesi *****************************
#int_timer1  // Timer1 kesmesi
void  timer1_kesme ()   // Kesme fonksiyonu ismi
{
   led=1;
   set_timer1(63036); // TMR1 de�eri belirleniyor
   i++;
   output_b(led);      // led de�i�keni de�eri B portuna g�nder


   if (i==50)
   {
    for(i=0;i<=7;i++)   // for d�ng�s� olu�turuluyor
      {
         output_b(led);      // led de�i�keni de�eri B portuna g�nder
         led=led<<1;         // led de�i�keni de�erini 1 bit sola kayd�r
         delay_ms(100);      // 100 msn'lik gecikme veriliyor
      }
    
    led=0x80;       //led de�i�kenine de�er y�kleniyor
      output_b(led);  //B portuna 0b10000000 bilgisi g�nderiliyor
      delay_ms(100);  // 100 msn'lik gecikme veriliyor
      
       for(i=0;i<=6;i++)  // for d�ng�s� olu�turuluyor
      {
         led=led>>1;    // led de�i�keni de�erini 1 bit sa�a kayd�r
         output_b(led); // led de�i�keni de�eri B portuna g�nder
         delay_ms(100); // 100 msn'lik gecikme veriliyor
      }
    
    }
   
   
   
   
   
   
   
   
}

/********* ANA PROGRAM FONKS�YONU********/

void main ( )
{
   setup_psp(PSP_DISABLED);        // PSP birimi devre d���
   setup_timer_2(T2_DISABLED,0,1); // T2 zamanlay�c�s� devre d���
   setup_adc_ports(NO_ANALOGS);    // ANALOG giri� yok
   setup_adc(ADC_OFF);             // ADC birimi devre d���
   setup_CCP1(CCP_OFF);            // CCP1 birimi devre d���
   setup_CCP2(CCP_OFF);            // CCP2 birimi devre d���


   set_tris_b(0x00);   // B portu komple ��k��

   output_b(0x00);     // B portu ��k��� ilk anda s�f�rlan�yor

   setup_timer_1(T1_INTERNAL | T1_DIV_BY_8); // Timer1 ayarlar� yap�l�yor
   set_timer1(63036);   // TMR1 de�eri belirleniyor


   enable_interrupts(INT_timer1); // int_timer0 kesmesini aktif yapar
   enable_interrupts(GLOBAL);     // Aktif edilen kesmelere izin ver

   while(1); // Sonsuz d�ng�

 }

