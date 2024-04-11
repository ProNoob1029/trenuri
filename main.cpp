#include "iostream"
#include "vector"
#include "fstream"
#include "string"
#include "unordered_map"
#include "thread"
#include "raylib.h"

using namespace std;

struct Dialog {
    string introducere = "Bun venit la trip trip cu trenul prin România!\n";
    string pickOption = "Alege una din următoarele opțiuni: \n0. Ieșire\n1. Excursie cu trenul\n\nNumărul opțiunii: ";
    string invalidInput = "\nOpțiune invalidă, încearcă din nou!\n";
} dialog;

const int MAX_OPTION = 1;
enum Option {
    EXIT = 0,
    EXCURSIE = 1
};

ifstream railway_in("railway.in");

struct Railway {
    int destId = -1;
    string destName;
    int distance = 1;
};

struct Station {
    int id = -1;
    string name;
    vector<Railway> neighbours;
};

unordered_map<string, int> nameIds;
vector<Station> stations;

const int inf = -1;
int cost_min[200][200];

void read_railway() {
    int distance;
    string distanceStr;
    string station_name_1;
    string station_name_2;
    Railway railway_1;
    Railway railway_2;
    int id = 0;
    while (getline(railway_in, station_name_1, ',')) {
        getline(railway_in, station_name_2, ',');
        getline(railway_in, distanceStr);
        distance = stoi(distanceStr);

        if (nameIds.count(station_name_1) == 0) {
            nameIds[station_name_1] = id;
            id++;
            stations.emplace_back();
        }
        if (nameIds.count(station_name_2) == 0) {
            nameIds[station_name_2] = id;
            id++;
            stations.emplace_back();
        }

        railway_1.distance = distance;
        railway_2.distance = distance;
        railway_1.destName = station_name_2;
        railway_2.destName = station_name_1;
        railway_1.destId = nameIds[station_name_2];
        railway_2.destId = nameIds[station_name_1];

        stations[nameIds[station_name_1]].name = station_name_1;
        stations[nameIds[station_name_2]].name = station_name_2;
        stations[nameIds[station_name_1]].neighbours.push_back(railway_1);
        stations[nameIds[station_name_2]].neighbours.push_back(railway_2);
        stations[nameIds[station_name_1]].id = nameIds[station_name_1];
        stations[nameIds[station_name_2]].id = nameIds[station_name_2];
    }
}

void calculate_roy_floyd() {
    int size = static_cast<int>(stations.size());

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                cost_min[i][j] = 0;
            } else {
                cost_min[i][j] = inf;
            }
        }
    }

    for (const Station& station : stations) {
        for (const Railway& railway : station.neighbours) {
            cost_min[station.id][railway.destId] = railway.distance;
        }
    }

    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (cost_min[i][k] != inf && cost_min[k][j] != inf) {
                    if (cost_min[i][j] == inf || cost_min[i][j] > cost_min[i][k] + cost_min[k][j]) {
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

    Texture bg = LoadTexture("iasi.png");

    while (!WindowShouldClose() && !iasi_done) {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawTextureEx(bg, {-100, -250}, 0, 1, WHITE);
        DrawText("Iasi", 20, 20, 80, WHITE);
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

void excursie() {
    string station = "Cluj-Napoca";
    string input;

    while (input != "exit") {
        for (const Railway& railway : stations[nameIds[station]].neighbours) {
            printf("%s %d\n", railway.destName.c_str(), railway.distance);
        }

        getline(cin, input);

        if (nameIds.count(input)) {
            station = input;
            if (station == "Iași") {
                open_Iasi();
            } else {
                close_Iasi();
            }
        }
    }

    close_Iasi();
}

Option pickOption() {
    bool done = false;
    string input;
    Option option;

    while (!done) {
        cout << dialog.pickOption;

        getline(cin, input);

        try {
            option = (Option)stoi(input);
            if (option > MAX_OPTION) {
                throw invalid_argument("invalid option");
            }
            done = true;
        } catch (...) {
            cout << dialog.invalidInput;
        }
    }

    cout << "\n";

    return option;
}

int main() {
    read_railway();
    calculate_roy_floyd();

    bool running = true;

    cout << dialog.introducere;

    while (running) {
        switch (pickOption()) {
            case EXCURSIE:
                excursie();
                break;
            case EXIT:
                running = false;
                break;
        }
    }
}
