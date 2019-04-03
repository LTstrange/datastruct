#include <iostream>
using namespace std;

typedef int Rank;
#define DEFAULT_CAPACITY 3

template <typename T> class Vector{
protected:
    Rank _size; int _capacity; T *_elem;
    void expand();
public:
    Vector(int c=DEFAULT_CAPACITY,int s=0,T v=0)//c接受默认容量
    {
        _elem=new T[_capacity=c];
        for(_size=0;_size<s;
        _elem[_size++]=v);
    }

    ~Vector(){
        delete []_elem;
    }

    Rank insert(Rank r,T const& e);

    Rank insert(T const& e){
        return insert(_size, e);
    }

    int remove(Rank lo,Rank hi);

    T remove(Rank r);

    Rank find(T const& e,Rank lo,Rank hi);//基本的增删查//为了描述简单，只读const与否不再列举
    int Size() const {
        return _size;
    }
    bool empty() const {
        return !_size;
    }
    T& operator[](Rank r) ;
};

template <typename T>  T& Vector<T>::operator[](Rank r){
	return _elem[r];
}

template <typename T> void Vector<T>::expand(){
    if(_size<_capacity) return;
    if(_capacity<DEFAULT_CAPACITY) _capacity=DEFAULT_CAPACITY;
    T *oldElem=_elem;
    _elem=new T[_capacity<<=1];
    for(int i=0;i<_size;++i)
        _elem[i]=oldElem[i];
    delete []oldElem;
}
template <typename T> Rank Vector<T>::insert(Rank r,T const& e){
    expand();
    for(int i=_size;i>r;--i)
        _elem[i]=_elem[i-1];
    _elem[r]=e;
    _size++;
    return r;
}
template <typename T> int Vector<T>::remove(Rank lo,Rank hi){//删除区间[lo,hi)
    if(hi==lo) return 0;
    while(hi<_size)
        _elem[lo++]=_elem[hi++];
    _size=lo;
    return hi-lo;
}
template <typename T> T Vector<T>::remove(Rank r){
    T e=_elem[r];
    remove(r,r+1);
    return e;
}
template <typename T> Rank Vector<T>::find(T const& e,Rank lo,Rank hi){
    while((lo<hi--)&&(e!=_elem[hi]));
    return hi;
}


template <typename T> class Stack: public Vector<T> { //将向量的首末端作为栈底/顶
public: //size()、empty()以及其他开放接口，均可直接沿用
   void push ( T const& e ) {
        Vector<T>::insert ( e );
   } //入栈：等效于将新元素作为向量的末元素插入
   T pop() {
        return Vector<T>::remove ( Vector<T>::Size() - 1 );
   } //出栈：等效于删除向量的末元素
   T& top() {
        return ( *this ) [Vector<T>::Size() - 1];
   } //取顶：直接返回向量的末元素
};

char compare(char c,char t){
//    if(c=='(')
//        return '>';
//    else if(c==')'&&t=='(')
//        return '=';
//    else if(c=='(')
//        return '<';//不确定！！！
//    else
//        return '<';
    if(c==')'){
        if(t=='(')
            return '=';
        else
            return '<';
    }
    if(c=='(')
        return '>';//可以根据<,>推理结果看应用哪个符号
    if(t=='(')//这个情况刚开始忘了
        return '>';

    if(c=='#'){
        if(t=='#') return '=';
        else    return '<';//返回值小于？？？
    }else if(c=='+'||c=='-'){
        if(t=='#')  return '>';
        else    return '<';
    }else if(c=='*'||c=='/'){
        if(t=='*'||t=='/')  return '<';
        else    return '>';
    }
}

float calcu(double n,char c,double m){
    if(c=='*') return n*m;
    if(c=='+') return n+m;
    if(c=='/') return n/m;
    if(c=='-') return n-m;
    return 1000000;
}
//
//float evaluate(char *S){
//    Stack<float> opnd;  Stack<char> optr;//运算数栈，运算符栈
//    optr.push('=');
//    while(!optr.empty()){
//            cout<<*S<<endl;
//        if(isdigit(*S-'0')){
//            opnd.push(*S-'0'); S++;
////            readNumber(S,opnd); append(RPN,opnd.top());
//        }else{
//            switch(orderBetween(optr.top(),*S)){
//            case '<':
//                optr.push(*S); S++;
//                break;
//            case '=':
//                optr.pop(); S++;
//                break;
//            case '>':{
//                char op=optr.pop();
//                float pOpnd2=opnd.pop(),pOpnd1=opnd.pop();
//                opnd.push(calcu(pOpnd1,op,pOpnd2));
//            }   break;
//            default: cout<<"good"<<endl;
//            }
//    }
//    }
//    return opnd.pop();
//
//}
//
//
//
//
//int main(){
//    Stack<char> S;
//    char p[20];
//    char *ptr=p;
//    cin>>p;
//    while(*ptr!='='){
//
//        S.push(*ptr);
//        ptr++;
//
////        cout<<S.top()<<endl;
//    }
//    cout<<evaluate(p);
//    return 0;
//}


double evaluate(){
    Stack<double> opnd;   Stack<char> optr;
    optr.push('#');
//    cout<<optr.top();
    char c; bool oldcIsNum=false; int num=0;
    cin>>c;
    while(c!='#'||optr.top()!='#'){
        if(c>='0'&&c<='9'){
            if(oldcIsNum){
                num=opnd.pop();
                num=num*10+c-'0';
            }else
                num=c-'0';
            opnd.push(num);
//            cout<<opnd.top()<<endl;
            cin>>c; oldcIsNum=true;
        }else{
            switch(compare(c,optr.top())){
            case '>':  optr.push(c); cin>>c; break;
            case '=':  optr.pop(); cin>>c;  break;
            case '<':
                char op=optr.pop();
                double pOpnd2=opnd.pop(),pOpnd1=opnd.pop();
                opnd.push(calcu(pOpnd1,op,pOpnd2));
                break;
            }oldcIsNum=false;
        }
    }
    cout<<opnd.top()<<endl;
}
int main(){
    for(int i=0;i<3;++i)
        evaluate();
    return 0;
}

