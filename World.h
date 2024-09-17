#ifndef WORLD_H
#define WORLD_H

#include "emp/Evolve/World.hpp"
#include "emp/math/random_utils.hpp"
#include "emp/math/Random.hpp"

#include "Org.h"

class OrgWorld : public emp::World<Organism>
{

  emp::Random &random;
  emp::Ptr<emp::Random> random_ptr;

public:
  OrgWorld(emp::Random &_random) : emp::World<Organism>(_random), random(_random)
  {
    random_ptr.New(_random);
  }

  ~OrgWorld()
  {
  }

  /*
    An update method that essentially allow the organisms to move through space respecting the various methods in the program
  */
  void Update()
  {
    double lastPreyPoints = 0; // variable that holds the # of points of a prey at a specific spot
    bool preyPresent = true;   // when a prey was present at a location
    emp::World<Organism>::Update();
    for (int i = 0; i < GetSize(); i++)
    {
      if (!IsOccupied(i))
      {
        continue;
      }
      if (pop[i]->GetSpecies() == 0) // if organism is a predator
      {
        if (!preyPresent) // if there were no prey present here
        {
          pop[i]->Process(1); // give it the normal number of points
        }
        else // otherwise, a prey was there
        {
          pop[i]->Process(lastPreyPoints / 2); // give this predator half the points of the prey that was here
          preyPresent = false;                 // reset
          lastPreyPoints = 0;                  // reset
        }
      }
      else // if organism is a prey
      {
        pop[i]->Process(1); // give it the normal # of points
        lastPreyPoints = pop[i]->GetPoints(); // assign the points of this prey to the variable
        preyPresent = true; // make a note that there was a prey here
      }
    }
    emp::vector<size_t> schedule = emp::GetPermutation(random, GetSize());
    for (int i : schedule)
    {
      if (!IsOccupied(i))
      {
        continue;
      }
      emp::Ptr<Organism> offspring = pop[i]->CheckReproduction();

      if (offspring)
      {
        ;
        // DoBirth(*offspring, i);  //i is the parent's position in the world

        emp::WorldPosition new_position_offspring = GetRandomNeighborPos(i);
        AddOrgAt(offspring, new_position_offspring);
      }
      emp::Ptr<Organism> ext_org = ExtractOrganism(i);
      emp::WorldPosition new_position = GetRandomNeighborPos(i);
      AddOrgAt(ext_org, new_position);
    }
  }
  /*
  A method to extract organisms given a certain position
  */
  emp::Ptr<Organism> ExtractOrganism(int position)
  {
    emp::Ptr<Organism> ext_org = pop[position];
    pop[position] = nullptr;
    return ext_org;
  }
};

#endif