#prama once

namespace mars
{

    namespace data_broker
    {

        // forward declarations
        class DataPackage;
        class DataInfo;

        /**
         * Interface for classes producing data to broadcast via a DataBroker.
         */
        class ProducerInterface
        {
        public:
            ProducerInterface() {}
            virtual ~ProducerInterface() {}
      
            virtual void produceData(const DataInfo &info,
                                     DataPackage *package,
                                     int callbackParam) = 0;

        }; // end of class ProducerInterface

    } // end of namespace data_broker

} // end of namespace mars
