#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <map>
#include <set>
using namespace std;


int main()
{
  //c++11: to_string()
  char c1, c2, c3, v, v0, v1;
  vector<char>votes;
  ifstream input;
  input.open("text_data.txt");
  input >> c1 >> c2 >> c3;
  int cd1 = 0, cd2 = 0,cd3 = 0;
  while(!input.eof())
  {
    input >> v >> v0 >> v1;
    votes = {v, v0, v1};
    for (int i = 0; i <  votes.size(); i++)
    {
      if (votes[i] == c1)
      {
        cd1 += 3 - i;
      }
      else if (votes[i] == c2)
      {
        cd2 += 3 - i;
      }
      else
      {
        cd3 += 3 - i;
      }
    }
    
  }
  map<int, char>results;
  results = {{cd1, c1}, {cd2, c2}, {cd3, c3}};
  set<int>sorted;
  sorted = {cd1, cd2, cd3};
  vector<int>final_sorted;
  for (auto i: sorted)
  {
    final_sorted.push_back(i);
  }

  cout << "The winner is "<< results[final_sorted[final_sorted.size()-1]]<< endl;



}
