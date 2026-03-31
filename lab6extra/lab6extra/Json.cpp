#include "Json.h"
#include "cstring"
#include <iostream>
JsonValue::~JsonValue() {}
void NullValue::print(std::ostream& out) {
	out << "null";
}
NumberValue::NumberValue(int val) :Value(val) {}
void NumberValue::print(std::ostream& out) {
	out << Value;
}
BoolValue::BoolValue(bool val):Value(val){}
void BoolValue ::print(std::ostream& out) {
	if (Value == 1)
		out << "true";
	else out << "false";
}
StringValue::StringValue(const char* val) {
	if (val != nullptr) {
		strcpy_s(value, 255, val);
		value[255] = '\0';
	}
	else value[0] = '\0';
}
void StringValue::print(std::ostream& out) {
	out << '"' << value << '"';
}
ArrayValue::ArrayValue():cnt(0){}
ArrayValue::~ArrayValue() {
	for (int i = 0; i < cnt; i++)
		delete Value[i];
}
void ArrayValue::add(JsonValue* val) {
	if (cnt < 16)
		Value[cnt++] = val;
}
void ArrayValue::print(std::ostream& out) {
	out << "[";
	for (int i = 0; i < cnt; i++) {
		Value[i]->print(out);
		if (i < cnt - 1)
			out << ',';
	}
	out << "]";
}
ObjectValue::ObjectValue():cnt(0){}
ObjectValue::~ObjectValue() {
	for (int i = 0; i < cnt; i++) {
		delete pairs[i].value;
		delete pairs[i].name;
	}
}
void ObjectValue::add(const char* name, JsonValue * val) {
	if (cnt < 16) {
		if (name != nullptr) {
			int len = strlen(name);
			pairs[cnt].name = new char[len+1];
			strcpy_s(pairs[cnt].name, len+1, name);
		}
		else {
			pairs[cnt].name = new char[1];
			pairs[cnt].name[0] = '\0';
		}
		pairs[cnt].value = val;
		cnt++;
	}
	else
		delete val;
}
void ObjectValue::print(std::ostream& out) {
	out << "{";
	for (int i = 0; i < cnt; i++) {
		out << '"'<<pairs[i].name << "\":";
		pairs[i].value->print(out);
		if (i < cnt - 1)
			out << ',';
	}
	out << "}";
}