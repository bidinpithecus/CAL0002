#ifndef _TRAIN_HPP_
#define _TRAIN_HPP_

#include <vector>
#include <algorithm>

struct Time {
	int hours;
	int minutes;

	Time() : hours(0), minutes(0) {}
	Time(int h, int m) : hours(h), minutes(m) {}
};

struct Train {
	int platform;
	Time arrival;
	Time departure;

	Train() {}
	Train(Time arrival, Time dept, int platform) : platform(platform), arrival(arrival), departure(dept) {}
};

struct Station {
	size_t numOfTrains;
	size_t numOfPlatforms;
	std::vector<Train> trains;

	Station() {}
	Station(size_t numT, size_t numP) : numOfTrains(numT), numOfPlatforms(numP) { trains.assign(numT, Train()); }
	Station(size_t numT, size_t numP, std::vector<Train> trains) : numOfTrains(numT), numOfPlatforms(numP) {
		if (numT >= trains.size()) this->trains = trains;
	}

	bool addTrain(Train train) {
		if (numOfTrains >= trains.size()) {
			return false;
		} else {
			trains.push_back(train);
			return true;
		}
	}
};


int maxStop(Station station);

#endif
