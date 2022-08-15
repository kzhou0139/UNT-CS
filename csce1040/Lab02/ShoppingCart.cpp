#include "ShoppingCart.h"

void ShoppingCart::GetCustomerName() const {
	return customerName;
}
void ShoppingCart::GetDate() const {
	return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase item) {
	cartItems.push_back(item);
}
void ShoppingCart::RemoveItem(string name) {
	int found = 0;
	for (int i = 0; i < (int)cartItems.size(); i++) {
		if (cartItems.at(i).GetName().compare(name) == 0) {
			cartItems.erase(cartItems.begin()+i);
			found = 1;
		}
	}
	if (found == 0)
		cout<<"Item not found in cart. Nothing removed."<<endl;
}
void ShoppingCart::ModifyItem(ItemToPurchase item) {
	int found = 0;
	for (int i = 0; i < (int)cartItems.size(); i++) {
		if (cartItems.at(i).GetName().compare(item.GetName()) == 0) {
			found = 1;
			if (cartItems.at(i).GetPrice() != item.GetPrice())
				cartItems.at(i).SetPrice(item.GetPrice());
			if (cartItems.at(i).GetQuantity() != item.GetQuantity())
				cartItems.at(i).SetQuantity(item.GetQuantity());
		}
	}
	if (found == 0)
		cout<<"Item not found in cart. Nothing modified."<<endl;
}

void ShoppingCart::GetNumItemsInCart() {
	int total = 0;
	for (int i = 0; i < (int)cartItems.size(); i++) 
		total += cartItems.at(i).GetQuantity();
	return total;
}
void ShoppingCart::GetCostOfCart() {
	int total = 0;
	for (int i = 0; i < (int)cartItems.size(); i++)
		total += cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity();
	return total;
}

void ShoppingCart::PrintTotal() {
	int total = 0;
	for (int i = 0; i < (int)cartItems.size(); i++) {
		cout<<cartItems.at(i).GetName()<<" "<<cartItems.at(i).GetQuantity()<<" @ $"<<cartItems.at(i).GetPrice()<<" = $"<<cartItems.at(i).GetQuantity() * artItems.at(i).GetPrice()<<endl;
		total += cartItems.at(i).GetQuantity() * artItems.at(i).GetPrice();
	}
	cout<<endl;
	cout<<"Total: $"<<total;
}
void ShoppingCart::PrintDescription() {
	cout<<"Item Descriptions"<<endl;
	for (int i = 0; i < (int)cartItems.size()<< i++)
		cout<<cartItems.at(i).GetName()<<": "<<cartItems.at(i).GetDescription()<<endl;
}