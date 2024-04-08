#include "iostream"
#include "vector"
#include "fstream"
#include "string"
#include "unordered_map"
#include "thread"
#include "raylib.h"
#include "windows_stuff.h"

using namespace std;

ifstream railway_in("railway.in");

struct Railway {
    string destination;
    int distance;
};

struct Station {
    string name;
    vector<Railway> neighbours;
};

unordered_map<string, Station> stations;

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
    windows_stuff();
    read_railway();
    for (const Railway& railway : stations["Simeria"].neighbours) {
        printf("%s %d\n", railway.destination.c_str(), railway.distance);
    }
    char num;
    cin >> num;
    open_Iasi();

    cin >> num;
    close_Iasi();
}
