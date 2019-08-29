#pragma once

class Parent;

#define DISALLOW_COPY(Typename) \
    Typename(const Typename&) = delete;

#define DISALLOW_ASSIGN(Typename) \
    Typename& operator=(const Typename&) = delete;

#define DISALLOW_COPY_AND_ASSIGN(Typename) \
    DISALLOW_COPY(Typename) \
    DISALLOW_ASSIGN(Typename)

// case 1: Parent take care of Child
// case 2: Parent and Child are Dependent
// case 3:

class Child{
public:
    Child(Parent* parent) : parent_(parent){}
DISALLOW_COPY_AND_ASSIGN(Child)
private:
    Parent *parent_;
    // Child(Child&) =delete;
    // Child& operator=(Child&) = delete;
};


class Parent{
public:
private:
    //std::scoped_ptr<Child> child;
    // Parent(Parent&) =delete;
    // Parent& operator=(Parent&) = delete;
};