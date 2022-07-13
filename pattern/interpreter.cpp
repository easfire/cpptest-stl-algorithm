//interpreter
#include <iostream>
#include <map>
#include <stack>

using namespace std;

class Expression {
  public:
    virtual int interpreter(map<char, int> var) = 0;
    virtual ~Expression(){}
};

//变量表达式
class VarExpression: public Expression {
  char key;

  public:
  VarExpression(const char& k): key(k){};

  int interpreter(map<char, int> var) override {
    return var[key];
  }
};

// 符号表达式
class SymbolExpression: public Expression {
  // 运算符左右两个参数
  protected:
    Expression* left;
    Expression* right;

  public:
    SymbolExpression(Expression* l, Expression* r):
      left(l), right(r) {}
};

// 加法运算
class AddExpression: public SymbolExpression {
  public:
    AddExpression(Expression* l, Expression* r):
      SymbolExpression(l, r) {}

    int interpreter(map<char, int> var) override {
      return left->interpreter(var) + right->interpreter(var);
    }
};

// 减法运算
class SubExpression: public SymbolExpression {
  public:
    SubExpression(Expression* l, Expression* r): 
      SymbolExpression(l, r) {}

    int interpreter(map<char, int> var) override {
      return left->interpreter(var) - right->interpreter(var);
    }
};

Expression* analyse(string expStr) {
  stack<Expression*> expStack;

  Expression* left  = nullptr;
  Expression* right = nullptr;

  for (int i=0; i < expStr.size(); i++) {
    switch(expStr[i])
    {
      case '+':
        left = expStack.top();
        right = new VarExpression(expStr[++i]);
        expStack.push(new AddExpression(left, right));
        break;
      case '-':
        left = expStack.top();
        right = new VarExpression(expStr[++i]);
        expStack.push(new SubExpression(left, right));
        break;
      default:
        // 变量表达式
        expStack.push(new VarExpression(expStr[i]));
    }
  } 

  Expression* expression = expStack.top();

  return expression;
}

void release(Expression* expression) {

}

int main()
{
  string expStr = "a+b-c+d-e";
  map<char, int> var;

  var.insert(make_pair('a', 5));
  var.insert(make_pair('b', 2));
  var.insert(make_pair('c', 1));
  var.insert(make_pair('d', 6));
  var.insert(make_pair('e', 3));

  Expression* expression = analyse(expStr);

  int result = expression->interpreter(var);

  cout << result << endl;

  release(expression);

  return 0;   
}

