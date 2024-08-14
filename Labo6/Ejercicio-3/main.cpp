#include <iostream>

using namespace std;

// Funcion para calcular la cantidad minima de vitaminas necesarias.
int minVitamins(int G, int vitamins[], int V) {
    // Inicializar arreglo para almacenar la cantidad minima de vitaminas para cada valor de velocidad.
    int dp[G + 1];
    for (int i = 0; i <= G; i++) {
        dp[i] = 1000000; // Usar un valor grande para representar "infinito".
    }
    dp[0] = 0; // No se necesitan vitaminas para un aumento de 0.

    // Recorrer todas las vitaminas.
    for (int i = 0; i < V; i++) {
        for (int j = vitamins[i]; j <= G; j++) {
            // Actualizar el valor de dp[j] si es posible alcanzarlo con menos vitaminas.
            dp[j] = min(dp[j], dp[j - vitamins[i]] + 1);
        }
    }

    // Devuelve la cantidad minima de vitaminas para alcanzar G o -1 si no es posible.
    return dp[G] == 1000000 ? -1 : dp[G];
}

int main() {
    int T, G, V;

    // Leer el numero de casos de prueba.
    cout << "Ingrese el numero de casos de prueba: ";
    cin >> T;

    while (T--) {
        cout << "------------------------------------------------------------------------------------------------------------";
        cout << "\nIngrese el limite de aumento de velocidad y el numero de tipos de vitaminas (separados por espacios):";
        cin >> G >> V;

        int vitamins[V];

        cout << "Ingrese el aumento de velocidad de cada vitamina (separados por espacios): ";
        for (int i = 0; i < V; i++) {
            cin >> vitamins[i];
        }

        // Calcular y mostrar el resultado.
        int result = minVitamins(G, vitamins, V);
        if (result == -1) {
            cout << "\nNo es posible alcanzar el limite de velocidad con las vitaminas disponibles." << endl << endl;
        } else {
            cout << "\nCantidad minima de vitaminas necesarias: " << result << endl << endl;
        }
    }

    return 0;
}
