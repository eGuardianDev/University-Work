
#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <vector>

uint32_t SEED = 1234;

int32_t xorshift32(const int32_t seed) {

  uint32_t x = seed & 0xFFFFFFFF;

  x ^= (x << 13) & 0xFFFFFFFF;
  x ^= x >> 17;
  x ^= (x << 5) & 0xFFFFFFFF;

  return x & 0xFFFFFFFF;
}

int32_t int_range(int l, int h) {
  SEED = xorshift32(SEED);
  return (SEED % (h - l)) + l;
}

void populate(const int &max_mass,
              const std::vector<std::pair<int, int>> &items,
              std::vector<std::vector<bool>> &list) {

  int elements = list[0].size();
  for (int i = 0; i < list.size(); ++i) {
    int mass = 0;
    int count = 0;
    while (true) {
      count++;
      int j = int_range(0, elements);
      bool sol = int_range(0, 2) && mass + items[j].first <= max_mass;
      list[i][j] = sol;
      if (sol) {
        mass += items[j].first;
      }
      if (count >= elements)
        break;
    }
  }
}

void print_chromosome(std::vector<bool> &chromosome) {

  for (int i = 0; i < chromosome.size(); ++i) {
    std::cout << chromosome[i] << " ";
  }
  std::cout << std::endl;
}

// mass,cost
std::pair<int, int> compute(const std::vector<std::pair<int, int>> &items,
                            const std::vector<bool> &chromosome) {
  int mass = 0, cost = 0;
  for (int i = 0; i < chromosome.size(); ++i) {
    mass += chromosome[i] * items[i].first;
    cost += chromosome[i] * items[i].second;
  }

  return {mass, cost};
}

int find_best(const int &max_mass,
              const std::vector<std::pair<int, int>> &items,
              const std::vector<std::vector<bool>> &chromosomes) {
  int index = -1;
  int cost = INT_MIN;

  for (int i = 0; i < chromosomes.size(); ++i) {
    auto [m, c] = compute(items, chromosomes[i]);
    if (m <= max_mass && c >= cost) {
      cost = c;
      index = i;
    }
  }

  return index;
}

void sort_population(const int &max_mass,
                     const std::vector<std::pair<int, int>> &items,
                     std::vector<std::vector<bool>> &chromosomes) {
  std::sort(chromosomes.begin(), chromosomes.end(),
            [&](const auto &a, const auto &b) {
              auto [mass_a, cost_a] = compute(items, a);
              auto [mass_b, cost_b] = compute(items, b);

              bool valid_a = mass_a <= max_mass;
              bool valid_b = mass_b <= max_mass;

              if (valid_a != valid_b) {
                return valid_a;
              }

              return cost_a > cost_b;
            });
}

std::vector<bool> cross(const std::vector<bool> &chromosome1,
                        const std::vector<bool> &chromosome2) {
  int n = chromosome1.size();
  std::vector<bool> child(n, 0);

  int point = int_range(0, n + 1);
  for (int i = 0; i < n; ++i) {
    if (i < point) {
      child[i] = chromosome1[i];
    } else {
      child[i] = chromosome2[i];
    }
  }
  return child;
}

void mutate(std::vector<bool> &chromosome, int change = 1) {

  for (int i = 0; i < chromosome.size(); ++i) {
    int val = int_range(0, 101);
    if (change >= val) {
      chromosome[i] = !chromosome[i];
    }
  }
}

const int START_POPULATION = 100;

int pick(int tries = 3) {
  int best = int_range(0, START_POPULATION);
  for (int i = 1; i < tries; ++i) {
    best = std::min(best, int_range(0, START_POPULATION));
  }
  return best;
}

int main() {

  int M, N;

  std::cin >> M >> N;

  // mass, cost
  std::vector<std::pair<int, int>> items;
  for (int i = 0; i < N; ++i) {
    int m, n;
    std::cin >> m >> n;
    items.push_back({m, n});
  }

  std::vector<std::vector<bool>> list(START_POPULATION,
                                      std::vector<bool>(N, 0));

  populate(M, items, list);
  //   print_chromosome(list[0]);
  //   auto [m, c] = compute(items, list[0]);
  //   std::cout << "mass: " << m << " | cost " << c << std::endl;

  //   int best_index = find_best(M, items, list);
  //   print_chromosome(list[best_index]);
  //   auto [m1, c1] = compute(items, list[best_index]);

  //   std::cout << "mass: " << m1 << " | cost " << c1 << std::endl;

  std::vector<std::vector<bool>> new_list;
  for (int iteration = 0; iteration < 10000; ++iteration) {

    sort_population(M, items, list);

    // print_chromosome(list[0]);

    new_list.push_back(list[0]);

    while (new_list.size() < START_POPULATION) {

      int p1 = pick();
      int p2 = pick();

      std::vector<bool> child = cross(list[p1], list[p2]);
      mutate(child, 1);
      new_list.push_back(child);
    }
    if (iteration % 100 == 0) {
      auto [mass, cost] = compute(items, list[0]);
      std::cout << "Generation: " << iteration << " | Mass: " << mass
                << " | Cost: " << cost << '\n';
    }
    list = new_list;
    new_list.clear();
    // std::cout << "mass: " << m2 << " | cost " << c2 << std::endl;
  }

  return 0;
}