#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
using namespace std;

const int MAX_TRIES=5;
int letterFill (char, string, string&);

int main ()
{
    for(int i=0;i<50;i++)
    {
        cout<<"*";
    }
        string name;
        char letter;
        int num_of_wrong_guesses=0;
        string word;
        string words[] =
        {
            "india",
            "pakistan",
            "nepal",
            "malaysia",
            "philippines",
            "australia",
            "iran",
            "ethiopia",
            "oman",
            "indonesia",
            "brazil",
            "chile",
            "denmark"
        };

            srand(time(NULL));
            int n=rand()% 13;
            word=words[n];
            string unknown(word.length(),'*');

            cout <<endl<<"          "<<"WELCOME TO HANGMAN"<<endl<<endl;
            cout<<"RULES-:"<<endl<<"Guess a country Name";
            cout << "\nEach letter is represented by a star.";
            cout << "\nYou have to type only one letter in one try";
            cout << "\nYou have " << MAX_TRIES << " tries to try and guess the word.";
            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

                while (num_of_wrong_guesses < MAX_TRIES)
                {
                    cout << "\n\n" <<"          "<<unknown;
                    cout << "\n\nGuess a letter: ";
                    cin >> letter;
                    if (letterFill(letter, word, unknown)==0)
                        {
                            cout << endl << "Whoops! That letter isn't in there!" << endl;
                            num_of_wrong_guesses++;
                        }
                    else
                        {
                            cout << endl << "You found a letter! Great Keep Going!" << endl;
                        }

                    cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
                    cout << " guesses left." << endl;
                    if (word==unknown)
                        {
                            cout << word << endl;
                            cout <<endl<< "Yeah! You got it, CONGO!!!!";
                            break;
                        }
                }
                    if(num_of_wrong_guesses == MAX_TRIES)
                        {
                            cout << "\nSorry, you lose..."<<endl<<"you've been HANEGD  ^_^ ." << endl;
                            cout << "The word was : "<<endl;
                            cout<<"               ";
                            for(int i=0;i<=word.length()+3;i++)
                            {
                                cout<<"#";
                            }
                            cout<<endl<<"               # "<<word<<" #"<<endl;
                            cout<<"               ";
                            for(int i=0;i<=word.length()+3;i++)
                            {
                                cout<<"#";
                            }
                        }
                cin.ignore();
                cin.get();
	return 0;
}


int letterFill (char guess, string secretword, string &guessword)
{
	int i;
	int matches=0;
	int len=secretword.length();
	for (i = 0; i< len; i++)
	{
		if (guess == guessword[i])
			return 0;
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}
