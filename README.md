Program written by Elhadji Amadou Touré '25 | Carleton College for CS 361: Artificial Life and Digital Evolution

This program is a contender for the "mastery" level of the Aritifical Ecologies Assignment

Two organisms, red (predator) and blue (prey), are "competing" on a green field. Somewhat similar to Anya Vostinar's example.

To reach the proficiency level, the two organisms (predator vs. prey) are:
    1. Getting different number of points to simulate evolution and a predator vs. prey environment.
    2. Preys are multiplying faster (more offsprings made when the required number of points is reached).
    3. I followed a real-world simulation. The predators need more energy (points) to replicate and produce less offsprings, whereas the preys do the opposite.
       Additionally, sometimes, organisms get more points than the requirements. Instead of giving the offsprings of the preys 0 points, they get the difference between the amount of points their parent had and the requirement, hence having the preys donate points to each other.
    4. The fact that an organism has a parent also plays a role. If an organism has a parent, the amount of points necessary for them to replicate is decreased.
    5. Whenever a predator overtakes the place of a prey (by reproducing and taking that spot), they also get 1/2 of the points the now gone prey had.
    6. 2 Predators and 6 Preys were added at the beginning to somewhat simulate real-world situations (the choosing of this number was very arbitrary).

To reach the mastery level, an inheritance system has been put in place to make sure that the system is self-sustaining (program can run for more than 5 minutes after my tests)