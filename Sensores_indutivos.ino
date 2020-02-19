const int sensor_indutivoDown = 2; //Sensor acoplado à chapa //fio verde ground e marrom e branco nas portas
const int sensor_indutivoUp = 3; //Sensor acoplado à chapa
int manualDown; //Varável de registro da leitura do sensor indutivo
int manualUp; //Varável de registro da leitura do sensor indutivo
void setup() 
{
  Serial.begin(9600);
  //i/o
  pinMode(sensor_indutivoDown, INPUT_PULLUP);
  pinMode(sensor_indutivoUp, INPUT_PULLUP);
  Serial.print("Start\n\n");  
}
void loop() {
  manualUp = digitalRead(sensor_indutivoUp);
  manualDown = digitalRead(sensor_indutivoDown);
  delay(100);
  if (manualUp == 0 && manualDown==0)
  {
    Serial.print("ambos\n");
  }
  else if (manualUp == 0 && manualDown==1)
  {
    Serial.print("sensor down\n");
  }
  
  else if (manualUp == 1 && manualDown==0)
  {
    Serial.print("sensor Up\n");
  }
  
  else if (manualUp == 1 && manualDown==1)
  {
    Serial.print("nada\n");
  }
}
