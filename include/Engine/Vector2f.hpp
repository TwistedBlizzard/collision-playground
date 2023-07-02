#ifndef VECTOR2F_H
#define VECTOR2F_H

#include <cmath>

struct Vector2f
{
    float x;
    float y;

    Vector2f() :
    x(0.0f),
    y(0.0f)
    {}

    Vector2f(float initX, float initY) :
    x(initX),
    y(initY)
    {}

    float Magnitude()
    {
        float a(x * x);
        float b(y * y);

        return float(sqrt(a + b));
    }

    float Distance(Vector2f const &other)
    {
        Vector2f vector;

        vector.x = other.x - x;
        vector.y = other.y - y;

        return vector.Magnitude();
    }

    Vector2f Normal()
    {
        float magnitude = Magnitude();
        if (!magnitude)
            return Vector2f();

        Vector2f vector;

        vector.x = x / magnitude;
        vector.y = y / magnitude;

        return vector;
    }

    Vector2f Toward(Vector2f const &other)
    {
        Vector2f vector;

        vector.x = other.x - x;
        vector.y = other.y - y;

        return vector.Normal();
    }

    Vector2f operator+(Vector2f const &other)
    {
        Vector2f vector;

        vector.x = x + other.x;
        vector.y = y + other.y;

        return vector;
    }

    Vector2f operator+=(Vector2f const &other)
    {
        x += other.x;
        y += other.y;

        return *this;
    }

    Vector2f operator-(Vector2f const &other)
    {
        Vector2f vector;

        vector.x = x - other.x;
        vector.y = y - other.y;

        return vector;
    }

    Vector2f operator-=(Vector2f const &other)
    {
        x -= other.x;
        y -= other.y;

        return *this;
    }
};

#endif