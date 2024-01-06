
const int PULSE_SENSOR_PIN = 0;   // 'S' Signal pin connected to A0

float Signal;                // Store incoming ADC data. Value can range from 0-1024
float Threshold = 550; // Determine which Signal to "count as a beat" and which to ignore.
float fil;
float sgnl;

const float alpha = 0.1;    // Smoothing factor for the IIR filter

float filteredSignal = 0;   // Variable to store the filtered signal

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  // Built-in LED will blink to your heartbeat
  Serial.begin(9600);            // Set comm speed for serial plotter window
}

void loop() {
  Signal = analogRead(PULSE_SENSOR_PIN); // Read the sensor value

  // Apply the IIR filter
  filteredSignal = 0.969*fil + 0.0155*Signal + 0.0155*sgnl;

  delay(1);
  fil = filteredSignal;
  sgnl = Signal;

  Serial.print(Signal);
  Serial.print(" ");
  Serial.println(filteredSignal);  // Send the filtered signal value to the serial plotter

  if (filteredSignal > Threshold) {  // If the filtered signal is above threshold, turn on the LED
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);   // Else turn off the LED
  }

  delay(10);
}
