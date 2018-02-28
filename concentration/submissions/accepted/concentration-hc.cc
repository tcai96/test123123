#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  N *= 2;

  queue<int> perm[2];

  for (int p = 0; p < 2; p++) {
    for (int i = 0; i < N; i++) {
      int x;
      cin >> x;
      perm[p].push(x);
    }
  }

  vector<bool> seen(N, false);

  int count[2] = {0};
  int turn = 0;
  int total = 0;

  int ready = 0;
  while (true) {
    // take all the similar cards that are known
    total += ready;
    count[turn] += ready;
    ready = 0;

    if (total == N) break;
    
    // get the next 2 cards
    int card[2];
    for (int i = 0; i < 2; i++) {
      while (seen[perm[turn].front()]) {
	perm[turn].pop();
      }
      card[i] = perm[turn].front();
      perm[turn].pop();
      seen[card[i]] = true;

      // see if it's similar to a card seen before, take both
      if (i == 0) {
	int t = card[i]/2 * 2;
	if (seen[t] && seen[t+1]) {
	  // take both
	  total += 2;
	  count[turn] += 2;
	  break;
	}
      } else {
	if (card[0]/2 == card[1]/2) {
	  total += 2;
	  count[turn] += 2;
	} else {
	  for (int i = 0; i < 2; i++) {
	    int t = card[i]/2 * 2;
	    if (seen[t] && seen[t+1]) {
	      ready += 2;
	    }
	  }
	  turn = 1 - turn;
	}
      }
    }
  }

  if (count[0] == count[1]) {
    cout << "-1" << endl;
  } else if (count[0] > count[1]) {
    cout << "0" << endl;
  } else {
    cout << "1" << endl;
  }
  
  return 0;
}
