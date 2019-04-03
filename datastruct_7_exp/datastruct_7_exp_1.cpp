#include <iostream>
using namespace std;

void input(char str[], int &lcount, int &scount, char longstr[], char substr[]){
    char* p = str;
    bool notsub=1;
    while (*p != '\0'){
        if (*p == ' '){
            longstr[lcount] = '\0';
            notsub = 0;
        } else if (notsub){
            longstr[lcount] = *p;
            lcount++;
        } else {
            substr[scount] = *p;
            scount++;
        }
        p++;
    }
    substr[scount] = '\0';
}


void getNext(int n, char strkey[], int next[]){
    int j = 0;
    int k = -1;
    next[0] = -1;

    while(j<n-1){
        if (k == -1 || strkey[j] == strkey[k]){
            next[++j] = ++k;
        } else {
            k = next[k];
        }
    }
}

void KMP(int lcount, int scount, char longstr[], char substr[]){
    
}


int main(){
    char str[101];
    for (int i=0; i<3; i++){
        cin.getline(str, 101);
        char longstr[100], substr[100];
        int lcount=0, scount=0;

        input(str, lcount, scount, longstr, substr);
        cout<<longstr<<' '<<lcount<<' '<<substr<<' '<<scount<<endl;

        // get next[]
        int next[scount];
        getNext(scount, substr, next);

        // print next[]
        for (int i=0;i<scount;i++){
            cout<<next[i]<<' ';
        }

        // KMP

        int j = 0;
        while (j < lcount){

        }
    }
    return 0;
}
