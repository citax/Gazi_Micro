#include <main.h>
#include <math.h>
#use fast_io(b)
#use fast_io(d)
#define use_portb_lcd TRUE

#include <lcd.c>

int32 sayi1 = 0;
int32 sayi = 0;
int32 x = 0;
int32 islem = 0;
int32 sonuc = 0;

int sonuc_bul()
{
  delay_ms(100);
  printf(lcd_putc, "\nsonuc=");
  switch (islem)
  {
  case 1:
    sonuc = (sayi1) + (sayi);
    printf(lcd_putc, "%ld", sonuc);
    sayi1 = 0;
    sayi = 0;
    x = 0;
    islem = 0;
    sonuc = 0;
    break;
  case 2:
    sonuc = sayi1 - sayi;
    printf(lcd_putc, "%ld", sonuc);
    sayi1 = 0;
    sayi = 0;
    x = 0;
    islem = 0;
    sonuc = 0;
    break;
  case 3:
    sonuc = sayi1 * sayi;
    printf(lcd_putc, "%ld", sonuc);
    sayi1 = 0;
    sayi = 0;
    x = 0;
    islem = 0;
    sonuc = 0;
    break;
  case 4:
    sonuc = sayi1 / sayi;
    printf(lcd_putc, "%ld", sonuc);
    sayi1 = 0;
    sayi = 0;
    x = 0;
    islem = 0;
    sonuc = 0;
    break;
  }
  islem = 0;
}

char tus()
{
  output_high(pin_d0);
  if (input(pin_d4))
  {
    while (input(pin_d4))
      ;
    printf(lcd_putc, "7");
    x = 7;
    sayi = sayi * 10 + x;
  }
  if (input(pin_d5))
  {
    while (input(pin_d5))
      ;
    printf(lcd_putc, "8");
    x = 8;
    sayi = sayi * 10 + x;
  }
  if (input(pin_d6))
  {
    while (input(pin_d6))
      ;
    printf(lcd_putc, "9");
    x = 9;
    sayi = sayi * 10 + x;
  }
  if (input(pin_d7))
  {
    while (input(pin_d7))
      ;
    printf(lcd_putc, "/");
    sayi1 = sayi;
    islem = 4;
    sayi = 0;
  }
  output_low(pin_d0);

  output_high(pin_d1);
  if (input(pin_d4))
  {
    while (input(pin_d4))
      ;
    printf(lcd_putc, "4");
    x = 4;
    sayi = sayi * 10 + x;
  }
  if (input(pin_d5))
  {
    while (input(pin_d5))
      ;
    printf(lcd_putc, "5");
    x = 5;
    sayi = sayi * 10 + x;
  }
  if (input(pin_d6))
  {
    while (input(pin_d6))
      ;
    printf(lcd_putc, "6");
    x = 6;
    sayi = sayi * 10 + x;
  }
  if (input(pin_d7))
  {
    while (input(pin_d7))
      ;
    printf(lcd_putc, "*");
    sayi1 = sayi;
    islem = 3;
    sayi = 0;
  }
  output_low(pin_d1);

  output_high(pin_d2);
  if (input(pin_d4))
  {
    while (input(pin_d4))
      ;
    printf(lcd_putc, "1");
    x = 1;
    sayi = sayi * 10 + x;
  }
  if (input(pin_d5))
  {
    while (input(pin_d5))
      ;
    printf(lcd_putc, "2");
    x = 2;
    sayi = sayi * 10 + x;
  }
  if (input(pin_d6))
  {
    while (input(pin_d6))
      ;
    printf(lcd_putc, "3");
    x = 3;
    sayi = sayi * 10 + x;
  }
  if (input(pin_d7))
  {
    while (input(pin_d7))
      ;
    printf(lcd_putc, "-");
    sayi1 = sayi;
    islem = 2;
    sayi = 0;
  }
  output_low(pin_d2);

  output_high(pin_d3);
  if (input(pin_d4))
  {
    while (input(pin_d4))
      ;
    printf(lcd_putc, "\f ON");
    printf(lcd_putc, "\f");
    sayi1 = 0;
    sayi = 0;
    x = 0;
    islem = 0;
    sonuc = 0;
  }
  if (input(pin_d5))
  {
    while (input(pin_d5))
      ;
    printf(lcd_putc, "0");
    x = 0;
    sayi = sayi * 10 + x;
  }
  if (input(pin_d6))
  {
    while (input(pin_d6))
      ;
    sayi1;
    sonuc_bul();
  }

  if (input(pin_d7))
  {
    while (input(pin_d7))
      ;
    printf(lcd_putc, "+");
    sayi1 = sayi;
    islem = 1;
    sayi = 0;
  }
  output_low(pin_d3);

  return sayi, sayi1, islem;
}

void main()
{

  set_tris_b(0x00);
  set_tris_d(0xF0);

  lcd_init();

  while (TRUE)
  {

    tus();
  }
}

