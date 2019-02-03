#include "DHT11.h"

DHT11::DHT11(uint8_t pin)
{
	_pin = pin;
}

float DHT11::temperatura_C()
{   
    return (float)((resultado & 0x0000FF00) >> 8);
}

float DHT11::temperatura_K()
{   
    return 273.15 + temperatura_C();
}

float DHT11::temperatura_F()
{   
    return 1.8 * temperatura_C() + 32.0;
}

float DHT11::humedad()
{
    return (float) (resultado >> 24);
}

uint32_t DHT11::leer()
{
    resultado = 0;
    uint8_t  i;

   
    pinMode(_pin, INPUT);
     digitalWrite(_pin, LOW);    // pongo a 0 la báscula de salida                     // ----
    pinMode(_pin, OUTPUT);  //  
	delay(18);
  
    pinMode(_pin, INPUT);    // ponemos la línea a 1
    while (digitalRead(_pin) == HIGH) {}  // espero hasta que el sensor tome el
                                      // control de la línea
  
    while (digitalRead(_pin) == LOW) {}  // esperar mientras 0
    while (digitalRead(_pin) == HIGH) {} // esperamos mientras 1
  
    for (i = 0; i < 32; i++)
    {
      resultado = resultado << 1;  
      while (digitalRead(_pin) == LOW) {}
      delayMicroseconds(40);
      if (digitalRead(_pin) == HIGH)
        resultado = resultado + 1;
      while (digitalRead(_pin) == HIGH) {}    // espero por si he leido un 1
                                        //y el sensor no ha puesto la linea a 0
    }
	return resultado;
}