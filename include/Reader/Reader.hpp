#pragma once
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


namespace Insightify {
    namespace Reader {

        template <typename T>
        class ReadFile {
            public:
            std::vector<std::vector<T>> data;
            std::vector<T> targetValues;
            std::vector<std::string> Header;
            ReadFile() {};
            void readCSV(const std::string &filename, bool hasHeader);
            ~ReadFile() {};
        };
        
    }
}
