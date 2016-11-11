#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"funciones.h"
#include <conio.h>
#include <ctype.h>
int menu()
{
	int opcion;
	printf("Elija una opcion:\n");
 	printf("1- Agregar pelicula\n2- Borrar pelicula\n3- Modificar pelicula\n4- Generar pagina web\n5- Salir\n");
	scanf("%d",&opcion);
	while(opcion<1 || opcion>5)
	{
		printf("ERROR,opcion de 1 a 5\n1- Agregar pelicula\n2- Borrar pelicula\n3- Modificar pelicula\n4- Generar pagina web\n5- Salir\n");
		scanf("%d",&opcion);
	}
	return opcion;
}
void Mostrar(Movie movie)
{
	printf("ID: %d\nTitulo:  %s\nGenero:  %s\nDuracion:  %d\n",movie.idPelicula,movie.titulo,movie.genero,movie.duracion);
	printf("Descripcion:  %s\nPuntuacion:  %d\n",movie.descripcion,movie.puntaje);
}
void MostrarTodo(Movie movie[],int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		if(movie[i].isEmpty==1)
		{
			Mostrar(movie[i]);
		}	
	}
}
int validarCadena(char cad[],int Largo)
{
	if(strlen(cad)>Largo)
		return 1;
			return 0;
}
int buscarLibre(Movie movie[],int tam)
{
	int i,index=-1;
	for(i=0;i<tam;i++)
	{
		if( movie[i].isEmpty == 0 )
		{
			index=i;
			break;
		}
	}
	return index;
}
int buscarPelicula(Movie movie[],int tam,int ID)
{
	int i,index=-1;
	for(i=0;i<tam;i++)
	{
		if( movie[i].idPelicula == ID && movie[i].isEmpty==1 )
		{
			index=i;
			break;
		}
	}
	return index;
}
void inicialisar(Movie movie[],int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		movie[i].isEmpty=0;
	}
}
int agregarPelicula(Movie movie[],int tam,int id)
{
	int index;
	int auxint;
	char auxcadena[1500];
	
	index = buscarLibre(movie,tam);
	
	if(index==-1)
	{
		printf("No hay lugar\n");
	}else
	{
		movie[index].idPelicula=id;
		
		printf("Ingrese titulo: \n");
		fflush(stdin);
		gets(auxcadena);
		while(validarCadena(auxcadena,50))
		{
			printf("ERROR\nIngrese titulo: \n");
			fflush(stdin);
			gets(auxcadena);
		}
		strcpy(movie[index].titulo,auxcadena);
			
		printf("Ingrese genero: \n");
		fflush(stdin);
		gets(auxcadena);
		while(validarCadena(auxcadena,20))
		{
			printf("ERROR\nIngrese genero: \n");
			fflush(stdin);
			gets(auxcadena);
		}
		strcpy(movie[index].genero,auxcadena);
		
		printf("Ingrese duracion: \n");
		scanf("%d",&auxint);
		while(auxint < 0 || auxint>400)
		{
			printf("ERROR\nIngrese duracion: \n");
			scanf("%d",&auxint);
		}
		movie[index].duracion=auxint;
		
		printf("Ingrese descripcion: \n");
		fflush(stdin);
		gets(auxcadena);
		while(validarCadena(auxcadena,1000))
		{
			printf("ERROR\nIngrese descripcion: \n");
			fflush(stdin);
			gets(auxcadena);
		}
		strcpy(movie[index].descripcion,auxcadena);
		
		printf("Ingrese puntaje: \n");
		scanf("%d",&auxint);
		while(auxint < 0 || auxint > 10 )
		{
			printf("ERROR\nIngrese puntaje: \n");
			scanf("%d",&auxint);
		}
		movie[index].puntaje=auxint;
		
		printf("Ingrese linkImagen:(archivo) \n");
		fflush(stdin);
		gets(auxcadena);
		while(validarCadena(auxcadena,300))
		{
			printf("ERROR\nIngrese linkImagen:(archivo) \n");
			fflush(stdin);
			gets(auxcadena);
		}
		strcpy(movie[index].linkImagen,auxcadena);
		
		movie[index].isEmpty=1;
		return 1;
	}
	return 0;
}
/**
 *  Borra una pelicula del archivo binario
 *  @param---movie la estructura a ser eliminada al archivo
 *  @return--retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */	
int borrarPelicula(Movie movie[],int tam)
{
	int id;
	int index;
    char opcion;
    
	MostrarTodo(movie,tam);
	
	printf("Ingrese ID de la pelicula que desee borrar: \n");
    scanf("%d",&id);

    index=  buscarPelicula(movie,tam,id);

    if(index == -1)
    {
    	printf("El ID que ingreso no se encuentra\n");
    }
    else
	{
		printf("Confirma eliminar dato? s/n\n");
	    opcion=tolower(getche());
	    while(opcion != 's' && opcion != 'n')
	    {
	        printf("Error\nReingrese: s/n\n");
	        opcion=tolower(getche());
	    }
		if(opcion =='s')
	    {
			movie[index].isEmpty=0;
	        printf("Borrado exitoso\n");
	        return 1;
		}
	    else
		{
	        printf("Se cancela el borrado\n");
		}
    }
	return 0;
}
void modificarPelicula(Movie movie[],int tam)
{
   	int auxint;
   	int index;
   	int opcion;
   	char auxcadena[1500];
   	char seguir;

   	MostrarTodo(movie,tam);

   	printf("Ingrese Id de la pelicula a modificar: \n");
   	scanf("%d",&auxint);

   	index=buscarPelicula(movie,tam,auxint);
   	
   	if( index == -1 )
	{
         printf("El Id ingresado no se encuentra\n");
    }
    else
	{
		printf("Ingrese la opcion a modificar: \n");
        printf("1- Titulo\n");
        printf("2- Genero\n");
        printf("3- Puntaje\n");
        printf("4- Duracion\n");
        printf("5- Descripcion\n");
        printf("6- Link de la imagen\n");
        scanf("%d", &opcion);
        while(opcion<1 || opcion>6)
        {
            printf("ERROR\nReingrese un valor valido,entre 1 y 6: \n");
        	scanf("%d", &opcion);
        }
        
        printf("\n\n Confirma que desea modificar? s/n\n");
        seguir=tolower(getche());
        while(seguir != 's' && seguir != 'n')
        {
        	printf("Error\nIngresar s/n: \n");
            seguir=tolower(getche());
        }

	    if(seguir == 's')
	    {
	
		    switch(opcion)
		    {
				case 1:
					printf("Ingrese nuevo titulo: \n");
					fflush(stdin);
					gets(auxcadena);
					while(validarCadena(auxcadena,50))
					{
						printf("ERROR\nIngrese nuevo titulo: \n");
						fflush(stdin);
						gets(auxcadena);
					}
					strcpy(movie[index].titulo,auxcadena);
				
				    printf("Modificacion realizada con exito\n");
				    break;
			 	case 2:
					printf("Ingrese nuevo genero: \n");
					fflush(stdin);
					gets(auxcadena);
					while(validarCadena(auxcadena,20))
					{
						printf("ERROR\nIngrese nuevo genero: \n");
						fflush(stdin);
						gets(auxcadena);
					}
					strcpy(movie[index].genero,auxcadena);		
		            
		            printf("Modificacion realizada con exito\n");
					break;
				case 3:
					printf("Ingrese nuevo puntaje: \n");
					scanf("%d",&auxint);
					while(auxint < 0 || auxint > 10 )
					{
						printf("ERROR\nIngrese nuevo puntaje: \n");
						scanf("%d",&auxint);
					}
					movie[index].puntaje=auxint;
		            
		            printf("Modificacion realizada con exito\n");
		            break;
		        case 4:
					printf("Ingrese nueva duracion: \n");
					scanf("%d",&auxint);
					while(auxint < 0 || auxint>400)
					{
						printf("ERROR\nIngrese nueva duracion: \n");
						scanf("%d",&auxint);
					}
					movie[index].duracion=auxint;
		            
		            printf("Modificacion realizada con exito\n");
		            break;
				case 5:
					printf("Ingrese nueva descripcion: \n");
					fflush(stdin);
					gets(auxcadena);
					while(validarCadena(auxcadena,1000))
					{
						printf("ERROR\nIngrese nueva descripcion: \n");
						fflush(stdin);
						gets(auxcadena);
					}
					strcpy(movie[index].descripcion,auxcadena);
					
		            printf("Modificacion realizada con exito\n");
		            break;
		        case 6:	
					printf("Ingrese nuevo linkImagen: \n");
					fflush(stdin);
					gets(auxcadena);
					while(validarCadena(auxcadena,300))
					{
						printf("ERROR\nIngrese nuevo linkImagen: \n");
						fflush(stdin);
						gets(auxcadena);
					}
					strcpy(movie[index].linkImagen,auxcadena);
		        	
					printf("Modificacion realizada con exito\n");
					break;
		    }
	    }
	    else
		{
	    	printf("Cancelo la modificacion\n");
	    }
    }	
}
void generarPagina(Movie movie[],int tam,char NombreArchivo[])
{   
	int cantidadEscrita;
    int i;
    int Longitud;
    char lineaTitulo[1000];
    char lineaDuracion[500];
    char lineaPuntaje[500];
    char lineaDescripcion[1000];
    char lineaGenero[500];
    char lineaLink[500];
    char CadenaInicio[]="<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><title>Lista peliculas</title><!-- Bootstrap Core CSS --><link href='css/bootstrap.min.css' rel='stylesheet'><!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --><link href='css/custom.css' rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body><div class='container'><div class='row'><!-- Repetir esto para cada pelicula -->";

   	char lineaHeaderIni[] = "<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='";
    char lineaHeaderFin[] = "' alt=''></a>";
    char lineaTituloIni[]="<h3><a href='#'>";
    char lineaTituloFin[]="</a></h3>";
    char lineaIniGenero[]="<ul><li>Genero: ";
    char lineaFinGenero[]="</li>";
    char lineaPuntajeIni[]="<li>Puntaje: ";
    char lineaPuntajeFin[]="</li>";
    char puntaje[10];
    char duracion[10];
    char lineaDuracionIni[]="<li>Duracion: ";
    char lineaDuracionFin[]="</li></ul>";
    char lineaDescripcionIni[]="<p>Descripcion: ";
    char lineaDescripcionFin[]="</p></article>";
    char lineaCadenaFin[]="</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>";

    // Creo el archivo y lo abro
    FILE *Archivo= fopen(NombreArchivo, "w");
    
    if(Archivo==NULL)
    {
        printf("ERROR. El programa se cerrará\n");
    	exit(1);
    }
    Longitud=strlen(CadenaInicio);
    //escribo la cabecera del archivo
    cantidadEscrita=fwrite(CadenaInicio,sizeof(char),Longitud,Archivo);
    
    if(cantidadEscrita<Longitud)
    {
        printf("Error al escribir el archivo\n");
        exit(1);
    }
    
    for(i=0;i<tam;i++)
    {
		if(movie[i].isEmpty==1)
        {
        	// inicializo el vector
        	lineaLink[0]='\0';
            strcat(lineaLink,lineaHeaderIni);
            strcat(lineaLink,movie[i].linkImagen);
            strcat(lineaLink,lineaHeaderFin);
            //lineaLink contiene el texto a ser grabado
            Longitud=strlen(lineaLink);

            //escribo en el archivo el texto del link de la imagen
            cantidadEscrita=fwrite(lineaLink, sizeof(char), Longitud, Archivo);

            if(cantidadEscrita<Longitud)
            {
                printf("Error al escribir el archivo\n");
                exit(1);
            }
			lineaTitulo[0]='\0';
            strcat(lineaTitulo,lineaTituloIni);
            strcat(lineaTitulo,movie[i].titulo);
            strcat(lineaTitulo,lineaTituloFin);

            Longitud=strlen(lineaTitulo);

            cantidadEscrita=fwrite(lineaTitulo, sizeof(char), Longitud, Archivo);
            if(cantidadEscrita<Longitud)
            {
                printf("Error al escribir el archivo\n");
                exit(1);
            }
			lineaGenero[0]='\0';
            strcat(lineaGenero,lineaIniGenero);
            strcat(lineaGenero,movie[i].genero);
            strcat(lineaGenero,lineaFinGenero);

            Longitud=strlen(lineaGenero);

            cantidadEscrita=fwrite(lineaGenero, sizeof(char), Longitud, Archivo);

            if(cantidadEscrita<Longitud)
            {
                printf("Error al escribir el archivo\n");
            	exit(1);
            }

            lineaPuntaje[0]='\0';
            sprintf(puntaje,"%d",movie[i].puntaje);
            strcat(lineaPuntaje,lineaPuntajeIni);
            strcat(lineaPuntaje,puntaje);
            strcat(lineaPuntaje,lineaPuntajeFin);
            
            Longitud=strlen(lineaPuntaje);

            cantidadEscrita=fwrite(lineaPuntaje, sizeof(char), Longitud, Archivo);

            if(cantidadEscrita<Longitud)
            {
                printf("Error al escribir el archivo");
                exit(1);
            }

            sprintf(duracion,"%d",movie[i].duracion);

            lineaDuracion[0]='\0';
            strcat(lineaDuracion, lineaDuracionIni);
            strcat(lineaDuracion, duracion);
            strcat(lineaDuracion, lineaDuracionFin);
            Longitud=strlen(lineaDuracion);

            cantidadEscrita=fwrite(lineaDuracion, sizeof(char), Longitud, Archivo);

            if(cantidadEscrita<Longitud)
            {
                printf("Error al escribir el archivo\n");
                exit(1);
            }

            lineaDescripcion[0]='\0';
            strcat(lineaDescripcion, lineaDescripcionIni);
            strcat(lineaDescripcion, movie[i].descripcion);
            strcat(lineaDescripcion, lineaDescripcionFin);
            Longitud=strlen(lineaDescripcion);

            cantidadEscrita=fwrite(lineaDescripcion, sizeof(char), Longitud, Archivo);

            if(cantidadEscrita<Longitud)
            {
                printf("Error al escribir el archivo\n");
                exit(1);
            }
        }
    }
    //escribo el final del archivo
    Longitud=strlen(lineaCadenaFin);
    cantidadEscrita=fwrite(lineaCadenaFin, sizeof(char), Longitud, Archivo);

    if(cantidadEscrita<Longitud)
    {
        printf("Error al escribir el archivo\n");
        exit(1);
    }
    printf("Se creo correctamente el archivo.\n");
    //Cierro el archivo
    fclose(Archivo);
}
