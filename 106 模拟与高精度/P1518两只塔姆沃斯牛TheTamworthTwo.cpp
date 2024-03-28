#include <stdio.h>
bool board[20][20];
int look[2][4]={//x,y
    {0,1,0,-1},
    {-1,0,1,0}
};
struct point {
    int x,y;
    point(int x=look[0][0], int y=look[1][0]):x(x),y(y){}
};
struct creature{
    int eye = 0;
    point position;
    point direct;
    bool next(){
        return !board[direct.x+position.x][direct.y+position.y];
    }
    void go(){
        position.x+=direct.x;
        position.y+=direct.y;
    }
    void turn(){
        eye++,eye%=4;
        direct.x=look[0][eye];
        direct.y=look[1][eye];
    };
    bool operator==(const creature& x)const{
        return position.x==x.position.x&&position.y==x.position.y
        &&direct.x==x.direct.x&&direct.y==x.direct.y;
    }
    bool operator&&(const creature& x)const{
        return position.x==x.position.x&&position.y==x.position.y;
    }
};
struct history{
    creature _F[400+10];
    creature _C[400+10];
    int ans = 0;
    
    void push(const creature& F, const creature &C){
        _F[ans] = F;
        _C[ans] = C;
        ans++;
    }
    bool back(const creature& F, const creature& C)const{
        for(int i = 0;i<ans;i++){
            if (F==_F[i]&&C==_C[i]){
                return 0;
            }
        }
        return 1;
    }
};
int main(){
    history x;
    creature F;
    creature C;
    for(int i = 0; i<=11;i++){
        board[0][i] = board[i][0] = 1;
        board[11][i] = board[i][11] = 1;
    }
    for(int y = 1; y<=10;y++){
        for(int x = 1; x<=10; x++){
            char box;scanf("%c",&box);
            if(box == '.'){
                board[x][y] = 0;
            }else if (box == '*'){
                board[x][y] = 1;
            }else if(box == 'F'){
                board[x][y] = 0;
                F.position = point(x,y);
            }else if(box == 'C'){
                board[x][y] = 0;
                C.position = point(x,y);
            }
        }
        y-10?scanf("\n"):0;
    }
    unsigned long long time = 0;
    while (++time){
        C.next()?C.go():C.turn();
        F.next()?F.go():F.turn();
        if (C&&F){
            break;
        }else{
            if(x.back(F,C)){
                x.push(F,C);
            }else{
                time = 0;
                break;
            }
        }       
    }
    return 0* printf("%llu",time);
}