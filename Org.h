#ifndef ORG_H
#define ORG_H
#include <iostream>

#include "emp/math/Random.hpp"
#include "emp/tools/string_utils.hpp"


class Organism {
    public:
        
    emp::Ptr<emp::Random> random;
    int species = 0;  //variable that holds species #
    double points = 0.0; // points of the organism
    bool hasParent = false; // to determine whether an organism ahs a parent or not

    Organism(emp::Ptr<emp::Random> _random, double _points=0.0, bool _hasParent = false) :
        points(_points), random(_random), hasParent(_hasParent){;}

    virtual void SetPoints(double _in) {points = _in;}
    virtual void AddPoints(double _in) {points += _in;}
    virtual void SetParent(bool _in) {hasParent = _in;}

    /*
        Method to process / add points
    */
    virtual void Process(double intPoints) {
        points = points + intPoints; //points adder
       
    }

    /*
        Method to get organism's points
    */
    virtual double GetPoints() {
        return points;
    }

    /*
        Method to get whether or not an organism has a parent
    */
    virtual double GetParentStatus () {
        return hasParent;
    }

    /*
        A method to determine wether or not an organism is eligible for reproduction, and provides them with an 'offspring' if true.
    */
    virtual emp::Ptr<Organism> CheckReproduction () {
        int req = 50; // number of points required to reproduce
        if (points == req) { // whenever the points of the organism reach the requirement
            emp::Ptr<Organism> offspring = new Organism(*this); // make an offspring
            offspring -> points = 0; // give it 0 points
            points -= req; //substact said organism's points by the requirement (think of it as the price to pay to have a kid)
            return offspring;
        }
        return nullptr;
    }

    /*
        Method to get the species of an organism
    */
    virtual int GetSpecies () {
         return species; // return the species of the organism (determined through inheritance)
     }    
};
#endif