#include <iostream>
#include <cstring>
#include <windows.h> //for colour, sleep and clear console screen
#include <iomanip>  //for setw, setfill, setprecision

using namespace std;

double totalPayment;

//FUNCTION PROTOTYPE

//function for login/signup
void login();  
void signup(); 

//function for food selection
void displayMenu(int restaurant);
double getPrice(char order);
int getOrderQuantity();
void processOrder(int restaurant, char& order, int& quantity, double& totalPrice);

//function for delivery
double deliveryG(double charges, int totalQuantity);
double deliveryF(double charges, int totalQuantity);

//function for payment
void onlineBanking();  
void cash();  


int main() 
{
	//for colour
	system("color ED"); //yellowpurple
	
	//LOGIN/SIGNUP
	
	cout<<"\n\n\n\n************************************************************************************************************************************************************"<<endl;     
    cout<<"~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ L O G  I N / S I G N  U P ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~"<<endl;
    cout<<setw(158)<<setfill('*')<<endl; //setw
	
 	int userChoice; 
 	char orderOption;

	cout << " \n"; 
	cout << " \t\t\t\t\t\t\t\t\t WELCOME TO MEAL DASH " << endl;
	cout << "\n"; 
	cout << " \t\t\t\t\t\t\t\t\t Please login/signup to continue. "<< endl; 
	cout << " \n \t\t\t\t\t\t\t\t\t (1 for login, 2 for signup.) : "; 
	cin >> userChoice;

	switch (userChoice)
	{
		case 1:
			login();
			break;
		
		case 2:
			signup();
			break;
			
		default:
			cout << "Invalid input. Exiting..." << endl; //invalid input message
			return 0;	
	}
	
	//for sleep function
	Sleep(3000);
	//to clear screen
	system("cls");
	
	
	//FOOD SELECTION
	
	//for colour
	system("color 57");//purplewhite
	
	cout<<"\n\n\n\n************************************************************************************************************************************************************"<<endl;     
    cout<<"~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ F O O D  S E L E C T I O N ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~"<<endl;
    cout<<setw(194)<<setfill('*')<<endl; //setw
	
	int restaurant, i = 1;
    char order;
    int quantity = 0, totalQuantity = 0;
    double totalPrice = 0;
    cout << "\n\n\t\t\t\t\t\t\t\t\t   ========================" << endl;
    cout << "\t\t\t\t\t\t\t\t\t   | [1] Texas Chicken    |" << endl;
    cout << "\t\t\t\t\t\t\t\t\t   | [2] ZUS Coffee       |" << endl;
    cout << "\t\t\t\t\t\t\t\t\t   | [3] Marrybrown       |" << endl;
    cout << "\t\t\t\t\t\t\t\t\t   | [4] Tealive          |" << endl;
    cout << "\t\t\t\t\t\t\t\t\t   ========================" << endl;
    cout << "\n\n" ;
    while ( i != 0 ) {
        do {
            cout << "\n\n\n\t\t\t\t\t\t\t\t\t   CHOOSE RESTAURANT : ";
            cin >> restaurant;
            
            if ( restaurant!=1 && restaurant!=2 && restaurant!=3 && restaurant!=4 ) {
            	cout << "\n\t\t\t\t\t\t\t\t\t   The restaurant you entered is not in the list."<< endl; //invalid input message
            	cout << "\t\t\t\t\t\t\t\t\t   Please choose another option.";
			}
			cout << endl ;
		} while ( restaurant!=1 && restaurant!=2 && restaurant!=3 && restaurant!=4 );

        processOrder(restaurant, order, quantity, totalPrice); // function call
        
        totalQuantity+=quantity;

        cout << "\n\n\t\t\t\t\t\t\t\t\t   Do You Want Add Your Order?" << endl;
        cout << "\t\t\t\t\t\t\t\t\t   Enter 1 to ADD | Enter 0 to SUBMIT" << endl;
        
        do {
        	cout << "\n\t\t\t\t\t\t\t\t\t   ";
        	cin >> i;
        	if ( i!=1 && i!=0 ) {
        		cout<<"\n\t\t\t\t\t\t\t\t\t   Please enter the correct option."<< endl;
			}
		} while( i!=1 && i!=0 );
    }
    
    
    cout.setf(ios::fixed); //set precision
    cout.precision(2);
    cout << "\n\n\t\t\t\t\t\t\t\t\t   T O T A L P R I C E : RM" << totalPrice;
    cout << "\n\n\t\t\t\t\t\t\t\t\t   T O T A L  Q U A N T I T Y  F O O D  O R D E R E D: " <<totalQuantity;
    
    //sleep function
	Sleep(3000);
	//to clear screen
    system("cls");
    
    
    cout<<"\n\n\n\n************************************************************************************************************************************************************"<<endl;     
    cout<<"~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ D E L I V E R Y ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ "<<endl;
    cout<<setw(187)<<setfill('*')<<endl; //setw
    
    
	//DELIVERY 
	
	//for colour
	system("color F1"); //bluewhite
	
    char deliver[] = {'G','F','S'}; //array
    char deliver2, clock[7], address[100], name1[70], phone[12];
    double charges;    
    
    cout<<"\n\n\t\t\t\t\t\t\t\t\t  GrabFood (Enter G)"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t  FoodPanda (Enter F)"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t  Self-Pickup (Enter S)"<<endl; 
    
	
    do
    {
    	cout<<"\n\n\t\t\t\t\t\t\t\t\t  Please choose your delivery option : ";
    	cin>>deliver2;
    	
    	if (deliver[0]==deliver2)
    	{
    		cout<<"\n\n\t\t\t\t\t\t\t\t\t  Enter your name : ";
    		cin>>name1;
    		cin.getline(name1, 70);
    		cout<<"\t\t\t\t\t\t\t\t\t  Enter your phone number : ";
    		cin>>phone;
    		cin.getline(phone, 12);
    		cout<<"\t\t\t\t\t\t\t\t\t  Enter your address : "<<endl;
    		cout<<"\t\t\t\t\t\t\t\t\t   ";
    		cin.getline(address, 100);
    		cout<<"\n\n\t\t\t\t\t\t\t\t\t   Total food ordered : "<<totalQuantity<<endl;
    		
    		
    		charges = deliveryG(0, totalQuantity); //function call
            cout <<"\n\n\t\t\t\t\t\t\t\t\t  Delivery charges: RM" <<charges<<endl;
	   
	   }
	 	else if (deliver[1]==deliver2)
		{
		    cout<<"\n\n\t\t\t\t\t\t\t\t\t   Enter your name : ";
    		cin>>name1;
    		cin.getline(name1, 70);
    		cout<<"\t\t\t\t\t\t\t\t\t   Enter your phone number : ";
    		cin>>phone;
    		cin.getline(phone, 12);
    		cout<<"\t\t\t\t\t\t\t\t\t   Enter your address : "<<endl;
    		cout<<"\t\t\t\t\t\t\t\t\t   ";
    		cin.getline(address, 100);
    		cout<<"\n\n\t\t\t\t\t\t\t\t\t   Total food ordered : "<<totalQuantity<<endl;
    		
    		charges = deliveryF(0, totalQuantity); //function call
    		cout <<"\n\n\t\t\t\t\t\t\t\t\t  Delivery charges: RM" <<charges<<endl;
        }
    	else if (deliver[2]==deliver2)
		{
			cout<<"\n\n\t\t\t\t\t\t\t\t\t   Enter your name : ";
    		cin>>name1;
    		cin.getline(name1, 70);
    		cout<<"\t\t\t\t\t\t\t\t\t   Enter your phone number : ";
    		cin>>phone;
    		cin.getline(phone, 12);
    		cout<<"\t\t\t\t\t\t\t\t\t   Please set pickup time (24H -> 13:15): ";
    		cin>>clock;
		}
		else
		{
			cout<<endl;
			cout<<"\t\t\t\t\t\t\t\t\t   Invalid. Please re-enter! "<<endl; //invalid input message
		}
    		
	}
	while (deliver[0]!=deliver2 && deliver[1]!=deliver2 && deliver[2]!=deliver2);
	
	totalPayment = totalPrice+charges;
    cout<<"\t\t\t\t\t\t\t\t\t  Total Payment : RM "<<totalPayment<<endl;
    
    //sleep function
    Sleep(3000);
    //to clear screen
    system("cls");
    
    
    //METHOD OF PAYMENT
    
	cout<<"\n\n\n\n************************************************************************************************************************************************************"<<endl;     
    cout<<"~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ P A Y M E N T ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ "<<endl;
    cout<<setw(194)<<setfill('*')<<endl;
	
	//for colour
	system("color BC");//lightaqua lightred
	
	int method;
	do
	{
		cout<<"\n\n\t\t\t\t\t\t\t\t  Select method of payment: "<<endl;
		cout<<"\t\t\t\t\t\t\t\t  ---------------------"<<endl;
		cout<<"\t\t\t\t\t\t\t\t  | 1. Online Banking   |"<<endl; 
		cout<<"\t\t\t\t\t\t\t\t  | 2. Cash             |"<<endl;
		cout<<"\t\t\t\t\t\t\t\t  ---------------------"<<endl;
		cout<<"\n\n\t\t\t\t\t\t\t\t  Enter '1' for Online Banking."<<endl;
		cout<<"\t\t\t\t\t\t\t\t  Enter '2' for Cash."<<endl;
		cout<<"\n\n\t\t\t\t\t\t\t\t  Please enter method of payment: ";
		cin>>method;
	
	if(method == 1)
	{
		onlineBanking();  //function call
	}
	else if (method == 2)
	{
		cash();  //function call
	}
	else
	{
		cout<<"\n\t\t\t\t\t\t\t\t   Invalid. Please re-enter again."; //invalid input message
	}
	
    }while(method != 1 && method !=2);
    
    
    cout<<"\n\n\n\n\t\t\t\t\t\t\t     Enjoy your meal and please have a nice day!"<<endl;
    cout<<"\n\n************************************************************************************************************************************************************"<<endl;
    cout<<"~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ T H A N K  Y O U  F O R  U S I N G  M E A L  D A S H ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ";
    cout<<"\n\n************************************************************************************************************************************************************"<<endl;
}



// FUNCTION FOR LOGIN/SIGNUP

void login() //LOGIN FUNCTION DEFINITION
{
	string username, password;

	cout << " \n \t\t\t\t\t\t\t\t\t LOGIN TO MEAL DASH" << endl; 
	cout << " \t\t\t\t\t\t\t\t\t Username: "; 
	cin >> username; 
	cout << " \t\t\t\t\t\t\t\t\t Password: "; 
	cin >> password;
	cout << " \n \t\t\t\t\t\t\t\t\t LOGIN SUCCESS!" << endl; 

}

void signup() //SIGNUP FUNCTION DEFINITION
{ 
	string f_username, f_password, name, username, password, loginChoice;
	int attempt;
	int const login_attempt=3;
	
	cout << "\n \t\t\t\t\t\t\t\t\t SIGN UP FOR FIRST TIME USER" << endl; 
	cout << "\n \t\t\t\t\t\t\t\t\t Enter Name: "; 
	cin >> name; 
	cout << "\t\t\t\t\t\t\t\t\t Username: "; 
	cin >> f_username; 
	cout << "\t\t\t\t\t\t\t\t\t Password :"; 
	cin >> f_password; 
	cout << " \t\t\t\t\t\t\t\t\t Thank you for signing up." << endl; 
	cout << " \n \t\t\t\t\t\t\t\t\t Do you want to continue login?(Yes/No): " ; 
	cin >> loginChoice;
	

		if (loginChoice == "Yes" || loginChoice == "yes" ) 
		{ 
			for (attempt=1 ; attempt<=login_attempt ; ++attempt)
			{
			
				cout << " \n \t\t\t\t\t\t\t\t\t LOGIN TO MEAL DASH" << endl; 
				cout << " \t\t\t\t\t\t\t\t\t Username: "; 
				cin >> username; 
				cout << "\t\t\t\t\t\t\t\t\t Password: "; 
				cin >> password;
			
				if (username==f_username && password == f_password) 
				{ 
					cout << " \n \t\t\t\t\t\t\t\t\t LOGIN SUCCESS!" << endl; 
					break;
				}

				else 
				{ 
					cout << " \t\t\t\t\t\t\t\t\t Login failed. You have reached " << login_attempt - attempt << " attempts remaining. "<<endl;
					 
				}	 
		
			}
			
			if (username!= f_username && password != f_password)
			{
				cout << " \t\t\t\t\t\t\t\t\t Maximum attempt reached. Please run again."; //invalid input message
				exit(0);
			}
		}

	else 
	{ 
		cout << " \t\t\t\t\t\t\t\t\t\t\t THANK YOU!"<< endl;
		exit(0); 
	} 
}


// FUNCTION FOR FOOD SELECTION
// FUNCTION FOR DISPLAY MENU

void displayMenu(int restaurant) {
    if (restaurant == 1) {
        cout << "\t\t\t\t\t\t\t\t\t   [A] 2 Pieces Chicken Combo" << endl;
        cout << "\t\t\t\t\t\t\t\t\t   [B] Mexicana Burger Combo" << endl;
        cout << "\t\t\t\t\t\t\t\t\t   [C] 12 Pieces Nuggets" << endl;
        cout << "\t\t\t\t\t\t\t\t\t   [D] Chicken Porridge" << endl;
    } else if (restaurant == 2) {
        cout << "\t\t\t\t\t\t\t\t\t   [A] Velvet Creme Mocha" << endl;
        cout << "\t\t\t\t\t\t\t\t\t   [B] Buttercreme Spanish Latte" << endl;
        cout << "\t\t\t\t\t\t\t\t\t   [C] Salted Caramel Frappe" << endl;
        cout << "\t\t\t\t\t\t\t\t\t   [D] CEO Latte" << endl;
    } else if (restaurant == 3) {
        cout << "\t\t\t\t\t\t\t\t\t   [A] Nasi Lemak MB Combo" << endl;
        cout << "\t\t\t\t\t\t\t\t\t   [B] Cheesy Chicken Combo" << endl;
        cout << "\t\t\t\t\t\t\t\t\t   [C] Hotouch Burger Combo" << endl;
        cout << "\t\t\t\t\t\t\t\t\t   [D] Bubur Pedas" << endl;
    } else if (restaurant == 4) {
        cout << "\t\t\t\t\t\t\t\t\t   [A] Nishio Fine Matcha Latte" << endl;
        cout << "\t\t\t\t\t\t\t\t\t   [B] Strawberry Pudding Smoothie" << endl;
        cout << "\t\t\t\t\t\t\t\t\t   [C] Black Diamond Roasted Milk" << endl;
        cout << "\t\t\t\t\t\t\t\t\t   [D] Brown Sugar Pearl Milk Tea" << endl;
    }
}

//FUNCTION GET PRICE

double getPrice(char order) { 
    double price = 0.0;

    switch (order) {
        case 'A':
        case 'a':
            price = 18.90;
            break;
        case 'B':
        case 'b':
            price = 15.40;
            break;
        case 'C':
        case 'c':
            price = 13.10;
            break;
        case 'D':
        case 'd':
            price = 10.90;
            break;
        default:
            price = 0.00;
    }

    return price;
}

//FUNCTION GET ORDER QUANTITY

int getOrderQuantity() {
    int quantity = 0;
    cout << "\t\t\t\t\t\t\t\t\t   Quantity   : ";
    cin >> quantity;
    cout << endl;
    return quantity;
}

//FUNCTION PROCESS ORDER

//passed by references
void processOrder(int restaurant, char& order, int& quantity, double& totalPrice) { 
    displayMenu(restaurant); //function call
    do {
    	cout << "\t\t\t\t\t\t\t\t\t   Your Order : ";
        cin >> order;
        
        if ( order!='A' && order!='a' && order!='B' && order!='b' && order!='C' && order!='c' && order!='D' && order!='d' ) {
        	cout << "\n\t\t\t\t\t\t\t\t\t   The menu you entered is not in the list."<< endl;
        	cout << "\t\t\t\t\t\t\t\t\t   Please choose another option."<< endl;
        	cout << endl;
		}
	} while ( order!='A' && order!='a' && order!='B' && order!='b' && order!='C' && order!='c' && order!='D' && order!='d' );
    
    
    quantity = getOrderQuantity(); // function call

    double price = getPrice(order); // function call

    double total = price * quantity;

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "\t\t\t\t\t\t\t\t\t   Price      : RM" << total << endl;
    cout << endl;
	totalPrice += total;
}


// FUNCTION FOR DELIVERY 

//passed by value
double deliveryG(double charges, int totalQuantity)
{
    if(totalQuantity>=2 && totalQuantity<=5) 
        charges=(4*totalQuantity)-(0.5*4*totalQuantity);
    else if (totalQuantity>=6)
        charges=(4*totalQuantity)-(0.6*4*totalQuantity);
    else
        charges=4;
    return charges;
}
 
double deliveryF(double charges, int totalQuantity)
{
    if(totalQuantity>=2 && totalQuantity<=5) 
        charges=(4.50*totalQuantity)-(0.5*4.50*totalQuantity);
    else if (totalQuantity>=6)
        charges=(4.50*totalQuantity)-(0.6*4.50*totalQuantity);
    else
        charges=4;
    return charges;
}

// FUNCTION FOR ONLINEBANKING AND COD

void onlineBanking()  //function definition
{
	int bankname;
	string username2, password2;
	
	do
	{
	cout<<"\n\n\t\t\t\t\t\t\t     Select bank: "<<endl;
				cout<<"\t\t\t\t\t\t\t\t -------------------------------"<<endl;
				cout<<"\t\t\t\t\t\t\t          | 1. RHB bank               |"<<endl;
				cout<<"\t\t\t\t\t\t\t          | 2. Bank Islam Berhad      |"<<endl;
				cout<<"\t\t\t\t\t\t\t          | 3. Bank Simpanan Nasional |"<<endl;
				cout<<"\t\t\t\t\t\t\t          | 4. Maybank                |"<<endl;
				cout<<"\t\t\t\t\t\t\t          | 5. Bank Rakyat            |"<<endl;
				cout<<"\t\t\t\t\t\t\t\t -------------------------------"<<endl;
				cout<<"\t\t\t\t\t\t\t Please enter the specified number to select the bank: ";
				cin>>bankname;
				
				if(bankname == 0 || bankname>5)
				{
					cout<<"\n\t\t\t\t\t\t\t     Invalid. Please re-enter again.";
				}
				else
				{
					cout<<"\n\t\t\t\t\t\t\t     Enter username: ";
					cin>>username2;
					cout<<"\t\t\t\t\t\t\t     Enter password: ";
					cin>>password2;
					cout<<"\n\t\t\t\t\t\t\t     Total Payment: RM "<<totalPayment<<endl;  //total payment by online banking
					cout<<"\n\t\t\t\t\t\t\t     YOUR BANK BALANCE HAS BEEN DEDUCTED."<<endl;
				}
				
   }while (bankname == 0 || bankname>5);
   return;
}

void cash()  //function definition
{
	cout<<"\n\n\t\t\t\t\t\t\t\t   Total Payment: RM "<<totalPayment<<endl; //total payment by cash 
	cout<<"\n\t\t\t\t\t\t\t     PLEASE PREPARE CASH IN EXACT AMOUNT.";
	return;
}

