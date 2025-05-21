#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///---prototipados---
void mensajeDeEjercicios ();
Pila cargarUnaPila (Pila aCargar);
Pila deUnaPilaAotra (Pila origen);
Pila pasarUnaPilaEnOrden (Pila origen);
int menorElementoDeUnaPila (Pila pilita);
Pila ordenarPorSeleccion (Pila pilita);
Pila insertarEnPila (Pila original, int numAagregar);
Pila ordenarPorInsercion(Pila desordenada);
int sumaDetopes(Pila pilita);
Pila nuevaPilaSinMenor (Pila desordenada);  //Ordenamiento Por seleccion sin punteros.
int main()
{
    char seguir = 's';
    int num =0;
    int numAagregar;
    Pila pilita, nuevaPila;
    inicpila(&pilita);
    inicpila(&nuevaPila);

    while(seguir == 's')
    {
        int opcion;
        int rta =0;

        mensajeDeEjercicios();
        printf("Ingrese el ejercicio que desea realizar: \n");
        fflush(stdin);
        scanf("%i", &opcion);

        system("cls");

        switch(opcion)
        {
        case 1:
            pilita= cargarUnaPila(pilita);
            mostrar(&pilita);
            break;
        case 2:
            nuevaPila= deUnaPilaAotra(pilita);
            mostrar(&pilita);
            mostrar(&nuevaPila);
            break;
        case 3:
            nuevaPila= pasarUnaPilaEnOrden(pilita);
            printf("Pila origen\n");
            mostrar(&pilita);
            printf("Pila destino\n");
            mostrar(&nuevaPila);
            break;
        case 4:
            /*num = menorElementoDeUnaPila(pilita);
            printf("El menor elemento es %i\n", num*/
            nuevaPila= nuevaPilaSinMenor(pilita);
            mostrar(&nuevaPila);
            break;
        case 5:
            nuevaPila = ordenarPorSeleccion(pilita);
            printf("Nueva pila ordenada\n");
            mostrar(&nuevaPila);
            break;
        case 6:
            printf("Ingrese el valor que quiere agregar:\n");
            scanf("%i", &numAagregar);
            nuevaPila = insertarEnPila(pilita, numAagregar);
            mostrar(&nuevaPila);
            break;
        case 7:
            nuevaPila = ordenarPorInsercion(pilita);
            mostrar(&nuevaPila);
            break;
        case 8:
            rta = sumaDetopes (pilita);
            printf("La suma es %i\n", rta);
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }

        printf("Desea realizar otro ejercicio?");
        fflush(stdin);
        scanf("%c", &seguir);

        system("cls");
    }


    return 0;
}

void mensajeDeEjercicios ()
{
    printf("1- Ejercicio 1\n");
    printf("2- Ejercicio 2\n");
    printf("3- Ejercicio 3\n");
    printf("4- Ejercicio 4\n");
    printf("5- Ejercicio 5\n");
    printf("6- Ejercicio 6\n");
    printf("7- Ejercicio 7\n");
    printf("8- Ejercicio 8\n");
}


/* 1- Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el usuario.*/
Pila cargarUnaPila (Pila aCargar)
{
    char seguir = 's';

    while(seguir=='s')
    {
        leer(&aCargar);

        printf("Desea cargar otro valor? s/n");
        fflush(stdin);
        scanf("%c", &seguir);
    }

    return aCargar;
}


/*2. Hacer una función que pase todos los elementos de una pila a otra.*/

Pila deUnaPilaAotra (Pila origen)
{
    Pila destino;
    inicpila(&destino);

    while(!pilavacia(&origen))
    {
        apilar(&destino, desapilar(&origen));
    }

    return destino;
}

/*3- Hacer una función que pase todos los elementos de una pila a otra, pero conservdndo el orden.
*/
Pila pasarUnaPilaEnOrden (Pila origen)
{
    Pila nueva, aux;
    inicpila(&nueva);
    inicpila(&aux);

    while(!pilavacia(&origen))
    {
        apilar(&aux, desapilar(&origen));
    }

    while(!pilavacia(&aux))
    {
        apilar(&nueva, desapilar(&aux));
    }
    return nueva;
}
///!
/*4. Hacer una función que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila.*/
int menorElementoDeUnaPila (Pila pilita)
{
    Pila menor;
    Pila aux;
    inicpila(&aux);
    inicpila(&menor);

    apilar(&menor, desapilar(&pilita));

    while(!pilavacia(&pilita))
    {
        if (tope(&menor)>tope(&pilita))
        {
            apilar(&aux, desapilar(&menor));
            apilar(&menor, desapilar(&pilita));
        }
        else
        {
            apilar(&aux, desapilar(&pilita));
        }
    }

    /*
    //Lo que deberia hacer si es puntero: Volvemos los elementos a la pila.
    while (!pilavacia(&aux))
    {
        apilar(pilita, desapilar(&aux));
    }*/
    return tope(&menor);
}

///!
/*5. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección)*/
Pila ordenarPorSeleccion (Pila pilita)
{
    Pila pilaOrdenada;
    inicpila(&pilaOrdenada);
    int menor;

    while(!pilavacia(&pilita))
    {
        menor = menorElementoDeUnaPila(pilita);
        apilar(&pilaOrdenada, menor);
    }
    return pilaOrdenada;
}

Pila nuevaPilaSinMenor (Pila desordenada)
{
    Pila ordenada,aux; inicpila(&ordenada); inicpila(&aux);
    int menor;

    while(!pilavacia(&desordenada))
    {
        menor = desapilar(&desordenada);

        while(!pilavacia(&desordenada))
        {
            if (menor>tope(&desordenada))
            {
                apilar(&aux, desapilar(&menor));
                menor = tope(&desordenada);
            }
            else
            {
                apilar(&aux, desapilar(&desordenada));
            }
        }

        apilar(&ordenada, menor);

        while(!pilavacia(&aux))
        {
            apilar(&desordenada, desapilar(&aux));
        }

    }
    return ordenada;
}

/*6. Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden de ésta. */
Pila insertarEnPila (Pila original, int numAagregar)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&original)&& (tope(&original)>numAagregar))
    {
        apilar(&aux, desapilar(&original));
    }


    apilar(&original, numAagregar);

    while(!pilavacia(&aux))
    {
        apilar(&original, desapilar(&aux));
    }

    return original;
}

/*7. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 6.(Ordenamiento por inserción)*/

Pila ordenarPorInsercion(Pila desordenada)
{
    Pila ordenada;
    inicpila(&ordenada);

    while(!pilavacia(&desordenada))
    {
        ordenada = insertarEnPila(ordenada, desapilar(&desordenada));
    }

    return ordenada;
}

/*8. Hacer una función que sume los dos primeros elementos de una pila (tope y anterior),
y retorne la suma,  sin alterar el contenido de la pila. */

int sumaDetopes(Pila pilita)
{
    int rta=0;
    int rta2=0;
    Pila aux;
    inicpila(&aux);

    if(!pilavacia(&pilita))
    {
        rta = desapilar(&pilita);
       rta = rta + desapilar(&pilita);
    }

    return rta;
}
