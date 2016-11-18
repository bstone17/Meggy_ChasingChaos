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

Enemy e1 = {random(8), random(8)};
Enemy e2 = {random(8), random(8)};
Enemy e3 = {random(8), random(8)};
Enemy enemies[3] = {e1,e2,e3};


int pcx = 4;
int pcy = 5;


void setup() 
{  
   MeggyJrSimpleSetup();      // Required code, line 2 of 2.
   Serial.begin(9600);
}

void loop() 
{             
  pcMovement();   
  spawn;
  drawEnemies();
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
  CheckButtonsPress();
    {
      if (Button_Up && pcy < 7)
      {
        pcy++;
        yenemyMovement();
        xenemyMovement();
      }
    }
    
    {  
      if (Button_Left && pcx > 0)
      {
        pcx--;
        yenemyMovement();
        xenemyMovement();
      }
    }
    
    {    
      if (Button_Down && pcy > 0)
      {
        pcy--;
        yenemyMovement();
        xenemyMovement();
      }
    }
    
    {  
      if (Button_Right && pcx < 7)
      {
        pcx++;
        yenemyMovement();
        xenemyMovement();
      }    
    }
    {
      DrawPx(pcx,pcy,Green);  // Spawning of player controlled sprite
    }
}

void xenemyMovement()
{
  for(int i = 0; i < 3; i++)
  {
    if (enemies[i].x > pcx)
    {
      enemies[i].x--;  
    }
    if (enemies[i].x < pcx)
    {
      enemies[i].x++;
    }
  }
}

void yenemyMovement()
{
  for(int i = 0; i < 3; i++)
  {
    if (enemies[i].y > pcy)
    {
      enemies[i].y--;
    }
    if (enemies[i].y < pcy)   
    {
      enemies[i].y++;
    }
  }
}

  



 





  

