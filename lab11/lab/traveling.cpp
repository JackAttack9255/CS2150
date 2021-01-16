#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth& me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    // TODO: YOUR CODE HERE
    string firstCity = dests.at(0);
    dests.erase(dests.begin());
    sort(dests.begin(), dests.end());
    float minDistance = 999999999.99;
    vector<string> shortRoute;
    do {
        float pathDistance = computeDistance(me, firstCity, dests);
        if(pathDistance < minDistance) {
            minDistance = pathDistance;
            shortRoute = dests;
        }
    } while(next_permutation(dests.begin(), dests.end()));
    
    cout << "Minimum path has distance " << minDistance << ": ";
    printRoute(firstCity, shortRoute);
    return 0;
}


// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
/** \brief computes distance
* \fn computeDistance
*
*/
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
    float distance = 0;
    distance += me.getDistance(start, dests.at(0));

    for(int i = 1; i < dests.size(); i++) {
        distance += me.getDistance(dests.at(i-1), dests.at(i));
    }
    distance += me.getDistance(dests.at(dests.size() - 1), start);

    return distance;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
    cout << start << " -> ";
    for(int i = 0; i < dests.size(); i++) {
        cout << dests.at(i);
        cout << " -> ";
    }
    cout << start;
    cout << endl;

}
