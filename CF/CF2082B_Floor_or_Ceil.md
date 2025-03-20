贪心，对于除二取整的运算，先上在下小于等于先下在上.

细节：单次复杂度为$O(n+m)$, 但是注意到对$x$反复除二，只需$\log_2(x)$次坍塌到0或1，所以可令`n := min(30, n); m := min(30, m)`.

核心代码：
```c++
int x, n, m;
cin >> x >> n >> m;
n = min(30, n);
m = min(30, m);
int max_ans = x, min_ans = x;
max_ans >>= n;
for(int i = 0; i < m; ++i){
    max_ans = (max_ans+1)>>1;
    min_ans = (min_ans+1)>>1;
}
min_ans >>= n;
cout << min_ans << ' ' << max_ans << '\n';
```

下面给出贪心正确性证明.

设两函数$f, g$为$
f(x) = \lfloor \frac{x}{2} \rfloor , \space
g(x) = \lceil \frac{x}{2} \rceil 
$, 欲证明对于任意正整数$x, n, m$都有$f^n(g^m(x)) \leq g^m(f^n(x))$.

证明：
先给出$f,g$的一些性质:

**引理1：** $f(x) \leq g(x)$, 当且仅当 $x$ 为偶数时等号成立.

**引理2：**
$$
x_1 \leq x_2 \Rightarrow 
\begin{cases}
f(x_1) \leq f(x_2), \\
g(x_1) \leq g(x_2)
\end{cases}
$$

**引理3：** $g(f(x)) \leq f(g(x))$.

前两条是显然的，浅证第三条：

当$x$为偶数时，不妨设$x = 2k$, 则：$f(g(x)) = f(k) \leq g(k) = g(f(x))$.

当$x$为奇数时，不妨设$x = 2k + 1$,则：$f(g(x)) = f(k+1) = \lfloor{\frac{k+1}{2}}\rfloor = \lceil{\frac{k}{2}}\rceil = g(k) =g(f(x))$.

综上**引理3**得证.

下通过归纳法证明$f^n(g^m(x)) \leq g^m(f^n(x))$.

对$n$施归纳：

当$n=0$时，$f^0(g^m(x)) = g^m(x) = g^m(f^0(x))$.

假设当$n=k$时，有$f^k(g^m(x)) \leq g^m(f^k(x))$，

预见：$f^{k+1}(g^m(x)) \leq g^m(f^{k+1}(x))$.

当$m=0$时显然成立，不妨设$m>0$, 那么：

$$
\begin{aligned}
f^{k+1}(g^m(x)) &= f^k(f(g(g^{m-1}(x)))) \\
               &\leq f^k(g(f(g^{m-1}(x)))) \quad \text{\# 引理3和引理2} \\
               &\cdots \\
               &\leq g(f^k(f(g^{m-1}(x)))) \quad \text{\# 反复使用引理3和引理2} \\
               &= g(f^{k+1}(g^{m-1}(x))) \\
               &\leq \cdots \leq g^m(f^{k+1}(x)) \quad \text{\# 反复上述过程}
\end{aligned}
$$

于是归纳成立，命题得证.
