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
    if (!(cin >> c)) return 0;
    cin.ignore();

    while (c--) {
        int k;
        cin >> k;
        cin.ignore();

        vector<pair<long long, long long>> vp;
        vp.reserve(k);

        for (int i = 0; i < k; ++i) {
            string s;
            getline(cin, s);
            auto v = split_ll(s, ' ');
            // v[0] = t_i, v[1] = p_i
            vp.push_back({v[0], v[1]});
        }

        // ordenar por segundo elemento 
        sort(vp.begin(), vp.end(),
            [](const pair<long long,long long>& a, const pair<long long,long long>& b){
                return a.second > b.second;  
            });

        set<int> slots;
        for (int i = 0; i < k; ++i) slots.insert(i * 10);

        long long suma = 0;

        for (const auto& p : vp) {
            bool pataleta = true;
            long long n = p.first; // hora deseada

            while (n >= 0) {
                auto it = slots.find((int)n);
                if (it != slots.end()) {
                    slots.erase(it);
                    pataleta = false;
                    break;
                }
                n -= 10;
            }

            if (pataleta) {
                suma += p.second;
                if (!slots.empty()) {
                    auto it = prev(slots.end()); 
                    slots.erase(it);
                }
            }
        }

        cout << suma << "\n";
    }

    return 0;
}
