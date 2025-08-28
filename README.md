# Arduino_IoT_System


This Arduino-powered environmental monitor collects real-time temperature, soil moisture, and ambient light data using a TMP36 sensor, soil probe, and LDR with resistor divider, with readings averaged, converted (°C and %), and streamed as CSV over Serial for easy logging or dashboarding. I designed and wired the sensor stack (TMP36 with decoupling, LDR divider, soil probe path), wrote the firmware to handle sampling, conversions, calibration, and mapping, and implemented alert logic with an LED indicator whenever values left safe ranges (15–30 °C, 30–70 % soil). The system was verified in Tinkercad. 

# Components
- **Arduino Uno** – microcontroller  
- **TMP36** – analog temperature sensor(A0)  
- **Analog soil moisture sensor** – SIG(A1)  
- **LDR (photoresistor)** – light sensing divider(A2)  
- **Potentiometer** – quick testing / simulation(A3)  
- **LED** (onboard D13) – alert indicator  
- **Jumpers + breadboard**  
- **ESP-01 / ESP32** – Wi-Fi uplink

# Features
- **Live sensing**: temperature (TMP36), soil moisture (analog), ambient light (LDR).  
- **Clean conversions**:  
  - TMP36 → °C  
  - Soil → % with easy calibration  
  - LDR → % of full scale  
- **Noise control**: averaging across multiple samples.  
- **Alerting**: LED turns on when values leave the “OK window”:  
  - Temp: **15–30 °C**  
  - Soil: **30–70 %**  
- **Validation**: wiring and code paths verified in **Tinkercad**. 
