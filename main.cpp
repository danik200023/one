#include <iostream>

struct Vector {
    int* mData;
    size_t mSize;
    size_t mCapacity;

    size_t size() const {
        return mSize;
    }

    bool empty() const {
        return mSize == 0;
    }

    void clear() {
        mSize = 0;
    }

    void reserve(const size_t new_cap) {
        if (new_cap > mCapacity) {
            int* newData = new int[new_cap];
            memcpy(newData, mData, mCapacity * sizeof(int));
            mCapacity = new_cap;
            std::swap(mData, newData);
            delete[] newData;
        }
    }

    int& operator[](const size_t& index) const {
        return mData[index];
    }

    Vector& operator=(Vector other) {
        swap(other);
        return *this;
    }

    Vector() : mData(nullptr), mSize(0), mCapacity(0) {}

    explicit Vector(const size_t count) : mData(new int[count]), mSize(count), mCapacity(count) {}

    Vector(const size_t count, const int& value) : mData(new int[count]), mSize(count), mCapacity(count) {
        for (size_t i = 0; i < mSize; i++) {
            mData[i] = value;
        }
    }

    Vector(const Vector& other) : mData(new int[other.mCapacity]), mSize(other.mSize), mCapacity(other.mCapacity) {
        memcpy(mData, other.mData, mSize * sizeof(int));
    }

    Vector(const std::initializer_list<int> lst) : mData(new int[lst.size()]), mSize(lst.size()), mCapacity(lst.size()) {
        std::copy(lst.begin(), lst.end(), mData);
    }

    ~Vector() {
        delete[] mData;
    }

    void swap(Vector& other) {
        std::swap(mData, other.mData);
        std::swap(mSize, other.mSize);
        std::swap(mCapacity, other.mCapacity);
    }

    void push_back(const int& value) {
        if (mSize == mCapacity) {
            if (mCapacity == 0) {
                reserve(1);
            } else {
                reserve(mCapacity * 2);
            }
        }
        mData[mSize++] = value;
    }
};

int main() {
    std::vector<int> vec(4);

    std::cout << vec[0] << vec[1] << vec[2] << std::endl;
}