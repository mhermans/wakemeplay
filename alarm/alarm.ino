int alarmInPin = 2;
int alarmOffPin = 3;


void setup()                    // run once, when the sketch starts
{
  Serial.begin(9600);           // set up Serial library at 9600 bps
  pinMode(alarmInPin, INPUT);    // sets the digital pin as input to read switch
  digitalWrite(alarmInPin, HIGH);
  pinMode(alarmOffPin, OUTPUT);      // sets the digital pin as output
}

void loop()                     // run over and over again
{
  Serial.print("Read alarm input: ");
  Serial.println(digitalRead(alarmInPin));    // Read the pin and display the value
  //Serial.print("Read alarm input: ");
  //Serial.println(digitalRead(alarmPin));    // Read the pin and display the value
  delay(1000);
}
