#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100030
struct vec{
    int x, y, id;
} data[MAX_SIZE];

long long doc(vec a, vec b){
    return a.x*b.x + a.y*b.y;
}
long long voc(vec a, vec b){
    return abs(a.x*b.y-b.x*a.y);
}

bool cmp(const pair<vec, vec>& lhs, const pair<vec, vec>& rhs){//<
//    dian/abs(cha) < dian/abs(cha);
//    printf("{%d %d %d %d}\n", voc(lhs.first, lhs.second),doc(lhs.first, lhs.second),voc(rhs.first, rhs.second),doc(rhs.first, rhs.second));
    if(doc(lhs.first, lhs.second)*doc(rhs.first, rhs.second)<=0){
        return doc(lhs.first, lhs.second) > doc(rhs.first, rhs.second);
    }else{
        return voc(lhs.first, lhs.second)*doc(rhs.first, rhs.second)
                <
               voc(rhs.first, rhs.second)*doc(lhs.first, lhs.second);
    }

}

int main(){
    int n; scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &data[i].x, &data[i].y);
        data[i].id = i+1;
    }
    sort(data, data+n, [](const vec& lhs, const vec& rhs){
        if(lhs.x*rhs.x < 0){
            return lhs.x > rhs.x;
        }else if(lhs.x*rhs.x == 0){
            if(lhs.x == 0){
                if(lhs.y > 0){
                    return rhs.x < 0;
                }else{
                    return true;
                }
            }else{
                if(rhs.y > 0){
                    return lhs.x >= 0;
                }else{
                    return false;
                }
            }
        }else{
            return lhs.y*rhs.x < rhs.y*lhs.x;
        }
    });

    data[n] = data[0];

    // for(int i = 0 ;i < n; ++i){
    //     printf("[%d %d - %d]\n", data[i].x, data[i].y, data[i].id);
    // }

    pair<vec, vec> _min = make_pair(data[0], data[1]);

    for(int i = 0; i < n; ++i){
        auto now = make_pair(data[i], data[i+1]);
        if(cmp(now, _min)){
            _min = now;
        }
    }
    printf("%d %d", _min.first.id, _min.second.id);
    return 0;

}