#include <cstdio>
#include <random>
#include <cmath>
int main(void) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dist(10.0, 90.0);
	short res1, res2;
	for(int i = 0; i < 13; i++)
	{
		res1 = int(round(dist(gen))*10);
		res2 = int(round(dist(gen))*10);
		printf("gen: %d, %d\n", res1, res2);
	}
	return 0;
}