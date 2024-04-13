#include "./../../include/Metrics/Metrics.hpp"

namespace Insightify {
    namespace Metrics {

        template <typename T>
        T meanSquaredError(const std::vector<T> &targetValue, const std::vector<T> &receivedValue) {
            if (targetValue.size() != receivedValue.size()) {
                throw std::invalid_argument("Metrics error [MSE] : target and received data expected equal size");
            }
            T sumSquaredDiff = 0.0;
            for (size_t i = 0; i < targetValue.size(); ++i) {
                sumSquaredDiff += std::pow(receivedValue[i] - targetValue[i], 2);
            }
            return sumSquaredDiff / targetValue.size();
        }

        template <typename T>
        T meanAbsoluteError(const std::vector<T> &targetValue, const std::vector<T> &receivedValue) {
            if (targetValue.size() != receivedValue.size()) {
                throw std::invalid_argument("Metrics error [MAE] : target and received data expected equal size");
            }
            T sumABSDiff = 0.0;
            for (size_t i = 0; i < targetValue.size(); ++i) {
                sumABSDiff += std::abs(receivedValue[i] - targetValue[i]);
            }
            return sumABSDiff / targetValue.size();
        }

        template <typename T>
        T sigmoidCrossEntropyLoss(const std::vector<T> &targetValue, const std::vector<T> &receivedValue) {
            if (targetValue.size() != receivedValue.size()) {
                throw std::invalid_argument("Metrics error [MAE] : target and received data expected equal size");
            }
            T logDiff = 0.0;
            for (size_t i = 0; i < targetValue.size(); ++i) {
                logDiff += targetValue[i] * std::log(receivedValue[i]) + (1 - targetValue[i]) * std::log(1 - receivedValue[i]);
            }
            return  - logDiff / targetValue.size();
        }

        template <typename T>
        T sigmoid(const T x) {
            return 1 / (1 + std::exp(-x));
        }

    }
}