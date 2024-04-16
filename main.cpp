#include "iostream"
#include "vector"
#include "fstream"
#include "string"
#include "unordered_map"
#include "thread"
#include "raylib.h"
#include "windows_stuff.h"
#include "font.h"

using namespace std;

struct Dialog {
    string introducere = "Bun venit la trip trip cu trenul prin România!🚂\n";
    string pickOption = "Alege una din următoarele opțiuni: \n0. Ieșire\n1. Excursie cu trenul\n"
                        "2. Află distanța între 2 orașe\n\nNumărul opțiunii: ";
    string invalidInput = "Opțiune invalidă, încearcă din nou!\n\n";
    string introExcursie = "Te-ai decis să mergi în excursie cu trenul prin țară!🚂🚂\n"
                           "Ai auzit un zvon cum că în unele orașe ai putea găsi niște poze pierdute.📷\n"
                           "Alege stația la care vrei să avansezi și încearcă să descoperi cât mai multe poze!\n"
                           "Pornești din Cluj.\nScrie exit pentru a te reîntoarce la meniul principal\n\n";
    string statii = "Stațiile disponibile:\n";
    string statie = "%d. %s, %d kilometri\n";
    string introDist = "Alege 2 orașe pentru care vrei să afli distanța minimă între ele\n\n";
    string yourPick = "Alegerea ta: ";
    string primulOras = "Primul oraș: ";
    string alDoileaOras = "Al doilea oraș: ";
    string tryAgain = "Vrei să încerci din nou? (da/nu): ";
    string distOrase = "Distanța cu trenul dintre %s și %s este de (aproximativ) %d kilometri\n";
} dialog;

const int MAX_OPTION = 2;
enum Option {
    EXIT = 0,
    EXCURSIE = 1,
    DISTANTA
};

ifstream railway_in("railway.in");
ifstream picture_in("pictures.in");

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
unordered_map<string, string> pictures;
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

void read_pictures() {
    string station;
    string fileName;
    while (getline(picture_in, station, ',')) {
        getline(picture_in, fileName);
        pictures[station] = fileName;
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

thread window_thread;
bool window_done = true;

void window(const string &station) {
    window_done = false;
    SetTraceLogLevel(LOG_ERROR);

    InitWindow(800, 800, "Picture");

    SetTargetFPS(60);

    LoadDefaultFont();

    Texture texture = LoadTexture(pictures[station].c_str());

    SetWindowSize(texture.width / 2, texture.height / 2);

    while (!WindowShouldClose() && !window_done) {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawTextureEx(texture, {0, 0}, 0, 0.5, WHITE);
        BeginShaderMode(defaultShader);
        DrawTextEx(defaultFont, station.c_str(), {20, 20}, 80, 0, WHITE);
        EndShaderMode();
        EndDrawing();
    }

    UnloadTexture(texture);
    UnloadDefaultFont();

    CloseWindow();
}

void close_window() {
    if (!window_done) {
        window_done = true;
        window_thread.join();
    }
}

void open_window(string &station) {
    close_window();
    window_thread = thread(window, station);
}

bool tryAgain() {
    bool done = false;
    string input;
    bool result;

    while (!done) {
        cout << dialog.tryAgain;

        getline(cin, input);

        cout << "\n";

        if (input.find("da") != string::npos) {
            result = true;
            done = true;
        } else if (input.find("nu") != string::npos) {
            result = false;
            done = true;
        } else {
            cout << dialog.invalidInput;
        }
    }

    cout << "\n";

    return result;
}

void excursie() {
    cout << dialog.introExcursie;

    string station = "Cluj-Napoca";
    string input;

    while (input != "exit") {
        cout << dialog.statii;
        vector<string> options;
        bool valid = false;

        int i = 1;

        for (const Railway& railway : stations[nameIds[station]].neighbours) {
            printf(dialog.statie.c_str(), i, railway.destName.c_str(), railway.distance);
            options.push_back(railway.destName);
            i++;
        }

        cout << "\n" << dialog.yourPick;

        getline(cin, input);

        cout << "\n";

        if (nameIds.count(input)) {
            station = input;
            valid = true;
        } else {
            try {
                int option = stoi(input);
                if (option > options.size()) {
                    throw invalid_argument("invalid option");
                }
                station = options[option - 1];
                valid = true;
            } catch (...) {
                cout << dialog.invalidInput;
            }
        }

        if (valid && pictures.count(station)) {
            open_window(station);
        } else {
            close_window();
        }
    }

    close_window();
}

Option pickOption() {
    bool done = false;
    string input;
    Option option;

    while (!done) {
        cout << dialog.pickOption;

        getline(cin, input);

        cout << "\n";

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

void distantaOras() {
    bool done = false;
    string input;
    string primul;
    string second;

    while (!done) {
        cout << dialog.introDist;

        bool primulDone = false;

        while (!primulDone) {
            cout << dialog.primulOras;

            getline(cin, input);

            cout << "\n";

            if (nameIds.count(input)) {
                primul = input;
                primulDone = true;
            } else {
                cout << dialog.invalidInput;
            }
        }

        bool secondDone = false;

        while (!secondDone) {
            cout << dialog.alDoileaOras;

            getline(cin, input);

            cout << "\n";

            if (nameIds.count(input)) {
                second = input;
                secondDone = true;
            } else {
                cout << dialog.invalidInput;
            }
        }

        int cost = cost_min[nameIds[primul]][nameIds[second]];

        printf(dialog.distOrase.c_str(), primul.c_str(), second.c_str(), cost);

        cout << "\n";

        done = !tryAgain();
    }
}

int main() {
    windows_stuff();
    read_railway();
    read_pictures();
    calculate_roy_floyd();

    bool running = true;

    cout << dialog.introducere;

    while (running) {
        switch (pickOption()) {
            case EXCURSIE:
                excursie();
                break;
            case DISTANTA:
                distantaOras();
                break;
            case EXIT:
                running = false;
                break;
        }
    }
}
