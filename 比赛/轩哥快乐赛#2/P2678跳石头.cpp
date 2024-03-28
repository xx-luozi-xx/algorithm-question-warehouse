    /**
     * @file P2678跳石头.cpp
     * @author luozi
     * @brief 轩哥快乐赛#2
     * @version 0.1
     * @date 2022-10-20
     * 
     * @copyright xX_luozi_Xx (c) 2022
     * 
     */
    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;
    int L, N, M;
    vector<int> a;

    bool chack(int mid);

    int main(){
        scanf("%d %d %d",&L, &N, &M);
        int l = L;
        int r = 0;
        
        a.push_back(0);
        int last = 0;
        for(int i = 0; i < N; ++i){
            int box;scanf("%d",&box);
            a.push_back(box-last);
            l>a.back()?l = a.back():0;
            r<a.back()?r = a.back():0;
            last = box;
        }
        a.push_back(L-last);
        l>a.back()?l = a.back():0;
        r<a.back()?r = a.back():0;//答案在[l,r]中
    /*    for(int i = 0; i < a.size(); ++i){
            printf("%d ",a[i]);
        }printf("\n");*/
        int mid;
        while(l<=r){
            mid = (r+l)/2;
            //printf("<%d, %d = %d>",l, r, mid);
            if(chack(mid)&&!chack(mid+1)){
                return 0*printf("%d",mid);
            }else if(chack(mid)){//合理（mid小了）
                l = mid+1;
            }else{//不合理（mid大了）
                r = mid-1;
            }
        }
        //printf("-1");
        while(1){}
    }
    int& last(vector<int> &b, int i){
        while(b[i]==-1){
            --i;
        }
        return b[i];
    }
    bool chack(int mid){
        vector<int> b(a);
        b[0] = __INT_MAX__;
        int times = 0;
        for(int i = 1; i < b.size(); ++i){
            if(b[i]<mid){
                if(++times>M){
                    return 0;
                }
                if(i!=b.size()-1&&(i==1||last(b,i-1)>b[i+1])){//移右边
                    b[i+1]+=b[i];
                    b[i] = -1;
                }else{//移左边
                    last(b,i-1)+=b[i];
                    b[i] = -1;
                }
            }
        }
        return 1;
    }


