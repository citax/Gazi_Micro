#include <main.h>
#fuses HS, NOWDT, NOPROTECT 
#use delay(clock=4000000)

#define pin_up   pin_A0
#define pin_stop pin_A2
#define display1 pin_C0
#define display2 pin_C1
#define display3 pin_C2
#define display4 pin_C3
int a,b,loop,c = 0;
int birler,onlar= 0;
unsigned long int digit = 0;
int up, stop= 0;
int number[10] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7C, 0x07, 0x7F, 0x6F};
int cls[4] = {0x58, 0x38, 0x6D, 0x79};
int opn[4] = {0x5C, 0x73, 0x79, 0x54};

void button_stop()
{
   if(input(pin_stop) && !input(pin_up))
   {
     stop = 1;
     up,a,b = 0;
     output_c(0x00);
     output_b(0x00);
     digit=0;
     while(input(pin_stop));
   }
   up=0;
}


void button_up()
{
    if(!input(pin_stop) && input(pin_up))
   {
      output_c(0x00);
      up = 1;
      a,c,b,loop = 0;
      stop= 0;
      if (digit==99)
      digit=0;
      while(input(pin_up));
   }
}



void main()
{
   set_tris_a(0xFF);
   set_tris_b(0x00);
   set_tris_c(0x00);
   output_b(0x00);
  output_c(0x00);
   
   while(TRUE)
   {  
      output_c(0xFF);
      output_b(0x00);
      delay_ms(20);
        loop=0; 
        output_b(0x80);
      a=0;
      delay_ms(20);
     
      
    
      button_stop();
      button_up();
      
       while(up == 1)
      {     
             
  /////////////////////////////////////////////////////////
     for(int t=0; t<15 ; t++)
     {
         output_high(display1);
         output_b(opn[3]);
         delay_ms(5);
         output_low(display1);
         
         output_high(display2);
         output_b(opn[2]);
         delay_ms(5);
         output_low(display2);
         
         output_high(display3);
         output_b(opn[1]);
         delay_ms(5);
         output_low(display3);
         
         output_high(display4);
         output_b(opn[0]);
         delay_ms(5);
         output_low(display4);
         
         button_stop();         
         if(stop == 1)
          break;
      }
 ////////////////////////////////////////////////////////////     
        
            if(stop == 1)
            break;
            
            for(int y=0; y<200;y++)
            {
            
            birler = digit % 10 ; //birler
            onlar = digit / 10 ; //onlar
            
            digit++;
            
            if(digit == 100)
            {
            digit=0;
            loop++;
            }
            
            for(int k=0; k<3 ; k++)
               {  
                  
                  output_high(display1);
                  output_b(number[birler]);
                  delay_ms(5);
                  output_low(display1);
                  
                  output_high(display2);
                  output_b(number[onlar]);
                  delay_ms(5);
                   output_low(display2);
 
                  button_stop();         
                 if(stop == 1){
                 break;}
                  
               }
                  if(stop == 1)
            break;
            }
             if(stop == 1){
             break;}
             
             if(loop == 2)
             {
             
             for(int t=0; t<15 ; t++)
               {
         output_high(display1);
         output_b(cls[3]);
         delay_ms(5);
         output_low(display1);
         
         output_high(display2);
         output_b(cls[2]);
         delay_ms(5);
         output_low(display2);
         
         output_high(display3);
         output_b(cls[1]);
         delay_ms(5);
         output_low(display3);
         
         output_high(display4);
         output_b(cls[0]);
         delay_ms(5);
         output_low(display4);
         button_stop();         
         if(stop == 1)
         break;
     }
             up=0;
             break;
             }
               
             if(stop == 1)
             {
             break;
             }
        }

   }
   }

