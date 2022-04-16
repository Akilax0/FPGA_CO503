-- Hello world program
use std.textio.all; --Imports the standard testio package

-- Defines a design entity, without any ports
entity hello_world is
end hello_world;

architecture behaviuor of hello_world is 
begin
	process
		variable l : line;
	begin
		write (l, String'("Hello world!"));
		writeline (output, l);
		wait;
	end process;
end behaviuor;
