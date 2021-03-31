//variaveis da led
const int vermelho = 5;
const int verde = 6;
const int azul = 7;

//variavel de verdadeiro ou falso
bool estadoLedVermelho = false;

//variaveis dos botões
const int botao1 = 2;
const int botao2 = 3;
unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 0;
const int botaoDelay = 100;

//declarando as entradas dos componente de entrada e saída
void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  
  Serial.begin(9600);
	
  Serial.println("AC1 - Meu Primeiro Projeto 2021");
  Serial.println("                           V1.0");
  Serial.println("Grupo: Aloha 3.0             ");
}

//programando as funcionalidades
void loop()
{
  if((millis() - lastDebounceTime1) > botaoDelay && digitalRead(botao1)){ //codigo para exibir o comando apenas uma vez ao apertar o botao
  	Serial.println("botao 1 apertado");
    ledVermelho(true);
  	lastDebounceTime1 = millis();
  }
    if((millis() - lastDebounceTime2) > botaoDelay && digitalRead(botao2)){ //codigo para exibir o comando apenas uma vez ao apertar o botao
  	Serial.println("Sistema desligado");
    ledVermelho(false);
  	lastDebounceTime2 = millis();
  }
  //verificador de tempetura
  if(getTemperatura() > 15){
    ledAzul(true);
	  Serial.println("Temperatura acima de 15ºC");
  }else{
  	ledAzul(false); 
	   Serial.println("Temperatura abaixo de 15ºC");
  }
//verificador de luminosidade
if(getLuminosidade() > 5){
    ledVerde(true);
           Serial.println("Luminosidade alta");
 }else{
  	ledVerde(false); 
           Serial.println("Luminosidade baixa");
  }
  	
  delay(10);
}

void ledVermelho(bool estado){
  digitalWrite(vermelho,estado);
  
}
void ledVerde(bool estado){
 digitalWrite(verde,estado);
 
}
void ledAzul(bool estado){
	digitalWrite(azul,estado);
}

int getTemperatura(){
  	int temperaturaC;
	temperaturaC = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  	return temperaturaC;
} 

int getLuminosidade(){
  	int luminosidade;
	luminosidade = map(analogRead(A1), 6, 619, -3, 10);
  	return luminosidade;
}
