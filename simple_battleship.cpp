#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
class HQ
{
public:
  bool hit1(int x, int y)
  {
    if (ship2[x-1][y-1] == '#')
    {
      update2(x, y);
      return true;
    }
    else
    {
      return false;
    }
  }
  bool hit2(int x, int y)
  {
    if (ship1[x-1][y-1] == '#')
    {
      update1(x, y);
      return true;
    }
    else
    {
      return false;
    }
  }
  void update1(int x, int y)
  {
    player1[x-1][y-1] = '#';
    player1_hits++;
  }
  void update2(int x, int y)
  {
    player2[x-1][y-1] = '#';
    player2_hits++;
  }
  char player1[6][6] = {
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'},
  };

  char player2[6][6] = {
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'},
    {'*', '*', '*', '*', '*'},
  };
  int player1_hits = 0;
  int player2_hits = 0;
private:
  char ship1[6][6] = {
    {'*', '*', '*', '#', '*'},
    {'#', '#', '*', '#', '*'},
    {'*', '*', '*', '#', '*'},
    {'*', '*', '*', '#', '*'},
    {'*', '*', '*', '*', '*'},
  };

  char ship2[6][6] = {
    {'*', '*', '*', '#', '*'},
    {'*', '*', '*', '#', '*'},
    {'#', '#', '#', '#', '*'},
    {'*', '*', '*', '#', '*'},
    {'*', '*', '*', '*', '*'},
  };

};

struct Player1: public HQ
{
  void attack(int x, int y)
  {
    bool flag = hit2(x, y);
    if (flag)
    {
      cout << "Nice shot!"<< endl;
    }
    else
    {
      cout << "Miss"<< endl;
    }
  }
  void show_opponent()
  {
    cout << "Your board:"<< endl;
    for (int i = 0; i< 6; i++)
    {
      for (int b = 0; b < 6; b++)
      {
        cout << player2[i][b]<< ' ';
      }
      cout << endl;
    }
    cout << "Total hits: "<< player2_hits<< endl;
  }
  void attack1()
  {
    int new_x = rand()%6+0;
    int new_y = rand()%6 + 0;
    bool flag = hit2(new_x, new_y);
    if (flag)
    {
      cout << "You have been hit!"<< endl;
    }
    else
    {
      cout << "Enemy missed!"<< endl;
    }
  }
  void show_opponent1()
  {
    cout << "Enemy board:"<< endl;
    for (int i = 0; i<6; i++)
    {
      for (int b = 0; b < 6; b++)
      {
        cout << player1[i][b]<< ' ';
      }
      cout << endl;
    }
    cout << "Total hits: "<< player1_hits<< endl;
  }
};

int main()
{
  int row, column;
  Player1 you;
//  Player2 computer;

  for (int i = 0; i < 10; i++)
  {
    cout << "Enter your x y coordiates: "<< endl;
    cin >> row >> column;
    you.attack(row, column);
    you.show_opponent();
    you.attack1();
    you.show_opponent1();
  }
}
