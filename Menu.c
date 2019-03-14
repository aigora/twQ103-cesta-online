/* 
	Al querer comprar un producto, pedir que inicie sesion o registrarse si aun no lo ha hecho.
	En finalizar comprar recordar pedir si se tiene algun codigo de descuento.
*/

#include <stdio.h>

int main()
{
	char opcion;
	printf("Menu en estado beta\n\n\n");
	
	
	do
	{
		printf("MENU DE OPCIONES\n1-Registrarse\n2-Iniciar sesion\n3-Comprar productos\n4-Mirar tu cesta\n5-Finalizar compra\n6-Salir del menu\n\n");
		scanf("%i", &opcion);
		switch(opcion)
		{
			case 1:
			break;
			
			case 2:
			break;
			
			case 3:
			break;
			
			case 4:
			break;
			
			case 5:
			break;
			
			case 6:
			printf("Esperamos volver a verte ;)\n");
			break;
			
			default: printf("Error al introducir la opcion\n");
						
		}
	}
	while(opcion!=6);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
