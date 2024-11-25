volatile bool cancelPrint = false;

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
      long x = x0 + ((long(font[c][i][0]) * sx) >> 8);
      long y = y0 + ((long(font[c][i][1]) * sy) >> 8);
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
    if(cancelPrint)
    {
      cancelPrint = false;
      return;
    }
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

void drawDigit(int *x, int y, int number, int sx = 256, int sy = 256, int spaceX = 0)
{
  if(number > 9)
    drawDigit(x, y, number / 10, sx, sy, spaceX);
  drawChar(*x, y, '0' + number % 10, sx, sy);
  *x += sx + spaceX;
}

void print(int x0, int y0, long number, int sx = 256, int sy = 256, int spaceX = 0)
{
  if(number < 0)
  {
    drawChar(x0, y0, '-', sx, sy);
    x0 += sx + spaceX;
    number = -number;
  }
  drawDigit(&x0, y0, number, sx, sy, spaceX);
}