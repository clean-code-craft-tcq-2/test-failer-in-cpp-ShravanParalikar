#include <iostream>
#include <assert.h>

int alertFailureCount = 0;
   
int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return celcius < 200 ? 200 : 500;
}

float convertFarenheitToCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    return celcius;
}

void alertInCelcius(float farenheit,int (*networkAlertFnPtr)(float)) {
    float celcius = convertFarenheitToCelcius(farenheit);
    int returnCode = (*networkAlertFnPtr)(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}


int main() {

    alertInCelcius(400.5 ,networkAlertStub );
    assert(alertFailureCount== 1);
    alertInCelcius(303.6 ,networkAlertStub );
    assert(alertFailureCount== 1);
    alertInCelcius(603.6 , networkAlertStub);
    assert(alertFailureCount== 2);
    
    std::cout << "All is well (maybe!)\n";
    return 0;
}