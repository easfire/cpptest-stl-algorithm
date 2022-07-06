// Purpose.  Observer design pattern demo
// // 
// // Discussion.  Decouple the independent object from the dependent
// // objects.  Dependent objects (Views) register themselves with the
// // independent object (Model).  Then when the Model changes, it broadcasts
// // that fact to all registered Views, and each in turn queries the Model
// // for the information it is responsible for displaying.
//
#include <iostream>

using namespace std;

class View;

class Model {
  public:
    Model()                  { totalViews_ = 0; }
    void attach( View* v)    { views_[totalViews_++] = v; }
    int  getState()          { return state_; }
    void setState( int val ) { state_ = val; notify(); }
    void notify();
  private:
    int    state_;
    View*  views_[10];
    int    totalViews_;
};

class View {
  public:
    virtual void update() = 0;
  protected:
    Model*  model_;
};

class GraphView : public View { public:
  GraphView( Model* m ) { model_ = m;   model_->attach( this ); }
  /* virtual */ void update() { cout << "displaying " << model_->getState()
    << " in graph" << endl; }
};

class TableView : public View { public:
  TableView( Model* m ) { model_ = m;   model_->attach( this ); }
  /* virtual */ void update() { cout << "displaying " << model_->getState()
    << " in table" << endl; }
};

void Model::notify() {
  for (int i=0; i < totalViews_; i++)   views_[i]->update(); }

int main()
{
  Model      m;
  GraphView  gv( &m );
  TableView  tv( &m );
  int        value;
  cout << "Enter new value for model: ";
  cin >> value;
  while (value) {
    m.setState( value );
    cout << "Enter new value for model: ";
    cin >> value; }
}

// Enter new value for model: 42
// displaying 42 in graph
// displaying 42 in table
// Enter new value for model: 24
// displaying 24 in graph
// displaying 24 in table
