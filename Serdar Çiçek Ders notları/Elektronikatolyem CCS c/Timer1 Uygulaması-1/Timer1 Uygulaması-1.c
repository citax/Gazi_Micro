/******************************************************
      PIC16F877 ile Timer1 Uygulamasý-1
      PIC PROG/DEKA     : Port B jumper'ý LED konumunda olmalý
*******************************************************/
#include <16f877.h>     // Kullanýlacak denetleyicinin baþlýk dosyasý tanýtýlýyor.

// Denetleyici konfigürasyon ayarlarý
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG,NOCPD

#use delay (clock=4000000) // Gecikme fonksiyonu için kullanýlacak osilatör frekansý belirtiliyor.

#use fast_io(b) //Port yönlendirme komutlarý B portu için geçerli

int i, led; // Tamsayý tipinde deðiþken tanýmlanýyor

//****************** Timer0 Kesmesi *****************************
#int_timer1  // Timer1 kesmesi
void  timer1_kesme ()   // Kesme fonksiyonu ismi
{
   led=1;
   set_timer1(63036); // TMR1 deðeri belirleniyor
   i++;
   output_b(led);      // led deðiþkeni deðeri B portuna gönder


   if (i==50)
   {
    for(i=0;i<=7;i++)   // for döngüsü oluþturuluyor
      {
         output_b(led);      // led deðiþkeni deðeri B portuna gönder
         led=led<<1;         // led deðiþkeni deðerini 1 bit sola kaydýr
         delay_ms(100);      // 100 msn'lik gecikme veriliyor
      }
    
    led=0x80;       //led deðiþkenine deðer yükleniyor
      output_b(led);  //B portuna 0b10000000 bilgisi gönderiliyor
      delay_ms(100);  // 100 msn'lik gecikme veriliyor
      
       for(i=0;i<=6;i++)  // for döngüsü oluþturuluyor
      {
         led=led>>1;    // led deðiþkeni deðerini 1 bit saða kaydýr
         output_b(led); // led deðiþkeni deðeri B portuna gönder
         delay_ms(100); // 100 msn'lik gecikme veriliyor
      }
    
    }
   
   
   
   
   
   
   
   
}

/********* ANA PROGRAM FONKSÝYONU********/

void main ( )
{
   setup_psp(PSP_DISABLED);        // PSP birimi devre dýþý
   setup_timer_2(T2_DISABLED,0,1); // T2 zamanlayýcýsý devre dýþý
   setup_adc_ports(NO_ANALOGS);    // ANALOG giriþ yok
   setup_adc(ADC_OFF);             // ADC birimi devre dýþý
   setup_CCP1(CCP_OFF);            // CCP1 birimi devre dýþý
   setup_CCP2(CCP_OFF);            // CCP2 birimi devre dýþý


   set_tris_b(0x00);   // B portu komple çýkýþ

   output_b(0x00);     // B portu çýkýþý ilk anda sýfýrlanýyor

   setup_timer_1(T1_INTERNAL | T1_DIV_BY_8); // Timer1 ayarlarý yapýlýyor
   set_timer1(63036);   // TMR1 deðeri belirleniyor


   enable_interrupts(INT_timer1); // int_timer0 kesmesini aktif yapar
   enable_interrupts(GLOBAL);     // Aktif edilen kesmelere izin ver

   while(1); // Sonsuz döngü

 }

