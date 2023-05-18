#include <iostream>
#include "train.hpp"

using namespace std;

int main(int argc, char** argv) {
	int numOfTrains = 6;
	int numOfPlatforms = 3;
	Station station(numOfTrains, numOfPlatforms);
	station.addTrain(Train(Time(10, 0), Time(10, 30), 1));
	station.addTrain(Train(Time(10, 10), Time(10, 30), 1));
	station.addTrain(Train(Time(10, 0), Time(10, 20), 2));
	station.addTrain(Train(Time(10, 30), Time(12, 30), 2));
	station.addTrain(Train(Time(12, 0), Time(12, 30), 3));
	station.addTrain(Train(Time(9, 0), Time(10, 5), 1));

	cout << "Num max of stops: " << maxStop(station) << endl;
}
