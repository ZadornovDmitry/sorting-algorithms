#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>

void printVector(vector<T> &v)
{
	for (auto i : v)
		cout << i;
	cout << endl;
}


template<typename T>

void bubbleSort(vector<T> &v, bool increas = true)
{
	cout << "bubble sort" << endl;

	bool needSort = true;

	while (needSort)
	{
		needSort = false;
		for (int i = 0; i < v.size() - 1; i++)
		{
			if (increas)
			{
				if (v.at(i + 1) < v.at(i)) {
					swap(v.at(i), v.at(i + 1));
					needSort = true;
				}
			}
			else
			{
				if (v.at(i + 1) > v.at(i)) {
					swap(v.at(i), v.at(i + 1));
					needSort = true;
				}
			}

		}
	}
}

template <typename T>

void insertion(vector<T> &v, bool increas = true)
{
	cout << "insertion sort" << endl;

	for (unsigned i = 1; i < v.size(); i++)
	{
		if (increas) {
			for (unsigned j = i; j >= 1 && v[j] < v[j - 1]; --j)
				swap(v.at(j), v.at(j - 1));
		}
		else
		{
			for (unsigned j = i; j >= 1 && v[j] > v[j - 1]; --j)
				swap(v.at(j), v.at(j - 1));
		}
	}
}


template <typename T>

void shellsort(vector<T> &v, bool increas = true)
{
	cout << "shellsort sort" << endl;

	for (unsigned gap = v.size() / 2; gap >= 1; gap /= 2)
	{
		for (unsigned i = gap; i < v.size(); i++)
		{
			if (increas)
			{
				for (unsigned j = i; j >= gap && v[j] < v[j - gap]; j -= gap)
					swap(v[j], v[j - 1]);
			}
			else
			{
				for (unsigned j = i; j >= gap && v[j] > v[j - gap]; j -= gap)
					swap(v[j], v[j - 1]);
			}
		}
	}
}

template <typename T>
void merge(vector<T> &v, size_t left, size_t right, size_t mid, bool increas);

template <typename T>

void mergesort(vector<T> &v, rsize_t left, size_t right, bool increas = true)
{
	cout << "mergesort sort" << endl;

	if (v.size() == 1 || left == right) return;
	size_t mid = (left + right) / 2;
	mergesort(v, left, mid, increas);
	mergesort(v, mid + 1, right, increas);
	merge(v, left, right, mid, increas);
}
template <typename T>
void merge(vector<T> &v, size_t left, size_t right, size_t mid, bool increas)
{
	vector<T> tmp;
	size_t l = left;
	size_t r = mid + 1;

	while (l <= mid && r <= right)
	{
		bool compare = increas ? v.at(l) < v.at(r) : v.at(l) > v.at(r);
		if (compare)
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

	//bubbleSort(v);
	//insertion(v);
	//shellsort(v);
	//mergesort(v, 0, v.size()-1);

	printVector(v);

	system("PAUSE");
	return 0;
}