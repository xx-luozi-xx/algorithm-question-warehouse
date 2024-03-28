#include <stdio.h>
int out[510][510];//x,y
int box[510][510];
void turn();
int main(){
    int ans=1;
    int n,m;scanf("%d %d",&n,&m);
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n;j++){
            out[j][i] = ans++;
        }
    }
    while(m--){
        int x,y,r,z;
        scanf("%d %d %d %d",&y,&x,&r,&z);
        x--,y--;
        for(int i = x-r;i<=x+r;i++){
            for(int j = y-r; j<=y+r;j++){
                z?
                box[(x-r)+(j-(y-r))][(y+r)-(i-(x-r))] = out[i][j]:
                box[(x+r)-(j-(y-r))][(y-r)+(i-(x-r))] = out[i][j];
            }
        }for(int i = x-r;i<=x+r;i++){
            for(int j = y-r; j<=y+r;j++){
                out[i][j]=box[i][j];
            }
        }
    }
    for(int i = 0; i<n;i++){
        i?printf("\n"):0;
        for(int j = 0; j<n;j++){
            printf("%d ",out[j][i]);
        }
    }
    return 0;
}