#include <iostream>
#include <string>
#include <map>

using namespace std;

string notes[] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
int skip[] = {0, 2, 4, 5, 7, 9, 11};
map<string, int> rev;

int main() {
    for (int i = 0; i < 12; ++i) rev[notes[i]] = i;

    int n;
    cin >> n;
    int played = 0;
    while (n--) {
        string s;
        cin >> s;
        played |= (1<<rev[s]);
    }

    int cnt = 0, scale = 0;
    for (auto x : skip) scale |= (1<<x);

    for (int i = 0; i < 12; ++i) {
        if ((scale & played) == played) {
            if (cnt++) cout << ' ';
            cout << notes[i];
        }
        scale = ((scale<<1)&0xfff) | (scale>>11);
    }
    if (!cnt) cout << "none" << endl;
    else cout << endl;

    return 0;
}
