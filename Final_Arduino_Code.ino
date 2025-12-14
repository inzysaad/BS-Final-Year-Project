const int lfmf = 13;   // L298N control pins
const int lfmr = 12;
const int lbmf = 8;
const int lbmr = 11;
const int rfmf = 6;
const int rfmr = 7;
const int rbmf = 4;
const int rbmr = 2;

const int pwm1 = 10;
const int pwm2 = 9;
const int pwm3 = 5;
const int pwm4 = 3;

const int sensor = A0;                 // analog pin used to connect the sharp sensor 
const int inter1 = 14;
const int inter2 = 15;
const int inter3 = 16;
const int inter4 = 17;

const int buzzer = 44;

int sen_val = 0;                 // variable to store the sen_values from sensor(initially zero)
int pwm_val = 10 ;
int pwm_turn_val = 170;
int x = 50; 
int a = 0;
int b = 0;
int c = 0;
int d = 0;
int sig = 0;

void setup()
{
  Serial.begin(9600);               // starts the serial monitor
  pinMode(lfmf, OUTPUT);
  pinMode(lfmr, OUTPUT);
  pinMode(lbmf, OUTPUT);
  pinMode(lbmr, OUTPUT);

  pinMode(rfmf, OUTPUT);
  pinMode(rfmr, OUTPUT);
  pinMode(rbmf, OUTPUT);
  pinMode(rbmr, OUTPUT);

  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(pwm3, OUTPUT);
  pinMode(pwm4, OUTPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(sensor, INPUT);
  pinMode(inter1, INPUT);
  pinMode(inter2, INPUT);
  pinMode(inter3, INPUT);
  pinMode(inter4, INPUT);

}

void loop()
{
  while(1)
  {
//    a=0,b=0,c=0,d=0;
    sig=0;
    sen_val = analogRead(sensor);       // reads the sen_value of the sharp sensor
    a=digitalRead(inter1);
    b=digitalRead(inter2);    
    c=digitalRead(inter3);
    d=digitalRead(inter4);
    Serial.println(a);
    Serial.println(b);
    Serial.println(c);
    Serial.println(d);
//    Serial.println(sen_val); 
    Serial.println("------------");
   
    if(a==HIGH && b==LOW && c==LOW && d==LOW)
    {
      sig=1;
    }
    else if(b==HIGH && a==LOW && c==LOW && d==LOW)
    {
      sig=2;
    }  
    else if(c==HIGH && b==LOW && a==LOW && d==LOW)
    {
      sig=3;
    }  
    else if(d==HIGH && b==LOW && c==LOW && a==LOW)
    {
      sig=4;
    }
    else if(a==HIGH && b==HIGH && c==LOW && d==LOW)
    {
      sig=5;
    }
    else if(a==HIGH && b==LOW && c==HIGH && d==LOW)
    {
      sig=6;
    }    
    else if(a==HIGH && b==LOW && c==LOW && d==HIGH)
    {
      sig=7;
    }  
    else if(a==LOW && b==HIGH && c==HIGH && d==LOW)
    {
      sig=8;
    }          
    else
    {
      sig=0;
    } 
  if(sen_val>300)
  {
    stop1();
    tone(buzzer, 500);
    Serial.println("Object Detectetd. Initiating Breaking System...!");
  }
  else
  {
    noTone(buzzer);
    switch(sig)
    {
      case(1):
      {
      Forward();
      break;
        }
      case(2):
      {
      Reverse();
      break;
        }
      case(3):
      {
      right();
      break;
        }
      case(4):
      {
      left();
      break;
        }
      case(5):
      {
      stop1();
      break;
        }
      case(6):
      {
      Forward80();
      break;
        }
      case(7):
      {
      Forward50();
      break;
        }
      case(8):
      {
      Forward20();
      break;
        }                        
      default:
      {
      stop1();
      Serial.println("No Interrupt Found. Initiating Breaking System...!");
      break;
        }
      }  
  }
}
  
}
void stop1()
{
  digitalWrite(lfmf, LOW);
  digitalWrite(lfmr, LOW);
  digitalWrite(lbmf, LOW);
  digitalWrite(lbmr, LOW);

  digitalWrite(rfmf, LOW);
  digitalWrite(rfmr, LOW);
  digitalWrite(rbmf, LOW);
  digitalWrite(rbmr, LOW);

  analogWrite(pwm1, pwm_val);
  analogWrite(pwm2, pwm_val);
  analogWrite(pwm3, pwm_val);
  analogWrite(pwm4, pwm_val);
}

void Forward()
{
  Serial.println("Forward");
  digitalWrite(lfmf, HIGH);
  digitalWrite(lfmr, LOW);
  digitalWrite(lbmf, HIGH);
  digitalWrite(lbmr, LOW);

  digitalWrite(rfmf, HIGH);
  digitalWrite(rfmr, LOW);
  digitalWrite(rbmf, HIGH);
  digitalWrite(rbmr, LOW);

  analogWrite(pwm1, pwm_val);
  analogWrite(pwm2, pwm_val);
  analogWrite(pwm3, pwm_val);
  analogWrite(pwm4, pwm_val);
}
void Forward80()
{
  pwm_val=180;
  Serial.println("Forward");
  digitalWrite(lfmf, HIGH);
  digitalWrite(lfmr, LOW);
  digitalWrite(lbmf, HIGH);
  digitalWrite(lbmr, LOW);

  digitalWrite(rfmf, HIGH);
  digitalWrite(rfmr, LOW);
  digitalWrite(rbmf, HIGH);
  digitalWrite(rbmr, LOW);

  analogWrite(pwm1, pwm_val);
  analogWrite(pwm2, pwm_val);
  analogWrite(pwm3, pwm_val);
  analogWrite(pwm4, pwm_val);
}
void Forward50()
{
  pwm_val=150;
  Serial.println("Forward");
  digitalWrite(lfmf, HIGH);
  digitalWrite(lfmr, LOW);
  digitalWrite(lbmf, HIGH);
  digitalWrite(lbmr, LOW);

  digitalWrite(rfmf, HIGH);
  digitalWrite(rfmr, LOW);
  digitalWrite(rbmf, HIGH);
  digitalWrite(rbmr, LOW);

  analogWrite(pwm1, pwm_val);
  analogWrite(pwm2, pwm_val);
  analogWrite(pwm3, pwm_val);
  analogWrite(pwm4, pwm_val);
}
void Forward20()
{
  pwm_val=80;
  Serial.println("Forward");
  digitalWrite(lfmf, HIGH);
  digitalWrite(lfmr, LOW);
  digitalWrite(lbmf, HIGH);
  digitalWrite(lbmr, LOW);

  digitalWrite(rfmf, HIGH);
  digitalWrite(rfmr, LOW);
  digitalWrite(rbmf, HIGH);
  digitalWrite(rbmr, LOW);

  analogWrite(pwm1, pwm_val);
  analogWrite(pwm2, pwm_val);
  analogWrite(pwm3, pwm_val);
  analogWrite(pwm4, pwm_val);
}

void Reverse()
{
  Serial.println("Reverse");
  digitalWrite(lfmf, LOW);
  digitalWrite(lfmr, HIGH);
  digitalWrite(lbmf, LOW);
  digitalWrite(lbmr, HIGH);

  digitalWrite(rfmf, LOW);
  digitalWrite(rfmr, HIGH);
  digitalWrite(rbmf, LOW);
  digitalWrite(rbmr, HIGH);

  analogWrite(pwm1, pwm_val);
  analogWrite(pwm2, pwm_val);
  analogWrite(pwm3, pwm_val);
  analogWrite(pwm4, pwm_val);
}

void right()
{
  Serial.println("Right");

  pwm_val = pwm_turn_val;
  
  digitalWrite(lfmf, HIGH);
  digitalWrite(lfmr, LOW);
  digitalWrite(lbmf, HIGH);
  digitalWrite(lbmr, LOW);

  digitalWrite(rfmf, LOW);
  digitalWrite(rfmr, HIGH);
  digitalWrite(rbmf, LOW);
  digitalWrite(rbmr, HIGH);

  analogWrite(pwm1, pwm_val);
  analogWrite(pwm2, pwm_val);
  analogWrite(pwm3, pwm_val);
  analogWrite(pwm4, pwm_val);
  delay(x);
}

void left()
{
  Serial.println("Left");
  
  pwm_val = pwm_turn_val;
  
  digitalWrite(lfmf, LOW);
  digitalWrite(lfmr, HIGH);
  digitalWrite(lbmf, LOW);
  digitalWrite(lbmr, HIGH);

  digitalWrite(rfmf, HIGH);
  digitalWrite(rfmr, LOW);
  digitalWrite(rbmf, HIGH);
  digitalWrite(rbmr, LOW);

  analogWrite(pwm1, pwm_val);
  analogWrite(pwm2, pwm_val);
  analogWrite(pwm3, pwm_val);
  analogWrite(pwm4, pwm_val);
  delay(x);
}
