#pragma once

bool targetReached()
{
  int x = currentX + offsetX;
  int y = currentY + offsetY;
  return (x == targetX) && (y == targetY);
}

bool moveGalvo()
{
  int x = currentX + offsetX;
  int y = currentY + offsetY;
  bool sx = false;
  bool sy = false;
  //int onOff = 0;
  if(!onOff)
  {
    targetX = 0;
    targetY = 0;
  }
  if(onOff || (x != 0 || y != 0))
  {
    digitalWrite(EN, 0);
    if(x != targetX)
    {
      if(x < targetX)
      {
        currentX++;
        digitalWrite(X_DIR, 0);
      }
      else
      {
        currentX--;
        digitalWrite(X_DIR, 1);      
      }
      sx = true;
    }

    if(y != targetY)
    {
      if(y < targetY)
      {
        currentY++;
        digitalWrite(Y_DIR, 1);
      }
      else
      {
        currentY--;
        digitalWrite(Y_DIR, 0);      
      }
      sy = true;
    }
    if(sx)
      digitalWrite(X_STP, HIGH);
    if(sy)
      digitalWrite(Y_STP, HIGH);
    //yolo
    //delayMicroseconds(1);
    if(sx)
      digitalWrite(X_STP, LOW);
    if(sy)
      digitalWrite(Y_STP, LOW);
    //now delayed with timer
    //delayMicroseconds(stepDelay);
    return sx || sy;
  }
  else
  {
    digitalWrite(EN, 1);
    //now delayed with timer
    //delayMicroseconds(stepDelay);
  }
  return false;
}

void line(int x1, int y1, int x2, int y2)
{
  int m = max(abs(x1 - x2), abs(y1 - y2));
  if(m <= 1)
  {
    targetX = x1;
    targetY = y1;
    while(!targetReached());//moveGalvo();
  }
  else
  {
    int x3 = (x1 + x2) >> 1;
    int y3 = (y1 + y2) >> 1;
    line(x1, y1, x3, y3);
    line(x3, y3, x2, y2);
  }
}

void move(int x, int y, int luminance)
{
  if(luminance == 0)
  {
    digitalWrite(LASER, 0);
    targetX = x;
    targetY = y;
    while(!targetReached());//moveGalvo();
  }
  else
  {
    digitalWrite(LASER, onOff);
    line(targetX, targetY, x, y);
    digitalWrite(LASER, 0);
  }
}
