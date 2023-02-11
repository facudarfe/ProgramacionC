#include <stdio.h>

float PI = 3.14;
float calcularArea(float radio);

int main(int argc, char *argv[]) {
	float radio = 15.2, area;
	
	area = calcularArea(radio);
	printf("%f", area);
	
	return 0;
}

float calcularArea(float radio){
	return PI*radio*radio;
}

