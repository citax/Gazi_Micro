#include <main.h> 
#fuses XT,NOWDT, NOPROTECT 
#use delay(clock=4000000) 
#use fast_io(a)
#use fast_io (b)

#define display_1 pin_a0
#define display_2 pin_a1
#define buton pin_a2


char birler=0, onlar=0, sayi=0;
const int digit [10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void main()
{
   set_tris_a(0xFC);
   set_tris_b(0x00);
   output_low(display_1);
   output_low(display_2);
   
   while(1)
   {
      birler=sayi%10;
      onlar=sayi/10;
      
      output_high(display_2);
      output_b(digit[birler]);  
      delay_ms(5);
      
      output_low(display_2);
      output_high(display_1);
      output_b(digit [onlar]);
      delay_ms(5);
      output_low(display_1);
      
      if (input (buton))
      {
         delay_ms(10);
         sayi++;
         if (sayi==100) 
         sayi=0;
         
         birler = sayi%10; 
         onlar = sayi/10;
            while(input (buton))
            {
               output_high(display_2); 
               output_b(digit[birler]);
               delay_ms(5);
               output_low(display_2);
               output_high(display_1);
               output_b(digit[onlar]);
            }
      delay_ms(5);
      output_low(display_1);
      }
   }
}
