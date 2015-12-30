/*******************************************************************************
  Copyright(c) 2016 Stephane Lucas. All rights reserved.

  INDI Rain Sensor Driver

  This program is free software; you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by the Free
  Software Foundation; either version 2 of the License, or (at your option)
  any later version.

  This program is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
  more details.

  You should have received a copy of the GNU Library General Public License
  along with this library; see the file COPYING.LIB.  If not, write to
  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
  Boston, MA 02110-1301, USA.

  The full GNU General Public License is included in this distribution in the
  file called LICENSE.
*******************************************************************************/

#ifndef INDI_RAINSENSOR_H
#define INDI_RAINSENSOR_H

#include "indiweather.h"

class IndiRainSensor : public INDI::Weather
{
    public:
    IndiRainSensor();
    virtual ~IndiRainSensor();

    //  Generic indi device entries
    bool Connect();
    bool Disconnect();
    const char *getDefaultName();

    virtual bool initProperties();
//    virtual bool ISNewText (const char *dev, const char *name, char *texts[], char *names[], int n);

    protected:
    virtual IPState updateWeather();
//    virtual bool saveConfigItems(FILE *fp);

};

#endif // INDI_RAINSENSOR_H
