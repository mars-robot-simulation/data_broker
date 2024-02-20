#include "DataPackageMapping.h"

namespace mars
{
  
    namespace data_broker
    {
    
        DataPackageMapping::DataPackageMapping()
            : first(true)
        {}

        DataPackageMapping::~DataPackageMapping()
        {
            clear();
        }
    
        bool DataPackageMapping::readPackage(const DataPackage &package)
        {
            bool ret = true;
            if(first)
            {
                for(std::vector<DataItemAccessorBase*>::iterator it = accessors.begin();
                    it != accessors.end(); ++it)
                {
                    ret = (ret && (*it)->getIndex(package));
                }
                if(!ret)
                {
                    return ret;
                }
                first = false;
            }
            for(std::vector<DataItemAccessorBase*>::iterator it = accessors.begin();
                it != accessors.end(); ++it)
            {
                ret = (ret && (*it)->getValue(package));
            }
            return ret;
        }

        bool DataPackageMapping::writePackage(DataPackage *package)
        {
            /* Writing the package is a bit more difficult.
             * We don't know if the DataItems exist. Even after the first run it might
             * not exist because it could be an entirly new DataPackage.
             * For perfomance reasons we abandon the "Look Before You Leap" style in
             * favour of the "Easier to Ask for Forgiveness Than Permission" style.
             * Only when setting a DataItem fails do we try to create it.
             */
            bool ret = true;
            for(std::vector<DataItemAccessorBase*>::iterator it = accessors.begin();
                it != accessors.end(); ++it)
            {
                bool tmp = (*it)->setValue(package);
                if(!tmp)
                {
                    ret = (ret && (*it)->createValue(package));
                }
            }
            return ret;
        }

        void DataPackageMapping::clear()
        {
            for(std::vector<DataItemAccessorBase*>::iterator it = accessors.begin();
                it != accessors.end(); ++it)
            {
                delete *it;
            }
            accessors.clear();
            first = true;
        }

    } // end of namespace data_broker

} // end of namespace mars
