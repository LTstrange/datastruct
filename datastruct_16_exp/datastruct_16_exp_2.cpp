#include <iostream>
#include <vector>
#include <time.h>
#include <random>

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

void bubbleSort(vector<int> list, bool print_or_not) {
    int tmp;
    for (int i = 0; i < list.size() - 1; ++i) {
        for (int j = 0; j < list.size() - i - 1; ++j) {
            if (list[j] > list[j + 1]) {
                tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
            }
        }
    }
    if (print_or_not) {
        for (int k = 0; k < list.size(); ++k) {
            cout << list[k] << ' ';
        }
        cout << endl;
    }
}

void shakerSort(vector<int> list, bool print_or_not) {
    int left = 0, right = list.size() - 1, shift = 1;
    int tmp;
    while (left < right) {
        for (int i = left; i < right; ++i) {
            if (list[i] > list[i + 1]) {
                tmp = list[i];
                list[i] = list[i + 1];
                list[i + 1] = tmp;
                shift = i;
            }
        }
        right = shift;
        for (int j = right - 1; j >= left; --j) {
            if (list[j] > list[j + 1]) {
                tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
                shift = j + 1;
            }
        }
        left = shift;
    }
    if (print_or_not) {
        for (int k = 0; k < list.size(); ++k) {
            cout << list[k] << ' ';
        }
        cout << endl;
    }
}

void quickSort(vector<int> list, int low, int high, bool print_or_not) {
    if (high <= low) return;
    int i = low;
    int j = high + 1;
    int key = list[low];
    while (true) {
        while (list[++i] < key) {
            if (i == high) {
                break;
            }
        }
        while (list[--j] > key) {
            if (j == low) {
                break;
            }
        }
        if (i >= j) break;
        int tmp = list[i];
        list[i] = list[j];
        list[j] = tmp;
    }
    int tmp = list[low];
    list[low] = list[j];
    list[j] = tmp;
    quickSort(list, low, j - 1, 0);
    quickSort(list, j + 1, high, 0);
    if (print_or_not) {
        for (int k = 0; k < list.size(); ++k) {
            cout << list[k]<<' ';
        }
        cout<<endl;
    }
}

void generator(vector<int> &list, int num = 10000) {
    for (int i = 0; i < num; ++i) {
        list.push_back(rand());
    }
}

int main() {
    vector<int> list;
    int s_time, e_time;
    bool generate = 0;

    if (generate) {
        generator(list);
    } else {
        Input(list);
    }

    s_time = clock();
    bubbleSort(list, !generate);
    e_time = clock();
    cout << "bubbleSort: " << e_time - s_time << " ticks" << endl;

    s_time = clock();
    shakerSort(list, !generate);
    e_time = clock();
    cout << "shakerSort: " << e_time - s_time << " ticks" << endl;

    quickSort(list, 0, list.size()-1, !generate);

    return 0;
}
