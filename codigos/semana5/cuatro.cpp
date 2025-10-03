#include <bits/stdc++.h>
using namespace std;

static inline int dayBase(const string& d) {
    if (d == "sabado") return 0;          // [0, 1440)
    if (d == "domingo") return 1440;      // [1440, 2880)
    if (d == "lunes")   return 2880;      // [2880, 4320)
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C; 
    if (!(cin >> C)) return 0;

    // Ventanas locales por día (en minutos, relativos al día)
    const int START_LOCAL = 6 * 60;       // 06:00
    const int END_LOCAL   = 24 * 60;      // 24:00
    // Para “lunes hasta mediodía”, usar: const int MONDAY_END_LOCAL = 720;
    const int MONDAY_END_LOCAL = 1440;    // 24:00 por defecto

    while (C--) {
        int F; 
        cin >> F;

        vector<pair<int,int>> intervals; // (end, start)

        for (int i = 0; i < F; ++i) {
            string dia; 
            int hh, mm, dur;
            char colon;
            cin >> dia >> hh >> colon >> mm >> dur; 
            if (dur <= 0) continue; // minimo 1 minuto

            int base = dayBase(dia);
            if (base < 0) continue; 

            // Inicio/fin locales dentro del día
            int startLocal = hh * 60 + mm;
            int endLimitLocal = END_LOCAL;
            if (dia == "lunes") endLimitLocal = MONDAY_END_LOCAL;

            if (startLocal < START_LOCAL) continue;
            if (startLocal + dur > endLimitLocal) continue;

            int start = base + startLocal;
            int end   = start + dur;
            intervals.emplace_back(end, start);
        }

        // greedy más temprano
        sort(intervals.begin(), intervals.end());
        int taken = 0;
        int last_end = -1;

        for (auto &iv : intervals) {
            int end = iv.first, start = iv.second;
            if (start >= last_end) {
                ++taken;
                last_end = end;
            }
        }

        cout << taken << "\n";
    }
    return 0;
}
