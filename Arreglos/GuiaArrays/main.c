#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int cargarArreglo (int arreglo[]);
void mostrarArreglo (int arreglo[], int validos);
void cargarConPunteros (int array[], int *validos);
int sumarValoresDeUnArray (int arreglo[], int validos);
void pasarDePilaAarreglo (int array [], int validos, Pila *nuevaPila);
int cargarArregloDecimal (float array[]);
void mostrarArregloDeci (float arreglo[], int validos);
float sumarValoresDecimales (float array[], int validos);
int buscarLetra (char arreglo[], char aBuscar, int validos);
int insertarLetra (char array[], char dato, int validos);
int esCapicua (int arre[], int validos);
void invertirDatos(int arre[], int validos);
int tercerArreglo(char ordenado1[], char ordenado2[], char aCopiar[], int validos1, int validos2, int dim);
int generarSumaVector (int arre[], int suma[], int validos, int dim);
char buscarMayor (char B [], int validos2);

int dim = 10;

int main()
{

    int arreglo[dim];
    int validos =0;

    ///1)
    //int validos = cargarArreglo(arreglo);
    //cargarConPunteros(arreglo, &validos);
    //mostrarArreglo(arreglo, validos);

    ///3)
    /*int suma = sumarValoresDeUnArray(arreglo, validos);
    printf("El resultado de la suma es %i", suma);*/

    ///4)
    /*Pila nueva;
    inicpila(&nueva);
    pasarDePilaAarreglo(arreglo, validos, &nueva);
    mostrarArreglo(arreglo, validos);
    mostrar(&nueva);*/

    ///5)
    /*float arregloDeci[dim];
    int validosDeci = cargarArregloDecimal(arregloDeci);
    float rta = sumarValoresDecimales(arregloDeci, validosDeci);
    printf("La suma es de %.1f", rta);
    mostrarArregloDeci(arregloDeci, validosDeci);*/

    ///6
    /*char arregloC[4] = {'h', 'o','l','a'};

    //int validosC = cargarArregloChar(arregloC, 4);

    for(int i=0; i<4; i++)
    {
        printf("%c", arregloC[i]);
    }

    char letra = 'e';
    int flag = buscarLetra(arregloC, letra,4);

    printf("\nFlag = %i", flag);*/

    ///7)
    /*char arregloC[dim];
    int validosC = cargarArregloChar(arregloC,dim);
     validosC= insertarLetra(arregloC, 'a',validosC);

    printf("%s\n", arregloC);
    printf("validos %i", validosC);*/

    ///9)
    /*int arreglo1[5]={1,1,3,2,1};
    int rta = esCapicua(arreglo1,5);
    printf("%i", rta);*/

    ///10)
    /*invertirDatos(arreglo1,5);
    mostrarArreglo(arreglo1,5);*/

    ///12)
    /*char arreglo1[3]={'d','e','f'};
    char arreglo2[3]={'a','b','c'};
    char arreglo3[10];
    int nuevosValis= tercerArreglo(arreglo1, arreglo2,arreglo3, 3,3,10);

    printf("%s", arreglo3);*/

    ///13)

    /*int vectorito[5]={1,5,6,7,8};
    int arre[5];

    int nuevosValis = generarSumaVector(vectorito, arre, 5,5);

    mostrarArreglo(arre,nuevosValis);*/




    return 0;
}

/*1. Hacer una función que reciba como parámetro un arreglo de números enteros y permita que
el usuario ingrese valores al mismo por teclado. La función debe retornar la cantidad de
elementos cargados en el arreglo (o pueden utilizar como puntero válidos).  */

int cargarArreglo (int arreglo[])
{
    int validos=0;
    char seguir = 's';

    while(seguir == 's' && validos<dim)
    {
        printf("Ingrese un valor..\n");
        scanf("%i", &arreglo[validos]);

        validos++;

        printf("Desea cargar otro valor?\n");
        fflush(stdin);
        scanf("%c", &seguir);
    }

    return validos;
}

void cargarConPunteros (int array[], int *validos)
{
    char seguir = 's';

    while(seguir=='s' && *validos<dim)
    {
        printf("Ingresa un valor..\n");
        scanf("%i", &array[*validos]);
        (*validos)++;

        printf("Desea seguir?\n");
        fflush(stdin);
        scanf("%c", &seguir);
    }

}

/*2. Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos)
cargados en él y los muestre por pantalla.  */

void mostrarArreglo (int arreglo[], int validos)
{
    for (int i=0; i<validos; i++)
    {
        printf("[%i]", arreglo[i]);
    }
}

/*3. Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos)
cargados en él y calcule la suma de sus elementos.  */

int sumarValoresDeUnArray (int arreglo[], int validos)
{
    int suma = 0;
    int i=0;

    while(i<validos)
    {
        suma+= arreglo[i];

        i++;
    }
    return suma;
}

/*4. Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos)
cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila.  */

void pasarDePilaAarreglo (int array [], int validos, Pila *nuevaPila)
{
    for (int i=0; i<validos; i++)
    {
        apilar(nuevaPila, array[i]);
    }
}

/*5. Realizar una función que sume los elementos de un arreglo de números reales (float) de
dimensión 100. (se recomienda hacer una función para cargar y otra para mostrar para este
tipo de dato asociado al arreglo)*/

int cargarArregloDecimal (float array[])
{
    int validos=0;
    char seguir='s';

    while(seguir=='s' && validos<dim)
    {
        printf("Ingrese un valor decimal..\n");
        scanf("%f", &array[validos]);
        //printf("%f", array[validos]);

        validos++;

        printf("Desea seguir?");
        fflush(stdin);
        scanf("%c", &seguir);
    }

    return validos;
}


void mostrarArregloDeci (float arreglo[], int validos)
{
    for (int i=0; i<validos; i++)
    {
        printf("[%.1f]", arreglo[i]);
    }
}

float sumarValoresDecimales (float array[], int validos)
{
    float rta=0;

    for(int i=0; i<validos; i++)
    {
        rta += array[i];
    }

    return rta;
}

/*6. Realizar una función que indique si un elemento dado se encuentra en un arreglo de
caracteres.  */
int buscarLetra (char arreglo[], char aBuscar, int validos)
{
    int flag =0;
    int i=0;

    while(i<validos)
    {
        if (aBuscar == arreglo[i])
        {
            flag = 1;
            i++;
        }
        else
        {
            i++;
        }
    }

    return flag;
}


int cargarArregloChar(char arre[], int dimC)
{
    int validos=0;
    char seguir ='s';

    while(seguir=='s' && validos<dimC)
    {
        printf("Ingrese una letra..");
        fflush(stdin);
        scanf("%c", &arre[validos]);

        validos++;

        printf("Desea seguir?");
        fflush(stdin);
        scanf("%c", &seguir);
    }
    return validos;
}

/*7. Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente,
conservando el orden.  */

int insertarLetra (char array[], char dato, int validos)
{
    int ultimo = validos-1; //posiciones.


    while(ultimo>=0 && dato<array[ultimo])
    {
        array[ultimo+1]=array[ultimo];
        ultimo--;
    }

    array[ultimo+1] = dato;

    return validos+1; ///mis nuevos validos
}

/*8. Realizar una función que obtenga el máximo carácter de un arreglo dado. */
char buscarMayor (char B [], int validos2)
{
    char miMayor= B[0];
    int i=1;
    for (i=1; i<validos2; i++)
    {
        if (miMayor < B[i])
        {
            miMayor= B[i];
        }
    }
return miMayor;
}

/*9. Realizar una función que determine si un arreglo es capicúa.  */
int esCapicua (int arre[], int validos)
{
    int flag=0;
    int ultimo= validos-1;
    int i=0;

    while(i<ultimo && flag==0)
    {
        if (arre[i]==arre[ultimo])
        {
            i++;
            ultimo--;
        }
        else
        {
            flag=1;
        }
    }

    return flag;
}

/*10. Realizar una función que invierta los elementos de un arreglo.  (sin utilizar un arreglo auxiliar) */

void invertirDatos(int arre[], int validos)
{
    int ultimo = validos-1;
    int i=0;
    int dato;
    int tope = validos/2; //basta con intercambiar las primeras posiciones con las últimas;
                        //por lo tanto, solo necesitas hacer cambios hasta la mitad del arreglo.

    while(i<tope)
    {
        dato=arre[ultimo];
        arre[ultimo]=arre[i];
        arre[i]=dato;
        i++;
        ultimo--;
    }
}

/*ordenamiento*/
int posicionMenor (int arreglo[], int pos, int validos)
{
    int menor = arreglo[pos];
    int posmenor = pos;
    int i = pos+1;

    while(i<validos)
    {
        if(arreglo[i]<menor)
        {
            menor= arreglo[i];
            posmenor= i;
        }
        i++;
    }

    return posmenor;
}

void ordenamientoPorseleccion (int arreglo[], int validos)
{
    int posmenor;
    int aux;
    int i =0;

    while(i<validos-1)
    {
        posmenor = posicionMenor(arreglo,i,validos);
        aux= arreglo[posmenor];
        arreglo[posmenor] = arreglo[i];
        arreglo[i]=aux;
        i++;
    }
}

//version de Juan
void ordenamientoPorSelecJ (int arre[], int validos)
{
    for (int i=0; i<validos-1; j++)
    {
        int posmenor = i;

        for (int j= i+1; j<validos; j++)
        {
            if (arre[j]<arre[posmenor])
            {
                posmenor = j;
            }
        }

        int aux = arre[posmenor];
        arre[posmenor] = arre[i];
        arre[i]= aux;
    }
}

/*ordamiento por inserccion*/
void ordenarInserccion (int arr[], int validos)
{
    for (int i=0; i<validos; i++)
    {
        int num = arr[i];
        int j = i-1;

        while (j>=0 && arr[j]>num)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = num;
    }
}

void ordenarInsercionconWhile (int arreglo[], int validos)
{
    int i=1;
    while(i<validos)
    {
        //[11][8][12][20]
        //pos 3 = 20
        int num = arreglo[i];
        //pos 1 = 126
        int j = i-1;

        //mueve los elementos mayores que num una posicion adelante
        while (j >= 0 && arreglo[j]>arreglo[i])
        {
            //pos 1+1 = pos 2 guardame 1
            arreglo[j+1] = arreglo[j];
            //0
            j--;
        }

        //pos 0+1 = 8;
        arreglo[j+1]=num;

        //3
        i++;
    }
}

/*12. Dados dos arreglos ordenados alfabéticamente, crear un tercer arreglo con los elementos de
los dos primeros intercalados, de manera que quede un arreglo también ordenado
alfabéticamente.  */

int tercerArreglo(char ordenado1[], char ordenado2[], char aCopiar[], int validos1, int validos2, int dim)
{
    int i1=0;
    int i2=0;
    int i3=0;

    while(i1<validos1 && i2<validos2 && i3<dim)
    {
        if(ordenado1[i1]<ordenado2[i2])
        {
            aCopiar[i3]=ordenado1[i1];
            i1++;
            i3++;
        }else
        {
            aCopiar[i3]=ordenado2[i2];
            i2++;
            i3++;
        }
    }

    while(i1<validos1)
    {
        aCopiar[i3]=ordenado1[i1];

        i1++;
        i3++;
    }

      while(i2<validos2)
    {
        aCopiar[i3]=ordenado2[i2];

        i2++;
        i3++;
    }

    return i3;
}

/*13. Dado el vector {1,5,6,7,8} escribir un programa que genere otro vector con la suma del
contenido de todo los elementos anteriores al índice actual: {1,6,12,19,27}.*/

int generarSumaVector (int arre[], int suma[], int validos, int dim)
{
    int i=0;
    int h=0;
    int valor=0;

    while(i<validos && h<dim)
    {
        valor = valor+arre[i];
        suma[h]=valor;

        i++;
        h++;
    }


    return h;
}

