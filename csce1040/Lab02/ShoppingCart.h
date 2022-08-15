#include <vector>

class ShoppingCart() {
	private:
		string customerName;
		string currentDate;
		vector<ItemToPurchase> cartItems;

	public:
		ShoppingCart() {
			customerName = "none";
			currentDate = "January 1, 2016";
		}
		ShoppingCart(string name, string date) {
			customerName = name;
			currentDate = date;
		}
		void GetCustomerName() const;
		void GetDate() const;
		void AddItem();
		void RemoveItem();
		void ModifyItem();
		void GetNumItemsInCart();
		void GetCostOfCart();
		void PrintTotal();
		void PrintDescriptions();

};