//Social Engineering Community Youth Challenge
//DEFCON 2023 SEC Village
//SW by Cyber City Circuits @MakeAugusta

int LED1_1 =  3;
int LED1_2 =  5;  
int LED1_3 =  4;

int LED2_1 =  1;
int LED2_2 =  2;
int LED2_3 = 10; 

int LED3_1 =  9;
int LED3_2 =  7;
int LED3_3 =  8;

int LED_CENT = 0;

int Mode_Btn = 6;

int LED1[] = {LED1_1, LED1_2, LED1_3};
int LED2[] = {LED2_1, LED2_2, LED2_3};
int LED3[] = {LED3_1, LED3_2, LED3_3};

void setup() {
  for(int i = 0; i < 4; i++) {
    pinMode(LED1[i], OUTPUT); digitalWrite(LED1[i],HIGH);
    pinMode(LED2[i], OUTPUT); digitalWrite(LED2[i],HIGH);
    pinMode(LED3[i], OUTPUT); digitalWrite(LED3[i],HIGH);
    }
  pinMode(LED_CENT, OUTPUT);  digitalWrite(LED_CENT,HIGH);
  pinMode(Mode_Btn, INPUT_PULLUP);

  delay(500);

  for(int i = 0; i < 3; i++) {
    {digitalWrite(LED1[i], LOW);delay(200);}
    {digitalWrite(LED2[i], LOW);delay(200);}
    {digitalWrite(LED3[i], LOW);delay(200);}
  }
  analogWrite(LED_CENT, 255);
  for(int i = 255; i > 0; i = i - 1) {analogWrite(LED_CENT, i);delay(5);}
}


void loop() {
  if (digitalRead(Mode_Btn)== LOW){
    jigawatts();
  }
  
  for(int i = 0; i < 32; i = i + 1){analogWrite(LED_CENT, i);delay(20);}
  for(int i = 32; i > 0; i = i - 1){analogWrite(LED_CENT, i);delay(20);}
}

void jigawatts(){
  for(int i = 0; i < 255; i = i + 3) {
      analogWrite(LED_CENT, i);
      delay(5);
    }
    digitalWrite(LED_CENT, HIGH);
    for (int x = 0; x < 500 ; x = x+50){
      for(int i = 0; i < 3; i++) {
       digitalWrite(LED1[i], HIGH); 
       digitalWrite(LED2[i], HIGH);
       digitalWrite(LED3[i], HIGH);
       delay(x);
     }
      for(int i = 0; i < 3; i++) {
        digitalWrite(LED1[i], LOW); 
        digitalWrite(LED2[i], LOW); 
        digitalWrite(LED3[i], LOW);
        delay(x);
      }
    }
  }
