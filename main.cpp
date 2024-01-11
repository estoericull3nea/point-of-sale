#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <thread>
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
	vector<string> container_date_time;
	vector<int> container_quantity;
	vector<int> container_price;
	// -------

	// global variable
	int discounted = 0;
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
		age_computation(); // compute the age
		// -------
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

		int quantity;
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

		// ask user to edit
		do {
			cout << "Do you want to edit? [y/n]: ";
			cin >> edit_order;

			edit_order = tolower(edit_order);

			if (edit_order != 'y' && edit_order != 'n') {
				cout << "Invalid input. Please enter 'y' or 'n'." << endl;
			}

		} while (edit_order != 'y' && edit_order != 'n');

		// if user select yes
		while (true) {
			if (tolower(edit_order) == 'y') {
				cout << "Editing order.\n";
				display_orders();
				int index;
				do {
				start:
					cout << "Enter index to edit (a non-negative integer): ";
					cin >> index;

					if (cin.fail() || index < 0) {
						cout << "Invalid input. Please enter a non-negative integer for the index." << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}

				} while (cin.fail() || index < 0);

				if (index > container_order.size()) {
					cout << "Invalid\n";
					goto start;
				}

				if (index < container_order.size()) {
					cout << "Invalid\n";
					goto start;
				}
				// after validation

				index--;
				// order again to repalce old one
				display_all_menus();

				cout << "Previous order is " << container_order.at(index) << "\n";
				cout << "Previous quantity is " << container_quantity.at(index) << "\n";

				ask_what_menu();


				do {
					cout << "Please select (b, c, or e) >>>: ";
					cin >> choice_what_menu;

					// Convert input to lowercase to handle both uppercase and lowercase input
					choice_what_menu = tolower(choice_what_menu);

					if (choice_what_menu != 'b' && choice_what_menu != 'c' && choice_what_menu != 'e') {
						cout << "Invalid choice. Please enter 'b', 'c', or 'e'." << endl;
					}

				} while (choice_what_menu != 'b' && choice_what_menu != 'c' && choice_what_menu != 'e');
				// after validation

				if (tolower(choice_what_menu) == 'b') { // beef burger
					display_single_beef_burgers_menu();

					int choice_what_menu;
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

					int index = --choice_what_menu;
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
				} else if (tolower(choice_what_menu) == 'c') { // chicken burger
					display_single_chick_burgers_menu();

					int choice_what_menu;
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
				} else {
					cout << "Thank you!\n";
					exit(1);
				}
			} else {
				break;
			}

			do {
				cout << "Do you want to edit again? [y/n]: ";
				cin >> edit_again;

				// Convert input to lowercase to handle both uppercase and lowercase input
				edit_again = tolower(edit_again);

				if (edit_again != 'y' && edit_again != 'n') {
					cout << "Invalid input. Please enter 'y' or 'n'." << endl;
				}

			} while (edit_again != 'y' && edit_again != 'n');

			// The user has entered a valid choice
			if (!(edit_again == 'y')) {
				break;
			}
		}
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

		// ask user to edit
		do {
			cout << "Do you want to edit? [y/n]: ";
			cin >> edit_order;

			edit_order = tolower(edit_order);

			if (edit_order != 'y' && edit_order != 'n') {
				cout << "Invalid input. Please enter 'y' or 'n'." << endl;
			}

		} while (edit_order != 'y' && edit_order != 'n');
		// after validation

		// if user select yes
		while (true) {
			if (tolower(edit_order) == 'y') {
				cout << "Editing order.\n";
				display_orders();
				int index;
				do {
				start:
					cout << "Enter index to edit (a non-negative integer): ";
					cin >> index;

					if (cin.fail() || index < 0) {
						cout << "Invalid input. Please enter a non-negative integer for the index." << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}

				} while (cin.fail() || index < 0);

				if (index > container_order.size()) {
					cout << "Invalid\n";
					goto start;
				}

				if (index < container_order.size()) {
					cout << "Invalid\n";
					goto start;
				}
				// after validation

				index--;
				// order again to repalce old one
				display_all_menus();

				cout << "Previous order is " << container_order.at(index) << "\n";
				cout << "Previous quantity is " << container_quantity.at(index) << "\n";

				ask_what_menu();

				do {
					cout << "Please select (b, c, or e) >>>: ";
					cin >> choice_what_menu;

					// Convert input to lowercase to handle both uppercase and lowercase input
					choice_what_menu = tolower(choice_what_menu);

					if (choice_what_menu != 'b' && choice_what_menu != 'c' && choice_what_menu != 'e') {
						cout << "Invalid choice. Please enter 'b', 'c', or 'e'." << endl;
					}

				} while (choice_what_menu != 'b' && choice_what_menu != 'c' && choice_what_menu != 'e');
				// after validation

				if (tolower(choice_what_menu) == 'b') { // beef burger
					display_single_beef_burgers_menu();

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
				} else if (tolower(choice_what_menu) == 'c') { // chicken burger
					display_single_chick_burgers_menu();

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
				} else {
					cout << "Thank you!\n";
					exit(1);
				}
			} else {
				break;
			}
			do {
				cout << "Do you want to edit again? [y/n]: ";
				cin >> edit_again;

				// Convert input to lowercase to handle both uppercase and lowercase input
				edit_again = tolower(edit_again);

				if (edit_again != 'y' && edit_again != 'n') {
					cout << "Invalid input. Please enter 'y' or 'n'." << endl;
				}

			} while (edit_again != 'y' && edit_again != 'n');

			// The user has entered a valid choice
			if (!(edit_again == 'y')) {
				break;
			}
		}
	}

	// order again
	void ask_to_order_again() {
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
			game_start();
		} else {
			cout << "Not order again\n";
		}
	}

	// adding order (true if success)
	bool add_order(string order, int quantity, int price) {
		if (order, quantity, price) {

			container_order.push_back(order);
			container_quantity.push_back(quantity);
			container_price.push_back(price);

			return true;
		}
		return false;
	}

	// display order
	void display_orders() {
		cout << "Index\t\t\tOrder\t\t\t\tQuantity\t\t\tSubtotal\n";
		for (int i = 0; i < container_order.size(); i++) {
			cout << (i + 1) << ".\t\t\t" << container_order.at(i) << "\t\t\t" << container_quantity.at(i) << " x " << container_price.at(i) << "\t\t\t\t" << (container_quantity.at(i) * container_price.at(i)) << "\n";
		}
		cout << "\n";
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
			if (cin.fail() || age < 0) {
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

	_burger.game_start();

	return 0;
}
