#include <main.h>
#fuses HS, NOWDT, NOPROTECT 
#use delay(clock=4000000)
#define up pin_A0
#define down pin_A1
#define stop pin_A2
int x = 0x01;
int number[10] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7C, 0x07, 0x7F, 0x6F};

void main()
{
   
   set_tris_a(0xFF);
   set_tris_b(0x00);
   set_tris_c(0x00);
   output_b(0x00);
   output_c(0x00);
   
   /*for(int i=0; i<9; i++)
   {
   output_b(x);
   x = x << 1;
   delay_ms(100);
   }*/

   while(TRUE)
   {
   
      
      
   }

}
