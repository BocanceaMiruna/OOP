#pragma once
template <typename T>
class Tree {
	T val;
	int fiicnt;
	int cap;
	Tree<T>** fii;
public:
	Tree(T v) {
		val = v;
		fiicnt = 0;
		cap = 2;
		fii = new Tree<T>*[cap];
	}
	~Tree() {
		delete[] fii;
	}
	static Tree<T>* addnode(Tree<T>* parent, T val) {
		Tree<T> *newnode = new Tree<T> (val);
		if (parent == nullptr)
			return newnode;
		if (parent->fiicnt == parent->cap) {
			parent->cap *= 2;
			Tree<T>** nou = new Tree<T>*[parent->cap];
			for (int i = 0; i < parent->fiicnt; i++)
				nou[i] = parent->fii[i];
			delete[]parent->fii;
			parent->fii = nou;
		}
		parent->fii[parent->fiicnt++] = newnode;
	}
	Tree<T> *get_node() {
		return this;
	}
	T get_value(){
		return val;
	}
	int count() {
		int total = fiicnt;
		for (int i = 0; i < fiicnt; i++)
			total += fii[i]->count();
		return total;
	}
	static void delete_node(Tree <T>* node) {
		if (node == nullptr) return;
		for (int i = 0; i < node->fiicnt; i++)
			delete_node(node->fii[i]);
		delete node;
	}
	static Tree<T>* insert(Tree<T>* parent, int idx, T val) {
		if (parent == nullptr || idx < 0 || idx > parent->fiicnt)
			return nullptr;
		Tree<T>* newNode = new Tree<T>(val);
		if (parent->fiicnt == parent->cap) {
			parent->cap *= 2;
			Tree<T>** nou = new Tree<T>*[parent->cap];
			for (int i = 0; i < parent->fiicnt; i++)
				nou[i] = parent->fii[i];
			delete[] parent->fii;
			parent->fii = nou;
		}
		for (int i = parent->fiicnt; i > idx; i--)
			parent->fii[i] = parent->fii[i - 1];
		parent->fii[idx] = newNode;
		parent->fiicnt++;
		return newNode;
	}
	static Tree<T>* find(Tree<T>* current, T search_val, bool (*cmp)(T, T)) {
		if (current == nullptr || cmp == nullptr)
			return nullptr;
		if (cmp(current->val, search_val)) 
			return current;
		for (int i = 0; i < current->fiicnt; i++) {
			Tree<T>* result = find(current->fii[i], search_val, cmp);
			if (result != nullptr)
				return result;
		}
		return nullptr;
	}
	void sort(bool (*cmp)(T, T)) {
		if (fiicnt < 2) 
			return;
		for (int i = 0; i < fiicnt - 1; i++) 
			for (int j = i + 1; j < fiicnt; j++) {
				bool swap_needed = false;
				if (cmp != nullptr)
					if (cmp(fii[j]->val, fii[i]->val)) swap_needed = true;
				else if (fii[j]->val < fii[i]->val) 
					swap_needed = true;
				if (swap_needed) {
					Tree<T>* temp = fii[i];
					fii[i] = fii[j];
					fii[j] = temp;
				}
			}
	}
};