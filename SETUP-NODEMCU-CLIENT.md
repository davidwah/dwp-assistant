# Setup Nodemcu Client

1. Flash firmware Nodemcu with [Tasmota](https://tasmota.github.io/install/)
2. Connect Nodemcu to local network
3. Configure Module
  * using module `Generic 18`
  * set `GPIO1` -> `PZEM0XX Tx`
  * set `GPIO2` -> `Relay`
  * set `GPIO3` -> `PZEM016 Rx`  
  ![Config-Module](https://github.com/davidwah/dwp-assistant/blob/main/img/Configure%20Module.png)
4. Configure MQTT
  * Host
  * Port
  * Client Name
  * User
  * Password
  * Topic
6. Configure Hostname
  `Configure Other`
8. Configure NTP
  ```
  ntpServer1 0.asia.pool.ntp.org
  timezone 7
  ``` 
7. Reboot Nodemcu
