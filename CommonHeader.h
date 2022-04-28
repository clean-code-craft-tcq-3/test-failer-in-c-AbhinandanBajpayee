#include <string.h>
#include <cstring>

#define TemperatureThreshold 200
extern int alertFailureCount;
int printColorMap();
char size(int cms);
int networkAlertStub(float celcius);
void alertInCelcius(float farenheit);
float farenheitToCelcius(float farenheit);

struct Colorpair
{
	char MajorColor[10];
	char MinorColor[10];
};

