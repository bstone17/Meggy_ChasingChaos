// Meggy_ChasingChaos By: Ikaika Stone

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

struct Point
{  
  int x;
  int y;
};

struct Enemy        
{
  int x;
  int y;
};

Enemy e1 = {0,0};
Enemy e2 = {0,0};
Enemy e3 = {0,0};
Enemy enemies[3] = {e1,e2,e3};

int direction = 0;

  // Spawn point for player controlled sprite
int pcx = 4;
int pcy = 5;

void setup() 
{  
   MeggyJrSimpleSetup();      // Required code, line 2 of 2.
   Serial.begin(9600);
}

void loop() 
{             
  DrawPx(pcx,pcy,Green);    // Draw player's dot in green
  DisplaySlate();
  ClearSlate();
}

boolean checkDupe (int x, int y)
{
  for(int i = 0; i < 3; i++)
  {
    if (x == enemies[i].x)
    {
      if(y == enemies[i].y)
        return true;
    }
  }
  return false;
}

void spawn (int index)
{
  // generate a random x
  // generate a random y
  int x;
  int y;
  do
  {
    x = random(8);
    y = random(8);
  }
  while(checkDupe(x,y) == true);
  enemies[index].x = x;
  enemies[index].y = y;
}

void drawEnemies()
{
  for(int i = 0; i < 3; i++)
  {
    DrawPx(enemies[i].x, enemies[i].y, Red);
  }
}

void pcMovement()
{
  CheckButtonsDown();
    {
      if (Button_Up && pcy < 7)
      {
        pcy++;
      }
    }
    
    {  
      if (Button_Left && pcx > 0)
      {
        pcx--;
      }
    }
    
    {    
      if (Button_Down && pcy > 0)
      {
        pcy--;
      }
    }
    
    {  
      if (Button_Right && pcx < 7)
      {
        pcx++;
      }    
    }
}
 





  

