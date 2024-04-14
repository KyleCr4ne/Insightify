#pragma once
#include "./../LinearAlgebra/LinearAlgebra.hpp"
#include <vector>
#include <cmath>

namespace Insightify {
    namespace LossGradients {
        template <typename T>
        T sign(const T x);

        template <typename T>
        T sigmoid(const T x);

        template <typename T> 
        std::pair<std::vector<T>, T> MSELossGradient(const std::vector<T> &sample, const T y, const std::vector<T> &weights, 
        const T bias, const std::string Regularization, const T RegularizationCoef);

        template <typename T>
        std::pair<std::vector<T>, T> MAELossGradient(const std::vector<T> &sample, const T y, const std::vector<T> &weights, 
        const T bias, const std::string Regularization, const T RegularizationCoef);

        template <typename T>
        std::pair<std::vector<T>, T> LogLossGradient(const std::vector<T> &sample, const T y, const std::vector<T> &weights,
        const T bias, const std::string Regularization, const T RegularizationCoef);
    }
}
