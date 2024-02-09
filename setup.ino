void setup()
{
  Serial.begin(9600);
  //Serial.println("1---");
  // Инициализация lcd
  lcd.init();                            
  lcd.backlight();
  
  
  //Инициализация кнопок
  for (int i=0;i<countbtn;i++)
  {
    //pinMode(btnpins[i],INPUT_PULLUP);
    btnarray[i]=Bounce();
    btnarray[i].attach(btnpins[i]);
    btnarray[i].interval(10); // interval in ms
  }
  
  btnDone.attach(btnPinDone);
  btnDone.interval(5); // interval in ms
  lcd.clear();

  
  lcd.clear();
  Serial.println("1------++++");
  printOpredeliPredatelya1();
  Serial.println("2------++++");
  sirenalong(5);
  printOpredeliPredatelya1();

}
