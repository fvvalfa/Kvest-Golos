#include "leters.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Bounce2.h>

#define sound 1

    int maxnum;
    int maxnumindex;


const int  btn1=1;
const int  btn2=0;
const int  btn3=2;  
const int  btn4=3;  
const int  btn5=4;  
const int  btn6=5;  
const int  btn7=6;  
const int  btn8=7;  
const int  btn9=8;  
const int  btn10=9;  
const int  btn11=10;  
const int  btn12=11;  
const int  btn13=12;  
#define btn14 14 
#define btn15 15
//const int  btn16=16;  

const int btnPinDone=16;
//const int btnDone=17;                         
const int countbtn=15;
int WinPlayer;

#define buzzer  A3


int btnpins[countbtn]= {
      btn1,
      btn2,
      btn3,  
      btn4,  
      btn5,  
      btn6,  
      btn7,  
      btn8,  
      btn9,  
      btn10,  
      btn11,  
      btn12,  
      btn13,  
      btn14,  
      btn15,  
    };

int i;

Bounce btnarray[countbtn]={};

Bounce btnDone = Bounce();
//ГОЛОСОВАНИЕ АКТИВИРОВАНО
//ОПРЕДЕЛИТЕ ПРЕДАТЕЛЯ

//ГЛИПДЯ

//ПРЕДАТЕЛЬ УСТАНОВЛЕН

//НАЖМИТЕ КНОПКУ ДЛЯ НАЧАЛА ГОЛОСОВАНИЯ

//ЖИПДЛЯЧГ


int btnPressed[countbtn]={};
int btnPressednew[countbtn]={};

LiquidCrystal_I2C lcd(0x27,20,4);   /* Задаем адрес и размерность дисплея. 
При использовании LCD I2C модуля с дисплеем 20х04 ничего в коде изменять не требуется, cледует только задать правильную размерность */

void getresetbutton()
{
 if (btnDone.update())
  {
    if (btnDone.read()==LOW)
    { 
     Serial.print("------------------------------");
    asm volatile("jmp 0x00");
    }
}
}
void printStar(String ch, int x, int y){
    int delpaus=40;
    lcd.setCursor(x, y);    
    lcd.print(ch);        
    delay(25);
   if (sound) tone(buzzer, random(400,600), 450); 
}
void printBorder(String  ch){
  for (i=0;i<19;i++){
    printStar(ch,i,0);    
  }
  for (int y=0;y<4;y++){
    printStar(ch,i,y);    
  }
  for (i=19;i>0;i--){
    printStar(ch,i,3);    
  }
  for (int y=3;y>=0;y--){
    printStar(ch,i,y);    
  }
}

void printDone(){
  
  lcd.clear();
  lcd.setCursor(7, 1);
  //Ж-8 И-1 Г-2 Л-3 П-4 Ы-5 У-6 
  //lcd.print("B\x05\x01\x02PA");
  //ПРЕДАТЕЛЬ УСТАНОВЛЕН
  create3Set();
//HA\x08M\x01TE KHO\x04K\x06
//ПРЕДАТЕЛЬ ВЫЯВЛЕН
//\x05PE\x02ATE\x03\x08 HE B\x04\x01B\x03EH
  String s="";
  lcd.setCursor(0, 0);    
  lcd.print("--------------------");

  lcd.setCursor(2, 1);    
  lcd.print("\x05");
  lcd.print("PE");
  lcd.print("\x02");
  lcd.print("ATE");
  lcd.print("\x03");
  lcd.print("\x08");
  lcd.print(" ");
  
 // lcd.setCursor(10, 1);  
  
 // lcd.setCursor(7, 2);  
  lcd.print("B");
  lcd.print("\x04");
  lcd.print("\x01");
  lcd.print("B");
  lcd.print("\x03");
  lcd.print("EH");


  

  for (int o=1;o<2;o++)
  {
    printBorder("*");
    printBorder(" ");
    printBorder("*");
  }
// И-1 Д-2 Л-3 Ы-4 П-5 Г-6  Ь-08
  lcd.clear();
  lcd.setCursor(7, 1);
  /// И-1 Д-2 Л-3 Ы-4 П-5 Г-6  Ь-08
  //lcd.print("B\x05\x01\x02PA");
  //ПРЕДАТЕЛЬ УСТАНОВЛЕН
  create5Set();
   lcd.setCursor(2, 1);    
  lcd.print("\x05");
  lcd.print("PE");
  lcd.print("\x02");
  lcd.print("ATE");
  lcd.print("\x03");
  lcd.print("\x08");
  lcd.print(" ");
  lcd.print("\x01\x06\POK");
  lcd.setCursor(9, 2);    
  lcd.print(maxnumindex+1);
  for (int o=1;o<3;o++)
  {
    printBorder("*");
    printBorder(" ");
    printBorder("*");
  }

  
  
}


void displayKeyCodes(void) {
  uint8_t i = 0;
  while (1) {
    lcd.clear();
    lcd.print("Codes 0x"); lcd.print(i, HEX);
    lcd.print("-0x"); lcd.print(i+16, HEX);
    lcd.setCursor(0, 1);
    for (int j=0; j<16; j++) {
      lcd.write(i+j);
    }
    i+=16;
    
    delay(4000);
  }
}

//ПРОГОЛОСОВАЛО 
//ПГЛИ
void printOpredeliPredatelya1()
{
  create4Set();
  lcd.setCursor(0,2);
  lcd.print("O");
  lcd.print("\x04");
  lcd.print("PE");
  lcd.print("\x07");
  lcd.print("E");
  lcd.print("\x03");
  lcd.print("\x01");
  lcd.print("TE ");
  lcd.print("\x04");
  lcd.print("PE");
  lcd.print("\x07");
  lcd.print("ATE");
  lcd.print("\x03");
  lcd.print("\x06");
}
void printOpredeliPredatelya2()
{
  create4Set();
  lcd.setCursor(5,0);
  lcd.print("\x02");
  lcd.print("O");
  lcd.print("\x03");
  lcd.print("OCOBAH");
  lcd.print("\x01");
  lcd.print("E");
  lcd.setCursor(4,1);
  lcd.print("AKT");
  lcd.print("\x01");
  lcd.print("B");
  lcd.print("\x001");
  lcd.print("POBAHO!");
}
void printNetPobedi(){
  create3Set();
//HA\x08M\x01TE KHO\x04K\x06
//ПРЕДАТЕЛЬ НЕ ВЫЯВЛЕН
//\x05PE\x02ATE\x03\x08 HE B\x04\x01B\x03EH
  String s="";
  lcd.setCursor(0, 0);    
  lcd.print("--------------------");

  lcd.setCursor(0, 1);    
  lcd.print("\x05");
  lcd.print("PE");
  lcd.print("\x02");
  lcd.print("ATE");
  lcd.print("\x03");
  lcd.print("\x08");
  lcd.print(" ");
  
 // lcd.setCursor(10, 1);  
  lcd.print("HE ");
 // lcd.setCursor(7, 2);  
  lcd.print("B");
  lcd.print("\x04");
  lcd.print("\x01");
  lcd.print("B");
  lcd.print("\x03");
  lcd.print("EH");
  lcd.setCursor(0, 2);    
  lcd.print("--------------------");
  voiceTUDO();
  waitAnyButton();  
  for (int i=0;i<countbtn;i++)
  {
    s=s+String(i+1)+"-"+String(btnPressed[i])+" ";
  }
  lcd.clear();
  lcd.setCursor(0, 0);    
  lcd.print(s.substring(0,19));
  lcd.setCursor(0, 1);    
  lcd.print(s.substring(20,39));
  lcd.setCursor(0, 2);    
  lcd.print(s.substring(40,59));
  lcd.setCursor(0, 3);    
  lcd.print(s.substring(60,s.length()));
  Serial.print("S=");
  Serial.println(s);
  waitAnyButton();  
}
void najmiteknopku(int x, int y){
  lcd.setCursor(x, y);    
  lcd.print("HA");
  lcd.print("\x08M\x01TE KHO\x04K\06");         

}





void sort(){
  for (int i=0;i<countbtn-1;i++)
  {
    btnPressednew[i]= btnPressed[i];
  }
  int old;
  for (int i=0;i<countbtn;i++)
  {
    for (int p=i+1;p<countbtn-1;p++)
    if (btnPressednew[i]<btnPressednew[p]){
      old=btnPressednew[i];
      btnPressednew[i]=btnPressednew[p];
      btnPressednew[p]=old;
    }
  }
}

bool Max(int* maxnum,int* maxnumindex ){
  *maxnum = btnPressed[0];
  *maxnumindex=0;
  
  for (int i=1;i<countbtn;i++)
  {
    if (btnPressed[i]>*maxnum){
      *maxnumindex=i;
      *maxnum=btnPressed[i];
    }
  }
  for (int i=0;i<countbtn;i++)
  {
    if ((btnPressed[i]==*maxnum)&&(i!=*maxnumindex))
    {
      return false;
    }
  }
    return true;
}
void printarray(){
  Serial.println("------");
  for (int i=0;i<countbtn;i++)
{
  Serial.println(btnPressed[i]);
}  
}
int countVote;
void buttons_Click(int i)
{
  
      Serial.println(i+1,DEC);
     btnPressed[i]++;
     if (sound) tone(buzzer, 200, 200); // Звук прекратится через 500 мс, о программа останавливаться не будет!
  //Ж-8 И-1 Г-2 Л-3 П-4 Ы-5 Я-6 Д-7
  //Ж-8 И-1 Г-2 Л-3 П-4 Ы-5 Я-6 Д-7
     lcd.setCursor(3,3);
     lcd.print("\x04");//П
     lcd.print("PO");//PO
     lcd.print("\x02");//Г
     lcd.print("O");//O
     lcd.print("\x03");//Л
     lcd.print("OCOBA");//OCOBA
     lcd.print("\x03");//Л
     lcd.print("O ");//П
     lcd.print(countVote);
     lcd.print("     ");
     //lcd.print("    ");
     //lcd.setCursor(5, 2);                   
     //lcd.print(btnPressed[i]);
     //lcd.print(" PA\x07   ");
     //lcd.print("B\x05\x01\x02PA\x03 \x01\x02POK- ");            // Выводим текст
      
    
      
      Serial.println(i,DEC);
}
