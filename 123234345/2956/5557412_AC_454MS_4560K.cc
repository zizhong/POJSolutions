#include <iostream>
#include <vector>
using namespace std;


vector<int> counts(10, 0);
vector<int> digits(12, 0);
int repeats = 0;
int lastdigit = -1;
int lastanswer = 0;

vector<int> answer(1000001);

void generate(int n)
{
  while (lastanswer < n)
  {
    for (int i = 0; ; ++i)
    {
      if (i <= lastdigit)
      {
        if (--counts[digits[i]] == 1)
          --repeats;
      }
      else
        lastdigit = i;
      
      ++digits[i];
      
      if (digits[i] == 10)
      {
        digits[i] = 0;
        if (++counts[digits[i]] == 2)
          ++repeats;
      }
      else
      {
        if (++counts[digits[i]] == 2)
          ++repeats;
        break;
      }
    }
    
    if (repeats == 0)
    {
      ++lastanswer;
      int value = 0;
      for (int i = lastdigit; i >= 0; --i)
        value = (value * 10) + digits[i];
      answer[lastanswer] = value;
    }
  }
}

int main()
{
  while (true)
  {
    int n;
    cin >> n;
    if (n == 0)
      break;

    if (n > lastanswer)
      generate(n);
    cout << answer[n] << endl;
  }
  return 0;
}
