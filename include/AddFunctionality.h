#ifndef CPP_TEMPLATE_ADDFUNCTIONALITY_H
#define CPP_TEMPLATE_ADDFUNCTIONALITY_H

template <typename T>
struct MathFunctions
{
    void scale(double multiplicator)
    {
        T& underlying = static_cast<T&>(*this);
        underlying.setValue(underlying.getValue() * multiplicator);
    }
    void square()
    {
        T& underlying = static_cast<T&>(*this);
        underlying.setValue(underlying.getValue() *
                            underlying.getValue());
    }
    void negate()
    {
        scale(-1);
    };

};


class IOVal : public MathFunctions<IOVal>{
public:

    IOVal() {
        val = 0.0;
    }
    double getValue() const {
      return val;
    };
    void setValue(double value){
        val = value;
    }

private:
    double val;

};


#endif //CPP_TEMPLATE_ADDFUNCTIONALITY_H
