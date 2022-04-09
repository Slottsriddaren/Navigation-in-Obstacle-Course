#define ML_Ctrl 4 // Definiera direction (riktning) för kontroll pin av motorerna B
#define ML_PWM 5 // Definiera PWM kontroll pin av motorerna B
#define MR_Ctrl 2 // Definiera direction (riktning) för kontroll pin av motorerna A
#define MR_PWM 9 // Definiera PWM kontroll pin av motorerna A

/******************************************************************
 * Konfiguration Sensorer - definiering av korrekta pins
 ******************************************************************/

// Diagonal vänster ultrasonic sensor
int tLeft = 30;    // Trigger
int eLeft = 31;    // Echo
long durationLeft, cmLeft;

// Mitten ultrasonic sensor
int tMiddle = 12;    // Trigger
int eMiddle = 13;    // Echo
long durationMiddle, cmMiddle;

// Diagonal höger ultrasonic sensor
int tRight = 52;    // Trigger
int eRight = 53;    // Echo
long durationRight, cmRight;

// Längst vänster ultrasonic sensor
int tFLeft = 44;    // Trigger
int eFLeft = 45;    // Echo
long dFLeft, cmFLeft;

// Längst höger ultrasonic sensor
int tFRight = 48;    // Trigger
int eFRight = 49;    // Echo
long dFRight, cmFRight;

void setup() {
  // put your setup code here, to run once:

  // Definiering av kontroll pins för motor A och B som outputs (A = höger sida, B = vänster sida)
  pinMode(ML_Ctrl, OUTPUT); // Direction B
  pinMode(ML_PWM, OUTPUT); // PWM B
  pinMode(MR_Ctrl, OUTPUT); // Direction A
  pinMode(MR_PWM, OUTPUT); // PWM A

  Serial.begin(9600);

/******************************************************************
 * Initiera pins - definiera inputs och outputs
 ******************************************************************/

  // Definiera inputs och outputs för diagonal vänster sensor
  pinMode(tLeft, OUTPUT);
  pinMode(eLeft, INPUT);

  // Definiera inputs och outputs för mitten sensor
  pinMode(tMiddle, OUTPUT);
  pinMode(eMiddle, INPUT);

  // Definiera inputs och outputs för diagonal höger sensor
  pinMode(tRight, OUTPUT);
  pinMode(eRight, INPUT);

  // Definiera inputs och outputs för längst vänster sensor
  pinMode(tFLeft, OUTPUT);
  pinMode(eFLeft, INPUT);

  // Definiera inputs och outputs för längst höger sensor
  pinMode(tFRight, OUTPUT);
  pinMode(eFRight, INPUT);

}

void loop() {
  

/******************************************************************
 * Diagonal vänster - avläs avstånd från sensor
 ******************************************************************/

  // Sensor är triggered av en HÖG (HIGH) puls av 10 eller mer microsekunder
  // Ger en kory LÅG (LOW) puls i förhand för att försäkra en bra HÖG (HIGH) puls:
  digitalWrite(tLeft, LOW);
  delayMicroseconds(2);
  digitalWrite(tLeft, HIGH);
  delayMicroseconds(10);
  digitalWrite(tLeft, LOW);
  
  // Läs signalen från sensorn: en HÖG puls vars
  // varaktighet är tiden (i mikrosekunder) från sändningen
  // av ping till mottagningen av dess eko från ett objekt.
  durationLeft = pulseIn(eLeft, HIGH);

  // Konvertera tiden till distans
  cmLeft = (durationLeft/2) / 29.1; // Dividera med 29.1 eller multiplicera med 0.0343 för att få avståndet i cm

/******************************************************************
 * Mitten - avläs avstånd från sensor
 ******************************************************************/
  
  // Sensor är triggered av en HÖG (HIGH) puls av 10 eller mer microsekunder
  // Ger en kory LÅG (LOW) puls i förhand för att försäkra en bra HÖG (HIGH) puls:
  digitalWrite(tMiddle, LOW);
  delayMicroseconds(2);
  digitalWrite(tMiddle, HIGH);
  delayMicroseconds(10);
  digitalWrite(tMiddle, LOW);
  
  // Läs signalen från sensorn: en HÖG puls vars
  // varaktighet är tiden (i mikrosekunder) från sändningen
  // av ping till mottagningen av dess eko från ett objekt.
  durationMiddle = pulseIn(eMiddle, HIGH);

  // Konvertera tiden till distans
  cmMiddle = (durationMiddle/2) / 29.1; // Dividera med 29.1 eller multiplicera med 0.0343 för att få avståndet i cm

/******************************************************************
 * Diagonal höger - avläs avstånd från sensor
 ******************************************************************/

  // Sensor är triggered av en HÖG (HIGH) puls av 10 eller mer microsekunder
  // Ger en kory LÅG (LOW) puls i förhand för att försäkra en bra HÖG (HIGH) puls:
  digitalWrite(tRight, LOW);
  delayMicroseconds(2);
  digitalWrite(tRight, HIGH);
  delayMicroseconds(10);
  digitalWrite(tRight, LOW);
  
  // Läs signalen från sensorn: en HÖG puls vars
  // varaktighet är tiden (i mikrosekunder) från sändningen
  // av ping till mottagningen av dess eko från ett objekt.
  durationRight = pulseIn(eRight, HIGH);

  // Konvertera tiden till distans
  cmRight = (durationRight/2) / 29.1; // Dividera med 29.1 eller multiplicera med 0.0343 för att få avståndet i cm


/******************************************************************
 * Längst åt vänster - avläs avstånd från sensor
 ******************************************************************/


  // Sensor är triggered av en HÖG (HIGH) puls av 10 eller mer microsekunder
  // Ger en kory LÅG (LOW) puls i förhand för att försäkra en bra HÖG (HIGH) puls:
  digitalWrite(tFLeft, LOW);
  delayMicroseconds(2);
  digitalWrite(tFLeft, HIGH);
  delayMicroseconds(10);
  digitalWrite(tFLeft, LOW);
  
  // Läs signalen från sensorn: en HÖG puls vars
  // varaktighet är tiden (i mikrosekunder) från sändningen
  // av ping till mottagningen av dess eko från ett objekt.
  dFLeft = pulseIn(eFLeft, HIGH);

  // Konvertera tiden till distans
  cmFLeft = (dFLeft/2) / 29.1; // Dividera med 29.1 eller multiplicera med 0.0343 för att få avståndet i cm


/******************************************************************
 * Längst åt höger - avläs avstånd från sensor
 ******************************************************************/

  // Sensor är triggered av en HÖG (HIGH) puls av 10 eller mer microsekunder
  // Ger en kory LÅG (LOW) puls i förhand för att försäkra en bra HÖG (HIGH) puls:
  digitalWrite(tFRight, LOW);
  delayMicroseconds(2);
  digitalWrite(tFRight, HIGH);
  delayMicroseconds(10);
  digitalWrite(tFRight, LOW);
  
  // Läs signalen från sensorn: en HÖG puls vars
  // varaktighet är tiden (i mikrosekunder) från sändningen
  // av ping till mottagningen av dess eko från ett objekt.
  dFRight = pulseIn(eFRight, HIGH);

  // Konvertera tiden till distans
  cmFRight = (dFRight/2) / 29.1; // Dividera med 29.1 eller multiplicera med 0.0343 för att få avståndet i cm


/******************************************************************
 * Kontrollera bilen - kör bilen utifån avlästa avstånd
 ******************************************************************/

  // Kolla om avståndet rakt frammåt är större än 20 cm
  if (cmMiddle > 20) {


  // Avståndet rakt fram är större än 20 cm:


  // Kolla om avståndet diagonalt vänster är större än avståndet diagonalt höger
  // och avståndet längst åt vänster är större än 10 cm
  if (cmLeft > cmRight && cmFLeft > 10) {

    
    // Åk frammåt diagonalt vänster:


    // Rotera höger motorer frammåt med hastigheten 200
    digitalWrite(MR_Ctrl,HIGH); // Direction A till HÖG (frammåt)
    analogWrite(MR_PWM, 200); // Set PWM hastighet till 200


    // Rotera vänster motorer frammåt med hastigheten 50
    digitalWrite(ML_Ctrl,HIGH); // Direction B till HÖG (frammåt)
    analogWrite(ML_PWM,50); // Set PWM hastighet till 50
    
  }


  // Kolla om avståndet diagonalt höger är större än avståndet diagonalt vänster
  // och avståndet längst åt höger är större än 10 cm
  if (cmRight > cmLeft && cmFRight > 10) {


    // Åk frammåt diagonalt höger:
   

    // Rotera höger motorer frammåt med hastigheten 50
    digitalWrite(MR_Ctrl,HIGH); // Direction A till HÖG (frammåt)
    analogWrite(MR_PWM, 50); // Set PWM hastighet till 50


    // Rotera vänster motorer frammåt med hastigheten 200
    digitalWrite(ML_Ctrl,HIGH); // Direction B till HÖG (frammåt)
    analogWrite(ML_PWM,200); // Set PWM hastighet till 200
    }
  }
  
  if (cmMiddle < 20) {
    
    
    // Avståndet rakt fram är mindre än 20 cm:


    // Stanna motorerna på höger sida
    digitalWrite(MR_Ctrl,LOW); // Direction A till LÅG (bakåt)
    analogWrite(MR_PWM,0); // Set PWM hastighet till 0


    // Stanna motorerna på vänster sida
    digitalWrite(ML_Ctrl,LOW); // Direction B till LÅG (bakåt)
    analogWrite(ML_PWM,0); // Set PWM hastighet till 0


    // Kolla om avståndet längst åt vänster är större än avståndet längst åt höger
    if (cmFLeft > cmFRight) {


      // Avståndet längst åt vänster är större än avståndet längst åt höger:

      // Sväng vänster:


      // Rotera höger motorer frammåt med hastigheten 100
      digitalWrite(MR_Ctrl,HIGH); // Direction A till HÖG (frammåt)
      analogWrite(MR_PWM, 100); // Set PWM hastighet till 100


      // Rotera vänster motorer bakåt med hastigheten 100
      digitalWrite(ML_Ctrl,LOW); // Direction B till LÅG (bakåt)
      analogWrite(ML_PWM,100); // Set PWM hastighet till 100




      
    } else if (cmFRight > cmFLeft) { // Kolla annars om avståndet längst åt höger är större än avståndet längst åt vänster
      

      // Avståndet längst åt höger är större än avståndet längst åt vänster:

      // Sväng höger:


      // Rotera höger motorer bakåt med hastigheten 100
      digitalWrite(MR_Ctrl,LOW); // Direction A till LÅG (bakåt)
      analogWrite(MR_PWM, 100); // Set PWM hastighet till 100


      // B = vänster sida
      digitalWrite(ML_Ctrl,HIGH); // Direction B till HÖG (frammåt)
      analogWrite(ML_PWM,100); // Set PWM hastighet till 100



      
    }
  }

  // Vänta 50 millisekunder innan börjar om
  delay(50);
}
