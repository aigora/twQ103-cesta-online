/* 
	Al querer comprar un producto, pedir que inicie sesion o registrarse si aun no lo ha hecho.
	En finalizar comprar recordar pedir si se tiene algun codigo de descuento.
*/

#include <stdio.h>
#define NUM_MAX_USUARIOS 100

struct persona{
	char nombre[20];
	int clave;
}usuarios[NUM_MAX_USUARIOS];
	

int main()
{
	int opcion;
	

	int nusuarios = 0;
	
	printf("Menu en estado beta\n\n\n");
	
	
	do
	{
		printf("\nMENU DE OPCIONES\n1-Registrarse\n2-Iniciar sesion\n3-Salir de la pagina");
		scanf("%i", &opcion);
		switch(opcion)
		{
			case 1:
				printf("introduce el usuario\n");
				fflush(stdin);
	            gets(persona1.nombre);
	            
				printf("introduce la clave\n");
				scanf("%i",&persona1.clave);
				
				printf("\n su usuario es: %s",persona1.usuario);
				printf("\n su clave es: %i",persona1.clave);
					
			
			break;
			
			case 2:
			break;
			
			
			case 3:
			printf("Esperamos volver a verte ;)\n");
			break;
			
			default: printf("Error al introducir la opcion\n");
						
		}
	}
	while(opcion!=3);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
	
}

