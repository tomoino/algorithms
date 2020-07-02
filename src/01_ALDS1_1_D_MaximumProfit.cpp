#include <iostream>
#include <algorithm>
using namespace std;
static const int N_MAX = 200000;

int main() {
    int n,diffMax = -1e+9,nMin;
    cin >> n;
    int rt[N_MAX];

    for (int i = 0; i < n; i++) {
        cin >> rt[i];
        // この方法だと遅い
        // for (int j = 0; j < i; j++) {
        //     diffMax = rt[i] - rt[j] > diffMax ? rt[i] - rt[j]  : diffMax;
        // }
    }

    nMin = rt[0];
    for (int i = 1; i < n; i++) {
        diffMax = max(diffMax, rt[i] - nMin);
        nMin = min(nMin, rt[i]);
    }

    cout << diffMax << endl;
    return 0;
}