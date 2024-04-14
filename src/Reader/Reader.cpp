#include "./../../include/Reader/Reader.hpp"


namespace Insightify {
    namespace Reader {
        template <typename T>
        void ReadFile<T>::readCSV(const std::string &filename, bool hasHeader) {
            std::ifstream file(filename);
            if (!file.is_open()) {
                std::cerr << "Error: Unable to open file " << filename << std::endl;
                return;
            }

            std::string line;

            while (std::getline(file, line)) {
                std::stringstream ss(line);
                std::string cell;
                std::vector<T> row;
                while (getline(ss, cell, ',')) {
                    row.push_back(static_cast<T>(std::stod(cell)));
                }
                if (!row.empty()) {
                    if (hasHeader == true) {
                        hasHeader = false;
                        continue;
                    } 
                    targetValues.push_back(row.back());
                    row.pop_back();
                    data.push_back(row);
                }
            }
            file.close();
        }
        
    }
}