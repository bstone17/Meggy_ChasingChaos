// Meggy_ChasingChaos By: Ikaika Stone

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

struct Point
{  
  int x;
  int y;
};

Point pc = {4,5};   // Spawn point for player controlled sprite
int direction = 0;

void setup() 
{  
   MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}

void loop() 
{              // says function definition is not allowed here before '{' token
  DrawPx(pc.x,pc.y,Green);    // Draw player's dot in green
  DisplaySlate();
  ClearSlate();
}

void pcMovement()
{
  CheckButtonsDown();
  {
    if (Button_Up) 
    {
      direction = 360;
    }
    if (Button_Right) 
    {
      direction = 90;
    }
    if (Button_Down) 
    {
      direction = 180;
    }
    if (Button_Left) 
    {
    direction = 270;
    }
  }  
} 



  

