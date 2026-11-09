
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

struct individual {
  std::vector<short> chromosome;
  int mass;
  int cost;
};

void populate(const int &max_mass, const int &max_count,
              const std::vector<std::pair<int, int>> &items,
              std::vector<individual> &list) {
  for (auto &indv : list) {
    indv.mass = 0;
    indv.cost = 0;
    indv.chromosome.assign(items.size(), 0);

    for (int i = 0; i < items.size(); ++i) {
      bool take = int_range(0, 2);
      if (take && indv.mass + items[i].first <= max_mass) {
        indv.chromosome[i] = 1;
        indv.mass += items[i].first;
        indv.cost += items[i].second;
      }
    }
  }
}

void print_chromosome(std::vector<short> &chromosome) {

  for (int i = 0; i < chromosome.size(); ++i) {
    std::cout << chromosome[i] << " ";
  }
  std::cout << std::endl;
}
void sort_population(const int &max_mass,
                     const std::vector<std::pair<int, int>> &items,
                     std::vector<individual> &chromosomes) {
  std::sort(chromosomes.begin(), chromosomes.end(),
            [&](const auto &a, const auto &b) {
              bool valid_a = a.mass <= max_mass;
              bool valid_b = b.mass <= max_mass;

              if (valid_a != valid_b) {
                return valid_a;
              }

              return a.cost > b.cost;
            });
}

individual cross(const std::vector<std::pair<int, int>> &items,
                 const individual &indv1, const individual &indv2) {
  int n = indv1.chromosome.size();
  individual child;

  child.mass = 0;
  child.cost = 0;

  child.chromosome.resize(n);

  int point = int_range(0, n + 1);
  for (int i = 0; i < n; ++i) {

    short parent = (i < point) ? indv1.chromosome[i] : indv2.chromosome[i];

    child.chromosome[i] = (parent);

    if (parent) {
      child.mass += items[i].first;
      child.cost += items[i].second;
    }
  }
  return child;
}

void mutate(std::vector<std::pair<int, int>> &items, individual &indv,
            int change = 1) {

  for (int i = 0; i < indv.chromosome.size(); ++i) {
    int val = int_range(0, 1001);
    if (change > val) {
      indv.chromosome[i] = !indv.chromosome[i];
      if (indv.chromosome[i] == 0) {
        indv.mass -= items[i].first;
        indv.cost -= items[i].second;
      } else {
        indv.mass += items[i].first;
        indv.cost += items[i].second;
      }
    }
  }
}

const int START_POPULATION = 400;

int pick(int tries = 3) {
  int best = int_range(0, START_POPULATION);
  for (int i = 1; i < tries; ++i) {
    best = std::min(best, int_range(0, START_POPULATION));
  }
  return best;
}

void repair(const int &max_mass, const std::vector<std::pair<int, int>> &items,
            individual &indv) {

  while (indv.mass > max_mass) {
    int j = int_range(0, indv.chromosome.size());
    if (indv.chromosome[j] == 1) {
      indv.chromosome[j] = false;
      indv.mass -= items[j].first;
      indv.cost -= items[j].second;
    }
  }
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

  std::vector<individual> list(START_POPULATION);

  populate(M, N, items, list);
  std::vector<individual> new_list;
  int count = 0;

  for (int iteration = 0; iteration < 500; ++iteration) {

    sort_population(M, items, list);

    new_list.push_back(list[0]);

    while (new_list.size() < START_POPULATION) {

      int p1 = pick(20);
      int p2 = pick(20);

      individual child = cross(items, list[p1], list[p2]);
      mutate(items, child, 10);
      repair(M, items, child);
      new_list.push_back(child);
    }
    ++count;
    if (count <= 9) {
      std::cout << list[0].cost << std::endl;
    }
    list = new_list;
    new_list.clear();
  }
  std::cout << list[0].cost << std::endl;

  std::cout << "\n";
  std::cout << list[0].cost << std::endl;

  return 0;
}