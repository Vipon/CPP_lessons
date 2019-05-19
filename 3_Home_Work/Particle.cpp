#include "Particle.h"
#include <cstring>

Particle::Particle(double ms, int ec, int sp, int ip)
{
	mass = ms;
	el_ch = ec;
	spin = sp;
	izospin = ip;
}

Particle::Particle()
{
	mass = 0;
	el_ch = 0;
	spin = 0;
	izospin = 0;
}

Particle::Particle(const Particle& p) 

{
	mass = p.mass;
	el_ch = p.el_ch;
	spin = p.spin;
	izospin = p.izospin;

}


Particle::~Particle()
{
	delete  &mass;
	delete  &el_ch;
	delete  &spin;
	delete  &izospin;
}


Particle& Particle::operator+(const Particle& p) 
{
	//Particle Sum;

	mass = mass + p.mass;
	el_ch = el_ch + p.el_ch;
	spin = spin + p.spin;
	izospin = izospin + p.izospin;

	return *this;

} 

Particle& Particle::operator-(const Particle& p)
{
	mass = mass - p.mass;
	el_ch = el_ch - p.el_ch;
	spin = spin - p.spin;
	izospin = izospin - p.izospin;

	return *this;
}

std::ostream& operator<<(std::ostream& out, const Particle& p)
{
	out << "mass " << p.mass<<'\n';
	out << "electrical charge " << p.el_ch<<'\n';
	out << "spin " << p.spin<< '\n';
	out << "izospin " << p.izospin<<'\n';

	return out;
}

std::istream& operator>>(std::istream& in, Particle& p)
{

	in >> p.mass;
	in >> p.el_ch;
	in >> p.spin;
	in >> p.izospin;

	return in;

}