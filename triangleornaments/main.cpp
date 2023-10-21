#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    float sum = 0;


    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == b) {
            // If a = b, we can simpy add c to the sum
            sum += c;
        } else {
            // Check that a is the largest
            if (a < b) swap(a, b);

            // Calculate the squares
            float a_square = a * a, b_square = b * b, c_square = c * c;
            float x = a_square - b_square;

            // Add the square root of the difference to the sum
            sum += sqrt(c_square - x * x / (2 * a_square + 2 * b_square - c_square));
        }
    }

    cout << sum << endl;
    return 0;
}
