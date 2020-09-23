#include <Servo.h>

Servo servoY;
Servo servoX;



int min = 800;
int max = 1500;
int minX = 0;
int maxX = 90;
boolean movingRight = true;int servoXPosition = 0;
int servoYPosition = 0;


void setup() {

  
  Serial.begin(9600);
  
  servoY.attach(11); //Attach your own pins. These
  servoY.write(20); // are just my simple own settings
  
  servoX.attach(10); 
  servoX.write(0);
  
  delay(2000); 
  
}

void loop() {
  //Random delay to make movement more mouse like
  delay(random(min, max));

  //this code moves the laser in a figure 8 like fashion
    
    if(servoXPosition == 88){
      movingRight = false;
    }
    if(servoXPosition <= 0){
      movingRight = true;
    }

    
    if(movingRight){
      servoXPosition = servoXPosition + 11;
    }
    else{
      servoXPosition = servoXPosition - 11;
    }

    
   
    
    
    if(servoXPosition % 44 == 0 && movingRight == true){
      servoYPosition = servoYPosition + 20;    
    }
    else if(servoXPosition % 44 == 0 && movingRight == false){
      servoYPosition = servoYPosition - 20;
    }
    
    Serial.print(servoXPosition);
    //Serial.print(servoYPosition);
   
    //Serial.print(movingRight);
    
    servoX.write(servoXPosition);
    servoY.write(servoYPosition);
    
    
 
}
