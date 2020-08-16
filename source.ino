int portArray[5]={2,4,7,8,12};
int mov=10;
int sensorPin = A0; // select the input pin for LDR
int sensorValue = 0;
bool testMode = false;
bool reset=false;

// 2 - Hal de entrada
// 4 - Sala de estar
// 7 - Cozinha
// 8 - Casa de banho
// 12 - Quarto
// 13 -- TEST MODE

void setup()
{
   for(int i=0;i<5;i++){
      pinMode(portArray[i], OUTPUT); 
    }
  pinMode(13, INPUT);
  Serial.begin(4800); //sets serial port for communication
  mov=random(5,10);
  if(digitalRead(13)==1){
    testMode=true;
  }
  Serial.println(digitalRead(13));
}

void loop()
{
  sensorValue = analogRead(sensorPin); // read the value from the sensor
  Serial.println(sensorValue);
  if(testMode){
    Serial.println("testing");
    for(int i=0;i<5;i++){
        digitalWrite(portArray[i], HIGH);
      }
  }else{
    if(sensorValue<30){
      Serial.println("Escuro");
      if(!reset){
        for(int mov=0;mov<random(5,10);mov++){
          for(int i=0;i<5;i++){
            bool ligadas=false;
            if(random(2)==0){
              Serial.print(portArray[i]);
              Serial.println(" Ligada");
             digitalWrite(portArray[i], HIGH); 
             ligadas=true;
            }else{
              Serial.print(portArray[i]);
              Serial.println(" Desligada");
              digitalWrite(portArray[i], LOW);
            }
            if(ligadas==false){
              digitalWrite(2, HIGH);
            }
          }
          Serial.println("=====================");
          delay(random(300000,3600000));
          //delay(5000); // for test only
        }
        Serial.println("Ir quarto");
        for(int i=0;i<5;i++){
          digitalWrite(portArray[i], LOW);
        }
        digitalWrite(12, HIGH);
        delay(random(300000,3600000));
        digitalWrite(12, LOW);
        delay(10800000);
        reset = true; 
      }else{
        delay(random(300000,3600000));
        if(random(10)==5){
          digitalWrite(12, HIGH);
          delay(random(60000,900000));
          digitalWrite(8, HIGH);
          delay(random(60000,900000));
          digitalWrite(8, LOW);
          delay(random(60000,900000));
          digitalWrite(12, LOW);
        }
      }
   }else{
      Serial.println("Claro");
      for(int i=0;i<5;i++){
        digitalWrite(portArray[i], LOW);
      }
      reset = false; 
      mov=random(5,10);
      delay(60000);
   }
}
 delay(100);
}
