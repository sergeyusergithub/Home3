#include "all_classes.hpp"
#include <iostream>


int main() {

	const int h_size = 10;
	Human hm[h_size]{};
	hm[0] = {"Bob","Tompson","Male","Father",35};
	hm[1] = { "Mark","Twen","Male","Son",61 };
	hm[2] = { "Klear","Pops","Female","Mother",40 };
	hm[3] = { "Emely","Casper","Female","Dougther",15 };
	hm[4] = { "Peter","Volos","Male","Son",5 };
	hm[5] = { "Mary","Volos","Female","Mother",24 };
	hm[6] = { "Sofy","Global","Female","Dougther",31 };
	hm[7] = { "Pipe","Global","Male","Father",65 };
	hm[8] = { "Cate","Global","Female","Mother",62 };
	hm[9] = { "Stive","Truth","Male","Son",22 };

	const int fl_size = 10;

	Flat fl[fl_size];

	fl[0] = {&hm[0],1,44.5,2,1,1};
	fl[1] = { &hm[1],1,33.5,1,2,1 };
	fl[2] = { &hm[2],1,75.5,3,3,1 };
	fl[3] = { &hm[3],1,47.5,2,4,2 };
	fl[4] = { &hm[4],2,66.5,2,5,2 };
	fl[5] = { &hm[6],3,99.5,4,6,2 };
	fl[6] = { &hm[9],1,22.5,1,7,3 };
	










	House ho;


	House ho1;







	return 0;
}