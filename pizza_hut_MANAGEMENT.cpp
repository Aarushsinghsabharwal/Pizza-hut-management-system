#include<iostream>
#include<string>
#include<cmath>
#include<fstream>
#include<iomanip>
using namespace std;
	void add_item();
	void delete_item();
	void take_order();	
	void generate_store_bill();
	void func();
class pizza
{
	char pizza_name[30];
	char customer_name[30];
	int no_of_customers;
	float pizza_price;
	int order_no;
	public:
	void display();
	void getorder();
	void add_pizza();
	friend void delete_pizza(const char*,int);
    friend void add_to_updated(pizza);
    void search();
};
    void add_to_updated(pizza obj)
	{
		ofstream outfile;
		outfile.open("pizzalist3.txt",ios::out|ios::ate|ios::app);
		cout<<"Enter the name of the pizza"<<endl;
		fflush(stdin);
		gets(obj.pizza_name);
		outfile<<endl;
		outfile<<obj.pizza_name;
		cout<<"Enter the cost of the pizza(small)"<<endl;
		cin>>obj.pizza_price;
		outfile<<"\t\t    "<<obj.pizza_price;
		cout<<"Enter the cost of the pizza(medium)"<<endl;
		cin>>obj.pizza_price;
		outfile<<"\t\t  "<<obj.pizza_price;
		cout<<"Enter the cost of the pizza(large)"<<endl;
		cin>>obj.pizza_price;
		outfile<<"\t\t   "<<obj.pizza_price<<endl;
		outfile.close();		
	}

//Class member function definitions*********************
	void pizza::display()
	{
		string line;
		ifstream infile;
		infile.open("pizzalist.txt");
		while(getline(infile,line))
		{
			cout<<line<<endl;
		}
		infile.close();
	}
	

	void pizza::getorder()
	{
		fstream order;
		fstream storage;
		order.open("pizzaorder.txt",ios::out);
		storage.open("storepizzaorder.txt",ios::out|ios::ate|ios::app);
		cout<<"Please give your name"<<endl;
		fflush(stdin);
		gets(customer_name);
		order<<"Customer Name: "<<customer_name<<endl;
		storage<<"\nCustomer Name: "<<customer_name<<endl;
		cout<<endl;
		cout<<"Enter the number of persons"<<endl;
		cin>>no_of_customers;
		order<<"Number of customers: "<<no_of_customers<<endl;
		storage<<"Number of customers: "<<no_of_customers<<endl;
		cout<<"Take order"<<endl;
		fflush(stdin);
		gets(pizza_name);
		order<<"Pizza names :"<<pizza_name<<endl;
		storage<<"Pizza names :"<<pizza_name<<endl;	
		order.close();
	}
	
	
	void pizza::add_pizza()
	{
		ofstream outfile;
		outfile.open("pizzalist.txt",ios::out|ios::ate|ios::app);
		cout<<"Enter the name of the pizza"<<endl;
		fflush(stdin);
		gets(pizza_name);
		outfile<<endl;
		outfile<<pizza_name;
		cout<<"Enter the cost of the pizza(small)"<<endl;
		cin>>pizza_price;
		outfile<<"\t\t    "<<pizza_price;
		cout<<"Enter the cost of the pizza(medium)"<<endl;
		cin>>pizza_price;
		outfile<<"\t\t  "<<pizza_price;
		cout<<"Enter the cost of the pizza(large)"<<endl;
		cin>>pizza_price;
		outfile<<"\t\t   "<<pizza_price<<endl;
		outfile.close();
	}
	
//	void pizza::search()
//	{
//		ifstream readfile;
//		readfile.open("storepizzaorder.txt",ios::ate);
//		string cus_name;
//		string line;
//		cout<<endl<<"Enter the name of the customer whose record is to be searched:- ";
//		fflush(stdin);
//		cin>>cus_name;
//		while(getline(readfile,line))
//		{
//			if(cus_name==line)
//			{
//				cout<<"Record found"<<endl<<"Customer name: ";
//				cout<<cus_name;
//			}
//			else
//			{
//				cout<<"NO RECORD FOUND\n";
//			}
//		}
//		readfile.close();
//	}
	
	
	void delete_pizza(const char *file_name, int n) 
{  
    ifstream is(file_name); 
  
    ofstream ofs; 
    ofs.open("pizzalist3.txt", ofstream::out); 
  
    n=n+3;
    char c; 
    int line_no = 1; 
    while (is.get(c)) 
    { 
        // if a newline character 
        if (c == '\n') 
        line_no++; 
  
        // file content not to be deleted 
        if (line_no != n) 
            ofs << c; 
    }  
    remove(file_name);
    rename("pizzalist3.txt", file_name);
}

// Starting of the main function**************

int main()
{
	system("Color 6E");
	pizza obj;
	int x;
	cout<<setw(90)<<"Welcome to AM PIZZA HUT"<<endl;
	cout<<endl<<endl;
	label:
	cout<<"Enter the number to do the following\n1 Display pizza list\n2 to add an item\n"
	    <<"3 to delete an item\n4 to show the updated list\n5 to take order\n6 to generate and store bill\n7 to search order from list\n";
	cin>>x;
	while(x>=1&&x<=7)
	{
		switch(x)
		{
			case 1:
			obj.display();
			break;
			case 2:
			cout<<"Enter number\n1 to add item to the original list\n2 to add item to the updated list";
		    int a;
		    cin>>a;
		    switch(a)
		    {
				case 1:
				add_item();
				break;
				case 2:
			    add_to_updated(obj);
			    break;
			}
		    break;
		    case 3:
			cout<<"Enter the pizza number to be deleted";
		    int n;
		    cin>>n;
		    delete_pizza("pizzalist.txt",n);	    
		    break;
		    case 4:
		    func();
		    break;
		    case 5:
		    take_order();
		    break;
		    case 6:
		    generate_store_bill();
		    break;
			case 7:
			obj.search();
			break;
		}
		goto label;
    }
}
/* ********************Function definitions*********************** */


	void add_item()
	{
		pizza obj2;
		obj2.add_pizza();
	}


	void take_order()
	{
		pizza ob;
		ob.getorder();
	}
	
	
	void generate_store_bill()
	{
            
	ifstream infile("pizzaorder.txt");
    string lineData;

    getline(infile, lineData);

    ofstream outfile;
    ofstream storage;
    outfile.open("storeorder.txt", ios::app);
    storage.open("storepizzaorder.txt",ios::app|ios::ate|ios::out);
    outfile <<endl<<lineData<<endl;

		float amount;    
		ofstream bill;
		bill.open("storeorder.txt",ios::app|ios::ate|ios::out);
		cout<<"Amount to pay"<<endl;
		cin>>amount;
		bill<<"\nBill amount: Rs."<<amount;
		storage<<"\nBill amount: Rs."<<amount;	
		bill.close();
	} 
	void func()
	{
		    string line;
		    fstream file;
		    file.open("pizzalist3.txt",ios::in);
		    while(getline(file,line))
		    {
		    	cout<<line<<endl;
			}
		    file.close();
	}
