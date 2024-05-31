#ifndef _LCD_8BIT_H_
#define _LCD_8BIT_H_

// tao cac bien cmd de thao tac voi LCD
#define _LCD_CLEAR 1   		
#define _LCD_RETURN_HOME 2
#define _LCD_ENTRY_MODE	6
#define _LCD_TURN_OFF	8
#define _LCD_TURN_ON 12
#define _LCD_CURSOR_OFF	12 	  
#define _LCD_UNDERLINE_ON		14
#define _LCD_BLINK_CURSOR_ON	15
#define _LCD_MOVE_CURSOR_LEFT	16
#define _LCD_MOVE_CURSOR_RIGHT	17
#define _LCD_SHIFT_LEFT	24
#define _LCD_SHIFT_RIGHT 28
#define _LCD_4BIT_1LINE_5x7FONT	0x20
#define _LCD_4BIT_2LINE_5x7FONT	0x28
#define _LCD_8BIT_1LINE_5x7FONT	0x30
#define _LCD_8BIT_2LINE_5x7FONT	0x38
#define _LCD_FIRST_ROW 128
#define _LCD_SECOND_ROW	192

void lcd_cmd(unsigned char cmd);
void lcd_init();
void lcd_out_char(char c);
void lcd_out_str(char *str);
void lcd_pos_char(unsigned char row, unsigned char col, char c);
void lcd_pos_str(unsigned char row, unsigned char col, char *str);
void lcd_customer_display(unsigned char location, char *lcd_str);

#endif