#include<iostream>
#include<string.h>
#include"HTMLClass.h"
using namespace std;
	
HTMLStamp::HTMLStamp(string fileName)
	{
		SetFileName(fileName);
		OpenHTMLFile();
		CloseHTMLFile();
	}
	
void HTMLStamp::SetFileName(string fileName)
	{
		this -> fileName = fileName;
	}
	
void HTMLStamp::OpenHTMLFile()
	{
		this -> fr = fopen(this -> fileName.c_str(), "r");
		if (fr == NULL)
			{
				throw "NoFile.";
			}			
	}

void HTMLStamp::CloseHTMLFile()
	{
		fclose(this -> fr);
	}
	
void HTMLStamp::ReadPage()
	{
		char ist[200];
		OpenHTMLFile();
		while(!strcmp(ist, "</html>") == 0)
			{
				fscanf(fr, "%s", ist);
				StampaTesto("</h1>", strcmp(ist, "<h1>"));
				StampaTesto("</h2>", strcmp(ist, "<h2>"));
				StampaTesto("</h3>", strcmp(ist, "<h3>"));
				StampaTesto("</h4>", strcmp(ist, "<h4>"));
				StampaTesto("</h5>", strcmp(ist, "<h5>"));
				StampaTesto("</h6>", strcmp(ist, "<h6>"));
				StampaTesto("</title>", strcmp(ist, "<title>"));
				StampaTesto("</p>", strcmp(ist, "<p>"));
			}
	}

void HTMLStamp::StampaTesto(string testo, int condition)
	{
		if (condition == 0)
			{
				char ist[200];
				while(!strcmp(ist, testo.c_str()) == 0)
					{
						fscanf(fr, "%s", ist);
						if (strcmp(ist, testo.c_str()) != 0)
						cout << ist;	
					}
				cout << endl;	
			}		
	}
