#include "hello_world.h"

// Use everything from the 'std' namespace.
// This lets us write 'string' instead of 'std::string'.
using namespace std;

namespace hello_world {

// Define the function itself. This could have also been written as:
// std::string hello_world::hello()
string hello() {
    // Return the string we need.
    return "Fix me!";
}

}  // namespace hello_world
