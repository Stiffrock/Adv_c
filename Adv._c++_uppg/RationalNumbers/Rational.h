#pragma once
#include <iostream>
#include "GCD.h"
#include "RelOps.h"

template <typename Tint> class Rational
{
public:
	Tint nom, denom;
	//template<typename T>
	friend std::ostream& operator<< (std::ostream &cout, Rational<Tint>& R) 
	{
		cout << R.nom << '/' << R.denom;
		return cout;
	}

	//template<typename T>
	friend std::istream& operator>> (std::istream &cin, Rational<Tint>& R) 
	{
		char sne;
		cin >> R.nom >> sne >> R.denom;
		return cin;
	}


	template<typename T>
	Rational(Rational<T> t) : nom(t.nom), denom(t.denom) {};
	Rational() : nom(0), denom(1) {};
	Rational(Tint P) : nom(P), denom(1) {};
	Rational(Rational<Tint> &R) : nom(R.nom), denom(R.denom) {};

	Rational(Tint P, Tint Q) : nom(P), denom(Q) {
		Reduce(nom, denom);
	}
	template <typename T>
	bool operator==(const Rational<T> rhs) {
		return ((nom / denom) == (rhs.nom / rhs.denom));
	};
	template <typename T>
	bool operator==(const T rhs) { 

		return ((nom/denom) == (rhs)); 
	};

	Rational& operator+= (const Rational rhs) 
	{
		this->nom = (nom * rhs.denom + rhs.nom * denom);
		this->denom = (denom * rhs.denom);
		return *this;
	};

	Rational operator+(const Rational rhs)
	{
		Rational temp;
		temp.nom = (nom * rhs.denom + rhs.nom * denom);
		temp.denom = (denom * rhs.denom);
		return temp;
	};
	Rational& operator-()
	{
		nom = -nom;
		return *this;
	}

	explicit operator long long() { return (long long)nom / denom; }
	explicit operator short() { return (short)nom / denom; }
	explicit operator int() { return (int)nom / denom; }

	Rational& operator++() { nom =+ denom; return *this; };
	Rational operator++(int) { Rational temp(nom / denom); nom += denom; return temp; };



	
	~Rational() {};
};
