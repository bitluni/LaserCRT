const int EN = 8;
const int X_DIR = 5;
const int Y_DIR = 6;
const int Z_DIR = 7;
const int X_STP = 2;
const int Y_STP = 3;
const int Z_STP = 4;
const int LASER = 12;
const int TRIGGER = 11;

const long cyclesPerSecond = 16000000L;
const long timerPrescaler = 1024;
volatile long ticksPerStep = 5000;
const long minTicksPerStep = 3000;

const int maxADCValue = 620; //at 3.3V input

int yOffset = 0;
int xOffset = 0;
int xres = 512;
int yres = 280;

const int adiv = 1; //40;
const int amul = 1; //16;
volatile int onOff = 0;

volatile int currentX = 0;
volatile int targetX = 0;
volatile int currentY = 0;
volatile int targetY = 0;
volatile int offsetX = 0;
volatile int offsetY = 0;

volatile int button = 0;
volatile int encoder = 0;

volatile int mode = 0;
volatile int menu = 0;
volatile int calibStep = 0;

#include "encoder.h"
#include "galvo.h"
#include "font.h"
#include "print.h"

void handleControls()
{
  if(!onOff)
    mode = 0;
  switch(mode)
  {
    case 0:
      if(button)
      {
        mode = menu + 1;
        cancelPrint = true;
      }
      else
      {
        int om = menu;
        menu = menu + encoder;
        if(menu < 0) menu = 0;
        if(menu > 4) menu = 4;
        if(om != menu)
          cancelPrint = true;
      }
      break;
    case 1:
      if(button)
        mode = 0;
      break;
    case 2:
      {
        if(button)
        {
          calibStep++;
          if(calibStep == 5)
          {
            calibStep = 0;
            mode = 0;
          }
        }
        else
          if(encoder) 
          {
            switch(calibStep)
            {
              case 0:
                offsetX += encoder * 8;
                break;
              case 1:
                offsetY += encoder * 8;
                break;
              case 2:
                xres += encoder * 8;
                if(xres < 40)
                  xres = 40;
                break;
              case 3:
                yres += encoder * 8;
                if(yres < 40)
                  yres = 40;
                break;
            }
          }
      }
      break;
    case 3:
      if(button)
        mode = 0;
        else
        {
          ticksPerStep += encoder * 100;
          if(ticksPerStep < minTicksPerStep)
            ticksPerStep = minTicksPerStep;
        }
      break;
    case 5:
      if(button)
        mode = 0;
      break;

  }  
  button = 0;
  encoder = 0;
}

void pollControls()
{
  int pinc = PINC;
  int P = (pinc >> 1) & 1;
  int A = (pinc >> 2) & 1;
  int B = (pinc >> 3) & 1;
  button += handleButton(P);
  encoder += handleEncoder(A, B);
  onOff = pinc & 1;
}

ISR (TIMER1_OVF_vect)
{
  TCNT1 = 65536L - ticksPerStep;
  pollControls();
  handleControls();
  moveGalvo();
}

void setup()
{
  Serial.begin(115200);
  pinMode(X_DIR, OUTPUT); pinMode(X_STP, OUTPUT);
  pinMode(Y_DIR, OUTPUT); pinMode(Y_STP, OUTPUT);
  pinMode(Z_DIR, OUTPUT); pinMode(Z_STP, OUTPUT);
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(EN, OUTPUT);
  digitalWrite(EN, LOW);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);
  yOffset = analogRead(A6) / adiv;
  xOffset = analogRead(A7) / adiv;
  pinMode(LASER, OUTPUT);
  //pinMode(TRIGGER, INPUT_PULLUP);
  pinMode(TRIGGER, INPUT);

  //set timer interrupt
  TCNT1 = 65536L - ticksPerStep;
  TCCR1A = 0x00;
	TCCR1B = (1<<CS10);  // no prescaler
	TIMSK1 = (1 << TOIE1);   // Enable timer1 overflow interrupt(TOIE1)
	sei();
}

#include "rick.h"

void drawVectors(int x0, int y0, const uint8_t (*r)[2], int c)
{
  bool restart = true;
  for(int i = 0; i < c; i++)
    {
      if(r[i][0] == 255)
        restart = true;    
      else
      {
        int x = r[i][0];
        int y = r[i][1];
        move(x0 + x, y0 + y, restart ? 0 : 1);
        restart = false;
      }
    } 
}

void loop()
{
  int trigger = digitalRead(TRIGGER) ? 1 : 0;
  if(mode == 1)
    digitalWrite(LASER, onOff & trigger);
  else
    digitalWrite(LASER, onOff);
  static int t = 0;
  t++;
  switch(mode)
  {
    case -1: //greeting
      break;
    case 0: //main menu
    {
      int x0 = (xres - (8 * 42 - 10)) / 2;
      int y0 = (yres - (6 * 48 - 16)) / 2;
      print(x0, y0 + (menu + 1) * (32 + 16), ">", 32, 32, 10, 16);
      print(x0, y0, "MENU:\n XY-MODE\n CALIB\n SPEED\n VIM\n RICK", 32, 32, 10, 16);
      break;
    }
    case 1:
      {
        ADCSRA &= ~(bit (ADPS0) | bit (ADPS1) | bit (ADPS2)); //speed up adc read
        ADCSRA |= bit (ADPS2);
        long a6 = analogRead(A6);
        long a7 = analogRead(A7);
        targetX = (a6 * xres) / maxADCValue;
        targetY = (a7 * yres) / maxADCValue;
        //targetX = (xres - 256) / 2 + (a6 * 256) / maxADCValue;
        //targetY = (yres - 256) / 2 + (a7 * 256) / maxADCValue;
      }
      break;

    case 2:
      move(0, 0, 0);
      move(xres - 1, 0, 1);
      move(xres - 1, yres - 1, 1);
      move(0, yres - 1, 1);
      move(0, 0, 1);
      break;
    case 3:
      print(0, 0, "TICKS:", 40, 40, 16, 16);
      print(0, 56, ticksPerStep, 40, 40, 16);
      break;
    case 4:
      print(50, 50, ">", 60, 60, 16, 16);
      if(t&4)
      {
        move(76 + 50, 50 + 50, 0);
        move(120 + 50, 50 + 50, 1);
      }
      break;
    case 5:
      {
        int x0 = (xres - 256) / 2;
        int y0 = (yres - 256) / 2;        
        drawVectors(x0, y0, rickPoints, rickPointsCount);
        break;
      }
    default:
      print(0, 0, "NOPE!", 100, 100, 16, 16);
      mode = 0;
      break;
  }
//  print(0, 0, "S", 240, 240, 4, 10);
  //print(0, 0, "MENU:\nSHIFT\nSPEED\nSCALE", 32, 32, 8, 10);
//  print(0, 0, "PRIORITY 1\nRETURN ALIEN\n\nCREW\nEXPENDABLE", 32, 32, 10, 20);
//  print(0, 0, "WOULD\nYOU LIKE\nTO PLAY\nA GAME?", 32, 32, 10, 20);
}
  