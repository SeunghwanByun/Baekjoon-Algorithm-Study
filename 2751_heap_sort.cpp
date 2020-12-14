#include <iostream>
#include <vector>
#include <algorithm>

void push_heap(std::vector<int>& heap, int Value) {
	heap.push_back(Value);

	int index = heap.size() - 1;

	while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
		std::swap(heap[index], heap[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
}

void pop_heap(std::vector<int>& heap) {
	heap[0] = heap.back();
	heap.pop_back();
	int here = 0;
	while (true) {
		int left = here * 2 + 1, right = here * 2 + 2;
		if (left >= heap.size()) break;
		int next = here;
		if (heap[next] < heap[left]) next = left;
		if (right < heap.size() && heap[next] < heap[right]) next = right;
		if (next == here) break;
		std::swap(heap[here], heap[next]);
		here = next;
	}
}

void sort_heap(std::vector<int>& heap) {
	for (int count = 1; count < heap.size(); count++) {
		std::swap(heap[heap.size() - count], heap[0]);
		int here = 0;
		while (true) {
			int left = here * 2 + 1, right = here * 2 + 2;
			if (left >= heap.size() - count) break;
			int next = here;
			if (heap[next] < heap[left]) next = left;
			if (right < heap.size() - count && heap[next] < heap[right]) next = right;
			if (next == here) break;
			std::swap(heap[here], heap[next]);
			here = next;
		}
	}
}

int main() {
	int N;
	std::cin >> N;

	std::vector<int> heap;
	for (int i = 0; i < N; i++) {
		int temp;
		std::cin >> temp;
		push_heap(heap, temp);
	}

	sort_heap(heap);

	for (auto content : heap)
		std::cout << content << "\n";

	return 0;
