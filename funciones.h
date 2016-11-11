typedef struct
{
    char titulo[50];//20
    char genero[20];//20
    int duracion;
    char descripcion[1000];//100
    int puntaje;
    char linkImagen[300];//50
    int idPelicula;
    int isEmpty;
}Movie;

/*
brief  Genera menu de opciones.
return retorna la opcion elegida.
*/
int menu();

/*
brief Valida el largo de una cadena.
param  la cadena a comparar y el tamaño a ser comparado.
return retorna 1 si es valido, 0 si no lo es.
*/
int validarCadena(char[],int);

/*
brief  muestra un elemento de un elemento del array.
param  una posision del array de tipo Movie.
return retorna void.
*/
void Mostrar(Movie);

/*
brief  muestra todos los elemento del array cuyo estado sea 1.
param  un array de tipo Movie.
return retorna void.
*/
void MostrarTodo(Movie[],int);

/*
brief  busca un indice del array cuyo campo de estado sea cero(Libre)
param  un array de tipo Movie,un entero que representa el tamaño del array.
return retorna el indice de la primera posicion del array libre.
*/
int buscarLibre(Movie[],int);

/*
brief  compara un id ingresado por el usuario con el parametro id del array Movie.
param  un array de tipo Movie,un entero que representa el tamaño del array,un entero que representa el id a comparar.
return retorna el indice de la posicion del id si lo encuentra,de no hacerlo retorna -1.
*/
int buscarPelicula(Movie[],int,int);

/*
brief  inicializa el campo isEmpty del array en cero.
param  un array de tipo Movie,un entero que representa el tamaño del array.
return retorna void.
*/
void inicialisar(Movie[],int);
/*
brief    agrega una pelicula al array Movie
param    un array de tipo Movie,un entero que representa el tamaño del array,un entero que representa una id.
return   retorna 1 si pudo agregar la pelicula o 0 si no pudo
*/
int agregarPelicula(Movie[],int,int);
/*
brief  borra un elemento del array cambiando el estado a 0
param  un array de tipo Movie,un entero que representa el tamaño del array.
return retorna 1 si borro y 0 si no lo a hecho.
*/
int borrarPelicula(Movie[],int);
/*
brief  modifica algun dato,elegido por el usuario,del array de peliculas.
param  un array de tipo Movie,un entero que representa el tamaño del array.
return retorna void.
*/
void modificarPelicula(Movie[],int);
/*
brief  Genera un archivo html con los datos cargados en el array.
param  un array de tipo Movie,un entero que representa el tamaño del array,una cadena de caracteres con el nombre del archivo y su extencion.
return retorna void.
*/
void generarPagina(Movie[],int,char[]);
