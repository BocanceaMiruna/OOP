#pragma once
#include <iostream>
class JsonValue {
public:
    virtual ~JsonValue() = 0;

    virtual void print(std::ostream& out) = 0;
};
class NullValue :public JsonValue {
public:
    void print(std::ostream&) override;
};
class NumberValue :public JsonValue {
    int Value;
public:
    NumberValue(int val);
    void print(std::ostream&)override;
};
class BoolValue :public JsonValue {
    bool Value;
public:
    BoolValue(bool val);
    void print(std::ostream&)override;
};
class StringValue :public JsonValue {
    char value[256];
public:
    StringValue(const char*val);
    void print(std::ostream&)override;
};
class ArrayValue :public JsonValue {
    JsonValue *Value[16];
    int cnt;
public:
    ArrayValue();
    ~ArrayValue()override;
    void print(std::ostream&)override;
    void add(JsonValue* val);
};
class ObjectValue :public JsonValue {
    struct Pair {
        char *name;
        JsonValue* value;
    };
    Pair pairs[16];
    int cnt;
public:
    ObjectValue();
    ~ObjectValue()override;
    void add(const char*name, JsonValue* val);
    void print(std::ostream&)override;
};