library IEEE;
use IEEE.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity Conponent is
    port( 
    	a , b : in std_logic_vector ( 7 downto 0 );
        s : in std_logic;
        clk , rst : in std_logic;
        f : out std_logic_vector ( 7 downto 0 );
    );
end Conponent;

architecture behavior of Conponent is
begin
	process( a , b , s , clk , rst )
    	variable temp : std_logic_vector ( 7 downto 0 ) := ( others => '0' );
        variable reg : unsigned ( 7 downto 0 );
        variable tb : std_logic_vector ( 7 downto 0 ) := ( others => '0' ) ;
    begin
    	if ( rst = '1' ) then
        	f <= "00000001";
        elsif ( clk'event and clk = '1'  ) then
        	if ( s = '0' ) then 
            	temp := ( others => '0' );
            	tb := std_logic_vector ( b ) ;
            	for i in 0 to 7 loop 
                	if ( a(i) = '1' ) then
                    	temp := std_logic_vector( unsigned( temp ) + unsigned( tb sll i ) );
                    end if;
                end loop;
                f <= std_logic_vector( temp ) ;
            elsif ( s = '1' ) then
            	reg := ( others => '0' ) ;
                temp := std_logic_vector( a ) ;
                while ( unsigned( temp ) >= unsigned( b ) ) loop
                	reg := reg + 1 ;
                    temp := std_logic_vector( unsigned( temp ) - unsigned( b ) );
                end loop;
       	  		f <= std_logic_vector( unsigned(reg) ) ;
           end if;
        end if;
     end process;
end behavior;