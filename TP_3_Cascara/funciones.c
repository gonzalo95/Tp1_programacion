#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "funciones.h"

#define OCUPADO 1
#define LIBRE 0

int agregarPelicula(EMovie movie)
{
    FILE *binario;
    binario = fopen("movies.dat", "ab");

    if(binario == NULL)
    {
        fclose(binario);
        return 0;
    }

    if(movie.estado == OCUPADO)
        fwrite(&movie, sizeof(EMovie), 1, binario);

    fclose(binario);

    return 1;
}

void generarPagina(EMovie lista[], char nombre[], int cant)
{
    int i;
    char encabezado[] = "<!DOCTYPE html>\n<!-- Template by Quackit.com -->\n<html lang='en'>\n<head>\n<meta charset='utf-8'>\n<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n<meta name='viewport' content='width=device-width, initial-scale=1'>\n<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n<title>Lista peliculas</title>\n<!-- Bootstrap Core CSS -->\n<link href='css/bootstrap.min.css' rel='stylesheet'>\n<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n<link href='css/custom.css' rel='stylesheet'>\n<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n<!--[if lt IE 9]>\n<script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n<script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n<![endif]-->\n</head>\n<body>\n<div class='container'>\n<div class='row'>\n";
    char pieDePagina[] = "</div>\n<!-- /.row -->\n</div>\n<!-- /.container -->\n<!-- jQuery -->\n<script src='js/jquery-1.11.3.min.js'></script>\n<!-- Bootstrap Core JavaScript -->\n<script src='js/bootstrap.min.js'></script>\n<!-- IE10 viewport bug workaround -->\n<script src='js/ie10-viewport-bug-workaround.js'></script>\n<!-- Placeholder Images -->\n<script src='js/holder.min.js'></script>\n</body>\n</html>\n";
    char pelicula[] = "\n<!-- Repetir esto para cada pelicula -->\n<article class='col-md-4 article-intro'>\n<a href='#'>\n<img class='img-responsive img-rounded' src=' %s ' alt=''>\n</a>\n<h3>\n<a href='#'> %s </a>\n</h3>\n<ul>\n<li>Género: %s </li>\n<li>Puntaje: %d </li>\n<li>Duración: %d </li>\n</ul>\n<p> %s </p>\n</article>\n<!-- Repetir esto para cada pelicula -->\n\n";

    FILE *html;
    html = fopen(nombre, "w");

    if(html == NULL)
    {
        printf("Se ha producido un error\n");
        fclose(html);
        return;
    }

    fwrite(encabezado, sizeof(char), strlen(encabezado), html);

    for(i = 0; i < cant; i++)
    {
        if(lista[i].estado == OCUPADO)
            fprintf(html, pelicula, lista[i].linkImagen, lista[i].titulo, lista[i].genero, lista[i].puntaje, lista[i].duracion, lista[i].descripcion);
    }

    fwrite(pieDePagina, sizeof(char), strlen(pieDePagina), html);

    fclose(html);
}

int cargarArray(EMovie array[], int len)
{
    EMovie aux;
    int i = 0;
    FILE *binario;
    binario = fopen("movies.dat", "rb");

    if(binario == NULL)
    {
        fclose(binario);
        return 0;
    }
    while(fread(&aux, sizeof(EMovie), 1, binario) == 1 && i < len)
    {
        array[i] = aux;
        i++;
    }
    fclose(binario);
    return 1;
}

int obtenerId(EMovie *lista, int len)
{
    int i;
    int maxId = -1;
    int retorno;
    for(i = 0; i < len; i++)
    {
        if(lista[i].estado == 1)
        {
            if((lista[i].id > maxId || maxId == -1) && lista[i].estado == OCUPADO)
                maxId = lista[i].id;
        }
    }
    retorno = maxId + 1;
    return retorno;
}

void listar(EMovie lista[], int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        if(lista[i].estado == OCUPADO)
            printf("Id: %d -- Nombre: %s\n", lista[i].id, lista[i].titulo);
    }
}

void inicializarArray(EMovie lista[], int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        lista[i].estado = LIBRE;
    }
}

int buscarPorId(EMovie lista[], int len, int id)
{
    int index = -1;
    int i;
    for(i = 0; i < len; i++)
    {
        if(lista[i].estado == OCUPADO && lista[i].id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

int pedirId(EMovie lista[], int len)
{
    int id;
    int retorno;
    printf("Ingrese el id: ");
    scanf("%d", &id);
    retorno = buscarPorId(lista, len, id);
    if(retorno == -1)
        printf("Id inexistente\n");
    return retorno;
}

int calcularCantidad(EMovie lista[], int len)
{
    int cantidad = 0;
    int i;
    for(i = 0; i < len; i++)
    {
        if(lista[i].estado == OCUPADO)
            cantidad++;
    }
    return cantidad;
}
