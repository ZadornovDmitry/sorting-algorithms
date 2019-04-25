#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>

void printVector(vector<T> &v  )
{
	for (auto i : v)
		cout << i;
	cout << endl;
}


template<typename T, typename F>

void bubbleSort(vector<T> &v, F&&compare)
{
	cout << "bubble sort" << endl;

	bool needSort = true;

	while (needSort)
	{
		needSort = false;
		for (int i = 0; i < v.size() - 1; i++)
		{
			if (compare(v.at(i),v.at(i+1))) {
				swap(v.at(i), v.at(i + 1));
				needSort = true;
			}
		}
	}
}

template <typename T, typename F>

void insertion(vector<T> &v, F&&compare)
{
	cout << "insertion sort" << endl;

	for (unsigned i = 1; i < v.size(); i++)
	{
		for (unsigned j = i; j >= 1 && compare(v[j], v[j-1]); --j)
			swap(v.at(j), v.at(j - 1));
	}
}


template <typename T, typename F>

void shellsort(vector<T> &v, F&&compare)
{
	cout << "shellsort sort" << endl;

	for (unsigned gap = v.size() / 2; gap >= 1; gap /= 2)
	{
		for (unsigned i = gap; i < v.size(); i++)
		{
			for (unsigned j = i; j >= gap && compare(v[j], v[j - gap]); j -= gap)
				swap(v[j], v[j - 1]);
		}
	}
}

template <typename T>
void merge(vector<T> &v, size_t left, size_t right, size_t mid, bool increas);

template <typename T, typename F>

void mergesort(vector<T> &v, rsize_t left, size_t right, F&&compare)
{
	if (left == 0 && right == v.size()-1) cout << "mergesort sort" << endl;

	if (left < right)
	{
		size_t mid = (left + right) / 2;
		mergesort(v, left, mid, compare);
		mergesort(v, mid + 1, right, compare);
		merge(v, left, right, mid, compare);
	}
}
template <typename T, typename F>
void merge(vector<T> &v, size_t left, size_t right, size_t mid, F&&compare)
{
	vector<T> tmp;
	size_t l = left;
	size_t r = mid + 1;

	while (l <= mid && r <= right)
	{
		if (compare(v.at(l), v.at(r)))
			tmp.push_back(v.at(l++));
		else
			tmp.push_back(v.at(r++));
	}

	while (l <= mid)
		tmp.push_back(v.at(l++));

	while (r <= right)
		tmp.push_back(v.at(r++));

	l = left;
	while (!tmp.empty())
	{
		v[l++] = tmp.front();
		tmp.erase(tmp.begin());
	}

}


int main()
{
// preparing vector
	vector<int> v;
	size_t size = 10;
	for (unsigned i = 0; i < size; i++)
	{
		v.push_back(i);
	}

	random_shuffle(v.begin(), v.end());
	printVector(v);

// sorting

	auto f = [](int i1, int i2) {return i1 < i2; };
	//bubbleSort(v, f);
	//insertion(v, f);
	//shellsort(v, f);
	mergesort(v, 0, v.size()-1, [](int i1, int i2) {return i1 <= i2; });

	printVector(v);

	system("PAUSE");
	return 0;
}