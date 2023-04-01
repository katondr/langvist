#include <iostream>
#include <string>
//#include "retriever.hpp"

using namespace std;

void displaymenu()
{
	cout<<"===========================\n";
	cout<<" 1. Also sprach Zarathustha\n";
	cout<<" 2. Max Havelaar\n";
}

int main()
{
	//read_list();
	//retriever();
	displaymenu();
	
	int choice;
	cin>>choice;
	//read_book();
	cout<<choice;
	return 0;
}
