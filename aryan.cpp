#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Pair {
public:
    int first;
    int second;

    // Default constructor
    Pair() : first(0), second(0) {}

    // Constructor
    Pair(int f, int s) : first(f), second(s) {}

    // Overload less than operator for sorting in reverse order
    bool operator<(const Pair& other) const {
        return (first > other.first) || (first == other.first && second > other.second);
    }
};

int main() {
    // Create a vector of Pair objects
    std::vector<Pair> pairs;
    
    // Initialize Pair objects and add them to the vector
    pairs.push_back(Pair(5, 10));
    pairs.push_back(Pair(2, 7));
    pairs.push_back(Pair(8, 3));
    
    // Sort the vector in reverse order using std::sort
    std::sort(pairs.begin(), pairs.end());

    // Use std::accumulate to find the sum of Pair objects
    Pair sum = std::accumulate(pairs.begin(), pairs.end(), Pair(0, 0),
        [](const Pair& a, const Pair& b) {
            return Pair(a.first + b.first, a.second + b.second);
        });

    // Create a vector for adjacent differences
    std::vector<Pair> differences(pairs.size());
    
    // Use a loop to calculate adjacent differences
    for (size_t i = 0; i < pairs.size(); i++) {
        if (i == 0) {
            differences[i] = pairs[i];
        } else {
            differences[i].first = pairs[i].first - pairs[i - 1].first;
            differences[i].second = pairs[i].second - pairs[i - 1].second;
        }
    }

    // Print the sorted pairs, the sum, and the adjacent differences
    for (const Pair& p : pairs) {
        std::cout << "First: " << p.first << ", Second: " << p.second << std::endl;
    }
    
    std::cout << "Sum - First: " << sum.first << ", Sum - Second: " << sum.second << std::endl;

    for (const Pair& diff : differences) {
        std::cout << "Difference - First: " << diff.first << ", Difference - Second: " << diff.second << std::endl;
    }

    return 0;
}
