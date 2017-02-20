#include<iostream>
using namespace std;

class HTMLStamp 
	{
		private:
			FILE* fr;
			string fileName;
			void SetFileName(string);
			void OpenHTMLFile();
			void CloseHTMLFile();

			void StampaTesto(string, int);
			
		public:
			HTMLStamp();
			HTMLStamp(string);
			void ReadPage();
	};
	
class HTMLCreate 
	{
		private:
			FILE* fw;
			string fileName;
			void SetFileName(string);
			void OpenHTMLFile();
			void CloseHTMLFile();
			void CreateString(string inizio, string controllo, bool titolo, string testo, string fine);			
		public:
			HTMLCreate();
			HTMLCreate(string);
			void PrintPage();
	};
