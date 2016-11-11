#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <ctype.h>
#define TAM 3
typedef struct
{
    char titulo[50];
    char genero[20];
    int duracion;
    char descripcion[1000];
    int puntaje;
    char linkImagen[300];
    int idPelicula;
    int isEmpty;
}EMovie;

int main()
{
	EMovie peli[TAM];
    char seguir='s';
    int id=1000;
    char opcion;
    char archivo[]={"Peliculas-Web.html"};
    
    inicialisar(peli,TAM);
    
    do
    {
        switch(menu())
        {
            case 1:
            	system("cls");
            	if(agregarPelicula(peli,TAM,id))
				{
					id++;
				}
				else
				{
					printf("No se ejecuto el alta\n");
				}
                break;
            case 2:
            	system("cls");
            	if(borrarPelicula(peli,TAM))
            	{
            		printf("Borrado OK\n");
				}else
				{
					printf("No paso nada\n");
				}
                break;
            case 3:
            	system("cls"); 
				modificarPelicula(peli,TAM);  
               	break;
            case 4:
            	system("cls");
            	generarPagina(peli,TAM,archivo);
            	break;
            case 5:
            	printf("Desea Salir? s/n \n");
            	fflush(stdin);
            	opcion=tolower(getche());
				while(opcion != 's' && opcion != 'n')
					{
						printf("ERROR\nDesea Salir? s/n \n");
						fflush(stdin);
						opcion=tolower(getche());
					}            	
            	if(opcion=='s')
				{
			       seguir = 'n';
				}
                break;
        }
    }while(seguir=='s');
    
    printf("\n\n");
	system("pause");
    return 0;
}
