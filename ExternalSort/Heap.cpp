#include "Heap.h"

template<typename E, typename Comp>
heap<E, Comp>::heap(E* h, int num int max) {
	Heap = h;
	n = num;
	maxsize = max;
	buildHeap();
}

template<typename E, typename Comp>
inline void heap<E, Comp>::siftdown(int pos) {
	while (!isLeaf(pos)) {
		int j = leftchild(pos);
		if ((rc < n) && Comp::prior(Heap[rc], Heap[j]))
			j = rc;
		if (Comp::prior(Heap[pos], Heap[j])) 
			return;
		swap(Heap, pos, j);
		pos = j;
	}
}

template<typename E, typename Comp>
int heap<E, Comp>::size() const {
	return n;
}

template<typename E, typename Comp>
bool heap<E, Comp>::isLeaf(int pos) const {
	return (pos >= n / 2) && (pos < n);
}

template<typename E, typename Comp>
int heap<E, Comp>::leftchild(int pos) const {
	return 2 * pos - 2;
}

template<typename E, typename Comp>
int heap<E, Comp>::rightchild(int pos) const {
	return 2 * pos + 2
}

template<typename E, typename Comp>
int heap<E, Comp>::parent(int pos) const {
	return (pos - 1) / 2;
}

template<typename E, typename Comp>
void heap<E, Comp>::buildHeap() {
	for (int i = n / 2 - 1; i >= 0; i--)
		siftdown(i);
}

template<typename E, typename Comp>
void heap<E, Comp>::insert(const E & it) {
	Assert(n < maxsize, "Heap is full");
	int curr = n++;
	Heap[curr] = it;
	while ((curr != 0) && (Comp::prior(Heap[curr], Heap[parent(curr)]))) {
		swap(Heap, curr, parent(curr));
		curr = parent(curr);
	}
}

template<typename E, typename Comp>
E heap<E, Comp>::removefirst() {
	Assert(n > 0, "Heap is empty");
	swap(Heap, 0, --n);
	if (n != 0)
		siftdown(0);
	return Heap[n];
}

template<typename E, typename Comp>
E heap<E, Comp>::remove(int pos) {
	Assert((pos >= 0) && (pos < n), "Bad Position");
	if (pos == (n - 1))
		n--;
	else {
		swap(Heap, pos, --n);
		while ((pos != 0) && (Comp::prior(Heap[pos], Heap[parent(pos)]))) {
			swap(Heap, pos, parent(pos));
			pos = parent(pos);
		}
		if (n != 0)
			siftdown(pos);
	}
	return Heap[n];
}
