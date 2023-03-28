#include <main.h>
#fuses HS, NOWDT, NOPROTECT 
#use delay(clock=4000000)

#define pin_up   pin_A0
#define pin_down pin_A1
#define pin_stop pin_A2
#define display1 pin_C0
#define display2 pin_C1

int i,x,a,j = 0;
int first_digit, overflow, digit = 0;
int down, up, stop= 0;
int number[10] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7C, 0x07, 0x7F, 0x6F};

void button_up()
{
    if(!input(pin_stop) && input(pin_up) && !input(pin_down))
   {
      delay_ms(15);
      up = 1;
      down, stop = 0;
      if (digit==99)
      digit=0;
      while(input(pin_up));
   }
}

void button_down()
{
   if(!input(pin_stop) && !input(pin_up) && input(pin_down))
   {
      delay_ms(15);
      down = 1;
      up , stop = 0;
      if(digit==0)
      digit = 99;
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
     output_high(display1);
     output_high(display2);
     digit=0;
     while(input(pin_stop));
   }

}


void main()
{
   
   set_tris_a(0xFF);
   set_tris_b(0x00);
   set_tris_c(0x00);
   output_b(0x00);
   output_high(display1);
   output_high(display2);

   while(TRUE)
   {  
      output_b(0x00);
      output_high(display1);
      output_high(display2);
      button_up();
      button_down();
      button_stop();
       while(up == 1 || down == 1)
      {     
            
            i = digit % 10 ; //birler
            j = digit / 10 ; //onlar
            
            if(up==1){
            digit++; 
            if(digit == 100)
            digit=0;
            }
            
            if(down==1){
            digit--;
            if(digit == 0)
            digit=99;          
            }
            for(int k=0; k<5 ; k++)
               {
                  output_high(display1);
                  output_b(number[i]);
                  delay_ms(10);
                  output_low(display1);
                  output_high(display2);
                  
                  output_b(number[j]);
                  delay_ms(10);
                  output_low(display2);
                  
                  button_stop();
                  if(input(pin_down))
                  {
                  down=1;
                  up = 0;
                  }
                  if(input(pin_up))
                  {
                  down=0;
                  up = 1;
                  }
                  
                  
                  if(stop == 1)
                  {
                     break;
                  }
               }
                       
             if(stop == 1)
             {
               break;
             }
        }

        
   }
}

