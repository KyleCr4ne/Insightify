#pragma once
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

namespace Insightify {
    namespace Writer {

        template <typename T>
        class WriteFile {
            public:
            WriteFile() {};
            void writeCSV(const std::string &filename, const std::vector<T> &values, bool hasIdx);
            ~WriteFile() {};
        };
    }
}