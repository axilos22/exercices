#include <math.h>

template <typename numeric>
class CartesianPosition1D
{
protected:
    numeric x;

public:
    CartesianPosition1D(numeric x) : x(x){};
    ~CartesianPosition1D() { delete &x; };
    inline numeric GetX() const { return x; }
    inline void IncreaseX(const numeric amount) { x += amount; }
    inline void DecreaseX(const numeric amount) { x -= amount; }
    inline numeric ComputeAbsoluteDistance(const CartesianPosition1D &pos) const
    {
        return abs(ComputeDistance(pos));
    }
    inline numeric ComputeDistance(const CartesianPosition1D &pos) const
    {
        return GetX() - pos.GetX();
    }
};

template <typename numeric>
class CartesianPosition2D : public CartesianPosition1D<numeric>
{
protected:
    numeric y;

public:
    CartesianPosition2D(numeric x, numeric y) : CartesianPosition1D<numeric>(x), y(y){};
    ~CartesianPosition2D() { delete &y; };
    inline numeric GetY() const { return y; };
    inline numeric ComputeDistance(const CartesianPosition2D &pos) const
    {
        numeric x_term = (this.GetX() - pos.GetX()) * (this.GetX() - pos.GetX());
        numeric y_term = (GetY() - pos.GetY()) * (GetY() - pos.GetY());
        return sqrt(x_term + y_term);
    }
};
