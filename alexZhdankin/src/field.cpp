#include "field.hpp"

#include <string>
#include <map>

namespace
{
	//?
	std::map<FieldType, std::pair<int,int> > fieldTypeData = {
		{ FieldType::AUTO, {500,250} },
		{ FieldType::CLOTHER, {100,250} },
		{ FieldType::FOOD, {250,250} },
		{ FieldType::TRAVEL, {700,250} },
        { FieldType::PRISON, {0,700} },
        { FieldType::BANK, {0, 1000} },
    };
}

Field::Field(std::string strName, FieldType typeField, int priceVal, int rentaVal)
    : name(strName), type(typeField), owner(nullptr), price(priceVal), renta(rentaVal)
{}

Field Field::getField(std::string name, FieldType fType)
{
	auto fieldInfo = fieldTypeData.at(fType);
	return Field{name, fType, fieldInfo.first, fieldInfo.second};
}

bool Field::operator==(const Field& rhs) const
{
	return getName() == rhs.getName() &&
		getOwner() == rhs.getOwner() &&
		getType() == rhs.getType() &&
		getPrice() == rhs.getPrice() &&
		getRenta() == rhs.getRenta();
}