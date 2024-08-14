#include <iostream> 
 #include "./reader.hpp" 
 #include "./minqueue.hpp"  
  
 using namespace std; 
 //he hecho un main2.cpp porque me daba conflicto a la hora de tener todo en un mismo main 
 int main() { 
  
     //SECCION PARA EL MIN QUEUE 
     const int maxSize = 1000; //lo mismo que rows solo que ahora le doy otro contexto 
     MinQueue minQueue(maxSize); //instanciando mi clase 
  
     //cargando los datos de igual forma que la vez anterior 
     Client data[maxSize]; 
     load_data(data, maxSize); 
  
     // bucle para poder insertar datos en la cola (que son los que provienen del .txt) 
     for (int i = 0; i < maxSize; i++) { 
         minQueue.insert(data[i]); 
         cout << "Se ha insertado el vuelo " << data[i].income << " en la cola" << endl; 
     } 
  
     // extraer y mostrar el elemento mínimo 
     //si se cambia un numero en el .txt y es 1 por ejemplo, mostrara eso 
     Client minElement = minQueue.extractMin(); 
     cout << "El elemento minimo de la cola es el Flight Number: " << minElement.name << endl; 
  
     // reduce la prioridad de un elemento 
     int flightNumberToReduce = 2975; //este es un numero de vuelo que quiero reducir su prioridad 
     int newPriority = 100; //mi prioridad a asignar 
     minQueue.reduceKey(flightNumberToReduce, newPriority); 
  
     // mostrando la reduccion de prioridad del vuelo 
     cout << "Se ha reducido la prioridad del vuelo " << flightNumberToReduce  
     << " a la prioridad de: " << newPriority << endl; 
  
     return 0; 
 }