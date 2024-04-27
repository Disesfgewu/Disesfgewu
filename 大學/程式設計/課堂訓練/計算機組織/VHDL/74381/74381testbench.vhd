-- Testbench automatically generated online
-- at https://vhdl.lapinoo.net
-- Generation date : 11.4.2024 01:43:57 UTC

library ieee;
use ieee.std_logic_1164.all;
use IEEE.numeric_std.all;

entity tb_Conponent is
end tb_Conponent;

architecture tb of tb_Conponent is

    component Conponent
        port (a : in std_logic_vector (7 downto 0 );
              b : in std_logic_vector (7 downto 0 );
              s : in std_logic_vector (2 downto 0 );
              c : in std_logic;
              f : out std_logic_vector (7 downto 0 ) );
    end component;

    signal a : std_logic_vector (7 downto 0 );
    signal b : std_logic_vector (7 downto 0 );
    signal s : std_logic_vector (2 downto 0 );
    signal c : std_logic;
    signal f : std_logic_vector (7 downto 0 );

begin

    dut : Conponent
    port map (a => a,
              b => b,
              s => s,
              c => c,
              f => f);

    stimuli : process
    begin
        -- EDIT Adapt initialization as needed
        a <= (others => '0');
        b <= (others => '0');
        s <= (others => '0');
        c <= '0';

        -- EDIT Add stimuli here
		for s_decision in 0 to 7 loop
        	s <= std_logic_vector ( to_unsigned( s_decision , s'length ) ) ;
           		
                c <= '0';
                
               	a <= x"55" ;
                b <= x"55" ;
                wait for 10 ns ;
                
                a <= x"55" ;
                b <= x"aa" ;
                wait for 10 ns ;
                
                a <= x"aa" ;
                b <= x"55" ;
                wait for 10 ns ;
                
                a <= x"aa" ;
                b <= x"aa" ;
                wait for 10 ns ;
            	
                c <= '1';
                
               	a <= x"55" ;
                b <= x"55" ;
                wait for 10 ns ;
                
                a <= x"55" ;
                b <= x"aa" ;
                wait for 10 ns ;
                
                a <= x"aa" ;
                b <= x"55" ;
                wait for 10 ns ;
                
                a <= x"aa" ;
                b <= x"aa" ;
                wait for 10 ns ;
            
        end loop;
        wait;
    end process;

end tb;

-- Configuration block below is required by some simulators. Usually no need to edit.

configuration cfg_tb_Conponent of tb_Conponent is
    for tb
    end for;
end cfg_tb_Conponent;