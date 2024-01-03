#include<iostream>
#include<string>
#include<vector>
#include <limits>
#define c cout <<
using namespace std;

class Burger_POS {

public:

	int picking_order;
	char b;
	bool ready;
	int _quantity, age, money, temp_for_sum, payment;
	char order_again;

	vector<string> foods;
	vector<int> quantity;
	vector<int> price;

	vector<string> beef_menu_init;
	vector<string> chick_menu_init;

	Burger_POS() {
		b = 'b';
		ready = false;

		beef_menu_init.push_back("Beef Burger");
		beef_menu_init.push_back("Cheese Burger");
		beef_menu_init.push_back("Beef Bacon");
		beef_menu_init.push_back("Creamy Mushroom");
		beef_menu_init.push_back("Hawaiian Burger");

		chick_menu_init.push_back("Spicy Tandoori");
		chick_menu_init.push_back("Spicy Buffalo");
		chick_menu_init.push_back("BBQ Chicken");
		chick_menu_init.push_back("Crispy Chicken");
		chick_menu_init.push_back("Chicken Paradise");
	}

	void show_beef_burgers_menu() {
		c "\n\t=======================================================================================================================\n";
		c "\n\n\t\t\t\t\t=================== Beef Burgers Menu ====================\n\n";
		c "\n   \t\t\t\t\t\t\t\tLists\t\tPrice\n\n";
		c "\t\t\t\t\t\t\t1. Beef Burger\t\t 120\n";
		c "\t\t\t\t\t\t\t2. Cheese Burger\t 130\n";
		c "\t\t\t\t\t\t\t3. Beef Bacon\t\t 140\n";
		c "\t\t\t\t\t\t\t4. Creamy Mushroom\t 100\n";
		c "\t\t\t\t\t\t\t5. Hawaiian Burger\t 110\n";
		c "\n\n\t\t\t\t\t==========================================================\n\n";
		c "\n\t=======================================================================================================================\n";
	}

	void show_chick_burgers_menu() {
		c "\n\t=======================================================================================================================\n";
		c "\n\n\t\t\t\t\t================ Chicken Burgers Menu ====================\n\n";
		c "\n   \t\t\t\t\t\t\t\tLists\t\tPrice\n\n";
		c "\t\t\t\t\t\t\t1. Spicy Tandoori\t 100\n";
		c "\t\t\t\t\t\t\t2. Spicy Buffalo\t 100\n";
		c "\t\t\t\t\t\t\t3. BBQ Chicken\t\t  99\n";
		c "\t\t\t\t\t\t\t4. Crispy Chicken\t 160\n";
		c "\t\t\t\t\t\t\t5. Chicken Paradise\t 190\n";
		c "\n\n\t\t\t\t\t==========================================================\n\n";
		c "\n\t=======================================================================================================================\n";
	}

	void pick_what_menu(char menu) {
		if (toupper(menu) == 'B') {
			show_beef_burgers_menu();
			for_beef();
		} else if (toupper(menu) == 'C') {
			show_chick_burgers_menu();
			for_chick();
		}
	}

	void for_beef() {

		ready = true;
		order_again = 'y';

		while (order_again == 'y' || order_again == 'Y') {

			do {
				cout << "Enter your order [1-5]: ";
				if (!(cin >> picking_order) || picking_order < 1 || picking_order > 5) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\n\t\t===============================================================" << endl;
					cout << "\t\t  Error message: Please enter a valid integer between 1 and 5." << endl;
					cout << "\t\t===============================================================\n" << endl;
				} else {
					break;
				}
			} while (true);

			cout << "\n" << beef_menu_init.at(picking_order - 1) << " is selected!\n\n";

			do {
				cout << "How many " << beef_menu_init.at(picking_order - 1) << ": ";
				if (!(cin >> _quantity) || _quantity < 1) {

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					cout << "\n\t\t===============================================================" << endl;
					cout << "\t\t  Error message: Please enter a valid integer & valid quantity." << endl;
					cout << "\t\t===============================================================\n" << endl;
				} else {

					break;
				}
			} while (true);

			cout << "\nOrder(s) made!\n\n";
			cout << "Order: " << beef_menu_init.at(picking_order - 1) << "\n";
			cout << "Quantity: " << _quantity << "\n\n";

		start:
			char edit_or_not;
			do {
				cout << "Do you want to edit your order? [y/n]: ";
				if (!(cin >> edit_or_not) || (toupper(edit_or_not) != 'Y' && toupper(edit_or_not) != 'N')) {

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\n\t\t=======================================================" << endl;
					cout << "\t\t\tInvalid input. Please enter 'y' or 'n'." << endl;
					cout << "\t\t=======================================================\n" << endl;
				} else {

					break;
				}
			} while (true);

			if (toupper(edit_or_not) == 'Y') {
				cout << "\n1. Edit.\n";
				cout << "2. Cancel edit.\n\n";

				int choice;

				do {
					cout << "Enter your choice: ";
					if (!(cin >> choice) || choice < 0 || choice > 2) {

						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n\t\t===============================================================" << endl;
						cout << "\t\t  Error message: Please enter a valid integer between 1 and 2." << endl;
						cout << "\t\t===============================================================\n" << endl;
					} else {

						break;
					}
				} while (true);

				if (choice == 1) {
					cout << "\n1. " << "Order.\n";
					cout << "2. " << "Quantity.\n\n";

					int option;
					do {
						cout << "What do you edit: ";
						if (!(cin >> option) || option < 1 || option > 2) {

							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "\n\t\t===============================================================" << endl;
							cout << "\t\t  Error message: Please enter a valid integer between 1 and 2." << endl;
							cout << "\t\t===============================================================\n" << endl;
						} else {

							break;
						}
					} while (true);

					if (option == 1) {
						show_beef_burgers_menu();
						show_chick_burgers_menu();
						char pick_menu;
						cout << "Previous order is: " << beef_menu_init.at(picking_order - 1) << " (beef menu) and quantity is " << _quantity << "\n";

						do {

							cout << "\nB - Beef Menu\n";
							cout << "C - Chicken Menu\n";
							cout << "Q - Exit\n\n";
							cout << "Please select valid letter: ";

							cin >> pick_menu;

							if (toupper(pick_menu) == 'Q') {
								exit(1);
							}


							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');


							if (toupper(pick_menu) == 'B' || toupper(pick_menu) == 'C') {
								break;
							} else {

								show_beef_burgers_menu();
								show_chick_burgers_menu();

								cout << "\n\t\t=======================================================" << endl;
								cout << "\t\t\tError message: Please enter B or C." << endl;
								cout << "\t\t=======================================================\n" << endl;
							}
						} while (true);

						if (toupper(pick_menu) == 'B') {
							do {
								show_beef_burgers_menu();
								cout << "Enter your order [1-5]: ";
								if (!(cin >> picking_order) || picking_order < 1 || picking_order > 5) {

									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cout << "\n\t\t===============================================================" << endl;
									cout << "\t\t  Error message: Please enter a valid integer between 1 and 5." << endl;
									cout << "\t\t===============================================================\n" << endl;
								} else {

									break;
								}
							} while (true);

							cout << "\n" << beef_menu_init.at(picking_order - 1) << " is selected!\n\n";
							cout << "Order Edited\n";

							cout << "\nOrder(s) made!\n\n";
							cout << "Order: " << beef_menu_init.at(picking_order - 1) << "\n";
							cout << "Quantity: " << _quantity << "\n\n";

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

							goto start;
						} else if (toupper(pick_menu) == 'C') {
							do {
								show_chick_burgers_menu();
								cout << "Enter your order [1-5]: ";
								if (!(cin >> picking_order) || picking_order < 1 || picking_order > 5) {

									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cout << "\n\t\t===============================================================" << endl;
									cout << "\t\t  Error message: Please enter a valid integer between 1 and 5." << endl;
									cout << "\t\t===============================================================\n" << endl;
								} else {

									break;
								}
							} while (true);

							cout << "\n" << chick_menu_init.at(picking_order - 1) << " is selected!\n\n";


							cout << "Order Edited\n";

							cout << "\nOrder(s) made!\n\n";
							cout << "Order: " << chick_menu_init.at(picking_order - 1) << "\n";
							cout << "Quantity: " << _quantity << "\n\n";

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

							goto start;
						}
					} else if (option == 2) {
						cout << "Previous quantity of " << beef_menu_init.at(picking_order - 1) << " is " << _quantity << "\n";

						do {
							cout << "Enter new quantity: ";
							if (!(cin >> _quantity) || _quantity < 1) {

								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');

								cout << "\n\t\t===============================================================" << endl;
								cout << "\t\t  Error message: Please enter a valid integer & valid quantity." << endl;
								cout << "\t\t===============================================================\n" << endl;
							} else {

								break;
							}
						} while (true);

						cout << "\nOrder(s) made!\n\n";
						cout << "Order: " << beef_menu_init.at(picking_order - 1) << "\n";
						cout << "Quantity: " << _quantity << "\n\n";

						goto start;
					}
				} else if (choice == 2) {
					cout << "Cancelled.\n";
				}
			} else {
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
			}

			do {
				cout << "Do you want to order again? [y/n]: ";
				if (!(cin >> order_again) || (order_again != 'y' && order_again != 'n')) {

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\n\t\t=======================================================" << endl;
					cout << "\t\t\tInvalid input. Please enter 'y' or 'n'." << endl;
					cout << "\t\t=======================================================\n" << endl;
				} else {

					break;
				}
			} while (true);

			if (order_again == 'y' || order_again == 'Y') {

				show_beef_burgers_menu();

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

	void for_chick() {

		order_again = 'y';

		while (order_again == 'y' || order_again == 'Y') {

			do {

				cout << "Enter your order [1-5]: ";
				if (!(cin >> picking_order) || picking_order < 1 || picking_order > 5) {

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					cout << "\n\t\t===============================================================" << endl;
					cout << "\t\t  Error message: Please enter a valid integer between 1 and 5." << endl;
					cout << "\t\t===============================================================\n" << endl;

				} else {

					break;
				}
			} while (true);

			cout << "\n" << chick_menu_init.at(picking_order - 1) << " is selected!\n\n";

			do {
				cout << "How many " << chick_menu_init.at(picking_order - 1) << ": ";
				if (!(cin >> _quantity) || _quantity < 1) {

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					cout << "\n\t\t===============================================================" << endl;
					cout << "\t\t  Error message: Please enter a valid integer & valid quantity." << endl;
					cout << "\t\t===============================================================\n" << endl;
				} else {

					break;
				}
			} while (true);

			cout << "\nOrder(s) made!\n\n";
			cout << "Order: " << chick_menu_init.at(picking_order - 1) << "\n";
			cout << "Quantity: " << _quantity << "\n\n";

		start:
			char edit_or_not;
			do {
				cout << "Do you want to edit your order? [y/n]: ";
				if (!(cin >> edit_or_not) || (toupper(edit_or_not) != 'Y' && toupper(edit_or_not) != 'N')) {

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\n\t\t=======================================================" << endl;
					cout << "\t\t\tInvalid input. Please enter 'y' or 'n'." << endl;
					cout << "\t\t=======================================================\n" << endl;
				} else {

					break;
				}
			} while (true);

			if (toupper(edit_or_not) == 'Y') {
				cout << "\n1. Edit.\n";
				cout << "2. Cancel edit.\n\n";

				int choice;

				do {
					cout << "Enter your choice: ";
					if (!(cin >> choice) || choice < 0 || choice > 2) {

						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n\t\t===============================================================" << endl;
						cout << "\t\t  Error message: Please enter a valid integer between 1 and 2." << endl;
						cout << "\t\t===============================================================\n" << endl;
					} else {

						break;
					}
				} while (true);

				if (choice == 1) {
					cout << "\n1. " << "Order.\n";
					cout << "2. " << "Quantity.\n\n";

					int option;
					do {
						cout << "What do you edit: ";
						if (!(cin >> option) || option < 1 || option > 2) {

							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "\n\t\t===============================================================" << endl;
							cout << "\t\t  Error message: Please enter a valid integer between 1 and 2." << endl;
							cout << "\t\t===============================================================\n" << endl;
						} else {

							break;
						}
					} while (true);

					if (option == 1) {

						show_beef_burgers_menu();
						show_chick_burgers_menu();

						char pick_menu;
						cout << "Previous order is: " << chick_menu_init.at(picking_order - 1) << " (chicken menu) and quantity is " << _quantity << "\n";

						do {

							cout << "\nB - Beef Menu\n";
							cout << "C - Chicken Menu\n";
							cout << "Q - Exit\n\n";
							cout << "Please select valid letter: ";
							cin >> pick_menu;

							if (toupper(pick_menu) == 'Q') {
								exit(1);
							}

							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');


							if (toupper(pick_menu) == 'B' || toupper(pick_menu) == 'C') {
								break;
							} else {

								show_beef_burgers_menu();
								show_chick_burgers_menu();

								cout << "\n\t\t=======================================================" << endl;
								cout << "\t\t\tError message: Please enter B or C." << endl;
								cout << "\t\t=======================================================\n" << endl;
							}
						} while (true);

						if (toupper(pick_menu) == 'C') {
							do {
								show_chick_burgers_menu();
								cout << "Enter your order [1-5]: ";
								if (!(cin >> picking_order) || picking_order < 1 || picking_order > 5) {

									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cout << "\n\t\t===============================================================" << endl;
									cout << "\t\t  Error message: Please enter a valid integer between 1 and 5." << endl;
									cout << "\t\t===============================================================\n" << endl;
								} else {

									break;
								}
							} while (true);

							cout << "\n" << chick_menu_init.at(picking_order - 1) << " is selected!\n\n";
							cout << "Order Edited\n";

							cout << "\nOrder(s) made!\n\n";
							cout << "Order: " << chick_menu_init.at(picking_order - 1) << "\n";
							cout << "Quantity: " << _quantity << "\n\n";

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

						} else if (toupper(pick_menu) == 'B') {
							do {
								show_beef_burgers_menu();
								cout << "Enter your order [1-5]: ";
								if (!(cin >> picking_order) || picking_order < 1 || picking_order > 5) {

									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cout << "\n\t\t===============================================================" << endl;
									cout << "\t\t  Error message: Please enter a valid integer between 1 and 5." << endl;
									cout << "\t\t===============================================================\n" << endl;
								} else {

									break;
								}
							} while (true);

							cout << "\n" << beef_menu_init.at(picking_order - 1) << " is selected!\n\n";
							cout << "Order Edited\n";

							cout << "\nOrder(s) made!\n\n";
							cout << "Order: " << beef_menu_init.at(picking_order - 1) << "\n";
							cout << "Quantity: " << _quantity << "\n\n";

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

						}
					} else if (option == 2) {
						cout << "Previous quantity of " << chick_menu_init.at(picking_order - 1) << " is " << _quantity << "\n";

						do {
							cout << "Enter new quantity: ";
							if (!(cin >> _quantity) || _quantity < 1) {

								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');

								cout << "\n\t\t===============================================================" << endl;
								cout << "\t\t  Error message: Please enter a valid integer & valid quantity." << endl;
								cout << "\t\t===============================================================\n" << endl;
							} else {

								break;
							}
						} while (true);

						cout << "\nOrder(s) made!\n\n";
						cout << "Order: " << chick_menu_init.at(picking_order - 1) << "\n";
						cout << "Quantity: " << _quantity << "\n\n";

						goto start;
					}
				} else if (choice == 2) {
					cout << "Cancelled.\n";
				}
			} else {
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
			}

			do {
				cout << "Do you want to order again? [y/n]: ";
				if (!(cin >> order_again) || (order_again != 'y' && order_again != 'n')) {

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\n\t\t=======================================================" << endl;
					cout << "\t\t\tInvalid input. Please enter 'y' or 'n'." << endl;
					cout << "\t\t=======================================================\n" << endl;
				} else {

					break;
				}
			} while (true);

			if (order_again == 'y' || order_again == 'Y') {
				show_chick_burgers_menu();

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

	void delete_item_in_foods() {

		char delete_or_not, r_or_d;
		int number_to_delete;

		do {
			c "Do you want to delete your item? [y/n]: ";
			if (!(cin >> delete_or_not) || (delete_or_not != 'y' && delete_or_not != 'n')) {

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\n\t\t=======================================================" << endl;
				cout << "\t\t\tInvalid input. Please enter 'y' or 'n'." << endl;
				cout << "\t\t=======================================================\n" << endl;
			} else {
				break;
			}
		} while (true);


		if (delete_or_not == 'y' || delete_or_not == 'Y') {
		start:
			display_order();
			do {
				cout << "\nEnter number do you want to delete: ";
				if (!(cin >> number_to_delete) || number_to_delete <= 0 || number_to_delete > foods.size()) {

					cout << number_to_delete << "\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\n\t\t===============================================================" << endl;
					cout << "\t\t   Invalid input. Please enter a valid non-negative integer." << endl;
					cout << "\t\t===============================================================\n" << endl;
				} else {

					break;
				}
			} while (true);

			c "\n" << foods.at(number_to_delete - 1) << " is selected!\n";

			do {
				cout << "\nPress R to remove Item, Press D to decrease the quantity: ";
				if (!(cin >> r_or_d) || (toupper(r_or_d) != 'R' && toupper(r_or_d) != 'D')) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\n\t\t============================================" << endl;
					cout << "\t\t  Invalid input. Please enter 'R' or 'D'.\n";
					cout << "\t\t============================================\n" << endl;
				} else {
					break;
				}
			} while (true);

			if (r_or_d == 'r' || r_or_d == 'R') {

				char sure_or_not;
				do {
					c "Are you sure? [y/n]: ";
					if (!(cin >> sure_or_not) || (toupper(sure_or_not) != 'Y' && toupper(sure_or_not) != 'N')) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n\t\t============================================" << endl;
						cout << "\t\t  Invalid input. Please enter 'Y' or 'n'.\n";
						cout << "\t\t============================================\n" << endl;
					} else {
						break;
					}
				} while (true);

				if (toupper(sure_or_not) == 'Y') {

					foods.erase(foods.begin() + number_to_delete - 1);
					quantity.erase(quantity.begin() + number_to_delete - 1);
					price.erase(price.begin() + number_to_delete - 1);

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
						c "Your overall order is!\n";
						display_order();
						c "\nTotal is: " << get_total() << "\n";
						payment_method(get_total());
					}
				}

			} else if (r_or_d == 'd' || r_or_d == 'D') {

				if (quantity.size() == 1) {

					int decrease_quantity;

					c "\n" << foods.at(number_to_delete - 1) << " is Selected!\n";

					do {
						cout << "\nEnter Number to decrease the Quantity: ";

						if (!(cin >> decrease_quantity) || decrease_quantity <= 0 || decrease_quantity > quantity.at(number_to_delete - 1)) {

							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "\n\t\t===============================================================" << endl;
							cout << "\t\t   Invalid input. Please enter a valid non-negative integer." << endl;
							cout << "\t\t===============================================================\n" << endl;
						} else {

							break;
						}
					} while (true);

					if (foods.size() == 1) {

						foods.clear();
						quantity.clear();
						price.clear();
						no_order_in_lists();

						exit(1);

					}

					int new_value_of_quantity = quantity.at(number_to_delete - 1) - decrease_quantity;
					quantity.insert(quantity.begin() + number_to_delete - 1, new_value_of_quantity);

					cout << "\n\t\t=======================================" << endl;
					c "\t\t\tQuantity is Decresed!\n";
					cout << "\t\t=======================================\n" << endl;
					if (quantity.at(number_to_delete - 1) == 0) {
						foods.erase(foods.begin() + (number_to_delete - 1));
						price.erase(price.begin() + (number_to_delete - 1));
						quantity.erase(quantity.begin() + (number_to_delete - 1));
					}

					if (foods.size() == 1) {

						display_order();
						c "\n\n";

						do {
							c "Do you want to delete your item? [y/n]: ";
							if (!(cin >> delete_or_not) || (delete_or_not != 'y' && delete_or_not != 'n')) {

								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "\n\t\t=======================================================" << endl;
								cout << "\t\t\tInvalid input. Please enter 'y' or 'n'." << endl;
								cout << "\t\t=======================================================\n" << endl;
							} else {

								break;
							}
						} while (true);

						if (delete_or_not == 'y' || delete_or_not == 'Y') {

							goto start;

						} else {
							c "Your overall order is!\n";
							display_order();
							c "\nTotal is: " << get_total() << "\n";
							payment_method(get_total());
							exit(1);
						}
					} else {
						no_order_in_lists();
					}

				} else if (quantity.size() > 1) {

					int decrease_quantity;

					c "\n" << foods.at(number_to_delete - 1) << " is Selected!\n";

					do {
						cout << "\nEnter Number to decrease the Quantity: ";
						if (!(cin >> decrease_quantity) || decrease_quantity <= 0 || decrease_quantity > quantity.at(number_to_delete - 1)) {

							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "\n\t\t===============================================================" << endl;
							cout << "\t\t   Invalid input. Please enter a valid non-negative integer." << endl;
							cout << "\t\t===============================================================\n" << endl;
						} else {

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

					if (quantity.at(number_to_delete - 1) == 0) {
						foods.erase(foods.begin() + (number_to_delete - 1));
						price.erase(price.begin() + (number_to_delete - 1));
						quantity.erase(quantity.begin() + (number_to_delete - 1));
					}

					cout << "\n\t\t=======================================" << endl;
					c "\t\t\tQuantity is Decresed!\n";
					cout << "\t\t=======================================\n" << endl;

					if (foods.size() == 1) {

						display_order();
						c "\n\n";

						do {
							c "Do you want to delete your item? [y/n]: ";
							if (!(cin >> delete_or_not) || (delete_or_not != 'y' && delete_or_not != 'n')) {

								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "\n\t\t=======================================================" << endl;
								cout << "\t\t\tInvalid input. Please enter 'y' or 'n'." << endl;
								cout << "\t\t=======================================================\n" << endl;
							} else {

								break;
							}
						} while (true);

						if (delete_or_not == 'y' || delete_or_not == 'Y') {

							goto start;

						} else {

							c "Your overall order is!\n";
							display_order();
							c "\nTotal is: " << get_total() << "\n";
							payment_method(get_total());
							exit(1);

						}
					} else {
						no_order_in_lists();
					}
				}
			}

		} else {
			c "Order cancelled!\n";
			exit(1);
		}
	}

	void order_in_another_burger() {
		char order_in_another;
		if (ready == true) {

			do {
				c "Do you want to order in Chicken Burger? [y/n]: ";
				if (!(cin >> order_in_another) || (order_in_another != 'y' && order_in_another != 'n')) {

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\n\t\t=======================================================" << endl;
					cout << "\t\t\tInvalid input. Please enter 'y' or 'n'." << endl;
					cout << "\t\t=======================================================\n" << endl;
				} else {
					break;
				}
			} while (true);

			if (order_in_another == 'y' || order_in_another == 'y') {

				ready = false;
				show_chick_burgers_menu();
				for_chick();

			}
		} else {

			do {
				c "Do you want to order in Beef Burger? [y/n]: ";
				if (!(cin >> order_in_another) || (order_in_another != 'y' && order_in_another != 'n')) {

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\n\t\t=======================================================" << endl;
					cout << "\t\t\tInvalid input. Please enter 'y' or 'n'." << endl;
					cout << "\t\t=======================================================\n" << endl;
				} else {
					break;
				}
			} while (true);

			if (order_in_another == 'y' || order_in_another == 'y') {

				show_beef_burgers_menu();
				for_beef();

			}
		}
	}

	void display_order() {

		char edit_or_not;
		int index;

		if (foods.size() > 0) {
			c "\t\t==================================\n\t\t\tYour Order(s) Are\n\t\t==================================";
			c"\n\n    List(s)\t\t   Quantity\t\t    Price\t\tSubtotal\n\n";
			for (int i = 0;i < foods.size();i++) {
				c "  " << i + 1 << ". " << foods.at(i) << "\t      " << quantity.at(i) << "\t\t\t     " << price.at(i) << "\t\t  " << (price.at(i) * quantity.at(i)) << "\n";
			}

			do {
				cout << "\nDo you want to edit your order? [y/n]: ";
				if (!(cin >> edit_or_not) || (toupper(edit_or_not) != 'Y' && toupper(edit_or_not) != 'N')) {

					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\n\t\t=======================================================" << endl;
					cout << "\t\t\tInvalid input. Please enter 'y' or 'n'." << endl;
					cout << "\t\t=======================================================\n" << endl;
				} else {

					break;
				}
			} while (true);

			if (toupper(edit_or_not) == 'Y') {
				do {
					cout << "Enter number to edit: ";
					if (!(cin >> index) || index < 0 || index > foods.size()) {

						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n\t\t=======================================================" << endl;
						cout << "\t\t\tInvalid input. Please enter integer only" << endl;
						cout << "\t\t=======================================================\n" << endl;
					} else {

						break;
					}
				} while (true);
				edit_order_by_index(index);
			}

		} else {
			no_order_in_lists();
		}
	}

	void edit_order_by_index(int index) {
		index--;
		char pick_menu;

		c "\t\t==================================\n\t\t\tYour Order Is\n\t\t==================================";
		c"\n\n    List(s)\t\t   Quantity\t\t    Price\t\tSubtotal\n\n";
		c "  " << index + 1 << ". " << foods.at(index) << "\t      " << quantity.at(index) << "\t\t\t     " << price.at(index) << "\t\t  " << (price.at(index) * quantity.at(index)) << "\n";

		int select;
		do {

			cout << "\n1. Order\n2. Quantity\n\n";
			cout << "Select what you want to edit: ";
			cin >> select;

			if (cin.fail() || select <= 0) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input. Please enter a valid positive integer.\n";
			} else {
				break;
			}
		} while (true);
		if (select == 1) {
			do {

				show_beef_burgers_menu();
				show_chick_burgers_menu();
				cout << "\nB - Beef Menu\n";
				cout << "C - Chicken Menu\n";
				cout << "Q - Exit\n\n";
				cout << "Please select valid letter: ";
				cin >> pick_menu;

				if (toupper(pick_menu) == 'Q') {
					exit(1);
				}

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');


				if (toupper(pick_menu) == 'B' || toupper(pick_menu) == 'C') {
					break;
				} else {

					show_beef_burgers_menu();
					show_chick_burgers_menu();

					cout << "\n\t\t=======================================================" << endl;
					cout << "\t\t\tError message: Please enter B or C." << endl;
					cout << "\t\t=======================================================\n" << endl;
				}
			} while (true);

			if (toupper(pick_menu) == 'B') {
				show_beef_burgers_menu();

				int picking_order;
				do {
					cout << "Enter your order [1-5]: ";
					if (!(cin >> picking_order) || picking_order < 1 || picking_order > 5) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n\t\t===============================================================" << endl;
						cout << "\t\t  Error message: Please enter a valid integer between 1 and 5." << endl;
						cout << "\t\t===============================================================\n" << endl;
					} else {
						break;
					}
				} while (true);
				cout << "\n" << beef_menu_init.at(picking_order - 1) << " is selected!\n";

				string new_order = beef_menu_init.at(picking_order - 1);
				foods.at(index) = new_order;
				cout << "\nOrder Edited.\n";
				display_order();


			} else if (toupper(pick_menu) == 'C') {
				show_chick_burgers_menu();

				int picking_order;
				do {
					cout << "Enter your order [1-5]: ";
					if (!(cin >> picking_order) || picking_order < 1 || picking_order > 5) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n\t\t===============================================================" << endl;
						cout << "\t\t  Error message: Please enter a valid integer between 1 and 5." << endl;
						cout << "\t\t===============================================================\n" << endl;
					} else {
						break;
					}
				} while (true);
				cout << "\n" << chick_menu_init.at(picking_order - 1) << " is selected!\n";

				string new_order = chick_menu_init.at(picking_order - 1);
				foods.at(index) = new_order;
				cout << "\nOrder Edited.\n";
				display_order();
			}

		} else if (select == 2) {
			int new_quantity;
			do {
				cout << "Enter new quantity: ";
				if (!(cin >> new_quantity) || new_quantity < 1) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\n\t\t===============================================================" << endl;
					cout << "\t\t  Error message: Please enter a valid integer" << endl;
					cout << "\t\t===============================================================\n" << endl;
				} else {
					break;
				}
			} while (true);
			// code here
			quantity.at(index) = new_quantity;
			cout << "\nQuantity Edited.\n";
			display_order();
		}
	}

	int get_total() {

		int s = 0;
		for (int i = 0;i < foods.size();i++) {
			s += (quantity.at(i) * price.at(i));
		}
		return s;
	}

	void age_comp() {

		do {
			cout << "\nEnter your Age (age >= 60 : 10% Discounted): ";
			if (!(cin >> age) || age <= 0) {

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "\n\t\t===============================================================" << endl;
				cout << "\t\t   Invalid input. Please enter a valid non-negative integer." << endl;
				cout << "\t\t===============================================================\n" << endl;
			} else {

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

	void senior_comp() {

		int temp = get_total() * .9;
		int d = get_total() * .10;
		c get_total() << " - " << d << " = " << temp << "\n";
		c "\nYour total payment is: " << temp << "\n";
		temp_for_sum = temp;
		payment_method(temp_for_sum);
	}

	void not_senior_comp() {

		c "\nYour total payment is: " << get_total() << "\n";
		temp_for_sum = get_total();
		payment_method(temp_for_sum);
	}

	void payment_method(int overall_total) {

		do {
			cout << "\nEnter payment: ";
			if (!(cin >> payment) || payment < 0 || payment == 0) {

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\n\t\t===============================================================" << endl;
				cout << "\t\t   Invalid input. Please enter a valid non-negative integer." << endl;
				cout << "\t\t===============================================================\n" << endl;
			} else {

				break;
			}
		} while (true);

		if (payment == overall_total) {

			c "Thank you Come Again!\n";
			exit(1);
		} else if (payment > overall_total) {
			int p = payment - overall_total;

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
						if (!(cin >> add_money) || add_money < 0 || add_money == 0) {

							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "\n\t\t===============================================================" << endl;
							cout << "\t\t   Invalid input. Please enter a valid non-negative integer." << endl;
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
					delete_item_in_foods();

				}
			}
		}
	}

	void no_order_in_lists() {

		char picking;

		show_beef_burgers_menu();
		show_chick_burgers_menu();
		cout << "\n\t\t=======================================================" << endl;
		c "\t\t\t    No more order, Please order.\n";
		cout << "\t\t=======================================================\n" << endl;
		do {

			cout << "\nB - Beef Menu\n";
			cout << "C - Chicken Menu\n";
			cout << "Q - Exit\n\n";
			cout << "Please select valid letter: ";
			cin >> picking;

			if (toupper(picking) == 'Q') {
				exit(1);
			}

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');


			if (toupper(picking) == 'B' || toupper(picking) == 'C') {
				break;
			} else {

				show_beef_burgers_menu();
				show_chick_burgers_menu();

				cout << "\n\t\t=======================================================" << endl;
				cout << "\t\t\tError message: Please enter B or C." << endl;
				cout << "\t\t=======================================================\n" << endl;
			}
		} while (true);

		pick_what_menu(toupper(picking));
	}
};

int main() {
	char pick_menu;

	Burger_POS _burger;

	_burger.show_beef_burgers_menu();
	_burger.show_chick_burgers_menu();

	do {
		cout << "\nB - Beef Menu\n";
		cout << "C - Chicken Menu\n";
		cout << "Q - Exit\n\n";
		cout << "Please select valid letter: ";
		cin >> pick_menu;

		if (toupper(pick_menu) == 'Q') {
			exit(1);
		}

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');


		if (toupper(pick_menu) == 'B' || toupper(pick_menu) == 'C') {
			break;
		} else {

			_burger.show_beef_burgers_menu();
			_burger.show_chick_burgers_menu();

			cout << "\n\t\t=======================================================" << endl;
			cout << "\t\t\tError message: Please enter B or C." << endl;
			cout << "\t\t=======================================================\n" << endl;
		}
	} while (true);

	_burger.pick_what_menu(pick_menu);

	return 0;
}
