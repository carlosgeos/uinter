/*
  Nom: Requena López
  Prénom: Carlos
  Section: INFO1

  Projet 1 : C++
 */

#include <cstdlib>
#include <cstddef>
#include <iostream>

class Uinter {
  class _Inter {
    int _bi, _bs;		// lower and upper bound
    _Inter *_next;		// pointer to next interval
  public:
    _Inter(int a, int b, _Inter* next=nullptr): _bi(a), _bs(b), _next(next){};
    void setbi(int a) {_bi = a;};
    void setbs(int b) {_bs = b;};
    void setnext(_Inter* next) {_next = next;};
    int getbi() const {return _bi;};
    int getbs() const {return _bs;};
    _Inter* getnext() const {return _next;};
  };
  _Inter* _tete;		// pointer to the first interval
public:
  Uinter(): _tete(new _Inter(1, 3)) {}; // first interval to test
  void reunion(int bi, int bs);
  void printUinter();
  bool contient(int nb);
  _Inter* gettete() {return _tete;};
};


// Uinter member functions

// void reunion(int new_bi, int new_bs) {
//   void();0;
// }


void Uinter::printUinter() {
  std::cout << "-------------Uinter information---------------" << std::endl;
  std::cout << "Location in memory: " << this << std::endl;
  std::cout << "Interval(s): " << "[" << _tete -> getbi() << ", " << _tete -> getbs() << "]" << std::endl;
  std::cout << "----------------------------------------------" << std::endl;
}


bool Uinter::contient(int nb) {
  _Inter* pointer = _tete;
  std::cout << "The number to check is: " << nb << std::endl;

  bool go = true;
  bool res = false;
  // if number is found, exit loop before
  while (go) {
    if (nb >= pointer -> getbi() and nb <= pointer -> getbs()) {
      std::cout << "The number IS in the interval" << std::endl;
      go = false;
      res = true;
    } else if (pointer -> getnext() != nullptr) {
      std::cout << "Going to next interval" << std::endl;
      pointer = pointer -> getnext();
    } else {
      std::cout << "The number IS NOT in the interval" << std::endl;
      go = false;
    }
  }
  return res;
}


int main() {
  Uinter interval;
  interval.contient(5);
  interval.printUinter();
  return 0;
}
