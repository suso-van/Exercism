#include "triangle.h"
#include <stdexcept>

namespace triangle {

flavor kind(double a, double b, double c) {
    // A valid triangle must have all sides greater than 0
    if (a <= 0 || b <= 0 || c <= 0) {
        throw std::domain_error("Sides must be strictly positive.");
    }

    // The sum of the lengths of any two sides must be strictly greater than the third
    if (a + b <= c || a + c <= b || b + c <= a) {
        throw std::domain_error("Violates triangle inequality theorem.");
    }

    // Determine the type of triangle
    if (a == b && b == c) {
        return flavor::equilateral;
    } 
    
    if (a == b || b == c || a == c) {
        return flavor::isosceles;
    }
    
    return flavor::scalene;
}

}  // namespace triangle