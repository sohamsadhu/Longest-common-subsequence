// This is the c++ implementation of the dynamic programming for LCS.

#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

class LCS
{
  public:
    void read_write();
    void dyn_prog(string, string);
    timespec diff(timespec, timespec);
};

void LCS ::dyn_prog(string A, string B)
{
  int rows = A.length() + 1;
  int columns = B.length() + 1;
  int table[rows][columns];

  // initialise the arrays
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) table[i][j] = 0;

  // make the table
  for (int i = 1; i < rows; i++)
  {
    for (int j = 1; j < columns; j++)
    {
      if (A[i - 1] == B[j - 1])
        table[i][j] = table[i - 1][j - 1] + 1;
      else
        table[i][j] = max(table[i - 1][j], table[i][j - 1]);
    }
  }

  string lcs = "";
  // Traverse the table and put the characters of the LCS that match 
  // into the empty string lcs that will be retruned or printed.
  while ((rows != 0) and (columns != 0))
  {
    if      (table[rows - 1][columns - 1] == table[rows - 1][columns - 2]) columns--;
    else if (table[rows - 1][columns - 1] == table[rows - 2][columns - 1]) rows--;
    else
    {
      lcs.push_back(A[rows - 2]);
      rows--;
      columns--;
    }
  }

  cout << " the length of lcs is " << lcs.length() << " for string length " 
      << A.length() << " and the lcs is: " << " ";
  for (int i = lcs.length() - 1; i >= 0; i--) cout << lcs[i];
}

void LCS ::read_write()
{
  string A, B, line; // A, B = strings that have LCS, line = from file that has both the strings
  ifstream myfile;
  int case_num = 1;
  struct timespec ts, te; // The structure entries for start and end time.
  long r1, r2;
  myfile.open("dna_input_long.txt"); // file opened for reading with ifstream so ios::in mode is default
  while (!myfile.eof())
  {
    getline(myfile, line);
    A = line.substr(0, line.find(' '));
    B = line.substr(line.find(' ') + 1, line.length());
    cout << "case " << case_num;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);
    dyn_prog(A, B);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &te);
    cout << " time taken " << diff(ts, te).tv_sec << ":" << diff(ts, te).tv_nsec << endl;
    case_num++;
  }
  myfile.close();
  myfile.open("binary_seq_input_long.txt"); // file opened for reading with ifstream so ios::in mode is default
  while (!myfile.eof())
  {
    getline(myfile, line);
    A = line.substr(0, line.find(' '));
    B = line.substr(line.find(' ') + 1, line.length());
    cout << "case " << case_num;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);
    dyn_prog(A, B);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &te);
    cout << " time taken " << diff(ts, te).tv_sec << ":" << diff(ts, te).tv_nsec << endl;
    case_num++;
  }
  myfile.close();
}

// The following piece of code is adopted from 
// www.guyrutenberg.com/2007/09/22profiling-code-using-clock_gettime
timespec LCS ::diff(timespec start, timespec end)
{
  timespec temp;
  if ((end.tv_nsec - start.tv_nsec) < 0)
  {
    temp.tv_sec = end.tv_sec - start.tv_sec - 1;
    temp.tv_nsec = 1000000000 + end.tv_nsec - start.tv_nsec;
  }
  else
  {
    temp.tv_sec = end.tv_sec - start.tv_sec;
    temp.tv_nsec = end.tv_nsec - start.tv_nsec;
  }
  return temp;
}

int main()
{
  LCS l;
  l.read_write();
  return 0;
}
