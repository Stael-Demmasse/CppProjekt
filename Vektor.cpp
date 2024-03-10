/*
 * Vektor.cpp
 *
 *  Created on: 08.11.2023
 *      Author: User
 */

#include "Vektor.h"
#include<iostream>
#include<memory>
using namespace std;
#include<String>

 //standart konstrukteur

Vektor::Vektor() {

  this->vsize =4;
  this->daten = make_unique<double[]>(4);

}

//destruktor

Vektor::~Vektor() {
	// TODO Auto-generated destructor stub
}

//konstruktor mit parameter size

Vektor::Vektor(int size) {

  this->vsize =4;
  this->daten = make_unique<double[]>(size);

}


//copy-konstruktor

Vektor::Vektor(const Vektor &o) {

	vsize = o.vsize;

	daten = make_unique<double[]>(vsize);

	for(int i=0; i<vsize; i++)
	{

		daten[i]=o.daten[i];
	}


}

//verschiebe konstruktor

Vektor::Vektor(Vektor &&o) {


	vsize=o.vsize;
	daten =move(o.daten);
	o.vsize=0;

}

//zuveisung operator

Vektor& Vektor::operator=(const Vektor &o) {


	if(this == &o){

		return *this;

	}

	vsize = o.vsize;
	daten = make_unique<double[]>(o.vsize);


	 for(int i=0;i<vsize;i++)
	 {
		 daten[i]=o.daten[i];
	 }
	 return *this;



}

//verschiebe zuweisung
Vektor& Vektor::operator=(Vektor &&o) {

	if(this == &o){

		return *this;
	}

	vsize = o.vsize;
	daten = move(o.daten);
	o.vsize = 0;
	return *this;



}


Vektor& Vektor::plusGleich(const Vektor& v){

	int newSize=max(vsize, v.vsize);

		unique_ptr<double[]>newData = make_unique<double[]>(newSize);


		for(int i=0;i<newSize;i++)
		{
			double value1;
			if(i<vsize)
			{
				value1=daten[i];
			}
			else
			{
				value1=0.0;
			}
			double value2;
			if(i<v.vsize)
			{
				value2=v.daten[i];
			}
			else
			{
				value2=0.0;
			}
			newData[i]=value1+value2;
		}
		vsize=newSize;

		daten=move(newData);

		return *this;

}

Vektor Vektor::add(const Vektor& v1, const Vektor& v2)
{
Vektor result=v1;

 result.plusGleich(v2);
 return result;
}

int Vektor::getSize()const
{
	return this->vsize;
}


double Vektor::getAt(int index){
	if(index <1 || index >vsize)
	{
		cerr<<"Falsche Index"<<endl;
		return 0.0;
	}
	else
	{
		return daten[index-1];
	}
}



void Vektor::setAt(int index,double wert)
{
	if(index < 1 || index >vsize)
		{
			cerr<<"Falsche Index"<<endl;
		}
	else
	{
		daten[index-1]=wert;
	}
}
void Vektor::print()
{
	for(int i=0;i<vsize;i++)
	{
		cout << daten[i] <<" ";
	}
	cout << endl;
}


int main()
{
Vektor v1(3);
Vektor v2;



	v1.setAt(1, 1.0);
	v1.setAt(2, 2.0);
	v1.setAt(3, 3.0);
	//v1.setAt(4, 4.0);
	//v1.setAt(5, 5.0);

	v2.setAt(1, 1.0);
	v2.setAt(2, 2.0);
	v2.setAt(3, 3.0);
	v2.setAt(4, 4.0);

	cout<<"add-Methode: v1+v2=  ";
		Vektor result;
		result=v1.add(v1,v2);
//		result.add(v1, v2);

		result.print();
		//cout<<result<< endl;

	cout<<"v1-Size= : " <<v1.getSize()<<endl;
	cout<<"v2-Size= : " <<v2.getSize()<<endl;
	cout<< "v1= "; v1.print();
	cout<< "v1= "; v2.print();


	cout<< "v1 in position 3 ist: ";
	cout << v1.getAt(3)<<endl;

	cout<< "v2 in position 2 ist: ";
	cout << v2.getAt(2)<<endl;


	cout << "v1 plusgleich v2:  " ;
	v1.plusGleich(v2);
	 cout<< "v1= ";
	 v1.print();


		cout<< "v1 in position 3 ist: ";
		cout << v1.getAt(3)<<endl;

		cout<< "v1 in position 4 ist: ";
		cout << v1.getAt(4)<<endl;

	return 0;
}









