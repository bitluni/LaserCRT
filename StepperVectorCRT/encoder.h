#pragma once
int handleButton(int button, int debounceIterations = 64)
{
  static int waitForButton = 0;
  static int lastButton = 0;
  if(waitForButton > 0)
  {
    waitForButton--;
    return 0;
  }
  if(lastButton == 1 && button == 0)
  {
    waitForButton = debounceIterations;
    lastButton = button;
    return 1;
  }
  lastButton = button;
  return 0;
}

int handleEncoder(int A, int B, int debounceIterations = 1)
{
  static int waitForIdle = 1;

  if(waitForIdle > 1)
  {
    waitForIdle--;
    return 0;
  }
  if(A && B)
  {
    waitForIdle = 0;
    return 0;
  }
  if(!waitForIdle)
  {
    if(A && !B)
    {
      waitForIdle = debounceIterations;
      return 1;
    }
    if(!A && B)
    {
      waitForIdle = debounceIterations;
      return -1;
    }
  }
  return 0;
}