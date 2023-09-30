#include <iostream>
#include <vector>
#include <string>

bool isNumber(const std::string& word) {
    if (word == "zero" || word == "one" || word == "two" || word == "three" ||
        word == "four" || word == "five" || word == "six" || word == "seven" ||
        word == "eight" || word == "nine") {
        return true;
    }
    return false;
}

int main() {
    std::string word;
    std::cin >> word;

    int columns = word.length() + 1;
    int rows = columns / 3 + 2;

    std::vector<std::vector<int>> results(rows, std::vector<int>(columns, 0));
    std::vector<int> uniqueness(rows, 1);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (i == 0) {
                results[i][j] = j;
            } else {
                if (j == 0) {
                    results[i][j] = 0;
                } else {
                    std::string subword = word.substr(0, j);
                    std::string threeword = subword.substr(std::max(0, j - 3), 3);
                    std::string fourword = subword.substr(std::max(0, j - 4), 4);
                    std::string fiveword = subword.substr(std::max(0, j - 5), 5);

                    if (isNumber(threeword)) {
                        if (j - 3 >= 0) {
                            int previous_best = results[i - 1][j - 3];
                            if (previous_best < results[i][j - 1]) {
                                results[i][j] = previous_best + 1;
                            } else if (previous_best == results[i][j - 1]) {
                                results[i][j] = previous_best + 1;
                                uniqueness[i]++;
                            } else {
                                results[i][j] = results[i][j - 1] + 1;
                            }
                        }
                    } else if (isNumber(fourword)) {
                        if (j - 4 >= 0) {
                            int previous_best = results[i - 1][j - 4];
                            if (previous_best < results[i][j - 1]) {
                                results[i][j] = previous_best + 1;
                            } else if (previous_best == results[i][j - 1]) {
                                results[i][j] = previous_best + 1;
                                uniqueness[i]++;
                            } else {
                                results[i][j] = results[i][j - 1] + 1;
                            }
                        }
                    } else if (isNumber(fiveword)) {
                        if (j - 5 >= 0) {
                            int previous_best = results[i - 1][j - 5];
                            if (previous_best < results[i][j - 1]) {
                                results[i][j] = previous_best + 1;
                            } else if (previous_best == results[i][j - 1]) {
                                results[i][j] = previous_best + 1;
                                uniqueness[i]++;
                            } else {
                                results[i][j] = results[i][j - 1] + 1;
                            }
                        }
                    } else {
                        results[i][j] = results[i][j - 1] + 1;
                    }
                }
            }
        }
    }

    std::cout << results[rows - 1][columns - 1] << std::endl;
    std::cout << uniqueness[rows - 1] << std::endl;

    return 0;
}
