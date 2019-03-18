#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <utility>
#include <vector>
#include <iostream>
#include <cstring>

template <typename T>
class Matrix{
public:
    Matrix(unsigned int Size);

    Matrix(const Matrix &M);

    Matrix(Matrix &&M);

    Matrix(std::vector <T> &arr, unsigned int Size);

    ~Matrix();

    Matrix &operator= (const Matrix &M);

    Matrix &operator+= (const Matrix &M);

    Matrix &operator-= (const Matrix &M);

    friend Matrix operator+ (Matrix left, const Matrix &right){
        if (left.size != right.size){
            abort();
        }
        left += right;
        return left;
    };

    friend Matrix operator- (Matrix left, const Matrix &right){
        if (left.size != right.size){
            abort();
        }
        left -= right;
        return left;
    };

    T &operator[](const std::pair <unsigned int, unsigned int> &nm);

    template <typename L>
    Matrix & operator *= (const L &l);

    template <typename L>
    friend Matrix operator* (Matrix left, const L &right){
        return (left *= right);
    };

    template <typename L>
    friend Matrix operator* (const L &left, Matrix right){
        return (right *= left);
    };

    Matrix &operator*= (const Matrix &M);

    friend Matrix &operator* (Matrix left, const Matrix &right){
        if (left.size != right.size){
            abort();
        }
        return (left *= right);
    }

    T tr();

    friend std::ostream &operator<< (std::ostream &out, const Matrix &M){
        for (unsigned int s = 0; s < M.size; ++s){
            for (unsigned int h = 0; h < M.size; ++h){
                out << M.mat[s * M.size + h] << " ";
            }
            out << std::endl;
        }
        return out;
    }

    friend std::istream &operator>> (std::istream &in, Matrix &M){
        for (unsigned int i = 0; i < M.size * M.size; ++i){
            in >> M.mat[i];
        }
        return in;
    }

protected:
    T *mat;
    unsigned int size;

private:
    friend T proizv(const Matrix &A, const Matrix &B, const unsigned int &s, const unsigned &h){
        T sum;
        sum -= sum;
        for (unsigned int i = 0; i < A.size; ++i){
            sum += A.mat[s * A.size + i] * B.mat[i * B.size + h];
        }
        return sum;
    };
};

template <typename T>
Matrix<T>::Matrix(unsigned int Size){
    this->mat =  new T[Size * Size];
    this->size = Size;
};

template <typename T>
Matrix<T>::Matrix(const Matrix &M){
    this->mat = new T[M.size * M.size];
    for (unsigned int i = 0; i < M.size * M.size; ++i){
        memcpy(this->mat, M.mat, M.size * M.size * sizeof(T));
    }
    this->size = M.size;
};

template <typename T>
Matrix<T>::Matrix(Matrix &&M){
    mat = M.mat;
    size =M.size;
    M.mat = nullptr;
    M.size = 0;
};

template <typename T>
Matrix<T>::Matrix(std::vector <T> &arr, unsigned int Size){
    this->mat =  new T[Size * Size];
    this->size = Size;
    auto it = arr.begin();
    for (unsigned int i = 0; i < Size * Size; ++i){
        this->mat[i] = *it;
        ++it;
    }
};

template <typename T>
Matrix<T>::~Matrix(){
    delete mat;
};

template <typename T>
Matrix<T> &Matrix<T>::operator= (const Matrix &M){
    if (M.size != this->size){
        abort();
    }
    memcpy(mat, M.mat, M.size * M.size * sizeof(T));
    return *this;
};

template <typename T>
Matrix<T> &Matrix<T>::operator+= (const Matrix &M){
    if (M.size != this->size){
        abort();
    }
    for (unsigned int i = 0; i < M.size * M.size; ++i){
        mat[i] += M.mat[i];
    }
    return *this;
};

template <typename T>
Matrix<T> &Matrix<T>::operator-= (const Matrix &M){
    if (M.size != this->size){
        abort();
    }
    for (unsigned int i = 0; i < M.size * M.size; ++i){
        mat[i] -= M.mat[i];
    }
    return *this;
};

template <typename T>
T &Matrix<T>::operator[](const std::pair <unsigned int, unsigned int> &nm){
    return this->mat[nm.first * this->size + nm.second];
};

template <typename T>
template <typename L>
Matrix<T> &Matrix<T>::operator*= (const L &l){
    for (unsigned int i = 0; i < size * size; ++i){
        mat[i] = (T) (mat[i] * l);
    }
    return *this;
};

template <typename T>
Matrix<T> &Matrix<T>::operator*= (const Matrix &M){
    if (M.size != this->size){
        abort();
    }
    T arr[size * size];
    for (unsigned int i = 0; i < size * size; ++i){
        arr[i] = proizv(*this, M, i / size, i % size);
    }
    for (unsigned int i = 0; i < size * size; ++i){
        mat[i] = arr[i];
    }
    return *this;
};

template <typename T>
T Matrix<T>::tr(){
    T sum;
    sum -= sum;
    for (unsigned int i = 0; i < size; ++ i){
        sum += mat[i * (size + 1)];
    }
    return sum;
}

#endif // MATRIX_H_INCLUDED
