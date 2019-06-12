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

void Output(vector<int> list) {
    for (unsigned int i = 0; i < list.size(); ++i) {
        cout << list[i] << ' ';
    }
    cout << endl;
}

void sift(vector<int> &list, int k, int m) {
    int x = k;
    int tmp, p = x;
    while (2 * x + 1 <= m || 2 * x + 2 <= m) {
        if (2 * x + 1 <= m) {
            p = 2 * x + 1;
        }
        if (p + 1 <= m && (list[p + 1] > list[p])) {
            p += 1;
        }
        if (list[p] > list[x]) {
            tmp = list[p];
            list[p] = list[x];
            list[x] = tmp;
        }
        x = p;
    }
}

void heapSort(vector<int> &list) {
    int tmp;
    for (int i = (list.size() - 2) / 2; i >= 0; --i) {
        sift(list, i, list.size() - 1);
    }
    for (int j = list.size() - 1; j >= 0; --j) {
        Output(list);
        tmp = list[0];
        list[0] = list[j];
        list[j] = tmp;
        sift(list, 0, j - 1);
    }
}

int main() {
    vector<int> list;
    Input(list);

    heapSort(list);

    return 0;
}
