#ifndef __PARTICLE_H
#define __PARTICLE_H


#include <cstddef>
#include <iostream>

class Particle {
public:
	Particle(double ms, int ec, int sp, int ip); 
	Particle();
	Particle(const Particle& p);
	~Particle();

//	Particle& 				operator-(const Particle& p);
//	Particle& 				operator+(const Particle& p);
	Particle&		operator+(const Particle& p) ;
	Particle&				operator-(const Particle& p);
	friend std::ostream& 	operator<< (std::ostream& os, const Particle& p);
	friend std::istream& 	operator>> (std::istream& is, Particle& p);
private:
	double mass;
	int el_ch;
	int spin;
	int izospin; 	
};


/*
Particle Alx(0.38, 1, 0, -1); 
Particle Aln(1.83, 0, -1, 1);
Particle Oni(21.5, -1, 1, 0);
Particle Vic(137.01, 1, 0, -1);
Particle Pro(512.8, -1, -1, 1);
Particle Cen(1328.54, 0, 1, 0);
Particle Tan(15.9, 1, 0, -1);
Particle Qad(147.12, 0, -1, 1);
Particle Pho(284.18, -1, 1, 0);
Particle Fei(9759.17, 1, 0, -1);
Particle Ele(0, 1, 0, 0);
Particle Spi(0, 0, 1, 0);
Particle Izo(0, 0, 0, 1);
Particle Pel(137.20, 0, 0, 0);
*/
#endif //__PARTICLE_H