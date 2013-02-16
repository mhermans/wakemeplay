int rx_pin = 0;
int ry_pin = 1;

int rx = 0;
int ry = 0;
//int lx = 0;
//int ly = 0;

int as_discrete(int val)  {
  int dval ;
  if (val < 350) {
    dval = -1;
  }
  else if (val > 650) {
    dval = 1;
  }
  else {
    dval = 0;
  }
  return dval;
}

//int read_position() {
//  rx = as_discrete(analogRead(rx_pin));
//  ry = as_discrete(analogRead(ry_pin))*-1;
  //TODO y positions
//}


void setup()
{
  Serial.begin(9600);          //  setup serial
}

void loop()
{
  //Serial.println(analogRead(ry_pin));
  int tmp_rx = as_discrete(analogRead(rx_pin));
  int tmp_ry = as_discrete(analogRead(ry_pin))*-1;
  //Serial.println(tmp_ry);

  //Serial.print("RX, RY: ");
  //if neutral was reached
  if (rx == 0 && ry == 0 ) {
//    if (tmp_rx != 0 && tmp_ry != 0 ) {
  if (tmp_rx != 0 || tmp_ry != 0) {
      Serial.print(tmp_rx);
      Serial.println(tmp_ry);
    }
  }

  rx = tmp_rx;
  ry = tmp_ry; 
  delay(20);
};
