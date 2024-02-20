#include "DataInfo.h"

namespace mars
{

    namespace data_broker
    {

        DataInfo::DataInfo()
        {
            dataId = 0;
            groupName = "";
            dataName = "";
            flags = DATA_PACKAGE_NO_FLAG;
        }
    
        DataInfo::~DataInfo()
        {
        }

        DataInfo::DataInfo(const DataInfo &other)
        {
            *this = other;
        }

        DataInfo &DataInfo::operator=(const DataInfo &other)
        {
            if(this == &other)
            {
                return *this;
            }
            dataId = other.dataId;
            flags = other.flags;
            groupName = other.groupName.c_str();
            dataName = other.dataName.c_str();
            return *this;
        }

    } // end of namespace data_broker
  
} // end of namespace mars
