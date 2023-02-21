#pragma once
#include <fstream>
#include <iostream>
#include <string>

#include "Heap.h"

#include "Comparator.h"

template <typename E, class Comp>
void heapsort(E A[], int n) {
	E maxval;
	heap<E, Comp> H(A, n, n);
	for (int i = 0; i < n; i++)
		maxval = H.removefirst();
}

int main(int argc, char* argv[]) {
	std::string response;
	std::fstream myFiles;
	std::FILE A[7];
	std::cout << "Welcome to the External File Sorter \n \n";
	for (int init = 1; init <= 7; init++) {
		std::cout << "Enter the name file, including extension (ex: file.txt): ";
		std::cin >> response;
	}
	heapsort<FILE, Comparator>(A, 7);
	return 0;
}
