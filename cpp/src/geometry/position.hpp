#include <math.h>

template <typename numeric>
class Position1D
{
protected:
    numeric x;

public:
    Position1D(numeric x) : x(x){};
    ~Position1D() { delete &x; };
    inline numeric GetX() const { return x; }
    inline void IncreaseX(numeric increment) { x += increment; }
    inline void DecreaseX(numeric increment) { x -= increment; }
    inline numeric ComputeAbsoluteDistance(const Position1D &pos) const
    {
        return abs(ComputeDistance(pos));
    }
    inline numeric ComputeDistance(const Position1D &pos) const
    {
        return GetX() - pos.GetX();
    }
};

template <typename numeric>
class Position2D : public Position1D<numeric>
{
protected:
    numeric y;

public:
    Position2D(numeric x, numeric y) : Position1D<numeric>(x), y(y){};
    ~Position2D() { delete &y; };
    inline numeric GetY() const { return y; };
    inline numeric ComputeDistance(const Position2D &pos) const
    {
        numeric x_term = (this.GetX() - pos.GetX()) * (this.GetX() - pos.GetX());
        numeric y_term = (GetY() - pos.GetY()) * (GetY() - pos.GetY());
        return sqrt(x_term + y_term);
    }
};
