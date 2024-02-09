//НАЖМИТЕ КНОПКУ ДЛЯ НАЧАЛА ГОЛОСОВАНИЯ
//ЖИПУ 
void create1Set(){
  lcd.createChar(8, rus_ZH); //Ж-8 И-1 Г-2 Л-3 П-4 Ы-5 У-6 Д-7
  lcd.createChar(1, rus_I);
  lcd.createChar(2, rus_G);
  lcd.createChar(3, rus_L);
  lcd.createChar(4, rus_P);
  lcd.createChar(5, rus_Y);
  lcd.createChar(6, rus_U);
  lcd.createChar(7, rus_D);
  
}
//ПРЕДАТЕЛЬ НЕ ВЫЯВЛЕН
//ГОЛОСОВАНИЕ АКТИВИРОВАНО
//ОПРЕДЕЛИТЕ ПРЕДАТЕЛЯ
//ИГРОК № 
//ГЛИ
//ПДЯ

//

void create2Set(){
  lcd.createChar(8, rus_myagk); // Я-1 Д-2 Л-3 И-4 П-5 Б-6  Ь-08
  lcd.createChar(1, rus_YA);
  lcd.createChar(2, rus_D);
  lcd.createChar(3, rus_L);
  lcd.createChar(4, rus_I);
  lcd.createChar(5, rus_P);
  lcd.createChar(6, rus_B);
  lcd.createChar(7, rus_Z);
  
}
//\x05PE\x02ATE\x03\x08 HE B\x04\x01B\x03EH
void create3Set(){
  lcd.createChar(8, rus_myagk); // Я-1 Д-2 Л-3 Ы-4 П-5 Б-6  Ь-08
  lcd.createChar(1, rus_YA);
  lcd.createChar(2, rus_D);
  lcd.createChar(3, rus_L);
  lcd.createChar(4, rus_Y);
  lcd.createChar(5, rus_P);
  lcd.createChar(6, rus_B);
  lcd.createChar(7, rus_Z);
  
}
void create4Set(){
  lcd.createChar(8, rus_ZH); //Ж-8 И-1 Г-2 Л-3 П-4 Ы-5 Я-6 Д-7
  lcd.createChar(1, rus_I);
  lcd.createChar(2, rus_G);
  lcd.createChar(3, rus_L);
  lcd.createChar(4, rus_P);
  lcd.createChar(5, rus_Y);
  lcd.createChar(6, rus_YA);
  lcd.createChar(7, rus_D);
  
}

//ПРЕДАТЕЛЬ ИГРОК
//ПДЛЬИГ

void create5Set(){
  lcd.createChar(8, rus_myagk); // И-1 Д-2 Л-3 Ы-4 П-5 Г-6  Ь-08
  lcd.createChar(1, rus_I);
  lcd.createChar(2, rus_D);
  lcd.createChar(3, rus_L);
  lcd.createChar(4, rus_Y);
  lcd.createChar(5, rus_P);
  lcd.createChar(6, rus_G);
  lcd.createChar(7, rus_Z);
  
}


void waitButtonDone()
{
    while (1==1)
  {
   if (btnDone.update())
   if (btnDone.read()==LOW)
    { 
      return;
    }
    
  }

}
void waitAnyButton()
{
  while (1==1)
  {
   for (int i=0;i<countbtn;i++)
   {

     if (btnarray[i].update())
      {
        if (btnarray[i].read()==LOW)
        { 
          Serial.println("======");
          return;        
        }
      }
   }
  }
} 


void voiceTUDO(){
  beep(200, 500);
  beep(200, 500);
  beep(200, 500);
  beep(100, 1000);
  beep(150, 500);
  beep(150, 500);
  beep(150, 500);
  beep(60, 1000);
}
