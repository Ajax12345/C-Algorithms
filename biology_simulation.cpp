#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <cctype>
using namespace std;
class Simulation
{

public:
  void ant_move();
  void doodlebug_move();
  void show_map()
  {
    for (int i = 0; i < 9; i++)
    {
      for (int b = 0; b < 9; b++)
      {
        cout << land[i][b];
      }
      cout << endl;
    }

  }

private:
  map<string, bool>doodlebug_movements = {{"d1", false}, {"d2", false}, {"d3", false}, {"d4", false}};
  map<string, bool>ant_movements = {{"a1", false}, {"a2", false}, {"a3", false}, {"a4", false}, {"a5", false}, {"a6", false}, {"a7", false}, {"a8", false}, {"a9", false}, {"a10", false}};;
  int ant_moves = 1;
  int doodlebug_moves = 1;
  //doodlebug_movements = {{"d1", false}, {"d2", false}, {"d3", false}, {"d4", false}};
  //ant_movements = {{"a1", false}, {"a2", false}, {"a3", false}, {"a4", false}, {"a5", false}, {"a6", false}, {"a7", false}, {"a8", false}, {"a9", false}, {"a10", false}};
  string land[9][9] = {
    {"d1", "-", "-", "-", "-", "-", "a10", "-"},
    {"-", "-", "a1", "-", "a2", "-", "-", "-"},
    {"-", "d1", "-", "-", "-", "-", "a9", "-"},
    {"-", "-", "a3", "-", "d3", "-", "-", "-"},
    {"d2", "-", "-", "-", "a4", "-", "d4", "-"},
    {"-", "a5", "-", "-", "-", "a6", "-", "-"},
    {"-", "-", "-", "a7", "a7", "-", "a8", "-"},
    {"-", "-", "-", "-", "-", "-", "-", "-"},
  };



};
int main()
{
  Simulation bio;
  bio.show_map();
  for (int i = 0; i < 10; i++)
  {
    bio.ant_move();
    bio.doodlebug_move();
    bio.show_map();
  }

}


void Simulation::ant_move()
{
  string options[5] = {"right", "left", "up", "down"};
  //int key = rand()%4+0;
  for (int i = 0; i < 9; i++)
  {
    for (int b = 0; b < 9; b++)
    {

      if (land[i][b][0] == 'a')
      {
        if (ant_moves%3 == 0)
        {
          if (i+1 <= 8 && i - 1 >= 0 && b + 1 >= 8 && b - 1 <= 0)
          {
            if (land[i+1][b] == "-")
            {
              string avatar = land[i][b];
              land[i][b] = "-"; ///////
              land[i+1][b] = avatar;

            }
            else if (land[i-1][b] == "-")
            {
              string avatar = land[i][b];
              land[i][b] = "-"; ///
              land[i-1][b] = avatar;
            }
            else if (land[i][b+1] == "-")
            {
              string avatar = land[i][b];
              land[i][b] = "-"; ///////
              land[i][b+1] = avatar;
            }
            else if (land[i][b-1] == "-")
            {
              string avatar = land[i][b];
              land[i][b] = "-"; //////
              land[i][b-1] = avatar;
            }
          }

        }


        else
        {
          int key = rand()%4+0;
          string movement = options[key];
          if (movement == "right")
          {
            if (i+1 <= 8)
            {
              if (land[i+1][b] == "-")
              {
                string avatar = land[i][b];
                land[i][b] = "-";
                land[i+1][b] = avatar;

              }
            }
          }
          else if (movement == "left")
          {
            if (i-1 >= 0)
            {
              if (land[i-1][b] == "-")
              {
                string avatar = land[i][b];
                land[i][b] = "-";
                land[i-1][b] = avatar;
              }
            }
          }
          else if (movement == "up")
          {
            if (b+1 <= 8)
            {
              string avatar = land[i][b];
              land[i][b] = "-";
              land[i][b+1] = avatar;
            }
          }
          else
          {
            if (b - 1 >= 0)
            {
              string avatar = land[i][b];
              land[i][b] = "-";
              land[i][b-1] = avatar;
            }
          }
        }
      }
      }
    }
  ant_moves++;
}

void Simulation::doodlebug_move()
{
  string options[5] = {"up", "down", "left", "right"};
  for (int i = 0; i < 9; i++)
  {
    for (int b = 0; b < 9; b++)
    {
      if (land[i][b][0] == 'd')
      {
        string avatar = land[i][b];
        if(doodlebug_moves%3 == 0 && !doodlebug_movements[avatar])
        {
          doodlebug_movements.erase(avatar);
          land[i][b] = "-";

        }
        else if (doodlebug_moves%8 == 0)
        {
          if (i+1 <= 8 && i - 1 >= 0 && b + 1 >= 8 && b - 1 <= 0)
          {
            if (land[i+1][b] == "-")
            {
              string avatar = land[i][b];
              land[i+1][b] = avatar;

            }
            else if (land[i-1][b] == "-")
            {
              string avatar = land[i][b];
              land[i][b] = "-"; //////
              land[i-1][b] = avatar;
            }
            else if (land[i][b+1] == "-")
            {
              string avatar = land[i][b];
              land[i][b] = "-"; //////
              land[i][b+1] = avatar;
            }
            else if (land[i][b-1] == "-")
            {
              string avatar = land[i][b];
              land[i][b] = "-"; ////////
              land[i][b-1] = avatar;
            }
          }
        }
        else
        {
          int key = rand()%4+0;
          string movement = options[key];
          if (movement == "right")
          {
            if (i+1 <= 8)
            {
              if (land[i+1][b] == "-")
              {
                string avatar = land[i][b];

                land[i][b] = "-";
                land[i+1][b] = avatar;
              }

            }
            else if (land[i+1][b][0] == 'a')
            {
              string avatar = land[i][b];
              land[i][b] = "-";
              ant_movements.erase(land[i+1][b]);
              doodlebug_movements[avatar] = true;
              land[i+1][b] = avatar;
            }
          }

          else if (movement == "left")
          {
            if (i-1 >= 0)
            {
              if (land[i-1][b] == "-")
              {
                string avatar = land[i][b];
                land[i][b] = "-";
                land[i-1][b] = avatar;
              }
              else if (land[i+1][b][0] == 'a')
              {
                string avatar = land[i][b];
                land[i][b] = "-";
                ant_movements.erase(land[i+1][b]);
                doodlebug_movements[avatar] = true;
                land[i+1][b] = avatar;
              }
            }
          }
          else if (movement == "up")
          {
            if (b+1 <= 8)
            {
              if (land[i][b+1] == "-")
              {
                string avatar = land[i][b];
                land[i][b] = "-";
                land[i][b+1] = avatar;
              }
              else if (land[i][b+1][0] == 'a')
              {
                string avatar = land[i][b];
                land[i][b] = "-";
                ant_movements.erase(land[i+1][b]);
                doodlebug_movements[avatar] = true;
                land[i][b+1] = avatar;
              }
            }
          }
          else
          {
            if (b - 1 >= 0)
            {
              if (land[i][b-1] == "-")
              {
                string avatar = land[i][b];
                land[i][b] = "-";
                land[i][b-1] = avatar;
              }
              else if (land[i][b-1][0] == 'a')
              {
                string avatar = land[i][b];
                land[i][b] = "-";
                ant_movements.erase(land[i+1][b]);
                doodlebug_movements[avatar] = true;
                land[i][b-1] = avatar;
              }

            }
          }

        }

    }

  }
  //doodlebug_moves++;
}
  doodlebug_moves++;
}
