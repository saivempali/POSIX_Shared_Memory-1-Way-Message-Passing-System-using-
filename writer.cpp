#include<iostream>
#include<string.h>
#include<stdio.h>

//#include "data.h"
#include "sharedLib.h"

using namespace std;

int main()
{
	cout<<"Writer process started communication\n";

	// writer creates the buffer for communication

	buffer_create();
	string message = "";
	while(1)
	{
		cout<<"writer:";
		getline(cin,message);

		

		const char *st = message.c_str();

		char *msgs = new char[message.length()+1];

		strcpy(msgs,st);
		// write method from shared library

		//cout<<"calling write in writer\n";
		
		Write(msgs,message.length()+1);

		if(message == "quit")
		{
			break;
		}
		//cout<<"after write\n";
	}

	//print();
	
	//remove("buffer");
	
	return 0;
}
