import processing.serial.*;
Serial Puerto;
PImage back;
void setup()
{
  fullScreen();
  Puerto = new Serial(this, "COM3", 9600);
  back = loadImage("p.jpg");
}
void draw()
{
    background(back);
  
  if (keyPressed) 
  {  
    Puerto.write(char(key));
  }
}
