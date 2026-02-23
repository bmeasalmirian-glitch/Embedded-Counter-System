#include <mega32.h>
#include <alcd.h>
#include <delay.h>

char Keypade[4][3]= {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
};
char keypressed(){
     unsigned char columns, key_row = 0, key_col = 0,k, i,t;
     DDRC = 0b00001111;  
     PORTC = 0b11110000;
     columns = PINC | 0x0F;
     while (columns != 0xFF)
          columns = PINC | 0x0F;  
     delay_ms(20);
     columns = PINC | 0x0F;
     if(columns == 0xFF) return 0;           
     k = 0x10;

     for(i = 0;i < 3;i++){  
         t = columns | k;
         if(t == 0xFF){
         key_col = i;
         break;
         }
         else 
         k = k << 1;
     }
     k = 0x01;                                                           
     for(i = 0 ; i < 4 ;i++){
          PORTC = ~k;
          columns = PINC | 0X0F;
          if(columns != 0xFF){
          key_row = i;
          break;
          }else 
              k = k << 1;
              }
              return Keypade[key_row][key_col];
         }
       
#asm
    .equ __lcd_port=0x1B   ; PORTA
#endasm

void main(void)
{
    char key;
    unsigned char idx = 0,i;    
    char Num[5];
    DDRB |= 0b00000001;
    PORTB &= 0b11111110;
    delay_ms(100);    
    lcd_init(16);
    lcd_clear();

    lcd_puts("Welcome");
    lcd_gotoxy(0,1);
    lcd_puts("Number order");

    while (1)
    {           
      key = keypressed();
      if (key != 0){
      if('0' <= key && key <= '9'){
      Num[idx++] = key;  
      PORTB |= 0b00000001;
      delay_ms(20);
      PORTB &= 0b11111110;
      lcd_putchar(key);
      }else if( key == '*'){ 
      Num[idx] = '\0';
      PORTB |= 0b00000001;
      delay_ms(200);
      PORTB &= 0b11111110;
      for( i = 0;i < 3;i++){
      lcd_clear();
      delay_ms(100);
      lcd_gotoxy(0,0);
      lcd_puts("Number Order:");
      lcd_gotoxy(0,1);
      lcd_puts(Num);
      delay_ms(100);
      }
      lcd_clear();
      lcd_puts("Number fixed");
      lcd_gotoxy(0,1);
      lcd_puts(Num);  
      delay_ms(500);
      lcd_clear();
      lcd_puts("Welcome");
      lcd_gotoxy(0,1);
     lcd_puts("Number order");
      }else if (key == '#'){
      idx = 0;
      lcd_clear();
      lcd_puts("Number Order:");
      lcd_gotoxy(0,1);
      }     
      
      delay_ms(200);     
      }
    }
}

