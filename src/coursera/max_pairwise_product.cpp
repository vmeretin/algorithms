#include <iostream>
#include <vector>
#include <cstdlib>

long long MaxPairwiseProductSlow(const std::vector<int> &numbers) {
    long long max_product = 0;
    unsigned long n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product, (long long) numbers[first] * (long long) numbers[second]);
        }
    }

    return max_product;
}

long long MaxPairwiseProduct(const std::vector<int> &numbers) {
    unsigned long n = numbers.size();

    int index1 = 0, index2 = 0;

    // search first biggest number
    for (int i = 1; i < n; i++) {
        if (numbers[i] > numbers[index1]) {
            index1 = i;
        }
    }

    // if the first is first biggest, start searching second biggest from the second
    if (index1 == 0) {
        index2 = 1;
    }

    for (int i = 1; i < n; i++) {
        if (numbers[i] > numbers[index2] && i != index1) {
            index2 = i;
        }
    }

    return (long long) numbers[index1] * (long long) numbers[index2];
}

void stressTest() {
    while (true) {
        int n = rand() % 1000 + 2;
        std::cout << n << std::endl;

        std::vector<int> a;
        for (int i = 0; i < n; i++) {
            a.push_back(rand() % 1000000);
        }
        for (int i = 0; i < n; i++) {
            std::cout << a[i] << ' ';
        }

        long long res1 = MaxPairwiseProduct(a);
        long long res2 = MaxPairwiseProductSlow(a);

        if (res1 != res2) {
            std::cout << "Fail:" << res1 << ' ' << res2 << std::endl;
            break;
        } else {
            std::cout << "OK!" << std::endl;;
        }
    }
}

int main() {
    int n;

    std::cin >> n;

    std::vector<int> numbers(n);

    for (int i = 0; i < n; i++) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << std::endl;

    return 0;
}
