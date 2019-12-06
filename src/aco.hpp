
int flow[n][n];
int dist[n][n];

float pheromones[n][n];
float pheromone_t[n];
float decay;

int select(int vert_f) {
	int temp = rand() % pheromone_t[vert_f];
	for (int i = 0; temp > 0;i++) {
		if (!visited[i]) {
			temp -= pheromones[vert_f][i];
		}
	}
	return vert_d;
}

class Ant {
	int vert_f;
	int permut[];
	int visited[];
	int fitness;

	Ant(int vert) {
		flow_vert = vert;
		fitness = 0;
	}

	int fitness() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				fitness += (flow[i][j] * dist[permut[i]][permut[j]]);
			}
		}
	}

	void traverse() {
	}
}

Ant ant[];
