
int led = 9;
int state;
int incomingByte = 0;
char outgoingBuf[128];

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    if(Serial.peek() == 'c')
    {
      incomingByte = Serial.read();
      state = Serial.parseInt();
      digitalWrite(led,state);
      Serial.write("I received: ");
      Serial.write(incomingByte);
      Serial.write("\n");
      sprintf(outgoingBuf, "(printf test) I received: %d\n", incomingByte);
      Serial.print(outgoingBuf);
    }
    while(Serial.available() > 0)
    {
      Serial.read();
    }
  }

}
