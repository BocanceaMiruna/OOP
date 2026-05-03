#include <iostream>
template <typename K,typename V>
class map {
public:
    struct element {
        K key;
        V value;
        int idx;
    };
private:
    element* data;
    int cap;
    int cnt;
    void resize(){
        cap *= 2;
        element* newdata = new element[cap];
        for (int i = 0; i < cnt; i++)
            newdata[i] = data[i];
        delete[] data;
        data = newdata;
    }
public:
    map() {
        cap = 10;
        cnt = 0;
        data = new element[cap];
    }
    ~map() {
        delete[] data;
    }
    V& operator[](const K& key) {
        for (int i = 0; i < cnt; i++)
            if (data[i].key == key)
                return data[i].value;
        if (cnt == cap)
           resize();
           data[cnt].key = key;
           data[cnt].idx = cnt; cnt++;
           return data[cnt - 1].value;
    }
    void Set(const K& key, const V& value) {
        (*this)[key] = value;
    }
    bool Get(const K& key, V& value)const {
        for(int i=0;i<cnt;i++)
            if (data[i].key == key) {
                value = data[i].key;
                return true;
            }
        return false;
    }
    int Count()const {
        return cnt;
    }
    void Clear() {
        cnt = 0;
    }
    bool Delete(const K& key) {
        for (int i = 0; i < cnt; i++)
            if (data[i].key == key) {
                for (int j = i; j < cnt - 1; j++) {
                    data[j] = data[j + 1];
                    data[j].idx = j;
                }
                cnt--;
                return true;
            }
       return false;
    }
    bool Includes(const map<K, V>& other)const {
        for (int i = 0; i < other.cnt; i++) {
            bool found = false;
            for (int j = 0; j < cnt; j++) {
                if (data[j].key == other.data[i].key) {
                    found = true;
                    break;
                }
            }
            if (!found)
                return false;
        }
        return true;
    }
    element* begin()const {
        return data;
    }
    element* end()const {
        return data + cnt;
    }
};
int main()
{
    map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}

