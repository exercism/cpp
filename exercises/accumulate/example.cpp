#include "accumulate.h"
#include <vector>

namespace accumulate {
// A helper function that implements binary search to help find the square root
int root(int n){
  int lo = 0, hi = n, mid;
  for(int i = 0 ; i < 1000 ; i++){
      mid = (lo + hi) / 2;
      if(mid * mid == n) return mid;
      if(mid * mid > n) hi = mid;
      else lo = mid;
  }
  return mid;
}

// A helper function that implements the factorial computation
// This is implemented tail recursively

// A tail recursive function to calculate factorial 
int factorial(int n, int a) 
{ 
    if (n == 0) return a; 
  
    return factTR(n-1, n*a); 
} 
  
// A wrapper over factorial 
int factorial_wrapper(int n) 
{ 
   return factorial(n, 1); 
} 

vector<int> accumulate(const vector<int> &collection, const string operation, vector<int> &output) {
    if (operation == "square") {
        for (size_t i = 0; i < collection.size(); ++i) {
            output.push_back(collection[i] * collection[i]);
        }
    }
    else if (operation == "cube") {
        for (size_t i = 0; i < collection.size(); ++i) {
            output.push_back(collection[i] * collection[i] * collection[i]);
        }
    }
    else if (operation == "square root") {
        for (size_t i = 0; i < collection.size(); ++i) {
            output.push_back(root(collection[i]));
        }
    }
    else if (operation == "factorial") {
        for (size_t i = 0; i < collection.size(); ++i) {
            output.push_back(factorial_wrapper(collection[i]));
        }
    }
    return output;
}
} // namespace accumulate