#include <iostream>
#include <string>

using namespace std;
// this string takes the user answer for the (y/n) questions//
string answer2;

int Answer, itemNumber = 4, Current_ID, itemNum, itemSellnum, s, cntr = 0;

bool  valid_id = true, valid_itemNum = true, valid_item_number = true, Is_price_or_Category = true, Confirm_buying = true;
// address of members//
struct address 
{
	string city;
	string area;
	string street;
	string house_number;
	string floor;
	string apartment_number;
};
//start and end dates for each item//
struct item_date 
{
	int day;
	int month;
	int year;
};
// members data//
struct members_Informations 
{
	int id;
	string Email;
	string name;
	string password;
	address add;
	int phone_Number;
	int points;
} member[4];
// it contains the sales of each category//
struct report 
{
	int car_sales = 0;
	int mobile_sales = 0;
	int laptops_sales = 0;
	int furniture_sales = 0;
} months[13];
// items data//
struct items 
{
	string itemName;
	int item_number;
	string item_category;
	item_date start_date;
	item_date end_date;
	int start_bid_Price;
	int item_suggested_price = 0;
	string status;
	int seller_ID;
	int buyer_ID;
	int Seller_accepet = 2;
} item[1000];
// this function confirms the buying request//
bool Buying_function()
{
	while (true) 
	{
		cout << "Do you want to use  your usual delivery address and phone number?,write(y/n)." << endl;
		cin >> answer2;
		if (answer2 == "y")
		{
			cout << "Confirm the buying request? write(y/n)." << endl;
			cin >> answer2;
			if (answer2 == "y")
			{
				cout << "Congratulations!,your request has been sent to the seller!,Please check your buying requests for seller respond!" << endl;
				cout << string(60, '*') << endl;
				cout << "Thank you for using the online acution application!" << endl;
				cout << string(60, '*') << endl;
				Confirm_buying = true;
				return Confirm_buying;
				break;
			}
			else if (answer2 == "n")
			{
				Confirm_buying = false;
				return Confirm_buying;
			}
			else
			{
				cout << "Invalid input!" << endl;
			}
		}
		else if (answer2 == "n")
		{
			cout << "Please write the delivery address you want:" << endl;
			cout << "Address:" << endl;
			cout << "City:\t";
			cin >> member[Current_ID - 1].add.city;
			cout << "Area:\t";
			cin >> member[Current_ID - 1].add.area;
			cout << "Street:\t";
			cin >> member[Current_ID - 1].add.street;
			cout << "House number:\t";
			cin >> member[Current_ID - 1].add.house_number;
			cout << "Floor:\t";
			cin >> member[Current_ID - 1].add.floor;
			cout << "Apartment number:\t";
			cin >> member[Current_ID - 1].add.apartment_number;
			cout << endl << "Phone number:\t";
			cin >> member[Current_ID - 1].phone_Number;
			cout << "Confirm the buying request? write(y/n)." << endl;
			cin >> answer2;
			if (answer2 == "y")
			{
				cout << "Congratulations!,your request has been sent to the seller!,Please check your buying requests for seller respond!" << endl;
				cout << string(60, '*') << endl;
				cout << "Thank you for using the online acution application!" << endl;
				cout << string(60, '*') << endl;
				Confirm_buying = true;
				return Confirm_buying;
				break;
			}
			else if (answer2 == "n")
			{
				Confirm_buying = false;
				return Confirm_buying;
			}
			else
			{
				cout << "Invalid input!" << endl;
			}
		}
		else
		{
			cout << "Invalid input!" << endl;
		}
	}
}
// this function checks if the buyer want to add a suggested price or not//
void buying_vladiation(int l)
{
	while (true) 
	{
		cout << "Do you want to buy this item with this price?,write(y/n)." << endl;
		cout << "To log out and cancel the buying process,Please enter 0." << endl;
		cin >> answer2;
		if (answer2 == "y") 
		{
			Buying_function();
			if (Confirm_buying == true) 
			{
				item[l].buyer_ID = Current_ID;
				item[l].status = "Requsted for buying";
				
				break;
			}
			else 
			{
				break;
			}
		}
		else if (answer2 == "n")
		{
			cout << "Write your suggested price:\t";
			cin >> item[l].item_suggested_price;
			Buying_function();
			if (Confirm_buying == true)
			{
				item[l].buyer_ID = Current_ID;
				item[l].status = "Requsted for buying";
				break;
			}
			else
			{
				break;
			}
		}
		else if (answer2 == "0") 
		{
			cout << string(60, '*') << endl;
			cout << "Thank you for using the online acution application!" << endl;
			cout << string(60, '*') << endl;
			return;
		}
		else 
		{
			cout << "Invalid answer!" << endl;
		}
	}

}
// this function checks if the user want to search by category or category and price and also display the items of the selected category//
void Buying_by_category_and_or_price()
{
	int price;
	bool valid_price = true;
	while (true)
	{
		cntr = 0;
		cout << "Please select one of the following categories of the item you want to buy:\n"
		<< "[1] Cars\n" << "[2] Mobiles\n" << "[3] Laptops\n" << "[4] Furniture\n" << "Category number:\t";
		cin >> Answer;
		if (!Is_price_or_Category)
		{
			while (true)
			{
				cout << "If you want to go back enter 0" << endl << "Please write the price you are looking for!" << endl;
				cout << "Price:\t\t";
				cin >> price;
				if (price == 0)
				{
					return;
				}
				for (int p = 0; p < itemNumber; p++)
				{
					if (item[p].start_bid_Price != price)
					{
						valid_price = false;
					}
					else
					{
						valid_price = true;
						break;
					}
				}
				if (valid_price == false)
				{
					cout << "Sorry,There is no item found with this price!" << endl;
				}
				else
				{
					break;
				}
			}
		}
		switch (Answer)
		{
		case 1:
			for (int i = 0; i < itemNumber; i++)
			{
				if (item[i].item_category == "cars" && item[i].status == "Avalabile" && item[i].seller_ID != Current_ID)
				{
					cntr++;
				}
			}
			if (cntr == 0)
			{
				cout << endl << "There is no items for selling in this category yet! " << endl;
				cout << string(100, '*') << endl;
			}
			else
			{
				cout << "Here are the cars found:" << endl;
				cout << "Item number:" << "\t" << "Item name:" << "\t" << "Item start bid price:" << "\t" << "Item status:" << "\t" << "Item start date:" << "     " << "Item end date:" << "\t" << "SellerID" << endl;
				for (int j = 0; j < itemNumber; j++)
				{
					if (!Is_price_or_Category)
					{
						if (item[j].item_category == "cars" && item[j].start_bid_Price == price && item[j].status == "Avalabile" && item[j].seller_ID != Current_ID)
						{

							cout << item[j].item_number << "\t\t" << item[j].itemName << "\t\t" << item[j].start_bid_Price << "\t\t" << item[j].status << "\t";
							cout << item[j].start_date.day << "/" << item[j].start_date.month << "/" << item[j].start_date.year << "\t     ";
							cout << item[j].end_date.day << "/" << item[j].end_date.month << "/" << item[j].end_date.year << "\t    " << item[j].seller_ID << endl;
						}
					}
					else
					{
						if (item[j].item_category == "cars" && (item[j].status == "Avalabile") && item[j].seller_ID != Current_ID)
						{
							cout << item[j].item_number << "\t\t" << item[j].itemName << "\t\t" << item[j].start_bid_Price << "\t\t" << item[j].status << "\t";
							cout << item[j].start_date.day << "/" << item[j].start_date.month << "/" << item[j].start_date.year << "\t     ";
							cout << item[j].end_date.day << "/" << item[j].end_date.month << "/" << item[j].end_date.year << "\t\t" << item[j].seller_ID << endl;
						}
					}
				}
				while (true)
				{
					cout << "Please write the item number you wish to buy:" << endl;
					cin >> itemNum;
					for (int l = 0; l < itemNumber; l++)
					{
						if (item[l].item_number == itemNum)
						{
							if (item[l].item_category == "cars" && item[l].status == "Avalabile")
							{
								buying_vladiation(l);
								valid_itemNum = false;
							}
						}
					}
					if (valid_itemNum == true)
					{
						cout << "item not avalabile! or this item is not in this category! " << endl;
					}
					else
					{
						break;
					}
				}
			}
			break;
		case 2:
			for (int i = 0; i < itemNumber; i++)
			{
				if (item[i].item_category == "mobiles" && item[i].status == "Avalabile" && item[i].seller_ID != Current_ID)
				{
					cntr++;
				}
			}
			if (cntr == 0)
			{
				cout << endl << "There is no items for selling in this category yet! " << endl;
				cout << string(100, '*') << endl;
				return;

			}
			else
			{
				cout << "Here are the mobile phones found:" << endl;
				cout << "Item number:" << "\t" << "Item name:" << "\t" << "Item start bid price:" << "\t" << "Item status:" << "\t" << "Item start date:" << "     " << "Item end date:" << "\t" << "SellerID" << endl;				
				for (int j = 0; j < itemNumber; j++)
				{
					if (!Is_price_or_Category)
					{
						if (item[j].item_category == "mobiles" && item[j].start_bid_Price == price && item[j].status == "Avalabile" && item[j].seller_ID != Current_ID)
						{

							cout << item[j].item_number << "\t\t" << item[j].itemName << "\t\t" << item[j].start_bid_Price << "\t\t" << item[j].status << "\t";
							cout << item[j].start_date.day << "/" << item[j].start_date.month << "/" << item[j].start_date.year << "\t     ";
							cout << item[j].end_date.day << "/" << item[j].end_date.month << "/" << item[j].end_date.year << "\t    " << item[j].seller_ID << endl;
						}
					}
					else
					{
						if (item[j].item_category == "mobiles" && (item[j].status == "Avalabile") && item[j].seller_ID != Current_ID)
						{
							cout << item[j].item_number << "\t\t" << item[j].itemName << "\t\t" << item[j].start_bid_Price << "\t\t" << item[j].status << "\t";
							cout << item[j].start_date.day << "/" << item[j].start_date.month << "/" << item[j].start_date.year << "\t     ";
							cout << item[j].end_date.day << "/" << item[j].end_date.month << "/" << item[j].end_date.year << "\t    " << item[j].seller_ID << endl;
						}
					}
				}
				while (true)
				{
					cout << "Please write the item number you wish to buy:" << endl;
					cin >> itemNum;
					for (int l = 0; l < itemNumber; l++)
					{
						if (item[l].item_number == itemNum)
						{
							if (item[l].item_category == "mobiles" && item[l].status == "Avalabile")
							{
								buying_vladiation(l);
								valid_itemNum = false;
							}
						}
					}
					if (valid_itemNum == true)
					{
						cout << "item not avalabile! or this item is not in this category! " << endl;

					}
					else
					{
						break;
					}
				}
			}
			break;
		case 3:
			for (int i = 0; i < itemNumber; i++)
			{
				if (item[i].item_category == "laptops" && item[i].status == "Avalabile" && item[i].seller_ID != Current_ID)
				{
					cntr++;
				}
			}
			if (cntr == 0)
			{
				cout << endl << "There is no items for selling in this category yet! " << endl;
				cout << string(100, '*') << endl;
				return;
			}
			else
			{
				cout << "Here are the laptops found:" << endl;
				cout << "Item number:" << "\t" << "Item name:" << "\t" << "Item start bid price:" << "\t" << "Item status:" << "\t" << "Item start date:" << "     " << "Item end date:" << "\t" << "SellerID" << endl;				
				for (int j = 0; j < itemNumber; j++)
				{
					if (!Is_price_or_Category)
					{
						if (item[j].item_category == "laptops" && item[j].start_bid_Price == price && item[j].status == "Avalabile" && item[j].seller_ID != Current_ID)
						{

							cout << item[j].item_number << "\t\t" << item[j].itemName << "\t\t" << item[j].start_bid_Price << "\t\t" << item[j].status << "\t";
							cout << item[j].start_date.day << "/" << item[j].start_date.month << "/" << item[j].start_date.year << "\t     ";
							cout << item[j].end_date.day << "/" << item[j].end_date.month << "/" << item[j].end_date.year << "\t    " << item[j].seller_ID << endl;
						}
					}
					else
					{
						if (item[j].item_category == "laptops" && (item[j].status == "Avalabile") && item[j].seller_ID != Current_ID)
						{
							cout << item[j].item_number << "\t\t" << item[j].itemName << "\t\t" << item[j].start_bid_Price << "\t\t" << item[j].status << "\t";
							cout << item[j].start_date.day << "/" << item[j].start_date.month << "/" << item[j].start_date.year << "\t     ";
							cout << item[j].end_date.day << "/" << item[j].end_date.month << "/" << item[j].end_date.year << "\t    " << item[j].seller_ID << endl;
						}
					}
				}
				while (true)
				{
					cout << "Please write the item number you wish to buy:" << endl;
					cin >> itemNum;
					for (int l = 0; l < itemNumber; l++)
					{
						if (item[l].item_number == itemNum)
						{
							if (item[l].item_category == "laptops" && item[l].status == "Avalabile")
							{
								buying_vladiation(l);
								valid_itemNum = false;
							}
						}
					}
					if (valid_itemNum == true)
					{
						cout << "item not avalabile! or this item is not in this category! " << endl;
					}
					else
					{
						break;
					}
				}
			}
			break;
		case 4:
			for (int i = 0; i < itemNumber; i++)
			{
				if (item[i].item_category == "furniture" && item[i].status == "Avalabile" && item[i].seller_ID != Current_ID)
				{
					cntr++;
				}
			}
			if (cntr == 0)
			{
				cout << endl << "There is no items for selling in this category yet! " << endl;
				cout << string(100, '*') << endl;
				return;
			}
			else
			{
				cout << "Here are the furniture found:" << endl;
				cout << "Item number:" << "\t" << "Item name:" << "\t" << "Item start bid price:" << "\t" << "Item status:" << "\t" << "Item start date:" << "     " << "Item end date:" << "\t" << "SellerID" << endl;				
				for (int j = 0; j < itemNumber; j++)
				{
					if (!Is_price_or_Category)
					{
						if (item[j].item_category == "furniture" && item[j].start_bid_Price == price && item[j].status == "Avalabile" && item[j].seller_ID != Current_ID)
						{

							cout << item[j].item_number << "\t\t" << item[j].itemName << "\t\t" << item[j].start_bid_Price << "\t\t" << item[j].status << "\t";
							cout << item[j].start_date.day << "/" << item[j].start_date.month << "/" << item[j].start_date.year << "\t     ";
							cout << item[j].end_date.day << "/" << item[j].end_date.month << "/" << item[j].end_date.year << "\t    " << item[j].seller_ID << endl;
						}
					}
					else
					{
						if (item[j].item_category == "furniture" && (item[j].status == "Avalabile") && item[j].seller_ID != Current_ID)
						{
							cout << item[j].item_number << "\t\t" << item[j].itemName << "\t\t" << item[j].start_bid_Price << "\t\t" << item[j].status << "\t";
							cout << item[j].start_date.day << "/" << item[j].start_date.month << "/" << item[j].start_date.year << "\t     ";
							cout << item[j].end_date.day << "/" << item[j].end_date.month << "/" << item[j].end_date.year << "\t    " << item[j].seller_ID << endl;
						}
					}
				}
				while (true)
				{
					cout << "Please write the item number you wish to buy:" << endl;
					cin >> itemNum;
					for (int l = 0; l < itemNumber; l++)
					{
						if (item[l].item_number == itemNum)
						{
							if (item[l].item_category == "furniture" && item[l].status == "Avalabile")
							{
								buying_vladiation(l);
								valid_itemNum = false;
							}
						}
					}
					if (valid_itemNum == true)
					{
						cout << "item not avalabile! or this item is not in this category! " << endl;
					}
					else {
						break;
					}
				}
			}
			break;
		default:
			cout << "Invalid input!" << endl;
			break;
		}
		break;
	}
}
// this function display the buying requests the buyer made//
void buyer_requests()
{
	cntr = 0;
	cout << "Your buying requests:" << endl;
	for (int i = 0; i < itemNumber; i++)
	{
		if (item[i].status == "Requsted for buying" && item[i].buyer_ID == Current_ID)
		{
			cntr++;
		}
	}
	s = cntr - (cntr - 1);
	cout << "You have\t" << cntr << "\tnew requests!" << endl;
	if (cntr == 0)
	{
		cout << "You have no requests at the moment!" << endl;
	}
	else
	{
		for (int i = 0; i < itemNumber; i++)
		{
			if ((item[i].status == "Requsted for buying" && item[i].buyer_ID == Current_ID) || (item[i].buyer_ID == Current_ID && (item[i].Seller_accepet == 0 || item[i].Seller_accepet == 1)))
			{
					cout << string(100, '*') << endl;
					cout << "Request Number:\t" << s << "\tTo member:\t" << member[item[i].seller_ID - 1].name << endl;
					cout << "item number:\t" << "item name:\t" << "Starting bid price:\t" << "Suggested price:\t" << "Seller ID" << endl;
					cout << item[i].item_number << "\t\t" << item[i].itemName << "\t\t" << item[i].start_bid_Price << "\t\t";
					if (item[i].item_suggested_price != 0) 
					{
						cout << item[i].item_suggested_price << "\t\t";
					}
					else
					{
						cout << "No suggested price" << "\t";
					}
					cout << item[i].seller_ID << endl;
					s++;
					if (item[i].Seller_accepet == 1)
					{
						cout << "Request status:\t" << "Congratulations!,The seller accepted your request!" << endl;
					}
					else if (item[i].Seller_accepet == 0)
					{
						cout << "Request status:\t" << "Sorry!,The seller did not accepted your request!" << endl;
					}
					else
					{
						cout << "Request status:\t" << "The seller has not responded yet!" << endl;
					}
					cout << string(100, '*') << endl;
			}
		}
	}
}
// this function makes the user sell a new item or an item from his item list//
void Sell_an_item_function()
{
	string seller_category;
	while (true) 
	{
		cout << "Please select one option:" << endl;
		cout << "[1] Sell a new item" << endl;
		cout << "[2] Sell an item from my wishlist" << endl;
		cout << "[3] Restart and cancel the selling process" << endl;
		cout << "Option:\t";
		cin >> Answer;
		switch (Answer)
		{
		case 1:
			cout << "Category list:" << endl;
			cout << "1\t" << "cars" << endl;
			cout << "2\t" << "furniture" << endl;
			cout << "3\t" << "laptops" << endl;
			cout << "4\t" << "mobiles" << endl;
			while (true)
			{
				cout << "Please write the name of the category of your items:\t";
				cin >> seller_category;
				if ((seller_category != "cars" ) && (seller_category != "furniture" ) && (seller_category != "laptops") && (seller_category != "mobiles" ))
				{
					cout << "This category is not avalabile!" << endl;
				}
				else
				{
					break;
				}
			}
			cout << "How many items do you want to sell?" << endl;
			cout << "If you want to restart and cancel the selling process,Please enter 0." << endl;
			cin >> itemSellnum;
			if (itemSellnum == 0)
			{
				cout << string(60, '*') << endl;
				cout << "Thank you for using the online acution application!" << endl;
				cout << string(60, '*') << endl;
				return;
			}
			for (int k = 0; k < itemSellnum; k++)
			{
				cout << "item number" << " " << k + 1 << " " << "information:" << endl;
				cout << "Iteam name:";
				cin >> item[itemNumber].itemName;
				while (true)
				{
					cout << "Item number:";
					cin >> item[itemNumber].item_number;
					for (int i = 0; i < itemNumber; i++)
					{
						if (item[itemNumber].item_number == item[i].item_number)
						{
							valid_item_number = false;
							break;
						}
						else
						{
							valid_item_number = true;
						}
					}
					if (valid_item_number == false)
					{
						cout << "Sorry this item number is already used,Please enter a different number!" << endl;
					}
					else
					{
						break;
					}
				}
				cout << "Staring bid price:";
				cin >> item[itemNumber].start_bid_Price;
				while (true)
				{
					cout << "Start date (day/month/year):\t";
					cin >> item[itemNumber].start_date.day >> item[itemNumber].start_date.month >> item[itemNumber].start_date.year;
					if (item[itemNumber].start_date.year < 2020)
					{
						cout << "Invalid date!" << endl;
					}
					else
					{
						break;
					}
				}
				while (true)
				{
					cout << "End date (day/month/year):\t";
					cin >> item[itemNumber].end_date.day >> item[itemNumber].end_date.month >> item[itemNumber].end_date.year;
					if (item[itemNumber].end_date.year < item[itemNumber].start_date.year)
					{
						cout << "Invalid date!" << endl;
					}
					else if (item[itemNumber].end_date.year == item[itemNumber].start_date.year && item[itemNumber].end_date.month < item[itemNumber].start_date.month)
					{
						cout << "Invalid date!" << endl;
					}
					else if (item[itemNumber].end_date.year == item[itemNumber].start_date.year && item[itemNumber].end_date.month == item[itemNumber].start_date.month && item[itemNumber].end_date.day < item[itemNumber].start_date.day)
					{
						cout << "Invalid date!" << endl;
					}
					else {
						break;
					}
					cout << endl;
				}
				item[itemNumber].status = "Avalabile";
				item[itemNumber].item_category = seller_category;
				item[itemNumber].seller_ID = Current_ID;
				itemNumber += itemSellnum;
			}
			while (true)
			{
				cout << "Confirm the selling process? write(y/n)." << endl;
				cin >> answer2;
				if (answer2 == "y")
				{
					cout << "Congratulations!,your items are now in the marketplace!" << endl;
					cout << string(60, '*') << endl;
					cout << "Thank you for using the online acution application!" << endl;
					cout << string(60, '*') << endl;
					break;
				}
				else if (answer2 == "n")
				{

				}
				else
				{
					cout << "Invalid input!" << endl;
				}
			}
			break;
		case 2:
			while (true)
			{
				cout << "Enter the item number from your wishlist that you want to sell: " << endl;
				cin >> itemNum;
				cout << "Confirm the selling process? write(y/n)." << endl;
				cin >> answer2;
				if (answer2 == "y")
				{
					for (int l = 0; l < itemNumber; l++)
					{
						if (item[l].item_number == itemNum && item[l].seller_ID == Current_ID && item[l].status == "Not in the marketplace")
						{
							item[l].status = "Avalabile";
							valid_itemNum = false;
						}
					}
					if (valid_itemNum == true)
					{
						cout << "Invalid item number or this item is not in your wishlist! " << endl;
					}
					else
					{
						cout << "Congratulations!,your transaction process is complete!" << endl;
						cout << "Your item is now in the marketplace and no longer in your wishlist!" << endl;
						cout << string(60, '*') << endl;
						cout << "Thank you for using the online acution application!" << endl;
						cout << string(60, '*') << endl;
						break;
					}
				}
			}
			break;
		case 3:
			cout << string(60, '*') << endl;
			cout << "Thank you for using the online acution application!" << endl;
			cout << string(60, '*') << endl;
			return;
			break;
		default:
			cout << "Invalid input!" << endl;
			break;
		}
		break;
	}
}
//this function displays the seller items wishlist the item that he wishs to sell in the future//
void Seller_items_list()
{
	cntr = 0;
	cout << "Your item wishlist:" << endl;
	for (int c = 0; c < itemNumber; c++)
	{
		if (item[c].status == "Not in the marketplace" && item[c].seller_ID == Current_ID)
		{
			cntr++;
		}
	}
	if (cntr == 0)
	{
		cout << "You have no items in your wishlist!" << endl;
		cout << "Do you want to add an item to your list? write (y/n)" << endl;
		cin >> answer2;
		if (answer2 == "y")
		{
			cout << "How many items do you want to add to your list?" << endl;
			cout << "If you want to restart and cancel the adding process,Please enter 0." << endl;
			cin >> itemSellnum;
			if (itemSellnum == 0)
			{
				cout << string(60, '*') << endl;
				cout << "Thank you for using the online acution application!" << endl;
				cout << string(60, '*') << endl;
				return;
			}
			for (int k = 0; k < itemSellnum; k++)
			{
				cout << "item number" << " " << k + 1 << " " << "required information:" << endl;
				cout << "Iteam name:";
				cin >> item[itemNumber].itemName;
				cout << "Item number:";
				cin >> item[itemNumber].item_number;
				cout << "Staring bid price:";
				cin >> item[itemNumber].start_bid_Price;
				cout << "Item category:";
				cin >> item[itemNumber].item_category;
				while (true)
				{
					cout << "Start date (day/month/year):\t";
					cin >> item[itemNumber].start_date.day >> item[itemNumber].start_date.month >> item[itemNumber].start_date.year;
					if (item[itemNumber].start_date.year < 2020) {
						cout << "Invalid date!" << endl;
					}
					else
					{
						break;
					}
				}
				while (true)
				{
					cout << "End date (day/month/year):\t";
					cin >> item[itemNumber].end_date.day >> item[itemNumber].end_date.month >> item[itemNumber].end_date.year;
					if (item[itemNumber].end_date.year < item[itemNumber].start_date.year)
					{
						cout << "Invalid date!" << endl;
					}
					else if (item[itemNumber].end_date.year == item[itemNumber].start_date.year && item[itemNumber].end_date.month < item[itemNumber].start_date.month)
					{
						cout << "Invalid date!" << endl;
					}
					else if (item[itemNumber].end_date.year == item[itemNumber].start_date.year && item[itemNumber].end_date.month == item[itemNumber].start_date.month && item[itemNumber].end_date.day < item[itemNumber].start_date.day)
					{
						cout << "Invalid date!" << endl;
					}
					else
					{
						break;
					}
					cout << endl;
				}
				item[itemNumber].status = "Not in the marketplace";
				item[itemNumber].seller_ID = Current_ID;
				itemNumber += itemSellnum;
			}
		}
	}
	else 
	{
		cout << "Item number:" << "\t" << "Item name:" << "\t" << "Item start bid price:" << "\t" << "Item status:" << "\t\t" << "Item start date:" << "\t" << "Item end date:" << endl;
		for (int i = 0; i < itemNumber; i++)
		{
			if (item[i].status == "Not in the marketplace" && item[i].seller_ID == Current_ID) {
				cout << item[i].item_number << "\t\t" << item[i].itemName << "\t\t\t" << item[i].start_bid_Price << "\t\t" << item[i].status << "\t" << "    ";
				cout << item[i].start_date.day << "/" << item[i].start_date.month << "/" << item[i].start_date.year << "\t\t";
				cout << item[i].end_date.day << "/" << item[i].end_date.month << "/" << item[i].end_date.year << endl;
			}
		}
		
	}
}
// this functions displays the seller requests and makes him choose which to handl//
void requests()
{
	int buyer_ID;
	cntr = 0;
	cout << "Your requests:" << endl;
	for (int i = 0; i < itemNumber; i++)
	{
		if (item[i].status == "Requsted for buying" && item[i].seller_ID == Current_ID)
		{
			cntr++;
		}
	}
	s = cntr - (cntr - 1);
	if (cntr == 0)
	{
		cout << "You have no requests at the moment!" << endl;
	}
	else
	{
		for (int j = 0; j < itemNumber; j++)
		{
			if (item[j].status == "Requsted for buying" && item[j].seller_ID == Current_ID)
			{
				cout << string(100, '*') << endl;
				cout << "Request Number:\t" << s << "\tFrom member:\t" << member[item[j].buyer_ID - 1].name << endl;
				cout << "item number:\t" << "item name:\t" << "item category:\t" << "Starting bid price:\t" << "Suggested price:\t" << "Buyer ID:" << endl;
				cout << item[j].item_number << "\t\t" << item[j].itemName << "\t\t" << item[j].item_category << "\t\t" << item[j].start_bid_Price << "\t\t";
				if (item[j].item_suggested_price != 0)
				{
					cout << item[j].item_suggested_price << "\t\t";
				}
				else
				{
					cout << "No suggested price" << "\t\t";
				}
				cout << item[j].buyer_ID << endl;
				cout << string(100, '*') << endl;
				s++;
			}
		}
		while (true)
		{
			cout << "Please enter the item number and the buyer ID  you want to sell it to!" << endl;
			cout << "Item number:\t";
			cin >> itemNum;
			for (int l = 0; l < itemNumber; l++) 
			{
				if (item[l].item_number == itemNum && item[l].status == "Requsted for buying" && item[l].seller_ID == Current_ID)
				{
					cout << "Buyer ID:\t";
					cin >> buyer_ID;
					if (item[l].buyer_ID == buyer_ID) 
					{
						valid_itemNum = true;
						break;
					}
				}
				else
				{
					valid_itemNum = false;
				}
			}
			if (valid_itemNum == false)
			{
				cout << "Invalid item number/Buyer ID!" << endl;
			}
			else
			{
				break;
			}
		}
		cout << "Buyer address information:" << endl;
		cout << "City :\t" << member[buyer_ID - 1].add.city << endl;
		cout << "Area :\t" << member[buyer_ID - 1].add.area << endl;
		cout << "Street :\t" << member[buyer_ID - 1].add.street << endl;
		cout << "House Number :\t" << member[buyer_ID - 1].add.house_number << endl;
		cout << "Floor :\t" << member[buyer_ID - 1].add.floor << endl;
		cout << "Apartment Number :\t" << member[buyer_ID - 1].add.apartment_number << endl;
		for (int n = 0; n < itemNumber; n++)
		{
			if (item[n].status == "Requsted for buying" && item[n].buyer_ID == buyer_ID)
			{
				cout << "Confirm selling to this member with this price? write (y/n)\t" << "Enter (0) to log out and restart the application!" << endl;
				cin >> answer2;
				if (answer2 == "y")
				{
					cout << "Congratulations! Your item is sold and no longer in the marketplace!" << endl;
					item[n].status = "Sold";
					if (item[n].item_category == "cars")
					{
						months[item[n].end_date.month].car_sales++;
					}
					else if (item[n].item_category == "mobiles")
					{
						months[item[n].end_date.month].mobile_sales++;
					}
					else if (item[n].item_category == "laptops")
					{
						months[item[n].end_date.month].laptops_sales++;
					}
					else if (item[n].item_category == "furniture")
					{
						months[item[n].end_date.month].furniture_sales++;
					}
					item[n].Seller_accepet = 2 - 1;
					break;
				}
				else if (answer2 == "n")
				{
					item[n].status = "Avalabile";
					item[n].Seller_accepet = 2 - 2;
					break;
				}
				else if (answer2 == "0")
				{
					return;
				}
				else
				{
					cout << "Invalid answer!" << endl;
				}
			}
		}
	}
}
// this functions generates a report and displays the top category in a certain month//
void report()
{
	int month;
	cout << "Please,Enter the number of the month:" << endl;
	cin >> month;
	if (month > 12) 
	{
		cout << "Invalid month number!" << endl;
	}
	else
	{
		int max = months[month].car_sales;
		cout << "This month top category is:" << endl;
		if (months[month].furniture_sales > max)
		{
			max = months[month].furniture_sales;
		}
		if (months[month].laptops_sales > max)
		{
			max = months[month].laptops_sales;
		}
		if (months[month].mobile_sales > max)
		{
			max = months[month].mobile_sales;
		}
		if (max == 0)
		{
			cout << "There is no top category for this month!\n";
			return;
		}
		if (months[month].furniture_sales == max)
		{
			cout << "furniture\t" << "Number of sold items:\t" << max << endl;
		}
		if (months[month].mobile_sales == max)
		{
			cout << "mobile\t" << "Number of sold items:\t" << max << endl;
		}
		if (months[month].laptops_sales == max)
		{
			cout << "laptops\t" << "Number of sold items:\t" << max << endl;
		}
		if (months[month].car_sales == max)
		{
			cout << "cars\t" << "Number of sold items:\t" << max << endl;
		}
	}
}
// this function makes the user give a feedback about another user//
void feedback_rating()
{
	string comment;
	int rate;
	int seller_buyerID;
	while (true)
	{
		cout << "Please enter the ID of the seller/buyer that you want to rate:" << endl;
		cin >> seller_buyerID;
		for (int i = 0; i < 4; i++)
		{
			if (member[i].id != seller_buyerID || seller_buyerID == Current_ID)
			{
				valid_id = false;
			}
			else
			{
				valid_id = true;
				break;
			}
		}
		if (valid_id == false)
		{
			cout << "Invalid seller/buyer ID!" << endl;
			cout << "Note:" << endl << "You can't rate yourself!" << endl;
		}
		else
		{
			break;
		}
	}
	cout << "On a scale from(1-5),Please rate this seller/buyer:" << endl;
	cin >> rate;
	if (rate >= 3)
	{
		member[seller_buyerID - 1].points++;
	}
	cout << "Please give us a comment about your experince " << endl;
	cout << "Comment:" << endl;
	cin >> comment;
	cout << endl;
	cout << "Thank you for your feedback!" << endl;
	cout << string(60, '*') << endl;
	cout << "Thank you for using the online acution application!" << endl;
	cout << string(60, '*') << endl;
}
// this function displays the member points//
void Member_view_points()
{
	cout << "Your points:\t\t";
	cout << member[Current_ID - 1].points << endl;
	cout << string(60, '*') << endl;
	cout << "Thank you for using the online acution application!" << endl;
	cout << string(60, '*') << endl;
}
// this function calls the buyer functios and options//
void buyer_functions()
{
	while (true)
	{
		cout << "Please select one of the following options:" << endl;
		cout << "[1] Buy an item" << endl;
		cout << "[2] View my points" << endl;
		cout << "[3] Give a feedback" << endl;
		cout << "[4] View monthly report!" << endl;
		cout << "[5] My buying requests" << endl;
		cout << "[6] Log out" << endl;
		cout << "Option number:\t\t";
		cin >> Answer;

		switch (Answer)
		{
		case 1:
			cout << "Please select one search option:" << endl;
			cout << "[1] By category" << endl;
			cout << "[2] By category and price" << endl;
			cout << "Option number:\t\t";
			cin >> Answer;
			switch (Answer)
			{
			case 1:
				Is_price_or_Category = true;
				Buying_by_category_and_or_price();
				cout << endl;
				break;
			case 2:
				Is_price_or_Category = false;
				Buying_by_category_and_or_price();
				cout << endl;
				break;
			default:
				cout << "Invalid option!" << endl;
				break;
			}
			break;
		case 2:
			Member_view_points();
			break;
		case 3:
			feedback_rating();
			break;
		case 4:
			report();
			break;
		case 5:
			buyer_requests();
			break;
		case 6:
			cout << string(60, '*') << endl;
			cout << "Thank you for using the online acution application!" << endl;
			cout << string(60, '*') << endl;
			return;
			break;
		default:
			cout << "Invalid input!,Please try again" << endl;
			break;
		}
	}
}
// this function calls the seller functios and options//
void seller_functions()
{
	while (true)
	{
		cout << "Please select one of the following options:" << endl;
		cout << "[1] Sell an item" << endl;
		cout << "[2] View my wishlist" << endl;
		cout << "[3] View my points" << endl;
		cout << "[4] Give a feedback" << endl;
		cout << "[5] View monthly report!" << endl;
		cout << "[6] handle request" << endl;
		cout << "[7] Log out!" << endl;
		cout << "Option number:\t\t";
		cin >> Answer;

		switch (Answer)
		{
		case 1:
			Sell_an_item_function();
			break;
		case 2:
			Seller_items_list();
			break;
		case 3:
			Member_view_points();
			break;
		case 4:
			feedback_rating();
			break;
		case 5:
			report();
			break;
		case 6:
			requests();
			break;
		case 7:
			cout << string(60, '*') << endl;
			cout << "Thank you for using the online acution application!" << endl;
			cout << string(60, '*') << endl;
			return;
		default:
			cout << "Invalid input!,Please try again" << endl;
			break;
		}
	}
}
// this function validates the user id and password//
void member_first_Input()
{
	bool valid_password = true;
	string member_password;
	while (true)
	{
		cout << "Enter the following:" << endl << "ID:\t\t";
		cin >> Current_ID;
		for (int i = 0; i < 4; i++)
		{
			if (member[i].id != Current_ID)
			{
				valid_id = false;
				continue;
			}
			else
			{
				valid_id = true;
				cout << "Password:\t";
				cin >> member_password;
				if (member[i].password != member_password)
				{
					valid_password = false;
					cout << "Sorry,Invalid/incorrect password!,Please try again " << endl;
					break;
				}
				else
				{
					valid_password = true;
					break;
				}
			}
		}
		if (valid_id == false)
		{
			cout << "Sorry,Invalid id!,Please try again" << endl;
		}
		if (valid_id == true && valid_password == true)
		{
			break;
		}
	}
}

int main()
{
	member[0] = { 1,"ali@gmail.com","Ali","123a",{"Cairo","Heliopolis","Korba","49","4","12"},1212757044 ,0 };
	member[1] = { 2,"ahmed@yahoo.com","Ahmed","456b",{"Cairo","Ain shams","Amar","1","5","13"},1012717045 ,0 };
	member[2] = { 3,"samy@hotmail.com","Samy","789c",{"Cairo","Abbassia","Radwan Shokry","13","1","1"},1112737046 ,0 };
	member[3] = { 4,"sara@gmail.com","Ali","012d",{"Cairo","Heliopolis","El Nozha","25","6","12"},1212727047 ,0 };
	item[0] = { "BMW", 1, "cars", {22,1,2020}, {21, 2, 2020}, 12412414, 0, "Avalabile", 1, 0, 2 };
	item[1] = { "iphone", 3, "mobiles", {22,1,2020}, {21, 2, 2020}, 12412414, 0, "Avalabile", 1, 0, 2 };
	item[2] = { "lenovo", 4, "laptops", {22,1,2020}, {21, 2, 2020}, 12412414, 0, "Avalabile", 3, 0, 2 };
	item[3] = { "bed", 1, "furniture", {22,1,2020}, {21, 2, 2020}, 12412414, 0, "Avalabile", 3, 0, 2 };
	while (true)
	{
		cout << "Welcome to the online acution application!" << endl << "Please select one of the following:" << endl; 
		cout << "Are you a:" << endl << "[1] Buyer" << endl << "[2] Seller" << endl;
		cin >> Answer;
		switch (Answer)
		{
		case 1:
			member_first_Input();
			buyer_functions();
			break;
		case 2:
			member_first_Input();
			seller_functions();
			break;
		default:
			cout << "Sorry,invalid/incorrect answer!,Please try again" << endl;
			break;
		}
	}
}