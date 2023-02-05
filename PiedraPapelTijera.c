/*
Ejercicio: Se desea simular rondas del famoso juego piedra, papel o tijera.
El usuario jugará contra la maquina que elegira una opcion al azar.
Se le debe mostrar al usuario un menu con las siguientes opciones:
1-Seguir jugando
2-Ver marcador parcial
3-Salir

Mientras el usuario quiera seguir jugando el programa le pide su opcion de acuerdo
a la siguiente codificacion: 1-Piedra, 2-Papel, 3-Tijera. Sabemos que piedra gana
a tijera, papel gana a piedra y tijera gana a papel.
Si el usuario elige la opcion de "Ver marcador parcial" se debe mostrar por pantalla
cuantas victorias, cuantas derrotas y cuantos empates lleva hasta el momento.
Cuando se elige la opcion de "Salir" el juego termina y se muestra el marcado final
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	short playerOpt, PCOpt, menuOpt = 1, winnings = 0, losses = 0, draws = 0;
	
	srand(time(NULL));
	do{
		switch(menuOpt){
			case 1:
				system("cls");
				PCOpt = (int)(1 + rand() % 3);
				printf("1-Piedra\n2-Papel\n3-Tijera\n");
				printf("Ingrese su opcion: ");
				scanf("%hd", &playerOpt);
				
				if((playerOpt==1 && PCOpt==3)||(playerOpt==2 && PCOpt==1)||
					(playerOpt==3 && PCOpt==2)){
					printf("\nHAS GANADO\n");
					winnings++;
				}
				else{
					if((PCOpt==1 && playerOpt==3)||(PCOpt==2 && playerOpt==1)||
						(PCOpt==3 && playerOpt==2)){
						printf("\nHAS PERDIDO :(\n");
						losses++;
					}
					else{
						printf("\nHAN EMPATADO\n");
						draws++;
					}
				}
				system("pause");
				break;
			case 2:
				system("cls");
				printf("-----MARCADOR PARCIAL------\n");
				printf("Victorias: %hd\nDerrotas: %hd\nEmpates: %hd\n", winnings, losses, draws);
				system("pause");
				break;
			case 3: break;
			default:
				while(menuOpt<1 || menuOpt>3){
					printf("La opcion elegida es incorrecta. Ingrese nuevamente: ");
					scanf("%hd", &menuOpt);
				}
		}
		system("cls");
		printf("1-Seguir jugando\n2-Mostrar marcador parcial\n3-Salir\n");
		printf("Ingrese su opcion: "); scanf("%hd", &menuOpt);
	} while(menuOpt != 3);
	
	system("cls");
	printf("-----MARCADOR FINAL------\n");
	printf("Victorias: %hd\nDerrotas: %hd\nEmpates: %hd\n", winnings, losses, draws);
	
	return 0;
}

