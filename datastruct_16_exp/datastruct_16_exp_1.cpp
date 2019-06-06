#include <iostream>
#include <vector>

using namespace std;

void Input(vector<int> &list, int len = -1) {
    int t;
    while (len) {
        cin >> t;
        if (t) {
            list.push_back(t);
            len--;
        } else {
            break;
        }
    }
}

void shellInsert(vector<int> &list, int delta) {
    int tmp, j;
    for (unsigned int i = delta; i < list.size(); ++i) {
        if (list[i] < list[i - delta]) {
            tmp = list[i];
            for (j = i - delta; j >= 0 && tmp < list[j]; j -= delta) {
                list[j + delta] = list[j];
            }
            list[j + delta] = tmp;
        }
    }
}

void shellSort(vector<int> list, vector<int> delta) {
    for (unsigned int i=0;i<delta.size();++i) {
        shellInsert(list, delta[i]);
        for (unsigned int j=0;j< list.size();++j) {
            cout << list[j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    vector<int> list;
    vector<int> delta;

    Input(list);
    Input(delta, 3);

    shellSort(list, delta);

    return 0;
}
