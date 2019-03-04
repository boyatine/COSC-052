#include <iostream>
#include <vector>

using namespace std;

void printOctal(int n, int c);



void printOctal(int n, int c, char []a ) {
	
    if (c > n)
        return;
    if (c == n) {
        target[c] = ;
        printf("%s\n", target);
        return;
    }
    if (count < size) {
        target[count] = '1';
        foo(size, count+1);
    }
    target[count] = '0';
    foo(size, count+1);
}

int main ( )
{

	int n = 4;

	char target[n];

	printOctal(n, 4);

	return 0;
}