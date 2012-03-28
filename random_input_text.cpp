/* Program to generate the random input strings for the LCS pattern programs */

#include<cstdlib>
#include<string>
#include<iostream>
#include<cmath>
#include<fstream>

using namespace std ;

int main()
{
    string dna_sequence = "ACGT" ;
	string binary_sequence = "01" ;
	ofstream dna_seq, bin_seq ;
	dna_seq.open( "dna_input_long.txt" ) ;
	bin_seq.open( "binary_seq_input_long.txt" ) ;
	int index ;
	// srand( time( NULL ) ) ;
	for ( int i = 0 ; i < 1 ; i++ )
	{
        string A = "", B = "", C = "", D = "" ;
		for ( int k = 0 ; k < 20000 ; k++ )
		{
            index = rand() % 4 ;
			A.push_back( dna_sequence[ index ] ) ;
			index = rand() % 4 ;
			B.push_back( dna_sequence[ index ] ) ;
		    index = rand() % 2 ;
		    C.push_back( binary_sequence[ index ] ) ;
			index = rand() % 2 ;
			D.push_back( binary_sequence[ index ] ) ;
		}
		dna_seq << A << " " << B << endl ;
		bin_seq << C << " " << D << endl ;
	}
	dna_seq.close();
	bin_seq.close();
	return 0 ;
}
