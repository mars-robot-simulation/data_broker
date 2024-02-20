#pragma once
#include <string>

namespace mars
{

    namespace data_broker
    {

        /**
         * \brief indicates to nature of the data contained in a DataPackage
         */
        enum PackageFlag
        {
            DATA_PACKAGE_NO_FLAG         = 0,
            DATA_PACKAGE_READ_FLAG       = (1 << 0),
            DATA_PACKAGE_WRITE_FLAG      = (1 << 1),
            DATA_PACKAGE_READ_WRITE_FLAG = (DATA_PACKAGE_READ_FLAG | 
                                            DATA_PACKAGE_WRITE_FLAG),
            DATA_PACKAGE_ALL_FLAGS       = 0xFF
        };

        /** \brief Class containing information about a DataPackage. */
        class DataInfo
        {
        public:
            DataInfo();
            ~DataInfo();
            DataInfo(const DataInfo &other);
            DataInfo &operator=(const DataInfo &other);

            /** \brief A unique numeric identifier assigned by the DataBroker
             */
            unsigned long dataId;
            /** \brief A name describing the group/category this belongs to. 
             *         The groupName-dataName combination should be unique.
             */
            std::string groupName; 
            /** \brief A name describing this DataPackage within the group
             *         The groupName-dataName combination should be unique.
             */
            std::string dataName;
            PackageFlag flags;
        };

    } // end of namespace data_broker

} // end of namespace mars
