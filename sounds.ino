void sirena()
{
  long prevtime=millis();
  for (int i = 600 ; i<800;i++)
  {
     if (sound) tone(buzzer, i,10);
   delay(5);
    
  }
   if (sound)tone(buzzer, 800,100);
   delay(80);
  for (int i = 800 ; i>600;i--)
  {
   if (sound)tone(buzzer, i,10);
   delay(5);
  }
   if (sound) tone(buzzer, 600,100);
   delay(80);
}

void sirenalong(int var )
{
  for (int i=0;i<var;i++)
  {
    sirena();
  }
  
}

void beep(int ton, int time)
{
 if (sound) tone(buzzer, ton, time);
  delay(time + 20);
}
