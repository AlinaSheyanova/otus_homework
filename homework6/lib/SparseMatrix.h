#ifndef OTUS_HOMEWORK_SPARSEMATRIX_H
#define OTUS_HOMEWORK_SPARSEMATRIX_H
#include <unordered_map>
#include <vector>

template<typename T, T DefaultValue>
class Matrix;

template<typename T, T DefaultValue>
class CellProxy {
public:
    CellProxy(Matrix<T, DefaultValue>& matrix, int x) : matrix_(matrix), x_(x) {}

    CellProxy<T, DefaultValue>& operator[](int y) {
        key_ = {x_, y};
        return *this;
    }

    CellProxy<T, DefaultValue>& operator=(const T& value) {
        if(value != DefaultValue)
            matrix_.data_[key_] = value;
        else if(matrix_.data_.find(key_) != matrix_.data_.end())
            matrix_.data_.erase(key_);
        return *this;
    }

    operator T() const {
        auto found = matrix_.data_.find(key_);
        if (found == matrix_.data_.end()) {
            return DefaultValue;
        } else {
            return found->second;
        }
    }


private:
    Matrix<T, DefaultValue>& matrix_;
    int x_;
    std::pair<int, int> key_;
};



template<typename T, T DefaultValue>
class Matrix {
public:
    struct Cell {
        int x;
        int y;
        T value;
    };

    CellProxy<T, DefaultValue> operator[](int x) {
        return CellProxy<T, DefaultValue>(*this, x);
    }

    [[nodiscard]] size_t size() const {
        return data_.size();
    }

    std::vector<Cell> getOccupiedCells() const {
        std::vector<Cell> cells;
        cells.reserve(data_.size());
        for (const auto &item : data_)
            cells.push_back({item.first.first, item.first.second, item.second});

        return cells;
    }

private:
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1,T2>& p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ h2;
        }
    };
    std::unordered_map<std::pair<int, int>, T, pair_hash> data_;

    friend class CellProxy<T, DefaultValue>;
};

#endif //OTUS_HOMEWORK_SPARSEMATRIX_H
