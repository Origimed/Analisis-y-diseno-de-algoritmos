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

    while (true) {
        int k;
        cin >> k;
        cin.ignore();
        if (k == 0) break;

        vector<pair<long long, long long>> eventos;
        eventos.reserve(k);
        for (int i = 0; i < k; ++i) {
            string s;
            getline(cin, s);
            auto v = split_ll(s, ' ');
            eventos.push_back({v[0], v[1]}); // {inicio, fin}
        }

        // ordenar por inicio
        sort(eventos.begin(), eventos.end(),
            [](const pair<long long,long long>& a, const pair<long long,long long>& b){
                return a.first < b.first;  
            });

        multiset<long long> ends;

        for (const auto &ev : eventos) {
            long long inicio = ev.first;
            long long fin = ev.second;
            auto it = ends.upper_bound(inicio); // primer elemento > inicio
            if (it == ends.begin()) {
                // no hay persona libre cuyo fin <= inicio -> nueva persona
                ends.insert(fin);
            } else {
                // reutilizar la persona con mayor fin <= inicio
                --it;
                ends.erase(it);
                ends.insert(fin);
            }
        }

        cout << ends.size() - 1<< "\n";
    }

    return 0;
}
