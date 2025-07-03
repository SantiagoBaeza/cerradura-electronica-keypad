#include <LiquidCrystal.h> 
#include <Keypad.h>        


LiquidCrystal lcd(7, 8, 9, 10, 11, 12); 

char Teclas[4][4] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte FILAS[4] = {2, 3, 4, 5};     
byte COLUMNAS[4] = {A0, A1, A2, A3}; 

Keypad TECLADO = Keypad(makeKeymap(Teclas), FILAS, COLUMNAS, 4, 4);

String clave;
int contador = 0;

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(13, HIGH);
  digitalWrite(6, LOW);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" CERRADURA ");
  lcd.setCursor(0, 1);
  lcd.print(" Electronica ");
  Serial.println("Sistema Inicializado");
  delay(3000);
  lcd.clear();
}

void loop()
{
  char tecla = TECLADO.getKey();
  lcd.setCursor(0, 0);
  lcd.print(" Puerta Cerrada ");
  lcd.setCursor(0, 1);
  lcd.print("* Ingrese clave ");
  if (tecla != NO_KEY)
  {
    if (tecla == '*')
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Ingresar Clave");
      Serial.println("Ingrese su clave de acceso");
      while (contador < 4)
      {
        char tecla = TECLADO.getKey();
        if (tecla != NO_KEY)
        {
          contador = contador + 1;
          clave += tecla;
          Serial.println(clave);
          Serial.println("El valor del contador es:");
          Serial.println(contador);
          lcd.setCursor(contador + 4, 1);
          lcd.print("*");
          delay(500);
        }
      }

      if (clave == "3519")
      {
        contador = 0;
        Serial.println("El valor del contador es:");
        Serial.println(contador);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Acceso Autorizad");
        lcd.setCursor(0, 1);
        lcd.print(" Puerta Abierta ");
        Serial.println("Acceso Autorizado - La puerta se abrira por 4 segundos");
        digitalWrite(6, HIGH);
        delay(4000);
        digitalWrite(6, LOW);
        clave = "";
      }
      else
      {
        contador = 0;
        Serial.println("El valor del contador es:");
        Serial.println(contador);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Acceso Denegado ");
        delay(4000);
        clave = "";
      }
      contador = 0;
    }
    Serial.println("Mensaje Inicial - Puerta Cerrada");
  }
}
