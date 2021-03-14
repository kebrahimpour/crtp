#ifndef CRTP_SIMPLEEXAMPLE_H
#define CRTP_SIMPLEEXAMPLE_H
template <typename D>
class InterfaceClass{
public:
    void doSomething(){
        this->interface()->doSomewthing();
    }
private:
    // force correct usage by private C'Tor: class Derived1 : public InterfaceClass<Derived1> ...
    InterfaceClass() {};  // this makes class Derived2 : public InterfaceClass<Derived1> fail to compile BUT
    friend D;   // then we need Derived class need access to private C'tor
    D * interface(){
        static_cast<D*>(this);
    }
};
// Note: Derived class doesn't have a "is a" relation to the base class
// as one would expect when inheritance is used
// here the derived class *expands*  the interface by adding more functionality
// AND it is used directly as oposed to the usual inheritance (including static polymorphism)
// scheme where the base class exposes the interface and redirects calls to the derived class

class D1: InterfaceClass<D1>{  // Derived class offers the interface of InterfaceClass
public:
    void doSomething(){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};
#endif //CRTP_SIMPLEEXAMPLE_H


