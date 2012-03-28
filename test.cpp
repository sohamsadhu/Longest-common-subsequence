#include<iostream>
#include<string>

using namespace std ;

int main()
{
	/*string s1, s2 ;
	cout << " \n enter two strings \n " ;
	getline( cin, s1 ) ;
	getline( cin, s2 );
	s1 = s2.substr(2,5 ) ;
	cout << s1 << endl ;
	cout << s2.substr( 0, 0 ) << endl ;*/
	int mat [ 204800 ] [ 204800 ] ;
	for ( int i = 0 ; i < 204800 ; i ++ )
	{
		for ( int j = 0 ; j < 204800 ; j++ )
		{
			mat [ i ] [ j ] = 1 ;
		}
	}
	long int result = 0L ;
	for ( int i = 0 ; i < 204800 ; i ++ )
	{
		for ( int j = 0 ; j < 204800 ; j++ )
		{
			result += mat [ i ] [ j ] ; 
		}
	}
	cout << result << endl;
	return 0 ;
}
