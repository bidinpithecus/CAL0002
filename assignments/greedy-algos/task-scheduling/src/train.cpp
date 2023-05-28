#include "train.hpp"

bool compareTrains(const Train& train1, const Train& train2) {
	return train1.departure.hours < train2.departure.hours || (train1.departure.hours == train2.departure.hours && train1.departure.minutes < train2.departure.minutes);
}

int maxStop(Station station) {
	// Sort trains based on their departure time
	std::sort(station.trains.begin(), station.trains.end(), compareTrains);

	int count = 0;
	std::vector<Time> platformDepartureTimes(station.numOfPlatforms + 1);

	// Assign platforms to trains
	for (const Train& train : station.trains) {
		int platform = train.platform;
		if ((train.departure.hours > platformDepartureTimes[platform].hours ||
			 (train.departure.hours == platformDepartureTimes[platform].hours &&
			  train.departure.minutes >= platformDepartureTimes[platform].minutes)) &&
			train.arrival.hours >= platformDepartureTimes[platform].hours &&
			(train.arrival.hours > platformDepartureTimes[platform].hours ||
			 train.arrival.minutes >= platformDepartureTimes[platform].minutes)) {
			count++;
			platformDepartureTimes[platform] = train.departure;
		}
	}

	return count;
}
