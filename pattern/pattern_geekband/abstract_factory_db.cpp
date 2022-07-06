//Abstract Factory
class IDBConnection {};
class IDBCommand {};
class IDBDataReader {};

// 既然这三个工厂强相关，那么合为一个工厂
class IDBFactory {
  public:
    virtual IDBConnection* CreateDBConnection() = 0;
    virtual IDBCommand* CreateDBCommand() = 0;
    virtual IDBDataReader* CreateDataReader() = 0;
};

class SqlConnection: public IDBConnection {...};
class SqlCommand: public IDBCommand {...};
class SqlDataReader: public IDataReader {...};

class SqlDBFactory: public IDBFactory {
  public:
    virtual IDBConnection* CreateDBConnection() {
      return new SqlConnection();
    }
    virtual IDBCommand* CreateDBCommand() {
      return new SqlCommand();
    }
    virtual IDBDataReader* CreateDataReader() {
      return new SqlDataReader();
    }
};

class MySQLConnection: public IDBConnection {...};
class MySQLCommand: public IDBCommand {...};
class MySQLDataReader: public IDataReader {...};

class MySQLDBFactory: public IDBFactory {
  public:
    virtual IDBConnection* CreateDBConnection() {
      return new MySQLConnection();
    }
    virtual IDBCommand* CreateDBCommand() {
      return new MySQLCommand();
    }
    virtual IDBDataReader* CreateDataReader() {
      return new MySQLDataReader();
    }
};


class EmployeeDAO { // data access object
  IDBFactory* dbFactory;

  public:
  vector<EmployeeDAO> GetEmployees() {
    IDBConnection* connection = 
      dbFactory->CreateDBConnection();
    connection->ConnectionString("...");

    IDBCommand* command = 
      dbFactory->CreateDBCommand();
    command->commandText("...");
    command->SetConnection(connection); // 关联性

    IDBDataReader* reader = command->ExecuteReader();   // 关联性
    while (reader->Read()) {

    }
  }
};
