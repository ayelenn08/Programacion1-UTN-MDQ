#include <stdio.h>
#include <stdlib.h>

///---Prototipados---
int sumarValoresMenores (int numeroAsumar);
void tablaDeMultiplicarDeUnNum(int num);
int suma2numeros (int num1, int num2);
int multiplicacionDe2numeros (int num1, int num2);
int restaDe2numeros (int num1, int num2);
float dividir2numeros (int num1, int num2);
void calculadora ();
void cambiarSigno (int *num);
void cargarValoresXreferencia (int *num1, int *num2);
void valorRandom (int *num);

int main()
{
    ///Ejercicio 3

    int num =0;
    printf("Ingrese un numero: \n");
    scanf("%d", &num);


    int rta = sumarValoresMenores(num);
    printf("La respuesta es %i", rta);

    ///Ejercicio 4

    tablaDeMultiplicarDeUnNum(num);

    ///Ejercicio 5
    calculadora();

    ///Ejercicio 6
    int numerito=3;
    cambiarSigno(&numerito);
    printf("El nuevo num es: %i", numerito);

    ///Ejercicio 7
    int num1, num2;
    cargarValoresXreferencia(&num1, &num2);
    printf("Los valores son %i y %i", num1, num2);

    ///Ejercicio 1 con punnteros
    int numR;
    valorRandom(&numR);
    printf("Valor: %i", numR);
    return 0;
}

/*3- Diseñe una función que reciba un número entero N y realice la suma de los números enteros positivos menores que N
 y lo retorne. N es un  dato ingresado por el usuario en el main.
*/

int sumarValoresMenores (int numeroAsumar)
{
    int rta =0;
    for (int i=0; i<numeroAsumar; i++)
    {
        rta = rta+i;
    }
    return rta;
}


/*4- Desarrollar una función que muestre la tabla de multiplicar de un número entero recibido por parámetro.*/

void tablaDeMultiplicarDeUnNum(int num)
{
    int rta =0;
    for (int i=0; i<=10; i++)
    {
        rta=i*num;
        printf("%ix%i=%i\n", i,num,rta);
    }
}

int suma2numeros (int num1, int num2)
{
    int rta = num1+ num2;
    return rta;
}

int multiplicacionDe2numeros (int num1, int num2)
{
    int rta = num1*num2;
    return rta;
}

int restaDe2numeros (int num1, int num2)
{
    int rta = num1-num2;
    return rta;
}

float dividir2numeros (int num1, int num2)
{
    float rta;
    if (num2==0)
    {
        printf("Error, no es posible dividir por cero.");
    }
    else
    {
        rta = num1/num2;
    }
    return rta;
}
/*5 - Realice una pequeña calculadora, utilizando funciones (una función de suma, una de multiplicación, una de resta, una de división…)*/
void calculadora ()
{
    int opcion = 0;
    int num1=0;
    int num2=0;

    printf("Ingrese la opcion que desea utilizar\n");
    printf("1- Suma\n");
    printf("2- Resta\n");
    printf("3- Multiplicacion\n");
    printf("4- Division\n");

    scanf("%i", &opcion);

    system("cls");

    printf("Ingrese el primer numero:\n");
    scanf("%i", &num1);

    printf("Ingrese el segundo numero:\n");
    scanf("%i", &num2);

    int rst, rst2, rst3 =0;
    float rst4=0;
    switch(opcion)
    {
    case 1:
        rst = suma2numeros(num1, num2);
        printf("El resultado es %i", rst);
        break;
    case 2:
        rst2 = restaDe2numeros(num1, num2);
        printf("El resultado es %i", rst2);
        break;
    case 3:
        rst3 = multiplicacionDe2numeros(num1, num2);
        printf("El resultado es %i", rst3);
        break;
    case 4:
        rst4 = dividir2numeros(num1, num2);
        printf("El resultado es %.2f", rst4);
        break;
    default:
        printf("Opcion invalida");
    }
}
/*6 - Realizar una funcion que reciba un numero positivo entero por parametro por referencia, y cambie su signo a negativo. */
void cambiarSigno (int *num)
{
    if (*num>0)
    {
        *num=*num*(-1);
    }
    else
    {
        printf("El numero ya es negativo");
    }
}

/*7- Realizar una función que reciba dos números enteros por parámetro por referencia
y cargue sus valores el usuario dentro de la función.*/
void cargarValoresXreferencia (int *num1, int *num2)
{
    printf("Ingrese un valor para el 1er numero\n");
    scanf("%i", num1);
    printf("Ingrese un valor para el 2do numero\n");
    scanf("%i", num2);
}

///Mismas funciones pero con punteros
/*1- Desarrollar una función que devuelva un valor RANDOM en el rango de 0 a 100.
*/

void valorRandom (int *num)
{
    srand(time(NULL));
    *num = rand()%10;
}



