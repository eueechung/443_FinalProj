#include <random>

int flow[VERT_NO][VERT_NO];
int dist[VERT_NO][VERT_NO];

float pheromones[VERT_NO][VERT_NO];
float pheromone_t[VERT_NO];
float pheromone_max[VERT_NO];
float decay;

class Ant {
	public:
		int permut[VERT_NO] = {-1};
		int visited[VERT_NO] = {0};
		int fitness;

		Ant() {
			fitness = 0;
		}

		//Fitness is the summed weight of the all edges of the bijection
		void evaluate() {
			for (int i = 0; i < VERT_NO; i++) {
				for (int j = 0; j < i; j++) {
					fitness += (flow[i][j] * dist[permut[i]][permut[j]]);
				}
			}
		}

		//Randomly select a vertex to map to vertex vert_f using pheromone intensity as weights
		int select(int vert_f) {
			int temp = (rand()/RAND_MAX) * pheromone_t[vert_f];
			for (int i = 0;;) {
				if (!visited[i]) {
					temp -= pheromones[vert_f][i];
					if (temp <= 0) {
						return i;
					}
				}
				i = (i + 1) % VERT_NO;
			}
		}

		void traverse() {
			//Choose starting vertex randomly, may improve later
			int temp = rand() % VERT_NO;
			permut[0] = temp;
			visited[temp] = true;

			//Fill in the permutation using the mapping selected by the select function
			for (int i = 1; i < VERT_NO; i++) {
				permut[i] = select(i);
			}
		}
};

Ant ant[ANT_NO];
