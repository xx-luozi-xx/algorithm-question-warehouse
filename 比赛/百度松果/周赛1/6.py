# https://www.matiji.net/exam/brushquestion/18/3846/4C6668FEB8CFD6520DE73B365B31D1A4
def feibo(num):
    x1 = 1
    x2 = 0
    x3 = 0
    if num == 0:
        return 0
    if num == 1:
        return 1

    for _ in range(num):
        x3 = x1 + x2
        x1 = x2
        x2 = x3
    return x3

def gcd(x, y):
    while y:
        x, y = y, x%y
    return x

a, b = input().split()
print(gcd(feibo(int(a)), feibo(int(b)))%1000000)