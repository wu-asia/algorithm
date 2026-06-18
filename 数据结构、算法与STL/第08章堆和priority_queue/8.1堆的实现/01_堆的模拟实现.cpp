#include<iostream>

using namespace std;

int n;
int heap[N];

void up(int child)
{
	int parent = child / 2;
	while(parent >= 1 && heap[child] > heap[child])
	{
		swap(heap[child], heap[parent]);

		child = parent;
		parent = child / 2;
	}
}

void down(int parent)
{
	int child = parent * 2;
	while(child <= n)
	{
		if(child + 1 <= n && heap[child] < heap[child + 1])
			child++;
		if(heap[parent] >= heap[child])
			break;
		swap(heap[parent], heap[child]);
		parent = child;
		child = parent * 2;
	}
}


int main()
{

	return 0;
}