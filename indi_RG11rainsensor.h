#ifndef INDI_RG11RAINSENSOR_H
#define INDI_RG11RAINSENSOR_H

#include "indiweather.h"
#include <indidome.h>

class IndiRG11RainSensor : public INDI::Weather
{
    public:
    IndiRG11RainSensor();
    virtual ~IndiRG11RainSensor();

    //  Generic indi device entries
    bool Connect();
    bool Disconnect();
    const char *getDefaultName();

    virtual bool initProperties();
    virtual bool ISSnoopDevice (XMLEle *root);

    protected:
    virtual IPState updateWeather();

};

#endif // INDI_RG11RAINSENSOR_H
