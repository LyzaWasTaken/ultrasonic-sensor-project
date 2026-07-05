const byte trigpin = 9;
const byte echopin = 8;
const byte leds[] = {2, 3, 4, 5, 6};
const byte values[] = {35, 30, 25, 20, 15};

void setup() {
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  for(int i = 0; i < 5; i++){
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

   long distance = pulseIn(echopin, HIGH, 20000);

    for(int i = 0; i < 5; i++){
      long duration = distance * 0.034 / 2;
    if(duration <= values[i] && duration > 0){
      digitalWrite(leds[i], HIGH);
    }
    else{
      digitalWrite(leds[i], LOW);
    }
  }
}
