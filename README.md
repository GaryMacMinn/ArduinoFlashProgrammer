# ArduinoFlashProgrammer
In designing my 65C02 retro computer I realised I'd be needing to program some Flash
memory chips to be the ROMs of my system. My old parallel EPROM programmer is long gone
so a new design was called for.

I had an Arduino Mega 2560 on the bench when the light dawned that this would be a good
platform to do this as it had plenty of I/O lines to operate the 27 address and data lines
and was fairly easy to program.

And so was born, the Arduino Flash Programmer.
