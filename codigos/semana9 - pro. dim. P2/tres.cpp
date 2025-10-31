#include <bits/stdc++.h>
#include <algorithm>  
#include <climits>    
using namespace std;

vector<string> split_ll(const string& s, char delim) {
    vector<string> out;
    stringstream ss(s);
    string t;
    while (getline(ss, t, delim)) {
        if (!t.empty()) out.push_back(t);
    }
    return out;
}

long long mayorDistanciaRutaMasCorta(const vector<vector<int>>& matriz) {
    const long long INF = (long long)4e18;
    int n = (int)matriz.size();

    vector<vector<long long>> dist(n, vector<long long>(n, INF));
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (matriz[i][j] > 0) dist[i][j] = matriz[i][j]; // arista directa
        }
    }

    // floyd–warshall
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (dist[i][k] == INF) continue;
            for (int j = 0; j < n; ++j) {
                if (dist[k][j] == INF) continue; 
                long long through = dist[i][k] + dist[k][j];
                if (through < dist[i][j]) dist[i][j] = through;
            }
        }
    }

    long long ans = 0; // al menos un par conectado
    bool found = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (dist[i][j] != INF) {
                if (!found) { ans = dist[i][j]; found = true; }
                else if (dist[i][j] > ans) ans = dist[i][j];
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int c;
        cin >> c;
        cin.ignore();
        if (c == 0) break;

        // matrz cuadrada

        vector<vector<int>> matriz;


        for (int caso = 0; caso < c; caso++) {
            string line;
            getline(cin, line);
            vector<string> nums = split_ll(line, ' ');
            vector<int> fila;
            for (const string& num_str : nums) {
                if (num_str == "-"){
                    fila.push_back(-10000);

                }
                else{
                    fila.push_back(stoi(num_str));

                }
                
            }
            matriz.push_back(fila);

        }
        cout << mayorDistanciaRutaMasCorta(matriz) << endl;

    }
    return 0;
}
