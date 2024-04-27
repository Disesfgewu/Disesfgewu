-- Testbench automatically generated online
-- at https://vhdl.lapinoo.net
-- Generation date : 15.4.2024 11:29:39 UTC

library ieee;
use ieee.std_logic_1164.all;

entity tb_Conponent is
end tb_Conponent;

architecture tb of tb_Conponent is

    component Conponent
        port (a   : in std_logic_vector (7 downto 0 );
              b   : in std_logic_vector (7 downto 0 );
              s   : in std_logic;
              clk : in std_logic;
              rst : in std_logic;
              f   : out std_logic_vector (7 downto 0 ));
    end component;

    signal a   : std_logic_vector (7 downto 0 );
    signal b   : std_logic_vector (7 downto 0 );
    signal s   : std_logic;
    signal clk : std_logic;
    signal rst : std_logic;
    signal f   : std_logic_vector (7 downto 0 );

    constant TbPeriod : time := 100 ns; -- EDIT Put right period here
    signal TbClock : std_logic := '0';
    signal TbSimEnded : std_logic := '0';

begin

    dut : Conponent
    port map (a   => a,
              b   => b,
              s   => s,
              clk => clk,
              rst => rst,
              f   => f);

    -- Clock generation
    TbClock <= not TbClock after TbPeriod/2 when TbSimEnded /= '1' else '0';

    -- EDIT: Check that clk is really your main clock signal
    clk <= TbClock;

    stimuli : process
    begin
        -- EDIT Adapt initialization as needed
        a <= (others => '0');
        b <= (others => '0');
        s <= '0';

        -- Reset generation
        -- EDIT: Check that rst is really your reset signal
        rst <= '0';
        wait for 100 ns;
        
        s <= '0';
        
        a <= x"05";
        b <= x"05";
        wait for 100 ns;
        a <= x"05";
        b <= x"05";
        wait for 100 ns;
        a <= x"05";
        b <= x"05";
        wait for 100 ns;
        a <= x"05";
        b <= x"05";
        wait for 100 ns;
        
        s <= '1';
        
        a <= x"05";
        b <= x"05";
        
        wait for 100 ns;
        
        s <= '1';
        
        a <= x"15";
        b <= x"05";
        
        wait for 100 ns;
        
        s <= '1';
        
        a <= x"25";
        b <= x"05";
        
        wait for 100 ns;
        
        s <= '1';
        
        a <= x"55";
        b <= x"05";
        
        wait for 100 ns;
        
        rst <= '1';
        wait for 100 ns;

        -- EDIT Add stimuli here
        wait for 100 * TbPeriod;

        -- Stop the clock and hence terminate the simulation
        TbSimEnded <= '1';
        wait;
    end process;

end tb;

-- Configuration block below is required by some simulators. Usually no need to edit.

configuration cfg_tb_Conponent of tb_Conponent is
    for tb
    end for;
end cfg_tb_Conponent;