// C++ code
/* Programa que ilumina con diferentes intensidades un led.
O programa debe definir un número limitado de niveis de luminosidade
e, empezando dende 0, subir de nivel de luminosidade. Ao chegar a máximo,
debe diminuir a luminosidade ata chegar ao 0 novamente

Criterios acerca do código:
O código debe ser lexible.
O mantemento debe ser o máis fácil posível.
*/

// Saida analóxica 11:
#define LED 11
#define VALOR_MAXIMO 255
#define VALOR_MINIMO 0
#define VALOR_INICIAL 0

int tempo = 200;
int nivel = -1; // Inicializamos cun nivel inválido
int incremento = 17;
bool fora_dos_limites = false;

void setup()
{
  //Saídas analóxicas non necesitan ser declaradas
  Serial.begin(9600);
  nivel = VALOR_INICIAL;
}

void loop ()
{
  int nivel_futuro;
  analogWrite(LED, nivel);
  delay(tempo);
  
  nivel_futuro = nivel + incremento;
  fora_dos_limites = nivel_futuro > VALOR_MAXIMO || nivel_futuro < VALOR_MINIMO;
  if (fora_dos_limites)
    incremento *= -1; // Cambia o sentido do incremento
  
  nivel = nivel + incremento;
  Serial.print("Nivel de luminosidade: ");
  Serial.println(nivel);
}

/* Modo 01
// Saída analóxica para o LED no pin 11:
#define LED 11

// Declaración de niveis
int nivel00 = 0;
int nivel01 = 51;
int nivel02 = 102;
int nivel03 = 153;
int nivel04 = 204;
int nivel05 = 255;

int tempo = 200;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()
{
  analogWrite(LED, nivel00);
  delay(tempo);
  analogWrite(LED, nivel01);
  delay(tempo);
  analogWrite(LED, nivel02);
  delay(tempo);
  analogWrite(LED, nivel03);
  delay(tempo);
  analogWrite(LED, nivel04);
  delay(tempo);
  analogWrite(LED, nivel05);
  delay(tempo);
  analogWrite(LED, nivel04);
  delay(tempo);
  analogWrite(LED, nivel03);
  delay(tempo);
  analogWrite(LED, nivel02);
  delay(tempo);
  analogWrite(LED, nivel02);
  delay(tempo);
  analogWrite(LED, nivel00);
  delay(tempo);
}
*/
