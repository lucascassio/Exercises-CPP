#include <iostream>
#include <vector>

using namespace std;

void matrixMultiplier(vector<vector<int>> mA, vector<vector<int>> mB, int l1, int l2, int c2) {
    vector<vector<int>> mC(l1, vector<int>(c2));
    for(int i=0;i<l1;i++) {
        for(int j=0;j<c2;j++) {
            for(int k=0;k<l2;k++) {
                mC[i][j] += mA[i][k] * mB[k][j];
            }
        }
    }
    for(int i=0; i<l1; i++) {
        for(int j=0; j<c2; j++) {
            cout << mC[i][j] << " ";
        }
            cout << endl;
    }
}

int main() {
    int l1, l2, c2;
    cin >> l1 >> l2 >> c2;
    vector<vector<int>> mA(l1, vector<int>(l2));
    vector<vector<int>> mB(l2, vector<int>(c2));

    for(int i=0; i<l1; i++) {
        for(int j=0; j<l2; j++){
            cin >> mA[i][j];
        }
    }

    for(int i=0; i<l2; i++) {
        for(int j=0; j<c2; j++){
            cin >> mB[i][j];
        }
    }

    matrixMultiplier(mA, mB, l1, l2, c2);

    return 0;
}