#include "Hamming.h"
#include <string>

using namespace std;

/// Compute hamming distance
int Compute(string a, string b) {
    int lenA = a.length();
    int lenB = b.length();
    int lenCompare = lenA;
    if (lenA > lenB) {
        lenCompare = lenB;
    }
    int ret = 0;
    for (int i=0; i<lenCompare; ++i) {
        if (a[i] != b[i]) {
            ++ret;
        }
    }
    return ret;
}

