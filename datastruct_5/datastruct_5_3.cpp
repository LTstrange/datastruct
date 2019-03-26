#include <iostream>
using namespace std;

template <class T> struct SqStack{
    T data[1000];
    int top;

    SqStack(){
        top=-1;
    }

    T pop(){
        if (top == -1){
            cout<<"pop ERROR!"<<endl;
            return 0;
        }
        T temp;
        temp = data[top];
        top--;
        return temp;
    }
    T gettop(){
        return data[top];
    }
    void push(T a){
        top++;
        data[top] = a;
    }
};

char compare(char c, char t){
    if (c==')') {
        if (t == '(') {
            return '=';
        } else {
            return '<';
        }
    }
    if (c=='('||t=='('){
        return '>';
    }
    if (c=='#'){
        if (t=='#'){
            return '=';
        } else{
            return '<';
        }
    } else if (c=='+'||c=='-'){
        if (t=='#'){
            return '>';
        } else{
            return '<';
        }
    } else if (c=='*'||c=='/'){
        if (t=='#'){
            return '>';
        } else if (t=='*'||t=='/'){
            return '<';
        } else{
            return '>';
        }
    }

}

int caculate(int num1, char opt, int num2){
    if (opt == '+') return num1 + num2;
    if (opt == '-') return num1 - num2;
    if (opt == '*') return num1 * num2;
    if (opt == '/') return num1 / num2;
}

void evaluate(){
    SqStack<float> nums;
    SqStack<char > optr;
    optr.push('#');
    char c;
    bool oldisnum = false;
    int num=0;
    cin>>c;
    while (c!='#'||optr.gettop() != '#'){
        if (c>='0'&&c<='9'){
            if (oldisnum){
                num = nums.pop();
                num = num*10+c-'0';
            }
            else{
                num = c-'0';
            }
            nums.push(num);
            oldisnum = true;
            cin>>c;
        } else{
            switch (compare(c, optr.gettop())){
                case '>':
                    optr.push(c);
                    cin>>c;
                    break;
                case '=':p
                    optr.pop();
                    cin>>c;
                    break;
                case '<':
                    int num1, num2;
                    char opt = optr.pop(), result;
                    num2 = nums.pop();
                    num1 = nums.pop();
                    result = caculate(num1,opt, num2);
                    nums.push(result);
                    break;
            }
            oldisnum = false;
        }
    }
    cout<<nums.gettop()<<endl;
}

int main(){
    for(int i=0;i<3;++i)
        evaluate();
    return 0;
}
