#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <cctype> // for isdigit, isalpha, isupper, islower
#include <conio.h>
#define c cout <<
using namespace std;

class Burger_POS {

public:

	// vector default
	vector<string> menu_for_beef_burger_init;
	vector<string> menu_for_chick_burger_init;

	vector<int> price_for_beef_burger_init;
	vector<int> price_for_chick_burger_init;
	// -------

	// store order
	vector<string> container_order;
	vector<int> container_quantity;
	vector<int> container_price;
	// -------

	// global variable
	int discounted = 0;
	// -------

	// for audit add
	vector<string> audit_add_date_and_time;
	vector<string> audit_add_order;
	vector<int> audit_add_price;
	vector<int> audit_add_quantity;
	// -------

	// for audit delete
	vector<string> audit_delete_date_and_time;
	vector<string> audit_delete_order;
	vector<int> audit_delete_quantity;
	// -------

	// for audit update
	vector<string> audit_update_date_and_time;
	vector<string> audit_update_order;
	vector<int> audit_update_quantity;
	// -------

	// constructor
	Burger_POS() {
		menu_for_beef_burger_init.push_back("Beef Burger"); 	 price_for_beef_burger_init.push_back(120);
		menu_for_beef_burger_init.push_back("Cheese Burger");  price_for_beef_burger_init.push_back(130);
		menu_for_beef_burger_init.push_back("Beef Bacon"); 	 price_for_beef_burger_init.push_back(140);
		menu_for_beef_burger_init.push_back("Creamy Mushroom");  price_for_beef_burger_init.push_back(100);
		menu_for_beef_burger_init.push_back("Hawaiian Burger");  price_for_beef_burger_init.push_back(110);

		menu_for_chick_burger_init.push_back("Spicy Tandoori");   price_for_chick_burger_init.push_back(100);
		menu_for_chick_burger_init.push_back("Spicy Buffalo");    price_for_chick_burger_init.push_back(100);
		menu_for_chick_burger_init.push_back("BBQ Chicken");      price_for_chick_burger_init.push_back(99);
		menu_for_chick_burger_init.push_back("Crispy Chicken");   price_for_chick_burger_init.push_back(160);
		menu_for_chick_burger_init.push_back("Chicken Paradise"); price_for_chick_burger_init.push_back(190);
	}

	// single menu (beef)
	void display_single_beef_burgers_menu() {
		c "\n\n\t\t\t\t\t=================== Beef Burgers Menu ====================\n\n";
		c "\n   \t\t\t\t\t\t\tLists\t\t\tPrice\n\n";
		for (int i = 0; i < menu_for_beef_burger_init.size(); i++) {
			cout << "\t\t\t\t\t\t" << i + 1 << ". " << menu_for_beef_burger_init.at(i) << "\t\t " << price_for_beef_burger_init.at(i) << "\n";
		}
		c "\n\n\t\t\t\t\t==========================================================\n\n";
	}

	// single menu (chick)
	void display_single_chick_burgers_menu() {
		c "\n\n\t\t\t\t\t================ Chicken Burgers Menu ====================\n\n";
		c "\n   \t\t\t\t\t\t\tLists\t\t\tPrice\n\n";
		for (int i = 0; i < menu_for_chick_burger_init.size(); i++) {
			cout << "\t\t\t\t\t\t" << i + 1 << ". " << menu_for_chick_burger_init.at(i) << "\t\t" << price_for_chick_burger_init.at(i) << "\n";
		}
		c "\n\n\t\t\t\t\t==========================================================\n\n";
	}

	// all menu (beef & chick)
	void display_all_menus() {
		display_single_beef_burgers_menu();
		display_single_chick_burgers_menu();
	}

	// asking for what menu to be select
	void ask_what_menu() {
		cout << "\nB. Beef Burger.\n";
		cout << "C. Chicken Burger.\n";
		cout << "E. Exit.\n";
	}

	// starting point of this system
	void game_start() {
		// local variables
		char choice_what_menu;
		// -------

		display_all_menus(); // display both menu
		ask_what_menu(); // select in two menu

		do {
			cout << "Please select (b, c, or e) >>>: ";
			cin >> choice_what_menu;

			choice_what_menu = tolower(choice_what_menu); // convert to lowercase

			if (choice_what_menu != 'b' && choice_what_menu != 'c' && choice_what_menu != 'e') {
				cout << "Invalid choice. Please enter 'b', 'c', or 'e'." << endl;
			}

		} while (choice_what_menu != 'b' && choice_what_menu != 'c' && choice_what_menu != 'e');
		// after validation for "Please select (b, c, or e) >>>: "

		// conditional statement
		if (tolower(choice_what_menu) == 'b') {
			beef_burger_selected();
		} else if (tolower(choice_what_menu) == 'c') {
			chick_burger_selected();
		} else {
			cout << "Thank you!\n";
			exit(1);
		}
		// -------

		// after populating orders
		cout << "Total is: " << get_total() << "\n";
		ask_to_order_again(); // asking to order again
		cout << "Total is: " << get_total() << "\n";
		update_order();
		// -------

		display_orders();
		cout << "Total is: " << get_total() << "\n";
		// -------

		// age computation
		age_computation();

	}

	// if beef
	void beef_burger_selected() {
		// local variables
		int choice_what_menu, index, price, quantity;
		string order;
		char edit_order, edit_again;
		// -------

		display_single_beef_burgers_menu(); // display beef

		do {
			// asking to select order
			cout << "Please select (1-5) >>>: ";
			cin >> choice_what_menu;

			if (choice_what_menu < 1 || choice_what_menu > 5) {
				cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
			}

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

		} while (choice_what_menu < 1 || choice_what_menu > 5);
		// after validation

		index = --choice_what_menu;
		order = menu_for_beef_burger_init.at(index);
		cout << "You selected " << order << "\n";

		do {
			// asking for quantity
			cout << "How many " << order << ": ";
			cin >> quantity;

			if (cin.fail() || quantity <= 0) {
				cout << "Invalid input. Please enter a positive integer for the quantity." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

		} while (cin.fail() || quantity <= 0);
		// after validation

		// adding order
		price = price_for_beef_burger_init.at(index);
		if (add_order(order, quantity, price)) {
			cout << "Order Added\n";

		} else {
			cout << "Something went wrong.\n";
		}

		// display order
		cout << "Your Order Are.\n";
		display_orders();
	}

	// if chicken
	void chick_burger_selected() {
		// variables
		int choice_what_menu, index, quantity, price;
		string order;
		char edit_order, edit_again;
		// -------

		display_single_chick_burgers_menu(); // display chick

		do {
			// asking to select order
			cout << "Please select (1-5) >>>: ";
			cin >> choice_what_menu;

			if (choice_what_menu < 1 || choice_what_menu > 5) {
				cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
			}

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

		} while (choice_what_menu < 1 || choice_what_menu > 5);
		// after validation

		index = --choice_what_menu;
		order = menu_for_chick_burger_init.at(index);
		cout << "You selected " << order << "\n";

		do {
			// asking for quantity
			cout << "How many " << order << ": ";
			cin >> quantity;

			if (cin.fail() || quantity <= 0) {
				cout << "Invalid input. Please enter a positive integer for the quantity." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

		} while (cin.fail() || quantity <= 0);
		// after validation

		// adding order
		price = price_for_chick_burger_init.at(index);
		if (add_order(order, quantity, price)) {
			cout << "Order Added\n";
		} else {
			cout << "Something went wrong.\n";
		}

		// display order
		cout << "Your Order Are.\n";
		display_orders();
	}

	// order again
	bool ask_to_order_again() {
		while (true) {

			// variables
			char order_again;
			// -------

			cout << "Order(s) are.\n";
			display_orders();
			do {
				cout << "Do you want to order again? [y/n]: ";
				cin >> order_again;

				order_again = tolower(order_again); // Convert the input to lowercase for case-insensitive comparison

				if (order_again != 'y' && order_again != 'n') {
					cout << "Invalid input. Please enter 'y' for yes or 'n' for no." << endl;
				}

			} while (order_again != 'y' && order_again != 'n');
			// after validation

			if (order_again == 'y') {

				// local variables
				char choice_what_menu;
				// -------

				display_all_menus(); // display both menu
				ask_what_menu(); // select in two menu

				do {
					cout << "Please select (b, c, or e) >>>: ";
					cin >> choice_what_menu;

					choice_what_menu = tolower(choice_what_menu); // convert to lowercase

					if (choice_what_menu != 'b' && choice_what_menu != 'c' && choice_what_menu != 'e') {
						cout << "Invalid choice. Please enter 'b', 'c', or 'e'." << endl;
					}

				} while (choice_what_menu != 'b' && choice_what_menu != 'c' && choice_what_menu != 'e');
				// after validation for "Please select (b, c, or e) >>>: "

				// conditional statement
				if (tolower(choice_what_menu) == 'b') {
					beef_burger_selected();
				} else if (tolower(choice_what_menu) == 'c') {
					chick_burger_selected();
				} else {
					cout << "Thank you!\n";
					exit(1);
				}
				// -------

			} else {
				cout << "Not order again\n";
				return true;
			}
		}

		return false;

	}

	// adding order (true if success)
	bool add_order(string order, int quantity, int price) {
		if (order, quantity, price) {

			container_order.push_back(order);
			container_quantity.push_back(quantity);
			container_price.push_back(price);

			audit_add_order.push_back(order);
			audit_add_quantity.push_back(quantity);
			audit_add_price.push_back(price);
			audit_add_date_and_time.push_back(get_current_date_and_time());

			return true;
		}
		return false;
	}

	// update order
	bool update_order() {

		while (true) {


			char edit_order;
			int index, choice;
			do {
				display_orders();
				cout << "Do you want to edit your order? [y/n]: ";
				cin >> edit_order;

				if (edit_order != 'y' && edit_order != 'n') {
					cout << "Invalid input. Please enter 'y' for Yes or 'n' for No." << endl;
				}

			} while (edit_order != 'y' && edit_order != 'n');
			// after validation

			if (tolower(edit_order) == 'y') {
				cout << "Editing\n";

				do {
					// asking to select order
					display_orders();
					cout << "Please select index to edit: ";
					cin >> index;

					if (index < 1 || index > container_order.size()) {
						cout << "Invalid choice. Please enter a valid number." << endl;
					}

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

				} while (index < 1 || index > container_order.size());

				index--;

				// options
				cout << "Options.\n";
				cout << "1. Order.\n";
				cout << "2. Quantity.\n";

				do {
					cout << "Enter choice (1 or 2): ";

					if (cin >> choice && (choice == 1 || choice == 2)) {
						break;
					} else {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input. Please enter either 1 or 2." << endl;
					}

				} while (true);

				if (choice == 1) {
					cout << "Editing order.\n";
					cout << container_order.at(index) << " is selected.\n";

					// local variables
					char choice_what_menu;
					// -------

					display_all_menus(); // display both menu
					ask_what_menu(); // select in two menu

					do {
						cout << "Please select (b, c, or e) >>>: ";
						cin >> choice_what_menu;

						choice_what_menu = tolower(choice_what_menu); // convert to lowercase

						if (choice_what_menu != 'b' && choice_what_menu != 'c' && choice_what_menu != 'e') {
							cout << "Invalid choice. Please enter 'b', 'c', or 'e'." << endl;
						}

					} while (choice_what_menu != 'b' && choice_what_menu != 'c' && choice_what_menu != 'e');
					// after validation for "Please select (b, c, or e) >>>: "

					// conditional statement
					if (tolower(choice_what_menu) == 'b') {
						display_single_beef_burgers_menu();

						int picking_order;
						do {
							cout << "Select order (1-5): ";

							if (cin >> picking_order && picking_order >= 1 && picking_order <= 5) {
								break;
							} else {
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Invalid input. Please enter a valid integer between 1 and 5." << endl;
							}

						} while (true);

						string new_order = menu_for_beef_burger_init.at(picking_order - 1);
						int change_price = price_for_beef_burger_init.at(picking_order - 1);

						cout << "Order edited\n";
						cout << "New order is " << new_order << "\n";

						container_order.at(index) = new_order;
						container_price.at(index) = change_price;

						audit_update_order.push_back(new_order);
						audit_update_date_and_time.push_back(get_current_date_and_time());
						// done
					} else if (tolower(choice_what_menu) == 'c') {
						display_single_chick_burgers_menu();

						int picking_order;
						do {
							cout << "Select order (1-5): ";

							if (cin >> picking_order && picking_order >= 1 && picking_order <= 5) {
								break;
							} else {
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Invalid input. Please enter a valid integer between 1 and 5." << endl;
							}

						} while (true);

						string new_order = menu_for_chick_burger_init.at(picking_order - 1);
						int change_price = price_for_chick_burger_init.at(picking_order - 1);

						cout << "Order edited\n";
						cout << "New order is " << new_order << "\n";

						container_order.at(index) = new_order;
						container_price.at(index) = change_price;
						audit_update_order.push_back(new_order);
						audit_update_date_and_time.push_back(get_current_date_and_time());
						// done
					} else {
						cout << "Thank you!\n";
						exit(1);
					}
					// -------


				} else if (choice == 2) {
					int old_quantity = container_quantity.at(index), new_quantity;
					cout << "Editing quantity.\n";
					cout << "Quantity of " << container_order.at(index) << " is " << old_quantity << "\n";

					do {
						cout << "Enter new quantity: ";
						if (cin >> new_quantity && new_quantity > 0) {
							break;
						} else {
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Invalid input. Please enter a valid positive integer." << endl;
						}

					} while (true);

					container_quantity.at(index) = new_quantity;
					cout << "Quantity edited.\n";

					audit_update_quantity.push_back(new_quantity);
					audit_update_date_and_time.push_back(get_current_date_and_time());
					// done
				}

			} else {

				ask_to_delete_order();
				return true;
			}
		}


		return false;
	}

	bool ask_to_delete_order() {

		char delete_or_not;
		int index;


		do {
			cout << "Do you want to delete your order? [y/n]: ";
			cin >> delete_or_not;

			if (delete_or_not != 'y' && delete_or_not != 'n') {
				cout << "Invalid input. Please enter 'y' or 'n'.\n";
			}
		} while (delete_or_not != 'y' && delete_or_not != 'n');
		// after validation

		if (tolower(delete_or_not) == 'y') {
		start:
			cout << "Deleting order...\n";

			display_orders();

			do {
				cout << "Enter index to delete: ";
				cin >> index;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input. Please enter a valid index (an integer).\n";
				} else {
					if (index <= 0) {
						cout << "Invalid input. Please enter a non-negative index.\n";
					} else if (index > container_order.size()) {
						cout << "Invalid input.\n";

					}
				}
			} while (index <= 0 || cin.fail() || index > container_order.size());
			// after validation

			index--;
			cout << "The index is " << index << "\n";
			cout << "You selected " << container_order.at(index) << ", Quantity is " << container_quantity.at(index) << "\n";

			audit_delete_order.push_back(container_order.at(index));
			audit_delete_quantity.push_back(container_quantity.at(index));
			audit_delete_date_and_time.push_back(get_current_date_and_time());

			container_order.erase(container_order.begin() + index);
			container_price.erase(container_price.begin() + index);

			container_quantity.erase(container_quantity.begin() + index);

			cout << "Order deleted.\n";

			if (container_order.size() >= 1) {
				display_orders();

				char delete_again;
				do {
					cout << "Do you want to delete again? [y/n]: ";
					cin >> delete_again;

					if (delete_again != 'y' && delete_again != 'n') {
						cout << "Invalid input. Please enter 'y' or 'n'.\n";
					}
				} while (delete_again != 'y' && delete_again != 'n');
				// after validation

				if (tolower(delete_again) == 'y') {
					goto start;
				} else {
					cout << "Not delete again.\n";
					ask_to_order_again();
				}
			} else {
				cout << "No order(s).\n";
				game_start();
			}

		} else {
			cout << "Not.\n";
		}
		return false;
	}

	// display order
	void display_orders() {
		cout << "Your order(s) are.\n";
		cout << "Index\t\t\tOrder\t\t\t\tQuantity\t\t\tSubtotal\n";
		for (int i = 0; i < container_order.size(); i++) {
			cout << (i + 1) << ".\t\t\t" << container_order.at(i) << "\t\t\t" << container_quantity.at(i) << " x " << container_price.at(i) << "\t\t\t\t" << (container_quantity.at(i) * container_price.at(i)) << "\n";
		}
	}

	// computation of age
	void age_computation() {
		// variables
		int age, discounted;
		// -------

		// Prompt user for age until a valid input is provided
		while (true) {
			cout << "Enter your age: ";
			cin >> age;

			// Check if the input is a positive integer
			if (cin.fail() || age <= 0) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input. Please enter a non-negative integer for age." << endl;
			} else {
				break;
			}
		}
		// after validation

		if (is_senior(age)) {
			cout << "You are senior\n";
			discounted = discount_calculation(get_total());
			cout << "Total now is " << discounted << "\n";
		} else {
			cout << "not senior\n";
			discounted = get_total();
			cout << "Total is " << discounted << "\n";
		}

		// payment
		payment_method(discounted, age);
	}

	void payment_method(int overall_total, int age) {

		int payment;
		do {
			cout << "\nEnter payment: ";
			if (!(cin >> payment)) {

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\n\t\t===============================================================" << endl;
				cout << "\t\t   Invalid input. Please enter a valid non-negative integer." << endl;
				cout << "\t\t===============================================================\n" << endl;
			} else if (payment <= 0) {
				cout << "\n\t\t===============================================================" << endl;
				cout << "\t\t  Invalid Input: Please input valid integer." << endl;
				cout << "\t\t===============================================================\n" << endl;
			} else {
				break;
			}
		} while (true);

		if (payment == overall_total) {

			c "Thank you Come Again!\n";
			display_all_added_orders();
			display_all_deleted_orders();
			display_all_updated_orders();
			exit(1);
		} else if (payment > overall_total) {
			int p = payment - overall_total;

			c "Here is your change: " << p << "\n";
			c "Thank you Come Again!\n";
			exit(1);
		} else if (payment < overall_total) {
		start:

			char add_more;
			int add_money;
			cout << "\n\t\t==============================================" << endl;
			cout << "\t\t\tPlease add more " << overall_total - payment << " to pay this!\n";
			cout << "\t\t==============================================\n" << endl;

			while (overall_total > payment) {

				do {
					cout << "\nDo you want to add more? [y/n]: ";
					if (!(cin >> add_more) || (add_more != 'y' && add_more != 'n')) {

						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n\t\t=======================================================" << endl;
						cout << "\t\t\tInvalid input. Please enter 'y' or 'n'." << endl;
						cout << "\t\t=======================================================\n" << endl;
					} else {

						break;
					}
				} while (true);

				if (add_more == 'y' || add_more == 'Y') {
					do {
						cout << "\nAdd Money: ";
						if (!(cin >> add_money)) {

							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "\n\t\t===============================================================" << endl;
							cout << "\t\t   Invalid input. Please enter a valid non-negative integer." << endl;
							cout << "\t\t===============================================================\n" << endl;
						} else if (add_money <= 0) {
							cout << "\n\t\t===============================================================" << endl;
							cout << "\t\t  Invalid Input: Please input valid integer." << endl;
							cout << "\t\t===============================================================\n" << endl;
						} else {

							break;
						}
					} while (true);

					cout << "You entered additional money: " << add_money << "\n";
					if (add_money <= 0) {
						cout << "\nInvalid Input of Money\n";
					} else {
						add_money += payment;
						payment = add_money;
						if (payment < overall_total) {

							cout << "\n\t\t==============================================" << endl;
							cout << "\t\t\tPlease Add more " << overall_total - payment << " to pay this!\n";
							cout << "\t\t==============================================\n" << endl;

						} else if (payment == overall_total) {

							cout << "\nExact Amount, No Change\n";
							c "Thank you Come Again!\n";
							exit(1);
						} else if (payment > overall_total) {

							cout << "\nHere is your change " << payment - overall_total << " Thank you for coming and ordering!\n";
							exit(1);
						}
					}

				} else {
					cout << "not adding money.\n";

					char del_or_not;

					do {
						cout << "Do you want to delete your order(s)? [y/n]: ";
						cin >> del_or_not;

						if (del_or_not != 'y' && del_or_not != 'n') {
							cout << "Invalid input. Please enter 'y' or 'n'.\n";
						}

					} while (del_or_not != 'y' && del_or_not != 'n');
					// after validation

					if (tolower(del_or_not) == 'y') {
						cout << "deleting order.\n";

						display_orders();

						int index;
						do {
							cout << "Enter index to delete: ";
							cin >> index;

							if (cin.fail() || index <= 0 || index > container_order.size()) {
								cout << "Invalid input. Please enter a valid non-negative integer index.\n";

								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
							}

						} while (cin.fail() || index <= 0 || index > container_order.size());
						// after validation

						index--;

						cout << "You selected " << container_order.at(index) << "\n";
						cout << "Quantity is " << container_quantity.at(index) << "\n";

						container_order.erase(container_order.begin() + index);
						container_price.erase(container_price.begin() + index);

						container_quantity.erase(container_quantity.begin() + index);

						cout << "Order deleted.\n";

						if (container_order.size() <= 0) {
							cout << "No Order(s).\n";
							game_start();
						} else {
							// code here
							cout << "Total is: " << get_total() << ".\n";
							age_computation();
						}
					} else {
						goto start;
					}

				}
			}
		}
	}

	void display_all_added_orders() {

		if (audit_add_order.size() >= 1) {
			cout << "Your order(s) history added are.\n";
			cout << "Index\t\t\t\tOrder\t\t\t\t\tPrice\t\t\t\tQuantity\t\t\tDate and Time\n";
			for (int i = 0; i < audit_add_order.size(); i++) {
				cout << i + 1 << ".\t\t\t\t" << audit_add_order.at(i) << "\t\t\t\t" << audit_add_price.at(i) << "\t\t\t\t" << audit_add_quantity.at(i) << "\t\t\t\t" << audit_add_date_and_time.at(i) << "\n";
			}
		}


	}

	void display_all_deleted_orders() {
		if (audit_delete_order.size() >= 1) {
			cout << "Your order(s) history deleted are.\n";
			cout << "Index\t\t\t\tOrder\t\t\t\tQuantity\t\t\tDate and Time\n";
			for (int i = 0; i < audit_delete_order.size(); i++) {
				cout << i + 1 << ".\t\t\t\t" << audit_delete_order.at(i) << "\t\t\t\t" << audit_delete_quantity.at(i) << "\t\t\t\t" << audit_delete_date_and_time.at(i) << "\n";
			}
		}

	}

	void display_all_updated_orders() {
		if (audit_update_order.size() >= 1) {
			cout << "Your order(s) history updated are.\n";
			cout << "Index\t\t\t\tOrder\t\t\t\tQuantity\t\t\tDate and Time\n";
			for (int i = 0; i < audit_update_order.size(); i++) {
				cout << i + 1 << ".\t\t\t\t" << audit_update_order.at(i) << "\t\t\t\t" << audit_update_quantity.at(i) << "\t\t\t\t" << audit_update_date_and_time.at(i) << "\n";
			}
		}

	}

	// returning calculated discount (int)
	int discount_calculation(int total) {
		float percent_of_discount = .9;
		int discounted_total = total * percent_of_discount;
		return discounted_total;
	}

	// checking if senior (true of senior)
	bool is_senior(int age) {
		if (age >= 60) {
			return true;
		}
		return false;
	}

	// get overall total (int)
	int get_total() {

		int total = 0;
		for (int i = 0;i < container_order.size();i++) {
			total += (container_quantity.at(i) * container_price.at(i));
		}
		return total;
	}

	// returning date and time (string)
	string get_current_date_and_time() {
		// Get the current time
		auto currentTime = chrono::system_clock::now();
		time_t time = chrono::system_clock::to_time_t(currentTime);
		tm* timeInfo = localtime(&time);

		// Convert the hour to 12-hour format
		int hour12 = timeInfo->tm_hour % 12;
		if (hour12 == 0) {
			hour12 = 12; // Set 12 for midnight and noon
		}

		// Determine whether it's AM or PM
		const char* ampm = (timeInfo->tm_hour < 12) ? "AM" : "PM";

		// Create a stringstream to format the date and time
		stringstream resultStream;
		resultStream << (timeInfo->tm_year + 1900) << "-"
			<< setfill('0') << setw(2) << (timeInfo->tm_mon + 1) << "-"
			<< setfill('0') << setw(2) << timeInfo->tm_mday << " "
			<< setfill('0') << setw(2) << hour12 << ":"
			<< setfill('0') << setw(2) << timeInfo->tm_min << " " << ampm;

		// Return the formatted date and time as a string
		return resultStream.str();
	}
};

int main() {
	Burger_POS _burger;

	cout << "Hello. my friend!\n";
	cout << "Please register first.\n";

	string username;
	do {
		cout << "Enter username: ";
		// getline(cin, username);
		cin >> username;

		if (username.length() < 5) {
			cout << "Username must be at least 5 characters long. Try again." << endl;
		}

		if (username.find(' ') != string::npos) {
			cout << "Username cannot contain spaces. Try again." << endl;
		}

	} while (username.length() < 5 || username.find(' ') != string::npos);
	cout << "Username accepted: " << username << endl;

	string password;

	// Validation checks
	bool hasUpperCase = false;
	bool hasLowerCase = false;
	bool hasDigit = false;
	bool hasSpecialChar = false;

	do {
		cout << "Enter password: ";

		// Masking the password on Windows using _getch
		char ch;
		while ((ch = _getch()) != '\r') { // '\r' is the carriage return character
			if (ch == '\b') {  // Handle backspace
				if (!password.empty()) {
					password.pop_back();
					std::cout << "\b \b";  // Move cursor back and erase the character
				}
			} else {
				password.push_back(ch);
				std::cout << '*';
			}
		}

		cout << endl;

		// Reset flags for each attempt
		hasUpperCase = false;
		hasLowerCase = false;
		hasDigit = false;
		hasSpecialChar = false;

		// Validation checks
		for (char ch : password) {
			if (isupper(ch)) {
				hasUpperCase = true;
			} else if (islower(ch)) {
				hasLowerCase = true;
			} else if (isdigit(ch)) {
				hasDigit = true;
			} else if (!isalnum(ch)) {
				hasSpecialChar = true;
			}
		}

		if (password.length() < 8) {
			cout << "Error: Password must be at least 8 characters long. Try again." << endl;
		} else if (!hasUpperCase) {
			cout << "Error: Password must contain at least one uppercase letter. Try again." << endl;
		} else if (!hasLowerCase) {
			cout << "Error: Password must contain at least one lowercase letter. Try again." << endl;
		} else if (!hasDigit) {
			cout << "Error: Password must contain at least one digit. Try again." << endl;
		} else if (!hasSpecialChar) {
			cout << "Error: Password must contain at least one special character. Try again." << endl;
		}

	} while (password.length() < 8 || !hasUpperCase || !hasLowerCase || !hasDigit || !hasSpecialChar);

	cout << "Password accepted!" << endl;

	// validation is done
	// login

	cout << "Account registerd, Login!.\n";

	string login_username;
	cout << "Enter username: ";
	cin >> login_username;


	string login_password;
	cout << "Enter password: ";
	cin >> login_password;


	// _burger.game_start();

	return 0;
}


