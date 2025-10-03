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

    // se añade una bebida por cada valor_tapa que sume 1000
    while (c--) {
        long total_bebidas = 0;
        string linea;
        getline(cin, linea);
        int k = stoi(linea);

        vector<int> valorTapas;
        for (int i = 0; i < k; i++) {
            getline(cin, linea);
            valorTapas.push_back(stoi(linea));
        }
        // algoritmo voraz
        sort(valorTapas.begin(), valorTapas.end());
        int left = 0;
        int right = k - 1;
        while (left < right) {
            int suma = valorTapas[left] + valorTapas[right];
            if (suma >= 1000) {
                total_bebidas++;
                left++;
                right--;
            } 
            else if (suma < 1000) {
                left++;
            } 
            else {
                right--;
                }
        }
        cout << total_bebidas << "\n";
 
    } 
    return 0;
}