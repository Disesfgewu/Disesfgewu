library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
use ieee.std_logic_unsigned.all;

entity Conponent is
    port( 
    	an, bn , cn: in std_logic;
        s0 , s1 , s2 : in std_logic;
        f : out std_logic_vector ( 7 downto 0 );
        g , p : out std_logic
    );
end Conponent;

architecture behavior of Conponent is
begin
	process( an , bn , cn , s0 , s1 , s2) 
    begin
	if ( s0 = 'L' and s1 = 'L' and s2 = 'L' ) then
    	f <= "LLLLLLLL" ;
        g <= 'L' ;
        p <= 'L' ;
    elsif ( s0 = 'H' and s1 = 'L' and s2 = 'L' ) then
    	if ( cn = 'L' ) then 
        	if ( an = 'L' ) then
            	if ( bn = 'L' ) then
                	f <= "HHHHHHHH" ;
                    g <= 'H';
                    p <= 'L';
                elsif ( bn = 'H' ) then
                	f <= "HHHHHHHL" ;
                    g <= 'L';
                    p <= 'L';
                end if;
            elsif ( an = 'H' ) then
            	if ( bn = 'L' ) then
                	f <= "LLLLLLLL" ;
                    g <= 'H';
                    p <= 'H';
                elsif ( bn = 'H' ) then
                	f <= "HHHHHHHH" ;
                    g <= 'H';
                    p <= 'L';
                end if;
           end if;
       	elsif ( cn = 'H' ) then
        	if ( an = 'L' ) then
            	if ( bn = 'L' ) then
                	f <= "LLLLLLLL" ;
                    g <= 'H';
                    p <= 'L';
                elsif ( bn = 'H' ) then
                	f <= "HHHHHHHH" ;
                    g <= 'L';
                    p <= 'L';
                end if;
            elsif ( an = 'H' ) then
            	if ( bn = 'L' ) then
                	f <= "LLLLLLLH" ;
                    g <= 'H';
                    p <= 'H';
                elsif ( bn = 'H' ) then
                	f <= "LLLLLLLL" ;
                    g <= 'H';
                    p <= 'L';
                end if;
           end if;
        end if;
     elsif ( s0 = 'L' and s1 = 'H' and s2 = 'L' ) then
    	if ( cn = 'L' ) then 
        	if ( an = 'L' ) then
            	if ( bn = 'L' ) then
                	f <= "HHHHHHHH" ;
                    g <= 'H';
                    p <= 'L';
                elsif ( bn = 'H' ) then
                	f <= "LLLLLLLL" ;
                    g <= 'H';
                    p <= 'H';
                end if;
            elsif ( an = 'H' ) then
            	if ( bn = 'L' ) then
                	f <= "HHHHHHHL" ;
                    g <= 'L';
                    p <= 'L';
                elsif ( bn = 'H' ) then
                	f <= "HHHHHHHH" ;
                    g <= 'H';
                    p <= 'L';
                end if;
           end if;
       	elsif ( cn = 'H' ) then
        	if ( an = 'L' ) then
            	if ( bn = 'L' ) then
                	f <= "LLLLLLLL" ;
                    g <= 'H';
                    p <= 'L';
                elsif ( bn = 'H' ) then
                	f <= "LLLLLLLH" ;
                    g <= 'H';
                    p <= 'H';
                end if;
            elsif ( an = 'H' ) then
            	if ( bn = 'L' ) then
                	f <= "HHHHHHHH" ;
                    g <= 'L';
                    p <= 'L';
                elsif ( bn = 'H' ) then
                	f <= "LLLLLLLL" ;
                    g <= 'H';
                    p <= 'L';
                end if;
           end if;
        end if;
     elsif ( s0 = 'H' and s1 = 'H' and s2 = 'L'  ) then
    	if ( cn = 'L' ) then 
        	if ( an = 'L' ) then
            	if ( bn = 'L' ) then
                	f <= "LLLLLLLL" ;
                    g <= 'H';
                    p <= 'H';
                elsif ( bn = 'H' ) then
                	f <= "HHHHHHHH" ;
                    g <= 'H';
                    p <= 'L';
                end if;
            elsif ( an = 'H' ) then
            	if ( bn = 'L' ) then
                	f <= "HHHHHHHH" ;
                    g <= 'H';
                    p <= 'L';
                elsif ( bn = 'H' ) then
                	f <= "HHHHHHHL" ;
                    g <= 'L';
                    p <= 'L';
                end if;
           end if;
       	elsif ( cn = 'H' ) then
        	if ( an = 'L' ) then
            	if ( bn = 'L' ) then
                	f <= "LLLLLLLH" ;
                    g <= 'H';
                    p <= 'H';
                elsif ( bn = 'H' ) then
                	f <= "LLLLLLLL" ;
                    g <= 'H';
                    p <= 'L';
                end if;
            elsif ( an = 'H' ) then
            	if ( bn = 'L' ) then
                	f <= "LLLLLLLL" ;
                    g <= 'H';
                    p <= 'L';
                elsif ( bn = 'H' ) then
                	f <= "HHHHHHHH" ;
                    g <= 'L';
                    p <= 'L';
                end if;
           end if;
       end if;
     elsif ( s0 = 'L' and s1 = 'L' and s2 = 'H'  ) then
        	if ( an = 'L' ) then
            	if ( bn = 'L' ) then
                	f <= "LLLLLLLL" ;
                    g <= 'H';
                    p <= 'H';
                elsif ( bn = 'H' ) then
                	f <= "HHHHHHHH" ;
                    g <= 'H';
                    p <= 'H';
                end if;
            elsif ( an = 'H' ) then
            	if ( bn = 'L' ) then
                	f <= "HHHHHHHH" ;
                    g <= 'H';
                    p <= 'L';
                elsif ( bn = 'H' ) then
                	f <= "LLLLLLLL" ;
                    g <= 'L';
                    p <= 'L';
                end if;
           end if;
      elsif ( s0 = 'H' and s1 = 'L' and s2 = 'H'  ) then
        	if ( an = 'L' ) then
            	if ( bn = 'L' ) then
                	f <= "LLLLLLLL" ;
                    g <= 'H';
                    p <= 'H';
                elsif ( bn = 'H' ) then
                	f <= "HHHHHHHH" ;
                    g <= 'H';
                    p <= 'H';
                end if;
            elsif ( an = 'H' ) then
            	if ( bn = 'L' ) then
                	f <= "HHHHHHHH" ;
                    g <= 'H';
                    p <= 'H';
                elsif ( bn = 'H' ) then
                	f <= "HHHHHHHH" ;
                    g <= 'H';
                    p <= 'L';
                end if;
           end if;
       elsif ( s0 = 'L' and s1 = 'H' and s2 = 'H'  ) then
        	if ( an = 'L' ) then
            	if ( bn = 'L' ) then
                	f <= "LLLLLLLL" ;
                    g <= 'L';
                    p <= 'L';
                elsif ( bn = 'H' ) then
                	f <= "LLLLLLLL" ;
                    g <= 'H';
                    p <= 'H';
                end if;
            elsif ( an = 'H' ) then
            	if ( bn = 'L' ) then
                	f <= "LLLLLLLL" ;
                    g <= 'L';
                    p <= 'L';
                elsif ( bn = 'H' ) then
                	f <= "HHHHHHHH" ;
                    g <= 'H';
                    p <= 'L';
                end if;
           end if;
      elsif ( s0 = 'H' and s1 = 'H' and s2 = 'H'  ) then
        	if ( an = 'L' ) then
            	if ( bn = 'L' ) then
                	f <= "HHHHHHHH" ;
                    g <= 'H';
                    p <= 'H';
                elsif ( bn = 'H' ) then
                	f <= "HHHHHHHH" ;
                    g <= 'H';
                    p <= 'H';
                end if;
            elsif ( an = 'H' ) then
            	if ( bn = 'L' ) then
                	f <= "HHHHHHHH" ;
                    g <= 'H';
                    p <= 'H';
                elsif ( bn = 'H' ) then
                	f <= "HHHHHHHH" ;
                    g <= 'H';
                    p <= 'L';
                end if;
           end if;
       end if;
       end process;
end behavior;