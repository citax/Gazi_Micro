#include <main.h>
#fuses HS, NOWDT, NOPROTECT 
#use delay(clock=4000000) 
#define start pin_A0
#define stop  pin_A2
int a,i,b,c,d,e = 0;
const int out[16]={ 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7C, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};

void input_button()
{
    if(input(start) == 1)
   {  
      c = 0;
      a++;
      while(input(start));
   }
}
void input_button_stop()
{
   if(input(stop) == 1)
   {  
      c = 44;
      a=0;
      while(input(stop));
      break;
   }
  
}

void main()
{
   set_tris_a(0xFF);
   set_tris_b(0x00);
   set_tris_c(0x00);
   output_b(0x00);
   output_c(0x01);
   while(TRUE)
   {
   
   input_button();
   input_button_stop();
      while(a == 10 && !input(stop))
      {     
            input_button_stop();
            
                     if(c==44){
                     break;}
                     
             for(b = 0; b < 50  && !input(stop) ; b++)
           {      
                  input_button_stop();
                  
                     if(c==44){
                     break;}
                     
                  for(i = 0; i < 17 && !input(stop) ; i++)
                     {
                           output_b(out[i]);
                           delay_ms(300);
                           output_b(0x00);
                           delay_ms(300);
                           input_button_stop();
                           
                     if(c==44){
                     break;}
                     
                     }
                     if(c==44){
                     break;}
                     
                     }
            }           
      }
   
   }
   
   

