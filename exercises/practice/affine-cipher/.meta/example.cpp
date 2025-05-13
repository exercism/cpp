#include <cctype>
#include <stdexcept>

#include "affine_cipher.h"

namespace affine_cipher {

static int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

static int mod(int x, int m) {
    int r = x % m;
    return r < 0 ? r + m : r;
}

static int modinv(int a, int m) {
    int t = 0, newt = 1;
    int r = m, newr = a;
    while (newr != 0) {
        int q = r / newr;
        t -= q * newt;
        std::swap(t, newt);
        r -= q * newr;
        std::swap(r, newr);
    }
    if (r != 1) throw std::invalid_argument("a and m must be coprime.");
    return t < 0 ? t + m : t;
}

std::string encode(const std::string& text, int a, int b) {
    const int m = 26;
    if (gcd(a, m) != 1) throw std::invalid_argument("a and m must be coprime.");
    std::string out;
    out.reserve(text.size());
    for (char ch : text) {
        if (std::isalpha(ch)) {
            int x = std::tolower(ch) - 'a';
            out += char('a' + mod(a * x + b, m));
        } else if (std::isdigit(ch)) {
            out += ch;
        }
    }
    for (int i = 5; i < (int)out.size(); i += 6) {
        out.insert(out.begin() + i, ' ');
    }
    return out;
}

std::string decode(const std::string& text, int a, int b) {
    const int m = 26;
    if (gcd(a, m) != 1) throw std::invalid_argument("a and m must be coprime.");
    int inv = modinv(a, m);
    std::string out;
    out.reserve(text.size());
    for (char ch : text) {
        if (std::isalpha(ch)) {
            int y = std::tolower(ch) - 'a';
            out += char('a' + mod(inv * (y - b), m));
        } else if (std::isdigit(ch)) {
            out += ch;
        }
    }
    return out;
}

}  // namespace affine_cipher