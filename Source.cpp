#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void shellsSort(vector<int> &v)
{
	for (unsigned gap = v.size() / 2; gap > 0; gap /= 2)
	{
		for (unsigned i = gap; i < v.size(); i++) {

			for (int j = i; j >= gap && v[j - gap] > v[j]; j-=gap)
			{
				swap(v.at(j - 1), v.at(j));
			}
		}
	}
}
void insertionSort(vector<int> &v)
{
	for (unsigned i = 1; i < v.size(); i++) {
		
		for (int j = i; j > 0 && v[j - 1] > v[j]; j--)
		{
			swap(v.at(j - 1), v.at(j));
		}
	}
}

void bubbleSort(vector<int> &v)
{
	bool needSort = true;
	while (needSort)
	{
		needSort = false;
		for (unsigned i = 0; i < v.size()-1; i++)
		{
			if (v.at(i) > v.at(i + 1))
			{
				int buf = v.at(i);
				v[i] = v.at(i + 1);
				v[i + 1] = buf;
				needSort = true;
			}
		}
	}
}


void sort(vector<int> &v, size_t left, size_t right, size_t mid);
void mergeSort(vector<int> &v, size_t left, size_t right)
{
	if (left < right) 
	{

		size_t mid = (right + left) / 2;
		mergeSort(v, left, mid);
		mergeSort(v, mid + 1, right);
		sort(v, left, right, mid);
	}
}

void sort(vector<int> &v, size_t left, size_t right, size_t mid)
{
	size_t l = left;
	size_t r = mid+1;
	vector<int> tmp;

	while (l <= mid && r <= right)
	{
		if (v.at(l) <= v.at(r))
		{
			tmp.push_back(v.at(l));
			l++;
		}
		else
		{
			tmp.push_back(v.at(r));
			r++;
		}
	}
	while (l <= mid)
	{
		tmp.push_back(v.at(l));
		l++;
	}

	while (r <= right)
	{
		tmp.push_back(v.at(r));
		r++;
	}

	size_t i = left;
	while (!tmp.empty()) {
		v[i++] = tmp.front();
		tmp.erase(tmp.begin());
	}
	
}

int main()
{
//vector
	vector<int> v;
// vector size
	size_t size = 5000;
// fill vector
	for (unsigned i = 0; i < size; i++)
		v.push_back(i);
// shuffling vector data		
	random_shuffle( v.begin(), v.end());

	for (auto i : v)
		cout << i << " ";
	cout << endl;

// choose sorting

	//mergeSort(v, 0, size - 1);
	//bubbleSort(v);
	//insertionSort(v);
	//shellsSort(v);

// results	
	for (auto i : v)
		cout << i << " ";
	cout << endl;

	system("PAUSE");
	return 0;
}