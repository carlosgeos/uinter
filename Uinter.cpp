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
    _Inter(int a, int b, _Inter* next=nullptr);
    void setbi(int a) {_bi = a;};
    void setbs(int b) {_bs = b;};
    void setnext(_Inter* next) {_next = next;};
    int getbi() const {return _bi;};
    int getbs() const {return _bs;};
    _Inter* getnext() const {return _next;};
    void checkBoundaries(int new_bi, int new_bs);
  };
  _Inter* _tete;		// pointer to the first interval
public:
  Uinter(): _tete(new _Inter(3, 7, new _Inter(20, 40))) {}; // first interval to test
  void reunion(int new_bi, int new_bs);
  void printUinter();
  bool contient(int nb);
};

// _Inter constructor

Uinter::_Inter::_Inter(int a, int b, _Inter* next) {
  std::cout << "Inter being constructed" << std::endl;
  checkBoundaries(a, b);
  _bi = a;
  _bs = b;
  _next = next;
}

// _Inter member functions

void Uinter::_Inter::checkBoundaries(int new_bi, int new_bs) {
  if (new_bs < new_bi) {
    std::cout << "Failed to create _Inter instance. Not a valid interval. Exiting" << std::endl;
    std::exit(0);
  }

}

// Uinter constructor

// Uinter member functions

void Uinter::reunion(int new_bi, int new_bs) {
  // if boundary in common: modify instance of _Inter
  if (contient(new_bi) and contient(new_bs)) {
    std::cout << "scam interval!" << std::endl;
  } else if (not contient(new_bi) and not contient(new_bs)) {
    std::cout << "new interval!!" << std::endl;
    _tete -> setnext(new _Inter(new_bi, new_bs));
  }
  // if nothing in common: create new instance
}


void Uinter::printUinter() {
  std::cout << "-------------Uinter information---------------" << std::endl;
  std::cout << "Location in memory: " << _tete << std::endl;
  std::cout << "Interval(s)       : ";
  _Inter* pointer = _tete;
  do {
    std::cout << "[" << pointer -> getbi() << ", " << pointer -> getbs() << "] ";
    pointer = pointer -> getnext();
  } while (pointer != nullptr);
  std::cout << std::endl;
  std::cout << "----------------------------------------------" << std::endl;
}

bool Uinter::contient(int nb) {
  _Inter* pointer = _tete;

  bool go = true;
  bool res = false;
  // if number is found, exit loop before
  while (go) {
    if (nb >= pointer -> getbi() and nb <= pointer -> getbs()) {
      std::cout << "The number " << nb << " IS in the interval" << std::endl;
      go = false;
      res = true;
    } else if (pointer -> getnext() != nullptr) {
      pointer = pointer -> getnext();
    } else {
      std::cout << "The number " << nb << " IS NOT in the interval" << std::endl;
      go = false;
    }
  }
  return res;
}


int main() {
  Uinter interval;

  interval.contient(15);
  interval.printUinter();
  return 0;
}
