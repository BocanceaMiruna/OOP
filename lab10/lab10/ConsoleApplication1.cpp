#include <iostream>
#include <exception>
using namespace std;

class IndexOutOfBoundsException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Index invalid";
    }
};

class InvalidCapacityException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Capacitatea trebuie sa fie pozitiva";
    }
};

class Compare {
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator {
    int current;
    T** list;
    int size;

public:
    ArrayIterator() {
        this->current = 0;
        this->list = nullptr;
        this->size = 0;
    }

    ArrayIterator(T** l, int start, int s) {
        this->list = l;
        this->current = start;
        this->size = s;
    }

    ArrayIterator& operator ++() {
        current++;
        return *this;
    }

    ArrayIterator& operator--() {
        current--;
        return *this;
    }
    bool operator=(const ArrayIterator<T>& other) {
        this->current = other.current;
        this->list = other.list;
        this->size = other.size;
        return true;
    }

    bool operator !=(const ArrayIterator<T>& other) const {
        return this->current != other.current;
    }

    T* GetElement() {
        if (current >= 0 && current < size)
            return list[current];
        return nullptr;
    }
};

template<class T>
class Array {
private:
    T** list;
    int capacity;
    int size;

    void Resize() {
        int newcapacity = (capacity == 0) ? 4 : capacity * 2;
        T** newlist = new T * [newcapacity];
        for (int i = 0; i < size; i++)
            newlist[i] = list[i];
        delete[] list;
        list = newlist;
        capacity = newcapacity;
    }

public:
    Array() : list(nullptr), capacity(0), size(0) {}

    Array(int cap) {
        if (cap < 0) throw InvalidCapacityException();
        capacity = cap;
        size = 0;
        list = new T * [capacity];
    }

    Array(const Array<T>& otherArray) {
        capacity = otherArray.capacity;
        size = otherArray.size;
        list = new T * [capacity];
        for (int i = 0; i < size; i++)
            list[i] = new T(*(otherArray.list[i]));
    }

    ~Array() {
        for (int i = 0; i < size; i++) {
            delete list[i];
        }
        delete[] list;
    }

    T& operator[] (int index) {
        if (index < 0 || index >= size) {
            throw IndexOutOfBoundsException();
        }
        return *(list[index]);
    }

    const Array<T>& operator+=(const T& newElem) {
        if (size >= capacity) Resize();
        list[size] = new T(newElem);
        size++;
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElem) {
        if (index < 0 || index > size) throw IndexOutOfBoundsException();
        if (size >= capacity) Resize();

        for (int i = size; i > index; i--)
            list[i] = list[i - 1];
        list[index] = new T(newElem);
        size++;
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T> otherArray) {
        if (index < 0 || index > size) throw IndexOutOfBoundsException();

        while (size + otherArray.size > capacity)
            Resize();
        for (int i = size - 1; i >= index; i--)
            list[i + otherArray.size] = list[i];
        for (int i = 0; i < otherArray.size; i++)
            list[index + i] = new T(*(otherArray.list[i]));
        size += otherArray.size;
        return *this;
    }

    const Array<T>& Delete(int index) {
        if (index < 0 || index >= size) throw IndexOutOfBoundsException();
        delete list[index];
        for (int i = index; i < size - 1; i++) {
            list[i] = list[i + 1];
        }
        size--;
        return *this;
    }

    bool operator=(const Array<T>& otherArray) {
        if (this == &otherArray) return true;

        for (int i = 0; i < size; i++) delete list[i];
        delete[] list;

        capacity = otherArray.capacity;
        size = otherArray.size;
        list = new T * [capacity];
        for (int i = 0; i < size; i++) {
            list[i] = new T(*(otherArray.list[i]));
        }
        return true;
    }

    void Sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (*(list[j]) > *(list[j + 1])) {
                    swap(list[j], list[j + 1]);
                }
            }
        }
    }

    void Sort(int(*compare)(const T&, const T&)) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (compare(*(list[j]), *(list[j + 1])) > 0) {
                    swap(list[j], list[j + 1]);
                }
            }
        }
    }

    void Sort(Compare* comparator) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (comparator->CompareElements(list[j], list[j + 1]) > 0) {
                    swap(list[j], list[j + 1]);
                }
            }
        }
    }

    int BinarySearch(const T& elem) {
        int l = 0, r = size - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (*(list[mid]) == elem) return mid;
            if (*(list[mid]) < elem) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
        int l = 0, r = size - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int cmp = compare(*(list[mid]), elem);
            if (cmp == 0) return mid;
            if (cmp < 0) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, Compare* comparator) {
        int l = 0, r = size - 1;
        T elemCopy = elem;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int cmp = comparator->CompareElements(list[mid], &elemCopy);
            if (cmp == 0) return mid;
            if (cmp < 0) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }

    int Find(const T& elem) {
        for (int i = 0; i < size; i++) {
            if (*(list[i]) == elem) return i;
        }
        return -1;
    }

    int Find(const T& elem, int(*compare)(const T&, const T&)) {
        for (int i = 0; i < size; i++) {
            if (compare(*(list[i]), elem) == 0) return i;
        }
        return -1;
    }

    int Find(const T& elem, Compare* comparator) {
        T elemCopy = elem;
        for (int i = 0; i < size; i++) {
            if (comparator->CompareElements(list[i], &elemCopy) == 0) return i;
        }
        return -1;
    }

    int GetSize() { return size; }
    int GetCapacity() { return capacity; }

    ArrayIterator<T> GetBeginIterator() {
        return ArrayIterator<T>(list, 0, size);
    }

    ArrayIterator<T> GetEndIterator() {
        return ArrayIterator<T>(list, size, size);
    }
};

int main() {
    try {
        Array<int> arr(3);

        arr += 30;
        arr += 10;
        arr += 50;
        arr += 20;
        arr += 40;
        ArrayIterator<int> it = arr.GetBeginIterator();
        ArrayIterator<int> endIt = arr.GetEndIterator();

        while (it != endIt) {
            cout << *(it.GetElement()) << " ";
            ++it;
        }
        cout << "\nDimensiune: " << arr.GetSize() << ", Capacitate: " << arr.GetCapacity() << endl;

        arr.Sort();
        cout << "sortare: ";

        it = arr.GetBeginIterator();
        while (it != endIt) {
            cout << *(it.GetElement()) << " ";
            ++it;
        }
        cout << endl;

        cout << "Index 20: " << arr.Find(20) << endl;
        cout << "Index 40 BinarySearch: " << arr.BinarySearch(40) << endl;
        cout << "Index 100 Inexistent: " << arr.Find(100) << endl;

        arr.Delete(2);
        cout << "stergere: " << arr[2] << endl;

    }
    catch (const std::exception& e) {
        cout << "Eroare neasteptata: " << e.what() << endl;
    }
    try {
        cout << "Array cu capacitate -5" << endl;
        Array<int> badArr(-5);
    }
    catch (const std::exception& e) {
        cout << "Exceptie prinsa corect: " << e.what() << endl;
    }

    try {
        cout << "accesare index 100..." << endl;
        Array<int> arr2(5);
        arr2 += 1;
        cout << arr2[100] << endl;
    }
    catch (const std::exception& e) {
        cout << "Exceptie prinsa corect: " << e.what() << endl;
    }

    try {
        cout << "stergere index negativ (-1)..." << endl;
        Array<int> arr3(5);
        arr3 += 1;
        arr3.Delete(-1);
    }
    catch (const std::exception& e) {
        cout << "Exceptie prinsa corect: " << e.what() << endl;
    }

    return 0;
}