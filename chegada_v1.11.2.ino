/*  ---------- CONTROLE DA CHEGADA -----------
TECNOLOGIA: FOTOCELULA COM SENSORES INFRAVERMELHO
RELÊS NORMAL FECHADO (HIGH = SEM CONTATO)
Recebendo sinal IR, digitalRead é false
-------------------------------------------------- */

#define pinSensorE 7
#define pinSensorD 8
#define pinLEDE 13
#define pinLEDD 12

boolean sinalizarE = false;
boolean sinalizarD = false;
boolean oldE = false;
boolean oldD = false;
boolean valorE = false;
boolean valorD = false;

unsigned long agora = 0;
unsigned long horaInterrompeuE = millis();
unsigned long horaInterrompeuD = millis();
unsigned long intervalo = 50;

void intro();
void venceu(int luz);

void setup() {
  pinMode(pinSensorE, INPUT);
  pinMode(pinSensorD, INPUT);
  pinMode(pinLEDE, OUTPUT);
  pinMode(pinLEDD, OUTPUT);

  intro();
}

void loop() {
  agora = millis();
  valorE = digitalRead(pinSensorE);
  valorD = digitalRead(pinSensorD);
//---------------------------SENSOR ESQUERDO  
  if (valorE && !oldE) { // ALTERNOU PARA INTERROMPIDO
    horaInterrompeuE = agora;
    oldE = valorE;
  }
  if (!valorE && oldE) { // ALTERNOU PARA RECEBENDO
    oldE = valorE;
    sinalizarE = true;
  }
//------------------------------SENSOR DIREITO -------------
  if (valorD && !oldD) { // ALTERNOU PARA INTERROMPIDO
    horaInterrompeuD = agora;
    oldD = valorD;
  }
  if (!valorD && oldD) { // ALTERNOU PARA RECEBENDO
    oldD = valorD;
    sinalizarD = true;
  }



  
//caso em que ta recebendo sinal, e alternou demorando 70 ms
  if (valorE && (agora >= (horaInterrompeuE+intervalo)) && sinalizarE) {
    sinalizarE = false;
    sinalizarD = false;
    venceu(pinLEDE);
    delay(500);
  }
  
  if (valorD && (agora >= (horaInterrompeuD+intervalo)) && sinalizarD) {
    sinalizarD = false;
    sinalizarE = false;
    venceu(pinLEDD);
    delay(500);
    }
}

void intro() {
//vamos comecar piscando as luzes
  digitalWrite(pinLEDE, LOW);
  digitalWrite(pinLEDD, HIGH);
  delay(200);
  digitalWrite(pinLEDE, HIGH);
  digitalWrite(pinLEDD, LOW);
  delay(200);
  digitalWrite(pinLEDE, LOW);
  digitalWrite(pinLEDD, HIGH);
  delay(200);
  digitalWrite(pinLEDE, HIGH);
  digitalWrite(pinLEDD, LOW);
  delay(200);
  digitalWrite(pinLEDE, LOW);
  digitalWrite(pinLEDD, HIGH);
  delay(200);
  digitalWrite(pinLEDE, HIGH);
  digitalWrite(pinLEDD, LOW);
  delay(200);  
  digitalWrite(pinLEDE, LOW);
  digitalWrite(pinLEDD, HIGH);
  delay(200);
  digitalWrite(pinLEDE, HIGH);
  digitalWrite(pinLEDD, LOW);
  delay(200);
  digitalWrite(pinLEDE, LOW);
}

void venceu(int luz) {
  digitalWrite(luz, HIGH);
  delay(200);
  digitalWrite(luz, LOW);
  delay(200);
  digitalWrite(luz, HIGH);
  delay(200);
  digitalWrite(luz, LOW);
  delay(200);
  digitalWrite(luz, HIGH);
  delay(200);
  digitalWrite(luz, LOW);
  delay(200);
  digitalWrite(luz, HIGH);
  delay(200);
  digitalWrite(luz, LOW);
  delay(200);
  digitalWrite(luz, HIGH);
  delay(1000);
  digitalWrite(luz, LOW);
  delay(1000);
  digitalWrite(luz, HIGH);
  delay(1000);
  digitalWrite(luz, LOW);
  delay(1000);
  digitalWrite(luz, HIGH);
  delay(1000);
  digitalWrite(luz, LOW);
  delay(1000);
}
