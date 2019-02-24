#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <cstring>

template <typename T, unsigned int Size>
class Matrix{
public:
    Matrix(){
        this->mat =  new T[Size * Size];
        this->size = Size;
    };

    Matrix(const Matrix &M){
        this->mat = new T[M.size * M.size];
        for (unsigned int i = 0; i < M.size * M.size; ++i){
            memcpy(this->mat, M.mat, M.size * M.size * sizeof(T));
        }
        this->size = M.size;
    };

    Matrix(Matrix &&M){
        mat = M.mat;
        size =M.size;
        M.mat = nullptr;
        M.size = 0;
    };

    Matrix(T *arr){
        this->mat =  new T[Size * Size];
        this->size = Size;
        memcpy(this->mat, arr, Size * Size * sizeof(T));
    };

    ~Matrix(){
        delete mat;
    };

    Matrix &operator= (const Matrix &M){
        memcpy(mat, M.mat, M.size * M.size * sizeof(T));
        return *this;
    };

    Matrix &operator+= (const Matrix &M){
        for (unsigned int i = 0; i < M.size * M.size; ++i){
            mat[i] += M.mat[i];
        }
        return *this;
    };

    Matrix &operator-= (const Matrix &M){
        for (unsigned int i = 0; i < M.size * M.size; ++i){
            mat[i] -= M.mat[i];
        }
        return *this;
    };

    friend Matrix operator+ (Matrix left, const Matrix &right){
        left += right;
        return left;
    };

    friend Matrix operator- (Matrix left, const Matrix &right){
        left -= right;
        return left;
    };

    T &operator[](const std::pair <unsigned int, unsigned int> &nm){
        return this->mat[nm.first * this->size + nm.second];
    };

    template <typename L>
    Matrix & operator *= (const L &l){
        for (unsigned int i = 0; i < size * size; ++i){
            mat[i] = (T) (mat[i] * l);
        }
        return *this;
    };

    template <typename L>
    friend Matrix operator* (Matrix left, const L &right){
        return (left *= right);
    };

    template <typename L>
    friend Matrix operator* (const L &left, Matrix right){
        return (right *= left);
    };

    Matrix &operator*= (const Matrix &M){
        T arr[size * size];
        for (unsigned int i = 0; i < size * size; ++i){
            arr[i] = proizv(*this, M, i / size, i % size);
        }
        for (unsigned int i = 0; i < size * size; ++i){
            mat[i] = arr[i];
        }
        return *this;
    };

    friend Matrix &operator* (Matrix left, const Matrix &right){
        return (left *= right);
    }

    T tr(){
        T sum;
        sum -= sum;
        for (unsigned int i = 0; i < size; ++ i){
            sum += mat[i * (size + 1)];
        }
        return sum;
    }

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

#endif // MATRIX_H_INCLUDED
