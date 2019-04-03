#include <iostream>
using namespace std;

//int* getNext(char strKey[]){
//    int next[strkey.size] = new int[strkey.length];
//
//    int j = 0;
//    int k = -1;
//    next[0] = -1;
//
//    while(j<strkey.length-1){
//        if (k == -1 || strkey[j] == strkey[k]){
//            next[++j] = ++k;
//        } else {
//            k = next[k];
//        }
//    }
//    return next;
//}

int main(){
    char str[101];
    for (int i=0; i<3; i++){
        cin.getline(str, 101);
        char* j = str;
        char longstr[100], substr[100];
        int count=0;
        bool notsub=1;
        while (*j != '\0'){
            if (*j == ' '){
                longstr[count] = '\0';
                notsub = 0;
                count = 0;
            } else if (notsub){
                longstr[count] = *j;
                count++;
            } else {
                substr[count] = *j;
                count++;
            }
            j++;
        }
        substr[count] = '\0';
        cout<<longstr<<' '<<substr<<' '<<count<<endl;
    }
    return 0;
}
