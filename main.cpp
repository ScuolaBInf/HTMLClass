#include <iostream>
#include <windows.h>
#include "HTMLClass.h"

main() 
	{
		HTMLCreate print("HTML2.html");
		print.PrintPage();
		system("cls");
		HTMLStamp read("HTML2.html");
		read.ReadPage();
		system("HTML2.html");
	}
