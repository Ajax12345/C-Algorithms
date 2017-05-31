#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
using namespace std;

int main()
{
  map<char, map<string, char> > nodes = {{'A', {{"right", 'B'}, {"down", 'E'}}}, {'E', {{"down", 'I'}}}, {'I', {{"right", 'J'}}}, {'J', {{"left", 'I'}}}, {'B', {{"left", 'A'}, {"down", 'F'}}}, {'F', {{"right", 'G'}}}, {'G', {{"up", 'C'}, {"down", 'K'}}}, {'C', {{"right", 'D'}}}, {'D', {{"left", 'C'}}}, {'H', {{"left", 'G'}, {"down", 'L'}}}, {'L', {{"up", 'H'}}}};


  char node = 'Z';

  while (node != 'L')
  {
    char user_move;
    cin >> user_move;
    user_move = toupper(user_move);
    string direction;
    cin >> direction;
    node = nodes[user_move][direction];
    cout << "Your square now is "<<node<<endl;
    if (node == 'L')
    {
      cout << "finished"<< endl;
    }
  }




}
