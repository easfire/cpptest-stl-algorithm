// 具体类
class BinarySplitter : public ISplitter
{
  public:
    void split() {
      ...
    }
};

class TxtSplitter : public ISplitter
{};

class PictureSplitter : public ISplitter
{};

class VideoSplitter : public ISplitter
{};

// 具体工厂
BinarySplitterFatory: public SplitterFactroy {
                        public:
                          virtual ISplitter* CreateSplitter() {
                            return new BinarySplitter();
                          }
                      };

TxtSplitterFatory: public SplitterFactroy {
                     public:
                       virtual ISplitter* CreateSplitter() {
                         return new TxtSplitter();
                       }
                   };
//....

// 基类
class ISplitter {
  public:
    virtual void split() = 0;
    virtual ~ISplitter() {}
};

// 工厂基类
class SplitterFactroy {
  public:
    virtual ISplitter* CreateSplitter() = 0;  // 虚函数延时绑定
    virtual ~SplitterFactroy(){}
};


// Factory methods// MainForm 没有具体类的依赖
class MainForm : public Form
{
  SplitterFactroy* factory;  // 工厂

  public:

  MainForm(SplitterFactroy* factory) {
    this->factory = factory;
  }

  void Button1_Click() {

    ISplitter* splitter =               
      factory->CreateSplitter(); // 多态new

    splitter->split();
  }
};
