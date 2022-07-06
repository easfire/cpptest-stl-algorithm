//抽象基类
class House {
  // ...
};

// 抽象基类
class HouseBuilder {
  public:
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

};

class StoneHouseBuilder: public HouseBuilder {
  protected:
    virtual void BuildPart1() {
      ...
    }
    virtual void BuildPart2() {}
    virtual void BuildPart3() {}
    virtual void BuildPart4() {}
    virtual void BuildPart5() {}

};


// 稳定的类实现
class HouseDirector {
  public:
    HouseBuilder* pHouseBuilder;

    HouseDirector(HouseBuilder* pHB) : pHouseBuilder(pHB){}

    House* Construct() {
      pHouseBuilder->BuildPart1();

      for (int i = 0; i < 4; i++) {
        pHouseBuilder->BuildPart2();
      }

      bool flag = pHouseBuilder->BuildPart3();

      if (flag) {
        pHouseBuilder->BuildPart4();
      }

      pHouseBuilder->BuildPart5();

      return pHouseBuilder->GetResult();
    }
};

int main() 
{
  HouseBuilder* pHb = new StoneHouseBuilder();
  House* pHouse = new HouseDirector(pHb);
}
