#include <Keypad.h>
#include <Servo.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);//les pin du capteur dans un ordre

Servo myservo;
#define ir_back  10//pin du capteur
#define ir_front 11
int led=12;
int flag1=0, flag2=0, flag3=0;

char data;//variable yet7at fiha données ml qt
String mot="";//code client  

const byte ROWS = 4; 
const byte COLS = 4; 

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {8, 7, 6, 5};//changeable:les pins de la carte arduino 
byte colPins[COLS] = {4, 3, 2, 1}; 

Keypad mykeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup(){

  pinMode(ir_back, INPUT);
  myservo.attach(9);//pin du servo
  myservo.write(90);//angle du servo*
  pinMode(led, OUTPUT);
  lcd.init();
  lcd.backlight();
  //lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("SQUADDESK Parking");
 // lcd.blink();  
  Serial.begin(9600);
}
  
void loop(){
 
    char key = mykeypad.getKey();
    
    /*if(key=='1')
    {
      Serial.write('1');
    }else if(key=='0')
    {
      Serial.write('0');
    }*/

    if(key!='#' and (key>='0' and key<='9'))
    {
      mot=mot+key;
    } else if(key=='#' and (key!='0' and key!='1' and key!='2' and key!='3' and key!='4' and key!='5' and key!='6' and key!='7' and key!='8' and key!='9'))
    {
      Serial.print(mot);
    }
    
    
    data=Serial.read();
    if(data=='1')
    {
      flag1=1;
      pinMode(ir_back, INPUT);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("acces possible");
    }
    else if(data=='0')
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("acces impossible");
    }
    
    if(digitalRead(ir_front)==0 and flag1==1)
    {
        myservo.write(90);
    }else if(digitalRead(ir_front)!=0 )
    {
      
      if(digitalRead(ir_back)==0 )
    {
      myservo.write(90);
        
    }else if(digitalRead(ir_back)!=0 )
    {
      myservo.write(180);
    }
    }

    

    if(flag1==1)
    {
      flag1=0;
reset();      
    }
    
  
}
void reset()
{
  lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SQUADDESK Parking");  
}
