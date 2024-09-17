#include "Org.h"

class Prey : public Organism {
    emp::Ptr<emp::Random> random;
    int species = 1;
    public:
    Prey(emp::Ptr<emp::Random> _random, double _points=0.0, bool _hasParent = false) : Organism (_random, _points, _hasParent){;}


     emp::Ptr<Organism> CheckReproduction () {
        int number_of_offsprings = rand()%10; //make a certain amount of offsprings (random)
        int req = 20; // number of points required to reproduce
        if (this->GetParentStatus ()) {
            int req = 10; // lower requirement of points if the predator has parents
        }
        if (points > req) { // whenever the points of the organism reach the requirement
        for (int i = 0; i < number_of_offsprings; i++) {
            emp::Ptr<Organism> offspring = new Prey(*this); // make an offspring
            offspring->SetPoints(0+(points-req)); // give it 0 points
            this->SetPoints(this->GetPoints()-req); //substact said organism's points by the requirement (think of it as the price to pay to have a kid)
            return offspring;
        }
        }
        return nullptr;
    }

    /*
        Method that always returns 1. Used my Animate.cpp to visualize preys
    */
    int GetSpecies () {
         return Organism::GetSpecies() + 1; // prey is species 1
     }
 

};