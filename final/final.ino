  
// user input pins

int doSupressPin = 5;
int doOffPin = 6;

// clock pins

int alarmStatePin = 2;
int alarmOffPin = 3;
int alarmSupressPin = 4;

int rx_pin = 0;
int ry_pin = 2;

int rx = 0;
int ry = 0;
//int lx = 0;
//int ly = 0;

int movedir; //direction controler -> int 1|2|3|4

int input_code[4]; // tried code

int correct_code[4] = {4,2,3, 1}; // challenge code TODO make random

int pos_code = 0;

int as_discrete(int val)  {
  int dval ;
  if (val < 200) {
    dval = -1;
  }
  else if (val > 450) {
    dval = 1;
  }
  else {
    dval = 0;
  }
  return dval;
}

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
  
  // controller gedeelte
  int tmp_rx = as_discrete(analogRead(rx_pin));
  int tmp_ry = as_discrete(analogRead(ry_pin))*-1;

  //if neutral was reached
  if (rx == 0 && ry == 0 ) {

  // do not need (0,0) values
  if (tmp_rx != 0 || tmp_ry != 0) {
      if (tmp_rx == 0 && tmp_ry == 1) { movedir = 1; }
      if (tmp_rx == 1 && tmp_ry == 0) { movedir = 2; }
      if (tmp_rx == 0 && tmp_ry == -1) { movedir = 3; }
      if (tmp_rx == -1 && tmp_ry == 0) { movedir = 4; }
      Serial.println(movedir);
      
      input_code[pos_code] = movedir;
      
      if (input_code[pos_code] == correct_code[pos_code]) {
        pos_code = pos_code + 1;
        if (pos_code == 4) {
          Serial.print("Well done, go get breakfast!");
          digitalWrite(alarmOffPin, HIGH);   // schakel alarm uit
            delay(10);
            digitalWrite(alarmOffPin, LOW);   // mag niet op off blijven staan
        }
      }
      else {
        Serial.print("error, reset");
        pos_code = 0;
        int input_code[4] ;
      }
    }
  }

  rx = tmp_rx;
  ry = tmp_ry; 
  
  // alarm stuk
  
  // alarm gaat af
  
  if (digitalRead(alarmStatePin) == 1) {
    Serial.println("ALARM! Enter code: 4231");
  }
  
  
  //Serial.print("Alarm state: ");
  //Serial.println(digitalRead(alarmStatePin));    // Read the pin and display the value
  
  //Serial.print("Relais/suppress state: ");
  //Serial.println(digitalRead(alarmSupressPin));    // Read the pin and display the value

  //Serial.print("Do suppress state: ");
  //Serial.println(digitalRead(doSupressPin));    // Read the pin and display the value

  //Serial.print("Do off state: ");
  //Serial.println(digitalRead(doOffPin));    // Read the pin and display the value

    
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
  
  delay(20);
}
