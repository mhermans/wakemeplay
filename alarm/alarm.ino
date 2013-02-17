
// user input pins

int doSupressPin = 5;
int doOffPin = 6;

// clock pins

int alarmStatePin = 2;
int alarmOffPin = 3;
int alarmSupressPin = 4;


void setup()                    // run once, when the sketch starts
{
  Serial.begin(9600);           // set up Serial library at 9600 bps
  
  // setup input pins
  
  pinMode(doSupressPin, INPUT);
  digitalWrite(doSupressPin, HIGH);
  
  pinMode(doOffPin, INPUT);
  digitalWrite(doOffPin, HIGH);
  
  // setup clock pins
  
  pinMode(alarmStatePin, INPUT);    // sets the digital pin as input to read switch
  digitalWrite(alarmStatePin, HIGH);
  
  pinMode(alarmOffPin, OUTPUT);      // sets the digital pin as output
  
  pinMode(alarmSupressPin, OUTPUT);
  digitalWrite(alarmSupressPin, HIGH);
}

void loop()                     // run over and over again
{
  Serial.print("Alarm state: ");
  Serial.println(digitalRead(alarmStatePin));    // Read the pin and display the value
  
  Serial.print("Relais/suppress state: ");
  Serial.println(digitalRead(alarmSupressPin));    // Read the pin and display the value

  Serial.print("Do suppress state: ");
  Serial.println(digitalRead(doSupressPin));    // Read the pin and display the value

  Serial.print("Do off state: ");
  Serial.println(digitalRead(doOffPin));    // Read the pin and display the value

    
  // detect supress call
  if (digitalRead(doSupressPin) == 0) {
    digitalWrite(alarmSupressPin, LOW);   // supress alarm
  }

  else  {
    digitalWrite(alarmSupressPin, HIGH);   // no supress signal -> relais on
  }

  // detect off call
  if (digitalRead(doOffPin) == 0) {
    digitalWrite(alarmOffPin, HIGH);   // schakel alarm uit
    delay(10);
    digitalWrite(alarmOffPin, LOW);   // mag niet op off blijven staan
  }

  
  // detect off call
  //if (digitalRead(doOffPin) == 1) {
  //  digitalWrite(alarmOffPin, HIGH);   // schakel alarm uit
  //}
  
  delay(1000);
}
