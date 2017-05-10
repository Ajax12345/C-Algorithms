#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <fstream>
using namespace std;
class BarCode
{
public:
  BarCode(string the_string)
  {
    string temporary = "";
    for (int i = 1; i < the_string.length()-1; i++)
    {
      temporary += the_string[i];
    }
    code = temporary;
  }
  int bar_code_sum();

private:
  string code;
};


int main()
{

  string code = "110100101000101011000010011";

  int result;
  BarCode postal(code);
  result = postal.bar_code_sum();
  cout << result<< endl;

}

int BarCode::bar_code_sum()
{
  map<char, int>convert = {{'1', 1}, {'0', 0}};

  string new_code = "";
  for (int i = 1; i<code.length()-1; i++)
  {
    new_code += code[i];
  }

  int value[6] = {7, 4, 2, 1, 0};

  vector<int>sums;
  string new_string = "";
  for (int i = 0; i < new_code.length(); i++)
  {

    if ((i+1)%5 == 0)
    {
    
      for (int b = 0; b < new_string.length(); b++)
      {
        //cout << new_string<< endl;
        int converted = convert[new_string[b]];
        //cout << converted<< endl;
        //cout << value[b]<< endl;
        sums.push_back(value[b]*converted);

      }
      new_string = "";
    }
    else
    {
      new_string += new_code[i];
    }

  }
  int total_sum = 0;

  for (int i: sums)
  {
    total_sum += i;
  }
  return total_sum;
}
