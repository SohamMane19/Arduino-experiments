#define D1 D1
void setup(){ 
  pinMode(D1,OUTPUT); // initialize digital pin LED_BUILTIN as an output.
}

void loop(){
  digitalWrite(D1,HIGH);
  delay(1000);  
// wait for a second
  digitalWrite(D1,LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
