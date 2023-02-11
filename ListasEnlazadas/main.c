#include <stdio.h>
#include <stdlib.h>
#include "TADLista.h"
#include "TADElemento.h"

int menu();

int main(void){
	int opc;
	tLista lis;
	tElem e;
	
	lis = nuevaLista();
	do{
		opc = menu();
		system("cls");
		switch(opc){
			case 1:
				printf("Cargue el elemento que desea insertar: \n");
				e = nuevoElem();
				agregarFinal(&lis, e);
				printf("Insercion al final exitosa!\n");
				break;
			case 2:
				printf("Cargue el elemento que desea insertar: \n");
				e = nuevoElem();
				agregarInicio(&lis, e);
				printf("Insercion al inicio exitosa!\n");
				break;
			case 3:
				printf("Cargue el elemento que desea insertar: \n");
				e = nuevoElem();
				agregarOrdenado(&lis, e);
				printf("Insercion ordenada exitosa!\n");
				break;
			case 4:
				printf("Que elemento desea eliminar?: \n");
				e = nuevoElem();
				eliminarElem(&lis, e);
				printf("Eliminacio con exito!\n");
				break;
			case 5:
				mostrarLista(lis);
				break;
			case 6:
				printf("Hasta luego.\n");
				break;
			default:
				printf("Opcion incorrecta. Vuelva a ingresar\n");
		}
		system("pause");
	}while(opc != 6);

	return 0;
}

int menu(){
	int opc;
	
	printf("\
				-------------------MENU------------------\n\
				| 1- Agregar un elemento al final       |\n\
				| 2- Agregar un elemento al inicio      |\n\
				| 3- Agregar un elemento ordenado       |\n\
				| 4- Eliminar un elemento               |\n\
				| 5- Mostrar la lista                   |\n\
				| 6- Salir                              |\n\
				-----------------------------------------\n");
	printf("Ingrese una opcion: "); scanf("%d", &opc);
	
	return opc;
}
