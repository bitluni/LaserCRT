#pragma once
const int maxLinesPerChar = 10;
uint8_t font[][maxLinesPerChar][2] = 
{
{{255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, // 
{{120,   0}, {120, 120}, {255, 255}, {120, 240}, {121, 240}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //!
{{255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //"
{{255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //#

{{255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //$
{{255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //%
{{255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //&
{{255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //'

{{255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //(
{{255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //)
{{255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //*
{{255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //+

{{255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //,
{{ 40, 120}, {200, 120}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //-
{{119, 240}, {121, 240}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //.
{{255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, ///

{{  0, 180}, { 80, 240}, {160, 240}, {240, 180}, {240,  60}, {160,   0}, { 80,   0}, {  0,  80}, {  0, 180}, {240,  60}}, //0
{{120, 240}, {120,   0}, {  0,  80}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {180, 240}, { 60, 240}, {255, 255}}, //1
{{  0,  60}, { 60,   0}, {180,   0}, {240,  60}, {  0, 240}, {240, 240}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //2
{{ 40,   0}, {180,   0}, {240,  40}, {240,  80}, {180, 120}, {240, 160}, {240, 200}, {180, 240}, { 40, 240}, {  0, 200}}, //3
{{240, 160}, {  0, 160}, {180,   0}, {180, 240}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //4
{{  0, 200}, { 80, 240}, {160, 240}, {240, 200}, {240, 160}, {160, 120}, {  0, 120}, {  0,   0}, {240,   0}, {255, 255}}, //5
{{  0, 120}, {200, 120}, {240, 180}, {200, 240}, { 60, 240}, {  0, 180}, {  0,  60}, { 60,   0}, {180,   0}, {240,  60}}, //6
{{  0,   0}, {240,   0}, { 80, 240}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //7
{{  0, 150}, {  0, 220}, {120, 240}, {240, 220}, {240, 150}, { 40,  60}, { 60,   0}, {180,   0}, {200,  60}, {  0, 150}}, //8
{{  0, 240}, {160, 240}, {240, 200}, {240,  40}, {180,   0}, { 60,   0}, {  0,  40}, {  0,  80}, { 60, 120}, {240, 120}}, //9


{{120,  80}, {121,  81}, {255, 255}, {120, 200}, {121, 201}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //:
{{255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //;
{{255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //<
{{255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //=
{{ 60,  40}, {180, 120}, { 60, 180}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //>
{{  0,  40}, { 60,   0}, {180,   0}, {240,  40}, {180,  80}, {120, 120}, {120, 200}, {255, 255}, {120, 240}, {121, 240}}, //?
{{255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //@


{{  0, 240}, {120,   0}, {240, 240}, {255, 255}, {180, 120}, { 60, 120}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //A
{{  0, 240}, {  0,   0}, {160,   0}, {240,  40}, {240,  80}, {120, 120}, {240, 160}, {240, 200}, {160, 240}, {  0, 240}}, //B
{{240, 180}, {180, 240}, { 60, 240}, {  0, 180}, {  0,  60}, { 60,   0}, {180,   0}, {240,  60}, {255, 255}, {255, 255}}, //C
{{  0, 240}, {  0,   0}, {160,   0}, {240,  40}, {240,  80}, {240, 120}, {240, 160}, {240, 200}, {160, 240}, {  0, 240}}, //D

{{  0, 240}, {  0,   0}, {240,   0}, {255, 255}, {0,   120}, {120, 120}, {255, 255}, {  0, 240}, {240, 240}, {255, 255}}, //E
{{  0, 240}, {  0,   0}, {240,   0}, {255, 255}, {0,   120}, {120, 120}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //F
{{180, 120}, {240, 120}, {240, 180}, {180, 240}, { 60, 240}, {  0, 180}, {  0,  60}, { 60,   0}, {180,   0}, {240,  60}}, //G
{{  0, 240}, {  0,   0}, {255, 255}, {240,   0}, {240, 240}, {255, 255}, {0,   120}, {240, 120}, {255, 255}, {255, 255}}, //H

{{120, 240}, {120,   0}, {255, 255}, { 60,   0}, {180,   0}, {255, 255}, {180, 240}, { 60, 240}, {255, 255}, {255, 255}}, //I
{{240, 180}, {200, 240}, {160, 240}, {120, 200}, {120,   0}, {255, 255}, { 60,   0}, {180,   0}, {255, 255}, {255, 255}}, //J
{{  0, 240}, {  0,   0}, {255, 255}, {255, 255}, {0,   120}, {240,   0}, {255, 255}, {  0, 120}, {240, 240}, {255, 255}}, //K
{{  0, 240}, {  0,   0}, {255, 255}, {255, 255}, {255, 255}, {  0, 240}, {240, 240}, {255, 255}, {255, 255}, {255, 255}}, //L

{{  0, 240}, {  0,   0}, {120,  60}, {240,   0}, {240, 240}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //M
{{  0, 240}, {  0,   0}, {240, 240}, {240,   0}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //N
{{  0, 180}, { 80, 240}, {160, 240}, {240, 180}, {240,  60}, {160,   0}, { 80,   0}, {  0,  80}, {  0, 180}, {255, 255}}, //O
{{  0, 240}, {  0,   0}, {180,   0}, {240,  40}, {240,  80}, {180, 120}, {  0, 120}, {255, 255}, {255, 255}, {255, 255}}, //P

{{240, 180}, {240,  60}, {160,   0}, { 80,   0}, {  0,  80}, {  0, 180}, { 80, 240}, {160, 240}, {240, 180}, {240, 240}}, //Q
{{  0, 240}, {  0,   0}, {180,   0}, {240,  40}, {240,  80}, {180, 120}, {  0, 120}, {240, 240}, {255, 255}, {255, 255}}, //R
{{  0, 200}, { 80, 240}, {160, 240}, {240, 200}, {240, 160}, {  0,  80}, {  0,  40}, { 80,   0}, {160,   0}, {240,  40}}, //S
{{120, 240}, {120,   0}, {255, 255}, {  0,   0}, {240,   0}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //T

{{  0,   0}, {  0, 180}, { 80, 240}, {160, 240}, {240, 180}, {240,   0}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //U
{{  0,   0}, {120, 240}, {240,   0}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //V
{{  0,   0}, { 60, 240}, {120, 180}, {180, 240}, {240,   0}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //W
{{  0, 240}, {240,   0}, {255, 255}, {  0,   0}, {240, 240}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //X

{{  0,   0}, {120, 120}, {240,   0}, {255, 255}, {120, 120}, {120, 240}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //Y
{{  0,   0}, {240,   0}, {  0, 240}, {240, 240}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}, {255, 255}}, //Z
};
