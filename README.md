# indi-RG11-Rain-Sensor

**So what it is?**
It's a driver to read the status of a [Rain Gauge Model RG-11](http://rainsensors.com/) sensor.
They are inexpensive to purchase, I have one installed on my observatory and it's quite efficient. As in: one drop of rain and it detects it.

**Sensor setup:**
Different modes are available, in this case we will use the [It's Raining](http://rainsensors.com) mode.
*“It’s Raining” | Close a skylight at the first sign of rain, and open it when it stops raining.*
From the pdf documentation, I have set my sensor to: "hold the output on for 15 minutes after the rain has ceased." (Added safety in my views.)

**How to connect it?**
This is the part where you must be comfortable with your '**Odroid C1**' or '**Raspberry PI**'. I will not cover this here. 
The relay output from the sensor is connected to the GPIO on your favourite board, and you need to have the wiringPi tools installed.
You should be able to do a:
gpio readall or gpio read 4 (4 is the input I have it connected to).
You can either match your GPIO input number to the code or change the code itself, it does matter as long as they match (for obvious reasons...)


The driver is fairly simple, not much in it, standard tabs as:
'Main Control' ~ 'Options' ~ 'Paramaters' ~ 'Site Management'
Self explanatory, no need for screenshots.


I hope you'll find this driver useful.



![alt tag](http://0144b4c2e6b6b1590378-8d8307f63a5046ee0a2d736269de64a5.r81.cf1.rackcdn.com/rainsensor1.png)

![alt tag](http://0144b4c2e6b6b1590378-8d8307f63a5046ee0a2d736269de64a5.r81.cf1.rackcdn.com/rainsensor2.png)
