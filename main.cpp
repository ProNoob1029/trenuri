#include "iostream"
#include "vector"
#include "fstream"
#include "string"
#include "unordered_map"

using std::vector, std::ifstream, std::string, std::unordered_map;

ifstream fin("input.in");

struct Railway {
    string destination;
    int distance;
};

struct Station {
    string name;
    vector<Railway> neighbours;
};

unordered_map<string, Station> stations;


int main() {

}
