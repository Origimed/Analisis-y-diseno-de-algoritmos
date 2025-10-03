#include <bits/stdc++.h>
using namespace std;

vector<long long> split_ll(const string& s, char delim) {
    vector<long long> out;
    stringstream ss(s);
    string t;
    while (getline(ss, t, delim)) {
        if (!t.empty()) out.push_back(stoll(t));
    }
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;
    cin.ignore(); 

    vector<int> monedas = {10000, 5000,1000, 500, 100, 50, 10, 5, 1};

    while (c--) {
        string linea;
        getline(cin, linea);
        long long M = stoll(linea);
        long long totalMonedas = 0;
        // algoritmo voraz
        for (int moneda : monedas) {
            if (M >= moneda){
                totalMonedas += M / moneda;
                M %= moneda;
            };

        }
        cout << totalMonedas << "\n";
        
        
    } 
    return 0;
}