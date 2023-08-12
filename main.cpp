#include<iostream>
#include<string>
#include<vector>
#define c cout <<

using namespace std;

class Burger_POS{

	public:

		int picking_order;
		char b;
		bool ready;
		int _quantity, age, money, temp_for_sum, payment;
		char order_again;
		
		Burger_POS(){
			b = 'b';
			ready = false;
		}
		
		vector<string> foods;
		vector<int> quantity;
		vector<int> price;
		
		void beef_burgers(){
			
			c "\n\n\t=================== Beef Burgers Menu ====================\n\n";
			
			c "\n   \t\t\tLists\t\tPrice\n\n";
			c "\t\t1. Beef Burger\t\t 120\n";
			c "\t\t2. Cheese Burger\t 130\n";
			c "\t\t3. Beef Bacon\t\t 140\n";
			c "\t\t4. Creamy Mushroom\t 100\n";
			c "\t\t5. Hawaiian Burger\t 110\n";
			
			c "\n\n\t==========================================================\n\n";
			
		} 
		void chick_burgers(){
			
			c "\n\n\t================ Chicken Burgers Menu ====================\n\n";
			
			c "\n   \t\t\tLists\t\tPrice\n\n";
			c "\t\t1. Spicy Tandoori\t 100\n";
			c "\t\t2. Spicy Buffalo\t 100\n";
			c "\t\t3. BBQ Chicken\t\t  99\n";
			c "\t\t4. Crispy Chicken\t 160\n";
			c "\t\t5. Chicken Paradise\t 190\n";
			
			c "\n\n\t==========================================================\n\n";
			
		} 
		
		void pick_what_menu(char menu){
			if(menu == 'b' || menu == 'B'){
				
				system("cls");
				beef_burgers();
				for_beef(menu);
				
			}else if(menu == 'c' || menu == 'C'){
			
				system("cls");
				chick_burgers();
				for_chick(menu);
				
			}else{
				c "Invalid Value!\n";
			}
		}
		
		void for_beef(char b){
			ready = true;
			order_again = 'y';
			
			while(order_again == 'y' || order_again == 'Y'){
				
				c "Enter your order: ";
				cin >> picking_order;
				
				
				c "How many: ";
				cin >> _quantity;
				
				
				if(picking_order == 1){
					
					foods.push_back("Beef Burger    ");
					quantity.push_back(_quantity);
					price.push_back(120);
					
				}else if(picking_order == 2){
					
					foods.push_back("Cheese Burger  ");
					quantity.push_back(_quantity);
					price.push_back(130);
					
				}else if(picking_order == 3){
					
					foods.push_back("Beef Bacon     ");
					quantity.push_back(_quantity);
					price.push_back(140);
					
				}else if(picking_order == 4){
					
					foods.push_back("Creamy Mushroom");
					quantity.push_back(_quantity);
					price.push_back(100);
					
				}else if(picking_order == 5){
					
					foods.push_back("Hawaiian Burger");
					quantity.push_back(_quantity);
					price.push_back(110);
					
				}
				
				c "Do you want to order again? [y/n]: ";
				cin >> order_again;
				
				if(order_again == 'y' || order_again == 'Y'){

					system("cls");
					beef_burgers();
					
				}else{

					order_again = 'n';
					order_in_another_burger();
					display_order();
					c "\nTotal is: " << get_total() << "\n";
					get_total();\
					age_comp();
                    
				}
				
			}
			
		} 
	
		void delete_item_in_foods(){
			
			char delete_or_not, r_or_d;
			int number_to_delete;
			
			c "Do you want to delete your item? [y/n]: ";
			cin >> delete_or_not;
			system("cls");
			
			if(delete_or_not == 'y' || delete_or_not == 'Y'){ // y
				
				start:
				
				display_order();
				
				c "\nEnter number do you want to delete: ";\
				cin >> number_to_delete;
				
				c "\n" << foods.at(number_to_delete-1) << " is selected!\n";
				
				c "\nPress R to remove Item, Press D to decrease the quantity: ";
				cin >> r_or_d;
				
				if(r_or_d == 'r' || r_or_d == 'R'){ // r
					
					if(foods.size() == 1){
						
						foods.clear();
						no_order_in_lists();
						
						exit(1);
						
					}
					
					foods.erase(foods.begin()+number_to_delete-1);
					quantity.erase(quantity.begin()+number_to_delete-1);
					price.erase(price.begin()+number_to_delete-1);
					
					system("cls");
					c "Item removed!\n";
					
					display_order();
					c "\n\n";
					
					c "Do you want to delete your item? [y/n]: ";
					cin >> delete_or_not;
					
					if(delete_or_not == 'y' || delete_or_not == 'Y'){
						
						goto start;
						
					}else{
						
						system("cls");
						c "Your overall order is!\n";
						display_order();
						c "\nTotal is: " << get_total() << "\n";
						payment_method(get_total());
						
						exit(1);
						
					}
					
				}else if(r_or_d == 'd' || r_or_d == 'D'){
					
					if(quantity.size() == 1){
						
						int decrease_quantity;
					
						c "\n" << foods.at(number_to_delete-1) << " is Selected!\n";
						
						c "\nEnter Number to decrease the Quantity: ";
					    cin >> decrease_quantity;
					
					if(decrease_quantity > quantity.at(number_to_delete-1) || decrease_quantity == quantity.at(number_to_delete-1)){
						
						c "Invalid Decrease!\n";
						exit(1);
						
					}
					
					int new_value_of_quantity = quantity.at(number_to_delete-1) - decrease_quantity;
					quantity.insert(quantity.begin() + number_to_delete - 1, new_value_of_quantity);
					
					c "Quantity is Decresed!\n";
					
					system("cls");
					display_order();
					c "\n\n";
					
					c "Do you want to delete your item? [y/n]: ";
					cin >> delete_or_not;
					
					if(delete_or_not == 'y' || delete_or_not == 'Y'){
						
						goto start;
						
					}else{
						
						system("cls");
						c "Your overall order is!\n";
						display_order();
						c "\nTotal is: " << get_total() << "\n";
						payment_method(get_total());
						
						exit(1);
						
					}
						
					}else if(quantity.size() > 1){
						
						int decrease_quantity;
					
						c "\n" << foods.at(number_to_delete-1) << " is Selected!\n";
						
						c "\nEnter Number to decrese the Quantity: ";
						cin >> decrease_quantity;
						
						
						int new_value_of_quantity = quantity.at(number_to_delete-1) - decrease_quantity;
						
						
						if(quantity.at(number_to_delete-1) < 1){
							
							foods.erase(foods.begin()+number_to_delete-1);
							quantity.erase(quantity.begin()+number_to_delete-1);
							price.erase(price.begin()+number_to_delete-1);
							
						}else{
							
							quantity.erase(quantity.begin()+number_to_delete-1);
							quantity.insert(quantity.begin() + number_to_delete - 1, new_value_of_quantity);
							
						}
						
						c "Quantity is Decresed!\n";
						
						system("cls");
						display_order();
						c "\n\n";
						
						c "Do you want to delete your item? [y/n]: ";
						cin >> delete_or_not;
						
						if(delete_or_not == 'y' || delete_or_not == 'Y'){
							
							goto start;
							
						}else{
							
							system("cls");
							c "Your overall order is!\n";
							display_order();
							c "\nTotal is: " << get_total() << "\n";
							payment_method(get_total());
							
							exit(1);
							
						}
					}
				}
				
			}else{
				c "Order Canceled!\n";
				exit(1);
			}
			
		} 
		
		void for_chick(char b){ 
			
			order_again = 'y';
			
			while(order_again == 'y' || order_again == 'Y'){
				
				c "Enter your order: ";
				cin >> picking_order;
				
				
				c "How many: ";
				cin >> _quantity;
				
				if(picking_order == 1){
					
					foods.push_back("Spicy Tandoori  ");
					quantity.push_back(_quantity);
					price.push_back(100);
					
				}else if(picking_order == 2){
					
					foods.push_back("Spicy Buffalo   ");
					quantity.push_back(_quantity);
					price.push_back(100);
					
				}else if(picking_order == 3){
					
					foods.push_back("BBQ Chicken     ");
					quantity.push_back(_quantity);
					price.push_back(99);
					
				}else if(picking_order == 4){
					
					foods.push_back("Crispy Chicken  ");
					quantity.push_back(_quantity);
					price.push_back(160);
					
				}else if(picking_order == 5){
					
					foods.push_back("Chicken Paradise");
					quantity.push_back(_quantity);
					price.push_back(190);
					
				}
				
				c "Do you want to order again? [y/n]: ";
				cin >> order_again;
				
				if(order_again == 'y' || order_again == 'Y'){
					//counter++;
					//foods.resize(counter);
					system("cls");
					chick_burgers();
					
				}else{
					order_again = 'n';
					order_in_another_burger();
					display_order();
					c "\nTotal is: " << get_total() << "\n";
					get_total();\
					age_comp();
				}
			} 
			
		} 
		
		void order_in_another_burger(){
			char order_in_another;
			if(ready == true){
				
				system("cls");
				c "Do you want to order in Chicken Burger? [y/n]: ";
				cin >> order_in_another;
				system("cls");
				
				if(order_in_another == 'y' || order_in_another == 'y'){
					
					ready = false;
					chick_burgers();
					for_chick('c');
					
				}
			}else{
				
				system("cls");
				c "Do you want to order in Beef Burger? [y/n]: ";
				cin >> order_in_another;
				system("cls");
				
				if(order_in_another == 'y' || order_in_another == 'y'){
					
					beef_burgers();
					for_beef('b');
					
				}
			}
		} 
		
		void display_order(){
			
			c "\n===> Your order are!\n";
			
			c"\n\n    List(s)\t\t   Quantity\n\n";
			
			for(int i=0;i<foods.size();i++){
				c "  " << i+1 << ". " << foods.at(i) << "\t      " << quantity.at(i) << "\n";
			}
		}
		
		int get_total(){
			
			int s=0;
			for(int i=0;i<foods.size();i++){
				s += (quantity.at(i) * price.at(i));
			}
			return s;
		}
		
		void age_comp(){
			
			c "\nEnter Age: ";
			cin >> age;
			
			if(age > 59){
				c "\n\nSenior Citizen, 10 Percent Dicounted!\n";
				senior_comp();
				
			}else if(age < 60){
				c "\n\nNot Senior!\n";
				not_senior_comp();
			}
			
		}
		
		void senior_comp(){
			
			int temp = get_total() * .9;
			int d = get_total() * .10;
			c get_total() << " - " << d << " = " << temp << "\n";
			c "\nYour total payment is: " << temp << "\n";
			temp_for_sum = temp;
			payment_method(temp_for_sum);
		}
		
		void not_senior_comp(){
			
			c "\nYour total payment is: " << get_total() << "\n";
			temp_for_sum = get_total();
			payment_method(temp_for_sum);
		}
		
		void payment_method(int overall_total){
			
			c "\nEnter payment: ";
			cin >> payment;
			
			if(payment == overall_total){
				system("cls");
				c "Thank you Come Again!\n";
				exit(1);
			}else if(payment > overall_total){
				int p = payment - overall_total;
				system("cls");
				c "Here is your change: " << p << "\n";
				c "Thank you Come Again!\n";
				exit(1);
			}else if(payment < overall_total){
				char add_more;
				int add_money;
				cout << "\nPlease add more " << overall_total - payment << " to pay this!\n";

				while(overall_total > payment){
				cout << "\nDo you want to add more? [y/n]: ";
				cin >> add_more;
					if(add_more == 'y' || add_more == 'Y'){
						cout << "\nAdd Money: ";
						cin >> add_money;
							if(add_money <= 0){
								cout << "\nInvalid Input of Money\n";
							}else{
								add_money += payment;
								payment = add_money;
								 if(payment < overall_total){
									cout << "\nAdd more " << overall_total - payment << "\n";
								}else if(payment == overall_total){
									system("cls");
									cout << "\nExact Amount, No Change\n";
									c "Thank you Come Again!\n";
									exit(1);
								}else if(payment > overall_total){
									system("cls");
									cout << "\nHere is your change "<< payment - overall_total << " Thank you for coming and ordering!\n";
									exit(1);
								}
							}

					}else{
						system("cls");
						delete_item_in_foods();
						
					}
			}
			}
		} // end of payment_method
		
		void no_order_in_lists(){
			
			char picking;
			
			system("cls");
			beef_burgers();
			chick_burgers();
			c "\nNo more order, Please order!!\n";
			c "Press B for Beef Bugrer, Press C for Chicken Burger: ";
			cin >> picking;
			pick_what_menu(picking);
			
		}
};

int main(){
	char pick_menu;
	
	Burger_POS _burger; /// object created!
	
	
	_burger.beef_burgers();
	_burger.chick_burgers();
	
	c "Press B for Beef Bugrer, Press C for Chicken Burger: ";
	cin >> pick_menu;	
	
	_burger.pick_what_menu(pick_menu);
	return 0;
}