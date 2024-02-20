#include <16f877A.h>
#fuses HS,NOWDT,NOPROTECT
#use delay(clock=4000000)

#define buton_1 pin_A0
#define buton_2 pin_A1
#include <lcd.c>


const int digit[4] = {0x03, 0x06 , 0x0C, 0x09};

int k,i,y,j, adim=0;
int geri = 0;
int ileri = 0;
long int drc;

void buton()
{
   if(input(buton_1)) //ileri butonu
   {
      ileri = 1; 
      geri = 0;
   }
   
   if(input(buton_2)) //ileri butonu
   {
      ileri = 0; 
      geri = 1;
   }

}

void delay_buton()
{
   for(int t=0; t<100; t++)
   {
      buton();
      delay_ms(10);
   }
   
}


void main()
{
   set_tris_a(0xff);
   set_tris_c(0x00); 
   output_c(0x00); 
   lcd_init();

   printf(lcd_putc, "\fStarting...");
   delay_ms(1000);
   
while(1)
{ 
   buton();
   
   while(ileri == 1 && geri == 0) 
   {
      for( ; ; )
      {
         for(k=0; k<4; k++)  
         {
            if(drc == 360)
            drc = 0;
            
            adim = (adim+1)%4;
            output_c(digit[adim]);
            drc += 45;
            printf(lcd_putc, "\fDerece = %ld", drc);
            delay_buton();
            if(geri == 1 && ileri == 0)
            break;
            
         }
         
         if(geri == 1 && ileri == 0)
         break;
      }
      ileri = 0;
   }
   
    while(ileri == 0 && geri == 1)
   {
      for( ; ; )
      {
         for(j=0; j<4; j++)  
         {
            if(drc == -360)
            drc = 0;
            
            adim = (adim-1)%4;
            output_c(digit[adim]);
            drc = drc - 45;
            printf(lcd_putc, "\fDerece = %ld", drc);
            delay_buton();
            if(geri == 0 && ileri == 1)       
            break;
            
         }
         if(geri == 0 && ileri == 1)
         break;
      }
      geri = 0;
   }
   
 
}

}


