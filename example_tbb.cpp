#include <iostream>
#include <tbb/parallel_for.h>
#include <atomic>

int main() {
    int n = 100;
    std::atomic<int> sum(0);  // variable atómica para evitar condiciones de carrera

    // parallel_for que ejecuta la lambda para cada valor i en [1, n]
    tbb::parallel_for(1, n + 1, [&](int i) {
        sum.fetch_add(i, std::memory_order_relaxed); // suma atómica sin bloqueo

        // Para mostrar qué hilo ejecuta qué iteración (no siempre determinístico)
        // En TBB no hay un ID de hilo directo, pero podemos imprimir algo simple
        std::cout << "Procesando i = " << i << std::endl;
    });

    std::cout << "La suma de 1 a " << n << " es: " << sum.load() << std::endl;
    return 0;
}
