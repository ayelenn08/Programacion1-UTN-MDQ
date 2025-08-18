#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void totalVendido (float precioUnitario, int cant, float* total);
void descuento (float *precioProducto, float porcetaje);
void promedioVendidadox1dia (Pila productos, float *promedio);
float totalVendidoPuntero (int *cantidad, float* precioUnidad);
void rotarVariables(int *a, int *b, int *c, int *d, int *e);

int main()
{
    //1)
    /*float precioTotal=0;

    totalVendido(250.15, 5,&precioTotal);
    printf("La cantidad total es de %.2f", precioTotal);*/

    //2)
    float arroz = 800;
    printf("El precio del producto es de %.2f\n", arroz);

    descuento(&arroz, 10);

    printf("El precio del producto con el descuento aplicado es de %.2f", arroz);


    //3)
    /*float promedio = 0;
    Pila nuevaPila;
    inicpila(&nuevaPila);

    apilar(&nuevaPila, 5);
    apilar(&nuevaPila, 47);
    apilar(&nuevaPila, 50);
    apilar(&nuevaPila, 59);

    promedioVendidadox1dia(nuevaPila, &promedio);
    printf("El promedio del dia es %.2f", promedio);*/

    //4)
    /*int cantidad;
    float precioUnidad;
    float total = totalVendidoPuntero(&cantidad, &precioUnidad);

    printf("Cantidad: %i\nPrecio Unidad: %.2f\nPrecio total: %.2f\n", cantidad, precioUnidad, total);*/

    //5)
    int a=1, b=2, c=3, d=4, e=5;
    printf("Antes: A=%d B=%d C=%d D=%d E=%d\n", a,b,c,d,e);
    rotarVariables(&a,&b,&c,&d,&e);
    printf("Despues: A=%d B=%d C=%d D=%d E=%d\n", a,b,c,d,e);


    return 0;
}

/*1. Crear una función que reciba:
○ El precio unitario.
○ La cantidad vendida.
○ Y devuelva el total vendido para ese producto mediante el uso de un puntero.
*/

void totalVendido (float precioUnitario, int cant, float* total)
{
    *total = precioUnitario*cant;
}

/*2. Crear una función que reciba el puntero a el precio de un producto y un porcentaje
de descuento. Debe modificar la variable del puntero para restarle el descuento
apropiado.*/

void descuento (float *precioProducto, float porcentaje)
{
    *precioProducto = (*precioProducto) - ( (*precioProducto) * (porcentaje / 100));
}

/*3. Crear una función que reciba una pila cargada con 5 elementos, cada uno
representando la cantidad de productos vendidos en un determinado dia. Debe
calcular el promedio y retornarlo mediante el uso de punteros.*/

void promedioVendidadox1dia (Pila productos, float *promedio)
{
    Pila aux;
    inicpila(&aux);

    int contador = 0;
    float suma = 0;

    while(!pilavacia(&productos))
    {
        suma=suma + tope(&productos);
        contador++;

        apilar(&aux, desapilar(&productos));
    }

    *promedio = suma/contador;

}

/*4. Crear una función que solicite al vendedor cargar la cantidad de unidades vendidas y
el precio. Debe cargar ambas a variables recibidas como puntero. Una vez realizado
esto, debe llamar a la primera función para calcular el total de la venta y devolverlo
al main, utilizando la palabra clave return
-Clave: A la primera función debemos pasarle un puntero, pero al main
debemos devolver el dato, no el puntero.
*/

float totalVendidoPuntero (int *cantidad, float* precioUnidad)
{
    printf("Ingrese la cantidad vendida\n");
    scanf("%i", cantidad);

    printf("Ingrese el precio del producto\n");
    scanf("%f", precioUnidad);

    float cantidadVendida =0;

    totalVendido(*precioUnidad, *cantidad, &cantidadVendida);

    return cantidadVendida;
}

/*5. Crear una función que reciba el puntero a 5 variables de tipo entero (a, b, c, d, e).
Debe intercambiar los valores de las variables de manera que A pase a ser B, B
pase a ser C, C pase a ser D, D pase a ser E y E pase a ser A.
○ Asegurarse de que no se pierda ningún dato.*/

void rotarVariables(int *a, int *b, int *c, int *d, int *e) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = *d;
    *d = *e;
    *e = temp;
}

