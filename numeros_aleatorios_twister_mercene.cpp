#include <iostream>
#include <random>
#include <ctime>

using namespace std;
/*
 * usando os numeros primos de mercene para o algoritimo de
 * twistter mercene para geracao de numeros aleatorios
 * 
 */
int main() {
    mt19937 gen(time(nullptr));

    // Use long long para suportar números maiores
    uniform_int_distribution<long long> distribuicao_numeros(1, 1000000000000LL);
    for (int i = 0; i < 10; i++) {
        cout << distribuicao_numeros(gen) << endl;
    }

    return 0;
}
