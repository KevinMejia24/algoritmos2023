#include <iostream>

using namespace std;


//Algoritmo "Max 1D Range Sum" (Máxima Suma en un Rango 1D),

// Función para calcular la cantidad mínima de fresas en una fila continua.
int minStrawberries(int jars[], int N) {
    int minSum = 0, currentSum = 0;

    // Recorrer todos los tarros.
    for (int i = 0; i < N; i++) {
        // Actualizar la suma actual agregando el valor del tarro actual.
        currentSum += jars[i];

        // Si la suma actual es menor que la suma mínima, actualizar la suma mínima.
        if (currentSum < minSum) {
            minSum = currentSum;
        }

        // Si la suma actual es positiva, reiniciarla.
        if (currentSum > 0) {
            currentSum = 0;
        }
    }

    return minSum;
}

int main() {
    int T, N;

    // Leer el número de casos de prueba.
    cout << "\nIngrese el numero de casos de prueba: ";
    cin >> T;

    while (T--) {
        cout << "------------------------------------------------------------------------------------------------------------";
        cout << "\nIngrese el numero de tarros de mermelada: ";
        cin >> N;

        int jars[N];

        cout << "Ingrese las diferencias de fresa en cada tarro (separadas por espacios): ";
        for (int i = 0; i < N; ++i) {
            cin >> jars[i];
        }

        // Calcular y mostrar el resultado.
        int result = minStrawberries(jars, N);
        cout << "\n\nCantidad minima de fresas en una fila continua: " << result << endl << endl;
    }

    return 0;
}
