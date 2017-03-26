#include <iostream>

#include <vector>
#include <string>
#include <set>

using namespace std;
int main()
{
    string string1 = "pat";
    string string2 = "patricia";
    //vector to set
    vector<char>first;
    vector<char>second;

    for (int i = 0; i < string1.length(); i++)
    {
        first.push_back(string1[i]);
    }
    for (int i = 0; i < string2.length(); i++)
    {
        second.push_back(string2[i]);
    }
    vector<int>target;
    if (first.size() < second.size())
    {
        for (int i = 0; i < first.size(); i++)
        {


            if (find(second.begin(), second.end(), first[i]) != second.end())
            {
                int count1 = count(first.begin(), first.end(), first[i]);
                int count2 = count(second.begin(), second.end(), first[i]);
                if (count1 <= count2)
                {
                    target.push_back(1);
                }
           


            }

        }
        if (target.size() == first.size())
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        for (int i = 0; i < second.size(); i++)
        {

            if (find(first.begin(), first.end(), second[i]) != first.end())
            {
                int count1 = count(first.begin(), first.end(), first[i]);
                int count2 = count(second.begin(), second.end(), first[i]);
                if (count1 >= count2)
                {
                    target.push_back(1);
                }
               
            }

        }
        if (target.size() == second.size())
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
