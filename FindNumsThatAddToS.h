#include <vector>
#include <map>
#include "SubsetToSum.h"

template <class T>
class FindNumsThatAddToS {

public:

    std::vector<T> find(std::vector<T> inputSet, T sum) {



        SubsetToSum<T>** table = new SubsetToSum<T>*[inputSet.size()];
        for (int i = 0; i < inputSet.size(); i++) {
            table[i] = new SubsetToSum<T>[sum + 1];
        }



        for (int i = 0; i < inputSet.size(); i++) {
            for (T j = 0; j < sum; j++) {
                if (j == 0) {
                    SubsetToSum<T> subsetToSum(0, nullptr);   
                    table[i][j] = subsetToSum;
                } else if (i == 0) {
                    addTopRowElementToTable(table, inputSet[i], j);
                } else if (inputSet[i] > j) {
                    checkPreviousRow(table, i, inputSet[i], j);
                } else {
                    determineElement()
                }
            }
        }


        delete[] table;

        return nullptr;
    }

    void addTopRowElementToTable(int** table, T element, T sum) {
        if (element == sum) {
            std::vector<T> subset();
            subset.add(element);
            SubsetToSum<T> subsetToSum(sum, subset);   
            table[element][sum] = subsetToSum;
        } else {
            table[element][sum] = nullptr;
        }
    }

    void checkPreviousRow(int** table, int rowIndex, T element, T sum) {
        table[rowIndex][sum] = table[rowIndex - 1][sum];
    }

    void determineElement(int** table, int rowIndex, T element, T sum)
};