// https://www.matiji.net/exam/brushquestion/16/3846/4C6668FEB8CFD6520DE73B365B31D1A4

#include <vector>   // point
#include <tuple>    // pair<point, distance>
#include <stdlib.h> // rand()
#include <time.h>   // srand(time(0)^rand())
#include <queue>	// show(), KNN()
#include <list> 	//Range_Query()

#define KDT_SHOW
#define KDT_VISIT_CNT
#define KDT_POP_ROOT

#ifdef KDT_SHOW
#include <stdio.h>  //printf()
#endif


template<typename T, int K>
class KdTree {
public:
	KdTree() noexcept;
	KdTree(const std::vector<std::vector<T>>& init);
	KdTree(const KdTree<T, K>&) = delete;
	KdTree<T, K>& operator=(const KdTree<T, K>& rhs) = delete;
	~KdTree() noexcept;

	void remake() noexcept;
	void remake(const std::vector<std::vector<T>>& init);
	void swap(KdTree<T, K>& rhs) noexcept;

	size_t size() const noexcept;
	bool empty() const noexcept;

	void insert(const std::vector<T>& element);
	void erase(const std::vector<T>& element);
	//* 返回每个找到的点及其距离的平方
	std::vector<std::pair<std::vector<T>, T>> KNN(const std::vector<T>& find, int k = 1) const;
	std::vector<std::pair<std::vector<T>, T>> Range_Query(const std::vector<T>& find, double r) const;
#ifdef KDT_SHOW
public:
	void show() const noexcept;
#endif
public:
	struct KdTree_err {
		enum RC {
			INIT_DIMENSION_WRONG = 1,
			INSERT_DIMENSION_WRONG,
			ERASE_DIMENSION_WRONG,
			KNN_K_OUT_OF_RANGE,
			KNN_FIND_ELEMENT_DIMENSION_WRONG,
			RANGE_QUERY_FIND_ELEMENT_DIMENSION_WRONG
		}rc;
		KdTree_err(RC rc) noexcept:rc(rc){printf("KdTree_err::RC = %d", rc);}
	};
protected:
	struct KdTree_node {
		int split;
		std::vector<T> data;

		KdTree_node* pre;
		KdTree_node* l;
		KdTree_node* r;
	};
protected:
	KdTree_node* root_;
	size_t size_;
private:
	static KdTree_node* make_tree_(std::vector<std::vector<T>>& element, size_t l, size_t r, KdTree_node* pre) noexcept;
	static void break_tree_(KdTree_node*) noexcept;
	static void sort_by_dimension_(std::vector<T>* begin, std::vector<T>* end, int d) noexcept;//[begin, end)
	static void shuffle_(std::vector<T>* begin, std::vector<T>* end) noexcept;//[begin, end)
	static void KNN_1_(KdTree_node* root, const std::vector<T>& find, KdTree_node*& nest) noexcept;
	static void KNN_N_(KdTree_node* root, const std::vector<T>& find, std::priority_queue<std::pair<T, std::vector<T>*>>& nests, size_t k) noexcept;
	static void Range_Query_(KdTree_node* root, const std::vector<T>& find, double r, std::list<std::pair<std::vector<T>, T>>& range_set) noexcept;
	static bool intersect_(KdTree_node* root, const std::vector<T>& find, const std::vector<T>& nest) noexcept;
	static bool range_intersect_(KdTree_node* root, const std::vector<T>& find, double r) noexcept;
	static void axis_nest_min_(KdTree_node* root, const T& find, int axis, KdTree_node*& nest) noexcept;
	static void axis_nest_max_(KdTree_node* root, const T& find, int axis, KdTree_node*& nest) noexcept;
	static void dfs_get_all(KdTree_node* root_, std::vector<std::vector<T>>& elements) noexcept;
public:
	static T dis2_(const std::vector<T>& lhs, const std::vector<T>& rhs) noexcept;
#ifdef KDT_VISIT_CNT
public:
	static size_t visit_cnt;
#endif
#ifdef KDT_POP_ROOT
public:
	void pop_root(){ root_ ? erase(root_->data):void();}
#endif

};
#ifdef KDT_VISIT_CNT
template<typename T, int K>
size_t KdTree<T, K>::visit_cnt = 0;
#endif
#ifdef KDT_SHOW
template<typename T, int K>
void KdTree<T, K>::show() const noexcept{
	std::queue<std::pair<KdTree_node*, int>> que;
	root_?que.push(std::pair<KdTree_node*, int>(root_, 0)):void();
	int flr = 0;
	while(!que.empty()){
		KdTree_node* now = que.front().first;
		int now_flr = que.front().second;
		que.pop();

		if(now_flr != flr){
			flr++; printf("\n");
		}

		if(now){
			printf("[%d:(", now->split);
			for (int i = 0; i < K; ++i) {
				printf("%lld ", now->data[i]);
			}
			printf(")] ");

			que.push(std::pair<KdTree_node*, int>(now->l, now_flr + 1));
			que.push(std::pair<KdTree_node*, int>(now->r, now_flr + 1));
		}else{
			printf("[-:(");
			for (int i = 0; i < K; ++i) {
				printf("- ");
			}
			printf(")] ");
		}
	}
}
#endif
template<typename T, int K>
void KdTree<T, K>::dfs_get_all(KdTree_node* root_, std::vector<std::vector<T>>& elements) noexcept{
	if(root_){
		elements.push_back(root_->data);
		dfs_get_all(root_->l, elements);
		dfs_get_all(root_->r, elements);
	}
}
template<typename T, int K>
inline void KdTree<T, K>::remake() noexcept{
	std::vector<std::vector<T>> elements;
	elements.reserve(size_);
	dfs_get_all(root_, elements);
	KdTree<T, K> tmp(elements);
	this->swap(tmp); 
}
template<typename T, int K>
inline void KdTree<T, K>::remake(const std::vector<std::vector<T>>& init){
	KdTree<T, K> tmp(init);
	this->swap(tmp);
}
template<typename T, int K>
inline typename std::vector<std::pair<std::vector<T>, T>> KdTree<T, K>::Range_Query(const std::vector<T>& find, double r) const{
	if(find.size()!=K){
		throw KdTree_err(KdTree_err::RC::RANGE_QUERY_FIND_ELEMENT_DIMENSION_WRONG);
	}
#ifdef KDT_VISIT_CNT
	visit_cnt=0;
#endif 
	std::list<std::pair<std::vector<T>, T>> range_set;
	Range_Query_(root_, find, r, range_set);
	
	std::vector<std::pair<std::vector<T>, T>> ret(range_set.size(), std::pair<std::vector<T>, T>());
	int i = 0;
	for(auto itr = range_set.begin(); itr != range_set.end(); ++itr){
		ret[i++] = *itr;
	}
	return ret;
}
template<typename T, int K>
void KdTree<T, K>::Range_Query_(KdTree_node* root, const std::vector<T>& find, double r, std::list<std::pair<std::vector<T>, T>>& range_set) noexcept{
	if(root){
#ifdef KDT_VISIT_CNT
		visit_cnt++;
#endif 
		if(dis2_(root->data, find) <= r*r){
			range_set.push_back(std::pair<std::vector<T>, T>(root->data, dis2_(root->data, find)));
		}

		if(find[root->split]<=root->data[root->split]){
			Range_Query_(root->l, find, r, range_set);
		}else{
			Range_Query_(root->r, find, r, range_set);
		}
		
		if(find[root->split]<=root->data[root->split]){
			if(range_intersect_(root, find, r)){//* 与r相交
				Range_Query_(root->r, find, r, range_set);
			}
		}else{
			if(range_intersect_(root, find, r)){//* 与l相交
				Range_Query_(root->l, find, r, range_set);
			}
		}
	}
}

template<typename T, int K>
inline typename std::vector<std::pair<std::vector<T>, T>> KdTree<T, K>::KNN(const std::vector<T>& find, int k) const{
	if(find.size()!=K){
		throw KdTree_err(KdTree_err::RC::KNN_FIND_ELEMENT_DIMENSION_WRONG);
	}
	if(k<1 || size_<k){
		throw KdTree_err(KdTree_err::RC::KNN_K_OUT_OF_RANGE);
	}
#ifdef KDT_VISIT_CNT
	visit_cnt=0;
#endif 
	if(k == 1){
		KdTree_node* nest = root_;
		KNN_1_(root_, find, nest);
		return std::vector<std::pair<std::vector<T>, T>>{std::pair<std::vector<T>, T>(nest->data, dis2_(nest->data, find))};
	}else{
		std::priority_queue<std::pair<T, std::vector<T>*>> nests;//<dis, data>
		KNN_N_(root_, find, nests, k);
		
		std::vector<std::pair<std::vector<T>, T>> ret(nests.size(), std::pair<std::vector<T>, T>());
		for(long long i = nests.size()-1; i >= 0; --i){
			ret[i] = std::pair<std::vector<T>, T>(*nests.top().second, nests.top().first);
			nests.pop();
		}
		return ret;
	}
}

template<typename T, int K>
void KdTree<T, K>::KNN_1_(KdTree_node* root, const std::vector<T>& find, KdTree_node*& nest) noexcept{
	if(root){
#ifdef KDT_VISIT_CNT
		visit_cnt++;
#endif 
		if(dis2_(root->data, find) < dis2_(nest->data, find)){
			nest = root;
		}

		if(find[root->split]<=root->data[root->split]){
			KNN_1_(root->l, find, nest);
		}else{
			KNN_1_(root->r, find, nest);
		}
		
		if(find[root->split]<=root->data[root->split]){
			if(intersect_(root, find, nest->data)){//* 与r相交
				KNN_1_(root->r, find, nest);
			}
		}else{
			if(intersect_(root, find, nest->data)){//* 与l相交
				KNN_1_(root->l, find, nest);
			}
		}
	}
}
template<typename T, int K>
void KdTree<T, K>::KNN_N_(KdTree_node* root, const std::vector<T>& find, std::priority_queue<std::pair<T, std::vector<T>*>>& nests, size_t k) noexcept{
	if(root){
#ifdef KDT_VISIT_CNT
		visit_cnt++;
#endif 
		if(nests.size()<k || dis2_(root->data, find) < nests.top().first){
			nests.size()==k?nests.pop():void();
			nests.push(std::pair<T, std::vector<T>*>(dis2_(root->data, find), &root->data));
		}

		if(find[root->split]<=root->data[root->split]){
			KNN_N_(root->l, find, nests, k);
		}else{
			KNN_N_(root->r, find, nests, k);
		}
		
		if(find[root->split]<=root->data[root->split]){
			if(intersect_(root, find, *nests.top().second)){//* 与r相交
				KNN_N_(root->r, find, nests, k);
			}
		}else{
			if(intersect_(root, find, *nests.top().second)){//* 与l相交
				KNN_N_(root->l, find, nests, k);
			}
		}
	}
}
template<typename T, int K>
inline T KdTree<T, K>::dis2_(const std::vector<T>& lhs, const std::vector<T>& rhs) noexcept{
	T ret = T();
	for(int i = 0; i < lhs.size(); ++i){
		ret += (lhs[i]-rhs[i])*(lhs[i]-rhs[i]);
	}
	return ret;
}
template<typename T, int K>
inline bool KdTree<T, K>::intersect_(KdTree_node* root, const std::vector<T>& find, const std::vector<T>& nest) noexcept{
	return
	(root->data[root->split]-find[root->split])*(root->data[root->split]-find[root->split]) 
	<=
	dis2_(find, nest);
}
template<typename T, int K>
inline bool KdTree<T, K>::range_intersect_(KdTree_node* root, const std::vector<T>& find, double r) noexcept{
	return
	(root->data[root->split]-find[root->split])*(root->data[root->split]-find[root->split]) 
	<=
	r*r;
}
template<typename T, int K>
void KdTree<T, K>::insert(const std::vector<T>& element){
	if(element.size()!=K){
		throw KdTree_err(KdTree_err::RC::INSERT_DIMENSION_WRONG);
	}

	if(root_){
		KdTree_node* find = root_;
		while(1){
			if(element[find->split]<=find->data[find->split]){
				if(find->l){
					find = find->l;
					continue;
				}else{
					find->l = new KdTree_node;

					find->l->split = rand()%K;
					find->l->data = element;
					find->l->pre = find;
					find->l->l = nullptr;
					find->l->r = nullptr;

					size_++;
					return;
				}
			}else{
				if(find->r){
					find = find->r;
					continue;
				}else{
					find->r = new KdTree_node;
					
					find->r->split = rand()%K;
					find->r->data = element;
					find->r->pre = find;
					find->r->l = nullptr;
					find->r->r = nullptr;
					
					size_++;
					return;
				}
			}
		}
	}else{
		root_ = new KdTree_node;

		root_->split = rand()%K;
		root_->data = element;
		root_->pre = nullptr;
		root_->l = nullptr;
		root_->r = nullptr;
		
		size_++;
		return;
	}
}
template<typename T, int K>
void KdTree<T, K>::erase(const std::vector<T>& element){
	if(element.size()!=K){
		throw KdTree_err(KdTree_err::RC::ERASE_DIMENSION_WRONG);
	}
	if(root_){
#ifdef KDT_VISIT_CNT
		visit_cnt = 0;
#endif 
		KdTree_node* find = root_;
		KNN_1_(root_, element, find);
		if(find->data == element){
			while(1){
				if((find->l == nullptr && find->r == nullptr)){//* 是叶子
					if(find->pre){
						if(find->pre->l == find){
							find->pre->l = nullptr;
						}else{
							find->pre->r = nullptr;
						}
					}else{//* root
						root_ = nullptr;
					}
					delete find;
					size_--;
					return;
				}else{//* 不是叶子
					KdTree_node* next = nullptr;
					if(find->l){//*有左孩子
						axis_nest_max_(find->l, element[find->split], find->split, next);
					}else{//*有右孩子
						axis_nest_min_(find->r, element[find->split], find->split, next);
					}
					find->data.swap(next->data);
					find = next;
				}
			}
		}
	}
}
template<typename T, int K>
void KdTree<T, K>::axis_nest_min_(KdTree_node* root, const T& find, int axis, KdTree_node*& nest) noexcept{
	if(root){
#ifdef KDT_VISIT_CNT
		visit_cnt++;
#endif 
		if(!nest ||(root->data[axis]-find)*(root->data[axis]-find) <= (nest->data[axis]-find)*(nest->data[axis]-find)){
			nest = root;
		}

		if(root->split == axis){
			axis_nest_min_(root->l, find, axis, nest);
		}else{
			axis_nest_min_(root->l, find, axis, nest);
			axis_nest_min_(root->r, find, axis, nest);
		}
	}
}
template<typename T, int K>
void KdTree<T, K>::axis_nest_max_(KdTree_node* root, const T& find, int axis, KdTree_node*& nest) noexcept{
	if(root){
#ifdef KDT_VISIT_CNT
		visit_cnt++;
#endif 
		if(!nest ||(root->data[axis]-find)*(root->data[axis]-find) <= (nest->data[axis]-find)*(nest->data[axis]-find)){
			nest = root;
		}

		if(root->split == axis){
			axis_nest_max_(root->r, find, axis, nest);
		}else{
			axis_nest_max_(root->l, find, axis, nest);
			axis_nest_max_(root->r, find, axis, nest);
		}
	}
}

template<typename T, int K>
inline bool KdTree<T, K>::empty()const noexcept{
	return !size_;
}
template<typename T, int K>
inline size_t KdTree<T, K>::size()const noexcept{
	return size_;
}
template<typename T, int K>
inline void KdTree<T, K>::swap(KdTree& rhs) noexcept{
	std::swap(root_, rhs.root_);
	std::swap(size_, rhs.size_);
}
template<typename T, int K>
void KdTree<T, K>::break_tree_(KdTree_node* node) noexcept{
	if (node) {
		break_tree_(node->l);
		break_tree_(node->r);
		delete node;
	}
}
template<typename T, int K>
inline KdTree<T, K>::~KdTree() noexcept{
	break_tree_(root_);
}
template<typename T, int K>
inline KdTree<T, K>::KdTree() noexcept:size_(0), root_(nullptr){srand(time(0)^rand());};
template<typename T, int K>
inline KdTree<T, K>::KdTree(const std::vector<std::vector<T>>& init): size_(init.size()), root_(nullptr) {
	for(size_t i = 0; i < init.size(); ++i){
		if(init[i].size()!=K){//除脏
			throw KdTree_err(KdTree_err::RC::INIT_DIMENSION_WRONG);
		}
	}
	srand(time(0)^rand());
	std::vector<std::vector<T>> init_copy(init);
	root_ = make_tree_(init_copy, 0, init.size(), nullptr);
}
template<typename T, int K>
typename KdTree<T, K>::KdTree_node* KdTree<T, K>::make_tree_(std::vector<std::vector<T>>& element, size_t l, size_t r, KdTree_node* pre) noexcept{
	//* 数据区空
	if(l >= r){
		return nullptr;
	}
	//* 选择切分维度
	//* 选取方差最小维度
	int split;
	double max_variance = -1;
	for(int d = 0; d < K; ++d){
		long long sum = 0;
		for(size_t i = l; i < r; ++i){
			sum += element[i][d];
		}
		double average = double(sum)/(r-l);
		double variance = 0;
		for(size_t i = l; i < r; ++i){
			variance += (element[i][d]-average)*(element[i][d]-average);
		}
		if(max_variance < variance){
			max_variance = variance;
			split = d;
		}
	}
	//* 按选择维度排序
	shuffle_(&element[0]+l, &element[0]+r);
	sort_by_dimension_(&element[0]+l, &element[0]+r, split);

	size_t mid = (l+r)>>1;
	//* 构建本处节点
	KdTree_node* ret = new KdTree_node;
	ret->split = split;
	ret->data = element[mid];
	ret->pre = pre;
	//* 递归左右  [l, mid)  [mid+1, r)
	ret->l = make_tree_(element, l, mid, ret);
	ret->r = make_tree_(element, mid+1, r, ret);

	return ret;
}
template<class T, int K>
void KdTree<T, K>::sort_by_dimension_(std::vector<T>* begin, std::vector<T>* end, int d) noexcept{//[begin, end)
	std::vector<T>* a = begin;
	long long l = 0, i = 0;
	long long r = end-begin-1, j = end-begin-1;

	T mid = a[(l+r)>>1][d];

	while (1) {
		while (a[i][d]<mid) i++;
		while (a[j][d]>mid) j--;
		
		if(i<=j){//等于时也做一遍，使得控制区间错开，方便递归取区间和防止同一值递归死循环
			a[i].swap(a[j]);
			i++, j--;
		}
		if (i>j){
			break;
		}
	}
	if(l<j) sort_by_dimension_(begin, begin+j+1, d);
	if(i<r) sort_by_dimension_(begin+i, end, d);
}
template<class T, int K>
inline void KdTree<T, K>::shuffle_(std::vector<T>* begin, std::vector<T>* end) noexcept{//[begin, end)
	for(size_t i = end - begin - 1; i > 0; --i){
		begin[i].swap(begin[(((rand()<<30)|(rand()<<15)|(rand()))&0x7fffffff)%i]);
	}
}

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<vector<double>> init;
    for(int i = 0; i < n; ++i){
        double x, y; cin >> x >> y;
        vector<double> vec2 = {x, y};
        init.push_back(vec2);
    }
    KdTree<double, 2> kdt(init);
    double min_dis = 1e20;
    for(int i = 0; i < n; ++i){
        double dis2 = kdt.KNN(init[i], 2)[1].second;
        min_dis = min(sqrt(dis2), min_dis); 
    }
    printf("%.4f", min_dis);
    return 0;
}
