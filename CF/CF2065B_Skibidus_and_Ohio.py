# https://codeforces.com/contest/2065/problem/B
n = int(input())
for _ in range(n):
    st_list = list(input())
    ans = len(st_list)
    for i in range(len(st_list)-1):
        if(st_list[i]==st_list[i+1]):
            ans = 1
            break
    print(ans)