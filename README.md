# The-Shootout

The Shootout

Task:

On a map there are placed several agents. Each agent has a range in which it can see other agents, a gun that can shoot in a certain way, relative to its kind,
and an armor that can protect the agent. If the agent does not have any other agent in its range, then it can change its position (the change is made with a distance
shorter than the range of the agent). The action is taking place in rounds. Each round, an agent can use its weapon or change its position, relative to the
situation it is in.


My approach:

You start the game by choosing which 2 types of agents will fight. Each agent has a unique description that affects their movement, weapon and range.
At the beginning of the game, the two agents are spawned randomly on the map. They will move towards each other until they enter the "Fight Zone".
Here, they will continue to move in a random direction until someone gets hit. Each agent has an armor. If an agent is hit, it gets flown across the
map in a random position, the armor is destroyed and its movement speed is increased by one unit. Last "man" standing wins.
