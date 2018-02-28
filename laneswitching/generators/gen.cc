#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include <random>
#include <iomanip>
#include <vector>
#include <tuple>

using namespace std;

const int MAX_N = 100;
const int MAX_CAR_PER_LANE = 100;
const int MAX_R = 1000000;
const string prob_name = "lanes";

default_random_engine generator;
uniform_int_distribution<int> distribution(0, MAX_R);

string filename(int s)
{
  ostringstream oss;
  oss << prob_name << "-" << setw(2) << setfill('0') << s << ".in";
  return oss.str();
}

int random_int(int lo, int hi)
{
  return distribution(generator) % (hi - lo + 1) + lo;
}

typedef pair<int,int> Interval;
typedef tuple<int,int,int> Car;

vector<Interval> gen_lane(int R, int cars, int max_car_len = MAX_R)
{
  vector<Interval> cars_vec;

  while (cars > 0) {
    int front = random_int(cars, R);
    int back = random_int(max(cars-1, front-max_car_len), front-1);
    cars_vec.push_back(Interval(back, front));
    R = back;
    cars--;
  }
  return cars_vec;
}

Car get_car(int lane, Interval I)
{
  return make_tuple(lane, I.second-I.first, I.first);
}

ostream &operator<<(ostream &os, const Car &car)
{
  return os << get<0>(car) << ' ' << get<1>(car) << ' ' << get<2>(car);
}


void output(int id, vector<Interval> lane[], int N, int R)
{
  ofstream out(filename(id).c_str());

  int M = 0;
  for (int i = 0; i < N; i++) {
    M += lane[i].size();
  }
  
  out << N << ' ' << M << ' ' << R << endl;
  int acm_index = random_int(0, lane[0].size()-1);
  Car acm_car = get_car(0, lane[0][acm_index]);
  out << acm_car << endl;
  swap(lane[0][acm_index], lane[0][lane[0].size()-1]);
  lane[0].pop_back();

  vector<Car> cars;
  for (int i = 0; i < N; i++) {
    for (auto p : lane[i]) {
      cars.push_back(get_car(i, p));
    }
  }

  shuffle(cars.begin(), cars.end(), generator);
  for (auto c : cars) {
    out << c << endl;
  }
}

void gen_rand_lanes(int id, int N, int R, int max_car_per_lane,
		    int max_car_len)
{
  vector<Interval> lane[MAX_N];
  for (int i = 0; i < N; i++) {
    lane[i] = gen_lane(R, random_int((i == 0) ? 1 : 0, max_car_per_lane),
		       max_car_len);
  }
  output(id, lane, N, R);
}

void gen_empty_lanes(int id, int N, int R, int max_car_len)
{
  vector<Interval> lane[MAX_N];
  for (int i = 0; i < N; i++) {
    lane[i] = gen_lane(R, (i == 0) ? 1 : 0, max_car_len);
  }
  output(id, lane, N, R);
}

void gen_zigzag(int id)
{
  int N = MAX_N;
  int R = 4000;
  vector<Interval> lane[MAX_N];

  lane[0].push_back(Interval{0,10});
  int lane_num = 0;
  for (int i = 0; i < N / 5; i++) {
    // lane 1
    int t = 10;
    for (int j = 0; j < 99; j++) {
      lane[lane_num].push_back(Interval{t, t+10});
      t += 40;
    }
    lane_num++;

    // lane 2
    t = 30;
    for (int j = 0; j < 99; j++) {
      lane[lane_num].push_back(Interval{t, t+10});
      t += 40;
    }
    lane_num++;

    // lane 3
    lane[lane_num].push_back(Interval{0, 3990});
    lane_num++;

    // lane 4 is empty
    lane_num++;

    // lane 5
    lane[lane_num].push_back(Interval{10,4000});
    lane_num++;
  }
  output(id, lane, N, R);
}

void gen_checker(int id, double gap_factor = 2.0)
{
  int N = MAX_N;
  vector<Interval> lane[MAX_N];

  int car_size = 10;
  int gap_size = floor(car_size*gap_factor+0.5);

  int R;
  for (int i = 0; i < MAX_N; i++) {
    int start = (i % 2) ? 0 : gap_size;
    for (int j = 0; j < MAX_CAR_PER_LANE; j++) {
      lane[i].push_back(Interval{start, start+car_size});
      start += car_size+gap_size;
      R = max(R, start+car_size);
    }
  }
  
  output(id, lane, N, R);
}

int main()
{
  int start = 1;

  // some with just 2 lanes
  for (int i = 0; i < 3; i++) {
    gen_rand_lanes(start++, 2, MAX_R, random_int(0, MAX_CAR_PER_LANE), 1000);
  }

  // some with no cars
  for (int i = 0; i < 5; i++) {
    gen_empty_lanes(start++, random_int(2, MAX_N), MAX_R, MAX_R);
  }

  // some with cars that are long, so hopefully impossible
  for (int i = 0; i < 5; i++) {
    gen_rand_lanes(start++, random_int(2, MAX_N), MAX_R,
		   random_int(0, MAX_CAR_PER_LANE), MAX_R/30);
  }

  // some really big cases
  for (int i = 0; i < 3; i++) {
    gen_rand_lanes(start++, MAX_N, MAX_R, random_int(0, MAX_CAR_PER_LANE),
		   MAX_R);
  }
  for (int i = 0; i < 3; i++) {
    gen_rand_lanes(start++, MAX_N, MAX_R, 30, 100);
  }
  gen_rand_lanes(start++, MAX_N, MAX_R, MAX_CAR_PER_LANE, 500);
  gen_rand_lanes(start++, MAX_N, MAX_R, MAX_CAR_PER_LANE, MAX_R);

  gen_zigzag(start++);

  for (int i = 3; i <= 6; i++) {
    gen_checker(start++, i/2.0);
  }
}

