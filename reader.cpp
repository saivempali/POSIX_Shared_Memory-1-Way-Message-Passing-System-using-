#include<iostream>
#include<string>
#include<stdio.h>
#include "sharedLib.h"

using namespace std;

int main()
{
	cout<<"Reader process started communication\n";

	while(1)
	{
		cout<<"reader:";
		int ret = Read();
		
		if(ret == 1)
			break;
	}

	remove("buffer.txt");
	return 0;
}
