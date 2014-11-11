int power = 8;
int red = 9;
int green = 11;
int blue = 10;
int redmax = 85;
int greenmax = 255;
int bluemax = 255;
int pattern[7][3] = {{100,0,0},
                       {100,100,0},
                       {0,100,0},
                       {0,100,100},
                       {0,0,100},
                       {100,0,100},
                       {100,100,100}};
boolean reddone = false;
boolean greendone = false;
boolean bluedone = false;
int stp = 0;
int redlev = 0;
int greenlev = 0;
int bluelev = 0;
int redstep = 0;
int greenstep = 0;
int bluestep = 0;

void setup()
{
  pinMode(power, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop()
{
  digitalWrite(power, HIGH);
  
  if (redlev < int(pattern[stp][0]*redmax)){
    redlev +=1;
  }
  else if (redlev > int(pattern[stp][0]*redmax)){
    redlev -=1;
  }
  else {
    reddone = true;
  }
  
  if (greenlev < int(pattern[stp][1]*greenmax)){
    greenlev +=1;
  }
  else if (greenlev > int(pattern[stp][1]*greenmax)){
    greenlev -=1;
  }
  else {
    greendone = true;
  }
  
  if (bluelev < int(pattern[stp][2]*bluemax)){
    bluelev +=1;
  }
  else if (bluelev > int(pattern[stp][2]*bluemax)){
    bluelev -=1;
  }
  else {
    bluedone = true;
  }
  
  analogWrite(red, redlev);
  analogWrite(green, greenlev);
  analogWrite(blue, bluelev);
  
  delay(30);
  
  if (reddone && greendone && bluedone){
    stp += 1;
    if(stp == 7){
      stp = 0;
    }
    reddone = false;
    greendone = false;
    bluedone = false;
  }
}
