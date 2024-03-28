#include <iostream>
using namespace std;
//const int ios_init = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 0);

int borad[20][20]{};

bool win(int x, int y){
    //* ->
    int rc = 1;
    for(int i = 0; i <= 4; ++i){
        if(x+i<=0 or 15<x+i){
            rc = 0;
            break;           
        }
        if(borad[x+i][y] != 1){
            rc = 0;
            break;
        }
    }
    if(rc){
        return rc;
    }
    //* <-
    rc = 1;
    for(int i = 0; i <= 4; ++i){
        if(x-i<=0 or 15<x-i){
            rc = 0;
            break;           
        }
        if(borad[x-i][y] != 1){
            rc = 0;
            break;
        }
    }
    if(rc){
        return rc;
    }
    //* -^
    rc = 1;
    for(int i = 0; i <= 4; ++i){
        if(y-i<=0 or 15<y-i){
            rc = 0;
            break;           
        }
        if(borad[x][y-i] != 1){
            rc = 0;
            break;
        }
    }
    if(rc){
        return rc;
    }
    //* --^
    rc = 1;
    for(int i = 0; i <= 4; ++i){
        if(y+i<=0 or 15<y+i){
            rc = 0;
            break;           
        }
        if(borad[x][y+i] != 1){
            rc = 0;
            break;
        }
    }
    if(rc){
        return rc;
    }



    //* ->-^
    rc = 1;
    for(int i = 0; i <= 4; ++i){
        if(x+i<=0 or 15<x+i){
            rc = 0;
            break;           
        }
        if(y-i<=0 or 15<y-i){
            rc = 0;
            break;           
        }
        if(borad[x+i][y-i] != 1){
            rc = 0;
            break;
        }
    }
    if(rc){
        return rc;
    }

    //* ->--^
    rc = 1;
    for(int i = 0; i <= 4; ++i){
        if(x+i<=0 or 15<x+i){
            rc = 0;
            break;           
        }
        if(y+i<=0 or 15<y+i){
            rc = 0;
            break;           
        }
        if(borad[x+i][y+i] != 1){
            rc = 0;
            break;
        }
    }
    if(rc){
        return rc;
    }

    //* -<-^
    rc = 1;
    for(int i = 0; i <= 4; ++i){
        if(x-i<=0 or 15<x-i){
            rc = 0;
            break;           
        }
        if(y-i<=0 or 15<y-i){
            rc = 0;
            break;           
        }
        if(borad[x-i][y-i] != 1){
            rc = 0;
            break;
        }
    }
    if(rc){
        return rc;
    }

    //* -<--^
    rc = 1;
    for(int i = 0; i <= 4; ++i){
        if(x-i<=0 or 15<x-i){
            rc = 0;
            break;           
        }
        if(y+i<=0 or 15<y+i){
            rc = 0;
            break;           
        }
        if(borad[x-i][y+i] != 1){
            rc = 0;
            break;
        }
    }
    if(rc){
        return rc;
    }


    return rc;
}

signed main(){
    for(int i = 0; i <= 16; ++i){
        for(int j = 0; j <= 16; ++j){
            if(i == 0 or j == 0 or i == 16 or j == 16){
                borad[i][j] = 2;
            }
        }
    }

    int n; scanf("%d", &n);
    for(int nn = 0; nn < n; ++nn){
        for(int i = 1; i <= 15; ++i){
            scanf("\n");
            for(int j = 1; j <= 15; ++j){
                scanf("%c", &borad[i][j]);
                borad[i][j]-='0';
            }
        }

        for(int i = 1; i<= 15; ++i){
            for(int j = 1; j <= 15; ++j){
                if(borad[i][j] == 0){
                    borad[i][j] = 1;
                    
                    for(int ii = 1; ii <= 15; ++ii){
                        for(int jj = 1; jj <= 15; ++jj){
                            if(win(ii,jj)){
                                cout << "Yes\n";
                                goto next_game;
                            }
                        }
                    }

                    borad[i][j] = 0;
                }
            }
        }
        
        cout << "No\n";
        next_game:
        int luozi_sb = 233;
    }
    return 0;
}