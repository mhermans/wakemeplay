int rx_pin = 0;
int ry_pin = 2;

int rx = 0;
int ry = 0;
//int lx = 0;
//int ly = 0;

int movedir;

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

void setup()
{
  Serial.begin(9600);          //  setup serial
}

void loop()
{
  //Serial.println(analogRead(rx_pin));
  //  Serial.println(analogRead(ry_pin));
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
      Serial.print(movedir);
    }
  }

  rx = tmp_rx;
  ry = tmp_ry; 
  delay(20);
};
