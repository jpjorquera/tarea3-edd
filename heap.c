#include <stdio.h>
#include <stdlib.h>

typedef struct {
	unsigned int *values;
	unsigned short size;
} HeapMin;
void inicializar(HeapMin *heap, unsigned short tam){
	heap = (HeapMin *)malloc(sizeof(HeapMin));
	heap->values = (unsigned int *)malloc(sizeof(unsigned int)*tam);
	heap->size = tam;
}

void flotar(HeapMin *heap, unsigned short pos_hijo){
	if (pos_hijo == 0){
		return;
	}
	unsigned short padre;
	if (pos_hijo % 2 == 0){
		padre = pos_hijo/2;
	}
	else {
		padre = (pos_hijo-1)/2;
	}
	if (heap->values[pos_hijo] < heap->values[padre]){
		unsigned int aux = heap->values[pos_hijo];
		heap->values[pos_hijo] = heap->values[padre];
		heap->values[padre] = aux;
		flotar(heap, padre);
	}
}

void insertHeap(HeapMin *heap, unsigned int value){
	unsigned short i = 0;
	while (heap->values[i++] != 0);
	heap->values[i] = value;
	flotar(heap, i);
}

int main (){
	unsigned short tam_arbitrario = 5;

	HeapMin *colap;
	inicializar(colap, tam_arbitrario);

	int tam = 7;
	unsigned int prueba[tam] = {5, 7, 1, 100, 59, 6, 2};
	int i = 0;
	while (i<10){
		insertHeap(colap, prueba[i]);
		i++;
	}
	return 1;
}