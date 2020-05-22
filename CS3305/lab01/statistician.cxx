#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cfloat>
#include <functional>

#include "statistician.h"

std::string statistician::toString( ) const {
    //Library facilities used:  sstream, string
    std::stringstream outs;
    outs << "Statistician: \n";
    outs << "\tcount = " << this->count  << "\n"; 
    outs << "\ttotal = " << this->total  << "\n";
    if ( this->count == 0 ) {
       outs << "\tmean  = NOT DEFINED\n";
       outs << "\tmin   = NOT DEFINED\n";
       outs << "\tmax   = NOT DEFINED\n";
    }
    else {
        outs << "\tmean  = " << this->mean()  << "\n";
        outs << "\tmin   = " << this->tinyest << "\n";
        outs << "\tmax   = " << this->largest << "\n";
    }
    return outs.str();
}

statistician::statistician( ) {
    this->count = 0;
    this->total = 0;
    this->tinyest =  DBL_MAX; 
    this->largest = -DBL_MAX ; 
}

statistician::statistician(const statistician& other) {
    /* student implements */
    this->count = other.count;
    this->total = other.total;
    this->tinyest = other.tinyest;
    this->largest = other.largest;
}

void statistician::next(double r) {
    /* student implements */
    this->count++;
    this->total += r;

    if(r > this->largest)
        this->largest = r;
    if(r < this->tinyest)
        this->tinyest = r;
}

void statistician::reset( ) {
    /* student implements */
    this->count = 0;
    this->total = 0.0;
    this->tinyest = DBL_MAX;
    this->largest = -DBL_MAX;
}

statistician& statistician::operator =(const statistician& other) {
    //Check for possible self-assignment
    if (this == &other) return *this;

    this->count   = other.count;
    this->total   = other.total;
    this->tinyest = other.tinyest;
    this->largest = other.largest;

    return *this;
}

size_t statistician::hashCode( ) const {
    size_t hashValue;
    std::hash<double> hash; 
    hashValue = 101 * ( hash(this->count) +
                        hash(this->total) +
                        hash(this->tinyest) +
                        hash(this->largest) 
                      );
    return hashValue;
}

int statistician::length( ) const {
    return count;
}

double statistician::sum( ) const {
    return total;
}

double statistician::mean( ) const {
    if ( this->length( ) == 0 )
        throw std::domain_error("Mean not defined as there is no data");
    return total / count;
}

double statistician::minimum( ) const {
    if ( this->length( ) == 0 )
        throw std::domain_error("Minimum not defined as there is no data");
    return tinyest;
}

double statistician::maximum( ) const {
    if ( this->length( ) == 0 )
        throw std::domain_error("Maximum not defined as there is no data");
    return largest;
}

statistician  operator *(double scale, statistician& s) {
    if (s.length() == 0)
        return s;
    statistician temp(s);
    double temporary;

    /* student completes implementation here */

    temp.total *= scale;
    temp.tinyest *= scale;
    temp.largest *= scale;

    if(temp.largest < temp.tinyest){
        temporary = temp.tinyest;
        temp.tinyest = temp.largest;
        temp.largest = temporary;
    }

    return temp;
}

statistician operator +(const statistician& s1, const statistician& s2){
     
    if (s1.length() == 0)
        return s2;
    if (s2.length() == 0)
        return s1;
    
    statistician temp;
    
    /* student completes implementation here */
    temp.count = s1.length() + s2.length();
    temp.total = s1.sum() + s2.sum();

    
    if(s1.maximum() > s2.maximum()){
        temp.largest = s1.maximum();
    }
    else{
        temp.largest = s2.maximum();
    }
    if(s1.minimum() < s2.minimum()){
        temp.tinyest = s1.minimum();
    }
    else{
        temp.tinyest = s2.minimum();
    }
    return temp;
}

bool operator ==(const statistician& s1, const statistician& s2) {
    if (s1.length( ) == 0 && s2.length( ) == 0) return true;

    bool attrEqual;

    if (s1.hashCode() != s2.hashCode()) return false;

    /* student completes implementation here */
    return (s1.length() == s2.length() && s1.sum() == s2.sum() && s1.minimum() == s2.minimum() && s1.maximum() == s2.maximum());

}


bool operator !=(const statistician& s1, const statistician& s2) {
    return !(s1 == s2);
}

std::ostream& operator <<(std::ostream& outs, const statistician& s1) {
    outs << s1.toString();
    return outs;
}

