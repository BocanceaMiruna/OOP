#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
void bubble(vector<char*>& v){
    int n = v.size();
    bool ok;
    for (int i = 0; i < n - 1; i++) {
        ok = false;
        for (int j = 0; j < n - i - 1; j++) {
            bool ok2 = false;
            int x = strlen(v[j]);
            int y = strlen(v[j + 1]);

            if (x < y)
                ok2 = true;
            else if (x == y && strcmp(v[j], v[j + 1]) > 0)
                ok2 = true;
            if (ok2)
                swap(v[j], v[j + 1]),ok = true;
        }
        if (!ok)break;
    }
}
int main() {
    char p[1000];
    scanf_s("%[^\n]", p, 1000);
   // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<char*> cuv;
    char temp[100];
    int k = 0;
    for (int i = 0; p[i] != '\0'; i++) {
        if (p[i] != ' ')
            temp[k++] = p[i];
        else
            if (k > 0) {
                temp[k] = '\0';
                char* word = new char[k + 1];
                strcpy_s(word, k + 1, temp);
                cuv.push_back(word);
                k = 0;
            }
    }

    if (k > 0) {
        temp[k] = '\0';
        char* word = new char[k + 1];
        strcpy_s(word, k + 1, temp);
        cuv.push_back(word);
    }
    bubble(cuv);
    for (int i = 0; i < cuv.size(); i++) {
        printf("%s\n", cuv[i]);
        delete[] cuv[i];
    }
    return 0;
}