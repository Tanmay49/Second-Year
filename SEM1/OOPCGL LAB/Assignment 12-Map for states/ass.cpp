
#include <iostream>
#include <map>
#include <stdlib.h>
#include <iomanip>
using namespace std;

string capitalize(string &s) // capitalize all the leters in the string.
{
  string tmp = "";
  for (int i = 0; i < s.length();i++)
  {
    char ch=s[i];
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
      tmp += (char)(ch & (~(1 << 5)));
  }
  s = tmp;
  return s;
}

map<string, long long>::iterator findMyState(string &s, map<string, long long> &mp)
{
  map<string, long long>::iterator state;
  map<string, long long>::iterator itr = mp.begin();
  int cnt = 0;

  for (itr = mp.begin(); itr != mp.end(); itr++)
  {
    int tmp = itr->first.find(s);
    if (tmp != string::npos)
    {
      state = itr;
      cnt++;
    }
  }
  if (cnt > 1)
  {
    cout << "UNABLE TO IDENTIFY!!!!\nRE-ENTER";
    return mp.end();
  }
  else if (cnt == 0)
  {
    cout << "\nSTATE NOT FOUND";
    return mp.end();
  }
  else
    return state;
}

int main()
{
  map<string, long long> mp;            // map created
  map<string, long long>::iterator itr; // Iterator for map

  mp.insert(make_pair("MAHARASHTRA", 12765123));

  int ch;
  string state, State1;

  while (1)
  {
    cout << "\nMENU\n1.Search State\n2.Add state\n3.Exit\nEnter your choice:";
    int tmp;
    cin >> ch;
    switch (ch)
    {

    case 1:
      cout << "\nEnter State Name to search:";
      cin >> state;
      State1 = state;
      state = capitalize(state);
      itr = findMyState(state, mp);

      if (itr != mp.end())
      {
        cout << "\n Search Found\n";
        if (State1.length() != itr->first.length())
          cout << itr->first << " has population of approx. " << itr->second << "\n";
        else
          cout << State1 << " has population of approx. " << itr->second << "\n";
      }
      cout << setw(100) << setfill('_') << endl;
      break;

    case 2:
      cout << "Enter state: ";
      cin >> state;
      cout << "Enter population: ";
      cin >> tmp;
      mp.insert(make_pair(capitalize(state), tmp));
      break;

   

    case 3:
      cout << "\nTHANK YOU!!!";
      exit(0);
    }
  }

  return 0;
}