/*
 * Vektor.h
 *
 *  Created on: 08.11.2023
 *      Author: User
 */

#ifndef VEKTOR_H_
#define VEKTOR_H_
#include <memory>
using namespace std;

class Vektor {

private:

int vsize;
unique_ptr<double[]> daten;





public:
	Vektor();
	virtual ~Vektor();
	Vektor(int size);
	Vektor(const Vektor &o);
	Vektor(Vektor &&o);
	Vektor& operator=(const Vektor &o);
	Vektor& operator=(Vektor &&o);
	Vektor& plusGleich(const Vektor& v);
	int getSize()const;
	double getAt(int index);
	void setAt(int index,double wert);
	void print();
	Vektor add(const Vektor& v1, const Vektor& v2);


};

#endif /* VEKTOR_H_ */
