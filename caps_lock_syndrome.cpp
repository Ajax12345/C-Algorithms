#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
using namespace std;


int main()
{
  string the_string = "hELLO hOW aRE yOU";
  vector<string>v;
  string new_string = "";
  for (int i = 0; i < the_string.length(); i++)
  {
    if (the_string[i] != ' ')
    {
      new_string += the_string[i];
    }
    else
    {
      v.push_back(new_string);
      new_string = "";
    }
  }
  //Now, the string vector is loaded

  for(int i = 0; i < v.size(); i++)
  {
    if (islower(v[i][0]))
    {
      int counter = 0;
      for (int b = 1; b < v[i].length(); b++)
      {
        if (isupper(v[i][b]))
        {
          counter += 1;
        }
      }
      if (counter == v[i].length()-1)
      {
        cout << v[i]<< " has caps lock syndrome"<< endl;

      }
      else
      {
        cout << v[i] << " does not have caps lock syndrome"<< endl;
      
      }
    }
    else
    {
      cout << v[i]<< " does not have caps lock syndrome"<< endl;
    }
  }

}
