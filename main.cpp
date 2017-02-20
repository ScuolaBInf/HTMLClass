#include <iostream>
#include <windows.h>
#include "HTMLClass.h"

main() 
	{
		HTMLCreate print("HTML2.txt");
		print.PrintPage();
		system("cls");
		HTMLStamp read("HTML2.txt");
		read.ReadPage();
	}
