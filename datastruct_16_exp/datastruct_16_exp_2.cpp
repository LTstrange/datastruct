#include <iostream>
#include <vector>
#include <ctime>
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
    for (unsigned int i = 0; i < list.size() - 1; ++i) {
        for (unsigned int j = 0; j < list.size() - i - 1; ++j) {
            if (list[j] > list[j + 1]) {
                tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
            }
        }
    }
    if (print_or_not) {
        for (unsigned int k = 0; k < list.size(); ++k) {
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
        for (unsigned int k = 0; k < list.size(); ++k) {
            cout << list[k] << ' ';
        }
        cout << endl;
    }
}

vector<int> quickSort(vector<int> list, bool print_or_not) {
    if (list.size() <= 1) {
        return list;
    }
    int mid = list.front();
    vector<int> leftList, rightList;
    for (unsigned int i = 1; i < list.size(); ++i) {
        if (list[i] <= mid) {
            leftList.push_back(list[i]);
        } else {
            rightList.push_back(list[i]);
        }
    }
    leftList = quickSort(leftList, false);
    rightList = quickSort(rightList, false);

    leftList.push_back(mid);
    for (unsigned int i = 0; i < rightList.size(); ++i) {
        leftList.push_back(rightList[i]);
    }


    if (print_or_not) {
        for (unsigned int k = 0; k < leftList.size(); ++k) {
            cout << leftList[k] << ' ';
        }
        cout << endl;
        return leftList;
    } else{
        return leftList;
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
    bool generate = true;

    if (generate) {
        generator(list);
    } else {
        Input(list);
    }

    s_time = clock();
    bubbleSort(list, !generate);
    e_time = clock();
    cout << "bubbleSort:\t" << e_time - s_time << " ticks" << endl;

    s_time = clock();
    shakerSort(list, !generate);
    e_time = clock();
    cout << "shakerSort:\t" << e_time - s_time << " ticks" << endl;

    s_time = clock();
    quickSort(list, !generate);
    e_time = clock();
    cout << "quickSort:\t" << e_time - s_time << " ticks" << endl;

    return 0;
}
