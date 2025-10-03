#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;
    cin.ignore();

    for (int i = 0; i < c; ) {
        string entrada;
        getline(cin, entrada);
        i++;

        long long n = stoll(entrada);

        long long cuadrado = n * n;

        bool esKap = false;

        for (long long p = 10; p <= cuadrado; p *= 10) {
            long long der = cuadrado % p;   
            long long izq = cuadrado / p;   
            if (der != 0 && izq + der == n) {
                esKap = true;
                break;
            }
        }

        cout << (esKap ? "KAP\n" : "NO\n");
    }

    return 0;
}
