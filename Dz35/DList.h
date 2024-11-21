#pragma once
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class DNode {
public:
	T info;
	DNode* prev;
	DNode* next;

	DNode(T value) { info = value; next= prev = nullptr; }
	void showDNode() {
		cout << "INFO: " << info<<endl;
		cout << "\tPREV: " << prev << endl;
		cout << "\tNEXT: " << next << endl;
	}
};
template <typename T>
class DList {
	DNode<T>* head;
	DNode<T>* current;
public:
	DList() { head = current = nullptr; }
	~DList() {
		DNode<T>* p = head;
		DNode<T>* pdel = head;
		while (p != nullptr) {
			cout << "Del: " << p->info << endl;
			pdel = p;
			p = p->next;
			if (pdel != nullptr)
			{
				delete pdel;
			}
		}
	}

	void push_back(T value) {
		DNode<T>* el = new DNode<T>(value);
		if (head == nullptr) {
			head = el;
			current = el;
		}
		else {
			current->next = el;
			el->prev = current;
			current = el;
		}
	}
	void push_front(T value) {
		DNode<T>* el = new DNode<T>(value);
		if (head == nullptr) {
			head = el;
			current = el;
		}
		else {
			head->prev = el;
			el->next = head;
			head = el;
		}
	}
	void showList() {
		DNode<T>* p = head;
		while (p != nullptr) {
			p->showDNode();
			p = p->next;
		}
		cout << endl; 
	}

	void showRList() {
		DNode<T>* p = current;
		while (p != nullptr) {
			p->showDNode();
			p = p->prev;
		}
		cout << endl;
	}
	
	DNode<T>* search(T value) {
		DNode<T>* p = head;
		while (p != nullptr) {
			if (p->info == value)
			{
				return p;
			}
			p = p->next;
		}
		return nullptr;
	}
	void push_front_value(T value1, T value) {
		DNode<T>* s = search(value1);
		if (s == nullptr) {
			cout << "Error!!!\n";
		}
		else {
			DNode<T>* el = new DNode<T>(value);
			el->next = s;
			el->prev = s->prev;
			if (s->prev!=nullptr)
			{
				s->next = el;
			}
			else
			{
				head = el;
			}
			s->prev = el;
		}
	}
	void push_back_value(T value1, T value) {
		DNode<T>* s = search(value1);
		if (s == nullptr) {
			cout << "Error!!!\n";
		}
		else {
			DNode<T>* el = new DNode<T>(value);
			el->prev = s;
			el->next = s->next;
			if (s->next !=nullptr)
			{
				s->prev = el;
			}
			else
			{
				current = el;
			}
			s->next = el;
		}
	}
	void erase(T value) {
		DNode<T>* s = search(value);
		if (s==nullptr)
		{
			cout << "Error!!!\n";
			return;
		}
		if (s->prev != nullptr)
		{
			s->prev->next = s->next;
		}
		else
		{
			head = s->next;
		}
		if (s->next != nullptr)
		{
			s->next->prev = s->prev;
		}
		delete s;
	}
};