#include "CancerData.hpp"


	CancerData::CancerData(std::string &countryInput, double &rateInput)
	{
		this->country = countryInput;
		this->cancerRate = rateInput;
	}
	CancerData::CancerData()
	{
		country = "N/A";
		cancerRate = 0;
	}
	CancerData::~CancerData()
	{
		
	}
//Getters
	std::string CancerData::getCountry()
	{
		return this->country;
	}
	double CancerData::getRate()
	{
		return this->cancerRate;
	}
//Operator overloads
	bool operator < (const CancerData& d1, const CancerData& d2)
	{
		return (d1.cancerRate < d2.cancerRate);
	}
	bool operator > (const CancerData& d1, const CancerData& d2)
	{
		return (d1.cancerRate > d2.cancerRate);
	}
	std::ostream& operator<<(std::ostream& lhs, const CancerData& rhs)
	{
		lhs << rhs.country << "  " << rhs.cancerRate;
		return lhs;
	}
	bool operator == (const CancerData& d1, const CancerData& d2)
	{
		if (d1.cancerRate == d2.cancerRate)
			return true;
		else
			return false;
	}