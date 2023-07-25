#include <iostream>
#include <string>
#include <thread>
#include <vector>

using namespace std;

void fizBuz(const vector<string> &names);
// void fizBuz(const vector<string> &names, int times); will not work, there is
// no overload of functions

int main() {
  vector<string> names{"Abdul", "Brat", "Claudia", "Dave"};
  // std::ref(), std::cref for passing reference or constant reference
  thread tr(fizBuz, std::cref(names));
  tr.join();

  return 0;
}

void fizBuz(const vector<string> &names) {
  for (int num = 1; num <= 30; num++) {
    cout << names[(num - 1) % 4] << " say ";

    if (num % 3 == 0 && num % 5 == 0) {
      cout << "fizzbuzz!";
    } else if (num % 3 == 0) {
      cout << "fizz!";
    } else if (num % 5 == 0) {
      cout << "buzz!";
    } else {
      cout << num;
    }
    std::cout << "\n";
  }
}

// void fizBuz(const vector<string> &names, int times)
// {
//   for (int num = 1; num <= times; num++) {
//     cout << names[(num -1) % 4] << " say ";

//     if (num % 3 == 0 && num % 5 == 0) {
//       cout << "fizzbuzz!";
//     } else if (num % 3 == 0) {
//       cout << "fizz!";
//     } else if (num % 5 == 0) {
//       cout << "buzz!";
//     } else {
//       cout << num;
//     }
//     std::cout << "\n";
//   }
// }
