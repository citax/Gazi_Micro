#include <main.h>
#fuses HS, WDT, NOPROTECT 
#use delay(clock=4000000)
int led = 0x01;
void main()
{  
   set_tris_c(0xFF);  
   set_tris_d(0x00);
   output_d(0x00);
   setup_WDT(WDT_2304MS);
 
   while(TRUE)
   {
         for(int i=0 ; i<7 ; i++)
         {  
            output_d(led);
            led = led << 1 ;
            delay_ms(100); 
                while (input(pin_c0))
         restart_WDT();
         }
         
         for(int y =0; y<7; y++)
         {
            output_d(led);
            led = led >> 1 ;
             delay_ms(100);         
                 while (input(pin_c0))
         restart_WDT();
         }
         
         while (input(pin_c0))
         restart_WDT();
      }
      
   }


