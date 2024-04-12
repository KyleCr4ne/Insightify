#pragma once
#include <vector>

namespace Insightify {
    namespace LinearAlgebra {
        template <typename T>
        T vectorScalarProduct(const std::vector<T> &vec1, const std::vector<T> &vec2);

        template <typename T>
        std::vector<T> multiplyMatrixByWeights(const std::vector<std::vector<T>> &matrixOfObjects, const std::vector<T> &weights);
    }
}