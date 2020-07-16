#include <iostream>
using namespace std;

static const int N_MAX = 36;
typedef struct {
    // char suit, value;
    int suit, value;
} Card;

void bubbleSort(Card a[], int n)
{
    int flag = 1, cnt = 0;
    while (flag) {
        flag = 0;

        for (int i = n - 1; i > 0; i--)
        {
            if (a[i].value < a[i-1].value) {
                // swap(a[i], a[i - 1]);
                Card t = a[i];
                a[i] = a[i - 1];
                a[i - 1] = t;
                flag = 1;
            }
        }
    }
}

void selectionSort(Card a[], int n) {
    for (int i = 0; i < n; i++)
    {
        int minj = i;
        for (int j = i; j < n; j++) {
            if (a[j].value < a[minj].value) {
                minj = j;
            }
        }
        if (i != minj) {
            swap(a[i], a[minj]);
        }
    }
}

void trace(Card a[], int n) {
    for (int i = 0; i < n-1; i++) {
        cout << a[i].suit << a[i].value << " ";
    }
    cout << a[n-1].suit << a[n-1].value << endl;
}

bool isStable(Card a[], Card a2[], int n) {
    for (int i = 0; i < n; i++)
        if (a[i].suit != a2[i].suit || a[i].value != a2[i].value)
            return false;

    return true;
}

int main() {
    int n;
    Card a[N_MAX], a2[N_MAX];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].suit >> a[i].value;
    }

    for (int i = 0; i < n; i++)
        a[i] = a2[i];

    bubbleSort(a, n);
    selectionSort(a2, n);

    trace(a,n);
    cout << "Stable" << endl;

    trace(a2, n);
    if (isStable(a, a2, n))
    {
        cout << "Stable" << endl;
    }
    else
    {
        cout << "Not stable" << endl;
    }
}