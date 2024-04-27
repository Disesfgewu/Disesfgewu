library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
use ieee.std_logic_unsigned.all;

entity Conponent is
    port( 
        b : in std_logic_vector( 7 downto 0 ) ;
        s : in std_logic;
        rst : in std_logic;
        clk : in std_logic;
        f : out std_logic_vector( 7 downto 0 )
    );
end Conponent;

architecture behavior of Conponent is
begin
    process( clk , rst , b , s )
    	variable reg : unsigned( 7 downto 0 ) := ( others => '0' ) ;
        variable temp : std_logic_vector( 7 downto 0 ) := "00000001";
        variable return_value : std_logic_vector ( 7 downto 0 ) := ( others => '0' ) ;
		variable tb : std_logic_vector ( 7 downto 0 ) := ( others => '0' ) ;
    begin
        if ( rst = '1' ) then
            reg := ( others => '0' ) ;
		    f <= "00000001";
        elsif ( clk = '1' and rst = '0' ) then
            if ( s = '0') then
            	return_value := ( others => '0' );
            	for i in 0 to 7 loop
                	if ( B(i) = '1' ) then 
                    	return_value := std_logic_vector( unsigned( return_value ) + shift_left( unsigned( temp ) , i ) ) ;
                    end if;
                end loop ;
                -- return_value := std_logic_vector( unsigned( return_value ) - unsigned( temp ) ) ;
                
                temp := std_logic_vector(return_value);
                f <= std_logic_vector(return_value); 
            elsif ( s = '1' ) then 
            	reg := ( others => '0' ) ;
                
                while ( unsigned( temp ) >= unsigned( b ) ) loop 
                	temp := std_logic_vector( unsigned( temp ) - unsigned( b ) );
                    reg := reg + 1 ;
                end loop;
                temp := std_logic_vector( reg ) ;
                f <= std_logic_vector( reg ) ;
         	end if;
        end if;
    end process;
end behavior;