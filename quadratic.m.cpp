#include <iostream>
#include <cmath>

using std::cout;
using std::cerr;
using std::cin;
using std::sqrt;
using std::abs;


// Parse quadractic equation parameters from stdin, a return value of true 
// indicates that doubles were successfully read.
bool readParams(double& a, double& b, double& c) 
{
  cout << "Please enter a, b and c (as in a*x^2 + b*x + c = 0) seperated by"
          " whitespace: ";
  a = 0;
  b = 0;
  c = 0;
  if(!(cin >> a) || !(cin >> b) || !(cin >> c)) {
    cerr << "Could not read double value from stdin\n";
    return false;
  }
  return true;
}

// Solve quadratic equation given the parameters of the equation and print 
// the result to stdin.
void solveQuadratic(double a, double b, double c)
{
  // Calculate the discriminant.
  double disc = b * b - 4 * a * c;

  // Calculate the roots of the equation.
  double x1 = (-b + sqrt(disc) ) / (2.0 * a);
  double x2 = (-b - sqrt(disc) ) / (2.0 * a);

  if(disc < 0) {
    // Seperate into real and imaginary parts
    double real = -b / (2.0 * a);
    double im = sqrt( abs(disc) ) / (2.0 * a);

    cout << "x1: " << real << " + " << im << "i\n";
    cout << "x2: " << real << " - " << im << "i\n";
  } else {
    cout << "x1: " << x1 << '\n';
    cout << "x2: " << x2 << '\n';
  }
}

int main()
{
  double a, b, c;
  if(readParams(a, b, c)) {
    solveQuadratic(a, b, c);
  }

  return 0; 
}
