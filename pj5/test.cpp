#include <string>
#include <iostream>

using namespace std;

int main ()
{
	string a, b, c, d, e, f, g;

	for ( unsigned z = 0; z < 8; z++ )
	{
		a = to_string(z);
		for ( unsigned y = 0; y < 8; y++ )
		{
			if ( y != z ) {
				b = to_string(y);
				for ( unsigned x = 0; x < 8; x++ ) 
				{
					if ( x != y ) {
						c = to_string(x);
						for ( unsigned w = 0; w < 8; w++ ) 
						{
							if ( w != x ) 
							{
								d = to_string(w);
								for ( unsigned v = 0; v < 8; v++ )
								{
									if ( v != w ) 
									{
										e = to_string(v);
										for ( unsigned u = 0; u < 8; u++ )
										{
											if ( u != v ) {
												f = to_string(u);
												for ( unsigned t = 0; t < 8; t++ )
												{
													if (t != u )
													{
														g = to_string(t);
														cout << a + b + c + d + e + f + g << endl;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;
}