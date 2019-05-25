#ifndef DEMOGRAPHICS_HPP
#define DEMOGRAPHICS_HPP
#include <string>
#include <vector>
class Demographic {
	std::string state_fips_code;
	std::string county_fips_code;
	std::string chsi_county_name;
	std::string chsi_state_name;
	std::string chsi_state_abbr;
	int strata_id_number;
	std::string strata_determining_factors;
	int number_counties;
	int population_size;
	int min_population_size;
	int max_population_size;
	int population_density;
	int min_population_density;
	int max_population_density;
    float poverty;
    float min_poverty;
    float max_poverty;
    float age_19_under;
    float min_age_19_under;
    float max_age_19_under;
    float age_19_64;
    float min_age_19_64;
    float max_age_19_65;
    float age_65_84;
    float min_age_65_84;
    float max_age_65_85;
    float age_85_and_over;
    float min_age_85_and_over;
    float max_age_85_and_over;
    float white;
    float min_white;
    float max_white;
    float black;
    float min_black;
    float max_black;
    float native_american;
    float min_native_american;
    float max_native_american;
    float asian;
    float min_asian;
    float max_asian;
    float hispanic;
    float min_hispanic;
    float max_hispanic;
public:
	Demographic(std::vector<std::string> data);
	friend std::ostream& operator<<(std::ostream& os, const Demographic& d);
	friend std::istream& operator>>(std::istream& is, const Demographic& d);
};

#endif
