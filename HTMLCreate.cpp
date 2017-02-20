#include<iostream>
#include<string.h>
#include"HTMLClass.h"
using namespace std;

HTMLCreate::HTMLCreate(string fileName)
	{
		SetFileName(fileName);
		OpenHTMLFile();
		CloseHTMLFile();
	}
	
void HTMLCreate::SetFileName(string fileName)
	{
		this -> fileName = fileName;
	}

void HTMLCreate::OpenHTMLFile()
	{
		this -> fw = fopen(this -> fileName.c_str(), "w");		
	}

void HTMLCreate::CloseHTMLFile()
	{
		fputs("</html>\n", fw);
		fclose(this -> fw);
	}
	
void HTMLCreate::PrintPage()
	{
		this -> OpenHTMLFile();
		fputs("<!DOCTYPE html>\n", fw);
		fputs("<html>\n", fw);
		CreateString("\t<head>\n", "Inserire titolo? (y/n)\t", false, "<title> ", " </title> \n");
		fputs("\t</head>\n\n", fw);
		CreateString("\t<body>\n", "Inserire occhiello? (y/n)\t", true, "<hn> ", " ");
		fputs("\t</body>\n", fw);
		this -> CloseHTMLFile();
	}
	
void HTMLCreate::CreateString(string inizio, string controllo, bool titolo, string testo, string fine)
	{
		string insert;
		char operand;
		int formatoTitolo;
		fputs(inizio.c_str(), fw);
			cout << controllo;
			cin >> operand;
			if (operand == 'y')
				{
					if (titolo)
						{
							cout << "Inserire formato titolo? (da 1 a 6)\t";
							cin >> formatoTitolo;
							testo[2] = formatoTitolo + 48;							
						}
					fputs("\t\t", fw);
					fputs(testo.c_str(), fw);
					cout << "Inserire Testo: ";
					cin >> insert;
					fputs(insert.c_str(), fw);
					if (titolo)
						{
							fputs(" </h", fw);
							fputc(formatoTitolo + 48, fw);
							fputs(">\n", fw);	
						}
					else
						{
							fputs(fine.c_str(), fw);
						}			
				}
			if (titolo){
			cout << "Inserire Paragrafo? (y/n)\t";
			cin >> operand;
			if (operand == 'y')
				{
					fputs("\t\t<p> ", fw);
					cout << "Inserire Testo: ";
					cin >> insert;
					fputs(insert.c_str(), fw);
					fputs(" </p>\n", fw);
				}}
			
	}
