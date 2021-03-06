#include <iostream>
#include <string>
using namespace std;

typedef struct {
    int r,c;
}PosType;

typedef struct {
    int ord;      //通道块在路径上的序号
    PosType seat; //通道块在迷宫中的“坐标位置”
    int di;       //从此通道块走向下一通道块的“方向”
}SElemType;

typedef struct {
    char arr[10][11];
}MazeType;

typedef struct SqStack {
    SElemType data[1000];
    int top;

    SqStack(){
        top=-1;
    }

    SElemType pop(){
        if (top == -1){
            cout<<"pop ERROR!"<<endl;
        }
        SElemType temp;
        temp = data[top];
        top--;
        return temp;
    }
    SElemType gettop(){
        return data[top];
    }
    void push(SElemType a){
        top++;
        data[top] = a;
    }
    bool StackEmpty(){
        if (top == -1)
            return true;
        else
            return false;
    }
};

bool Pass(MazeType maze, PosType pos){
    if (maze.arr[pos.r][pos.c] != '#' && maze.arr[pos.r][pos.c] != '!' && maze.arr[pos.r][pos.c] != '*')
        return true;
    else
        return false;
}

void FootPrint(MazeType &maze, PosType pos){
    maze.arr[pos.r][pos.c] = '*';
}

PosType NextPos(PosType pos, int direct){
    switch (direct){
        case 1 :
            pos.c++;
            break;
        case 2:
            pos.r++;
            break;
        case 3:
            pos.c--;
            break;
        case 4:
            pos.r--;
            break;
    }
    return pos;
}

void MarkPrint(MazeType &maze, PosType pos){
    maze.arr[pos.r][pos.c] = '!';
}

bool MazePath(MazeType &maze, PosType start, PosType end) {
    SqStack S;
    PosType curpos;
    int curstep;
    SElemType e;

    curpos = start;
    curstep = 1;
    do {
        if (Pass(maze, curpos)){
            FootPrint(maze, curpos);
            e.di = 1;
            e.ord = curstep;
            e.seat = curpos;
            S.push(e);
            if (curpos.r == end.r && curpos.c == end.c){
                return true;
            }
            curpos = NextPos(curpos, 1);
            curstep++;
        } else {
            if (!S.StackEmpty()){
                e = S.pop();
                while (e.di == 4 && !S.StackEmpty()){
                    MarkPrint(maze, e.seat);
                    e = S.pop();
                }
                if (e.di < 4){
                    e.di++;
                    S.push(e);
                    curpos = NextPos(e.seat, e.di);
                }
            }
        }
    } while (!S.StackEmpty());
    return false;
}

int main(){
    MazeType maze;
    PosType start, end;
    for (int i=0;i<10;i++)
        cin.getline(maze.arr[i], 11);
    for (int i=0;i<10;i++)
        for (int j = 0; j < 10; ++j) {
            if (maze.arr[i][j] == 'S') {
                start.r = i;
                start.c = j;
            } else if (maze.arr[i][j] == 'E'){
                end.r = i;
                end.c = j;
            }
        }

    if (MazePath(maze, start, end)) {
        for (int j = 0; j < 10; j++)
            cout << maze.arr[j] << endl;
    } else{
        cout<<"ERROR!!!"<<endl;
    }
    return 0;
}

/*
##########
#S #   # #
#  #   # #
#    ##  #
# ###    #
#   #    #
# #   #  #
# ### ## #
##      E#
##########
 */

