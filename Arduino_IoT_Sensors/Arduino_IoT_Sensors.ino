#define USE_POT_FOR_TEMP 0   

const int PIN_TMP  = A0; #Temperature Sensor
const int PIN_SOIL = A1; #Soil Sensor     
const int PIN_LDR  = A2; #Light Sensor    
const int PIN_POT  = A3; #Potentiometer     
const int PIN_LED  = 13; #LED Signal

int SOIL_DRY_RAW = 900; #Calibration for Wet Soil      
int SOIL_WET_RAW = 350; #Calibration for Dry Soil          

#Setting up the range of accepted values
const float T_OK_MIN=15.0, T_OK_MAX=30.0;
const float SOIL_OK_MIN=30.0, SOIL_OK_MAX=70.0;
const int N_SAMPLES=8; const unsigned PRINT_MS=500;

int avgRead(uint8_t pin){ long s=0; for(int i=0;i<N_SAMPLES;i++){ s+=analogRead(pin); delay(2);} return s/N_SAMPLES; }
#Converting the soil readings into moisture
float soilPctFromRaw(int raw){ 
  int dry=SOIL_DRY_RAW, wet=SOIL_WET_RAW;
  if(dry==wet) return 0;
  raw = constrain(raw, min(dry,wet), max(dry,wet));
  float p = 100.0f*(float)(dry - raw)/(float)(dry - wet);
  return constrain(p, 0.0f, 100.0f);
}

void setup(){
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);
  Serial.println("ms,rawTMP,rawSOIL,rawLDR,Vtmp,tempC,soilPct,ldrPct,alert");
}

void loop(){
  unsigned long ms=millis(); #Readings in miliseconds

  int rSoil=avgRead(PIN_SOIL); #Reading the raw value of the soil
  int rLdr =avgRead(PIN_LDR);  #Reading the raw value of light
  int rTmp = USE_POT_FOR_TEMP ? avgRead(PIN_POT) : avgRead(PIN_TMP);

  float Vtmp  = rTmp*(5.0/1023.0);
  float tempC = (Vtmp - 0.5)*100.0;   
  float soil  = soilPctFromRaw(rSoil);
  float ldr   = (rLdr/1023.0f)*100.0f;

  bool alert = !(tempC>=T_OK_MIN && tempC<=T_OK_MAX && soil>=SOIL_OK_MIN && soil<=SOIL_OK_MAX);
  digitalWrite(PIN_LED, alert ? HIGH : LOW); #Alerting users with LED if data is outside the range 

  Serial.print(ms);Serial.print(",");
  Serial.print(rTmp);Serial.print(",");
  Serial.print(rSoil);Serial.print(",");
  Serial.print(rLdr);Serial.print(",");
  Serial.print(Vtmp,3);Serial.print(",");
  Serial.print(tempC,1);Serial.print(",");
  Serial.print(soil,1);Serial.print(",");
  Serial.print(ldr,1);Serial.print(",");
  Serial.println(alert?1:0);

  delay(PRINT_MS);
}
