#ifndef DISJOINTSET_H
#define DISJOINTSET_H


class DisjointSet {
   public:
    DisjointSet(int n);
    virtual ~DisjointSet();
    int find(int a);
    void Join(int a, int b);
   private:
   	int *elements, *rank;

};

#endif // DISJOINTSET_H