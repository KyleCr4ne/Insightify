#include "./../../include/LossGradients/LossGradients.hpp"

namespace Insightify {
    namespace LossGradients {
        template <typename T>
        T sign(T x) {
            if (x > 0) return 1.0;
            if (x < 0) return -1.0;
            return 0.0;
        }

        template <typename T>
        T sigmoid(const T x) {
            return 1 / (1 + std::exp(-x));
        }

        template <typename T> 
        std::pair<std::vector<T>, T> MSELossGradient(const std::vector<T> &sample, const T y, const std::vector<T> &weights, 
        const T bias, const std::string Regularization, const T RegularizationCoef) {
            std::vector<T> weightsGradient(sample.size());
            T weightsByFeatures = LinearAlgebra::vectorScalarProduct(sample, weights);
            for (size_t i = 0; i < sample.size(); ++i) {
                weightsGradient[i] = 2 * (weightsByFeatures + bias - y) * sample[i];
                if (Regularization == "L2") weightsGradient[i] += 2 * RegularizationCoef * weights[i];
                if (Regularization == "L1") weightsByFeatures[i] += RegularizationCoef * sign(weights[i]);
            }
            T biasGradient = 2 * (weightsByFeatures + bias - y);
            return std::pair(weightsGradient, biasGradient);
        }

        template <typename T>
        std::pair<std::vector<T>, T> MAELossGradient(const std::vector<T> &sample, const T y, const std::vector<T> &weights, 
        const T bias, const std::string Regularization, const T RegularizationCoef) {
            std::vector<T> weightsGradient(sample.size());
            T weightsByFeatures = LinearAlgebra::vectorScalarProduct(sample, weights);
            for (size_t i = 0; i < sample.size(); ++i) {
                weightsGradient[i] = sign(weightsByFeatures + bias - y) * sample[i];
                if (Regularization == "L2") weightsGradient[i] += 2 * RegularizationCoef * weights[i];
                if (Regularization == "L1") weightsByFeatures[i] += RegularizationCoef * sign(weights[i]);
            }
            T biasGradient = sign(weightsByFeatures + bias - y);
            return std::pair(weightsGradient, biasGradient);
        }

        template <typename T>
        std::pair<std::vector<T>, T> LogLossGradient(const std::vector<T> &sample, const T y, const std::vector<T> &weights,
        const T bias, const std::string Regularization, const T RegularizationCoef) {
            std::vector<T> weightsGradient(sample.size());
            T weightsByFeatures = LinearAlgebra::vectorScalarProduct(sample, weights);
            for (size_t i = 0; i < sample.size(); ++i) {
                weightsByFeatures[i] = (sigmoid(weightsByFeatures + bias) - y) * sample[i];
                if (Regularization == "L2") weightsGradient[i] += 2 * RegularizationCoef * weights[i];
                if (Regularization == "L1") weightsByFeatures[i] += RegularizationCoef * sign(weights[i]);
            }
            T biasGradient = sigmoid(weightsByFeatures + bias) - y;
            return std::pair(weightsGradient, biasGradient);
        }
    }
}