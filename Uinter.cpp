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
  Uinter(): _tete(new _Inter(3, 7, new _Inter(20, 40, new _Inter(43, 46, new _Inter(50, 60))))) {}; // first interval to test
  void reunion(int new_bi, int new_bs);
  void reunion(int new_bi, int new_bs, _Inter* pointer);
  void printUinter();
  bool contient(int nb);
};

// _Inter constructor

Uinter::_Inter::_Inter(int a, int b, _Inter* next) {
  //std::cout << "Inter being constructed" << std::endl;
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

void::Uinter::reunion(int new_bi, int new_bs) {
  // this overload has access to the _tete attribute. it is executed
  // when reunion is called with only 2 parameters

  // reason: a non-static data member cannot be a default argument for
  // a method
  reunion(new_bi, new_bs, _tete);
}

void Uinter::reunion(int new_bi, int new_bs, _Inter* pointer) {
  std::cout << "3 arguments called" << std::endl;
  // if boundary in common: modify instance of _Inter
  // checkBoundaries needs to be done now!! Otherwise reunion code doesnt work
  std::cout << "reunion with: " << new_bi << " and " << new_bs << std::endl;

  int bi;
  int bs;
  int next_bi;
  int next_bs;
  _Inter* next_inter;
  bool go = true;

  bool bi_inside = contient(new_bi);
  bool bs_inside = contient(new_bs);

  bi = pointer -> getbi();
  next_bi = pointer -> getnext() -> getbi();
  bs = pointer -> getbs();
  next_bs = pointer -> getnext() -> getbs();
  next_inter = pointer -> getnext() -> getnext();

  if (bi_inside) {
    std::cout << "should be seen" << std::endl;
    if (bi < new_bi and new_bi < bs) {
      if (new_bs > bs) {
	pointer -> setbs(new_bs);
      }
      printUinter();
      while (pointer -> getnext() -> getbs() < new_bs) {
	std::cout << "veces" << std::endl;
	pointer -> setnext(pointer -> getnext() -> getnext());
	std::cout << "final" << std::endl;
      }
      if (bs_inside and new_bs > bs) {
	pointer -> setbs(pointer -> getnext() -> getbs());
	pointer -> setnext(pointer -> getnext() -> getnext());
      }
    } else {
      // take a step forward in the list
      reunion(new_bi, new_bs, pointer -> getnext());
    }
  } else if (not bi_inside) {
    if (new_bi < bi) {
      pointer -> setbi(new_bi);
    }
    while (new_bs > bs) {
      pointer -> setbs(next_bs);
      pointer -> setnext(next_inter);
    }
  } else if (bi_inside and bs_inside) {
    std::cout << "yeahh" << std::endl;
  } else {
    std::cout << "yeahh" << std::endl;
  }
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
      //std::cout << "The number " << nb << " IS in the interval" << std::endl;
      go = false;
      res = true;
    } else if (pointer -> getnext() != nullptr) {
      pointer = pointer -> getnext();
    } else {
      //std::cout << "The number " << nb << " IS NOT in the interval" << std::endl;
      go = false;
    }
  }
  return res;
}

//--------------------- Main --------------------------
int main() {
  Uinter interval;

  std::cout << "BEFORE:" << std::endl;
  interval.printUinter();
  interval.reunion(25, 35);
  std::cout << "AFTER" << std::endl;
  interval.printUinter();
  return 0;
}
