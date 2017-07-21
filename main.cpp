#include <iostream>
#include <sys/time.h>
#include "Lagrange.h"

using namespace std;

long long convert(timeval tp) {
    return (long long) tp.tv_sec * 1000L + tp.tv_usec / 1000;
}

//First real C++ program Jiachen ever wrote. Excited!
int main() {
    unsigned int start, stop, debugInterval;
    cout << "Start: ";
    cin >> start;
    cout << "Stop: ";
    cin >> stop;
    cout << "Print interval(0 to disable): ";
    cin >> debugInterval;
    cout << "Computing from " << start << " to " << stop << endl;

    Lagrange *lagrange = new Lagrange(start, stop, 4);
    lagrange->setPrintInterval(debugInterval);

    struct timeval tp;
    gettimeofday(&tp, NULL);
    long long ms = convert(tp);
    lagrange->solve();
    gettimeofday(&tp, NULL);
    cout << "\nDone." << endl;
    cout << "Time Elapsed: " << convert(tp) - ms << " millis\n";
    return 0;
}

