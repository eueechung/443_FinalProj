#include "aco.hpp"

//one ant at each starting vertex

int main() {
	//Init pheromones
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			pheromones[i][j] = pheromone[j][i] = 1;
		}
		pheromone_t[i] = n;
	}
	
	//Init ants
	/*
	for (int i = 0; i < n; i++) {
		ant[i] = Ant(i);
	}
	*/

	while () {
		for (int i = 0; i < n; i++) {
			ant[i].traverse();
		}
		//Decay trail
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
			}
		}
	}
}
