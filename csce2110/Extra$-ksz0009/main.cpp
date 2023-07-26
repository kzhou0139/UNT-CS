//Kelly Zhou
//ksz0009
//main.cpp

#include <iostream>
#include <string>
#include "node.h"
using namespace std;

class Stack {
	private:
		Node* top;
		int num;
	public:
		Stack() {
			top = nullptr;
		}

		int getInt() {
			return num;
		}

		void setInt(int n) {
			num = n;
		}

		bool isEmpty() {
			return top == nullptr;
		}

		void push (int value) {
			Node *newNode = new Node;
			newNode->data = value;
			newNode->next = top;
			top = newNode;
		}

		void pop () {
			if (isEmpty()) {
				cout << "Stack is empty!" << endl;
				return;
			}
			Node* temp = top;
			top = top->next;
			delete temp;
		}

		int peek () {
			if (isEmpty()) {
				cout << "Stack is empty!" << endl;
				return -1;
			}
			return top->data;
		}

		void display() {
			if (isEmpty())
				cout << "Stack is empty!" << endl;
			Node* temp = top;
			while (temp != nullptr) {
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
};

int main() {
	Stack s;
	int input;

	while (true) {
		cout << "Enter a positive number to push: " << endl;
		cin >> input;
		if (input < 0)
			break;
		else {
			s.push(input);
			cout << input << " added to stack" << endl;
		}
	}

	int popNum;
	cout << "How many numbers do you want to pop?" << endl;
	cin >> popNum;
	for (int i = 0; i < popNum; i++) {
		int val = s.peek();
		s.pop();
		cout << val << "removed from stack" << endl;
	}

	s.display();

	return 0;
}
