#include <iostream>
#include <string>
//#include "booklist.hpp"
//{:w
#include "listreader.hpp"
//#include "menu.hpp"
//#include "retriever.hpp"

//using namespace std;

int main(int argc, char *argv[])
{
	try
	{
		//read_list();
		//retriever();
		listreader();
		displaymenu();
		
		int choice;
		std::cin>>choice;
		//read_book();
		std::cout<<choice;
	}
	catch (...)
	{
		//some code
	}
	return 0;
}
