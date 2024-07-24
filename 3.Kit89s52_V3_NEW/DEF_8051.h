/**
  ******************************************************************************
  * Ten Tep      :        DEF_8051.h
  * Tac Gia      :        Nguyen Quy Nhat
  * Cong Ty      :        MinhHaGroup
  * Website      :        BanLinhKien.Vn
  * Phien Ban    :        V1.1.1
  * Ngay         :        1-1-2013
  * Tom Tat      :        define lai ten chan su dung cho 8051
  *                       define huong truyen du lieu cho 8051
  *                         
  ******************************************************************************
**/
#ifndef __DEF_8051_H
#define __DEF_8051_H
//___________________ PORT - PIN - A__________________________ 
//-------------------      PORT    ----------------------
#define PORTA           P0
#define PORTA0          P0_0
#define PORTA1          P0_1
#define PORTA2          P0_2
#define PORTA3          P0_3
#define PORTA4          P0_4
#define PORTA5          P0_5
#define PORTA6          P0_6
#define PORTA7          P0_7
//-------------------      PIN    ----------------------
#define PINA            P0
#define PINA0           P0_0
#define PINA1           P0_1
#define PINA2           P0_2
#define PINA3           P0_3
#define PINA4           P0_4
#define PINA5           P0_5
#define PINA6           P0_6
#define PINA7           P0_7
//___________________ PORT - PIN - B__________________________ 
//-------------------      PORT    ----------------------
#define PORTB           P1
#define PORTB0          P1_0
#define PORTB1          P1_1
#define PORTB2          P1_2
#define PORTB3          P1_3
#define PORTB4          P1_4
#define PORTB5          P1_5
#define PORTB6          P1_6
#define PORTB7          P1_7
//-------------------      PIN    ----------------------
#define PINB            P1
#define PINB0           P1_0
#define PINB1           P1_1
#define PINB2           P1_2
#define PINB3           P1_3
#define PINB4           P1_4
#define PINB5           P1_5
#define PINB6           P1_6
#define PINB7           P1_7
//___________________ PORT - PIN - C__________________________ 
//-------------------      PORT    ----------------------
#define PORTC           P2
#define PORTC0          P2_0
#define PORTC1          P2_1
#define PORTC2          P2_2
#define PORTC3          P2_3
#define PORTC4          P2_4
#define PORTC5          P2_5
#define PORTC6          P2_6
#define PORTC7          P2_7
//-------------------      PIN    ----------------------
#define PINC            P2
#define PINC0           P2_0
#define PINC1           P2_1
#define PINC2           P2_2
#define PINC3           P2_3
#define PINC4           P2_4
#define PINC5           P2_5
#define PINC6           P2_6
#define PINC7           P2_7
//___________________ PORT - PIN - D__________________________ 
//-------------------      PORT    ----------------------
#define PORTD           P3
#define PORTD0          P3_0
#define PORTD1          P3_1
#define PORTD2          P3_2
#define PORTD3          P3_3
#define PORTD4          P3_4
#define PORTD5          P3_5
#define PORTD6          P3_6
#define PORTD7          P3_7
//-------------------      PIN    ----------------------
#define PIND            P3
#define PIND0           P3_0
#define PIND1           P3_1
#define PIND2           P3_2
#define PIND3           P3_3
#define PIND4           P3_4
#define PIND5           P3_5
#define PIND6           P3_6
#define PIND7           P3_7
//___________________      DDRA    __________________________ 
#define DDRA           P0
#define DDRA0          P0_0
#define DDRA1          P0_1
#define DDRA2          P0_2
#define DDRA3          P0_3
#define DDRA4          P0_4
#define DDRA5          P0_5
#define DDRA6          P0_6
#define DDRA7          P0_7
//___________________      DDRB    __________________________ 
#define DDRB           P1
#define DDRB0          P1_0
#define DDRB1          P1_1
#define DDRB2          P1_2
#define DDRB3          P1_3
#define DDRB4          P1_4
#define DDRB5          P1_5
#define DDRB6          P1_6
#define DDRB7          P1_7
//___________________      DDRC    __________________________ 
#define DDRC           P2
#define DDRC0          P2_0
#define DDRC1          P2_1
#define DDRC2          P2_2
#define DDRC3          P2_3
#define DDRC4          P2_4
#define DDRC5          P2_5
#define DDRC6          P2_6
#define DDRC7          P2_7
//___________________      DDRD    __________________________ 
#define DDRD           P3
#define DDRD0          P3_0
#define DDRD1          P3_1
#define DDRD2          P3_2
#define DDRD3          P3_3
#define DDRD4          P3_4
#define DDRD5          P3_5
#define DDRD6          P3_6
#define DDRD7          P3_7
#ifndef DDROUT
    #define DDROUT     1
#endif
#ifndef DDRIN
    #define DDRIN      1
#endif
#endif
/******************************KET THUC FILE******************************
______________________________NGUYEN QUY NHAT______________________________*/