#include <4.soru.h>
#fuses XT, NOWDT, NOPROTECT
#use delay(clock=4000000)
#define buton pin_A0
#define stop pin_A1
int a,b=0;

void main()
{
set_tris_a(0xFF);
set_tris_b(0x00);
output_b(0x00);


while(TRUE)
{

   if(input(buton))
     {
      delay_ms(15);
    //delay_ms(50);
    //delay_ms(110);
    //delay_ms(160);
    //delay_ms(210);
    //delay_ms(300);
      b=b+1;
      while(input(buton));
     }

        if(input(stop))
          {
            delay_ms(15);
            b=0;
            output_b(0x00);
          }


if(b==10)
{
        if(input(stop))
           {
             delay_ms(15);
             output_b(0x00);
             break;
           }
        
     for(a=0;a<20;a++)
      {
        
           if(input(stop))
           {
             delay_ms(15);
             output_b(0x00);
             break;
           }
           
        output_b(0xFF);
           
           if(input(stop))
           {
             delay_ms(15);
             output_b(0x00);
             break;
           }
           
        delay_ms(500);
           
           if(input(stop))
           {
             delay_ms(15);
             output_b(0x00);
             break;
           }
           
        output_b(0x00);
           
           if(input(stop))
           {
             delay_ms(15);
             output_b(0x00);
             break;
           }
           
        delay_ms(500);
           
           if(input(stop))
           {
             delay_ms(15);
             output_b(0x00);
             break;
           }
           
    
      }
}
}
}
