#include <16F877A.h>
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG,NOCPD
#use delay (clock=4000000)
#use rs232(baud=9600 , xmit=PIN_C6 , rcv=PIN_C7 , ERRORS)
#use fast_io(b)
#use fast_io(d)

#define sut1 pin_d0

#define sut2 pin_d1

#define sut3 pin_d2

#define sut4 pin_d3


#define sat1 pin_d4

#define sat2 pin_d5

#define sat3 pin_d6

#define sat4 pin_d7

char tus=0;

char keypad_oku()

{

output_d(0x00);

output_high(sat1);

if(input(sut1))
{delay_ms(20); tus=1;}
if(input(sut2))
{delay_ms(20); tus=2;}
if(input(sut3))
{delay_ms(20); tus=3;}
if(input(sut4))
{delay_ms(20); tus=0xA;}
output_low(sat1);
output_high(sat2);
if(input(sut1))
{delay_ms(20); tus=4;}
if(input(sut2))
{delay_ms(20); tus=5;}
if(input(sut3))
{delay_ms(20); tus=6;}
if(input(sut4))
{delay_ms(20); tus=0xB;}
output_low(sat2);
output_high(sat3);
if(input(sut1))
{delay_ms(20); tus=7;}
if(input(sut2))
{delay_ms(20); tus=8;}
if(input(sut3))
{delay_ms(20); tus=9;}
if(input(sut4))
{delay_ms(20); tus=0xC;}
output_low(sat3);
output_high(sat4);
if(input(sut1))
{delay_ms(20); tus=0xE;}
if(input(sut2))
{delay_ms(20); tus=0;}
if(input(sut3))
{delay_ms(20); tus=0xF;}
if(input(sut4))
{delay_ms(20); tus=0xD;}
output_low(sat4);
return tus;
}
void main()
{


 puts("\n Herhangi bir tusa basiniz: ");
 for(;;)
 {
 printf("\b");
 printf("%c",keypad_oku());
 }

 }


