/*
  Nom: Requena López
  Prénom: Carlos
  Section: INFO1

  Projet C++
 */

#include <cstdlib>
#include <cstddef>
#include <iostream>

// this is a comment underneath the includes
// extra

class Uinter {
private:
  class _Inter {
  private:
    int _bi, _bs;		// lower and upper bound
    _Inter *_next;		// pointer to next interval
  public:
    _Inter(int a, int b, _Inter* next=nullptr);
    void setbi(int a);
    void setbs(int b);
    int getbi() const {return _bi;};
    int getbs() const {return _bs;};
  };
  _Inter* _tete;		// pointer to the first interval
public:
  Uinter();
  void reunion(int bi, int bs);
  void printUinter();
  bool contient(int nb);
  _Inter* gettete() const {return _tete;};
};

// Constructors

Uinter::Uinter() {
  //  std::cout << "Yeahhh, a is: " << a << " and b is: " << b << std::endl;
  std::cout << "this is the Uinter constructor!" << std::endl;
  _Inter mySegment(4, 8);
  _Inter* _tete;
  _tete = &mySegment;
  std::cout << _tete -> getbs() << std::endl;
  std::cout << "About to apply a change to bs" << std::endl;
  _tete -> setbs(10);
  std::cout << _tete -> getbs() << std::endl;
  std::cout << "after" << std::endl;
}

Uinter::_Inter::_Inter(int a, int b, _Inter* next) {
  std::cout << "This is the _Inter constructor" << std::endl;
  _bi = a;
  std::cout << "_bi is: " << _bi << std::endl;
  _bs = b;
  std::cout << "_bs is: " << _bs << std::endl;
  _next = next;
  std::cout << "_next is: " << _next << std::endl;
}

// _Inter Member functions

void Uinter::_Inter::setbi(int a) {
  _bi = a;
}

void Uinter::_Inter::setbs(int b) {
  _bs = b;
}

// Uinter member functions

bool Uinter::contient(int a) {
  if(a > _tete -> getbi() and a < gettete() -> getbs()) {
    std::cout << "trueeeee" << std::endl;
    return true;
  }
  else {
    std::cout << "falseeee" << std::endl;
    return false;
  }
}


void Uinter::printUinter() {
  //  std::cout << _tete << std::endl;
  std::cout << gettete() -> getbs() << std::endl;
}

int main() {
  Uinter interval;
  std::cout << "just before printing the bas stuff" << std::endl;
  //  interval.printUinter();
  return 0;
}
