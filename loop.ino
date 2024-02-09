void loop()
{
  
   for (int i=0;i<countbtn;i++)
 {
 if (btnarray[i].update())
  {
    if (btnarray[i].read()==LOW)
    { 
      Serial.print(i,DEC);
      Serial.println("----");
      countVote++;
      buttons_Click(i);
    }
  };
 }  
 if (btnDone.update())
  {
    if (btnDone.read()==LOW)
    { 
     // Serial.print("------------------------------");
    //asm volatile("jmp 0x00");
    if (Max(&maxnum, &maxnumindex)){
      
    //  printarray();
      Serial.print("maxnum-");
      Serial.println(maxnum);
      Serial.print("maxnumindex-");
      Serial.println(maxnumindex);
      printDone();
      waitAnyButton();
      asm volatile("jmp 0x00");
    }
    else{
      lcd.clear();
      //lcd.print("HET ");
      printNetPobedi();
      printarray();
      //delay(5000);
      asm volatile("jmp 0x00");
      }
    }
    
  }
  /*Функция принимает три аргумента
    1) Номер пина
    2) Частоту в герцах, определяющую высоту звука
    3) Длительность в миллисекундах. 
  */
  

  /* Вариант без установленной длительности   */
//  tone(piezoPin); // Запустили звучание
 // delay(500);
 // noTone(piezoPin); // Остановили звучание

}
