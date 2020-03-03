//Headers
#include <iostream>
#include <string.h>

class CancerData
{
private:
	std::string country;
	double cancerRate;
public:
	CancerData(std::string &countryInput, double &rateInput);
	CancerData();
	~CancerData();
	std::string getCountry();
	double getRate();
	friend bool operator < (const CancerData& d1, const CancerData& d2);
	friend bool operator > (const CancerData& d1, const CancerData& d2);
	friend std::ostream& operator<<(std::ostream& lhs, const CancerData& rhs);
	friend bool operator == (const CancerData& d1, const CancerData& d2);
};