/* 
This program is only for the implementation of the naive recursive algorithm for the LCS problem.
With the below implementation you can only find the length of the longest subsequence but not the subsequence.
*/

// The header files included are for std io , string and file stream.
#include<iostream>
#include<string>
#include<fstream>
#include<time.h>
using namespace std;

/* The class LCS that has the two functions. One will read the strings from the file and write the LCS length.
And the other will calculate the just the LCS via naive recursive algorithm */

class LCS
{
    public:
        int lcs_len( string, string ) ;
        void lcs_read_write();
        timespec diff ( timespec , timespec ) ;
};

/* Below is the function that calculates the LCS via naive recursive algorithm */  
int LCS :: lcs_len( string A, string B )
{
    if( A.length() == 0 || B.length() == 0 )
    {
        return 0;
    }
    string c, d ;
    c = A.substr( 0, A.length() - 1 );
    d = B.substr( 0, B.length() - 1 );
    if( A[ A.length() - 1 ]  == B[ B.length() - 1 ] )
    {
        return  lcs_len( c , d ) + 1 ;
    }
    else
    {
        return max( lcs_len( c, B ) , lcs_len( A, d ) );
    }    
}

/* Timing function adapted from www.guyrutenberg.com/2007/09/22profiling-code-using-clock_gettime */
timespec LCS :: diff( timespec start, timespec end )
{
	timespec temp ;
	if ( ( end.tv_nsec - start.tv_nsec ) < 0 )
	{
		temp.tv_sec = end.tv_sec - start.tv_sec - 1 ;
		temp.tv_nsec = 1000000000 + end.tv_nsec - start.tv_nsec ;
	}
	else
	{
		temp.tv_sec = end.tv_sec - start.tv_sec ;
		temp.tv_nsec = end.tv_nsec - start.tv_nsec ;
	}
	return temp ;
}

/* This is the function that will read the strings from the file and write the output to console */
void LCS :: lcs_read_write()
{
    string line, A, B ;
    int position, length, lcs_length, case_num = 1 ;
    struct timespec ts, te ;
    ifstream myfile ;
    myfile.open("lcs_test_case.txt", ios::in);
    if ( myfile.is_open() )
    {
        while( myfile.good() )
        {
            getline( myfile, line );
            position = line.find(' ');
            length = line.length();
            A = line.substr( 0 , position ) ;
            B = line.substr( position + 1 , length ) ;
            clock_gettime( CLOCK_PROCESS_CPUTIME_ID, &ts ) ;
            cout << " case " << case_num << " lcs length is: " << lcs_len( A, B ) << " for strings of length " << A.length() ;
            clock_gettime( CLOCK_PROCESS_CPUTIME_ID, &te ) ;
            cout<< " and the time taken is " << diff( ts, te ).tv_sec << ":" << diff( ts, te ).tv_nsec << endl ;
            case_num++ ; 
        }
        myfile.close();
    }
    else 
    {
        cout << " \n Unable to open the file. The input case file may not exist. " ;
    }
}

/* The main program that will only call the read write function for LCS */
int main()
{
    LCS l ;
    l.lcs_read_write(); 
    return 0; 
}
