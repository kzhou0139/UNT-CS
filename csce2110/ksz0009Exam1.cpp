//Kelly Zhou
//ksz0009
//ksz0009Exam1.cpp
//Circular linked, selection sort

#include <iostream>
using namespace std;

//creates Node struct
struct Node {
	int data;
	Node *next;
};

//performs selection sort algorithm
Node* selectionSort(Node* head) {
	Node *a, *b, *c, *d, *r;
	a = b = head;
	while (b->next) {
		c = d = b->next;
		while (d) {
			if (b->data > d->data) {
				if (b->next == d) {
					if (b == head) {
						b->next = d->next;
						d->next = b;
						r = b;
						b = d;
						d = r;
						c = d;
						head = b;
						d = d->next;
					}
					else {
						b->next = d->next;
						d->next = b;
						a->next = d;
						r = b;
						b = d;
						d = r;
						c = d;
						d = d->next;
					}
				}
				else {
					if (b == head) {
						r = b->next;
						b->next = d->next;
						d->next = r;
						c->next = b;
						r = b;
						b = d;
						d = r;
						c = d;
						d = d->next;
						head = b;
					}
					else {
						r = b->next;
						b->next = d->next;
						d->next = r;
						c->next = b;
						a->next = d;
						r = b;
						b = d;
						d = r;
						c = d;
						d = d->next;
					}
				}
			}
			else {
				c = d;
				d = d->next;
			}
		}
		a = b;
		b = b->next;
	}
	return head;
}

//finds key then deletes the node with that key
void deleteNode (Node** head, int key) {
	Node* temp;
	if ((*head)->data == key) {
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	else {
		Node* current = *head;
		while (current->next != NULL) {
			if (current->next->data == key) {
				temp = current->next;
				current->next = current->next->next;
				free(temp);
				break;
			}
			else
				current = current->next;
		}
	}
}

//prints list
void printList (Node* n) {
	while (n != NULL) {
		cout << n->data << " -> ";
		n = n->next;
	}
	cout << endl;
}

//prepends element to list
void push(Node** head_ref, int new_data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

int main() {
	Node* head = NULL;
	int insNum = 0;
	while (insNum != -1) {
		cout << "Enter a positive number to insert into the linked list (Enter -1 when you're done): ";
		cin >> insNum;
		if (insNum != -1)
			push(&head, insNum);
	}
	cout << "Linked list:" << endl;
	printList(head);
	cout << "Enter a number from the linked list to delete: ";
	int delNum = 0;
	cin >> delNum;
	deleteNode(&head, delNum);
	cout << "Linked list after deleting number:" << endl;
	printList(head);
	cout << endl;
	cout << "Linked list before sorting: " << endl;
	printList(head);
	head = selectionSort(head);
	cout << "Linked list after sorting: " << endl;
	printList(head);
	return 0;
}
