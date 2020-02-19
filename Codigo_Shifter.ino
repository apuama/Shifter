// Entradas 
const int b_direita =  A2; //Comando de aumento da marcha (borboleta direita)
const int b_esquerda = A3; //Comando de diminuição da marcha (borboleta esquerda)

const int sensor_indutivoDown = 2; // fio azul/verde
const int sensor_indutivoUp = 3; //fio azul/verde
// O marrom/amarelo vai no gnd 

int manualDown; //Varável de registro da leitura do sensor indutivo
int manualUp; //Varável de registro da leitura do sensor indutivo

// Saidas
const int pistao_avanco = A1; //Propulsão do pistão
const int pistao_recuo =  A0; //Retração do pistão

int macha_atual = 0; 
int num_macha   = 0; 

int shift_up = 0; //Variável de registro da leitura da borboleta direita
int shift_down = 0; //Variável de registro da leitura da borboleta esquerda

void macha_up(void); 
void macha_down(void);
void selecao_display(byte macha);

void setup() {
  Serial.begin(9600); 

  pinMode(8, OUTPUT);   //pino responsável pelo led A
  pinMode(7, OUTPUT);   //pino responsável pelo led B
  pinMode(6, OUTPUT);   //pino responsável pelo led C
  pinMode(5, OUTPUT);   //pino responsável pelo led D
  pinMode(4, OUTPUT);   //pino responsável pelo led E
  pinMode(9, OUTPUT);   //pino responsável pelo led F
  pinMode(10, OUTPUT);   //pino responsável pelo led G

  digitalWrite(4,LOW); 
  digitalWrite(5,LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8,LOW); 
  digitalWrite(9,LOW); 
  digitalWrite(10,HIGH); 

  
  pinMode(pistao_avanco, OUTPUT);
  pinMode(pistao_recuo, OUTPUT);
  
  pinMode(b_esquerda,INPUT);
  pinMode(b_direita,INPUT);

  pinMode(sensor_indutivoDown, INPUT_PULLUP);
  pinMode(sensor_indutivoUp, INPUT_PULLUP);

  Serial.print("Start\n");

  Serial.print("Comecou\n");
}

void loop() {
//Leitura de ambas as borboletas
  shift_up = digitalRead(b_direita);  // botao verde
  delay(20);
  shift_down = digitalRead(b_esquerda);
  delay(20);
  manualUp = digitalRead(sensor_indutivoUp);
  delay(20);
  manualDown = digitalRead(sensor_indutivoDown);  
  delay(20);

  if (macha_atual == 0 && shift_down == 0 && shift_up == 1){
    macha_down();
    num_macha++; 
    selecao_display(num_macha);
    Serial.print("Down!!\n");
    Serial.print(num_macha);
    Serial.print("\n");
  }

  
  else if (macha_atual>0 && macha_atual<6 && shift_down == 0 && shift_up == 1){
    macha_up();
    num_macha++;
    selecao_display(num_macha);
    Serial.print("Up!!\n");
    Serial.print(num_macha);
    Serial.print("\n");
  }
  else if ( macha_atual>0 && macha_atual <= 6 && shift_up == 0 && shift_down == 1){
    macha_down();
    num_macha--;
    selecao_display(num_macha);
    Serial.print("Down!!\n");
    Serial.print(num_macha);
    Serial.print("\n");
  }

  else if(manualUp == 0 && manualDown ==1 && num_macha<6 && num_macha>=0){
    num_macha++;
    selecao_display(num_macha);
    Serial.print("Up!!\n");
    Serial.print(num_macha);
    Serial.print("\n");
  }
  else if(manualUp == 1 && manualDown ==0 && num_macha>0 && num_macha<=6){
    num_macha--;
    selecao_display(num_macha);
    Serial.print("Down!!\n");
    Serial.print(num_macha);
    Serial.print("\n");
  }
  
  macha_atual = num_macha;

  delay(50);
}

//Função para acionar as valvulas para shift up
void macha_up(void){
  digitalWrite(pistao_avanco, HIGH);
  delay(21);
  digitalWrite(pistao_avanco, LOW);
  digitalWrite(pistao_recuo, HIGH);
  delay(33);
  digitalWrite(pistao_recuo, LOW);
}
void macha_down(void){
  //Função que determina recuo do pistão
  digitalWrite(pistao_recuo, HIGH);
  delay(21);
  digitalWrite(pistao_recuo, LOW);
  digitalWrite(pistao_avanco, HIGH);
  delay(21);
  digitalWrite(pistao_avanco, LOW);
}

void selecao_display(byte macha) {
  if(macha == 0)
  {
  digitalWrite(4,LOW); 
  digitalWrite(5,LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8,LOW); 
  digitalWrite(9,LOW); 
  digitalWrite(10,HIGH); 
  }
  if(macha == 1)
  {
  digitalWrite(4,HIGH); 
  digitalWrite(5,HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8,HIGH); 
  digitalWrite(9,HIGH); 
  digitalWrite(10,HIGH); 
  }if(macha == 2)
  {
  digitalWrite(4,LOW); 
  digitalWrite(5,LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8,LOW); 
  digitalWrite(9,HIGH); 
  digitalWrite(10,LOW);  
  }if(macha == 3)
  { 
  digitalWrite(4,HIGH); 
  digitalWrite(5,LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8,LOW); 
  digitalWrite(9,HIGH); 
  digitalWrite(10,LOW); 
  }if(macha == 4)
  {
  digitalWrite(4,HIGH); 
  digitalWrite(5,HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8,HIGH); 
  digitalWrite(9,LOW); 
  digitalWrite(10,LOW); 
  }if(macha == 5)
  {
  digitalWrite(4,HIGH); 
  digitalWrite(5,LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8,LOW); 
  digitalWrite(9,LOW); 
  digitalWrite(10,LOW);   
  }if(macha == 6)
  {
  digitalWrite(4,LOW); 
  digitalWrite(5,LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8,HIGH); 
  digitalWrite(9,LOW); 
  digitalWrite(10,LOW); 
  }
}


/*

 Catodo comum
 
 void selecao_display(byte macha) {
  if(macha == 0)
  {
  digitalWrite(4,HIGH); 
  digitalWrite(5,HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8,HIGH); 
  digitalWrite(9,HIGH); 
  digitalWrite(10,LOW); 
  }
  if(macha == 1)
  {
  digitalWrite(4,LOW); 
  digitalWrite(5,LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8,LOW); 
  digitalWrite(9,LOW); 
  digitalWrite(10,LOW); 
  }if(macha == 2)
  {
  digitalWrite(4,HIGH); 
  digitalWrite(5,HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8,HIGH); 
  digitalWrite(9,LOW); 
  digitalWrite(10,HIGH);  
  }if(macha == 3)
  { 
  digitalWrite(4,LOW); 
  digitalWrite(5,HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8,HIGH); 
  digitalWrite(9,LOW); 
  digitalWrite(10,HIGH); 
  }if(macha == 4)
  {
  digitalWrite(4,LOW); 
  digitalWrite(5,LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8,LOW); 
  digitalWrite(9,HIGH); 
  digitalWrite(10,HIGH); 
  }if(macha == 5)
  {
  digitalWrite(4,LOW); 
  digitalWrite(5,HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8,HIGH); 
  digitalWrite(9,HIGH); 
  digitalWrite(10,HIGH);   
  }if(macha == 6)
  {
  digitalWrite(4,LOW); 
  digitalWrite(5,HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8,LOW); 
  digitalWrite(9,HIGH); 
  digitalWrite(10,HIGH); 
  }
}*/
