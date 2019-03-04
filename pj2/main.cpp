#include "main.h"

int main () {
	Bikes bikelist;

	try {
		bikelist.read( "bikes.dta" );

		bikelist.print();

		cout << "Total gears: " << bikelist.getTotalGears() << endl;

		cout << "Total carrying capacity: " << bikelist.getTotalCapacity() << endl;

	} catch ( invalid_argument& e ) {
		cout << "Invalid argument: " << e.what() << endl;
	} catch ( logic_error& e ) {
		cout << "Logic error: " << e.what() << endl;
	} catch ( ... ) {
		cout << "Unknown exception!" << endl;
	}

	return 0;
}

// int main() {
//     Client *pClient = new Client(1);
//     Vehicle * pVehicle = pClient->getVehicle();
//     pVehicle->printVehicle();
//     return 0;
// }