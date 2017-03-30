#include <iostream>
#include <map>
#include <string>
using namespace std;



int main()
{
    char letters[27] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    map<char, char>the_dict;
    int key = 6;
    for (int i = 0; i < 27; i++)
    {
        if (i + key < 27)
        {
            the_dict[letters[i]] = letters[i + key];
        }
        else
        {
            the_dict[letters[i]] = letters[26 - i];
        }


    }
    string message = "hello";
    string new_message = "";
    for (int i = 0; i < message.length(); i++)
    {
        new_message += the_dict[message[i]];
    }
    cout << new_message << endl;
    return 0;
}
