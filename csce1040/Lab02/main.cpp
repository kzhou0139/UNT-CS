#include <iostream>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"
using namespace std;

void PrintMenu() {
	cout<<"MENU"<<endl;
	cout<<"a - Add item to cart"<<endl;
	cout<<"d - Remove item from cart"<<endl;
	cout<<"c - Change item quantity"<<endl;
	cout<<"i - Output items' descriptions"<<endl;
	cout<<"o - Output shopping cart"<<endl;
	cout<<"q - Quit"<<endl;
}

void ExecuteMenu(char c, ShoppingCart &theCart) {
	if (c == 'q')
		exit(EXIT_RETURN);
	if (c == 'a') {
		cout<<"ADD ITEM TO CART"<<endl;
		string name;
		cout<<"Enter the item name:"<<endl;
		cin.ignore();
		getline(cin, name);
		string description;
		cout<<"Enter the item description:"<<endl;
		getline(cin, description);
		int price;
		cout<<"Enter the item price:"<<endl;
		cin >> price;
		int quantity;
		cout<<"Enter the item quantity:"<<endl;
		cin >> quantity;
		ItemToPurchase item(name, description, price, quantity);
		theCart.AddItem(item);
	}
	if (c == 'd') {
		cout<<"REMOVE ITEM FROM CART"<<endl;
		string name;
		cout<<"Enter name of item to remove:"<<endl;
		cin.ignore();
		getline(cin, name);
		theCart.RemoveItem(name);
	}
	if (c == 'c') {
		cout<<"CHANGE ITEM QUANTITY"<<endl;
		string name;
		cout<<"Enter the item name:"<<endl;
		cin.ignore();
		getline(cin, name);
		int quantity;
		cout<<"Enter the new quantity:"<<endl;
		cin >> quantity;
		theCart.ModifyItem(name);
	}
	if (c == 'i') {
		cout << "OUTPUT ITEMS' DESCRIPTIONS"<<endl;
		cout << "John Doe's Shopping Cart - February 1, 2016"<<endl;
		cout<<endl;
		theCart.PrintDescriptions();
	}
	if (c == 'o') {
		cout<<"OUTPUT SHOPPING CART"<<endl;
		cou<<"John Doe's Shopping Cart - February 1, 2016"<<endl;
		cout<<theCart.GetNumItemsInCart();
		cout<<endl;
		theCart.PrintTotal();
	}
} 

int main() {
	/*cout<<"Item 1"<<endl;
	string name;
	cout<<"Enter the item name:"<<endl;
	cin.ignore();
	getline(cin,name);
	int price;
	cout<<"Enter the item price:"<<endl;
	cin>>price;
	int quantity;
	cout<<"Enter the item quantity:"<<endl;
	cin>>quantity;
	ItemToPurchase item1(name, price, quantity);
	cout<<endl;

	cout<<"Item 2"<<endl;
	cout<<"Enter the item name:"<<endl;
	cin.ignore();
	getline(cin,name);
	int price;
	cout<<"Enter the item price:"<<endl;
	cin>>price;
	int quantity;
	cout<<"Enter the item quantity:"<<endl;
	cin>>quantity;
	ItemToPurchase item1(name, price, quantity);

	cout<<"TOTAL COST"<<endl;
	cout<<item1.GetName()<<" "<<item1.GetQuantity<<" @ $"<<item1.GetPrice()<<" = $"<<item1.GetQuantity() * item1.GetPrice()<<endl;
	cout<<item2.GetName()<<" "<<item2.GetQuantity<<" @ $"<<item2.GetPrice()<<" = $"<<item2.GetQuantity() * item2.GetPrice()<<endl;
	cout<<endl;
	cout<<"Total: $"<<((item1.GetQuantity() * item1.GetPrice()) + (item2.GetQuantity() * item2.GetPrice()));*/

	string name;
	cout<<"Enter customer's name:"<<endl;
	cin.ignore();
	getline(cin, name);
	string date;
	cout<<"Enter today's date:"<<endl;
	getline(cin, date);
	ShoppingCart cart(name, date);
	cout<<endl;

	cout<<"Customer name: "<<name;
	cout<<"Today's date: "<<date;

	char choice = '!';
	while (choice != 'q') {
		PrintMenu();
		cout<<endl;
		cout<<"Choose an option:"<<endl;
		cin >> choice;
		while (choice != 'a' && choice != 'd' choice != 'c' && choice != 'i' && choice != 'o' && choice != 'q') {
			cout<<"Choose an option:"<<endl;
			cin>>choice;
		}
		ExecuteMenu(choice, cart);
	}


	return 0;
}