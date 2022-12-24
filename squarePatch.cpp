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
    int n = 3;
    vector< vector<int> > g = {
        {3, 3, 3}, 
		{3, 3, 3}, 
		{3, 3, 3}
    }, in = squarePatch(3);
    if (in == g) cout << "true" << endl;
    else cout << "fake" << endl;
    return 0;
}