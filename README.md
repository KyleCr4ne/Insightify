# Insightify (The C++ Machine Learning Library)


*Выражаю огромную благодарность автору YouTube канала selfedu С.М. Балакиреву и профессору К.В. Воронцову за предоставленные в общий доступ лекционные и текстовые материалы по машинному и глубокому обучению, которые стали основой для данного проекта.*


## Что такое Insightify? 


**Insightify** - это библиотека, написанная на языке C++, в которой реализованы основные методы машинного обучения для работы с данными. Основная цель проекта - образовательная. За счет открытого исходного кода и описании работы алгоритмов, библиотека позволяет любому желающему заглянуть внутрь основных подходов машинного обучения, а также понять принципы их работы. Кроме того, написание этой библиотеки позволило мне самому углубиться в познании этого интересного и базового направления науки о данных, разобраться в инженерной части и осознать некоторые подводные камни реализации, на которые можно не обратить внимание при теоретическом изучении. 


## Пространства имен и модули.


После подключения основного заголовочного файла ./include/Insightify.hpp, пользователю становится доступным основное пространство имен namespace::Insightify. Данное пространство имен содержит вложенные пространства имен. Во вложенных пространствах имен содержатся функции и классы, нажав на которые можно перейти к ознакомлению с ними.


## Insightify::Metrics


- [Insightify::Metrics meanSquaredError](#meanSquaredError)
- [Insightify::Metrics meanAbsoluteError](#Insightify::Metrics-meanAbsoluteError)
- [Insightify::Metrics sigmoidCrossEntropyLoss](Insightify::Metrics-sigmoidCrossEntropyLoss)
- [Insightify::Metrics sigmoid](#Insightify::Metrics-sigmoid)


## Insightify::LinearAlgebra


- [Insightify::LinearAlgebra vectorScalarProduct](#Insightify::LinearAlgebra-vectorScalarProduct)
- [Insightify::LinearAlgebra multiplyMatrixByWeights](#Insightify::LinearAlgebra-multiplyMatrixByWeights)


## Insightify::Reader


- [Insightify::Reader::ReadFile](#insightify::reader::readfile)


## Insightify::Writer


- [Insightify::Writer::WriteFile](#insightify::writer::writefile)


## Описание классов и функций


## Insightify::Metrics meanSquaredError[](#meanSquaredError)  

- Функция высчитывает среднюю квадратичную ошибку
- Шаблон функции:

```cpp
T meanSquaredError(const std::vector<T> &targetValue, const std::vector<T> &receivedValue);
```

- Функция принимает два вектора одинаковой размерности и возвращает число


 ## [Insightify::Metrics meanAbsoluteError](#Insightify::Metrics-meanAbsoluteError)

- Функция высчитывает среднюю абсолютную ошибку
- Шаблон функции:

```cpp
T meanAbsoluteError(const std::vector<T> &targetValue, const std::vector<T> &receivedValue);
```

- Функция принимает два вектора одинаковой размерности и возвращает число


## [Insightify::Metrics sigmoidCrossEntropyLoss](#Insightify::Metrics-sigmoidCrossEntropyLoss) 

- Функция высчитывает сигмоидную кросс-энтропию (ошибку между истинными метками класса и предсказанными)
- Шаблон функции:

```cpp
T sigmoidCrossEntropyLoss(const std::vector<T> &targetValue, const std::vector<T> &receivedValue);
```

- Функция принимает два вектора одинаковой размерности и возвращает число


## [Insightify::Metrics sigmoid](#Insightify::Metrics-sigmoid) 

- Функция высчитывает значение сигмоиды для числа
- Шаблон функции:

```cpp
T sigmoidCrossEntropyLoss(const std::vector<T> &targetValue, const std::vector<T> &receivedValue);
```

- Функция принимает число и возвращает число


## [Insightify::LinearAlgebra vectorScalarProduct](#Insightify::LinearAlgebra-vectorScalarProduct)

- Функция высчитывает скалярное произведение векторов
- Шаблон функции:

```cpp
T vectorScalarProduct(const std::vector<T> &vec1, const std::vector<T> &vec2);
```

- Функция принимает два вектора и возвращает число


## [Insightify::LinearAlgebra multiplyMatrixByWeights](#Insightify::LinearAlgebra-multiplyMatrixByWeights) 

- Функция высчитывает результат произведения матрица A на транспонированный вектор весов w: $A \times w$
- Шаблон функции:

```cpp
std::vector<T> multiplyMatrixByWeights(const std::vector<std::vector<T>> &matrixOfObjects, const std::vector<T> &weights);
```

- Функция принимает матрицу и вектор и возвращает вектор, где каждый элемент это соответственное скалярное произведение признаков объектво на данный набор весов 


## [Insightify::Reader::ReadFile](#insightify::reader::readfile) 

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

## [Insightify::Writer::WriteFile](#insightify::writer::writefile)

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