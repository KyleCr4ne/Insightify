#include "./../../include/LinearAlgebra/LinearAlgebra.hpp"

namespace Insightify {
    namespace LinearAlgebra {
        template <typename T>
        T vectorScalarProduct(const std::vector<T> &vec1, const std::vector<T> &vec2) {
            if (vec1.size() != vec2.size()) {
                throw std::invalid_argument("LinAlg error [scalar product] : vectors in scalar product should have equal size");
            }
            T product = 0.0;
            for (size_t i = 0; i < vec1.size(); ++i) {
                product += vec1[i] * vec2[i];
            }
            return product;
        }

        template <typename T>
        std::vector<T> multiplyMatrixByWeights(const std::vector<std::vector<T>> &matrixOfObjects, const std::vector<T> &weights) {
            if (matrixOfObjects.empty() || matrixOfObjects[0].size() != weights.size()) {
                throw std::invalid_argument("LinAlg error [multiply matrix by weights] : Number of cols in matrix not equal to dimention of vector");
            }
            std::vector<T> product(matrixOfObjects.size());
            for (size_t i = 0; i < matrixOfObjects.size(); ++i) {
                product[i] = vectorScalarProduct(matrixOfObjects[i], weights);
            }
            return product;
        }
    }
}