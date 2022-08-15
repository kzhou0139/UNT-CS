class ItemToPurchase() {
	private:
		string itemName;
		int itemPrice;
		int itemQuantity;
		string itemDescription;

	public:
		ItemToPurchase() {
			itemName = "none";
			itemDescription = "none";
			itemPrice = 0;
			itemQuantity = 0;
		}

		ItemToPurchase(string name, string description, int price, int quantity) {
			itemDescription = description;
			itemName = name;
			itemPrice = price;
			itemQuantity = quantity;
		}

		void setDescription(string description);
		void SetName(string name);
		void SetPrice(int price);
		void SetQuantity(int quantity);
		string GetDecription() const;
		string GetName() const;
		int GetPrice() const;
		int GetQuantity() const;

		void PrintItemCost();
		void PrintItemDescription();
};