const int trigPin = 3; // Entrée trigger ultrason
const int echoPin = 2; // Sortie trigger ultrason
int pinLed1, pinLed2, pinLed3, pinLed4; // variables broches led

long duration; // temps de reception
int distance; // calcul de la distance
void setup() {
  pinMode(trigPin, OUTPUT); // Broche 3 en sortie
  pinMode(echoPin, INPUT); // Broche 2 en entrée
  Serial.begin(9600); // Début de la communication série
  // Initialisation des pin des LEDs
  pinLed1 = 4; pinLed2 = 5; pinLed3 = 6; pinLed4 = 7;
  pinMode(pinLed1, OUTPUT); pinMode(pinLed2, OUTPUT); pinMode(pinLed3, OUTPUT); pinMode(pinLed4, OUTPUT);
  
  //Mise à 0V de chaque pin
  digitalWrite(pinLed1, HIGH); digitalWrite(pinLed2, HIGH); digitalWrite(pinLed3, HIGH); digitalWrite(pinLed4, HIGH);
  }
  
void loop() {
  digitalWrite(trigPin, LOW); //Mise à 0V de trigPin
  delayMicroseconds(2); //Attente de 2 Microsecondes
  digitalWrite(trigPin, HIGH); //Donner de la puissance au trigPin
  delayMicroseconds(10); //Attente de 10 Microsecondes
  digitalWrite(trigPin, LOW); //Mise à 0V de trigPin
  duration = pulseIn(echoPin, HIGH); // Lire echoPin pour savoir la distance parcourue en 10 Microsecondes
  
  distance= duration*0.034/2; //Calculer la distance
  // Afficher la distance dans le Moniteur série
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(225); // Délai d'actualisation de LEDs

  // Allumer les LEDs à la distance défini
  if(distance > 36 and distance < 39)
    digitalWrite(pinLed1, LOW);
  else
    digitalWrite(pinLed1, HIGH);


  if(distance > 27 and distance < 36)
    digitalWrite(pinLed2, LOW);
  else
    digitalWrite(pinLed2, HIGH);


  if(distance > 18 and distance < 27)
    digitalWrite(pinLed3, LOW);
  else
    digitalWrite(pinLed3, HIGH);

  
  if(distance > 1 and distance < 18 )
    digitalWrite(pinLed4, LOW);
  else
    digitalWrite(pinLed4, HIGH);
}
