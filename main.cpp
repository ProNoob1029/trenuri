#include "iostream"
#include "vector"
#include "fstream"
#include "string"
#include "unordered_map"
#include "thread"
#include "raylib.h"

using namespace std;

ifstream railway_in("railway.in");

struct Railway {
    string destination;
    int distance = 1;
};

struct Station {
    string name;
    vector<Railway> neighbours;
    int id = -1;
};

const int inf = -1;
unordered_map<string, Station> stations;
string keys[200];
int cost_min[200][200];

void read_railway() {
    char buffer[200];
    int distance;
    string station_name_1;
    string station_name_2;
    Railway railway_1;
    Railway railway_2;
    while (railway_in.getline(buffer, 200, ',')) {
        station_name_1 = buffer;
        railway_in.getline(buffer, 200, ',');
        station_name_2 = buffer;
        railway_in.getline(buffer, 200);
        distance = stoi(buffer);
        railway_1.distance = distance;
        railway_2.distance = distance;
        railway_1.destination = station_name_2;
        railway_2.destination = station_name_1;
        stations[station_name_1].name = station_name_1;
        stations[station_name_2].name = station_name_2;
        stations[station_name_1].neighbours.push_back(railway_1);
        stations[station_name_2].neighbours.push_back(railway_2);
    }

    vector<string> key_list;
    key_list.reserve(stations.size());
    for (pair<string, Station> pairs : stations) {
        key_list.push_back(pairs.first);
    }

    int id = 0;
    for (const string& key : key_list) {
        stations[key].id = id;
        keys[id] = key;
        id++;
    }
}

void calculate_roy_floyd() {
    int size = stations.size();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                cost_min[i][j] = 0;
            } else {
                cost_min[i][j] = inf;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        for (const Railway& railway : stations[keys[i]].neighbours) {
            cost_min[i][stations[railway.destination].id] = railway.distance;
        }
    }

    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (cost_min[i][k] != inf && cost_min[k][j] != inf) {
                    if (cost_min[i][j] == inf) {
                        cost_min[i][j] = cost_min[i][k] + cost_min[k][j];
                    } else if (cost_min[i][j] > cost_min[i][k] + cost_min[k][j]) {
                        cost_min[i][j] = cost_min[i][k] + cost_min[k][j];
                    }
                }
            }
        }
    }
}

thread iasi_thread;
bool iasi_done = true;

void window() {
    iasi_done = false;
    SetTraceLogLevel(LOG_ERROR);

    InitWindow(800, 800, "Iasi");

    SetTargetFPS(60);

    while (!WindowShouldClose() && !iasi_done) {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawText("Iasi", 20, 20, 80, BLACK);
        EndDrawing();
    }

    CloseWindow();
    iasi_done = true;
}

void open_Iasi() {
    iasi_thread = thread(window);
}

void close_Iasi() {
    if (!iasi_done) {
        iasi_done = true;
        iasi_thread.join();
    }
}

int main() {
    read_railway();
    calculate_roy_floyd();

    int min = cost_min[stations["Cluj-Napoca"].id][stations["Iași"].id];
    printf("%d\n", min);

    string station = "Cluj-Napoca";
    char buffer[200];
    string input;

    while (true) {
        for (const Railway& railway : stations[station].neighbours) {
            printf("%s %d\n", railway.destination.c_str(), railway.distance);
        }

        cin.getline(buffer , 200);
        input = buffer;

        if (stations.count(input)) {
            station = input;
        }
    }
    char num;
    cin >> num;
    open_Iasi();

    cin >> num;
    close_Iasi();
}
