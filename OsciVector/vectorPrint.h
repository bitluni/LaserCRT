#pragma once
#include "font.h"
void move(int x, int y, int luminance);
void drawChar(int x0, int y0, char c, int sx = 256, int sy = 256)
{
  if(c < ' ' || c > 'Z') return;
  c-=' ';
  bool restart = true;
  int x = 0;
  int y = 0;
  for(int i = 0; i < maxLinesPerChar; i++)
  {
    if(font[c][i][0] == 255)
      restart = true;    
    else
    {
      int x = x0 + ((int(font[c][i][0]) * sx) >> 8);
      int y = y0 + ((int(font[c][i][1]) * sy) >> 8);
      if(!restart)
        move(x, y, 1);
      else
        move(x, y, 0);
      restart = false;
    }
  }
}

void print(int x0, int y0, const char *text, int sx = 256, int sy = 256, int spaceX = 0, int spaceY = 0)
{
  int x = x0;
  int y = y0;
  while(*text)
  {
    if(*text == '\n')
    {
      x = x0;
      y += sy + spaceY;
    }
    else
    {
      drawChar(x, y, *text, sx, sy);
      x += sx + spaceX;
    }
    text++;
  }
}