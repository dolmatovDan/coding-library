#include <iostream>
using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  int res = gcd(10, 5);
  cout << res;
  return 0;
}
