/*CESTA ONLINE*/


#include <stdio.h>
#include <string.h>

#define NUM_MAX_USUARIOS 100
#define NUM_MAX_PRODUCTOS 100

void imprimirBanner();
int menu1();
int menu2();
int menu3();

struct persona
{
	char nombre[50];
	char clave[50];
}usuarios[NUM_MAX_USUARIOS];
	
struct compra
{
	char nombre[50];
	int precio, identificador;
}productos[NUM_MAX_PRODUCTOS], cesta[NUM_MAX_PRODUCTOS];

struct codigo
{
	char nombre [50];
	int precio;
	
}descuentos[100];

int main()
{
	system ("color 3F");
	int opcion1, opcion2, opcion3, n, precio_total;
	int contador, nusuarios = 0, nproductos, npcesta, ndescuentos, i; // npcesta=nproductoscesta
	int r, c, x=0; // r permite saber si el nombre al registrarse esta en uso,c verifica el codigo de decuento, x permite saber el exito o fracaso al iniciar sesion
	char inicio_nombre[50], descuento[50];
	char inicio_clave[50];
	char z[100]; // Esta cadena definira el nombre del fichero de un usuario en concreto y contendra su cesta propia
	
	imprimirBanner();
	
	do
	{
		//SE LEE EL FICHERO CON LOS DATOS DE LOS USUARIOS (NOMBRE Y CLAVE)
		FILE *fichero;		
		fichero = fopen("datos.txt", "r");			
		
		while (fscanf(fichero, "%s %s", usuarios[nusuarios].nombre, usuarios[nusuarios].clave)!=EOF)
		{
			nusuarios++;
		}
		fclose(fichero);
				
		opcion1=menu1();
		switch(opcion1)
		{
			case 1:
				
				//ABRO EL FICHERO EN EL QUE ESCRIBO LOS DATOS DE LOS USUARIOS (NOMBRE Y CLAVE)
				fichero=fopen("datos.txt", "a");
				
				do{
					printf("\n\nIntroduce el nombre de usuario\n");
					fflush(stdin);
		            gets(usuarios[nusuarios].nombre);
		            
		            r=0;
		            for(i=0;i<nusuarios;i++){
		            	if (strcmp(usuarios[nusuarios].nombre,usuarios[i].nombre)==0){
		            		printf("El nombre ya esta en uso\n");
		            		r=1;
		            		break;
						}
					}
				}while(r==1);
	            
				printf("introduce la clave\n");
				fflush(stdin);
				gets(usuarios[nusuarios].clave);
				
				
				fprintf(fichero,"%s ", usuarios[nusuarios].nombre);
				fprintf(fichero,"%s\n", usuarios[nusuarios].clave);
				
				fclose(fichero);
								
			break;
			
			case 2:
				do
				{
					printf("\n\nIntroduce el nombre de usuario\n");
					fflush(stdin);
		            gets(inicio_nombre);
		            
					printf("introduce la clave\n");
					fflush(stdin);
					gets(inicio_clave);
					
					//COMPRUEBO QUE COINCIDEN  EL NOMBRE Y CLAVE QUE INTRODUCE EL USUARIO CON LOS YA REGISTRADOS
					for(i=0;i<nusuarios;i++)
					{
														
						if(0==strcmp(inicio_nombre,usuarios[i].nombre)&&0==strcmp(inicio_clave,usuarios[i].clave))
						{						
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
						
							npcesta=0;
							while (fscanf(fichero, "%d", &cesta[npcesta].identificador)!=EOF)
							{
								npcesta++;
							}
							fclose(fichero);
								
							opcion2=menu2();
							switch(opcion2)
							{
								case 1:
								
								printf("\nLos productos disponibles son:\n");
								for(i=0;i<nproductos;i++){
									
										if(productos[i].identificador==100){
											printf("ZAPATILLAS\n");
										}
										
										else if(productos[i].identificador==200){
											printf("CAMISETAS\n");
										}
										
										else{
											printf("Identificador: %d\tModelo: %s\tPrecio: %ieuros\n", productos[i].identificador, productos[i].nombre, productos[i].precio);
										}
								
								}
									
									
								do{
									printf("\nEscriba el identificador del producto que desea comprar\n");
									scanf("%d", &cesta[npcesta].identificador);
										
									if(cesta[npcesta].identificador!=1&&cesta[npcesta].identificador!=2&&cesta[npcesta].identificador!=3&&cesta[npcesta].identificador!=4
									&&cesta[npcesta].identificador!=5&&cesta[npcesta].identificador!=6&&cesta[npcesta].identificador!=7&&cesta[npcesta].identificador!=8
									&&cesta[npcesta].identificador!=9){
										
										printf("ERROR\n");
									}
								} while(cesta[npcesta].identificador!=1&&cesta[npcesta].identificador!=2&&cesta[npcesta].identificador!=3&&cesta[npcesta].identificador!=4
									&&cesta[npcesta].identificador!=5&&cesta[npcesta].identificador!=6&&cesta[npcesta].identificador!=7&&cesta[npcesta].identificador!=8
									&&cesta[npcesta].identificador!=9);
								
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
								do{
									
									opcion3=menu3();
									switch (opcion3){
										case 1:
										fichero = fopen("descuentos.txt", "r");			
										if(fichero==NULL)
										{
											printf("No es posible abrir el fichero.\n");
										}
										ndescuentos=0;
										while (fscanf(fichero, "%s %i", descuentos[ndescuentos].nombre, &descuentos[ndescuentos].precio)!=EOF)
										{
											ndescuentos++;
										}
										fclose(fichero);
										
										precio_total=0;	
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
										
										do{
											printf("Introduzca el codigo de descuento:\n");
											fflush(stdin);
											gets(descuento);
											
											c=0, contador=0;
											for(i=0;i<ndescuentos;i++)
											{	
												if(strcmp(descuento,descuentos[i].nombre)==0){
													c=1;
													break;
												}																
												contador++;
											}
										}while(c!=1);								
				
										printf("\n\nPRECIO A PAGAR: %.2f\n", precio_total*((float)descuentos[contador].precio/100));										
										return 0;
										
										
										break;
										
										case 2:
										precio_total=0;	
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
										return 0;
										break;
										
										default: printf("Error al introducir la opcion\n");
									}
									
								}while(opcion3!=1&&opcion3!=2);
								
								break;
								
								default: printf("Error al introducir la opcion\n");
							}
						}
						while(opcion2!=3);
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
	while(opcion1!=3);
	
	
	
	
	return 0;
	
}

void imprimirBanner()
{
	printf(".............................................\n");
	printf(".................CESTA ONLINE................\n");	
	printf(".............................................\n");
}

menu1(){
	
	int opcion;
	
	printf("\nMENU DE OPCIONES\n1-Registrarse\n2-Iniciar sesion\n3-Salir de la pagina\n");
	scanf("%i", &opcion);
	
	return opcion;
}

menu2(){
	
	int opcion;
	
	printf("\nGESTIONANDO SU COMPRA\n1-Comprar productos\n2-Ver tu cesta\n3-Finalizar compra\n");
	scanf("%i", &opcion);
	
	return opcion;
}


menu3(){
	
	int opcion;
	
	printf("Indique si cuenta con algun codigo de descuento\n1-SI\t2-NO\n");
	scanf("%i", &opcion);
	
	return opcion;
}

