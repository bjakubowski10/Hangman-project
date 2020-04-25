#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <cstddef>
#include <vector>
#include <cstring>
#include <cctype>
#include <locale> //locale and tolower
using namespace std;


int spacecount = 0;
int scorecount = 0;
string noupper;
string remove(string word)
{
	word.erase(remove(word.begin(), word.end(), '_'), word.end());
	return word;
}

//whitspace calculate
 void space(string str)
{
	int length = str.length();
	for (int i = 0; i < length;i++)
	{
		int c = str[i];
		if (isspace(c))
		{
			spacecount++;
		}
	}

}

void countunderscores(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '_')
		{
			scorecount++;
		}
	}

}




int main()
{
	string guess ;
	string entry;
	char letter;
	vector<char>::iterator it;
	string empty = "";
	int wrong = 0;
	bool win = false;
	vector<char>usedlet;
	//fstream file;
	//file.open("../../Hangman.txt", ios::app);

	cout << "Welcome to Hangman!!\n";
	cout << "====================\n\n";

	cout << "Enter a phrase, word, or a sequence ==> ";
	getline(cin, entry);


	


	transform(entry.begin(), entry.end(), entry.begin(), ::tolower);  // one way to turn string to lower case 

	/*std::for_each(entry.begin(), entry.end(), [](char& c) //another way
		{
			c = ::tolower(c);
		});
		*/
	cout << endl;
	

	vector<char> word(entry.begin(), entry.end());
	


	for (int i = 0; i < word.size(); i++)
	{
		empty.append("_"); //fills the empty string with _ the size of vector word
	}
	cout << empty << "\n\n";
	
	
	
	space(entry);

	while (wrong < 7 || win == false)
	{
		

		cout << "Emter a letter ==> ";
		cin >> letter;
		usedlet.push_back(letter);


		cout << "Letters used --> ";
		for (int i = 0; i < usedlet.size(); i++)
		{
			cout << " " << usedlet[i];
		}
		cout << endl;


		int pos = entry.find(letter); //gets the first time the letter appears
		while (pos != string::npos) //looks for every other occurence and replaces them
		{
			empty.replace(pos, 1, 1, letter);
			pos = entry.find(letter, pos + 1);
			scorecount -= scorecount;
			
		}


		
		
		cout << empty << endl;

		
		countunderscores(empty);
		cout << "spacecount ==> " << spacecount<<endl;
		if (spacecount == scorecount)
		{
			win = true;
			break;
		}
		
		if (entry.find(letter) == string::npos)
		{
			++wrong;
			--scorecount;
		}
		


		switch (wrong)
		{
		case 1:
			cout << "+--+" << endl;
			cout << "|" << endl;
			cout << "|" << endl;
			cout << "| " << endl;
			break;
		case 2:
			cout << "+--+" << endl;
			cout << "|  o" << endl;
			cout << "| " << endl;
			cout << "| " << endl;
			break;
		case 3:
			cout << "+--+" << endl;
			cout << "|  o" << endl;
			cout << "|  |" << endl;
			cout << "| " << endl;
			break;
		case 4:
			cout << "+--+" << endl;
			cout << "|  o" << endl;
			cout << "| /|" << endl;
			cout << "| " << endl;
			break;
		case 5:
			cout << "+--+" << endl;
			cout << "|  o" << endl;
			cout << "| /|\\ " << endl;
			cout << "| " << endl;
			break;
		case 6:
			cout << "+--+" << endl;
			cout << "|  o" << endl;
			cout << "| /|\\ " << endl;
			cout << "| / " << endl;
			break;
			
		case 7:
			cout << "+--+" << endl;
			cout << "|  o" << endl;
			cout << "| /|\\ " << endl;
			cout << "| / \\ " << endl;
			cout << "\nYou lost\n";
			break;

		}
		if (wrong == 7)
		{
			break;

		}

		cout << endl << endl;
	} 
	
	if (win == true)
	{
		cout << "\n\nYOU WON !!!!!!!!\n";

	}
	
}


