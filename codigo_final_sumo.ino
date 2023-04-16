//TRACCION DELANTERA
byte sensor1 = A2 ;
//MOTOR 1 DERECHA
byte controlA = 13 ; 
byte controlB = 12 ;
byte PWM1 = 11 ;

//MOTOR 2 IZQUIERDA
byte controlA2 = 8 ; 
byte controlB2 = 9 ;
byte PWM2 = 10 ;

//TRACCION TRASERA
byte sensor2 =  A3;

//VARIABLES
const int pwm_motores = 255 ;

//Sensor Ultrasonido
#define trig A1
#define echo A0
float duracion, distancia;
int blancomin, blancomax;
int negromin, negromax;
int blancomin2, blancomax2;
int negromin2, negromax2;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);

  pinMode(controlA, OUTPUT);
  pinMode(controlB, OUTPUT);
  pinMode(PWM1, OUTPUT);

  pinMode(controlA2, OUTPUT);
  pinMode(controlB2, OUTPUT);
  pinMode(PWM2, OUTPUT);

  negromin = 0;
  negromax = 150;
  blancomin = 200;
  blancomax = 300;
  negromin2 = 0;
  negromax2 = 150;
  blancomin2 = 200;
  blancomax2 = 300;
}

void loop() {
  int n1 = analogRead(sensor1); // Leer valor del sensor
  int n2 = analogRead(sensor2); // Leer valor del sensor
  Serial.println("----");
  Serial.println(n1);
  Serial.println(n2);
  Serial.println("----");

  digitalWrite(trig, HIGH);
  delayMicroseconds(1);
  digitalWrite(trig, LOW);
  duracion = pulseIn(echo, HIGH);
  distancia = duracion / 58.2;

  //sensor adelante
  if (distancia <= 20 && n1 >= negromin && n1 <= negromax && n2 >= negromin2 && n2 <= negromax2) {
    adelante();
    delay(100);
  } else if (n1 >= blancomin && n1 <= blancomax && n2 >= blancomin2 && n2 <= blancomax2) {
    reversa();
    delay(100);
  } else {
    
    delay(300);
    izquierda();
    delay(300);
    derecha();
    delay(200);
    parar();
  }
}

void adelante() {
  digitalWrite(PWM1, pwm_motores);
  digitalWrite(controlA, HIGH);
  digitalWrite(controlB, LOW);

  digitalWrite(PWM2, pwm_motores);
  digitalWrite(controlA2, HIGH);
  digitalWrite(controlB2, LOW);
}

void reversa() {
  analogWrite(PWM1, pwm_motores);
  digitalWrite(controlA, LOW);
  digitalWrite(controlB, HIGH);

  analogWrite(PWM2, pwm_motores);
  digitalWrite(controlA2, LOW);
  digitalWrite(controlB2, HIGH);
}
void izquierda () {

    analogWrite( PWM1 , pwm_motores ) ;
    digitalWrite( controlA , HIGH ) ;
    digitalWrite( controlB , LOW ) ;

    analogWrite( PWM2 , pwm_motores ) ;
    digitalWrite( controlA2 , LOW ) ;
    digitalWrite( controlB2 , HIGH ) ; 
}
void derecha () {

    analogWrite( PWM1 , pwm_motores ) ;
    digitalWrite( controlA , LOW ) ;
    digitalWrite( controlB , HIGH ) ;

    analogWrite( PWM2 , pwm_motores ) ;
    digitalWrite( controlA2 , HIGH ) ;
    digitalWrite( controlB2 , LOW ) ;
}

void parar () {
  
    digitalWrite( PWM1 ,0 ) ;
    digitalWrite( controlA , LOW ) ;
    digitalWrite( controlB , LOW ) ;

    digitalWrite( PWM2 , 0 ) ;
    digitalWrite( controlA2 , LOW ) ;
    digitalWrite( controlB2 , LOW ) ; 
}