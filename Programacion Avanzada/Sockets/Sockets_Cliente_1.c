/***********************************************************/
/*********************PROGRAMA CLIENTE*********************/
/***********************************************************/

// Estructura utilizada por el socket
/*
struct sockaddr_in{
	short int sin_family; 			// Familia de direcciones. Usaremos siempre "AF_INET"
	unsigned short int sin_port; 	// Numero de puerto
	struct in_addr sin_addr;		// Estructura que indica la direccion IP
	unsigned char sin_zero[8];		// Array de 8 bytes rellenados a cero.
}
*/


// Protocolos disponibles para el transporte de datos
/*
TCP (SOCK_STREAM) --> 	Socket de flujo que define una comunicacion bidireccional, confiables y orientada a la conexion.
						Todo lo que se mande desde el origen llegar� al destino.
						Necesitan mantener una conexion abierta.
		
UDP (SOCK_DGRAM) --> 	Socket de datagramas que no esta orientado a la conexion y no es confiable.
						No precisan mantener una conexion abierta.
*/

#include <stdio.h>
#include <winsock2.h>
#include <string.h>

int main(int argc, char **argv){
	WSADATA wsa;
	SOCKET skt;
	int puerto = 55227, recv_size;
	char mensaje[2000];
	struct sockaddr_in server;
	
	/**********************INICIALIZACION WINSOCK**********************/
	printf("Inicializando Winsock...");
	if(WSAStartup(MAKEWORD(2, 2), &wsa) != 0){
		printf("Error al inicializar winsock\n");
		exit(-1);
	}
	printf("Winsock inicializado\n");
	
	/**********************CREACION SOCKET**********************/
	printf("Creando socket...");
	if((skt = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET){
		printf("Error creando socket\n");
		exit(-1);
	}
	printf("Socket creado\n");
	
	/**********************CONFIGURACION SOCKADDR_IN**********************/	
	server.sin_family = AF_INET; // Familia TCP/IP
	server.sin_port = htons(puerto); // Puerto de la aplicacion del servidor
	server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Direccion IP del servidor
	
	/**********************CONEXION AL SERVIDOR**********************/	
	if(connect(skt, (struct sockaddr *)&server, sizeof(server)) < 0){
		printf("Error de conexion\n");
		exit(-1);
	}
	printf("Conexion exitosa\n");
	
	/**********************ENVIAR UN MENSAJE**********************/	
	printf("Ingrese mensaje a enviar: "); gets(mensaje);
	if(send(skt, mensaje, strlen(mensaje), 0) < 0){
		printf("Error al enviar mensaje\n");
		exit(-1);
	}
	
	printf("Mensaje enviado exitosamente\n");
	
	/**********************RECEPCION DE MENSAJE**********************/	
	printf("Esperando respuesta entrante...\n");
	if((recv_size = recv(skt, mensaje, 2000, 0)) == SOCKET_ERROR)
		printf("Recepcion fallida\n");
		
	mensaje[recv_size] = '\0';
	printf("%s\n\n", mensaje);
	
	closesocket(skt);
	WSACleanup();
	
	return 0;
}
