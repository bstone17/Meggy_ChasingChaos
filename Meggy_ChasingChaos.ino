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
  boolean dead;
};

Enemy e1 = {random(8), random(8), false};
Enemy e2 = {random(8), random(8), false};
Enemy e3 = {random(8), random(8), false};
Enemy e4 = {random(8), random(8), false};
Enemy e5 = {random(8), random(8), false};


Enemy enemies[5] = {e1,e2,e3,e4,e5};


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
  enemyCollision();
  playerCollision();
  DisplaySlate();
  ClearSlate();
}

boolean checkDupe (int x, int y)
{
  for(int i = 0; i < 5; i++)
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
  for(int i = 0; i < 5; i++)
  {
    if (enemies[i].dead == false)
    {
      DrawPx(enemies[i].x, enemies[i].y, Red);
    }
    if (enemies[i].dead == true)
    {
      DrawPx(enemies[i].x, enemies[i].y, Blue);
    }
  }
}

void pcMovement()
{
  CheckButtonsPress();
    {
      if (Button_Up)
      {
        pcy++;
        yenemyMovement();
        xenemyMovement();
      }
      if (pcy > 7)
      {
        pcy = 0;
      }
    }
    
    {  
      if (Button_Left)
      {
        pcx--;
        yenemyMovement();
        xenemyMovement();
      }
      if (pcx < 0)
      {
        pcx = 7;
      }
    }
    
    {    
      if (Button_Down)
      {
        pcy--;
        yenemyMovement();
        xenemyMovement();
      }
      if (pcy < 0)
      {
        pcy = 7;
      }
    }
    
    {  
      if (Button_Right)
      {
        pcx++;
        yenemyMovement();
        xenemyMovement();
      }
      if (pcx > 7)
      {
        pcx = 0;    
      }
    }
    {
      DrawPx(pcx,pcy,Green);  // Spawning of player controlled sprite
    }
}

void xenemyMovement()
{
  for(int i = 0; i < 5; i++)
  {
    if (enemies[i].dead == false)
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
}

void yenemyMovement()
{
  for(int i = 0; i < 5; i++)
  {
    if (enemies[i].dead == false)
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
}

void enemyCollision()
{
  for (int i = 0; i < 5; i++)
  {
    for(int j = 0; j < 5; j++)
    {
      if (i!=j)
      {
        if (enemies[i].x == enemies[j].x && enemies[i].y == enemies[j].y)
        {
          enemies[i].dead = true;
          enemies[j].dead = true; 
        }
      }
    }
  }
}

void playerCollision()
{
  for (int i = 0; i < 5; i++)
  {
    if (pcx == enemies[i].x && pcy == enemies[i].y)
    {
      DrawPx(3,7, Orange);
      DrawPx(3,6, Orange);
      DrawPx(3,5, Orange);
      DrawPx(3,4, Orange);
      DrawPx(3,3, Orange);
      DrawPx(3,2, Orange);
      DrawPx(3,1, Orange);
      DrawPx(3,0, Orange);
      DrawPx(4,0, Orange);
      DrawPx(5,0, Orange);
      DrawPx(6,0, Orange);
      DrawPx(7,0, Orange);
    }
  }
}

  



 





  

