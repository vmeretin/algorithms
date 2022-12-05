#include <iostream>
#include <map>

void stonesAndJeweleries() {
    std::string jeweleries, stones;

    std::cin >> jeweleries >> stones;

    int result = 0;

    for (char stone: stones) {
        if (jeweleries.find(stone) != std::string::npos) {
            result++;
        }
    }

    std::cout << result << std::endl;
}

void longest() {
    int n = 0, current = 0, longest = 0, digit = 0;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> digit;

        if (digit == 1) {
            current++;

            if (current > longest) {
                longest = current;
            }
        } else {
            current = 0;
        }
    }

    std::cout << longest << std::endl;
}

void distinct() {
    int n, last, digit;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> digit;

        if (digit != last) {
            last = digit;
            std::cout << digit << std::endl;
        }
    }
}

void generate(int n, const std::string &s, int open, int closed) {
    if (s.length() == n * 2) {
        std::cout << s << std::endl;
        return;
    }

    if (open < n) {
        generate(n, s + "(", open + 1, closed);
    }

    if (closed < open) {
        generate(n, s + ")", open, closed + 1);
    }
}

void bracesGenerator() {
    int n;

    std::cin >> n;

    generate(n, "(", 1, 0);
}

std::map<char, int> getMap(const std::string &word) {
    std::map<char, int> map;

    for (char currentChar: word) {
        int currentValue = map[currentChar];

        if (map.count(currentChar)) {
            map[currentChar] = currentValue + 1;
        } else {
            map[currentChar] = 1;
        }
    }

    return map;
}

void anagrams() {
    std::string a, b;

    std::cin >> a >> b;

    std::map<char, int> mapA, mapB;

    mapA = getMap(a);
    mapB = getMap(b);

    if (mapA == mapB) {
        std::cout << "1";
    } else {
        std::cout << "0";
    }
}
