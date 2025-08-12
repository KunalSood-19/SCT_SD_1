#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip> // for fixed and setprecision

using namespace std;

double convert(double temp, string from, string to) {
    if (from == "C" && to == "F") return temp * 9.0 / 5.0 + 32.0;
    if (from == "F" && to == "C") return (temp - 32.0) * 5.0 / 9.0;
    if (from == "C" && to == "K") return temp + 273.15;
    if (from == "K" && to == "C") return temp - 273.15;
    return temp;
}

int main() {
    // UTF-8 output
    cout << "Content-type: text/plain; charset=UTF-8\n\n";

    char* query = getenv("QUERY_STRING");
    if (!query) {
        cout << "Error: No query string";
        return 0;
    }

    string q = query;
    double temp = 0;
    string from, to;

    // Parse parameters from QUERY_STRING
    size_t tpos = q.find("temp=");
    size_t fpos = q.find("&from=");
    size_t topos = q.find("&to=");
    if (tpos != string::npos && fpos != string::npos && topos != string::npos) {
        temp = stod(q.substr(tpos + 5, fpos - (tpos + 5)));
        from = q.substr(fpos + 6, topos - (fpos + 6));
        to = q.substr(topos + 4);
    }

    double result = convert(temp, from, to);

    // Fixed precision with UTF-8 degree symbol
    cout << fixed << setprecision(2) << result << " \u00B0" << to;

    return 0;
}
