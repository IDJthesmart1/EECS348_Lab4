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

//Converts Fahrenheit to Kelvin using priviously defined functions
float fahrenheit_to_kelvin (float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

//Converts Kelvin to Fahrenheit using priviously defined functions
float kelvin_to_fahrenheit (float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

int main() {
    float temperature;
    char input_scale, output_scale;

    printf("Enter the temperature value: ");
    scanf("%f", &temperature);

    printf("Enter the input scale (C, F, K): ");
    scanf(" %c", &input_scale);

    printf("Enter the output scale (C, F, K): ");
    scanf(" %c", &output_scale);

    float converted_temperature = 0;

    if (input_scale == 'C' && output_scale == 'F') {
        converted_temperature = celsius_to_fahrenheit(temperature);
    } else if (input_scale == 'F' && output_scale == 'C') {
        converted_temperature = fahrenheit_to_celsius(temperature);
    } else if (input_scale == 'C' && output_scale == 'K') {
        converted_temperature = celsius_to_kelvin(temperature);
    } else if (input_scale == 'K' && output_scale == 'C') {
        converted_temperature = kelvin_to_celsius(temperature);
    } else if (input_scale == 'F' && output_scale == 'K') {
        converted_temperature = fahrenheit_to_kelvin(temperature);
    } else if (input_scale == 'K' && output_scale == 'F') {
        converted_temperature = kelvin_to_fahrenheit(temperature);
    }

    printf("The converted temperature is: %.2f\n", converted_temperature);

}