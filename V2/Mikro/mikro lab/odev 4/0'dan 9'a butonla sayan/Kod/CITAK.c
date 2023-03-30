#include <CITAK.h>
#fuses HS, NOWDT, NOPROTECT 
#use delay(clock=4000000)

#define pin_plus pin_A0
#define pin_minus pin_A1
#define pin_stop  pin_A2
int segment[10] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7C, 0x07, 0x7F, 0x6F};
int number,a,b = 0;

void main()
{  
   set_tris_a(0xFF);
   set_tris_b(0x00);
   set_tris_c(0x00);
   output_b(0x3F);
   output_c(0x01);
   while(TRUE)
   {
      if(input(pin_plus))
      {  
         number++;
         if(number==10)
         number=0;
         output_b(segment[number]);
         while(input(pin_plus));
      
      }
      
      if(input(pin_stop))
      {
         number=0;
         output_b(segment[number]);
         while(input(pin_stop));
      }
      
      if(input(pin_minus))
      {  
         number--;
         if(number==-1)
         number=9;
         output_b(segment[number]);
         while(input(pin_minus));
    
      }
      
   }

}
