#include <iostream>
using namespace std;
int main()
{
    int p, e, i, d;
    int n = 0;
    int j = 1;
    while( 1 )
    {
        cin >> p >> e >> i >> d;
        if( p == -1 && e == -1 && i == -1 && d == -1 )
            break;
        n = ( p * 5544 + e * 14421 + i * 1288 - d + 21252 ) % 21252;
        if( !n )
            n = 21252;
        cout << "Case " << j++ << ": the next triple peak occurs in " << n << " days." << endl;
    }
    return 0;
}

