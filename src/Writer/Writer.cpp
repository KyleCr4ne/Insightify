#include "./../../include/Writer/Writer.hpp"

namespace Insightify{
    namespace Writer {
        template <typename T>
        void WriteFile<T>::writeCSV(const std::string &filename, const std::vector<T> values, bool hasIdx) {
            std::ofstream file(filename);
            if (!file.is_open()) {
                std::cerr << "Error: Unable to open file " << filename << std::endl;
                return;
            }

            for (size_t i = 0; i < values.size(); ++i) {
                if (hasIdx) file << i << ",";
                file << values[i] << std::endl;
            }
            file.close();
        }
    }
}