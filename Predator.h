#include "Org.h"

class Predator : public Organism {
    emp::Ptr<emp::Random> random;
    int species = 0;
    public:
    Predator(emp::Ptr<emp::Random> _random, double _points=0.0, bool _hasParent = false) : Organism (_random, _points, _hasParent){;}


     emp::Ptr<Organism> CheckReproduction () {
        int req = 55;  // number of points required to reproduce;
        if (this->GetParentStatus ()) {
            int req = 45; // lower requirement of points if the predator has parents
        }
            if (points > req) { // whenever the points of the organism reach the requirement
                emp::Ptr<Organism> offspring = new Predator(*this); // make an offspring
                offspring->SetPoints(0); // give it 0 points
                this->SetPoints(this->GetPoints()-req); //substact said organism's points by the requirement (think of it as the price to pay to have a kid)
                return offspring;
            }
        
        return nullptr;
    }


    /*
        Method that always returns 0. Used my Animate.cpp to visualize predators
    */
    int GetSpecies () {
         return Organism::GetSpecies(); // predator is species 0
     }  

};