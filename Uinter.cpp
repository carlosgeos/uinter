/*
  Nom: Requena López
  Prénom: Carlos
  Section: INFO1

  Projet C++
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
  };
  _Inter* _tete;		// pointer to the first interval
public:
  Uinter();
  void reunion(int bi, int bs);
  void printUinter();
  bool contient(int nb);
};

// Constructors

Uinter::Uinter() {
  //  std::cout << "Yeahhh, a is: " << a << " and b is: " << b << std::endl;
  std::cout << "this is the Uinter constructor!" << std::endl;
  _tete = new _Inter(4,8);
  std::cout << _tete -> getbs() << std::endl;
  std::cout << "About to apply a change to bs, becomes" << std::endl;
  _tete -> setbs(10);
  std::cout << _tete -> getbs() << std::endl;
  std::cout << "after" << std::endl;
  std::cout << this << std::endl;
}

Uinter::_Inter::_Inter(int a, int b, _Inter* next) {
  std::cout << "----------------------------------------------" << std::endl;
  std::cout << "This is the _Inter constructor" << std::endl;
  _bi = a;
  std::cout << "_bi is: " << _bi << std::endl;
  _bs = b;
  std::cout << "_bs is: " << _bs << std::endl;
  _next = next;
  std::cout << "_next is: " << _next << std::endl;
  std::cout << "----------------------------------------------" << std::endl;
}

// Uinter member functions


void reunion() {
  
}


void Uinter::printUinter() {
  std::cout << "-------------Uinter information---------------" << std::endl;
  std::cout << "Location in memory: " << this << std::endl;
  std::cout << "Interval(s): " << "[" << _tete -> getbi() << ", " << _tete -> getbs() << "]" << std::endl;
  std::cout << "----------------------------------------------" << std::endl;
}


bool Uinter::contient(int a) {
  if(a > _tete -> getbi() and a < _tete -> getbs()) {
    return true;
  } else {
    return false;
  }
}


int main() {
  Uinter interval;
  interval.contient(5);
  interval.printUinter();
  return 0;
}
