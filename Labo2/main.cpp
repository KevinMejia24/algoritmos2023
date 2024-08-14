#include <iostream> 
#include "./reader.hpp" 
#include "./heapsort.hpp" 
  
  
using namespace std; 
  
int main() { 
  
    /* SECCION PARA EL HEAPSORT */ 
    //variables para el heapsort 
    const int Rows = 1000; 
    Client data[Rows]; 
    load_data(data, Rows); 
    MinHeap minHeap; 
    //Datos desordenados
    cout<<"---------------DATOS DESORDENADOS------------"<<endl; 
    for (int i = 0; i < Rows; i++) { 
        cout << "income: " << data[i].income; 
        cout << " name: " << data[i].name;
        cout << " address: " << data[i].address;
        cout << " job: " << data[i].job << endl;
    } 

    //Datos con MinHeap
    minHeap.BuildMinHeap(data,Rows);

    cout<<"---------------DATOS BUILDMINHEAP------------"<<endl<<endl; 
    for (int i = 0; i < Rows; i++) { 
        cout << "income: " << data[i].income; 
        cout << " name: " << data[i].name;
        cout << " address: " << data[i].address;
        cout << " job: " << data[i].job << endl;
    } 

    //la data lo metemos al heapsort para ordenarlos 
    //llamamos la clase de MinHeap y utilizamos los metodos 
    minHeap.Heapsort(data,Rows); 
  
    // mostrando los vuelos ordenados 
    cout<<"---------------DATOS ORDENADOS------------"<<endl<<endl; 
    for (int i = 0; i < Rows; i++) { 
        cout << "income: " << data[i].income; 
        cout << " name: " << data[i].name;
        cout << " address: " << data[i].address;
        cout << " job: " << data[i].job << endl;
    } 
    return 0; 
}