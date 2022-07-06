class House {
  // ...
};

class HouseBuilder {
  public:
    // 在C++ 不能写到纯虚函数调用，不能写在父类的构造函数内
    // 显然子类还没有override，如何调用
    void Init() {
      this->BuildPart1();

      for (int i = 0; i < 4; i++) {
        this->BuildPart2();
      }

      bool flag = this->BuildPart3();

      if (flag) {
        this->BuildPart4();
      }

      this->BuildPart5();
    }

    House* GetResult() {
      return pHouse;
    }

    virtual ~HouseBuilder(){}

  protected:
    House* pHouse;
    virtual void BuildPart1() = 0;
    virtual void BuildPart2() = 0;
    virtual void BuildPart3() = 0;
    virtual void BuildPart4() = 0;
    virtual void BuildPart5() = 0;
};

class StoneHouse: public House {
  protected:
    virtual void BuildPart1() {
      ...
    }
    virtual void BuildPart2() {}
    virtual void BuildPart3() {}
    virtual void BuildPart4() {}
    virtual void BuildPart5() {}

};

int main() 
{
  House* pHouse = new StoneHouse();
  pHouse->Init();
}
