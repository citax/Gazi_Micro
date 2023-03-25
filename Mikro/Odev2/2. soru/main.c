#include <main.h>
#fuses XT, NOWDT, NOPROTECT
#use delay(clock=4000000)
#define start pin_A0
#define stop pin_A1
int i,a,led,c=0;

void main()
{

setup_psp(PSP_DISABLED); 
setup_timer_1(T1_DISABLED); 
setup_timer_2(T2_DISABLED,0,1); 
setup_adc_ports(NO_ANALOGS); 
setup_adc(ADC_OFF);  
setup_CCP1(CCP_OFF);
setup_CCP2(CCP_OFF); 
set_tris_a(0xFF);
set_tris_b(0x00);
output_b(0x00);
while(TRUE)
{
if(input(start))
{
delay_ms(15);
c=c+1;
while(input(start));
}
if(input(stop))
{
c=0;
output_b(0x00);
while(input(stop));
}
if(c==10)
{
led=1;
if(input(stop))
{
output_b(0x00);
break; 
}
for(a=0;a<100;a++)
{
if(input(stop))
{
output_b(0x00);
break; 
}
for(i=0;i<=7;i++)
{
if(input(stop))
{
output_b(0x00);
break;
}
output_b(led);
led=led<<1;
delay_ms(100);
} 
led=0x80;
output_b(led);
delay_ms(100);
for(i=0; i<=6;i++)
{
if(input(stop))
{
output_b(0x00);
break; 
}
led=led>>1;
output_b(led);
delay_ms(100);
}
c=0;
}
}
}
}
