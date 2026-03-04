#include <stdio.h>

/*
/  EECS 348 Lab 4: Isaiah Jenks
/  This program will read in a temperature value in either Fahrenheit, Celsius or Kelvin, read in the scale, then read
/  in the conversion target scale. The program will then output the converted temperature value and a simple weather advisory.
*/

//Converts Celsius to Fahrenheit using the formula: F = (9/5)C + 32
float celsius_to_fahrenheit (float celsius) {
    return (9.0/5.0) * celsius + 32;
}
//Converts Fahrenheit to Celsius using the formula: C = (5/9)(F - 32)
float fahrenheit_to_celsius (float fahrenheit) {
    return (5.0/9.0) * (fahrenheit - 32);
}
//Converts Celsius to Kelvin using the formula: K = C + 273.15
float celsius_to_kelvin (float celsius) {
    return celsius + 273.15;
}
//Converts Kelvin to Celsius using the formula: C = K - 273.15
float kelvin_to_celsius (float kelvin) {
    return kelvin - 273.15;
}
//Converts Fahrenheit to Kelvin using previously defined functions
float fahrenheit_to_kelvin (float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}
//Converts Kelvin to Fahrenheit using previously defined functions
float kelvin_to_fahrenheit (float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}


int isKelvin(char *scale) {
    return (scale[0] == 'K' || scale[0] == 'k');
}
int isCelsius(char *scale) {
    return (scale[0] == 'C' || scale[0] == 'c');
}
int isFahrenheit(char *scale) {
    return (scale[0] == 'F' || scale[0] == 'f');
}

void categorize_temperature(float celsius) {
    if (celsius < -273.15) {
        printf("Wait, that's colder than absolute zero! That's not possible!\n");
    } else if (celsius >= -273.15 && celsius < -89.2) {
        printf("Whoa, that's a world record cold!\n");
    } else if (celsius >= -89.2 && celsius < 0) {
        printf("Weather Advisory: Freezing\nTry to stay inside and make sure to bundle up!\n");
    } else if (celsius >= 0 && celsius < 10) {
        printf("Weather Advisory: Cold\nMake sure to dress warmly and stay out of the wind.\n");
    } else if (celsius >= 10 && celsius < 25) {
        printf("Weather Advisory: Comfortable\nEnjoy the pleasant weather!\n");
    } else if (celsius >= 25 && celsius < 35) {
        printf("Weather Advisory: Hot\nMake sure to stay cool and take breaks in the shade.\n");
    } else if (celsius >= 35 && celsius < 56.7) {
        printf("Weather Advisory: Extreme Heat\nTry to stay inside and make sure to stay hydrated!\n");
    } else if (celsius >= 56.7 && celsius < 100) {
        printf("Whoa, that's a world record heat!\n");
    } else {
        printf("Wait, it's boiling out there! I don't think that's possible!\n");
    }
}

int main() {
    float InputTemperature;
    char inputScale[15], outputScale[15];
    float outputTemperature, celsiusTemperature;

    while(1) {

        printf("Enter the temperature value: ");
        scanf("%f", &InputTemperature);

        printf("Choose the temperature scale of the input value (Fahrenheit, Celsius, or Kelvin): ");
        scanf("%14s", inputScale);

        printf("Choose the conversion target (Fahrenheit, Celsius, or Kelvin): ");
        scanf("%14s", outputScale);


        if ((inputScale[0] == '\0' || outputScale[0] == '\0')) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        if (isCelsius(inputScale) && isFahrenheit(outputScale)) {
            outputTemperature = celsius_to_fahrenheit(InputTemperature);
            celsiusTemperature = InputTemperature;
        } else if (isFahrenheit(inputScale) && isCelsius(outputScale)) {
            outputTemperature = fahrenheit_to_celsius(InputTemperature);
            celsiusTemperature = outputTemperature;
        } else if (isCelsius(inputScale) && isKelvin(outputScale)) {
            outputTemperature = celsius_to_kelvin(InputTemperature);
            celsiusTemperature = InputTemperature;
        } else if (isKelvin(inputScale) && isCelsius(outputScale)) {
            outputTemperature = kelvin_to_celsius(InputTemperature);
            celsiusTemperature = outputTemperature;
        } else if (isFahrenheit(inputScale) && isKelvin(outputScale)) {
            outputTemperature = fahrenheit_to_kelvin(InputTemperature);
            celsiusTemperature = kelvin_to_celsius(outputTemperature);
        } else if (isKelvin(inputScale) && isFahrenheit(outputScale)) {
            outputTemperature = kelvin_to_fahrenheit(InputTemperature);
            celsiusTemperature = kelvin_to_celsius(InputTemperature);
        } else {
            printf("Invalid input. Please try again.\n");
            continue;
        }


        printf("The converted temperature is: %.2f°%c\n", outputTemperature, outputScale[0]);
        categorize_temperature(celsiusTemperature);

        if (celsiusTemperature < -273.15) {
            printf("Try again? (Y/N)\n");
            scanf("%14s", &inputScale);
            if (inputScale[0] == 'Y') {
                continue;
            }
        } else if (celsiusTemperature >= -273.15 && celsiusTemperature < -89.2) {
            printf("Are you sure? (Y/N)\n");
            scanf("%14s", &inputScale);
            if (inputScale[0] == 'Y') {
                printf("Well, I hope you have some heaters!\n");
            } else {
                printf("Phew, that's a relief!\n");
                continue;
            }
        } else if (celsiusTemperature >= 56.7 && celsiusTemperature < 100) {
            printf("Are you sure? (Y/N)\n");
            scanf("%14s", &inputScale);
            if (inputScale[0] == 'Y') {
                printf("Well, I hope you have some air conditioning!\n");
            } else {
                printf("Phew, that's a relief!\n");
                continue;
            }
        } else if (celsiusTemperature > 100) {
            printf("Try again? (Y/N)\n");
            scanf("%14s", &inputScale);
            if (inputScale[0] == 'Y') {
                continue;
            }
        }
        break; // break out of the while loop after a successful conversion and advisory message
    }

    return 0;
}
