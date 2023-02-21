#pragma once
template <typename E, typename Comp>
class heap {
private:
	E* Heap;
	int maxsize;
	int n;

	void siftdown(int pos);

public:
	heap(E* h, int num int max);
	int size() const;
	bool isLeaf(int pos) const;
	int leftchild(int pos) const;
	int rightchild(int pos) const;
	int parent(int pos) const;
	void buildHeap();
	void insert(const E& it);
	E removefirst();
	E remove(int pos)
};