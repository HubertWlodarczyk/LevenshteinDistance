#include <iostream>
#include <string>

int LevenshteinDistance(std::string, std::string);

int Min(int, int, int);

int main() {
    std::cout << "Insert first word" << std::endl;
    std::string word1;
    std::cin >> word1;
    std::cout << "Insert second word" << std::endl;
    std::string word2;
    std::cin >> word2;
    std::cout << "Levenshtein distance is: " << LevenshteinDistance(word1, word2) << std::endl;
    return 0;
}

int LevenshteinDistance(std::string word1, std::string word2) {
    int matrixHigh = word1.size() + 1;
    int matrixWidth = word2.size() + 1;
    int **resultMatrix = new int *[matrixHigh];
    for (int i = 0; i < matrixHigh; i++) {
        resultMatrix[i] = new int[matrixWidth];
        resultMatrix[i][0] = i;
    }
    for (int i = 0; i < matrixWidth; i++) resultMatrix[0][i] = i;
    int sameChar;
    for (int i = 1; i < matrixHigh; i++) {
        for (int j = 1; j < matrixWidth; j++) {
            sameChar = 0;
            if (word1[i - 1] != word2[j - 1]) sameChar++;
            resultMatrix[i][j] = Min(resultMatrix[i - 1][j - 1] + sameChar, resultMatrix[i - 1][j] + 1,
                                     resultMatrix[i][j - 1] + 1);
        }
    }
    return resultMatrix[matrixHigh - 1][matrixWidth - 1];
}

int Min(int arg1, int arg2, int arg3) {
    int min = arg1;
    if (min > arg2) min = arg2;
    if (min > arg3) min = arg3;
    return min;
}
