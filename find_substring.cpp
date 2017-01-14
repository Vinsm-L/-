#include <iostream>       
using namespace std;
int n, m;

void get_next(int* next, int* A, int* B) {
    next[1] = 0;
    int j = 0;
    for(int i = 2; i <= m; ++i) {
        while (j > 0 && B[j+1] != B[i]) {
            j = next[j];
        }
        if (B[j+1] == B[i]) {
            j = j+1;
        }
        next[i] = j;
    }
}

void kmp(int* next, int* A, int* B) {
    int j = 0;
    for(int i = 1; i <= n; ++i) {
        while (j > 0 && B[j+1] != A[i]) {
            j = next[j];
        }
        if (B[j+1] == A[i]) {
            j = j+1;
        }
        if (j == m) {
            cout << i-m << endl;
            return;
        }
    }
    cout << "no solution" << endl;
}

int main() {
    int A[1000000], B[80000];   
    int next[80000];    
    while(cin >> m) {
        for(int i = 1;i <= m; ++i) {
            cin >> B[i];
        }
        cin >> n;
        for(int i = 1;i <= n; ++i) {
            cin >> A[i];
        }
        get_next(next, A, B);
        kmp(next, A, B);
    }
    return 0;
}