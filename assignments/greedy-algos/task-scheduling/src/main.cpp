#include <iostream>
#include "train.hpp"

using namespace std;

int main(void) {
	vector<Train> trains1;
	trains1.push_back(Train(Time(10, 0), Time(10, 30), 1));
	trains1.push_back(Train(Time(11, 10), Time(11, 30), 1));
	trains1.push_back(Train(Time(12, 0), Time(12, 20), 1));
	Station station1(3, 1, trains1);

	vector<Train> trains2;
	trains2.push_back(Train(Time(10, 0), Time(10, 30), 1));
	trains2.push_back(Train(Time(10, 10), Time(10, 30), 1));
	trains2.push_back(Train(Time(10, 0), Time(10, 20), 2));
	trains2.push_back(Train(Time(10, 30), Time(12, 30), 2));
	trains2.push_back(Train(Time(12, 0), Time(12, 30), 3));
	trains2.push_back(Train(Time(9, 0), Time(10, 5), 1));
	Station station2(6, 3, trains2);

	cout << "Maximum stopped trains at station 1: " << maxStop(station1) << endl;
	cout << "Maximum stopped trains at station 2: " << maxStop(station2) << endl;
}
