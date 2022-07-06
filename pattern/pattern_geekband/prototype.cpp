//具体类
class BinarySplitter : public ISplitter
{
  public:
    void split() {
      //...
    }
    virtual ISplitter* clone() {
      return new BinarySplitter(*this);
    }
};

class TxtSplitter : public ISplitter
{
  public:
    virtual ISplitter* clone() {
      return new TxtSplitter(*this);
    }
};

class PictureSplitter : public ISplitter
{
  public:
    virtual ISplitter* clone() {
      return new PictureSplitter(*this);
    }
};

class VideoSplitter : public ISplitter
{
  public:
    virtual ISplitter* clone() {
      return new VideoSplitter(*this);
    }
};


// ① 基类 和 工厂基类 合二为一
// 基类
class ISplitter {
  public:
    virtual void split() = 0;
    virtual ISplitter* clone() = 0;  // 通过克隆自己来创建对象

    virtual ~ISplitter() {}
};


// Factory methods// MainForm 没有具体类的依赖
class MainForm : public Form
{
  ISplitter* prototype;  // 原型对象

  public:

  MainForm(ISplitter* prototype) {
    this->prototype = prototype;
  }

  void Button1_Click() {

    ISplitter* splitter =               
      prototype->clone(); // 克隆原型

    splitter->split();
  }
};
