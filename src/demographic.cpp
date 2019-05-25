/*
 * file: demographic.cpp
 * author: Jhony Angulo
 * date: 25-05-2019
 */
#include "../include/demographic.hpp"
#include "../include/functions.hpp"
Demographic::Demographic(std::vector<std::string> data) {
	state_fips_code = data[0];
	county_fips_code = data[1];
	chsi_county_name = data[2];
	chsi_state_name = data[3];
	chsi_state_abbr = data[4];
	strata_id_number = std::stoi(data[5]);
	strata_determining_factors = data[6];
	number_counties = std::stoi(data[7]);
	population_size = std::stoi(data[8]);
	min_population_size = std::stoi(data[9]);
	max_population_size = std::stoi(data[10]);
	population_density = std::stoi(data[11]);
	min_population_density = std::stoi(data[12]);
	max_population_density = std::stoi(data[13]);
    poverty = std::stof(data[14]);
    min_poverty = std::stof(data[15]);
    max_poverty = std::stof(data[16]);
    age_19_under = std::stof(data[17]);
    min_age_19_under = std::stof(data[18]);
    max_age_19_under = std::stof(data[19]);
    age_19_64 = std::stof(data[20]);
    min_age_19_64 = std::stof(data[21]);
    max_age_19_65 = std::stof(data[22]);
    age_65_84 = std::stof(data[23]);
    min_age_65_84 = std::stof(data[24]);
    max_age_65_85 = std::stof(data[25]);
    age_85_and_over = std::stof(data[26]);
    min_age_85_and_over = std::stof(data[27]);
    max_age_85_and_over = std::stof(data[28]);
    white = std::stof(data[29]);
    min_white = std::stof(data[30]);
    max_white = std::stof(data[31]);
    black = std::stof(data[31]);
    min_black = std::stof(data[32]);
    max_black = std::stof(data[33]);
    native_american = std::stof(data[34]);
    min_native_american = std::stof(data[35]);
    max_native_american = std::stof(data[36]);
    asian = std::stof(data[37]);
    min_asian = std::stof(data[38]);
    max_asian = std::stof(data[39]);
    hispanic = std::stof(data[40]);
    min_hispanic = std::stof(data[41]);
	max_hispanic = std::stof(data[42]);
}

std::ostream& operator<<(std::ostream& os, const Demographic& d) {
	return os;
}

std::istream &operator>>(std::istream &is, const Demographic &d)  {
	return is;
}
