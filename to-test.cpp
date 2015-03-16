#include "Uinter.hpp"

int main(){
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




}
