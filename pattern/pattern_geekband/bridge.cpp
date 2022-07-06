// bridge

class Messager {
  protected:
    MessagerImp* messagerImp;
  public:
    Messager(MessagerImp* msgImp) : messagerImp(msgImp) {}

    // 交互型接口
    virtual void Login(string username, string password) = 0;
    virtual void SendMessage(string message) = 0;
    virtual void SendPicture(Image image) = 0;

    virtual ~Message(){}
};

class MessagerImp {
  public:
    // 底层接口
    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;
    virtual void Connect() = 0;

    virtual ~MessagerImp(){}
};

class PCMessagerImp : public MessagerImp {
  public:
    virtual void PlaySound() {
      // ....
    }
    virtual void DrawShape() {
      // ....
    }
    virtual void WriteText() {
      // ....
    }
    virtual void Connect() {
      // ....
    }
};

class MobileMessageImp : public MessagerImp {
  public:
    virtual void PlaySound() {
      // ....
    }
    virtual void DrawShape() {
      // ....
    }
    virtual void WriteText() {
      // ....
    }
    virtual void Connect() { 
      // ....
    }
};

class MessagerLite : public Messager {

  public:
    virtual void Login(string username, string password) {
      messagerImp->Connect();
      // ...
    }
    virtual void SendMessage(string message) {
      messagerImp->WriteText();
      // ...
    }
    virtual void SendPicture(Image image) {
      messagerImp->DrawShape();
      // ...
    }
};

class MessagerPerfect : public Messager {

  public:
    virtual void Login(string username, string password) {
      messagerImp->PlaySound();
      // ***
      messagerImp->Connect();
      // ...
    }
    virtual void SendMessage(string message) {
      messagerImp->PlaySound();
      // ***
      messagerImp->WriteText();
      // ...
    }
    virtual void SendPicture(Image image) {
      messagerImp->PlaySound();
      // ***
      messagerImp->DrawShape();
      // ...
    }
};

void Process() {
  MessagerImp* mImp = new PCMessagerImp();
  Messager* m = new Messager(mImp);
  MessagerLite* mPcLite = new MessagerLite(m);
}
