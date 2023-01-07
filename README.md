# IOT-WeatherStation
A simple weather station that get humidity (in %) and temperature (in C°).


# Operation
The normal working it's that each loop, the station get weather data, display it and send it by NRF module.
Now you can so get the data from another module to use it as you want.
  

# Cable Management
Here there is all you need to make the wiring part.
> Note that for now, the system use à 9V battery.

| Sensors         | Usage | Link |
| --------------- | ----- | ---- |
| Arduino UNO     | To operate and update the software | [here](https://www.amazon.fr/Arduino-A000066-M%C3%A9moire-flash-32/dp/B008GRTSV6/ref=sr_1_5?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=6UZUTJTEXEB4&keywords=Arduino+Uno&qid=1673103852&sprefix=arduino+uno%2Caps%2C104&sr=8-5) |
| DHT             | To get humidity and temperature | [here](https://www.amazon.fr/AZDelivery-KY-015-capteur-Temp%C3%A9rature-compris/dp/B089W7CJL4/ref=sr_1_3?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=3LAKNEDJVILAC&keywords=Arduino+DHT+Sensor&qid=1673103920&sprefix=arduino+dht+sensor%2Caps%2C86&sr=8-3) |
| Screen LCD 16x2 | To Display data just received from the sensors | [here](https://www.amazon.fr/AZDelivery-HD44780-1602-Module-afficheur-16-caract%C3%A8res-Arduino/dp/B07CQG6CMT/ref=sr_1_1_sspa?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=2HSQR946VA8JZ&keywords=Arduino%2BLCD%2BScreen%2B16x2&qid=1673103874&sprefix=arduino%2Blcd%2Bscreen%2B16x2%2Caps%2C88&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&th=1) |
| NRF 24L01       | To send data to whatever you want | [here](https://www.amazon.fr/DollaTek-nRF24L01-Module-Niveau-Communication/dp/B07DK55W35/ref=sr_1_4?keywords=NRF+Arduino+module&link_code=qs&qid=1673103765&sourceid=Mozilla-search&sr=8-4)


# Next
- I will soon upload some pictures of the project
- I will soon upload some Tinkercad schema about the wiring
- Battery percent will be display on the LCD screen.
