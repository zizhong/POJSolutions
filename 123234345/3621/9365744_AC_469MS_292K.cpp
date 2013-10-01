#include <cstdio>
#include <algorithm>
using namespace std;

typedef double D;

const int N = 1010, M = 5010;
const int INF = 1000000000;

// [Adjacent List]
// {version}
// 2009-07-16
//{
// {param}
// VSIZE is max vertex num.
// ESIZE is max edge num, 2(n - 1) when tree.
// {discription}
// node index begin with any number.

// [Vector]
// {version}
// 2009-07-16
//{

template<class T, int SIZE>
class Vec
{
public:
    Vec() : end(a) {}
    inline T * Beg() { return a; }
    inline T * End() { return end; }
    inline T * Push(const T &t) { *end = t; return end++; }
    inline T & Back() { return *(end - 1); }
    inline void Pop() { --end; }
    inline void Clr() { end = a; }
    inline bool Ept() { return a == end; }
private:
    T a[SIZE];
    T *end;
};

//}
// end of [Vector]

// can add some addition field
struct E
{
    int v, w;
    E *next;
    E(int vin = 0, E *nin = NULL, int win = 0) : v(vin), next(nin), w(win) {}
};

#define CLR(a) (memset(a, 0, sizeof(a)))
template<int VSIZE, int ESIZE>
class AList
{
public:
    inline void Clr() { CLR(e); buf.Clr(); }
    inline void Add(int u, int v, int w) {
        e[u] = buf.Push(E(v, e[u], w));
    }
    // Add Unique
    inline bool AddUni(int u, int v, int w) {
        for (E *p = e[u]; p; p = p->next)
            if (p->v == v) return true;
        Add(u, v, w);
        return false;
    }
    inline void Del(int u, int v) {
        if (!e[u]) return;
        if (e[u]->_v == v) {
            e[u] = e[u]->next;
            return;
        }
        for (E *q = e[u], *p = q->next; p; q = p, p = p->next)
            if (p->v == v)  q->next = p->next;
    }
    inline E * operator [] (int i) { return e[i]; }
private:
    Vec<E, ESIZE> buf;
    E* e[VSIZE];
};

//}
// end of [Adjacent List]

// [Queue]
// {version}
// 2009-07-16
//{

template <int SIZE>
class Queue {
public:
    Queue() : beg(0), end(0) {}
    inline void Push(int x) { a[end] = x; end = (end + 1) % SIZE; }
    inline int Front() { return a[beg]; }
    inline void Pop() { beg = (beg + 1) % SIZE; }
    inline bool Ept() { return beg == end; }
    inline void Clr() { beg = end = 0; }
private:
    int beg, end, a[SIZE];
};

//}
// end of [Queue]

Queue<N + 1> _que;
D _dis[N];
int _cnt[N];
bool _inq[N];

void spfa_init(int s, int n) {
    CLR(_inq), CLR(_cnt);
    fill_n(_dis, n, INF);
    _dis[s] = 0;
    _que.Clr();
}

bool SPFA(D ans, int n, AList<N, M> l, int a[]) {
    spfa_init(0, n);
    _que.Push(0);
    _inq[0] = true;
    ++_cnt[0];
    while (!_que.Ept()) {
        int u = _que.Front();
        _que.Pop();
        _inq[u] = false;
        for (E *p = l[u]; p; p = p->next) {
            int v = p->v, w = p->w;
            D val = w * ans - a[u];
            if (_dis[u] + val < _dis[v]) {
                _dis[v] = _dis[u] + val;
                if (!_inq[v]) {
                    _que.Push(v);
                    _inq[v] = true;
                    if (++_cnt[v] == n) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

AList<N, M> _l;
int _a[N];

int main() {
    int n, m, u, v, w, i;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; ++i) {
        scanf("%d", _a + i);
    }
    for (i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        --u, --v;
        _l.Add(u, v, w);
    }
    D beg = 0, end = 1000, mid;
    while (end - beg > 0.001) {
        if (SPFA(mid = (beg + end) / 2, n, _l, _a)) beg = mid;
        else end = mid;
    }
    printf("%.2lf\n", mid);
    scanf("%'d");
    return 0;
}
