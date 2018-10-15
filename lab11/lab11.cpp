/*
 * lab11.cpp
 *
 * Implementations of binary search, Fisher-Yates shuffling, and insertion
 * sort (with added timing code) for analysis practice.  There are also some 
 * convenience methods to provide vectors of integers to use in testing.
 *
 * Author: C. Painter-Wakefield
 * 
 * Last modified: 11/30/2017
 */

#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>

using namespace std;

/* Function prototypes */
/* Algorithms */
double binary_search(const vector<int> &vec, int search_val);
int    binary_search(const vector<int> &vec, int search_val, int left, int right);
double insertion_sort(vector<int> &vec);
double shuffle(vector<int> &vec);

/* Utility */
vector<int> range_vector(int size);
vector<int> random_vector(int size);


/* main() */
int main() {

	const int SIZE = 100000000;

	// each of the algorithm functions provided returns the time taken
	// in running the algorithm.

	// INSERTION SORT
	vector<int> vec = random_vector(SIZE);
	/*double t1 = insertion_sort(vec);
	cout << "Sorted " << SIZE << " elements in " << t1 << " seconds." << endl;
	*/
	
	// Better timing data can be obtained by averaging many trial runs
	// of the same algorithm.  This can even out differences due to 
	// various types of interference, or differences in the data input.

	// FISHER-YATES SHUFFLE
	/*vec = range_vector(SIZE);
	double t2 = 0;
	for (int i = 0; i < 1000; i++) {
		t2 += shuffle(vec);
	}
	cout << "Shuffled " << SIZE << " elements in " << t2 / 1000 << " seconds (average)." << endl;
	*/
	// BINARY SEARCH
	double t3 = 0;
	vec = range_vector(SIZE); // input to binary search *must* be ordered
	for (int i = 0; i < 1000; i++) {
		t3 += binary_search(vec, rand() % vec.size());
	}
	cout << "Searched " << SIZE << "  elements in " << t3 / 1000 << " seconds (average)." << endl;
}

/*
  double binary_search(const vector<int> &vec, int search_val)
  Takes in an *already sorted* vector of integers, and searches the vector for
  the search value.  When the value is found, or is determined not to be in
  the vector, the function returns.  (Normally, this function would return the
  index of the found value, but this code returns a double reflecting the 
  number of seconds spent in the algorithm, instead.)
*/
double binary_search(const vector<int> &vec, int search_val) {
	clock_t start = clock();

	int ans = binary_search(vec, search_val, 0, vec.size() - 1);

	clock_t stop = clock();
	return (stop - start) / double(CLOCKS_PER_SEC);
}

/*
 * int binary_search(const vector<int> &vec, int search_val, int left, int right) 
 * The actual recursive implementation of the binary search algorithm.  In
 * addition to the vector and the search value, this function takes in the 
 * left hand and right hand indices bounding the part of the vector being
 * searched.  The function returns the index of the found value, or -1 if not
 * found.
 */
int binary_search(const vector<int> &vec, int search_val, int left, int right) {
	if (left > right) return -1;
	int pivot = left + (right - left) / 2;
	if (vec[pivot] == search_val) {
		return pivot;
	} else if (search_val < vec[pivot]) {
		return binary_search(vec, search_val, left, pivot - 1);
	} else {
		return binary_search(vec, search_val, pivot + 1, right);
	}
}

/*
 * double insertion_sort(vector<int> &vec)
 * Sorts a vector of integers in place.  Returns the processor time taken, in
 * seconds.
 */
double insertion_sort(vector<int> &vec) {
	clock_t start = clock();

	for (int i = 1; i < vec.size(); i++) {
		int j;
		int el = vec[i];
		for (j = i - 1; j >= 0 && vec[j] > el; j--) {
			vec[j + 1] = vec[j];
		}
		vec[j + 1] = el;
	}

	clock_t stop = clock();
	return (stop - start) / double(CLOCKS_PER_SEC);
}

/*
 * double shuffle(vector<int> &vec)
 * Shuffles a vector of integers in place.  Returns the processor time taken, in
 * seconds.  The algorithm used is the Fisher-Yates algorithm.
 */
double shuffle(vector<int> &vec) {
	clock_t start = clock();

	for (int i = vec.size() - 1; i >= 1; i--) {
		int idx = rand() % (i + 1);
		swap(vec[idx], vec[i]);
	}

	clock_t stop = clock();
	return (stop - start) / double(CLOCKS_PER_SEC);
}

/*
 * vector<int> range_vector(int size)
 * Return a vector<int> containing all the integers from 0 to size - 1, in 
 * order.
 */
vector<int> range_vector(int size) {
	vector<int> answer(size);
	for (int i = 0; i < size; i++) answer[i] = i;
	return answer;
}

/*
 * vector<int> random_vector(int size)
 * Return a vector<int> containing random integers, in no particular order.
 */
vector<int> random_vector(int size) {
	vector<int> answer(size);
	for (int i = 0; i < size; i++) answer[i] = rand();
	return answer;
}

