#include "./../../include/Reader/Reader.hpp"


namespace Insightidy {
    namespace Reader {
        template <typename T>
        void ReadFile<T>::readCSV(const std::string &filename, bool hasHeader) {
            std::ifstream file(filename);

            std::vector<std::vector<T>> data;
            std::vector<T> target;

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
                    target.push_back(row.back());
                    row.pop_back();
                    data.push_back(row);
                }
            }
        }
    }
}