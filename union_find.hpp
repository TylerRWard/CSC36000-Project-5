#ifndef UNION_FIND_HPP
#define UNION_FIND_HPP

#include <vector>

class UnionFind {
private:
    std::vector<int> parent, rank;

public:
    UnionFind(int n);
    int find(int x);
    bool union_sets(int x, int y);
};

struct Edge {
    int u, v, cost;
    Edge(int _u, int _v, int _cost) : u(_u), v(_v), cost(_cost) {}
};

#endif // UNION_FIND_HPP