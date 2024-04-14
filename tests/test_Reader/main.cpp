#include "./../../include/Reader/Reader.hpp"
#include "./../../src/Reader/Reader.cpp"

#include <vector>
#include <iostream>


int main() {
    Insightify::Reader::ReadFile<double> Reader;

    std::vector <std::vector<double>> X;
    std::vector<double> Y;

    Reader.readCSV("in.csv", false);
    
    X = Reader.data;
    Y = Reader.targetValues;

    std::cout << "Features of objects:" << std::endl;
    for (const auto &row : X) {
        for (const auto &elem : row) {
            std::cout << elem << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "Target value of objects" << std::endl;
    for (const auto &target : Y) {
        std::cout << target << std::endl;
    }
    return 0;
}
