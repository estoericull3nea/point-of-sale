// ============================== Libraries Used ==============================
#include<iostream>
#include<string>
#include<vector>
#include <limits>
#define c cout <<
using namespace std;

class Burger_POS {

public:

	// ============================== Variables ==============================
	int picking_order;
	char b;
	bool ready;
	int _quantity, age, money, temp_for_sum, payment;
	char order_again;

	// ============================== Constructor ==============================
	Burger_POS() {
		b = 'b';
		ready = false;
	}

	// ============================== Initializing Vector ==============================
	vector<string> foods;
	vector<int> quantity;
	vector<int> price;

	// ============================== Show Burger Menu ==============================
	void beef_burgers() {
		c "\n\n\t=================== Beef Burgers Menu ====================\n\n";
		c "\n   \t\t\tLists\t\tPrice\n\n";
		c "\t\t1. Beef Burger\t\t 120\n";
		c "\t\t2. Cheese Burger\t 130\n";
		c "\t\t3. Beef Bacon\t\t 140\n";
		c "\t\t4. Creamy Mushroom\t 100\n";
		c "\t\t5. Hawaiian Burger\t 110\n";
		c "\n\n\t==========================================================\n\n";
	}

	// ============================== Show Chicken Menu ==============================
	void chick_burgers() {
		c "\n\n\t================ Chicken Burgers Menu ====================\n\n";
		c "\n   \t\t\tLists\t\tPrice\n\n";
		c "\t\t1. Spicy Tandoori\t 100\n";
		c "\t\t2. Spicy Buffalo\t 100\n";
		c "\t\t3. BBQ Chicken\t\t  99\n";
		c "\t\t4. Crispy Chicken\t 160\n";
		c "\t\t5. Chicken Paradise\t 190\n";
		c "\n\n\t==========================================================\n\n";
	}

	// ============================== User Selecting Menu ==============================
	void pick_what_menu(char menu) {
		char upperMenu = toupper(menu);  // Convert to uppercase for case-insensitivity

		if (upperMenu == 'B') {
			// system("cls");
			beef_burgers();
			for_beef(menu);
		} else if (upperMenu == 'C') {
			// system("cls");
			chick_burgers();
			for_chick(menu);
		} else {
			// Handle invalid input
			cout << "Invalid menu choice." << endl;
		}
	}


	// ============================== If Beef Burger Selected ==============================
	void for_beef(char b) {

		ready = true;
		order_again = 'y';

		while (order_again == 'y' || order_again == 'Y') {

			do {
				cout << "Enter your order [1-5]: ";
				if (!(cin >> picking_order) || picking_order < 1 || picking_order > 5) {
					// Input is not a valid integer or not in the range [1, 5]
					cin.clear();  // Clear the error flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
					cout << "\n\t\t===============================================================" << endl;
					cout << "\t\t  Error message: Please enter a valid integer between 1 and 5." << endl;
					cout << "\t\t===============================================================\n" << endl;
				} else {
					// Valid input, break out of the loop
					break;
				}
			} while (true);


			do {
				c "How many: ";
				if (!(cin >> _quantity) || _quantity < 1) {

					cin.clear();  // Clear the error flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input

					cout << "\n\t\t===============================================================" << endl;
					cout << "\t\t  Error message: Please enter a valid integer & valid quantity." << endl;
					cout << "\t\t===============================================================\n" << endl;
				} else {
					// Valid input, break out of the loop
					break;
				}
			} while (true);

			if (picking_order == 1) {

				foods.push_back("Beef Burger    ");
				quantity.push_back(_quantity);
				price.push_back(120);

			} else if (picking_order == 2) {

				foods.push_back("Cheese Burger  ");
				quantity.push_back(_quantity);
				price.push_back(130);

			} else if (picking_order == 3) {

				foods.push_back("Beef Bacon     ");
				quantity.push_back(_quantity);
				price.push_back(140);

			} else if (picking_order == 4) {

				foods.push_back("Creamy Mushroom");
				quantity.push_back(_quantity);
				price.push_back(100);

			} else if (picking_order == 5) {

				foods.push_back("Hawaiian Burger");
				quantity.push_back(_quantity);
				price.push_back(110);

			}

			do {
				cout << "Do you want to order again? [y/n]: ";
				if (!(cin >> order_again) || (order_again != 'y' && order_again != 'n')) {
					// Input is not a valid character or not 'y' or 'n'
					cin.clear();  // Clear the error flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
					cout << "\n\t\t=======================================================" << endl;
					cout << "\t\t\tInvalid input. Please enter 'y' or 'n'." << endl;
					cout << "\t\t=======================================================\n" << endl;
				} else {
					// Valid input, break out of the loop
					break;
				}
			} while (true);

			if (order_again == 'y' || order_again == 'Y') {

				// system("cls");
				beef_burgers();

			} else {

				order_again = 'n';
				order_in_another_burger();
				display_order();
				c "\nOverall total: " << get_total() << "\n";
				get_total();
				age_comp();

			}

		}

	}

	// ============================== If Chicken Burger Selected ==============================
	void for_chick(char b) {

		order_again = 'y';

		while (order_again == 'y' || order_again == 'Y') {

			do {
				cout << "Enter your order [1-5]: ";
				if (!(cin >> picking_order) || picking_order < 1 || picking_order > 5) {

					cin.clear();  // Clear the error flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input

					cout << "\n\t\t===============================================================" << endl;
					cout << "\t\t  Error message: Please enter a valid integer between 1 and 5." << endl;
					cout << "\t\t===============================================================\n" << endl;
				} else {
					// Valid input, break out of the loop
					break;
				}
			} while (true);




			do {
				c "How many: ";
				if (!(cin >> _quantity) || _quantity < 1) {

					cin.clear();  // Clear the error flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input

					cout << "\n\t\t===============================================================" << endl;
					cout << "\t\t  Error message: Please enter a valid integer & valid quantity." << endl;
					cout << "\t\t===============================================================\n" << endl;
				} else {
					// Valid input, break out of the loop
					break;
				}
			} while (true);

			if (picking_order == 1) {

				foods.push_back("Spicy Tandoori  ");
				quantity.push_back(_quantity);
				price.push_back(100);

			} else if (picking_order == 2) {

				foods.push_back("Spicy Buffalo   ");
				quantity.push_back(_quantity);
				price.push_back(100);

			} else if (picking_order == 3) {

				foods.push_back("BBQ Chicken     ");
				quantity.push_back(_quantity);
				price.push_back(99);

			} else if (picking_order == 4) {

				foods.push_back("Crispy Chicken  ");
				quantity.push_back(_quantity);
				price.push_back(160);

			} else if (picking_order == 5) {

				foods.push_back("Chicken Paradise");
				quantity.push_back(_quantity);
				price.push_back(190);

			}

			do {
				cout << "Do you want to order again? [y/n]: ";
				if (!(cin >> order_again) || (order_again != 'y' && order_again != 'n')) {
					// Input is not a valid character or not 'y' or 'n'
					cin.clear();  // Clear the error flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
					cout << "\n\t\t=======================================================" << endl;
					cout << "\t\t\tInvalid input. Please enter 'y' or 'n'." << endl;
					cout << "\t\t=======================================================\n" << endl;
				} else {
					// Valid input, break out of the loop
					break;
				}
			} while (true);

			if (order_again == 'y' || order_again == 'Y') {
				//counter++;
				//foods.resize(counter);
				// system("cls");
				chick_burgers();

			} else {
				order_again = 'n';
				order_in_another_burger();
				display_order();
				c "\nOverall total: " << get_total() << "\n";
				get_total();
				age_comp();
			}
		}

	}

	// ============================== Delete Foods in Temporary Storage of Vector ==============================
	void delete_item_in_foods() {

		char delete_or_not, r_or_d;
		int number_to_delete;

		do {
			c "Do you want to delete your item? [y/n]: ";
			if (!(cin >> delete_or_not) || (delete_or_not != 'y' && delete_or_not != 'n')) {
				// Input is not a valid character or not 'y' or 'n'
				cin.clear();  // Clear the error flag
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
				cout << "\n\t\t=======================================================" << endl;
				cout << "\t\t\tInvalid input. Please enter 'y' or 'n'." << endl;
				cout << "\t\t=======================================================\n" << endl;
			} else {
				// Valid input, break out of the loop
				break;
			}
		} while (true);
		// system("cls");

		if (delete_or_not == 'y' || delete_or_not == 'Y') { // y

		start:

			display_order();

			do {
				cout << "\nEnter number do you want to delete: ";
				if (!(cin >> number_to_delete) || number_to_delete <= 0 || number_to_delete > foods.size()) {
					// Input is not a valid non-negative integer
					cout << number_to_delete << "\n";
					cin.clear();  // Clear the error flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
					cout << "\n\t\t===============================================================" << endl;
					cout << "\t\t   Invalid input. Please enter a valid non-negative integer." << endl;
					cout << "\t\t===============================================================\n" << endl;
				} else {
					// Valid input, break out of the loop
					break;
				}
			} while (true);

			c "\n" << foods.at(number_to_delete - 1) << " is selected!\n";

			do {
				cout << "\nPress R to remove Item, Press D to decrease the quantity: ";
				if (!(cin >> r_or_d) || (toupper(r_or_d) != 'R' && toupper(r_or_d) != 'D')) {
					// Input is not a valid character or not 'R' or 'D'
					cin.clear();  // Clear the error flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
					cout << "\n\t\t============================================" << endl;
					cout << "\t\t  Invalid input. Please enter 'R' or 'D'.\n";
					cout << "\t\t============================================\n" << endl;
				} else {
					// Valid input, break out of the loop
					break;
				}
			} while (true);

			if (r_or_d == 'r' || r_or_d == 'R') { // r

				char sure_or_not;
				do {
					c "Are you sure? [y/n]: ";
					if (!(cin >> sure_or_not) || (toupper(sure_or_not) != 'Y' && toupper(sure_or_not) != 'N')) {
						// Input is not a valid character or not 'R' or 'D'
						cin.clear();  // Clear the error flag
						cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
						cout << "\n\t\t============================================" << endl;
						cout << "\t\t  Invalid input. Please enter 'Y' or 'n'.\n";
						cout << "\t\t============================================\n" << endl;
					} else {
						// Valid input, break out of the loop
						break;
					}
				} while (true);

				if (foods.size() == 1) {

					foods.clear();
					no_order_in_lists();

					exit(1);

				} else if (toupper(sure_or_not) == 'Y') {
					foods.erase(foods.begin() + number_to_delete - 1);
					quantity.erase(quantity.begin() + number_to_delete - 1);
					price.erase(price.begin() + number_to_delete - 1);

					// system("cls");
					cout << "\n\t\t=================================" << endl;
					c "\t\t\tItem removed!\n";
					cout << "\t\t=================================\n" << endl;

					display_order();
					c "\n\n";

					c "Do you want to delete your item? [y/n]: ";
					cin >> delete_or_not;

					if (delete_or_not == 'y' || delete_or_not == 'Y') {

						goto start;

					} else {

						// system("cls");
						c "Your overall order is!\n";
						display_order();
						c "\nTotal is: " << get_total() << "\n";
						payment_method(get_total());

						exit(1);

					}
				}



			} else if (r_or_d == 'd' || r_or_d == 'D') {

				if (quantity.size() == 1) {

					int decrease_quantity;

					c "\n" << foods.at(number_to_delete - 1) << " is Selected!\n";

					do {
						cout << "\nEnter Number to decrease the Quantity: ";

						if (!(cin >> decrease_quantity) || decrease_quantity <= 0 || decrease_quantity > quantity.size()) {
							// Input is not a valid non-negative integer
							cin.clear();  // Clear the error flag
							cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
							cout << "\n\t\t===============================================================" << endl;
							cout << "\t\t   Invalid input. Please enter a valid non-negative integer." << endl;
							cout << "\t\t===============================================================\n" << endl;
						} else {
							// Valid input, break out of the loop
							break;
						}
					} while (true);

					//					if(decrease_quantity > quantity.at(number_to_delete-1) || decrease_quantity == quantity.at(number_to_delete-1)){
					//						
					//						c "Invalid Decrease!\n";
					//						exit(1);
					//						
					//					}

					int new_value_of_quantity = quantity.at(number_to_delete - 1) - decrease_quantity;
					quantity.insert(quantity.begin() + number_to_delete - 1, new_value_of_quantity);

					// system("cls");

					cout << "\n\t\t=======================================" << endl;
					c "\t\t\tQuantity is Decresed!\n";
					cout << "\t\t=======================================\n" << endl;
					display_order();
					c "\n\n";

					c "Do you want to delete your item? [y/n]: ";
					cin >> delete_or_not;

					if (delete_or_not == 'y' || delete_or_not == 'Y') {

						goto start;

					} else {

						// system("cls");
						c "Your overall order is!\n";
						display_order();
						c "\nTotal is: " << get_total() << "\n";
						payment_method(get_total());

						exit(1);

					}

				} else if (quantity.size() > 1) {

					int decrease_quantity;

					c "\n" << foods.at(number_to_delete - 1) << " is Selected!\n";

					do {
						cout << "\nEnter Number to decrease the Quantity: ";
						cout << "quantity is: " << quantity.size() << "\n";
						if (!(cin >> decrease_quantity) || decrease_quantity <= 0 || decrease_quantity > quantity.size()) {
							// Input is not a valid non-negative integer
							cin.clear();  // Clear the error flag
							cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
							cout << "\n\t\t===============================================================" << endl;
							cout << "\t\t   Invalid input. Please enter a valid non-negative integer." << endl;
							cout << "\t\t===============================================================\n" << endl;
						} else {
							// Valid input, break out of the loop
							break;
						}
					} while (true);


					int new_value_of_quantity = quantity.at(number_to_delete - 1) - decrease_quantity;


					if (quantity.at(number_to_delete - 1) < 1) {

						foods.erase(foods.begin() + number_to_delete - 1);
						quantity.erase(quantity.begin() + number_to_delete - 1);
						price.erase(price.begin() + number_to_delete - 1);

					} else {

						quantity.erase(quantity.begin() + number_to_delete - 1);
						quantity.insert(quantity.begin() + number_to_delete - 1, new_value_of_quantity);

					}

					cout << "\n\t\t=======================================" << endl;
					c "\t\t\tQuantity is Decresed!\n";
					cout << "\t\t=======================================\n" << endl;

					// system("cls");
					display_order();
					c "\n\n";

					do {
						c "Do you want to delete your item? [y/n]: ";
						if (!(cin >> delete_or_not) || (delete_or_not != 'y' && delete_or_not != 'n')) {
							// Input is not a valid character or not 'y' or 'n'
							cin.clear();  // Clear the error flag
							cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
							cout << "\n\t\t=======================================================" << endl;
							cout << "\t\t\tInvalid input. Please enter 'y' or 'n'." << endl;
							cout << "\t\t=======================================================\n" << endl;
						} else {
							// Valid input, break out of the loop
							break;
						}
					} while (true);

					if (delete_or_not == 'y' || delete_or_not == 'Y') {

						goto start;

					} else {

						// system("cls");
						c "Your overall order is!\n";
						display_order();
						c "\nTotal is: " << get_total() << "\n";
						payment_method(get_total());

						exit(1);

					}
				}
			}

		} else {
			c "Order cancelled!\n";
			exit(1);
		}

	}

	// ============================== Order in Another Menu ==============================
	void order_in_another_burger() {
		char order_in_another;
		if (ready == true) {

			// system("cls");

			do {
				c "Do you want to order in Chicken Burger? [y/n]: ";
				if (!(cin >> order_in_another) || (order_in_another != 'y' && order_in_another != 'n')) {
					// Input is not a valid character or not 'y' or 'n'
					cin.clear();  // Clear the error flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
					cout << "\n\t\t=======================================================" << endl;
					cout << "\t\t\tInvalid input. Please enter 'y' or 'n'." << endl;
					cout << "\t\t=======================================================\n" << endl;
				} else {
					// Valid input, break out of the loop
					break;
				}
			} while (true);

			// system("cls");

			if (order_in_another == 'y' || order_in_another == 'y') {

				ready = false;
				chick_burgers();
				for_chick('c');

			}
		} else {

			// system("cls");

			do {
				c "Do you want to order in Beef Burger? [y/n]: ";
				if (!(cin >> order_in_another) || (order_in_another != 'y' && order_in_another != 'n')) {
					// Input is not a valid character or not 'y' or 'n'
					cin.clear();  // Clear the error flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
					cout << "\n\t\t=======================================================" << endl;
					cout << "\t\t\tInvalid input. Please enter 'y' or 'n'." << endl;
					cout << "\t\t=======================================================\n" << endl;
				} else {
					// Valid input, break out of the loop
					break;
				}
			} while (true);

			// system("cls");

			if (order_in_another == 'y' || order_in_another == 'y') {

				beef_burgers();
				for_beef('b');

			}
		}
	}

	// ============================== Show All Orders ==============================
	void display_order() {

		c "\t\t==================================\n\t\t\tYour Order(s) Are\n\t\t==================================";

		c"\n\n    List(s)\t\t   Quantity\t\t    Price\t\tSubtotal\n\n";

		for (int i = 0;i < foods.size();i++) {
			c "  " << i + 1 << ". " << foods.at(i) << "\t      " << quantity.at(i) << "\t\t\t     " << price.at(i) << "\t\t  " << (price.at(i) * quantity.at(i)) << "\n";
		}
	}

	// ============================== Get Total ==============================
	int get_total() {

		int s = 0;
		for (int i = 0;i < foods.size();i++) {
			s += (quantity.at(i) * price.at(i));
		}
		return s;
	}

	// ============================== Computation of Age ==============================
	void age_comp() {

		do {
			cout << "\nEnter your Age (age >= 60 : 10% Discounted): ";
			if (!(cin >> age) || age < 0) {
				// Input is not a valid non-negative integer
				cin.clear();  // Clear the error flag
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input

				cout << "\n\t\t===============================================================" << endl;
				cout << "\t\t   Invalid input. Please enter a valid non-negative integer." << endl;
				cout << "\t\t===============================================================\n" << endl;
			} else {
				// Valid input, break out of the loop
				break;
			}
		} while (true);

		if (age > 59) {

			cout << "\n\t\t=====================================================" << endl;
			cout << "\t\t   Congratulations! You qualify for a 10% discount." << endl;
			cout << "\t\t=====================================================\n" << endl;

			senior_comp();

		} else if (age < 60) {
			cout << "\n\t\t===========================================================" << endl;
			cout << "\t\t  Unfortunately, you do not qualify for a senior discount." << endl;
			cout << "\t\t===========================================================\n" << endl;
			not_senior_comp();
		}

	}

	// ============================== Senior Citizen Computation ==============================
	void senior_comp() {

		int temp = get_total() * .9;
		int d = get_total() * .10;
		c get_total() << " - " << d << " = " << temp << "\n";
		c "\nYour total payment is: " << temp << "\n";
		temp_for_sum = temp;
		payment_method(temp_for_sum);
	}

	// ============================== !Senior Citizen Computation ==============================
	void not_senior_comp() {

		c "\nYour total payment is: " << get_total() << "\n";
		temp_for_sum = get_total();
		payment_method(temp_for_sum);
	}

	// ============================== Payment Method Area ==============================
	void payment_method(int overall_total) {

		do {
			cout << "\nEnter payment: ";
			if (!(cin >> payment) || payment < 0 || payment == 0) {
				// Input is not a valid non-negative numeric value
				cin.clear();  // Clear the error flag
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
				cout << "\n\t\t===============================================================" << endl;
				cout << "\t\t   Invalid input. Please enter a valid non-negative integer." << endl;
				cout << "\t\t===============================================================\n" << endl;
			} else {
				// Valid input, break out of the loop
				break;
			}
		} while (true);

		if (payment == overall_total) {
			// system("cls");
			c "Thank you Come Again!\n";
			exit(1);
		} else if (payment > overall_total) {
			int p = payment - overall_total;
			// system("cls");
			c "Here is your change: " << p << "\n";
			c "Thank you Come Again!\n";
			exit(1);
		} else if (payment < overall_total) {
			char add_more;
			int add_money;
			cout << "\n\t\t==============================================" << endl;
			cout << "\t\t\tPlease add more " << overall_total - payment << " to pay this!\n";
			cout << "\t\t==============================================\n" << endl;

			while (overall_total > payment) {

				do {
					cout << "\nDo you want to add more? [y/n]: ";
					if (!(cin >> add_more) || (add_more != 'y' && add_more != 'n')) {
						// Input is not a valid character or not 'y' or 'n'
						cin.clear();  // Clear the error flag
						cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
						cout << "\n\t\t=======================================================" << endl;
						cout << "\t\t\tInvalid input. Please enter 'y' or 'n'." << endl;
						cout << "\t\t=======================================================\n" << endl;
					} else {
						// Valid input, break out of the loop
						break;
					}
				} while (true);

				if (add_more == 'y' || add_more == 'Y') {
					do {
						cout << "\nAdd Money: ";
						if (!(cin >> add_money) || add_money < 0 || add_money == 0) {
							// Input is not a valid non-negative numeric value
							cin.clear();  // Clear the error flag
							cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
							cout << "\n\t\t===============================================================" << endl;
							cout << "\t\t   Invalid input. Please enter a valid non-negative integer." << endl;
							cout << "\t\t===============================================================\n" << endl;
						} else {
							// Valid input, break out of the loop
							break;
						}
					} while (true);

					// Use the valid value of add_money here
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
							// system("cls");
							cout << "\nExact Amount, No Change\n";
							c "Thank you Come Again!\n";
							exit(1);
						} else if (payment > overall_total) {
							// system("cls");
							cout << "\nHere is your change " << payment - overall_total << " Thank you for coming and ordering!\n";
							exit(1);
						}
					}

				} else {
					// system("cls");
					delete_item_in_foods();

				}
			}
		}
	} // end of payment_method

	// ============================== If No Orders ==============================
	void no_order_in_lists() {

		char picking;

		// system("cls");
		beef_burgers();
		chick_burgers();
		cout << "\n\t\t=======================================================" << endl;
		c "\t\t\t    No more order, Please order.\n";
		cout << "\t\t=======================================================\n" << endl;
		do {
			cout << "Press B for Beef Burger, Press C for Chicken Burger: ";
			cin >> picking;

			// Clear the input buffer in case of invalid input
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			// Check if the input is valid
			if (toupper(picking) == 'B' || toupper(picking) == 'C') {
				break;  // Exit the loop if the input is valid
			} else {
				cout << "\n\t\t=======================================================" << endl;
				cout << "\t\t\tError message: Please enter B or C." << endl;
				cout << "\t\t=======================================================\n" << endl;
			}
		} while (true);

		// Now, you can use the valid input
		pick_what_menu(toupper(picking));  // Convert to uppercase for consistency

	}
};

// ============================== Main Method ==============================
int main() {
	char pick_menu;

	Burger_POS _burger; /// object created!

	_burger.beef_burgers();
	_burger.chick_burgers();

	// c "Press B for Beef Bugrer, Press C for Chicken Burger: ";
	// cin >> pick_menu;	
	// _burger.pick_what_menu(pick_menu);

	do {
		cout << "Press B for Beef Burger, Press C for Chicken Burger: ";
		cin >> pick_menu;

		// Clear the input buffer in case of invalid input
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// Check if the input is valid
		if (toupper(pick_menu) == 'B' || toupper(pick_menu) == 'C') {
			break;  // Exit the loop if the input is valid
		} else {
			cout << "\n\t\t=======================================================" << endl;
			cout << "\t\t\tError message: Please enter B or C." << endl;
			cout << "\t\t=======================================================\n" << endl;
		}
	} while (true);

	// Now, you can use the valid input
	_burger.pick_what_menu(toupper(pick_menu));  // Convert to uppercase for consistency


	return 0;
}
