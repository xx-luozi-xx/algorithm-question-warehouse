#include <stdio.h>
#include <algorithm>

int I, J;

struct row{
    int W=0,R=0,B=0;
};

row  data[51]{};

int main(){
    scanf("%d %d", &I, &J);
    for(int i = 0; i < I; ++i){
        scanf("\n");
        for(int j = 0; j < J; ++j){
            char input;
            scanf("%c", &input);
            switch(input){
                case 'W':{
                    ++data[i].W;
                }break;
                case 'B':{
                    ++data[i].B;
                }break;
                case 'R':{
                    ++data[i].R;
                }break;
                default:{
                    throw "error input";
                }
            }
        }
    }
    int _min = __INT_MAX__;
    for(int i1 = 0; i1 < I-2; ++i1){
        for(int i2 = i1 + 1; i2 < I-1; ++i2){
            //[0, i1] (i1, i2] (i2, I)
            int tmp = 0;
            for(int s1 = 0; s1 <= i1; ++s1){
                tmp += data[s1].B + data[s1].R;
            }
            for(int s2 = i1+1; s2 <=i2; ++s2){
                tmp+= data[s2].W+data[s2].R;
            }
            for(int s3 = i2+1; s3<I; ++s3){
                tmp+= data[s3].B+data[s3].W;
            }
            _min = std::min(_min, tmp);
        }
    }
    printf("%d", _min);
    return 0;
}