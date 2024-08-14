#include <iostream> 
#include "./reader.hpp" 
  
using namespace std; 
  
//cambiar a min heap 
class MinHeap { 
    //se cambio a Client para poder leer los datos 
    public: 
        void BuildMinHeap(Client *array, int size); 
        void MinHeapify(Client *array, int i, int size); 
        void Heapsort(Client *arr, int n); 
        int left(int i); 
        int right(int i); 
}; 
  
void MinHeap::BuildMinHeap(Client *array, int size) { 
    for (int i = (size / 2) - 1; i >= 0; i--) 
        MinHeapify(array, i, size); 
    } 
  
void MinHeap::MinHeapify(Client *array, int i, int size) { 
    //lo utilizamos dentro de MInheap
    int l = left(i); 
    int r = right(i); 
    int smallest = i; 
  
    //con esto logro ordenar los datos pata Minimos cambie de > a < 
    //hacemos las comparaciones en las ramas, si lo vemos como arboles, en los ejercicios anteriores era de manera 
    //ascendente, para este caso es descendente, por eso verificamos que los datos sean menores
    if (l < size && array[l].income < array[i].income) 
        //si se cumple, smallest tomara el valor de la izquierda
        smallest = l; 
    if (r < size && array[r].income < array[smallest].income) 
        //si se cumple, smallest tomara el valor de la derecha
        smallest = r; 
    
    if (smallest != i) { 
        //se intercambian los valores
        swap(array[i], array[smallest]); 
        MinHeapify(array, smallest, size); 
    } 
} 
//se cambia los datos del swap de swap(arr, 0, i); a lo que se tiene ahorita  
void MinHeap::Heapsort(Client *arr, int n) { 
    int heap_size = n; 
    BuildMinHeap(arr, heap_size); 
    for (int i = n - 1; i > 0; i--) { 
        swap(arr[i], arr[0]); 
        heap_size--; 
        MinHeapify(arr, 0, heap_size); 
    } 
} 
  
//Acceder a los hijos de un nodo en específico en un árbol binario
int MinHeap::left(int i) { 
    return 2 * i + 1; 
} 
  
int MinHeap::right(int i) { 
    return 2 * i + 2; 
 }