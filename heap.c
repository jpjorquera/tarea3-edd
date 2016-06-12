#include <stdio.h>
#include <stdlib.h>

typedef struct {				// Struct para almacenar Heap de Minimos
	unsigned int *values;		// Valores a almacenar en el Heap en Array
	unsigned short size;		// Tamano total del Heap (notar que en la primera
} HeapMin;						// posicion se deja siempre un valor vacio)

/*****
* void inicializar
******
* Crea array del espacio necesario segun la cantidad de terminos + 1
******
* Input:
* HeapMin * base : puntero donde se inicializa el Heap
* unsigned short tam : cantidad de valores a introducir
******
* Returns:
* void
*****/
void inicializar(HeapMin *heap, unsigned short tam){
	heap->values = (unsigned int *)calloc(tam+1, sizeof(unsigned int));		// Inicializar valores con 0
	heap->size = 0;
}

/*****
* void flotar
******
* Intercambia posiciones de los valores en el heap flotandolo asegurandose
* de mantener el orden de Heap de Minimos
******
* Input:
* HeapMin * heap : puntero al Heap en el cual se esta trabajando
* unsigned short pos_hijo : posicion actual del valor que se desea flotar
******
* Returns:
* void
*****/
void flotar(HeapMin *heap, unsigned short pos_hijo){
	if (pos_hijo == 1){						// Caso base al llegar a la raiz
		return;
	}
	unsigned short padre;					// Calcular posicion del padre
	if (pos_hijo % 2 == 0){					// dependiendo de si es par o impar
		padre = pos_hijo/2;
	}
	else {
		padre = (pos_hijo-1)/2;
	}
	if (heap->values[pos_hijo] < heap->values[padre]){	// Intercambiar valores
		unsigned int aux = heap->values[pos_hijo];		// del flote
		heap->values[pos_hijo] = heap->values[padre];
		heap->values[padre] = aux;
		flotar(heap, padre);	// Intentar flotar la nueva posicion de ser posible
	}
}

/*****
* void insertHeap
******
* Inserta valor en la primera posicion vacia del Heap, de ser necesario flota este valor
******
* Input:
* HeapMin * heap : puntero que representa el Heap en el que se trabaja
* unsigned int value : valor a insertar en el Heap
******
* Returns:
* void
*****/
void insertHeap(HeapMin *heap, unsigned int value){
	heap->values[++heap->size] = value;				// Actualizar tamano, asignar valor
	flotar(heap, heap->size);						// Intentar flotar de ser necesario en esa posicion

}

/*****
* void freeHeap
******
* Libera memoria usada por el Heap
******
* Input:
* HeapMin * heap : puntero del Heap que se desea liberar
******
* Returns:
* void
*****/
void freeHeap(HeapMin *heap){
	free(heap->values);				// Liberar array de valores
	free(heap);						// Liberar Heap
}

int main (){												// Main de prueba
	unsigned short tam_arbitrario = 8;						// Tamano para el array de valores

	HeapMin *colap = (HeapMin *)malloc(sizeof(HeapMin));	// Creacion Heap
	inicializar(colap, tam_arbitrario);						// Inicializacion

	unsigned int prueba[8] = {5, 7, 4, 100, 59, 2, 6, 1};	// Caso de prueba
	int i = 0;
	while (i<8){
		insertHeap(colap, prueba[i]);						// Insertar en Heap
		i++;
	}

	freeHeap(colap);										// Liberar Heap
	return 1;
}