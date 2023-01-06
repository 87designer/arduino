int LED1 = 10; //pins 10-12 are to be LED outputs
int LED2 = 11;
int LED3 = 12;
int Switch1 = 2;  //pins 2-4 are to be switch inputs
int Switch2 = 3;
int Switch3 = 4;
int blink_count = 0; // a way to limit the else/"OFF" blink count
 
void setup() {
//now setup our input and output pins accordingly
 pinMode(LED1, OUTPUT);
 pinMode(LED2, OUTPUT);
 pinMode(LED3, OUTPUT);
 pinMode(Switch1, INPUT);
 pinMode(Switch2, INPUT);
 pinMode(Switch3, INPUT);
 
}
 
void loop() {
 //now within loop() we'll take actions based on the status of the switches

// If Only Switch 1 is ON alternate blinking its corresponding LED and the remaining LEDs
 if ((digitalRead(Switch1) == HIGH) && (digitalRead(Switch2) != HIGH) && (digitalRead(Switch3) != HIGH)) {
  blink_count = 0;
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  delay(500);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  delay(500);
 }

// If Only Switch 2 is ON alternate blinking its corresponding LED and the remaining LEDs
 if ((digitalRead(Switch1) != HIGH) && (digitalRead(Switch2) == HIGH) && (digitalRead(Switch3) != HIGH)) {
  blink_count = 0;
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, LOW);
  digitalWrite(LED1, LOW);
  delay(500);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED1, HIGH);
  delay(500);
 }

// If Only Switch 3 is ON alternate blinking its corresponding LED and the remaining LEDs
 if ((digitalRead(Switch1) != HIGH) && (digitalRead(Switch2) != HIGH) && (digitalRead(Switch3) == HIGH)) {
  blink_count = 0;
  digitalWrite(LED3, HIGH);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  delay(500);
  digitalWrite(LED3, LOW);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  delay(500);
 }

// If Any 2 Switches are ON at the same time make all lights blink in concert
 if (((digitalRead(Switch1) == HIGH) && (digitalRead(Switch2) == HIGH) && (digitalRead(Switch3) != HIGH))
 || ((digitalRead(Switch1) != HIGH) && (digitalRead(Switch2) == HIGH) && (digitalRead(Switch3) == HIGH))
 || ((digitalRead(Switch1) == HIGH) && (digitalRead(Switch2) != HIGH) && (digitalRead(Switch3) == HIGH))) {
  blink_count = 0;
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  delay(500);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  delay(500);
 }

// If All Switches are ON at the same time Make all LEDs Always on
 if ((digitalRead(Switch1) == HIGH) && (digitalRead(Switch2) == HIGH) && (digitalRead(Switch3) == HIGH)) {
  blink_count = 0;
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
 }

// If All Switches are turned off Blink all LEDs 2x
 else {
   // prevent unwanted blinking due to combinations not considered
   if((digitalRead(Switch1) == HIGH) || (digitalRead(Switch2) == HIGH) || (digitalRead(Switch3) == HIGH)) {
 }
 else {
     while (blink_count < 2 ){
      delay(100);
      digitalWrite(LED1, HIGH); // turn LED OFF
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      delay(100);
      digitalWrite(LED1, LOW); // turn LED OFF
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      blink_count += 1;
   }

   }

 }
 
}
