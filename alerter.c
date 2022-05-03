#include <stdio.h>
#include <assert.h>
#include "CommonHeader.h"

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    int returnCode = 0; 
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if(TemperatureThreshold < celcius)
    {
        returnCode = 500;
    }
    else
    {
        returnCode = 200;
    }
    return returnCode;
}

float farenheitToCelcius(float farenheit)
{
    float celcius;
    celcius = (farenheit - 32) * 5 / 9;
    return celcius;
}

void alertInCelcius(float farenheit) {
    float celcius = farenheitToCelcius(farenheit);
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    printf("%d alerts failed.\n", alertFailureCount);
    assert(alertFailureCount == 1);
    printf("All is well (maybe!)\n");
    return 0;
}
