//Creator/ Factory 抽象类
class IDBConnection {};
class IDBConnectionFactory {
  public:
    virtual IDBConnection* CreateDBConnection() = 0;
};

class IDBCommand {};
class IDBCommandFactory {
  public:
    virtual IDBCommand* CreateDBCommand() = 0;
};

class IDBDataReader {};
class IDBDataReaderFactory {
  public:
    virtual IDBDataReader* CreateDataReader() = 0;
};


// Creator/ Factory 具体类
class SqlConnection: public IDBConnection {...};
class MySQLConnection: public IDBConnection {...};

class SqlConnectionFactory: public IDBConnectionFactory {
  public:
    virtual IDBConnection* CreateDBConnection() {
      return new SqlConnection();
    }
};

class MySQLConnectionFactory: public IDBConnectionFactory {
  public:
    virtual IDBConnection* CreateDBConnection() {
      return new MySQLConnection();
    }
};

class SqlCommand: public IDBCommand {...};

class SqlCommandFactory: public IDBCommandFactory {
  public:
    virtual IDBCommand* CreateDBCommand() {
      return new SqlCommand();
    }
};

class SqlDataReader: public IDataReader {...};

class SqlDataReaderFactory: public IDBDataReaderFactory {
  public:
    virtual IDBDataReader* CreateDataReader() {
      return new SqlDataReader();
    }
};

class EmployeeDAO { // data access object
  IDBConnectionFactory* dbConnectionFactory;
  IDBCommandFactory* dbCommandFactory;
  IDBDataReaderFactory* dataReaderFactory;
  // 操作集合种类较多，并且有依赖交叉

  public:
  vector<EmployeeDAO> GetEmployees() {
    IDBConnection* connection = 
      dbConnectionFactory->CreateDBConnection();
    connection->ConnectionString("...");

    IDBCommand* command = 
      dbCommandFactory->CreateDBCommand();
    command->commandText("...");
    command->SetConnection(connection); // 关联性, 三组 Factory必须是一个Database类型。 

    IDBDataReader* reader = command->ExecuteReader();   // 关联性
    while (reader->Read()) {

    }
  }
};
