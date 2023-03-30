#include <soru3.h>
#fuses XT,NOWDT,NOPROTECT
#use delay(clock=4000000)
#use fast_io(a)
#use fast_io(b)
#define name pin_A0
#define number pin_A1
#define stop pin_A2
int A[]={0x03, 0x75, 0x76,0x75, 0x03}; 
int H[]={0x00,0XF7,0XF7,0xF7,0X00};
int M[]={0x00, 0xFD, 0xFB, 0xFD, 0x00}; 
int E[]={0x00, 0xB6, 0xB6, 0xB6,0xBE }; 
int T[]={0xFE,0xFE,0x00,0xFE,0xFE}; 
int ZERO[]={0xC1,0XBE,0XBE,0XBE,0XC1};
int ONE[] = {0XFF,0XFF,0XFB,0XFD,0X00};
int TWO[] = {0xBD,0x9E,0xAE,0xB6,0xB9};
int THREE[] = {0xDD,0XBE,0XB6,0XB6,0XC9};
int EIGHT[] = {0XC9,0XB6,0XB6,0XB6,0XC9};

int stp =0;
int nm,nmbr =0;

int sutunsec (int s) 
{ switch (s)
   { 
      case 4: return (0x10); break;
      case 3: return (0x08); break; 
      case 2: return (0x04); break;
      case 1: return (0x02); break;
      case 0: return (0x01); break;

   }
}
void button_name()
{

   if(input(name))
      {
         output_b(0x00);
         output_c(0x00);
         stp=0;  
         nm=1;
         nmbr=0;
         while(input(name));
      }
     
}
void button_number()
{

   if(input(number))
      {
         output_b(0x00);
         output_c(0x00);
         stp=0;  
         nm=0;
         nmbr=1;
         while(input(number));
      }
     
}

void button_stop()
{

   if(input(stop))
      {
         output_b(0x00);
         output_c(0x00);
         stp=1;  
         nm=0;
         nmbr=0;
         while(input(stop));
      }
 
}

void matris_karakter_gonder (char harf[], int tekrar)
{
   int i,j; 
   if(stp==1)
         break;
         
      for (i=1;i<tekrar;i++) 
         {
         for(j=0;j<5;j++) 
            {
               output_b(sutunsec(j)); 
               output_c(harf[j]);
               delay_ms(10);
               button_stop();
                if(stp==1)
         break;
            }
         if(stp==1)
         break;
         
           
         }
           if(stp==1)
         break;
         
}


void main()
{
set_tris_a(0x07);
set_tris_b(0x00); 
set_tris_c(0x00); 
output_b(0x00);
output_c(0x00);
   while(TRUE)
   
    {
      button_number();
      button_name();
      button_stop();
      while(nm==1)
      {
         matris_karakter_gonder (A, 25); 
         matris_karakter_gonder (H,25);
         matris_karakter_gonder (M, 25); 
         matris_karakter_gonder (E,25); 
         matris_karakter_gonder (T,25); 
         output_c(0x00);
         output_b(0x00);
         nm=0;
      }
      while(nmbr==1)
      {
         matris_karakter_gonder (TWO, 25); 
         matris_karakter_gonder (ZERO,25);
         matris_karakter_gonder (ONE, 25); 
         matris_karakter_gonder (EIGHT,25); 
         matris_karakter_gonder (ZERO,25); 
         matris_karakter_gonder (THREE,25); 
         matris_karakter_gonder (ZERO,25); 
         matris_karakter_gonder (ONE,25); 
         matris_karakter_gonder (ZERO,25); 
         output_c(0x00);
         output_b(0x00);
         nmbr=0;
      }
      
   }
}
