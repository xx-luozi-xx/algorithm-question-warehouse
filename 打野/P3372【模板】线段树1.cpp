#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define int_ signed
const int MAX_N = 1e5+30;
const int MAX_T = MAX_N*8;

int n, m;
int data[MAX_N];

struct Node{
	int val;
	int tag;
	int_ l;
	int_ r;
}tree[MAX_T];

#define ls(x) ((x)<<1)
#define rs(x) (((x)<<1)|1)
#define mid(x, y) (((x)+(y))>>1)

void view(int_ root = 1){
	printf("(%d,%d,%d:%d,%d)", root, tree[root].l, tree[root].r, tree[root].tag, tree[root].val);
	if(tree[root].l != tree[root].r){
		view(ls(root));
		view(rs(root));
	}
}

void make_tree(int_ root, int_ l, int_ r)noexcept{
	//printf("(%d,%d,%d)", root, l, r);
	tree[root].l = l;
	tree[root].r = r;
	if(l == r){
		tree[root].val = data[l];
	}else{
		make_tree(ls(root), l, mid(l,r));
		make_tree(rs(root), mid(l,r)+1, r);
		tree[root].val = tree[ls(root)].val+tree[rs(root)].val;
	}
}

inline void push_down(int_ root)noexcept{
	if(tree[root].tag){
		if(tree[root].l != tree[root].r){
			tree[ls(root)].tag+=tree[root].tag;
			tree[rs(root)].tag+=tree[root].tag;
		}
		tree[root].val+=tree[root].tag*(tree[root].r-tree[root].l+1);
		tree[root].tag = 0;
	}
}
inline void push_up(int_ root)noexcept{
	push_down(root);
	if(tree[root].l != tree[root].r){
		push_down(ls(root));
		push_down(rs(root));
		tree[root].val = tree[ls(root)].val + tree[rs(root)].val;
	}
}
void updata(int_ root, int_ l, int_ r, int num)noexcept{
	push_down(root);
	if(l == tree[root].l && r == tree[root].r){
		tree[root].tag += num;
	}else if(r <= tree[ls(root)].r){
		updata(ls(root), l, r, num);
	}else if(l >= tree[rs(root)].l){
		updata(rs(root), l, r, num);
	}else{
		updata(ls(root), l, tree[ls(root)].r, num);
		updata(rs(root), tree[rs(root)].l, r, num);
	}
	push_up(root);
}

int sum(int_ root, int_ l, int_ r)noexcept{
	push_down(root);
	//printf("[%d,%d,%d,%d]", root, tree[root].l, tree[root].r, tree[root].val);
	if(l == tree[root].l && r == tree[root].r){
		return tree[root].val;
	}else if(r <= tree[ls(root)].r){
		return sum(ls(root), l, r);
	}else if(l >= tree[rs(root)].l){
		return sum(rs(root), l, r);
	}else{
		return 
		sum(ls(root), l, tree[ls(root)].r)
		+
		sum(rs(root), tree[rs(root)].l, r);
	}
}


int_ main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> data[i];
	}
	make_tree(1, 1, n);
	for(int i = 1; i <= m ;++i){
		int op; cin >> op;
		if(op == 1){
			int x, y, k;
			cin >> x >> y >> k;
			updata(1, x, y, k);
		}else if(op == 2){
			int x, y;
			cin >> x >> y;
			cout << sum(1, x, y) << '\n';
		}
		if(op == 3){
			view();
		}
	}

	return 0;
}