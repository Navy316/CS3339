#include <iostream>
#include <iomanip>
#include <bitset>
#include <cmath>
#include <cstring>
using namespace std;

// Convert a float to its IEEE 754 bit representation
string floatToBinary(float value) {
    unsigned int bits;
    memcpy(&bits, &value, sizeof(bits));
    bitset<32> b(bits);
    return b.to_string();
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Error: Program requires exactly 2 floating-point arguments." << endl;
        cout << "Usage: ./fp_overflow_checker loop_bound loop_counter" << endl;
		cout << "loop_bound is a positive floating-point value" << endl;
		cout << "loop_counter is a positive floating-point value" << endl;
        return 1;
    }

    // Convert command-line arguments to floats
    float loopBound = atof(argv[1]);
    float increment = atof(argv[2]);

    // Output IEEE bit representation
    cout << scientific << setprecision(8);
    cout << "loop bound: " << floatToBinary(loopBound) << endl;

    
    cout << "loop_counter: " << floatToBinary(increment) << endl;

    // Detect overflow or precision loss
    float next = loopBound + increment;

    if (next == loopBound || isnan(next) || isinf(next)) {
        cout << "Warning: Possible overflow!" << endl;
        cout << "Overflow threshold:" << endl;
		cout << loopBound << endl;
        cout << floatToBinary(loopBound) << endl;
    } else {
        cout << "No overflow!" << endl;
    }

    return 0;
}
