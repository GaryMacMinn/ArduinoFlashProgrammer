# ArduinoFlashProgrammer
In designing my 65C02 retro computer I realised I'd be needing to program some Flash
memory chips to be the ROMs of my system. My old parallel EPROM programmer is long gone
so a new design was called for.

I had an Arduino Mega 2560 on the bench when the light dawned that this would be a good
platform to do this as it had plenty of I/O lines to operate the 27 address and data lines
and was fairly easy to program.

And so was born, the Arduino Flash Programmer.

The code shown here supports the AMD AM29F040B specifically as this is the Flash chip I'm
using. These are available on eBay and the like at cheap prices. They are a 4Mbit chip
arranged as 512k x 8bit. The sector operations work on 64k sectors so there are only 8 sectors
in this chip.
