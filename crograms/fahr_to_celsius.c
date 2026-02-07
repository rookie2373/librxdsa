#include<stdio.h>

/*	Print Fahrenheit-Celsius table 
	for fahr 0, 20, ....... 300
*/

int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

	fahr = lower;

	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr - 32);
		printf("Fahr\t%3.1f\tCelsius\t%6.2f\n", fahr, celsius);
		// smart typecasting to float
		fahr = fahr + step;
	}

	// six character wide
	printf("Step%6d\n", step);
	printf("Float%8.2f\n", celsius);

	// Different number systems
	int number = 33;
	printf("Octal %o\n", number);
	printf("Hexadecimal %x\n", number);
	
}