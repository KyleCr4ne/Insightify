#pragma once
#include <vector>
#include <cmath>

namespace Insightify {
    namespace Metrics {

        template <typename T>
        T meanSquaredError(const std::vector<T> &targetValue, const std::vector<T> &receivedValue);

        template <typename T>
        T meanAbsoluteError(const std::vector<T> &targetValue, const std::vector<T> &receivedValue);

        template <typename T>
        T sigmoidCrossEntropyLoss(const std::vector<T> &targetValue, const std::vector<T> &receivedValue);

        template <typename T>
        T sigmoid(const T x);
        
    }
}