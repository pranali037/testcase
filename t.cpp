#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

// Function to decode a value from a given base
int decodeValue(int base, string value) {
    return stoi(value, nullptr, base);
}

// Function to perform Lagrange interpolation to find f(0)
double lagrangeInterpolation(vector<pair<int, int>> points) {
    int n = points.size();
    double result = 0.0;

    for (int i = 0; i < n; i++) {
        double term = points[i].second;  // Start with y_i
        
        // Multiply by the Lagrange basis polynomial
        for (int j = 0; j < n; j++) {
            if (i != j) {
                term *= (0.0 - points[j].first) / (points[i].first - points[j].first);
            }
        }
        
        // Add the term to the result
        result += term;
    }

    return result;
}

int main() {
    // Example JSON input represented in C++
    map<int, pair<int, string>> input = {
        {1, {10, "4"}},
        {2, {2, "111"}},
        {3, {10, "12"}},
        {4, {4, "213"}}
    };

    // Decode the values
    vector<pair<int, int>> points;
    for (const auto& entry : input) {
        int x = entry.first;
        int base = entry.second.first;
        string value = entry.second.second;
        int y = decodeValue(base, value);
        points.push_back({x, y});
    }

    // Calculate the constant term using Lagrange interpolation
    double constantTerm = lagrangeInterpolation(points);

    // Output the result
    cout << "The constant term (c) is: " << constantTerm << endl;

    return 0;
}
