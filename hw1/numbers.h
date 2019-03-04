#ifndef NUMBERS_H
#define NUMBERS_H

#include <iostream>
#include <vector>

using namespace std;

class Numbers {
	public:
		void read(istream &in=cin);
		double average();

	private:
		vector<double> numbers;
};

#endif