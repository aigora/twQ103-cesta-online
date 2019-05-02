/*CESTA ONLINE*/

/*
Falta por añadir:
Codigo de descuento
Dar una cantidad limitada a cada producto
Stocks para cada producto y asi comprobar si ya no quedan
*/


#include <stdio.h>
#include <string.h>

#define NUM_MAX_USUARIOS 100
#define NUM_MAX_PRODUCTOS 100

struct persona
{
	char nombre[50];
	int clave;
}usuarios[NUM_MAX_USUARIOS];
	
struct compra
{
	char nombre[50];
	int precio, identificador;
}productos[NUM_MAX_PRODUCTOS], cesta[NUM_MAX_PRODUCTOS];

int main()
{
	system ("color 3F");
	int opcion, n, precio_total=0;
	int nusuarios = 0, nproductos, npcesta, i; // npcesta=nproductoscesta
	int x=0; // x permite saber el exito o fracaso al iniciar sesion
	char inicio_nombre[50];
	int inicio_clave;
	
	char z[100]; // Esta cadena definira el nombre del fichero de un usuario en concreto y contendra su cesta propia
	
	do
	{
		//SE LEE EL FICHERO CON LOS DATOS DE LOS USUARIOS (NOMBRE Y CLAVE)
		FILE *fichero;		
		fichero = fopen("datos.txt", "r");			
		if(fichero==NULL)
		{
			printf("No es posible abrir el fichero.\n");
		}
		while (fscanf(fichero, "%s %i", usuarios[nusuarios].nombre, &usuarios[nusuarios].clave)!=EOF)
		{
			nusuarios++;
		}
		fclose(fichero);
				
		printf("\nMENU DE OPCIONES\n1-Registrarse\n2-Iniciar sesion\n3-Salir de la pagina\n");
		scanf("%i", &opcion);
		switch(opcion)
		{
			case 1:
				
				//ABRO EL FICHERO EN EL QUE ESCRIBO LOS DATOS DE LOS USUARIOS (NOMBRE Y CLAVE)
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
				do
				{
					printf("\n\nIntroduce el nombre de usuario\n");
					fflush(stdin);
		            gets(inicio_nombre);
		            
					printf("introduce la clave\n");
					scanf("%i",&inicio_clave);
					
					//COMPRUEBO QUE COINCIDEN  EL NOMBRE Y CLAVE QUE INTRODUCE EL USUARIO CON LOS YA REGISTRADOS
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
					
					//COINCIDEN -> PUEDE INICIAR LA SESION
					if(x==1)
					{
						//printf("Puede inciar sesion\n");
						do
						{
							//COPIO EN LA CADENA DE CARACTERES Z EL NOMBRE DEL USUARIO SEGUIDO DE .TXT
							strcpy(z, inicio_nombre);
							strcat(z,".txt");
							
							
							//LEO LOS PRODUCTOS QUE ESTAN EN VENTA DE NUESTRA TIENDA
							fichero = fopen("productos.txt", "r");			
							if(fichero==NULL)
							{
								printf("No es posible abrir el fichero.\n");
							}
							nproductos=0;
							while (fscanf(fichero, "%d %s %i", &productos[nproductos].identificador, productos[nproductos].nombre, &productos[nproductos].precio)!=EOF)
							{
								nproductos++;
							}
							fclose(fichero);
							
							//LEO LA CESTA DEL USUARIO QUE HA INICIADO LA SESION
							fichero = fopen(z, "r");			
							if(fichero==NULL)
							{
								printf("No es posible abrir el fichero.\n");
							}
							npcesta=0;
							while (fscanf(fichero, "%d", &cesta[npcesta].identificador)!=EOF)
							{
								npcesta++;
							}
							fclose(fichero);
								
							printf("\nGESTIONANDO SU COMPRA\n1-Comprar productos\n2-Ver tu cesta\n3-Finalizar compra\n");
							scanf("%i", &opcion);
							switch(opcion)
							{
								case 1:
								
								printf("\nLos productos disponibles son:\n");
								for(i=0;i<nproductos;i++)
								{
									printf("Identificador: %d\tModelo: %s\tPrecio: %ieuros\n", productos[i].identificador, productos[i].nombre, productos[i].precio);
								}
																
								printf("\nEscriba el identificador del producto que desea comprar\n");
								scanf("%d", &cesta[npcesta].identificador);
								
								//ABRO EL FICHERO QUE ES LA CESTA DEL USUARIO Y EN EL ESCRIBO LOS PRODUCTOS QUE COMPRA
								fichero=fopen( z, "a");
								fprintf(fichero, "%d\n", cesta[npcesta].identificador);
								fclose(fichero);
								break;
								
								case 2:
								for(i=0;i<nproductos;i++)
								{
									for(n=0;n<npcesta;n++)
									{
										if(productos[i].identificador==cesta[n].identificador)
										{
											printf("Identificador: %d\tModelo: %s\tPrecio: %ieuros\n", productos[i].identificador, productos[i].nombre, productos[i].precio);
										}	
									}															
								}
								
								if(npcesta==0)
								{
									printf("Aun no tiene ningun producto en la cesta\n");
								}
								
								break;
									
								case 3:
								for(i=0;i<nproductos;i++)
								{
									for(n=0;n<npcesta;n++)
									{
										if(productos[i].identificador==cesta[n].identificador)
										{
											precio_total=precio_total+productos[i].precio;
										}	
									}															
								}	
								printf("\n\nPRECIO A PAGAR: %i\n", precio_total);
								break;
								
								default: printf("Error al introducir la opcion\n");
							}
						}
						while(opcion!=3);
					}
					
					//NO COINCIDEN -> NO PUEDE INICIAR LA SESION
					else //x=0
					{
						printf("Error al inciar sesion, intentelo de nuevo\n");
					}
					
				}while(x!=1);
				
				
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
