#define POINTS 5000
#include "aco.hpp"

int main() {
	//Init pheromones
	for (int i = 0; i < VERT_NO; i++) {
		for (int j = 0; j <= i; j++) {
			pheromones[i][j] = pheromones[j][i] = 1;
		}
		pheromone_t[i] = VERT_NO;
	}

	//Init ants
	for (int i = 0; i < ANT_NO; i++) {
		ant[i] = Ant();
	}

	while (true) {
		//Run ant routes
		for (int i = 0; i < ANT_NO; i++) {
			ant[i].traverse();
		}

		//Add pheromones to trail
		for (int i = 0; i < ANT_NO; i++) {
			for (int j = 0; j < VERT_NO; j++) {
				pheromones[i][ant[i].permut[j]] += (POINTS/ant[i].fitness);
			}
		}

		//Decay trail
		for (int i = 0; i < VERT_NO; i++) {
			for (int j = 0; j < VERT_NO; j++) {
				pheromones[i][j] *= decay;
			}
		}
	}
}
