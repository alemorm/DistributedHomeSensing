// Pins
#define THERMISTORPIN 4
#define SAMPLERATE 1000
#define READDELAY 10
#define PRINTDELAY 10000

const double VCC = 3.3;             // NodeMCU on board 3.3v vcc
const double R2 = 10000;            // 10k ohm series resistor
const double adc_resolution = 1023; // 10-bit adc

const double A = 0.001129148;   // thermistor equation parameters
const double B = 0.000234125;
const double C = 0.0000000876741; 

void setup() {
  Serial.begin(9600);  /* Define baud rate for serial communication */
}

void loop() {
  double thermalSamples[SAMPLERATE], average, Vout, Rth, temperature, adc_value; 
  analogReadResolution(10);

  average = 0;
  // Collect SAMPLERATE samples
  for (int i=0; i<SAMPLERATE; i++) {
      thermalSamples[i] = analogRead(THERMISTORPIN);
      average += thermalSamples[i];
      delay(READDELAY);
  }

  // Calculate the average value of the samples
  average /= SAMPLERATE;
  Vout = (average * VCC) / adc_resolution;
  Rth = (VCC * R2 / Vout) - R2;

/*  Steinhart-Hart Thermistor Equation:
 *  Temperature in Kelvin = 1 / (A + B[ln(R)] + C[ln(R)]^3)
 *  where A = 0.001129148, B = 0.000234125 and C = 8.76741*10^-8  */
  temperature = (1 / (A + (B * log(Rth)) + (C * pow((log(Rth)),3))));   // Temperature in kelvin

  temperature = -temperature + 273.15;  // Temperature in degree celsius
  temperature = temperature * (9/5.) + 32; // Temperature in degree Fahrenheit
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" degree Fahrenheit");
  delay(PRINTDELAY);
}
