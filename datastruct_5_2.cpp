#include<iostream>
using namespace std;

typedef struct {
	char a[1000];
	int top;
}SeqStack;

void InitStack(SeqStack &S){
	S.top = -1;
}

char pop(SeqStack &S){
	char temp;
	if (S.top != -1){
		temp = S.a[S.top];
		S.top--;
	}
	else {
		return 0;
	}
	return temp;
}

void push(SeqStack &S, char c){
	S.top++;
	S.a[S.top] = c;
}

int main(){
	SeqStack A;
	InitStack(A);
	
	int count =0;
	char c=0, temp='z';
	int flag = 1;
	while (cin>>c && c != '@'){
		
		if (c == '&'){
			flag = 0;
		}else{
		if(flag){
			push(A, c);
			count++;
		}
		else{
			temp = pop(A);
			if (temp == c){
				continue;
			}
			else{
				cout<<"no"<<endl;
				return 0;
			}
		}
		}
	}
	cout<<count<<0;
	return 0;
}



