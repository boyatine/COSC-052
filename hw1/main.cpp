#include "main.h"

int main() {
	Numbers numbers;
	numbers.read(cin);

	cout << "Average: " << numbers.average() << endl;
	return 0;
}