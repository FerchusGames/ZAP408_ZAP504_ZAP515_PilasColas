//parte 1
//equipo de zap408 zap515 zap504
#include <iostream>
#include <string>
#include <stdio.h>
#include <stack>
#include <queue>
#define max 1000 
using namespace std;

int esPrimo(int numero) {
    if (numero == 0 || numero == 1) return 0;
    /*
            El número 4 es un caso especial, pues al dividirlo entre
            2 el resultado es 2, y el ciclo nunca se cumple, indicando que
            el 4 SÍ es primo, pero realmente NO lo es, así que si el número es 4
                          inmediatamente indicamos que no es primo (regresando 0)
            Nota: solo es para el 4, los demás funcionan bien
    */
    if (numero == 4) return 0;
    for (int x = 2; x < numero / 2; x++) {
        // Si es divisible por cualquiera de estos números, no
        // es primo
        if (numero % x == 0) return 0;
    }
    // Si no se pudo dividir por ninguno de los de arriba, sí es primo
    return 1;
}

void mostrarCola(queue<int> cola)
{
    cout << "Esta es la pila: " << endl;
    queue<int> colita = cola;
    while (!colita.empty())
    {
        cout << "\n" << colita.front();
        colita.pop();
    }
    cout << endl << endl;
}

void mostrarPila(stack<int> pila)
{
    cout << "Esta es la cola: " << endl;
    stack<int> pilita = pila;
    while (!pilita.empty())
    {
        cout << "\n" << pilita.top();
        pilita.pop();
    }
    cout << endl << endl;
}


int main()
{	
	system("color 02");//cambio de color(detalle estetico)
	string palabra; // La palabra que se pedirá
	stack<char> stackChars; // Declaramos un stack de la librería estándar

	cout << "Introduce una palabra: " << endl;
	cin >> palabra;

	// Le agrega los chars uno por uno al stack
	int tamanoPalabra = palabra.length();
	for (int i = 0; i < tamanoPalabra; i++)
	{
		stackChars.push(palabra[i]); // Le agrega un char al final del stack
	}
	system("color 7c");//cambio de color(detalle estetico)
	//Esto muestra el último caracter en el stack y procede a hacerle pop para que el penúltimo pase al final
	cout << "Esta es la palabra al reves: " << endl;
	while (!stackChars.empty())
	{
		cout << stackChars.top(); // Muestra el último elemento en el stack
		stackChars.pop(); // Elimna el último elemento en el stack
	}

    // Pasamos al segundo ejercicio

    cout << "Ahora trabajaremos con pilas y colas para ingresar un número a una de ellas" << endl;

    int num = 0;
    stack<int> pila;
    queue<int> cola;

    // Agregando valores a la pila
    pila.push(1);
    pila.push(78);
    pila.push(98);

    mostrarPila(pila);

    // Agregando valores a la cola
    cola.push(30);
    cola.push(20);
    cola.push(10);

    mostrarCola(cola);

    cout << "Si el número es mayor al último elemento en la pila, se guardará en lugar del mismo. Si no lo es, pero es un numero primo, se agregara a una cola" << endl;
    cout << "Ingresa un numero: ";
    cin >> num;

    if (num>pila.top())
    {
        pila.pop();
        pila.push(num);
        mostrarPila(pila);
    }
    else
    {
        if (esPrimo(num))
        {
            cola.pop();
            cola.push(num);
        }
        mostrarCola(cola);
    }
}

