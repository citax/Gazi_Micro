#include <16f877A.h>
#fuses HS,NOWDT,NOPROTECT
#use delay(clock=4000000)

#define button_start_stop PIN_A3
#define button_way        PIN_A2
#define button_speed_up   PIN_A0
#define button_speed_down PIN_A1

const int digit[4] = {0x03, 0x06 , 0x0C, 0x09};


int start_pin=0,stop_pin=1;
int start = 0;
int way = 0;
int speed = 10;
int x = 0;
int adim = 0;
int a, i, k, u;

void start_stop()
{
   if(input(button_start_stop))
   x += 1;
   while(input(button_start_stop));
   start = x % 2;
   // start = 0 ise durdurma olacak strat = 1 ise baslatma
   if(start == 10)
   start = 0;
}

void change_speed()
{
   if(input(button_speed_up))
   {
      speed += 5;
      while(input(button_speed_up));
   }
   
   if(input(button_speed_down))
   {
      speed -= 5;
      while(input(button_speed_down));
   }
}

void change_way()
{
   if(input(button_way))
   u += 1;
   while(input(button_way));
   way = u % 2;
   if(way == 10)
   way = 0;
}

void delay_button()
{  
   for(k=0; k<5; k++)
   {
      start_stop();
      change_way();
      change_speed();
      delay_ms(speed);
      if(start == 0)
      break;
   }
}

void main()
{
   set_tris_a(0xff);
   set_tris_c(0x00);
   output_c(0x00);
   
while(1)
{ 
   start_stop();
   change_way();
   change_speed();
   while(start == 1)
   {
      for(a=0; a<4; a++)
      {  
         if(way == 0)
         i = (i+1)%4;
         if(way == 1)
         i = (i-1)%4;        
         output_c(digit[i]);
         delay_button();
         if(start == 0)
         break;
      }
      start_stop();
      change_way();
      if(start == 0)
      break;
   }
}

}
