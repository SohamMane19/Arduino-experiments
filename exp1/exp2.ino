#define D1 D1
void setup(){ 
  pinMode(D1,OUTPUT); // initialize digital pin LED_BUILTIN as an output.
}
/*
long leg-D1
short leg-one t of resistor
one leg of resistor-gnd
*/

void loop(){
  digitalWritse(D1,HIGH);
  delay(1000);  
                     // wait for a second
  digitalWrite(D1,LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
