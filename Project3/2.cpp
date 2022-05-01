#include <iostream>
#include <vector>
using namespace std;

void merge2(int low, int mid, int high, vector<int>& S, int& count) {
    count++;
    int i = low, j = mid + 1, k = 0;
    vector<int> U(high - low + 1);

    while (i <= mid && j <= high) {
        U[k++] = (S[i] < S[j]) ? S[i++] : S[j++];
    }

    if (i > mid) {
        while (j <= high) {
            U[k++] = S[j++];
        }
    }
    else {
        while (i <= mid) {
            U[k++] = S[i++];
        }
    }

    for (int t = low; t <= high; t++) {
        S[t] = U[t - low];
    }
}

void mergesort2(int low, int high, vector<int>& S, int& count) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort2(low, mid, S, count);
        mergesort2(mid + 1, high, S, count);
        merge2(low, mid, high, S, count);
    }
}

int main() {
    int n;
    cin >> n;
    int count=0;
    vector<int> S(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }

    mergesort2(1, n, S, count);

    cout << count << endl;
    for (int i = 1; i <= n; i++) {
        cout << S[i] << " ";
    }
}
