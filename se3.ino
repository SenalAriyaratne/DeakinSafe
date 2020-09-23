// This #include statement was automatically added by the Particle IDE.
#include <MQTT.h>

// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT_Particle.h>


#define DHTPIN D2     

#define DHTTYPE DHT11    



DHT dht(DHTPIN, DHTTYPE);


void setup() {
  

  dht.begin(); // sets the pinMode
  
}

void loop() 
{

// Read temperature as Celsius
  float outdoortemp = dht.getTempCelcius();
  float thermals = 35;
  float thermalw = 30;
  float thermala = 22;
  //check for during summer
  if(outdoortemp > 25 and  outdoortemp < 35 )
  {
      if (thermals > 25 and thermals < 40 )
      {
          Particle.publish("temp", "High Body temperature", PRIVATE);
      }
      else
      {
          Particle.publish("temp", "Normal Body temperature", PRIVATE);
      }
  }
  
  // Check temperature during winter
  if(outdoortemp > 5 and outdoortemp < 25)
  {
      if(thermalw > 20  and thermalw < 32)
      {
         Particle.publish("temp", "High Body temperature", PRIVATE);
      }
      else
      {
          Particle.publish("temp", "Normal Body temperature", PRIVATE);
      }
  }
  
  // Check temperaature during autumn
  if(outdoortemp > 15 and outdoortemp < 25)
  {
      if(thermalw > 20  and thermalw < 32)
      {
         Particle.publish("temp", "High Body temperature", PRIVATE);
      }
      else
      {
          Particle.publish("temp", "Normal Body temperature", PRIVATE);
      }
  }
  

  Particle.publish("temp",String(outdoortemp),PRIVATE);
  delay(30000);
}

