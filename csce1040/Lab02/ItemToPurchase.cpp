#include "ItemToPurchase.h"

void ItemToPuchase::SetName(string name) {
	itemName = name;
}
void ItemToPuchase::SetPrice(int price) {
	itemPrice = price;
}
void ItemToPuchase::SetName(int quantity) {
	itemQuantity = quantity;
}

string ItemToPurchase::GetName() const {
	return itemName;
}
int ItemToPuchase::GetPrice() const {
	return itemPrice;
}
int ItemToPurchase::GetQuantity() const {
	return itemQuantity;
}


