#include <iostream>
#include <cctype>
#include <string>

using namespace std;

void input(string& text);
//Takes string input from use
//to test if it's palindrome.

void make_lowercase(string& text);
//Makes all alphabets in input string
//lowercase.

void remove_punctuation(string& text);
//Removes everything except alphabets
//from input string.

string reverse_text(string text);
//Returns the input string backwards.

void test_palindrome(string& text);
//Tests whether the string forwards
//and backwards is equal or not.

void loop(bool& lever);
//Asks user whether they want to
//run program again.

int main()
{
    bool lever(true);
    while (lever)
    {
        string text;                //String for user input.

        input(text);
        make_lowercase(text);
        remove_punctuation(text);
        test_palindrome(text);

        loop(lever);
    }
    return 0;
}

void input(string& text)
{
    cout << "Enter a word or phrase to check if it is a palindrome:\n";
    getline(cin, text);     //Takes input till the user presses Enter.
    //Preceeded by a .ignore() function in case the user runs program again.
    //This is to make sure the previous user input (Enter or '\n') does not
    //become the sentinel value of getline(), thus ending program immediately.
}

void make_lowercase(string& text)
{
    int len = text.length();
    for (int index=0; index < len; index++)
    {
        text.at(index) = tolower(text.at(index));
    }
}

void remove_punctuation(string& text)
{
    int len = text.length();
    for (int index=0; index < len; index++)
    {
        if (!isalpha(text.at(index)))
        {
            text.erase(index, 1);
            //Decrement index and length because .erase() reduces string length
            //and the index of erased character is occupied by the next one.
            --index;
            --len;
        }
    }
}

string reverse_text(string text)
{
    string backward_text(text);
    int back_index = 1; // Used to get the index in descending order. 
    int len = text.length();   
    for (int index=0; index < len; index++)
    {
        backward_text.at(index) = text.at(len - back_index);
        ++back_index;
    }
    return backward_text;
}

void test_palindrome(string& text)
{
    string text_backwards = reverse_text(text);

    if (text_backwards == text)
    {
        cout << "The text is a PALINDROME!\n";
    }
    else
    {
        cout << "The text is NOT a Palindrome.\n";
    }
}

void loop(bool& lever)
{
    char prompt {};
    while (true)
    {
        cout << "Run program again? (Y/N): ";
        cin >> prompt;
        if (prompt == 'Y' || prompt == 'y')
        {
            cin.ignore(1, '\n');
            //getline() is called right after this, hence we clear the last
            //'\n' from input buffer.
            break;
        }
        else if (prompt == 'N' || prompt == 'n')
        {
            lever = false;
            cout << "Thank You for using this program!\n";
            break;
        }
    }
}