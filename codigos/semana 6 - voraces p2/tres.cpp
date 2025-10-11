#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int k;
        if (!(cin >> k)) return 0;
        if (k == 0) break;

        vector<long long> heap;
        heap.reserve(k);
        auto cmp = greater<long long>(); // comparator para monticulo

        for (int i = 0; i < k; ++i) {
            long long x;
            cin >> x;
            heap.push_back(x);
            push_heap(heap.begin(), heap.end(), cmp); 
        }

        long long sum = 0;
        while (heap.size() > 1) {
            pop_heap(heap.begin(), heap.end(), cmp); // mueve minimo al final
            long long a = heap.back(); heap.pop_back();
            pop_heap(heap.begin(), heap.end(), cmp);
            long long b = heap.back(); heap.pop_back();

            sum += a + b;
            heap.push_back(a + b);
            push_heap(heap.begin(), heap.end(), cmp);
        }

        cout << sum << "\n";
    }

    return 0;
}