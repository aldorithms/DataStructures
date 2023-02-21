#include "Comparator.h"

template<class E>
static bool Comparator<E>::prior(E * x, E * y) {
	return x->key < y->key;
}
