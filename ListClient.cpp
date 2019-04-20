#include <iostream>
#include "List.h"

using namespace std;


int menu() 
{
	cout <<"A LINKED LIST WITH INSERTION AND DELETION \n\n\n " << endl;


	cout << "You are giving OPTIONS below on how to use 'said' program , Please enter a NUMBER \n"<< endl;

	int opt ;
	cout << endl << endl;
	cout << "\t" << char(218) << "------------------" << char(194) << "------------------" << char(194) << "-----------------------------------------------------------------" << char(191) << endl;
	cout << "\t" << "|                  |                  |                  |                 |               |            | " << endl;
	cout << "\t" << "| Insertion Option | Removal Option   | Display Position | Display List    |  Exit Program |   Manual   | " << endl;
	cout << "\t" << "|                  |                  |                  |                 |               |            | " << endl;
	cout << "\t" << char(195) << "------------------" << char(197) << "------------------" << char(197) << "-----------------------------------------------------------------"  << char(180) << endl;
	cout << "\t" << "|                  |                  |                  |                 |               |            | " << endl;
	cout << "\t" << "|          1       |         2        |        3         |        4        |        5      |     6      | " << endl;
	cout << "\t" << "|                  |                  |                  |                 |               |            | "<< endl;
	cout << "\t" << "|                  |                  |                  |                 |               |            | "<< endl;
	cout << "\t" << char(192) << "------------------" << char(193) << "------------------" << char(193) << "-----------------------------------------------------------------" << char(217) << endl;
	cin >> opt; 
	return opt;
}

int main()
{

	cout << "I didn't get the stacks to run on my laptop\n" << endl;


	List L1, L2;

	int option=0, value=0, pos=0, delV=0;
 while ((option=menu())!=7)
{
	switch(option)
	{
		case 1:
			cout<<"\n\nEnter number to be inserted: ";
			cin>>value;
			cout<<"\nEnter position";
			cin>>pos;
			L1.insert(value,pos);
			cout<<"\n\nValue "<<value<<" was inserted in position "<<pos<<endl;
			break;
 
		case 2: 
			cout<<"\n\nEnter position of value to be removed: ";
			cin>>pos;
			delV=L1.remove(pos);
			cout<<"Value in "<<pos<<" has been removed\nThe current number of elements in the list is "<<delV<<endl;
		        break;

		case 3:
			cout<<"\n\nEnter position of value to be found ";
			cin>>pos;
			cout<<"The value in position "<<pos<<" is: "<<L1.getAt(pos)<<"\n\n";
			break;
		case 4:
			cout<<"\n\n---------------------"<<endl;
			L1.display();
			cout<<"\n\n---------------------"<<endl;			
			break;
		case 5:
			cout << "you are existing the program" << endl; 
			        exit(0);
			break;
		case 6:
			cout << "This how the program works\n" << endl;

			cout << "-----------insertion[1]------------\n" <<endl;
			cout << " You enter a number and it's position\n in this case we will use '0','1' and '1', '2' \n" <<endl;
			L2.insert(0,1);
			L2.insert(1,2);

			cout<<"\nValue '0' was inserted in position '1'\n\n\n  " <<endl;;

			cout << "-----------Deletion[2]-------------\n" <<endl;
			cout <<"you will enter a position which you want to be delete\n this case '2' \n " << endl; 
			delV=L2.remove(2);
			cout<<"Value in '1' has been removed\nThe current number of elements in the list is  "<<delV<<endl;
			cout<< "\n\n" <<endl;

			cout << "-------Display Position[3]-------\n" <<endl;
			cout<<"Enter position of value to be found in this case 1 \n ";
			cout<<"The value in position is   "<<L2.getAt(1)<<"\n\n";

			cout << "-------Display list[4]-------\n" <<endl;
			L2.display();
			cout<<"\n\n---------------------"<<endl;		

			cout << "-----------Exit[5]-----------\n" <<endl;
			cout <<" this is to simply exit the program\n"<<endl;
			break;

		default: cout<<"Error. Please enter a option that is giving "<<endl;
	}//endswitch	
}//endwhile
}
	
