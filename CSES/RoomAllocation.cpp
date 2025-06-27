#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Customer {
    long long arrival, departure;
    int index;
};

int main() {
    int n;
    cin >> n;
    vector<Customer> customers(n);
    for (int i = 0; i < n; ++i) {
        cin >> customers[i].arrival >> customers[i].departure;
        customers[i].index = i;
    }
    sort(customers.begin(), customers.end(), [](const Customer &a, const Customer &b) {
        return a.arrival < b.arrival;
    });

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    vector<int> allocation(n);
    int room_count = 0;

    for (int i = 0; i < n; ++i) {
        long long a = customers[i].arrival;
        long long d = customers[i].departure;
        int idx = customers[i].index;

        if (!pq.empty() && pq.top().first < a) {
            int room = pq.top().second;
            pq.pop();
            pq.push(make_pair(d, room));
            allocation[idx] = room;
        } else {
            room_count++;
            pq.push(make_pair(d, room_count));
            allocation[idx] = room_count;
        }
    }

    cout << room_count << "\n";
    for (int i = 0; i < n; ++i) {
        cout << allocation[i] << " ";
    }
    cout << "\n";

    return 0;
}
