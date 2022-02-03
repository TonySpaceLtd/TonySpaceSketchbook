#include "TonyS_X1.h"
#include "TonySpace_SHT31.h"
#include "TonySpace_NBIoT.h"

NBIoT nb;
NBIoT_UDP udp;
#define SERVER_IP   "xxx.xxx.xxx.xxx"
#define SERVER_PORT 4444

unsigned long previousMillis = 0;
const long interval = 2000;
void setup()
{
  Serial.begin(9600);
  Serial.println("TonyS X1");
  Tony.begin();
  Serial.println("\r\nNBIoT Setting");
  nb.begin(SLOT2);
  Serial.println("NBIoT Ready");
  Serial.print("SIM(S/N) :");
  Serial.println(nb.getSIMSerial());
  Serial.print("IMEI :");
  Serial.println(nb.getIMEI());
  Serial.print("IMSI :");
  Serial.println(nb.getIMSI());
  Serial.print("Network Status:");
  while (!nb.getNetworkStatus())
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("OK");
  Serial.print("Signal :");
  Serial.println(nb.getSignal());
  Serial.print("Signal :");
  Serial.print(nb.getSignaldBm());
  Serial.println("dBm");
  Serial.print("Signal Level :");
  Serial.println(nb.getSignalLevel());
  Serial.print("Device IP :");
  Serial.println(nb.getDeviceIP());
  
  TonySHT31.begin();
  
  connectServer();
}
uint8_t cnt = 0;
void loop()
{

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    float t = TonySHT31.readTemperature();
	float h = TonySHT31.readHumidity();
    udp.printf("Temp *C = %.2f\r\nHum.= %.2f\r\n", t, h);
    // Serial.printf("Temp *C = %.2f\r\nHum. \% = %.2f\r\n",t,h);
    previousMillis = currentMillis;
  }
  while (udp.available())
  {
    String udpData = udp.readStringUntil('\n');
    Serial.println(udpData);
  }

}
void connectServer()
{
  udp.createSocket(SERVER_IP, SERVER_PORT);
}
