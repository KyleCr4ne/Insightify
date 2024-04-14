#include "./../../include/Writer/Writer.hpp"
#include "./../../src/Writer/Writer.cpp"

#include <vector>
#include <iostream>

int main() {
    Insightify::Writer::WriteFile<double> Writer;

    std::vector <double> targets = {1.2, 3.0, 5.6, 1.3};

    Writer.writeCSV("out1.csv", targets, true);
    Writer.writeCSV("out2.csv", targets, false);

    return 0;
}