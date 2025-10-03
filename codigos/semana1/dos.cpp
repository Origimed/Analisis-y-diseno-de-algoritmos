#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {

        long long n;
        cin >> n;
        if (n == 0) break;

        int cont = 0;

        for (long long i = 3; i < n; i++) {
            long long izq = ((i * (i + 1) *(2*i + 1))/ 6) - i*i;
            long long der = ((n * (n + 1) *(2*n + 1))/ 6) - (((i * (i + 1) *(2*i + 1))/ 6));

            if(der % izq == 0){
                //cout << i << "\n";
                cont++;
            }
        }

        cout << cont << "\n";   
        
    }
    

    return 0;
}
