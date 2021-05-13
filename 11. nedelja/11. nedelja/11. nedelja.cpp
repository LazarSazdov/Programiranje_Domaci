#include <iostream>
#include <list>
#include "dinstring.hpp"
class  Component {
protected:
    double X;
    double Y;
public:
    double getX()const { return X; }
    double getY()const { return Y; }
    virtual void printComponent() {
        std::cout << "X je : " << X << std::endl;
        std::cout << "Y je : " << Y << std::endl;
    }
    virtual DinString getTypeName() = 0;
};
class CheckBox : public Component {
private:
    bool Pressed;
    static DinString typeName;
public:
    CheckBox() {
        X = 0;
        Y = 0;
        Pressed = false;
    }
    CheckBox(double x, double y, bool pressed) {
        X = x;
        Y = y;
        Pressed = pressed;
    }
    DinString getTypeName() {
        return typeName;
    }

    void printComponent() {
        std::cout << "X je : " << X << std::endl;
        std::cout << "Y je : " << Y << std::endl;
        std::cout << "Pressed = ";
        if (Pressed) {std::cout << "TRUE" << std::endl;}
        else{ std::cout << "FALSE" << std::endl;}
    }
};
DinString CheckBox::typeName = "CheckBox";
class Label : public Component {
private:
    DinString text;
    static DinString typeName;
public:
    Label() {
        X = 0;
        Y = 0;
        text = "";
    }
    Label(double x_, double y_, DinString text_) {
        X = x_;
        Y = y_;
        text = text_;
    }
    DinString getTypeName() {return typeName;}
    void printComponent() {std::cout << text << std::endl;}
    DinString getText()const { return text;}
    void setText(DinString text_) {text = text_;}
};
DinString Label::typeName = "Label";
class Panel : public Component {
private:
    static DinString typeName;
    int capacity;
    std::list<Component*> components;
public:
    Panel() {capacity = 10;}
    Panel(Panel& panel) { capacity = panel.capacity; components = panel.components; }
    DinString getTypeName() {return typeName;}
    void printComponent() {
        std::list<Component*> ::iterator it = components.begin();
        for (int i = 0; it != components.end(); it++, i++) {
            (*it)->Component::printComponent();
        }
    }
    int getCapacity()const {return capacity;}
    void setCapacity(int cap) {capacity = cap;}
    bool addComponent(Component& component) { components.push_back(&component);  return true; }
    bool removeComponent(int pozicija) {
        std::list<Component*> ::iterator it = components.begin();
        for (int i = 0; i < capacity; it++, i++) {
            if (i == pozicija) {
                components.erase(it);
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};
DinString Panel::typeName = "Panel";
int main()
{
    CheckBox traktor;
    cout << traktor.getX()<< std::endl;
    Label aaaa;
    Panel sa;
    aaaa.setText("neki text");
    aaaa.printComponent();
    std::cout << aaaa.getTypeName() << std::endl;
    cout << sa.addComponent(aaaa) << std::endl;
    sa.printComponent();
}
