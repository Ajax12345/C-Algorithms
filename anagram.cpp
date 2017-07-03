int main()
{
  string a = "james";
  string b = "joe";

  vector<char>a1;
  vector<char>b1;

  for (int i = 0; i < a.length(); i++)
  {
    a1.push_back(a[i]);
  }

  for (int i = 0; i < b.length(); i++)
  {
    b1.push_back(b[i]);
  }

  int counter = 0;

  for (int i = 0; i < a.length(); i++)
  {
    if (count(a1.begin(), a1.end(), a[i]) == count(b1.begin(), b1.end(), a[i]))
    {
      counter++;
    }
  }

  cout << ((counter == a.length())?"YES":"NO")<< endl;

}
