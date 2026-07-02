#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

int button=2;
int buzzer =7;
bool laststate=HIGH;
bool currentstate;
long end_time;
long start_time;
void countdown(){
  lcd.clear();
  for(int i=3;i>0;i--){
    lcd.setCursor(3,0);
    lcd.print(i);
    delay(1000);
  }
}

void show_result(long result){
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print(result);
}



void setup(){
pinMode(button,INPUT_PULLUP);
pinMode(buzzer,OUTPUT);
lcd.init();
lcd.backlight();
lcd.clear();
lcd.setCursor(3,0);
lcd.print("press to start");
while(true){
currentstate=digitalRead(button);
if(currentstate==LOW && laststate==HIGH){
  countdown();
  break;
}
}
lcd.setCursor(3,0);
lcd.print("go!");
start_time=millis();
laststate=HIGH;
tone(buzzer,500,100);
}


void loop(){
   
  currentstate=digitalRead(button);
    if(laststate==HIGH && currentstate==LOW){
   end_time=millis();
   long reaction_time=end_time-start_time;

   show_result(reaction_time);
   while(1){}
  }
  laststate=currentstate;
  }


  
