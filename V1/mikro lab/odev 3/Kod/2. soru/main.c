#include <main.h>
#fuses HS, NOWDT, NOPROTECT 
#use delay(clock=4000000) 
#define start pin_A0
#define start1 pin_A1
#define start2 pin_A2
#define stop  pin_A3

int z,x,y = 0x01 ;
int b,i,m,n;
int t,j,l;
void buton_start_1()
{
   if (input(start))
   {
      b=1;
      n,i=0;
      z = 0x01;
      t=1;
      while(input(start));
   }
}

void buton_start_2()
{
   if (input(start1))
   {
      b=1;
      n,i=0;
      x = 0x01;
      j=1;
      while(input(start1));
   }
}

void buton_start_3()                          
{
   if (input(start2))
   {
      b=1;
      n,i=0;
      y = 0x01; 
      l=1;
      while(input(start2));
   }
}

void buton_stop()
{
   if(input(stop))
   {
      z,x,y=0x00;
      output_b(0x00);
      output_c(0x00);
      output_d(0x00);
      n=1;
      b,t,j,l=0;
      while(input(stop));
      break;
   }
}

void delay_button_control()
{
   for(m=0; m<20; m++)
   {
      delay_ms(5);
      buton_stop();
      buton_start_3();
      buton_start_2();
      buton_start_1();
   }
   
   if(n==1)
   {  
      output_b(0x00);
      output_c(0x00);
      output_d(0x00);
      break;
   }
}

void main()
{  
   set_tris_a(0xFF);
   set_tris_b(0x00);
   set_tris_c(0x00);
   set_tris_d(0x00);
   output_b(0x00);
   output_c(0x00);
   output_d(0x00);
   while(TRUE)
   {  

      buton_start_1();
      buton_start_2();
      buton_start_3();
      if(b==1)
      {  
         
      for(;;)
      {
         for(i=0; i<8; i++)
         {  
            if(t==1){
            output_b(z);
            z = z<<1;
            }
            if(j==1){
            output_c(x);
            x = x<<1;
            }
            if(l==1){
            output_d(y);
            y = y<<1;
            }
            delay_button_control();
            if(n==1)
            break;
         }
         z=0x01;
         x=0x01;
         y=0x01;
         if(n==1)
         break;
      }
         if(n==1)
         break;
      }
     
   }

}
