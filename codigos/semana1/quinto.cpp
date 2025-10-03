#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>


using namespace std;



bool esCapicua(string s) {
    int len = s.length();
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

string invertirString(const string& s) {
    string resultado = s;
    reverse(resultado.begin(), resultado.end());
    return resultado;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {

        string s;
        cin >> s;
        long long iteraciones = 0;
        if (s == "0") break;

        bool limite = false;
        while (!esCapicua(s))
        {
            iteraciones ++;
            string s_invertido = invertirString(s);
            long long suma = stoll(s) + stoll(s_invertido);
            s = to_string(suma);
            if (stoll(s)> 10000000000){
                limite = true;
                break;

            } 
            
        }
        if(limite){
            cout << "L\n";
            continue;  
        }

        cout << iteraciones << "\n";
        
        
  
    }
    

    return 0;
}
