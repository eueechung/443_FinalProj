
int flow[n][n];
int dist[n][n];

float pheromones[n][n];
float pheromone_t[n];
float pheromone_max[n];
float decay;


class Ant {
	int permut[n] = {-1};
	int visited[n] = {0};
	int fitness;

	Ant(int vert) {
		fitness = 0;
	}

	//Fitness is the summed weight of the all edges of the bijection
	int fitness() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				fitness += (flow[i][j] * dist[permut[i]][permut[j]]);
			}
		}
	}

	//Randomly select a vertex to map to vertex vert_f using pheromone intensity as weights
	int select(int vert_f) {
		int temp = rand() % pheromone_t[vert_f];
		for (int i = 0;;) {
			if (!visited[i]) {
				temp -= pheromones[vert_f][i];
				if (temp <= 0) {
					return i;
				}
			}
			i = (i + 1) % n;
		}
	}

	void traverse() {
		//Choose starting vertex randomly, may improve later
		int temp = rand() % n;
		permut[0] = temp;
		visited[temp] = true;

		//Fill in the permutation using the mapping selected by the select function
		for (int i = 1; i < n; i++) {
			permut[i] = select(i);
		}
	}
}

Ant ant[ANT_NO];
