const int x = A0;
const int y = A1;
int valx = 0;
int valy = 0;
int xx=0;
int yy=0;
const int pin1 = 11;
const int pin2 = 10;
const int light1 = 13;
const int light2 = 12;

void setup() {
  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT);
  digitalWrite(light1, HIGH);
  digitalWrite(light2, HIGH);
  Serial.begin(9600);
}


void loop() {
  valy = (analogRead(y));
  valx = (analogRead(x)); 
  if (valy > 520)
  { yy = ((valy-520)/2);
    analogWrite(10, 255-yy);
    analogWrite(11, 255-yy);
    if (valx>520)
    {
      xx=((valx - 512)/4);
      analogWrite(6, 255-xx);
      analogWrite(5, 255);
    }
    if (valx<500)
    {
      xx = ((511 - valx)/4);
      analogWrite(6,255);
      analogWrite(5,255-xx);
    }
  }
  if (valy < 500)
  { yy = ((511 - valy)/2);
    analogWrite(5, 255-yy);
    analogWrite(6, 255-yy);
    if (valx>520)
    {
      xx=((valx - 512)/4);
      analogWrite(10, 255-xx);
      analogWrite(11, 255);
    }
    if (valx<500)
    {
      xx = ((511 - valx)/4);
      analogWrite(10,255);
      analogWrite(11,255-xx);
    }
  }
  if (valy < 520 && valy > 500)
  { analogWrite(10, 255);
    analogWrite(11, 255);
    if (valx>520)
    {
      xx=((valx - 512)/2);
      analogWrite(6, 255-xx);
      analogWrite(5, 255);
    }
    if (valx<500)
    {
      xx = ((511 - valx)/2);
      analogWrite(6,255);
      analogWrite(5,255-xx);
    }
  }


  
    
      

  Serial.print(yy);
  Serial.print("      ");
  Serial.println(xx);
}
