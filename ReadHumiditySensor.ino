//Code pour mesurer les données depuis le capteur DTH11

 // Bibliothèques
 #include "DHT.h"

 // Cacpteur DHT
 #define DHTPIN 7
 #define DHTTYPE DHT11

 // Instance DHT
 DHT dht(DHTPIN, DHTTYPE);

 void setup()
 {
  // Initialisation du port serie
  Serial.begin(9600);
  // Initialisation de DHT
  dht.begin();
 }

 void loop()
 {
  // Mesure depuis DHT
  float temperature = dht.readTemperature();
  float humidite = dht.readHumidity();

  // Affichage de la temperature
  Serial.print("Température:");
  Serial.print((int)temperature);
  Serial.println(" °C");

  // Affrichage de l'humidité
  Serial.print("Humidité:");
  Serial.print(humidite);
  Serial.println(" %");

  // Delai d'attente de 1s
  delay(1000);
 }
