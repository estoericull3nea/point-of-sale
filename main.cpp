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
	vector<string> beef_menu_init;
	vector<string> chick_menu_init;

	vector<int> beef_menu_price_init;
	vector<int> chick_menu_price_init;

	vector<string> date_time;
	// --------------------------------

	Burger_POS() {
		beef_menu_init.push_back("Beef Burger"); 	 beef_menu_price_init.push_back(120);
		beef_menu_init.push_back("Cheese Burger");   beef_menu_price_init.push_back(130);
		beef_menu_init.push_back("Beef Bacon"); 	 beef_menu_price_init.push_back(140);
		beef_menu_init.push_back("Creamy Mushroom"); beef_menu_price_init.push_back(100);
		beef_menu_init.push_back("Hawaiian Burger"); beef_menu_price_init.push_back(110);

		chick_menu_init.push_back("Spicy Tandoori");   chick_menu_price_init.push_back(100);
		chick_menu_init.push_back("Spicy Buffalo");    chick_menu_price_init.push_back(100);
		chick_menu_init.push_back("BBQ Chicken");      chick_menu_price_init.push_back(99);
		chick_menu_init.push_back("Crispy Chicken");   chick_menu_price_init.push_back(160);
		chick_menu_init.push_back("Chicken Paradise"); chick_menu_price_init.push_back(190);
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


	return 0;
}
