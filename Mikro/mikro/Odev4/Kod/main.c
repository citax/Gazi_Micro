#include <main.h>
#fuses HS, NOWDT, NOPROTECT 
#use delay(clock=4000000)

#define pin_up pin_A0
#define pin_down pin_A1
#define pin_stop pin_A2

int i,x,a = 0;
int first_digit, overflow = 0;
int down, up, stop= 0;
int number[10] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7C, 0x07, 0x7F, 0x6F};


void button_up()
{
    if(!input(pin_stop) && input(pin_up) && !input(pin_down))
   {
      up = 1;
      down, stop = 0;
      while(input(pin_up));
   }
}

void button_down()
{
   if(!input(pin_stop) && !input(pin_up) && input(pin_down))
   {
      down = 1;
      up , stop = 0;
      while(input(pin_down));
   }
}

void button_stop()
{
   if(input(pin_stop) && !input(pin_up) && !input(pin_down))
   {
     i,x,a = 0;
     first_digit, overflow = 0;
     down, up= 0;   
     stop = 1;
     up, down = 0;
     output_b(0x00);
     output_c(0x03);
     while(input(pin_stop));
   }

}


void main()
{
   
   set_tris_a(0xFF);
   set_tris_b(0x00);
   set_tris_c(0x00);
   output_b(0x00);
   output_c(0x03);

   while(TRUE)
   {  
      output_b(0x00);
      output_c(0x03);
      button_up();
      button_stop();
       while(up == 1)
      {
         
         for(i=0 ; i<11; i++)
         {  
            
            if(first_digit == 10)
            {
               overflow++;
               first_digit=0;
               if (overflow == 10)
               overflow = 0;
            }
            
            if(0 < overflow < 10)
            {  
               a = number[overflow];
            }
               for(int k=0; k<10 ; k++)
               {
                  output_c(0x01);
                  output_b(x);
                  delay_ms(10);
                  output_c(0x02);
                  output_b(a);
                  delay_ms(10);
                  button_stop();
                  button_down();
                  button_up();
                  if(stop == 1 || down == 1)
                  {
                     break;
                  }
               }
               
            if(stop == 1 || down == 1)
            {
               break;
            }
            
            x = number[i]; 
            first_digit++; 

         }
         if(stop == 1 || down == 1)
            {
               break;
            }
      }
   }
}

