#include "Arduino.h"

class DHT11
{
private:
	int _pin;
    uint32_t resultado;
	
public:
	DHT11(uint8_t);
   
	float temperatura_C();
	float temperatura_K();
	float temperatura_F();
	float humedad();
	uint32_t leer();
};
