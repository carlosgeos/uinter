/*
  Nom: Requena López
  Prénom: Carlos
  Section: INFO1

  INFO-F-105
  Projet 1 : C++
 */

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
  Uinter(): _tete() {};
  void reunion(int new_bi, int new_bs);
  void reunion(int new_bi, int new_bs, _Inter* pointer);
  void set_interval_bs(int new_bs, _Inter* pointer);
  void printUinter();
  bool contient(int nb);
};

// =============== _Inter constructor ===============

Uinter::_Inter::_Inter(int a, int b, _Inter* next) : _bi(a),
						     _bs(b),
						     _next(next)
{
  /* Constructor with initialization list. Also checks for valid
     boundaries
  */
  checkBoundaries(a, b);
}

// =============== _Inter member functions ===============

void Uinter::_Inter::checkBoundaries(int new_bi, int new_bs) {
  if (new_bs < new_bi) {
    std::cout << "Failed to create _Inter instance. "
      "Not a valid interval. Exiting" << std::endl;
    std::exit(0);
  }
}

// =============== Uinter member functions ===============

void::Uinter::reunion(int new_bi, int new_bs) {
  /* This overload has access to the _tete attribute. It is executed
     when reunion is called with only 2 parameters (user).

     Note: a non-static data member cannot be a default argument for a
     method
  */
  std::cout << "Applying reunion with interval: [" << new_bi
	    << ", " << new_bs << "]" << std::endl;
  reunion(new_bi, new_bs, _tete);
}

void Uinter::reunion(int new_bi, int new_bs, _Inter* pointer) {
  /* Possible patterns (match entries in if statements):

     - The interval is empty

     - The new lower bound is lower than the actual lower bound
         - The upper bound as well -> create new _Inter below
	 - Otherwise -> adjust lower bound and upper bound

     - The new lower bound is contained in the actual interval
         - The upper bound as well -> do nothing
	 - Otherwise -> simply set the upper bound

     - If reached the end, means interval is bigger and new _Inter
       is created at the end

     - The new interval is contained between the actual interval
       and the next -> insert new _Inter there

     - None of these -> iterate through the list
  */

  pointer -> checkBoundaries(new_bi, new_bs);

  if (pointer == nullptr) {
    _tete = new _Inter(new_bi, new_bs);
  } else if (new_bi < pointer -> getbi()) {
    if (new_bs < pointer -> getbi()) {
      _Inter* next_inter = pointer;
      _tete = new _Inter(new_bi, new_bs, next_inter);
    } else if (new_bs >= pointer -> getbi()) {
      pointer -> setbi(new_bi);
      set_interval_bs(new_bs, pointer);
    }
  } else if (new_bi >= pointer -> getbi() and
	     new_bi <= pointer -> getbs()) {
    if (new_bs <= pointer -> getbs()) {
      ;
    } else {
      set_interval_bs(new_bs, pointer);
    }
  } else if (pointer -> getnext() == nullptr) {
    pointer -> setnext(new _Inter(new_bi, new_bs));
  } else if (new_bi < pointer -> getnext() -> getbi() and
	     new_bs < pointer -> getnext() -> getbi()) {
    _Inter* next_inter = pointer -> getnext();
    pointer -> setnext(new _Inter(new_bi, new_bs, next_inter));
  } else {
    reunion(new_bi, new_bs, pointer -> getnext());
  }
}

void Uinter::set_interval_bs(int new_bs, _Inter* pointer) {
  /* Sets the upper bound for the given interval and adjusts the next
     pointer accordingly. It also deletes the unused intervals.
  */

  bool bs_inside = contient(new_bs);
  _Inter* jumped;

  if (bs_inside and new_bs > pointer -> getbs()) {
    do {
      jumped = pointer -> getnext();
      pointer -> setbs(jumped -> getbs());
      pointer -> setnext(jumped -> getnext());
      delete jumped;
    } while (new_bs > pointer -> getbs());
  } else if (not bs_inside) {
    pointer -> setbs(new_bs);
    while (pointer -> getnext() != nullptr and
	   pointer -> getnext() -> getbi() < new_bs) {
      jumped = pointer -> getnext();
      pointer -> setnext(jumped -> getnext());
      delete jumped;
    }
  }
}

void Uinter::printUinter() {
  std::cout << "|------------Uinter information-------------" << std::endl;
  std::cout << "| Empty interval?    : ";
  if (_tete == nullptr) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
  std::cout << "| Interval(s)        : ";
  _Inter* pointer = _tete;
  _Inter* last = pointer;
  while (pointer != nullptr) {
    std::cout << "[" << pointer -> getbi() << ", "
	      << pointer -> getbs() << "] ";
    last = pointer;
    pointer = pointer -> getnext();
  }
  std::cout << std::endl;
  std::cout << "| Location in memory : " << _tete
	    << " to " << last << std::endl;
  std::cout << "|-------------------------------------------"
	    << std::endl << std::endl;
}

bool Uinter::contient(int nb) {
  /* Iterate over the list, checking if nb is in one of the
     intervals. If it is, return true, false otherwise.
  */
  _Inter* pointer = _tete;

  bool go = true;		// if number is found, exit loop
  bool res = false;		// bool to return

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

int main() {
  Uinter interval;
  interval.printUinter();

  int bis[] = {5, 10, 22, 12, 0, 10, 7, 7, 3, 100, 140, -1, -100};
  int bss[] = {8, 15, 30, 23, 0, 25, 7, 9, 5, 150, 170,  0, 1000};
  int len = sizeof(bis) / sizeof(bis[0]);

  for (int i = 0; i < len; ++i) {
    interval.reunion(bis[i], bss[i]);
    interval.printUinter();
  }

  return 0;
}
