#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;
#define TemperatureThreshold 200

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

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
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
