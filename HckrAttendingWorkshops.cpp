#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshop {
    int start_time;
    int duration;
    int end_time;
};
struct Available_Workshops {
    int n;
    Workshop* workshops;
};

Available_Workshops* initialize(int start_time[], int duration[], int n) {
    Available_Workshops* aw = new Available_Workshops{n, new Workshop[n]};
    for (int i = 0; i < n; i++) {
        auto &w = aw->workshops[i];
        w.start_time = start_time[i];
        w.duration = duration[i];
        w.end_time = w.start_time + w.duration;
    }
    return aw;
}

int CalculateMaxWorkshops(Available_Workshops* aw) {
    int max = 0;
    for (int i = 0; i < aw->n; i++) {
        
    }
}

void Sort(Workshop* workshops, int n) {
    for (int i = 0; i < n - 1; i++) {
        
    }
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
