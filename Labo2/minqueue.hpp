#include <iostream> 
 #include <limits> 
 #include "./reader.hpp" 
  
 using namespace std; 
 //esta clase practicamente es una copia de lo que se hizo en heapsort.hpp solo con unos pequeños cambios 
 //separe la logica de las 2 clases para que se diferencie una de la otra en base a la tarea que se pidio en el labo 
 class MinQueue{ 
     public: 
         //constructor de la clase 
         MinQueue(int maxSize); 
         void insert(Client &info); //metodo de insertar 
         Client seeMin(); //metodo para ver el minimo 
         Client extractMin(); //metodo para extraer el minimo 
         void reduceKey(int flightNumber, int priority); //metodo de reduccion de la llave (prioridad) 
  
         //se necesita saber si la cola esta vacia o si esta llena 
         bool isEmpty(); 
         bool isFull(); 
  
     //como no quiero que se "sepa" los siguientes metodos se hace privado 
     private: 
         Client *heap; //aqui es donde guardo los elementos 
         int size; //tamaño de la cola 
         int capacity; //capacidad de la cola 
  
         //estos metodos son para el manejo del min heap (basado en lo del labo) 
         //vuelvo a construir el min heap porque se me muere a la hora de trabajar con el heapsort.hpp 
         void buildMinHeap(); 
         void minHeapify(int i); 
         int parent(int i); 
         int left(int i); 
         int right(int i); 
 }; 
  
 //implementacion de mis metodos de la clase 
 MinQueue::MinQueue(int maxSize){ 
     capacity = maxSize; //asignacion de los elementos 
     size = 0; //esto es el numero actual de la cola de prioridad 
     heap = new Client[maxSize]; //arreglo para implementar el min heap de donde se almacenan los elementos de la cola 
     buildMinHeap(); 
 } 
  
 void MinQueue::insert(Client &info){ 
     //validando que la cola no este llena 
     if (isFull()) { 
         cout << " HEAP OVERFLOW: nimodo la cola esta llena" << endl; 
         return; 
     } 
     size++; //incrementando el tamaño de la cola 
     int i = size - 1; //para obtener la posicion del nuevo elemento en el arreglo 
     heap[i] = info; //asignando el valor del elemento nuevo al arreglo 
  
     //bucle para mantener que sea min heap 
     while (i != 0 && heap[parent(i)].income > heap[i].income) { 
         swap(heap[i], heap[parent(i)]); 
         i = parent(i); 
     } 
 } 
 //implementando ver el minimo 
 Client MinQueue::seeMin() { 
     //validacion para que la cola no este vacia 
     if (isEmpty()) { 
         cout << "HEAP UNDERFLOW: nimodo la cola está vacía." << endl; 
         return Client(); // si esto falla, entonces mando el objeto Client 
     } 
     return heap[0]; //sino devuelvo el elemento minimo de la cola 
 } 
 //implementando extraer el minimo 
 Client MinQueue::extractMin() { 
     if (isEmpty()) { 
         cout << "HEAP UNDERFLOW: nimodo la cola está vacía." << endl; 
         return Client(); // si esto falla, entonces mando el objeto Client tambien 
     } 
  
     //si es 1, quiere decir que la cola no esta vacia pero como solo es 1 es porque es el elemento minimo 
     //por lo tanto solamente devuelvo o mejor dicho extraigo ese valor directamente 
     if (size == 1) { 
         size--; 
         return heap[0]; 
     } 
  
     //en este punto es donde la cola tiene mas de 1 elemento 
     Client root = heap[0]; //alamceno el primer elemento en root (variable auxiliar) 
     heap[0] = heap[size - 1]; //reemplazo el primer elemento con el ultimo del arreglo (siguiendo estructura de min heap) 
     size--; //decremento el tamaño de la cola 
     minHeapify(0); //llamo a esta funcion para poder reorganizar el arreglo y mantener la estructura de min 
  
     return root; //retorno el valor, lo que se almacena es el elemento minimo extraido 
 } 
 //implementando reducir la llave 
 void MinQueue::reduceKey(int flightNumber, int priority) { 
     // busco el elemento con flightNumber y actualizo su prioridad 
     int index = -1; //variable para almacenar la posicion de elemento que voy a actualizar 
     for (int i = 0; i < size; i++) { 
         if (heap[i].income == flightNumber) { 
             index = i; 
             break; //hago este break para que se salga del bucle en dado caso se cumpla la condicion de arriba 
         } 
     } 
     //si la variable sigue siendo -1 quiere decir que no se ha encontrado ningun elemento 
     if (index == -1) { 
         cout << "nimodo no hay un elemento Flight Number " << flightNumber << endl; 
         return; 
     } 
  
     //validando que la nueva prioridad sea menor o igual 
     if (priority > heap[index].income) { 
         cout << "calamdo mi rey la nueva prioridad debe ser menor o igual al valor actual" << endl; 
         return; 
     } 
     //actualizo la nueva prioridad 
     heap[index].income = priority; 
  
     //se vuelve a hacer el while para que la estructura de min heap se logre mantener, sino se me muere 
     while (index != 0 && heap[parent(index)].income > heap[index].income) { 
         swap(heap[index], heap[parent(index)]); //cambio al padre de posicion 
         index = parent(index); 
     } 
 } 
  
 //las 2 siguientes son para las validaciones hechas arriba 
 bool MinQueue::isEmpty(){ 
     return size == 0; 
 } 
  
 bool MinQueue::isFull(){ 
     return size == capacity; 
 } 
  
 //para construir el min heap (basado ya de lo que se ha hecho), aqui es practicamente un copia y pega de la clase minHeap 
 void MinQueue::buildMinHeap() { 
     for (int i = (size / 2) - 1; i >= 0; i--) { 
         minHeapify(i); 
     } 
 } 
  
 void MinQueue::minHeapify(int i) { 
     int l = left(i); 
     int r = right(i); 
     int smallest = i; 
  
     if (l < size && heap[l].income < heap[i].income) { 
         smallest = l; 
     } 
  
     if (r < size && heap[r].income < heap[smallest].income) { 
         smallest = r; 
     } 
  
     if (smallest != i) { 
         swap(heap[i], heap[smallest]); 
         minHeapify(smallest); 
     } 
 } 
  
 int MinQueue::parent(int i) { 
     return (i - 1) / 2; 
 } 
  
 int MinQueue::left(int i) { 
     return (2 * i) + 1; 
 } 
  
 int MinQueue::right(int i) { 
     return (2 * i) + 2; 
 }