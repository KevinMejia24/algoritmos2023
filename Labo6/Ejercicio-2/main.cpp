#include <iostream>

using namespace std;


//Algoritmo Problema de la Mochila (Knapsack Problem)


// Definir INF como un valor grande para representar "infinito" o no alcanzable.
const int INF = 1000000;

// Función para calcular el mínimo número de actores para gastar todo el presupuesto.
int minActors(int budget, int salaries[], int N) {
    // Inicializar el arreglo dp con el valor INF.
    int dp[budget + 1];
    for (int i = 0; i <= budget; i++) {
        dp[i] = INF;
    }

    // El número mínimo de actores para gastar 0 es 0.
    dp[0] = 0;

    // Iterar sobre cada actor.
    for (int i = 0; i < N; ++i) {
        // Actualizar dp para cada posible presupuesto.
        for (int j = budget; j >= salaries[i]; --j) {
            if (dp[j - salaries[i]] != INF) {
                // Usar una condición en lugar de std::min
                if (dp[j - salaries[i]] + 1 < dp[j]) {
                    dp[j] = dp[j - salaries[i]] + 1;
                }
            }
        }
    }

    // Devuelve el número mínimo de actores para gastar todo el presupuesto.
    return dp[budget];
}

int main() {
    int B, N;

    // Leer el presupuesto y el número de actores hasta que ambos sean 0.
    while (true) {
        cout << "\nIngrese el presupuesto total y el numero de actores (0 0 para salir): ";
        cin >> B >> N;

        if (B == 0 && N == 0) {
            cout << "\n\nSaliendo del programa..." << endl;
            break; // Terminar si ambos B y N son 0
        }

        int salaries[N];

        // Leer los salarios de los actores.
        cout << "\nIngrese los salarios de los " << N << " actores (separados por espacios): ";
        for (int i = 0; i < N; ++i) {
            cin >> salaries[i];
        }

        // Calcular y mostrar el resultado.
        int result = minActors(B, salaries, N);
        if (result == INF) {
            cout << "\nNo es posible gastar todo el presupuesto." << endl;
        } else {
            cout << "\nEl minimo numero de actores necesario es: " << result << endl;
        }
        cout << "------------------------------------------------------------------------------------------------------------";
    }

    return 0;
}
