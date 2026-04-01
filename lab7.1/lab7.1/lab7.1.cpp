#include <iostream>
constexpr float operator""_Kelvin(unsigned long long val) {
    return static_cast<float>(val) - 273.15f;
}
constexpr float operator""_Fahrenheit(unsigned long long val) {
    return static_cast<float>((val)-32) / 1.8f;
}
int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    std::cout << a << " " << b;
    return 0;
}
