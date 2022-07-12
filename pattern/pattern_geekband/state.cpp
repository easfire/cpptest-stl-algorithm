
//接口函数变为状态对象的行为。
class NetworkState {
  public:
    NetworkState* pNext;
    virtual void Operation1() = 0;
    virtual void Operation2() = 0;
    virtual void Operation3() = 0;

    virtual ~NetworkState(){}
}; 

// ① 单个状态对象，用singleton模式
// ② 新增状态，只需要扩展子类

class OpenState: public NetworkState {
  static NetworkState* m_instance;
  public:
  static NetworkState* getInstance() {
    if (m_instance == nullptr) {
      m_instance = new OpenState();
    }
    return m_instance;
  }

  void Operation1() {
    // ***
    pNext = CloseState::getInstance();
  }

  void Operation2() {
    // ...
    pNext = ConnectState::getInstance();
  }

  void Operation3() {
    // xxx
    pNext = OpenState::getInstance();
  }
};

class CloseState: public NetworkState {
  static NetworkState* m_instance;
  public:
  static NetworkState* getInstance() {
    if (m_instance == nullptr) {
      m_instance = new CloseState();
    }
    return m_instance;
  }

  void Operation1() {
    // ***
    pNext = OpenState::getInstance();
  }

  void Operation2() {
    // ...
    pNext = ConnectState::getInstance();
  }

  void Operation3() {
    // ***
    pNext = CloseState::getInstance();
  }
};

class ConnectState: public NetworkState {
  static NetworkState* m_instance;
  public:
  static NetworkState* getInstance() {
    if (m_instance == nullptr) {
      m_instance = new ConnectState();
    }
    return m_instance;
  }

  void Operation1() {
    // ***
    pNext = OpenState::getInstance();
  }

  void Operation2() {
    // ...
    pNext = CloseState::getInstance();
  }

  void Operation3() {
    // xxx
    pNext = ConnectState::getInstance();
  }
};

// 从一个起始状态开始
class NetworkProcessor {
  NetworkState* pState;

  public:
  NetworkProcessor(NetworkState* pSt): pState(pSt){}

  void Operation1() {
    // ...
    pState->Operation1();
    pState = pState->pNext;
    // ...
  }

  void Operation2() {
    // ...
    pState->Operation2();
    pState = pState->pNext;
    // ...
  }

  void Operation3() {
    // ...
    pState->Operation3();
    pState = pState->pNext;
    // ...
  }
};

