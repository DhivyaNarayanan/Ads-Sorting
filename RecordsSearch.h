#include"Interfaces03.h"

class RecordsSearch :public IRecordsSearch
{
	std::vector<Employee>srecords;
	std::vector<std::string>dim_vec[3];
public:
	RecordsSearch() { }
	~RecordsSearch() { }
    void bulkInsert(std::vector<Employee> records);
	Employee searchFirstName(std::string first_name);
	Employee searchLastName(std::string last_name);
	Employee searchPassword(std::string password);

};