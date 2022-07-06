//多继承，推荐Form主继承类（datas+funcs）IProgress 接口类(funcs),避免数据的嵌套
class MainForm : public Form, public IProgress
{
  TextBox* txtFilePath;
  TextBox* txtFileNumber;

  ProgressBar* progressBar;

  public:
  void Button1_Click() {
    string filePath = txtFilePath->getText();
    int number = atoi(txtFileNumber->getText().c_str());

    ConsoleNotifier cn;

    FileSplitter splitter(filePath, number, this);

    splitter.addIProgress(this);
    splitter.addIProgress(&cn);

    splitter.split();

    splitter.removeIProgress(this);
  }

  virtual void DoProgress(float value) {
    progressBar->setValue(value);
  }
};

class ConsoleNotifier : public IProgress {
  public:
    virtual void DoProgress(float value) {
      cout << "." 
    }
}

class IProgress {
  public:
    virtual void DoProgress(float value) = 0;
    virtual ~IProgress(){}
}

// FileSplitter 和 progressBar组件解耦合了。
class FileSplitter
{
  string m_filePath;
  int m_fileNumber;

  // ProgressBar* m_progressBar;  // 具体通知控件
  list<IProgress*> m_iprogressList;       // 抽象通知机制, 支持多个观察者 

  public:
  FileSplitter(const string& filePath, int fileNumber) :
    m_filePath(filePath),
    m_fileNumber(fileNumber) {

    }

  void split() {
    //1, 读文件

    //2, 分批次向小文件里写数据
    for (int i = 0; i< m_fileNumber; i++) {
      float progressValue = m_fileNumber;
      progressValue = (i + 1) / progressValue;
      onProgress(progressValue);
    }
  }

  void addIProgress(IProgress* iprogress) {
    m_iprogressList.push_back(iprogress);
  }

  void removeIProgress(IProgress* iprogress) {
    m_iprogressList.remove(iprogress);
  }

  protected:
  void onProgress(float value) {

    list<IProgress*>::Iterator itor = m_iprogressList.begin();

    for (; itor != m_iprogressList.end(); ++itor) {
      m_iprogress->DoProgress(value); // 更新进度条           
    }
  }
};
