#include "main.h"

const unsigned INPUTFILENAME_POSTFIX_LENGTH = 3;

int main() {
	try {
		ifstream in1, in2;
		string filename1, filename2;
		Calendar calendar1, calendar2;

		cout << "Enter the name of a calendar file." << endl;
		cin >> filename1;
		calendar1.read( filename1 );

		cout << "Enter the name of another calendar file to sync." << endl;
		cin >> filename2;
		calendar2.read( filename2 );

	for ( int i = 0; i < INPUTFILENAME_POSTFIX_LENGTH; i++ ) {
		filename1.pop_back();
	}

	for ( int i = 0; i < INPUTFILENAME_POSTFIX_LENGTH; i++ ) {
		filename2.pop_back();
	}

	calendar1.synchronize( calendar2 );
	calendar1.print();

	calendar1.write( filename1 + ".out");
	calendar1.write( filename2 + ".out" );

	} catch ( invalid_argument& e ) {
		cout << "Invalid argument: " << e.what() << endl;
	} catch ( logic_error& e ) {
		cout << "Logic error: " << e.what() << endl;
	} catch ( ... ) {
		cout << "Unknown exception!" << endl;
	}

	return 0;
}