#pragma once

namespace mars
{

    namespace data_broker
    {
        // forward declarations
        class DataInfo;
        class DataPackage;

        /**
         * \brief Interface for classes that want to receive data from the
         *        DataBroker.
         */
        class ReceiverInterface
        {

        public:
            ReceiverInterface() {}
            virtual ~ReceiverInterface() {}
            /**
             * \brief The DataBroker will call this method to notify the receiver of
             *        whenever the condition for which the receiver registered occur.
             * \param info Information about the DataPackage.
             * \param dataPackage The DataPackage containing all the data.
             * \param callbackParam The \c int the receiver passed during 
             *                      registration. The default (the receiver didn't
             *                      provide a callbackParam) is 0. This can be used
             *                      to easily distinguish different registrations.
             */
            virtual void receiveData(const DataInfo &info, 
                                     const DataPackage &dataPackage,
                                     int callbackParam) = 0;
        }; // end of class ReceiverInterface

    } // end of namespace data_broker

} // end of namespace mars
