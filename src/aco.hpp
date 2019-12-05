
int flow[][];
int dist[][];

float pheromones[][];
float decay;

int select(int vert_f) {
	int max = 0, vert_d;
	int temp = rand() % n;
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
