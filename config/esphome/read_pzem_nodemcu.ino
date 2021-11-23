#include <PZEM004Tv30.h>
#include <ArduinoOTA.h>
#include <SimpleTimer.h>
#include <ModbusMaster.h>
#include <ESP8266WiFi.h>
#include "settingsPZEM.h"
#include <SoftwareSerial.h> // ( NODEMCU ESP8266 )
SoftwareSerial pzem(D5,D6); // (RX,TX) connect to TX,RX of PZEM for NodeMCU
//SoftwareSerial pzem(D7,D8); // (RX,TX) connect to TX,RX of PZEM
#include <ModbusMaster.h>
ModbusMaster node;
SimpleTimer timer;

int timerTask1;
double U_PR, I_PR, P_PR, PPR, PR_F, PR_PF, PR_alarm;
uint8_t result; uint16_t data[6];

void setup(){
    Serial.begin(115200); Serial.println("Start serial"); pzem.begin(9600); Serial.println("Start PZEM serial");
    node.begin(1, pzem); Serial.println("Start PZEM"); // 1 = ID MODBUS
    WiFi.mode(WIFI_STA);
}

void loop(){
    result = node.readInputRegisters(0x0000, 10);
    if (result == node.ku8MBSuccess) {
        U_PR = (node.getResponseBuffer(0x00)/10.0f);
        I_PR = (node.getResponseBuffer(0x01)/1000.000f);
        P_PR = (node.getResponseBuffer(0x03)/10.0f);
        PPR = (node.getResponseBuffer(0x05)/1000.0f);
        PR_F = (node.getResponseBuffer(0x07)/10.0f);
        PR_PF = (node.getResponseBuffer(0x08)/100.0f);
        PR_alarm = (node.getResponseBuffer(0x09));
    }

    Serial.print("U_PR: "); Serial.println(U_PR); // V
    Serial.print("I_PR: "); Serial.println(I_PR,3); // A
    Serial.print("P_PR: "); Serial.println(P_PR); // W
    Serial.print("PPR: "); Serial.println(PPR,3); // kWh
    Serial.print("PR_F: "); Serial.println(PR_F); // Hz
    Serial.print("PR_PF: "); Serial.println(PR_PF);
    Serial.print("PR_alarm: "); Serial.println(PR_alarm,0);
    Serial.println("====================================================");
    delay(1000);
}
