# Arduino_IoT_System


In this project, I was specifically responsible for the sensor code. I implemented the routines to read raw values from the TMP36 temperature sensor, soil moisture probe, and LDR-resistor divider, then handled calibration and mapping to human-readable units (°C and %). I also wrote the averaging logic to smooth noisy readings, structured the output into CSV format for logging/dashboarding, and added threshold-based alert logic that triggered an LED whenever sensor values moved outside safe ranges (15–30 °C for temperature, 30–70 % for soil moisture). This part of the firmware ensured reliable, interpretable sensor data for the rest of the system.

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
