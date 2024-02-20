#include <main.h>
#fuses XT, NOWDT, NOPROTECT
#use delay(clock=4000000)
#define start pin_A0
#define stop pin_A1
int a,b,led;
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
While(TRUE){
if(input(start))
{
led=1;
if(input(stop))
{
output_b(0x00);
break; 
}
for(b=0;b<100;b++)
{
if(input(stop))
{
output_b(0x00);
break; 
}
for(a=0;a<=7;a++)
{
if(input(stop))
{output_b(0x00);
break; 
}
output_b(led);
led=led<<1;
delay_ms(100);
} 
led=0x80;
output_b(led);
delay_ms(100);
for(a=0; a<=6;a++)
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
}
}
}
}

