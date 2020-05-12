// Code pour un simple systeme d'alarme

// Declaration des PINS
#define alarm_pin 8
#define ledred_pin 6
#define ledgreen_pin 5
#define motion_pin 7

// Alarm
boolean alarm_mode = false;

// Variables for the flashing LDED
int ledState = LOW;
long previousMillis = 0; 
long interval = 100;  // Intervalle de cligottement des lampes (millisecondes)

void setup()
{
  // activer les capteur en entrées ou en sorties
  pinMode(ledred_pin,OUTPUT);
  pinMode(ledgreen_pin,OUTPUT);
  pinMode(alarm_pin,OUTPUT);
  pinMode(alarm_pin,INPUT);
  
  // Delai avant le demarrage de l'alarme 
  delay(5000);
}

void loop()
{
  
  // Detection de mouvement
  if (digitalRead(motion_pin)== HIGH) {
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
  else {
    digitalWrite(ledgreen_pin, HIGH);
    digitalWrite(ledred_pin, LOW);
    noTone(alarm_pin); //arreter l'alarme avec la fonction noTone()
  }
  //delai de clignetement
  delay(100);
}
