#include <memory>
#include "indi_RG11rainsensor.h"

// We declare an auto pointer to RG11RainSensor.
std::unique_ptr<IndiRG11RainSensor> Indirg11rainsensor(new IndiRG11RainSensor());

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void ISInit()
{
   static int isInit =0;

   if (isInit == 1)
       return;

    isInit = 1;
    if(Indirg11rainsensor.get() == 0) Indirg11rainsensor.reset(new IndiRG11RainSensor());
}

void ISGetProperties(const char *dev)
{
	ISInit();
        Indirg11rainsensor->ISGetProperties(dev);
}

void ISNewSwitch(const char *dev, const char *name, ISState *states, char *names[], int num)
{
	ISInit();
        Indirg11rainsensor->ISNewSwitch(dev, name, states, names, num);
}

void ISNewText(	const char *dev, const char *name, char *texts[], char *names[], int num)
{
	ISInit();
        Indirg11rainsensor->ISNewText(dev, name, texts, names, num);
}

void ISNewNumber(const char *dev, const char *name, double values[], char *names[], int num)
{
	ISInit();
        Indirg11rainsensor->ISNewNumber(dev, name, values, names, num);
}

void ISNewBLOB (const char *dev, const char *name, int sizes[], int blobsizes[], char *blobs[], char *formats[], char *names[], int n)
{
  INDI_UNUSED(dev);
  INDI_UNUSED(name);
  INDI_UNUSED(sizes);
  INDI_UNUSED(blobsizes);
  INDI_UNUSED(blobs);
  INDI_UNUSED(formats);
  INDI_UNUSED(names);
  INDI_UNUSED(n);
}

void ISSnoopDevice (XMLEle *root)
{
    ISInit();
    Indirg11rainsensor->ISSnoopDevice(root);
}

IndiRG11RainSensor::IndiRG11RainSensor()
{
   setVersion(1,0);
   setWeatherConnection(CONNECTION_NONE);
}

IndiRG11RainSensor::~IndiRG11RainSensor()
{

}

const char * IndiRG11RainSensor::getDefaultName()
{
    return (char *)"Indi RG11 Rain Sensor";
}

bool IndiRG11RainSensor::Connect()
{
    return true;
}

bool IndiRG11RainSensor::Disconnect()
{
    return true;
}

/**
 * Init all properties
 */
bool IndiRG11RainSensor::initProperties()
{
    INDI::Weather::initProperties();
    addParameter("WEATHER_RAIN", "Rain", 0, 0, 0, 0);
    setCriticalParameter("WEATHER_RAIN");
    addDebugControl();
    return true;
}

bool IndiRG11RainSensor::ISSnoopDevice (XMLEle *root)
{
	return INDI::Weather::ISSnoopDevice(root);
}

IPState IndiRG11RainSensor::updateWeather()
{
      FILE *in;
      char buff[8];
      if (!(in = popen("gpio read 6", "r")))
      {
        DEBUG(INDI::Logger::DBG_ERROR, "Unable to read GPIO.");
        IPS_ALERT;
      }

      fgets(buff, sizeof(buff), in);
      pclose(in);

	DEBUGF(INDI::Logger::DBG_SESSION, "GPIO buffer (%s)", buff);

        if (atoi(buff) == 0)
            setParameterValue("WEATHER_RAIN", 0);
        else
            setParameterValue("WEATHER_RAIN", 1);

    return IPS_OK;
}
