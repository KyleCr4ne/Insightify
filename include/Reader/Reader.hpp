#pragma once
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


namespace Insightidy {
    namespace Reader {

        template <typename T>
        class ReadFile {
            public:
            std::vector<std::vector<T>> data;
            std::vector<T> targetValues;
            std::vector<std::string> Header;
            ReadFile() {};
            void readCSV(const std::string &filename, bool hasHeader);
            ~ReaFile() {};
        };
        
    }
}