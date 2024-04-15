# Insightify (The C++ Machine Learning Library)


*Выражаю огромную благодарность автору YouTube канала selfedu С.М. Балакиреву и профессору К.В. Воронцову за предоставленные в общий доступ лекционные и текстовые материалы по машинному и глубокому обучению, которые стали основой для данного проекта.*


## Что такое Insightify? 


**Insightify** - это библиотека, написанная на языке C++, в которой реализованы основные методы машинного обучения для работы с данными. Основная цель проекта - образовательная. За счет открытого исходного кода и описании работы алгоритмов, библиотека позволяет любому желающему заглянуть внутрь основных подходов машинного обучения, а также понять принципы их работы. Кроме того, написание этой библиотеки позволило мне самому углубиться в познании этого интересного и базового направления науки о данных, разобраться в инженерной части и осознать некоторые подводные камни реализации, на которые можно не обратить внимание при теоретическом изучении. 


## Пространства имен и модули.


После подключения основного заголовочного файла ./include/Insightify.hpp, пользователю становится доступным основное пространство имен namespace::Insightify. Данное пространство имен содержит вложенные пространства имен. Во вложенных пространствах имен содержатся функции и классы, нажав на которые можно перейти к ознакомлению с ними.


## Insightify::Metrics


- [Insightify::Metrics meanSquaredError](#insightifymetrics-meansquarederror)
- [Insightify::Metrics meanAbsoluteError](#insightifymetrics-meanabsoluteerror)
- [Insightify::Metrics sigmoidCrossEntropyLoss](#insightifymetrics-sigmoidcrossentropyloss)
- [Insightify::Metrics sigmoid](#insightifymetrics-sigmoid)


## Insightify::LinearAlgebra


- [Insightify::LinearAlgebra vectorScalarProduct](#insightifylinearalgebra-vectorscalarproduct)
- [Insightify::LinearAlgebra multiplyMatrixByWeights](#insightifylinearalgebra-multiplymatrixbyweights)


## Insightify::Reader


- [Insightify::Reader::ReadFile](#insightifyreaderreadfile)


## Insightify::Writer


- [Insightify::Writer::WriteFile](#insightifywriterwritefile)


## Insightify::LossGradients

- [Insightify::LossGradients MSELossGradient](#insightifylossgradients-mselossgradient)
- [Insightify::LossGradients MAELossGradient](#insightifylossgradients-maelossgradient)
- [Insightify::LossGradients LogLossGradient](#insightifylossgradients-loglossgradient)


## Описание классов и функций


## Insightify::Metrics meanSquaredError[](#insightifymetrics-meansquarederror)  

- Функция высчитывает среднюю квадратичную ошибку
- Шаблон функции:

```cpp
T meanSquaredError(const std::vector<T> &targetValue, const std::vector<T> &receivedValue);
```

- Функция принимает два вектора одинаковой размерности и возвращает число


 ## Insightify::Metrics meanAbsoluteError[](#insightifymetrics-meanabsoluteerror)

- Функция высчитывает среднюю абсолютную ошибку
- Шаблон функции:

```cpp
T meanAbsoluteError(const std::vector<T> &targetValue, const std::vector<T> &receivedValue);
```

- Функция принимает два вектора одинаковой размерности и возвращает число


## Insightify::Metrics sigmoidCrossEntropyLoss[](#insightifymetrics-sigmoidcrossentropyloss) 

- Функция высчитывает сигмоидную кросс-энтропию (ошибку между истинными метками класса и предсказанными)
- Шаблон функции:

```cpp
T sigmoidCrossEntropyLoss(const std::vector<T> &targetValue, const std::vector<T> &receivedValue);
```

- Функция принимает два вектора одинаковой размерности и возвращает число


## Insightify::Metrics sigmoid[](#insightifymetrics-sigmoid) 

- Функция высчитывает значение сигмоиды для числа
- Шаблон функции:

```cpp
T sigmoidCrossEntropyLoss(const std::vector<T> &targetValue, const std::vector<T> &receivedValue);
```

- Функция принимает число и возвращает число


## Insightify::LinearAlgebra vectorScalarProduct[](#insightifylinearalgebra-vectorscalarproduct)

- Функция высчитывает скалярное произведение векторов
- Шаблон функции:

```cpp
T vectorScalarProduct(const std::vector<T> &vec1, const std::vector<T> &vec2);
```

- Функция принимает два вектора и возвращает число


## Insightify::LinearAlgebra multiplyMatrixByWeights[](#insightifylinearalgebra-multiplymatrixbyweights) 

- Функция высчитывает результат произведения матрица A на транспонированный вектор весов w: $A \times w$
- Шаблон функции:

```cpp
std::vector<T> multiplyMatrixByWeights(const std::vector<std::vector<T>> &matrixOfObjects, const std::vector<T> &weights);
```

- Функция принимает матрицу и вектор и возвращает вектор, где каждый элемент это соответственное скалярное произведение признаков объектво на данный набор весов 


## Insightify::Reader::ReadFile[](#insightifyreaderreadfile) 

- Базовый класс для чтения файлов. Конструктор класса не содержит параметров.

```cpp
Insightify::Reader::ReadFile Reader;
```

- Содержит метод readCSV, необходимый для чтения данных из CSV файла:

```cpp
// void readCSV(const std::string &filename, bool hasHeader);

Reader.readCSV("example.csv", true);
```

- Принимает на вход путь к файлу, а также флаг наличия заголовка в файле. После записывает матрицу признаков в публичное поле матрицу data, а целевые значения (последний столбец в файле) - в вектор targetValues

- [Пример](tests/test_Reader)

## Insightify::Writer::WriteFile[](#insightifywriterwritefile)

- Базовый класс для записи данных в файл. Конструктор класса не содержит параметров.

```cpp
Insightify::Writer::WriteFile Writer;
```

- Содержит метод writeCSV, необходимый для записи данных в файл формата CSV:

```cpp
// void writeCSV(const std::string &filename, const std::vector<T> &values, bool hasIdx);

Writer.writeCSV("example.csv", outputValues, true);
```

- Принимает на вход путь к файлу, указатель на одномерный вектор значений и флаг необходимости указывать в выходном файле индексы данных. 

- [Пример](tests/test_Writer)

## Insightify::LossGradients MSELossGradient[](#insightifylossgradients-mselossgradient)

- Функция высчитывает градиент MSE для определенного объекта из выборки по весам линейной модели.
 $$Loss(w, x_i |y_i) = (w_0 + w_1x_1 + .. + w_nx_n - y_i)^2$$
 $$\frac{dLoss}{dw_k} = 2 * (w_0 + w_1x_1 + .. + w_nx_n - y_i) * x_{ik}$$
 $$\frac{dLoss}{dw_0} = 2 * (w_0 + w_1x_1 + .. + w_nx_n - y_i)$$

 - Шаблон функции:

 ```cpp
std::pair<std::vector<T>, T> MSELossGradient(const std::vector<T> &sample, const T y, const std::vector<T> &weights, 
        const T bias, const std::string Regularization, const T RegularizationCoef);
```

- Функция принимает значения признаков сэмпла, целевое значение сэмпла, текущий вектор весов, значение поля смещения, а также тип регуляризации (L1/L2) и ее вес.

## Insightify::LossGradients MAELossGradient[](#insightifylossgradients-maelossgradient)

- Функция высчитывает градиент MAE для определенного объекта из выборки по весам линейной модели.
$$Loss(w, x_i |y_i) = |w_0 + w_1x_1 + .. + w_nx_n - y_i|$$
$$\frac{dLoss}{dw_k} = sign(w_0 + w_1x_1 + .. + w_nx_n - y_i) * x_{ik}$$
$$\frac{dLoss}{dw_0} = sign(w_0 + w_1x_1 + .. + w_nx_n - y_i)$$

- Шаблон функции:

 ```cpp
std::pair<std::vector<T>, T> MAELossGradient(const std::vector<T> &sample, const T y, const std::vector<T> &weights, 
        const T bias, const std::string Regularization, const T RegularizationCoef);
```

- Функция принимает значения признаков сэмпла, целевое значение сэмпла, текущий вектор весов, значение поля смещения, а также тип регуляризации (L1/L2) и ее вес.

## Insightify::LossGradients LogLossGradient[](#insightifylossgradients-loglossgradient)

- Функция высчитывает градиент LogLoss для определенного объекта из выборки по весам линейной модели. Log Loss рассматривается в плане бинарной классификации для меток классов 0 или 1.

$$Loss(w, x_i |y_i) = -y_i \log \sigma(w_0 + w_1x_1 + .. + w_nx_n) - (1 - y_i) \log (1 - \sigma(w_0 + w_1x_1 + .. + w_nx_n))$$
$$\frac{dLoss}{dw_k} = (\sigma(w_0 + w_1x_1 + .. + w_nx_n) - y_i) * x_{ik}$$
$$\frac{dLoss}{dw_0} = (\sigma(w_0 + w_1x_1 + .. + w_nx_n) - y_i)$$

- Шаблон функции:

 ```cpp
std::pair<std::vector<T>, T> LogLossGradient(const std::vector<T> &sample, const T y, const std::vector<T> &weights,
        const T bias, const std::string Regularization, const T RegularizationCoef);
```

- Функция принимает значения признаков сэмпла, целевое значение сэмпла, текущий вектор весов, значение поля смещения, а также тип регуляризации (L1/L2) и ее вес.

