#include "Canva.h"
#include <iostream>
Canvas::Canvas(int width, int height) {
	this->width = width;
	this->height = height;
	mat = new char* [height];
	for (int i = 0; i < height; i++) {
		mat[i] = new char[width];
		for (int j = 0; j < width; j++)
			mat[i][j] = ' ';
	}
}
void Canvas::Clear() {
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			mat[i][j] = ' ';
}
void Canvas::Print() {
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			std::cout << mat[i][j];
	std::cout << "\n";
}
void Canvas::SetPoint(int x, int y, char ch) {
	if (x >= 0 && x < width && y >= 0 && y < height)
		mat[y][x] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
	int dx = abs(x2 - x1);
	int dy = -abs(y2 - y1);
	int sx = x1 < x2 ? 1 : -1;
	int sy = y1 < y2 ? 1 : -1;
	int err = dx + dy;
	while (1) {
		SetPoint(x1, y1, ch);
		int e2 = 2 * err;
		if (e2 >= dy) {
			if (x1 == x2) break;
			err += dy;
			x1 += sx;
		}
		if (e2 <= dx) {
			if (y1 == y2) break;
			err += dx;
			y1 += sy;
		}
	}
}
void Canvas::DrawCircle(int x, int y, int ray, char ch) {
	int c = 0;
	int r = ray;
	int d = 3 - 2 * ray;
	while (r >= c) {
		SetPoint(x + c, y + r, ch);
		SetPoint(x - c, y + r, ch);
		SetPoint(x + c, y - r, ch);
		SetPoint(x - c, y - r, ch);
		SetPoint(x + r, y + c, ch);
		SetPoint(x - r, y + c, ch);
		SetPoint(x + r, y - c, ch);
		SetPoint(x - r, y - c, ch);
		if (d <= 0)
			d = d + 4 * c + 6;
		else {
			d = d + 4 * (c - r) + 10;
			r--;
		}
		c++;
	}
}
void Canvas::FillCircle(int x, int y, int ray, char ch) {
	int c = 0;
	int r = ray;
	int d = 3 - 2 * ray;
	while (r >= c) {
		for (int i = x - c; i <= x + c; i++) {
			SetPoint(i, y + r, ch);
			SetPoint(i, y - r, ch);
		}
		for (int i = x - r; i <= x + r; i++) {
			SetPoint(i, y + c, ch);
			SetPoint(i, y - c, ch);
		}
		if (d <= 0)
			d = d + 4 * c + 6;
		else {
			d = d + 4 * (c - r) + 10;
			r--;
		}
		c++;
	}
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
	for (int x = left; x <= right; x++) 
		SetPoint(x, top, ch);
	for (int x = left; x <= right; x++)
		SetPoint(x, bottom, ch);
	for (int y = top; y <= bottom; y++)
		SetPoint(left, y, ch);
	for (int y = top; y <= bottom; y++)
		SetPoint(right, y, ch);
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
	for (int y = top; y <= bottom; y++) {
		for (int x = left; x <= right; x++) {
			SetPoint(x, y, ch);
		}
	}
}