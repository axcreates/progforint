int xValue = 0;
int yValue = 0; 
int bValue = 0;
int xMove;
int yMove;
int lPin = 6;
int gPin = 7;
int xMove1=0;
int yMove1=0;

void setup()  
{ 
  pinMode(8,INPUT); 
  digitalWrite(8,HIGH); 
  pinMode(lPin, OUTPUT);
  digitalWrite(lPin, LOW);
  pinMode(gPin, OUTPUT);
  digitalWrite(gPin, LOW);
 
  Serial.begin(9600) ;

} 

void loop() 
{ 
  xValue = analogRead(A0);  
  yValue = analogRead(A1); 
  bValue = digitalRead(8);

//right
  if (xValue > 1000){
     xMove = 1;
  }
//left
  else if (xValue < 50){
    xMove = -1;
  }
  else if (50<= xValue <= 1000){
    xMove = 0;
  }
  
//down
  if (yValue > 1000){
     yMove = 1;
  }
//up
  else if (yValue < 50){
    yMove = -1;
  }
  else if (50<= yValue <= 1000){
    yMove = 0;
  }

 
  if (xMove1 != xMove || yMove1 != yMove){
    Serial.print(xMove, DEC); //Serial.write better (write specific byte count also)
    Serial.print(",");
    Serial.print(yMove, DEC);
    Serial.print(",");
    Serial.print(!bValue);
    Serial.print("\n");

    xMove1 = xMove;
    yMove1 = yMove;
  }
  
  if (Serial.available ( ) == 0) {
    digitalWrite(lPin, LOW);
  }
  if (Serial.available ( ) > 0) {   
    char state = Serial.read ( );    // Reading the data received and saving in the state variable
    
    if(state == '0'){             // If received data is '0', then turn on LED
      digitalWrite (lPin, HIGH); 
      delay(100);
      digitalWrite (lPin, LOW);
    }  

    else if(state == '1'){
      digitalWrite(lPin, LOW);
    }
    
    else if (state == '2') {     // If received data is '1', then turn off led
      for (int i=0; i<20; i++){
         digitalWrite (lPin, HIGH);
          delay(50);
          digitalWrite (lPin, LOW);
          delay(50);
      }
    } 
  } 

}
