#ifndef CONFIG_H
#define CONFIG_H
#include "Led.h"
#include "Point.h"
#define BODICE_COUNT 109 //45
#define OUTERHEART_COUNT 24
#define INNERHEART_COUNT 16
#define JEWELHEART_COUNT 7
#define TUTU1_COUNT 16
#define TUTU2_COUNT 16
#define TUTU3_COUNT 16
#define TUTU4_COUNT 16

/*uint8_t outerheart[] =
    { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
    20, 21, 22, 23
};
uint8_t innerheart[] =
    { 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39 };
uint8_t jewelheart[] = { 40, 41, 42, 43, 44, 45, 46 };
*/
Point heart=Point(55,9);

LED outerheart[]={LED(&strips[1],0),
                  LED(&strips[1],1),
                  LED(&strips[1],2),
                  LED(&strips[1],3),
                  LED(&strips[1],4),
                  LED(&strips[1],5),
                  LED(&strips[1],6),
                  LED(&strips[1],7),
                  LED(&strips[1],8),
                  LED(&strips[1],9),
                  LED(&strips[1],10),
                  LED(&strips[1],11),
                  LED(&strips[1],12),
                  LED(&strips[1],13),
                  LED(&strips[1],14),
                  LED(&strips[1],15),
                  LED(&strips[1],16),
                  LED(&strips[1],17),
                  LED(&strips[1],18),
                  LED(&strips[1],19),
                  LED(&strips[1],20),
                  LED(&strips[1],21),
                  LED(&strips[1],22),
                  LED(&strips[1],23)};

LED innerheart[]={LED(&strips[1],24),
                  LED(&strips[1],25),
                  LED(&strips[1],26),
                  LED(&strips[1],27),
                  LED(&strips[1],28),
                  LED(&strips[1],29),
                  LED(&strips[1],30),
                  LED(&strips[1],31),
                  LED(&strips[1],32),
                  LED(&strips[1],33),
                  LED(&strips[1],34),
                  LED(&strips[1],35),
                  LED(&strips[1],36),
                  LED(&strips[1],37),
                  LED(&strips[1],38),
                  LED(&strips[1],39)};

LED jewelheart[]={LED(&strips[1],40),
                  LED(&strips[1],41),
                  LED(&strips[1],42),
                  LED(&strips[1],43),
                  LED(&strips[1],44),
                  LED(&strips[1],45),
                  LED(&strips[1],46)};

BodiceLED bodice[]={BodiceLED(Point(100,95),255,&strips[0],0),
              BodiceLED(Point(98,92),244,&strips[0],1),
              BodiceLED(Point(94,86),223,&strips[0],2),
              BodiceLED(Point(81,63),144,&strips[0],3),
              BodiceLED(Point(78,60),132,&strips[0],4),
              BodiceLED(Point(76,56),119,&strips[0],5),
              BodiceLED(Point(69,35),53,&strips[0],6),
              BodiceLED(Point(67,30),37,&strips[0],7),
              BodiceLED(Point(58,37),49,&strips[0],8),
              BodiceLED(Point(58,44),70,&strips[0],9),
              BodiceLED(Point(58,68),142,&strips[0],10),
              BodiceLED(Point(58,76),165,&strips[0],11),
              BodiceLED(Point(61,93),217,&strips[0],12),
              BodiceLED(Point(58,96),225,&strips[0],13),
              BodiceLED(Point(55,100),237,&strips[0],14),
              BodiceLED(Point(37,96),230,&strips[0],15),
              BodiceLED(Point(39,89),209,&strips[0],16),
              BodiceLED(Point(40,83),191,&strips[0],17),
              BodiceLED(Point(48,60),119,&strips[0],18),
              BodiceLED(Point(46,53),99,&strips[0],19),
              BodiceLED(Point(52,33),37,&strips[0],20),
              BodiceLED(Point(53,27),19,&strips[0],21),
              BodiceLED(Point(46,26),22,&strips[0],22),
              BodiceLED(Point(43,30),37,&strips[0],23),
              BodiceLED(Point(35,48),96,&strips[0],24),
              BodiceLED(Point(35,57),120,&strips[0],25),
              BodiceLED(Point(26,67),159,&strips[0],26),
              BodiceLED(Point(15,87),227,&strips[0],27),
              BodiceLED(Point(12,92),244,&strips[0],28),
              BodiceLED(Point(0,72),215,&strips[0],29),
              BodiceLED(Point(3,67),198,&strips[0],30),
              BodiceLED(Point(6,64),185,&strips[0],31),
              BodiceLED(Point(18,52),135,&strips[0],32),
              BodiceLED(Point(17,45),121,&strips[0],33),
              BodiceLED(Point(27,36),81,&strips[0],34),
              BodiceLED(Point(29,31),67,&strips[0],35),
              BodiceLED(Point(44,13),0,&strips[0],36),
              BodiceLED(Point(41,0),15,&strips[0],37),
              BodiceLED(Point(28,0),50,&strips[0],38),
              BodiceLED(Point(25,3),56,&strips[0],39),
              BodiceLED(Point(17,26),89,&strips[0],40),
              BodiceLED(Point(65,48),85,&strips[1],47),
              BodiceLED(Point(63,55),105,&strips[1],48),
              BodiceLED(Point(74,79),182,&strips[1],49),
              BodiceLED(Point(77,83),196,&strips[1],50),
};

#endif //CONFIG_H
