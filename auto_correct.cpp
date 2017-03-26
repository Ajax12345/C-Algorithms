#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
using namespace std;


int main()
{
   
    char KeyboardRow1[15] = { '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', ' '};
    char KeyboardRow2[15] = { ' ', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', ' ' };
    char KeyboardRow3[15] = { ' ', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', ' ', ' ', ' ' };
    char KeyboardRow4[16] = { ' ', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', ' ', ' ', ' ' };
    char KeyboardRow1S[15] = { '~', '!', '@', '#', '$', '%', '^', '&', '*', ',', '_', '+', ' ' };
    char KeyboardRow2S[15] = { ' ', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', ', ', '|' };
    char KeyboardRow3S[15] = { ' ', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', ' ', ' ', ' ' };
    char KeyboardRow4S[15] = { ' ', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?', ', ',', ', ', ' };

    map<char, char>the_dict;

    for (int i = 1; i < 15; i++)
    {
        the_dict[KeyboardRow1[i]] = KeyboardRow1[i - 1];
    }

    for (int i = 1; i < 15; i++)
    {
        the_dict[KeyboardRow2[i]] = KeyboardRow2[i - 1];
    }
    for (int i = 1; i < 15; i++)
    {
        the_dict[KeyboardRow3[i]] = KeyboardRow3[i - 1];
    }

    for (int i = 1; i < 15; i++)
    {
        the_dict[KeyboardRow4[i]] = KeyboardRow4[i - 1];
    }
    for (int i = 1; i < 15; i++)
    {
        the_dict[KeyboardRow1S[i]] = KeyboardRow1S[i - 1];
    }
    for (int i = 1; i < 15; i++)
    {
        the_dict[KeyboardRow2S[i]] = KeyboardRow2S[i - 1];
    }
    for (int i = 1; i < 15; i++)
    {
        the_dict[KeyboardRow3S[i]] = KeyboardRow3S[i - 1];
    }
    for (int i = 1; i < 15; i++)
    {
        the_dict[KeyboardRow4S[i]] = KeyboardRow4S[i - 1];
    }

    string user_string = "XCVBNM,./";
    vector<char>final_answer;
    for (int i = 0; i < user_string.length(); i++)
    {
        final_answer.push_back(the_dict[user_string[i]]);
    }

    for (int i = 0; i < final_answer.size(); i++)
    {
        cout << final_answer[i];
    }
   
    return 0;
}
