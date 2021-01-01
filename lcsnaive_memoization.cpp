// This program is only for the implementation of the naive recursive algorithm with memoization
// for the lcs problem. With the below implementation you can only find the length of the longest
// subsequence but not the subsequence.

// the header files included are for std io , string and file stream.
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

// The class lcs that has the two functions. one will read the strings from the file and write
// the lcs length and the other will calculate the just the lcs via naive recursive algorithm.

class LCS
{
  public:
    int rows, columns;     // need the rows and columns for strings of different lengths
    int c[30][30];         // maximum size of the memo as 30 since do not think will consider strings
                           // over length considering the experience with naive recursive algorithm
    void arr_initialise(); // initialiases the array with null elements
    int lcs_len(string, string, int, int);
    void lcs_read_write();
};

void LCS ::arr_initialise()
{
  for (int i = 0; i < 30; i++)
    for (int j = 0; j < 30; j++) c[i][j] = NULL;
}

// Below is the function that calculates the lcs via naive recursive algorithm.
int LCS ::lcs_len(string A, string B, int i, int j)
{
  if ((c[i][j] == NULL) and (i >= 0) and (j >= 0)) // Taking note of the memo and returning the same.
  {
    if (A[i] == B[j]) return c[i][j] = lcs_len(A, B, i - 1, j - 1) + 1;
    else              return c[i][j] = max(lcs_len(A, B, i - 1, j), lcs_len(A, B, i, j - 1));
  }
  else return c[i][j];
}

// This is the function that will read the strings from the file and write the output to console.
void LCS ::lcs_read_write()
{
  string line, A, B;
  int position, length, lcs_length, case_num = 1;
  clock_t t;
  ifstream myfile;
  myfile.open("lcs_test_case.txt", ios::in); // reading in from the file
  if (myfile.is_open())
  {
    while (myfile.good())
    {
      getline(myfile, line);
      position = line.find(' ');
      length = line.length();
      A = line.substr(0, position);
      B = line.substr(position + 1, length);
      rows = A.length();
      columns = B.length();
      arr_initialise();
      t = clock();
      cout << " case " << case_num << " lcs length is: " << lcs_len(A, B, rows - 1, columns - 1);
      cout << " and the time taken is " << (double)((clock() - t) / CLOCKS_PER_SEC) << endl;
      case_num++;
    }
    myfile.close();
  } 
  else cout << " \n Unable to open the file. The input case file may not exist. ";
}

int main()
{
  LCS l;
  l.lcs_read_write();
  return 0;
}
