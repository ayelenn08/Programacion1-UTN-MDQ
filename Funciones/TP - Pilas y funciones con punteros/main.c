
#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void cargarUnaPila (Pila *p_nuevaPila);
void pasarElementos (Pila *p_origen, Pila *p_destino);
void conservarOrden(Pila *desordenada, Pila*ordenada);
int devolverMenor (Pila *pilita);
void ordenarPorSeleccion (Pila *desordenada, Pila *ordenada);
void agregarUnElemento (Pila *pilita, int elemento);
void agregarUnElemento2 (Pila *pilita, int elemento);
void ordenamientoXinsercion(Pila* desordenada, Pila*ordenada);
int sumaDeTopes (Pila *pilita);
int trasnformarAdigitos(Pila *pilita);
void mostrarUnaPila (Pila *pilita);

int main()
{
    Pila nueva,otraP;
    inicpila(&nueva);
    inicpila(&otraP);

    apilar(&nueva, 4);
    apilar(&nueva, 2);
    apilar(&nueva, 1);
    apilar(&nueva, 6);
    apilar(&nueva, 8);

    //cargarUnaPila(&nueva);

    //pasarElementos(&nueva,&otraP);

    //conservarOrden(&nueva, &otraP);
    //mostrar(&otraP);
    /*int menor  = devolverMenor(&nueva);
    printf("El menor quitado es %i", menor);*/

    //ordenarPorSeleccion(&nueva,&otraP);
    //agregarUnElemento(&otraP, 5);
    //agregarUnElemento2(&otraP,5);
    //ordenamientoXinsercion(&nueva, &otraP);
    //mostrar(&otraP);

    /*int rta = sumaDeTopes(&nueva);
    printf("La suma es %i", rta);*/

    /*mostrar(&nueva);
    int suma = trasnformarAdigitos(&nueva);

    printf("Valor en digito %i", suma);*/

    mostrarUnaPila (&nueva);
    return 0;
}

/*1. Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el usuario. */

void cargarUnaPila (Pila *p_nuevaPila)
{
    char mander = 's';

    while (mander == 's')
    {
        leer(p_nuevaPila);

        printf("Desea ingresar otro valor?\n");
        fflush(stdin);
        scanf("%c", &mander);
    }
}

/*2. Hacer una función que pase todos los elementos de una pila a otra. */
void pasarElementos (Pila *p_origen, Pila *p_destino)
{
    while (!pilavacia (p_origen))
    {
        apilar(p_destino, desapilar(p_origen));
    }
}

/*3. Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden. */

void conservarOrden(Pila *desordenada, Pila*ordenada)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(desordenada))
    {
        apilar(&aux, desapilar(desordenada));
    }

    while(!pilavacia(&aux))
    {
        apilar(ordenada, desapilar(&aux));
    }
}

/*4. Hacer una función que encuentre el menor elemento de una pila y lo retorna.
La misma debe eliminar ese dato de la pila.*/

int devolverMenor (Pila *pilita)
{
    int menor;
    Pila aux;
    inicpila(&aux);

    menor = tope(pilita);
    desapilar(pilita);

    while(!pilavacia(pilita))
    {
        if (menor>tope(pilita))
        {
            apilar(&aux, menor);
            menor = desapilar(pilita);
        }
        else
        {
            apilar(&aux, desapilar(pilita));
        }

    }

    while(!pilavacia(&aux))
    {
        apilar(pilita, desapilar(&aux));
    }

    return menor;
}

/*5. Hacer una función que pase los elementos de una pila a otra,
de manera que se genere una nueva pila ordenada.
Usar la función del ejercicio 4. (Ordenamiento por selección)*/

void ordenarPorSeleccion (Pila *desordenada, Pila *ordenada)
{
    int menor;

    while(!pilavacia(desordenada))
    {
        menor = devolverMenor(desordenada);
        apilar(ordenada, menor);
    }
}

/*6. Hacer una función que inserta en una pila ordenada un nuevo elemento,
 conservando el orden de ésta. */

void agregarUnElemento (Pila *pilita, int elemento)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(pilita))
    {
        if (tope(pilita)>elemento)
        {
            apilar(&aux, desapilar(pilita));
        }
        else
        {
            apilar(pilita, elemento);
            break; //el problema de hacerlo asi esta en que apilas el valor que vos queres almacenar pero no sucede nada mas para terminar el bucle, entonces se sobreescribe constrantemente.
        }
    }

    while(!pilavacia(&aux))
    {
        apilar(pilita, desapilar(&aux));
    }

}

void agregarUnElemento2 (Pila *pilita, int elemento)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(pilita) && (tope(pilita)>elemento))
    {
        apilar(&aux, desapilar(pilita));
    }

    apilar(pilita, elemento);

    while(!pilavacia(&aux))
    {
        apilar(pilita, desapilar(&aux));
    }
}

/*7. Hacer una función que pase los elementos de una pila a otra,
de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 6.
 (Ordenamiento por inserción)*/

void ordenamientoXinsercion(Pila* desordenada, Pila*ordenada)
{
    while(!pilavacia(desordenada))
    {
        agregarUnElemento2(ordenada, desapilar(desordenada));
    }
}

/*8. Hacer una función que sume los dos primeros elementos de una pila (tope y anterior),
 y retorne la suma,  sin alterar el contenido de la pila. */
int sumaDeTopes (Pila *pilita)
{
    int rta= desapilar(pilita);
    rta = rta+desapilar(pilita);
    return rta;
}

/*9. Hacer una función que calcule el promedio de los elementos de una pila,
para ello hacer también una función que calcule la suma, otra para la cuenta
y otra que divida. En total son cuatro funciones, y la función que calcula
el promedio invoca a las otras 3. */



/*10. Hacer una función que reciba una pila con números de un solo dígito
(es responsabilidad de quien usa el programa)
y que transforme esos dígitos en un número decimal. */

int trasnformarAdigitos(Pila *pilita)
{
    int decimal =0;
    Pila aux;
    inicpila(&aux);

    while (!pilavacia(pilita))
    {
        apilar(&aux, desapilar(pilita));
    }

    while(!pilavacia(&aux))
    {
        decimal = (decimal*10)+ tope(&aux) ;
        apilar(pilita, desapilar(&aux));
    }

    return decimal;
}

/*Extra: funcion mostrar*/
void mostrarUnaPila (Pila *pilita)
{
    Pila aux;
    inicpila(&aux);

    printf("Base-------------tope\n");
    while(!pilavacia(pilita))
    {
        apilar(&aux, desapilar(pilita));
    }
    while (!pilavacia(&aux))
    {
        printf("! %i !", desapilar(&aux));
    }
    printf("\nBase-------------tope\n");
}


