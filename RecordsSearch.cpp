#include"RecordsSearch.h"

void RecordsSearch::bulkInsert(std::vector<Employee> records)
{
	for (int i = 0; i < records.size(); i++)
	{
		srecords.push_back(records[i]);
	}
	/*for (int i = 0; i < records.size(); i++)
	{
		Employee temp;
		temp.first_name = records[i].first_name;
		temp.last_name = records[i].last_name;
		temp.password = records[i].password;
		
		dim_vec[i][0] = temp.first_name;
		dim_vec[i][1] = temp.last_name;
		dim_vec[i][2] = temp.password;
				
	}*/
}
Employee RecordsSearch::searchFirstName(std::string first_name)
{
	for (int i = 0; i < srecords.size(); i++)
	{
		if (srecords[i].first_name == first_name)
			return srecords[i];
	}
	
}
Employee RecordsSearch::searchLastName(std::string last_name)
{
	for (int i = 0; i < srecords.size(); i++)
	{
		if (srecords[i].last_name == last_name)
			return srecords[i];
	}
}
Employee RecordsSearch::searchPassword(std::string password)
{
	for (int i = 0; i < srecords.size(); i++)
	{
		if (srecords[i].password == password)
			return srecords[i];
	}
}
