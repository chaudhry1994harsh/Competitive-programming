#include <iostream>
#include <set>
#include <unordered_map>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct Rein {
	string name = "";
	long n1 = 0;
	long n2 = 0;
};

struct id_compare {
	bool operator()(const Rein &x, const Rein &y) const {
		if (x.n1 != y.n1) {
			return x.n1 > y.n1;
		} else {
			return x.n2 > y.n2;
		}
	}
};

int main() {
	set<Rein, id_compare> v;
	unordered_map<string, Rein> m;
	long n;
	scanf("%ld", &n);
	char ch = 'a';
	long sum = 0;

	while (n--) {
		Rein newR;
		cin >> ch >> newR.name;
		if (ch == 'A') {
			scanf("%ld %ld", &newR.n1, &newR.n2);
			v.insert(newR);
			m.insert(make_pair(newR.name, newR));
			set<Rein, id_compare>::iterator ite = v.find(newR);

			if (newR.name == (v.rbegin())->name) {
				if (v.size() > 1) {
					ite--;
					sum += newR.n2 * ite->n2;
				}
			} else if (newR.name == (v.begin())->name) {
				ite++;
				sum += newR.n2 * ite->n2;
			} else {
				ite++;
				long next = ite->n2;
				ite--;
				ite--;
				long prev = ite->n2;
				sum -= next * prev;
				sum += newR.n2 * prev;
				sum += newR.n2 * next;
			}
		} else {
			set<Rein, id_compare>::iterator ite = v.find(m[newR.name]);
			long val = ite->n2;
			if (newR.name == (v.rbegin())->name) {
				if (v.size() > 1) {
					ite--;
					sum -= ite->n2 * val;
				}
			} else if (newR.name == (v.begin())->name) {
				ite++;
				sum -= ite->n2 * val;
			} else {
				ite++;
				long next = ite->n2;
				ite--;
				ite--;
				long prev = ite->n2;
				sum -= prev * val;
				sum -= next * val;
				sum += next * prev;
			}
			v.erase(m[newR.name]);
			m.erase(newR.name);
		}
		printf("%ld\n", sum);
	}

}