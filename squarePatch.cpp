#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > squarePatch(int n) {
    vector< vector<int> > f;
    vector<int> p;
    p.assign(n, n);
    f.assign(n, p);
    return f;
}

int main() {
    int n;
    cout << "n : ";
    cin >> n;
    vector< vector<int> > in = squarePatch(n);
    for (int i = 0; i < in.size(); i ++) {
        for (int j = 0, k = in.at(i).size(); j < k; j ++) {
            cout << in.at(i).at(j) << " ";
            if (j + 1 == k) cout << endl;
        }
    }
    return 0;
}
