#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int timer1;
int timer2;

float Time;

int flag1 = 0;
int flag2 = 0;

float distance = 5.0;
float Speed=0;
double calibrate=0;
float time_for_speed=0;

int ir_s1 = 6;
int ir_s2 = 7;

int buzzer = 13;
//Starting introduction
void setup(){
  pinMode(ir_s1, INPUT);
  pinMode(ir_s2, INPUT);
  pinMode(buzzer, OUTPUT);
  
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" WELCOME TO  ");
  lcd.setCursor(0,1);
  lcd.print("GROUP 3 PROJECT");
  delay(2000);
  lcd.clear();
}
// Speed Calculation
void loop() {
calibrate=millis();

  if(digitalRead(6)==1)
  {
    while(digitalRead(7)!=1);
    time_for_speed=millis()-calibrate;
    while(digitalRead(7)!=0);
    Speed=5000/time_for_speed;
   
}
//If there is no car No car detected will show
if(Speed==0){ 
lcd.setCursor(0, 1); 
if(flag1==0 && flag2==0){lcd.print("No car  detected");}
                    else{lcd.print("Searching...    ");} 
}
//shows whether the car has overspeeded or not
else{
    lcd.clear(); 
    lcd.setCursor(0, 0); 
    lcd.print("Speed:");
    lcd.print(Speed,1);
    lcd.print("Km/Hr  ");
    lcd.setCursor(0, 1); 
  if(Speed > 50){lcd.print("  Over Speeding  "); digitalWrite(buzzer, HIGH);}
            else{lcd.print("  Normal Speed   "); }    
    delay(3000);
    digitalWrite(buzzer, LOW);
    Speed = 0;
    flag1 = 0;
    flag2 = 0;    
 }
