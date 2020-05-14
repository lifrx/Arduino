/* Code pour un simple systeme d'alarme 
 *avec un détecteur de proximité ultrasonic HC-SR04
 *une alarme (buzzer passif)
 *et deux lampes témoins
  */
// Declaration des PINS
#define alarm_pin 8
#define ledred_pin 6
#define ledgreen_pin 4
#define trig 13
#define echo 11
float cm;

// Alarm
boolean alarm_mode = false;

// Déclaration des variables pour clignoter les lampes
int ledState = LOW;
long previousMillis = 0; 
long interval = 100;  // Intervalle de cligottement des lampes (millisecondes)

void setup()
{
  // activer les capteur en entrées ou en sorties
  pinMode(ledred_pin,OUTPUT);
  pinMode(ledgreen_pin,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

}

void loop()
{
  digitalWrite(trig, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trig, HIGH); 
  //delayMicroseconds(10);
  //digitalWrite(trig, LOW);
  /* On évalue la distance en cm. La distance parcourue par le son est de 
   * /340m/s soit 29 micronseconde par metre. le temps d'acces de l'objet est evaluée
   * à la moitié de la distance parcourue soit 29/2
   * stockage de la distance de l'objet en cm
    */
  cm = pulseIn(echo, HIGH)/29/2;
  // Detection de mouvement
  if (cm > 0 && cm < 50) {
    alarm_mode = true; 
    // Si un mouvement est détecté, clignoter la lampe rouge et faire sonner l'alarme
    if (alarm_mode){
      unsigned long currentMillis = millis();
      if(currentMillis - previousMillis > interval) {
        previousMillis = currentMillis;   
        if (ledState == LOW)
          ledState = HIGH;
        else
          ledState = LOW;
      // faire commuter le clignotement des lampes
      digitalWrite(ledred_pin, ledState);
      digitalWrite(ledgreen_pin, LOW);
      }
    tone(alarm_pin,5000,50); // sonner l'alarme avec la fonction tone
    }  
  }
  else if(cm >= 50) {
    digitalWrite(ledgreen_pin, HIGH);
    digitalWrite(ledred_pin, LOW);
    noTone(alarm_pin); //arreter l'alarme avec la fonction noTone()
  }
  //delai de clignetement
  delay(100);
}
