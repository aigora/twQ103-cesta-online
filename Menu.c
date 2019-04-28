/*CESTA ONLINE*/

//En finalizar comprar recordar pedir si se tiene algun codigo de descuento.


#include <stdio.h>
#define NUM_MAX_USUARIOS 100

struct persona
{
	char nombre[50];
	int clave;
}usuarios[NUM_MAX_USUARIOS];
	

int main()
{
	
	int opcion;
	int nusuarios = 0, i, x=0;
	char inicio_nombre[50];
	int inicio_clave;
	

	
	do
	{
		//SE LEE EL FICHERO
		FILE *fichero;		
		fichero = fopen("datos.txt", "r");			
		if(fichero==NULL)
		{
			printf("No es posible abrir el fichero.\n");
		}
		while (fscanf(fichero, "%s%i", usuarios[nusuarios].nombre, &usuarios[nusuarios].clave)!=EOF)
		{
			nusuarios++;
		}
		fclose(fichero);
		
		//................................................................//
				
		printf("\nMENU DE OPCIONES\n1-Registrarse\n2-Iniciar sesion\n3-Salir de la pagina\n");
		scanf("%i", &opcion);
		switch(opcion)
		{
			case 1:
				fichero=fopen("datos.txt", "a");
				
				printf("\n\nintroduce el nombre de usuario\n");
				fflush(stdin);
	            gets(usuarios[nusuarios].nombre);
	            
				printf("introduce la clave\n");
				scanf("%i",&usuarios[nusuarios].clave);
				
				
				fprintf(fichero,"%s ", usuarios[nusuarios].nombre);
				fprintf(fichero,"%i\n", usuarios[nusuarios].clave);
				
				fclose(fichero);
								
			break;
			
			case 2:
				printf("\n\nintroduce el nombre de usuario\n");
				fflush(stdin);
	            gets(inicio_nombre);
	            
				printf("introduce la clave\n");
				scanf("%i",&inicio_clave);
				
				for(i=0;i<nusuarios;i++)
				{
					/*printf("\n\n%s\n", inicio_nombre);
					printf("%s\n\n\n", usuarios[i].nombre);
					printf("%i\n", inicio_clave);
					printf("%i\n", usuarios[i].clave);*/
					
					if(0==strcmp(inicio_nombre,usuarios[i].nombre)&&inicio_clave==usuarios[i].clave)
					{
						//printf("okeeeyy\n");
						x=1;
						break;
					}
					
				}
				if(x!=0)//x==1
				{
					printf("Puede inciar sesion\n");
				}
				else//x=0
				{
					printf("Error al inciar sesion\n");
				}
				
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
