#include "emp/math/Random.hpp"
#include "emp/web/Animate.hpp"
#include "emp/web/web.hpp"
#include "World.h"
#include "Org.h"
#include "Predator.h"
#include "Prey.h"

emp::web::Document doc{"target"};

class AEAnimator : public emp::web::Animate
{

    // arena width and height
    const int num_h_boxes = 70;
    const int num_w_boxes = 70;
    const double RECT_SIDE = 10;
    const double width{num_w_boxes * RECT_SIDE};
    const double height{num_h_boxes * RECT_SIDE};

    emp::Random random{5};
    OrgWorld world{random};

    emp::web::Canvas canvas{width, height, "canvas"};

public:
    AEAnimator()
    {
        // shove canvas into the div
        // along with a control button
        doc << canvas;
        doc << GetToggleButton("Toggle");
        doc << GetStepButton("Step");
        doc << "Program showcases two organisms (a predator in red and a prey in blue) 'competing' based upon them gaining a certain amount of points (one program has a lower reach than the other) and their capabilities for reproduction (preys reproduce faster than the predators). Additionally, predators need more energy (points) to replicate and produce less offsprings, whereas the preys do the opposite. Also, to simulae real-world environments, offsprings of preys get points from there parents whenever they are 'born'. For both the predators and the preys, the amount of points needed to get an offspring decreases if an organism has a parent (as in, it's easier to survive in the environment if you have a parent). Finally, whenever a predator overtakes the place of a prey (by reproducing and taking that spot), they also get 1/2 of the points the now gone prey had";
        
        Organism *Predator_1 = new Predator(&random, 0); // creates new predator with 0 points
        world.AddOrgAt(Predator_1, 0);
        Organism *Predator_2 = new Predator(&random, 0); // creates new predator with 0 points
        world.AddOrgAt(Predator_2, 2);

        Organism *Prey_1 = new Prey(&random, 0); // creates new prey with 0 points
        world.AddOrgAt(Prey_1, 5);
        Organism *Prey_2 = new Prey(&random, 0); // creates new prey with 0 points
        world.AddOrgAt(Prey_2, 7);
        Organism *Prey_3 = new Prey(&random, 0); // creates new prey with 0 points
        world.AddOrgAt(Prey_3, 9);
        Organism *Prey_4 = new Prey(&random, 0); // creates new prey with 0 points
        world.AddOrgAt(Prey_4, 11);

        std::cout << world.size(); // prints out the world size
        world.Resize(num_w_boxes, num_h_boxes);

        world.SetPopStruct_Grid(num_w_boxes, num_h_boxes);
    }

    void DoFrame() override
    {
        world.Update();
        canvas.Clear();
        int org_num = 0;           // position of organism
        for (int x = 0; x < num_w_boxes; x++)
        {
            for (int y = 0; y < num_h_boxes; y++)
            {
                if (world.IsOccupied(org_num)) // make sure that there is an organism there
                {                                                
                    if (world.GetOrg(org_num).GetSpecies() == 0) // if the species is a predator
                    {                                                    
                        canvas.Rect(x * RECT_SIDE, y * RECT_SIDE, RECT_SIDE, RECT_SIDE, "red", "red"); // simply draw a predator
                    }
                    else
                    {
                        canvas.Rect(x * RECT_SIDE, y * RECT_SIDE, RECT_SIDE, RECT_SIDE, "blue", "blue"); // Prey
                    }
                }
                else
                {
                    canvas.Rect(x * RECT_SIDE, y * RECT_SIDE, RECT_SIDE, RECT_SIDE, "green", "green"); // field
                }
                org_num++; // increase org #
            }
        }
    }
};

AEAnimator animator;

int main() { animator.Step(); }