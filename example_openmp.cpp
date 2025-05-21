#include <iostream>
#include <omp.h>

int main() {
    int n = 100;
    int sum = 0;

    // Configurar número de hilos (opcional)
    omp_set_num_threads(4);

    // Paralelizar el bucle for con reducción para evitar condiciones de carrera
    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= n; ++i) {
        // Cada hilo suma su parte de los números
        sum += i;

        // Mostrar qué hilo está ejecutando qué iteración (solo para demostración)
        int thread_id = omp_get_thread_num();
        std::cout << "Hilo " << thread_id << " procesando i = " << i << std::endl;
    }

    std::cout << "La suma de 1 a " << n << " es: " << sum << std::endl;
    return 0;
}
