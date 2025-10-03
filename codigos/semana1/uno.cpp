#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long entradas;
    cin >> entradas;
    string resultado = "";
    
    for (int i = 0; i < entradas;i++){

        long long n;
        cin >> n;
        
        long double casa = sqrt(((n*n)+n)/2);
        
        if (ceil(casa) == casa){
            resultado += to_string((long long)casa) + "\n";
        }
        else{
            resultado += "NO\n";
        }


    }
    cout << resultado;

    return 0;
}
