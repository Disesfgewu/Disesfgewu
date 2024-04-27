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
        port (an : in std_logic;
        	  bn : in std_logic;
              cn : in std_logic;
              s0 : in std_logic;
              s1 : in std_logic;
              s2 : in std_logic;
              f : out std_logic_vector (7 downto 0 );
              p : out std_logic;
              g : out std_logic;
              );
    end component;

    signal an : std_logic;
    signal bn : std_logic;
    signal cn : std_logic;
    signal s0 : std_logic;
    signal s1 : std_logic;
    signal s2 : std_logic;
    signal f : std_logic_vector (7 downto 0 );
    signal p : std_logic;
    signal g : std_logic;

begin

    dut : Conponent
    port map (an => an,
              bn => bn,
			  cn => cn,
			  s0 => s0,
			  s1 => s1,
              s2 => s2,
              f => f,
              p => p,
              g => g);

    stimuli : process
    begin
    	an <= 'L';
        bn <= 'L';
        cn <= 'L';
        s0 <= 'L';
        s1 <= 'L';
        s2 <= 'L';
        wait for 10 ns;
        s0 <= 'H';
        s1 <= 'L';
        s2 <= 'L';
        
        cn <= 'L';
        
        an <= 'L';
        bn <= 'L';
        wait for 10 ns;
        an <= 'L';
        bn <= 'H';
        wait for 10 ns;
        an <= 'H';
        bn <= 'L';
        wait for 10 ns;
        an <= 'H';
        bn <= 'H';
        wait for 10 ns;
        
        cn <= 'H';
        
        an <= 'L';
        bn <= 'L';
        wait for 10 ns;
        an <= 'L';
        bn <= 'H';
        wait for 10 ns;
        an <= 'H';
        bn <= 'L';
        wait for 10 ns;
        an <= 'H';
        bn <= 'H';
        wait for 10 ns;
        
        s0 <= 'L';
        s1 <= 'H';
        s2 <= 'L';
        
        cn <= 'L';
        
        an <= 'L';
        bn <= 'L';
        wait for 10 ns;
        an <= 'L';
        bn <= 'H';
        wait for 10 ns;
        an <= 'H';
        bn <= 'L';
        wait for 10 ns;
        an <= 'H';
        bn <= 'H';
        wait for 10 ns;
        
        cn <= 'H';
        
        an <= 'L';
        bn <= 'L';
        wait for 10 ns;
        an <= 'L';
        bn <= 'H';
        wait for 10 ns;
        an <= 'H';
        bn <= 'L';
        wait for 10 ns;
        an <= 'H';
        bn <= 'H';
        wait for 10 ns;
        
        s0 <= 'H';
        s1 <= 'H';
        s2 <= 'L';
        
        cn <= 'L';
        
        an <= 'L';
        bn <= 'L';
        wait for 10 ns;
        an <= 'L';
        bn <= 'H';
        wait for 10 ns;
        an <= 'H';
        bn <= 'L';
        wait for 10 ns;
        an <= 'H';
        bn <= 'H';
        wait for 10 ns;
        
        cn <= 'H';
        
        an <= 'L';
        bn <= 'L';
        wait for 10 ns;
        an <= 'L';
        bn <= 'H';
        wait for 10 ns;
        an <= 'H';
        bn <= 'L';
        wait for 10 ns;
        an <= 'H';
        bn <= 'H';
        wait for 10 ns;
        
        s0 <= 'L';
        s1 <= 'L';
        s2 <= 'H';
        
        cn <= 'L';
        
        an <= 'L';
        bn <= 'L';
        wait for 10 ns;
        an <= 'L';
        bn <= 'H';
        wait for 10 ns;
        an <= 'H';
        bn <= 'L';
        wait for 10 ns;
        an <= 'H';
        bn <= 'H';
        wait for 10 ns;
        
        cn <= 'H';
        
        an <= 'L';
        bn <= 'L';
        wait for 10 ns;
        an <= 'L';
        bn <= 'H';
        wait for 10 ns;
        an <= 'H';
        bn <= 'L';
        wait for 10 ns;
        an <= 'H';
        bn <= 'H';
        wait for 10 ns;
        
        s0 <= 'H';
        s1 <= 'L';
        s2 <= 'H';
        
        cn <= 'L';
        
        an <= 'L';
        bn <= 'L';
        wait for 10 ns;
        an <= 'L';
        bn <= 'H';
        wait for 10 ns;
        an <= 'H';
        bn <= 'L';
        wait for 10 ns;
        an <= 'H';
        bn <= 'H';
        wait for 10 ns;
        
        cn <= 'H';
        
        an <= 'L';
        bn <= 'L';
        wait for 10 ns;
        an <= 'L';
        bn <= 'H';
        wait for 10 ns;
        an <= 'H';
        bn <= 'L';
        wait for 10 ns;
        an <= 'H';
        bn <= 'H';
        wait for 10 ns;
        
        s0 <= 'L';
        s1 <= 'H';
        s2 <= 'H';
        
        cn <= 'L';
        
        an <= 'L';
        bn <= 'L';
        wait for 10 ns;
        an <= 'L';
        bn <= 'H';
        wait for 10 ns;
        an <= 'H';
        bn <= 'L';
        wait for 10 ns;
        an <= 'H';
        bn <= 'H';
        wait for 10 ns;
        
        cn <= 'H';
        
        an <= 'L';
        bn <= 'L';
        wait for 10 ns;
        an <= 'L';
        bn <= 'H';
        wait for 10 ns;
        an <= 'H';
        bn <= 'L';
        wait for 10 ns;
        an <= 'H';
        bn <= 'H';
        wait for 10 ns;
        
        s0 <= 'H';
        s1 <= 'H';
        s2 <= 'H';
        
        cn <= 'L';
        
        an <= 'L';
        bn <= 'L';
        wait for 10 ns;
        an <= 'L';
        bn <= 'H';
        wait for 10 ns;
        an <= 'H';
        bn <= 'L';
        wait for 10 ns;
        an <= 'H';
        bn <= 'H';
        wait for 10 ns;
        
        cn <= 'H';
        
        an <= 'L';
        bn <= 'L';
        wait for 10 ns;
        an <= 'L';
        bn <= 'H';
        wait for 10 ns;
        an <= 'H';
        bn <= 'L';
        wait for 10 ns;
        an <= 'H';
        bn <= 'H';
        wait for 10 ns;
        -- EDIT Adapt initialization as needed
        wait;
    end process;

end tb;

-- Configuration block below is required by some simulators. Usually no need to edit.

configuration cfg_tb_Conponent of tb_Conponent is
    for tb
    end for;
end cfg_tb_Conponent;