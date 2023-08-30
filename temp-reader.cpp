/*
* NASA Internship Project 2023
*
* Copyright 2023 Ari Perkins-Babcock
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* 
*     http://www.apache.org/licenses/LICENSE-2.0
* 
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#define aref_voltage 3.3 
int tempPin = A1;                                
int tempReading; 
 
void setup(void) {  
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);   
  analogReference(EXTERNAL);
  Serial.print("Hello from the Nasa Summer Program Interns!");
}
 
void loop(void) { 
  tempReading = analogRead(tempPin);   
  Serial.print("Temp reading = ");
  Serial.print(tempReading);   
  float voltage = tempReading * aref_voltage;
  voltage /= 1024.0; 
  Serial.print(" - ");
  Serial.print(voltage); Serial.println(" volts");
  float temperatureC = (voltage - 0.5) * 100 ;                      
  Serial.print(temperatureC); Serial.println(" degrees C");   
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  Serial.print(temperatureF); Serial.println(" degrees F"); 
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}