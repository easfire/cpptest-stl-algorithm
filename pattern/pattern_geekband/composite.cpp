#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

class Component
{
  public:
    virtual void process() = 0;
    virtual ~Component(){}
};

class Composite: public Component {
  string name;
  list<Component*> elements; //多态对象
  public:
  Composite(const string& s): name(s) {}

  void add(Component* element) {
    elements.push_back(element);
  }
  void remove(Component* element) {
    elements.remove(element);
  }

  void process() {
    //process current node
    cout << "process Composite current node. " << name << endl;

    // process leaf nodes
    for (auto& e: elements) {
      e->process();
    }
  }
};

class Leaf: public Component {
  string name;
  public:
  Leaf(string s): name(s) {}

  void process() {
    // process current node
    cout << "process Leaf current node. " << name << endl;

  }
};

void invoke(Component& c) {
  c.process();
}

int main()
{
  Composite root("root");
  Composite treeNode1("treeNode1");
  Composite treeNode2("treeNode2");
  Composite treeNode3("treeNode3");
  Composite treeNode4("treeNode4");

  Leaf left1("left1");
  Leaf left2("left2");

  root.add(&treeNode1);
  treeNode1.add(&treeNode2);
  treeNode2.add(&left1);

  root.add(&treeNode3);
  treeNode3.add(&treeNode4);
  treeNode4.add(&left2);

  root.process();
  cout << "---------" << endl;
  invoke(root);
}
