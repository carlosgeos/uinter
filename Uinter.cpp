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
  Uinter(): _tete() {}; // first interval(s) to test
  void reunion(int new_bi, int new_bs);
  void reunion(int new_bi, int new_bs, _Inter* pointer);
  void set_interval_bs(int new_bs, _Inter* pointer);
  void printUinter();
  bool contient(int nb);
};

// _Inter constructor

Uinter::_Inter::_Inter(int a, int b, _Inter* next) {
  // check for valid boundaries before constructing the object
  checkBoundaries(a, b);
  _bi = a;
  _bs = b;
  _next = next;
}

// _Inter member functions

void Uinter::_Inter::checkBoundaries(int new_bi, int new_bs) {
  if (new_bs < new_bi) {
    std::cout << "Failed to create _Inter instance. "
      "Not a valid interval. Exiting" << std::endl;
    std::exit(0);
  }
}

// Uinter member functions

void::Uinter::reunion(int new_bi, int new_bs) {
  // this overload has access to the _tete attribute. it is executed
  // when reunion is called with only 2 parameters

  // reason: a non-static data member cannot be a default argument for
  // a method

  reunion(new_bi, new_bs, _tete);
}

void Uinter::reunion(int new_bi, int new_bs, _Inter* pointer) {
  pointer -> checkBoundaries(new_bi, new_bs);
  std::cout << "Applying reunion with interval: [" << new_bi
	    << ", " << new_bs << "]" << std::endl;

  if (pointer == nullptr) {
    _tete = new _Inter(new_bi, new_bs);
  } else if (pointer -> getbi() < new_bi and new_bi < pointer -> getbs()) {
    set_interval_bs(new_bs, pointer);
  } else if (new_bi < pointer -> getbi() and new_bs < pointer -> getbi()) {
    _Inter* next_inter = pointer;
    _tete = new _Inter(new_bi, new_bs, next_inter);
  } else if (new_bi < pointer -> getbi() and new_bs >= pointer -> getbi()) {
    pointer -> setbi(new_bi);
    set_interval_bs(new_bs, pointer);
  } else if (pointer -> getnext() == nullptr) {
    pointer -> setnext(new _Inter(new_bi, new_bs));
  } else {
    // if it does not match any pattern, take a step forward in the
    // list
    reunion(new_bi, new_bs, pointer -> getnext());
  }
}

void Uinter::set_interval_bs(int new_bs, _Inter* pointer) {
  // sets the upper bound for the given interval and adjusts the next
  // pointer accordingly
  bool bs_inside = contient(new_bs);

  if (bs_inside and new_bs > pointer -> getbs()) {
    do {
      pointer -> setbs(pointer -> getnext() -> getbs());
      pointer -> setnext(pointer -> getnext() -> getnext());
    } while (new_bs > pointer -> getnext() -> getbs());
  } else if (not bs_inside) {
    printUinter();
    pointer -> setbs(new_bs);
    while (pointer -> getnext() != nullptr and pointer -> getnext() -> getbi() < new_bs) {
      pointer -> setnext(pointer -> getnext() -> getnext());
    }
  }
}


void Uinter::printUinter() {
  std::cout << "-------------Uinter information---------------" << std::endl;
  std::cout << "Location in memory: " << _tete << std::endl;
  std::cout << "Empty interval?   : ";
  if (_tete == nullptr) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
  std::cout << "Interval(s)       : ";
  _Inter* pointer = _tete;
  while (pointer != nullptr) {
    std::cout << "[" << pointer -> getbi() << ", " << pointer -> getbs() << "] ";
    pointer = pointer -> getnext();
  }
  std::cout << std::endl;
  std::cout << "----------------------------------------------" << std::endl;
}

bool Uinter::contient(int nb) {
  // iterate over the list, checking if nb is in one of the intervals
  _Inter* pointer = _tete;

  bool go = true;
  bool res = false;
  // if number is found, exit loop before
  while (go) {
    if (nb >= pointer -> getbi() and nb <= pointer -> getbs()) {
      go = false;
      res = true;
    } else if (pointer -> getnext() != nullptr) {
      pointer = pointer -> getnext();
    } else {
      go = false;
    }
  }
  return res;
}

//--------------------- Main --------------------------
int main() {
  Uinter a, b, c, d, e, f,g;
  a.reunion(5,10);
  a.reunion(6,15);
  a.reunion(-5,0);
  a.reunion(100,300);
  a.reunion(1,1);
  a.printUinter();

  b.reunion(0,0);
  b.reunion(6,9);
  b.reunion(-35,-22);
  b.reunion(2,6);
  b.reunion(4,50);
  b.reunion(4,8);
  b.reunion(2,4);
  b.reunion(15,17);
  b.reunion(23,30);
  b.reunion(-2,16);
  b.printUinter();

  c.reunion(1,3);
  c.reunion(5,9);
  c.reunion(0,0);
  c.reunion(-1,-1);
  c.reunion(6,10);
  c.reunion(3,4);
  c.printUinter();

  d.reunion(30,564);
  d.reunion(20,654);
  d.reunion(10,1237879);
  d.reunion(-5,0);
  d.reunion(3,12);
  d.reunion(4567,123657);
  d.printUinter();

  e.reunion(-5,0);
  e.reunion(-6,9);
  e.reunion(-6,13);
  e.reunion(-6,45);
  e.reunion(-6,0);
  e.printUinter();

  f.reunion(1,1);
  f.reunion(1,1);
  f.reunion(1,1);
  f.reunion(2,2);
  f.reunion(2,2);
  f.printUinter();

  g.reunion(0,2);
  g.reunion(4,8);
  g.reunion(0,5);
  g.reunion(100,4000);
  g.printUinter();

  return 0;


  // Uinter interval;
  // std::cout << "Given interval:" << std::endl;
  // interval.printUinter();
  // interval.reunion(4, 5);
  // std::cout << "After modification" << std::endl;
  // interval.printUinter();
  // return 0;
}
