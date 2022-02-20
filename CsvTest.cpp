void getCsvAttributes(std::string& inputStr, const std::string& separator,
	std::map<std::string, unsigned int>& result,
	const std::list<std::string>& filterList = {})
{
	std::string::size_type sz{};
	std::string word{};
	unsigned int counter{ 0 };
	bool useFilter{ false };

	if (filterList.size() != 0)
	{
		useFilter = true;
	}

	result.clear();

	while (inputStr.size() > 0)
	{
		word = "";
		sz = inputStr.find_first_of(separator);

		if (sz != 0)
		{
			word = inputStr.substr(0, sz);
			inputStr.erase(0, sz + 1);
		}
		else
		{
			inputStr.erase(0, 1);
		}

		if (useFilter)
		{
			auto it = std::find(filterList.begin(), filterList.end(), word);

			if (it != filterList.end())
			{
				result.insert({ word, counter });
			}
		}
		else
		{
			result.insert({ word, counter });
		}

		counter++;
	}
}

void getCsvValues(std::string& inputStr, const std::string& separator, std::map<unsigned int, std::string>& result)
{
	std::string::size_type sz{};
	std::string word{};
	unsigned int counter{ 0 };
	result.clear();

	while (inputStr.size() > 0)
	{
		word = "";
		sz = inputStr.find_first_of(separator);

		if (sz != 0)
		{
			word = inputStr.substr(0, sz);
			inputStr.erase(0, sz + 1);
		}
		else
		{
			inputStr.erase(0, 1);
		}

		result.insert({ counter, word });
		counter++;
	}
}

void testCsv()
{
	std::list<std::map< unsigned int, std::string>> content{};
	std::string line{};
	std::map<std::string, unsigned int> attributes_list{};
	std::map< unsigned int, std::string> row_list{};

	std::list<std::string> filterList = { "MachineCore.Origin.Location", "MachineCore.Reject.NoLength", "Sorting.SortingProduct.FirstReject.Name" };
	std::ifstream file("C:\\Users\\Strutu\\Desktop\\MPR_TOP2000 VALENCE_1645178161_CUSTOMER_SORT_22-02-18T09-56-01Z.csv", std::ios::in);

	if (file.is_open())
	{
		std::getline(file, line);
		getCsvAttributes(line, ";", attributes_list, filterList);

		while (std::getline(file, line))
		{
			getCsvValues(line, ";", row_list);
			content.push_back(row_list);
		}
	}
	else
		std::cout << "Could not open the file\n";

	file.close();
}